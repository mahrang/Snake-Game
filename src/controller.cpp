#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(std::shared_ptr<Snake> snake,
                                 Snake::Direction input,
                                 Snake::Direction opposite) const 
{
  // Prevent a direct reversal unless the snake size is 1
  if (snake == nullptr) {
    std::cerr << "[Controller] Snake pointer is null, cannot change direction.\n";
    return;
  }

  if (snake->direction != opposite || snake->size == 1) {
    snake->direction = input;
#ifdef DEBUG_CONTROLLER
    std::cout << "[Controller] Direction changed to: " << static_cast<int>(snake->direction) << "\n";
#endif
  }
}

void Controller::HandleInput(bool &running, 
                             bool &paused, 
                             std::shared_ptr<Snake> snake) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) 
  {
    switch (e.type) 
    {
      case SDL_QUIT:
        running = false;
        break;

      // SDL_WINDOWEVENT close can catch alt+F4 or window close from OS.
      case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
          running = false;
        }
        break;

      case SDL_KEYDOWN:
      {
        switch (e.key.keysym.sym) 
        {
          // Arrow keys
          case SDLK_UP:
            ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
            break;
          case SDLK_DOWN:
            ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
            break;
          case SDLK_LEFT:
            ChangeDirection(snake, Snake::Direction::kLeft, Snake::Direction::kRight);
            break;
          case SDLK_RIGHT:
            ChangeDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);
            break;

          // WASD keys
          case SDLK_w:
            ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
            break;
          case SDLK_s:
            ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
            break;
          case SDLK_a:
            ChangeDirection(snake, Snake::Direction::kLeft, Snake::Direction::kRight);
            break;
          case SDLK_d:
            ChangeDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);
            break;

          // Toggle pause
          case SDLK_p:
            paused = !paused;
            if (paused) {
#ifdef DEBUG_CONTROLLER
              std::cout << "[Controller] Game paused.\n";
#endif
            } else {
#ifdef DEBUG_CONTROLLER
              std::cout << "[Controller] Game unpaused.\n";
#endif
            }
            break;

          // Escape to quit
          case SDLK_ESCAPE:
            running = false;
            break;

          default:
            break;
        }
        break;
      }

      default:
        break;
    }
  }
}
