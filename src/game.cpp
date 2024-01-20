#include "game.h"
#include <iostream>
#include <thread>
#include <mutex>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(std::make_shared<Snake>(grid_width, grid_height)),
      _item(grid_width, grid_height) {
  PlaceFood();
  PlacePoison();
}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
/*  Original code:
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, poison);
    
    Threads:
    std::thread t1 = std::thread(&Controller::HandleInput, std::ref(controller), running, snake);  //gave errors
    std::thread t2 = std::thread(&Game::Update, this);
    std::thread t3 = std::thread(&Renderer::Render, std::ref(renderer), snake, food, poison);
    
    t1.join();
    t2.join();
    t3.join();  */
    
    controller.HandleInput(running, snake);
    Update();  //original code
    //RunThread();  // runs Update in a thread
    //renderer.Render(snake, food, poison);  //original code
    //renderer.RunThread(snake, food, poison);  // compiles but crashes
    //std::thread t3 = std::thread(&Renderer::Render, std::ref(renderer), snake, food, poison);  // this works
    //t3.join();
    threads.emplace_back(std::thread(&Renderer::Render, std::ref(renderer), snake, food, poison));  // compiles but crashes
    
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

/*  Since placing food or poison follows the same procedure, the function Item::PlaceItem() was created so that only 1 function does that task.  The output will be either food or poison depending on whether Game::PlaceFood() or Game::PlacePoison() call it.
When I tried Item::PlaceItem(Snake const snake), I got an error b/c of
SnakeCell(x, y)) below.  The function header is
bool Snake::SnakeCell(int x, int y)
from line 81 of snake.cpp.  B/c the bool value can change, you can't use const.  */
SDL_Point Item::PlaceItem(std::shared_ptr<Snake> snake) {
  int x, y;
  //std::mutex mtx;
  //std::unique_lock<std::mutex> lck(mtx);
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      item.x = x;
      item.y = y;
      return item;
    }
  }
  //lck.unlock();
}

void Game::PlaceFood() { food = _item.PlaceItem(snake); }

void Game::PlacePoison() { poison = _item.PlaceItem(snake); }

void Game::RunThread() {
  threads.emplace_back(std::thread(&Game::Update, this));
}

void Game::Update() {
  std::mutex mtxSnake;
  std::unique_lock<std::mutex> lockSnake(mtxSnake);
  if (!snake->alive) return;

  snake->Update();

  int new_x = static_cast<int>(snake->head_x);
  int new_y = static_cast<int>(snake->head_y);
  
  std::mutex mtxFood;
  std::unique_lock<std::mutex> lockFood(mtxFood);
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake->GrowBody();
    snake->speed += 0.02;
  }
  lockFood.unlock();
 
  std::mutex mtxPoison;
  std::unique_lock<std::mutex> lockPoison(mtxPoison);
    // Check if there's poison over here
  if (poison.x == new_x && poison.y == new_y) {
    score--;
    PlacePoison();
    // Shrink snake
    snake->ShrinkBody();
  }
  lockPoison.unlock();
  lockSnake.unlock();
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->size; }
