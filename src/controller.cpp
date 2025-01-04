#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(std::shared_ptr<Snake> snake, Snake::Direction input, Snake::Direction opposite) const {
// snake can only go in opposite direction if its size = 1
  if (snake->direction != opposite || snake->size == 1) snake->direction = input;
  return;
}

void Controller::HandleInput(bool &running, bool &paused, std::shared_ptr<Snake> snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
       
      // SDL_WINDOWEVENT close can catch alt+F4 or window close
      //from OS.
      case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
          running = false;
        }
        break;

      case SDL_KEYDOWN:
        switch (e.key.keysym.sym) {
          // Arrow keys
          case SDLK_UP:
            ChangeDirection(snake, Snake::Direction::kUp,
                            Snake::Direction::kDown);
            break;

          case SDLK_DOWN:
            ChangeDirection(snake, Snake::Direction::kDown,
                            Snake::Direction::kUp);
            break;

          case SDLK_LEFT:
            ChangeDirection(snake, Snake::Direction::kLeft,
                            Snake::Direction::kRight);
            break;

          case SDLK_RIGHT:
            ChangeDirection(snake, Snake::Direction::kRight,
                            Snake::Direction::kLeft);
            break;
          
          // Toggle pause
          case SDLK_p:
            paused = !paused;
            break;
            
          // Escape to quit
          case SDLK_ESCAPE:
            running = false;
            break;
        }
    }
  }
}
