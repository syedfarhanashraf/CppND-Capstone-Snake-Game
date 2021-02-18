#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <bits/stdc++.h>
#include <fstream>

#include "Player.h"

using namespace std;

class ScoreBoard{
public:
    //Default Constructor
    ScoreBoard();
    //Methods
    void SaveScore(Player &player, int duration);
    vector<shared_ptr<Player>> GetScoreFromFile();
    vector<shared_ptr<Player>> SortScoreBoard(vector<shared_ptr<Player>> &v);
 
    void DisplayScoreBoard();
   
private:
    vector<shared_ptr<Player>> _history;
};
#endif