#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const size_t screen_width,
                   const size_t screen_height,
                   const size_t grid_width, const size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "SDL could not initialize.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    cerr << "Window could not be created.\n";
    cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    cerr << "Renderer could not be created.\n";
    cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food, SDL_Point const &power_slow) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render Powerslow
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0x00);
  block.x = power_slow.x * block.w;
  block.y = power_slow.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
 
   for( int i = 0; i < snake.body.size();i++){
       if(i % 2)
         {
              SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
         }
       else
         {
            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x7A, 0xFF, 0xFF);
         }
    block.x = snake.body[i].x * block.w;
    block.y = snake.body[i].y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } 
  else {
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps, float speed) {
  string title{"Snake Score: " + to_string(score) + " FPS: " + to_string(fps) + " Speed: " + to_string(speed)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
