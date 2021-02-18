#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

using namespace std;

class Game {
 public:
  Game(size_t grid_width, size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  bool PowerSlowCell(int x, int y);
  bool FoodCell(int x, int y);
  
 private:
  Snake snake;
  SDL_Point food;
  SDL_Point power_slow;

  random_device dev;
  mt19937 engine;
  uniform_int_distribution<int> random_w;
  uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
  void PlacePowerSlow();
};

#endif