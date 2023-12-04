# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

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


## New feature added to the game

Poison has been added to the game such that, when eaten, the snake's body will shrink by 1 square and score will decrease by 1.  Once both the snake's body and head are gone, the score will be -1 and the game will stop.


## 5 rubric points addressed are:

1. Loops, Functions, I/O:  The project demonstrates an understanding of C++ functions and control structures.
    The function Item::PlaceItem() was created in game.cpp at line 56 that uses a while loop and an if statement.  
    A new Game::PlaceFood() function was created in game.cpp at line 71 that calls Item::PlaceItem to place food.
    The function Game::PlacePoison() was created in game.cpp at line 73.
    The function Snake::ShrinkBody() was created in snake.cpp at line 78.
    Inside the function Game::Update() in game.cpp at line 75, I added an if statement from lines 93-98 to check for poison.
    Inside the function Snake::UpdateBody in snake.cpp at line 46, I added lines to the if-else statement from lines 50-66 to account for shrinking.
2. Object Oriented Programming:  One or more classes are added to the project with appropriate access specifiers for class members.
    The class Item was added in item.h at line 8.
3. Object Oriented Programming:  Class constructors utilize member initialization lists.
    Class Item's constructor uses a member initialization list in item.h at line 10.
4. Object Oriented Programming:  All class member functions document their effects, either through function names, comments, or formal documentation.
    In game.cpp at lines 51-56, the comments and function header indicate what the function Item::PlaceItem() does.
5. Memory Management:  At least two variables are defined as references, or two functions use pass-by-reference in the project code.
    Item::PlaceItem() uses pass-by-reference in game.cpp at line 56.
    Also, in the function Renderer::Render() in renderer.cpp at line 41, I modified the function header to pass 2 more variables as reference.  In the starter code, its function header was 
    Renderer::Render(Snake const snake, SDL_Point const &food)
    but because I added poison and changed snake to a reference, the function header became
    Renderer::Render(Snake const &snake, SDL_Point const &food, SDL_Point const &poison)
