#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>   // For std::shared_ptr
#include "snake.h"

class Controller {
 public:
  /**
   * @brief Handles user input to control the Snake's direction and overall game state.
   * 
   * @param running A reference to a boolean that dictates the main game loop.
   * @param paused  A reference to a boolean indicating whether the game is currently paused.
   * @param snake   A shared pointer to the Snake object that will be manipulated by user input.
   */
  void HandleInput(bool &running, bool &paused, std::shared_ptr<Snake> snake) const;

 private:
  /**
   * @brief Changes the Snake's direction, preventing immediate reversal unless the Snake size is 1.
   * 
   * @param snake    A shared pointer to the Snake instance to modify.
   * @param input    The desired new direction.
   * @param opposite The direction considered the opposite of @p input.
   */
  void ChangeDirection(std::shared_ptr<Snake> snake,
                       Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif  // CONTROLLER_H
