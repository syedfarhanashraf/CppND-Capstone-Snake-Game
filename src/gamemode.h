#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <bits/stdc++.h>

using namespace std;

class GameMode{
public:
    void MainMenu();
    void GetPlayerName();
    int Input_number();
   string Input_string();
   
    enum States{
        kMain = 0, kPlay = 1, kHistory = 2
    };
};

#endif