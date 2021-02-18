#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "ScoreBoard.h"
#include "Player.h"
#include "gamemode.h"

int main() {
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{640};
  constexpr size_t kScreenHeight{640};
  constexpr size_t kGridWidth{32};
  constexpr size_t kGridHeight{32};

  GameMode gamemode;
  Player player;
  ScoreBoard Scoreboard;
  string player_name;
  int gametime, duration, first, last;
  gamemode.MainMenu();
  int mode = gamemode.Input_number();
  if (mode == gamemode.kPlay){
    gamemode.GetPlayerName();
    player_name = gamemode.Input_string();
    player.SetPlayerName(player_name);
    player.SetPlayerGameTime(gametime);
    first = player.GetPlayerGameTime();
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    player.SetPlayerGameTime(gametime);
    last = player.GetPlayerGameTime();
    duration = last - first;
    cout << "\033[2J\033[1;1H";
    cout << "Game has terminated successfully!\n";
    cout << "Player: " << player.GetPlayerName() << "\n";
    cout << "Score: " << game.GetScore() << "\n";
    cout << "Duration: " << duration << " seconds\n";
    cout << "Size: " << game.GetSize() << "\n";
    player.SetPlayerScore(game.GetScore());
    player.GetPlayerGameTime();
    Scoreboard.SaveHistory(player, duration);
  }
  else if(mode == gamemode.kHistory){
    
    auto player_history = Scoreboard.ReadHistory();
    if(!(player_history.size() > 0))
    {
      cout << "No Previous Data Stored!\n";
    }
    else
    {
    Scoreboard.DisplayOrderedHistory();
    }
   
  }
  return 0;
}