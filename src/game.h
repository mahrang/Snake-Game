#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "item.h"
#include "gameObject.h"

class Game : public GameObject 
{
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void RunThread();
  int GetScore() const;
  int GetSize() const;

 private:
  std::shared_ptr<Snake> snake;
  Item _item;
  SDL_Point food, poison;

  int score{0};

  void PlaceFood();
  void PlacePoison();
  void Update();
  void SimulateFood();
};

#endif
