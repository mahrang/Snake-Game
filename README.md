# Snake Game

![Snake_Game4_github](https://github.com/user-attachments/assets/c8067e55-a07b-4c80-a9ab-43312be3f7db)

When the snake eats food (yellow square), its body grows, it moves faster, and the player earns 1 point.  When the snake eats poison (red square), its body shrinks but its speed isn't affected, and the player loses 1 point.  Once both the snake's body and head are gone, the score will be -1 and the game will end.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## project rubric points addressed:

1. Loops, Functions, I/O:  The project demonstrates an understanding of C++ functions and control structures.
    The function Item::PlaceItem() was created in game.cpp at line 79 that uses a while loop and an if statement.  
    A new Game::PlaceFood() function was created in game.cpp at line 97 that calls Item::PlaceItem to place food.
    The function Game::PlacePoison() was created in game.cpp at line 99.
    The function Snake::ShrinkBody() was created in snake.cpp at line 82.
    Inside the function Game::Update() in game.cpp at line 109, I added an if statement from lines 135-141 to check for poison.
    Inside the function Snake::UpdateBody in snake.cpp at line 50, I added lines to the if-else statement from lines 61-67 to account for shrinking.
2. Object Oriented Programming:  
    One or more classes are added to the project with appropriate access specifiers for class members.
    The class Item was added in item.h at line 8.
   Also, class Item's constructor uses a member initialization list in item.h at line 10.
   All class member functions document their effects, either through function names, comments, or formal documentation.
    In game.cpp at lines 74-78, the comments and function header indicate what the function Item::PlaceItem() does.
3. Memory Management:  
    I use pass-by-reference in the function Renderer::Render() in renderer.cpp at line 53.  I passed food and poison to the function as references.
    Also, I created a shared pointer in game.h line 23.
4.  Concurrency:  
    Game::Update() and Renderer::Render() functions are run in threads in game.cpp lines 43-48.
    Also, mutexes and locks are used in Game::Update() in game.cpp lines 110-111 and 143.
