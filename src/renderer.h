#ifndef RENDERER_H
#define RENDERER_H

#include <bits/stdc++.h>
#include "SDL.h"
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const size_t screen_width, const size_t screen_height,
           const size_t grid_width, const size_t grid_height);
  ~Renderer();
int snakecount;
  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &power_slow,SDL_Point const &power_Fast);
  void UpdateWindowTitle(int score, int fps, float speed);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const size_t screen_width;
  const size_t screen_height;
  const size_t grid_width;
  const size_t grid_height;
};

#endif