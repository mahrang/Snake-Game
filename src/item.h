#ifndef ITEM_H
#define ITEM_H

#include "SDL.h"
#include <random>
#include "snake.h"

class Item {
  public:
   Item(int grid_width, int grid_height)
      : engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)) {}

   SDL_Point PlaceItem(Snake &snake);

  private:
   SDL_Point item;
  
   std::random_device dev;
   std::mt19937 engine;
   std::uniform_int_distribution<int> random_w;
   std::uniform_int_distribution<int> random_h;
};

#endif
