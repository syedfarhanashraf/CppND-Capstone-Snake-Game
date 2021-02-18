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
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.




## Rubric Points
### Object Oriented Programming
|Criteria| Addressed(Yes/No)|
|--------|------------|
The project uses Object Oriented Programming techniques. |YES
Classes use appropriate access specifiers for class members.|YES
Class constructors utilize member initialization lists. |YES
Classes abstract implementation details from their interfaces.|YES
Classes encapsulate behavior.|YES

### Loops, Functions, I/O
|Criteria| Addressed(Yes/No)|
|--------|------------|
The project demonstrates an understanding of C++ functions and control structures.|YES
The project reads data from a file and process the data, or the program writes data to a file. |YES
The project accepts user input and processes the input.|YES

### Memory Management
|Criteria| Addressed(Yes/No)|
|--------|------------|
Classes abstract implementation details from their interfaces. |YES
The project uses destructors appropriately.|YES
The project follows the Rule of 5. |YES
The project uses smart pointers instead of raw pointers.|YES
The project uses move semantics to move data, instead of copying it, where possible.|YES
The project makes use of references in function declarations. |YES


## Add New Features In Project
1. Create Main Menu System ,that will show you two options( Play Game , check Scoreboard)
2. Create Power slow egg as power in the game in which it is green block that slow the speed of snake.
3. Create Power increase egg as power in the game in which it is Red block that increase the twice speed of snake.
4. Add Snake Alternative Color that will feel better for users.
