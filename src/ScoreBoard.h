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
    void SaveHistory(Player &player, int duration);
    vector<shared_ptr<Player>> ReadHistory();
    vector<shared_ptr<Player>> SortHistory(vector<shared_ptr<Player>> &v);
    void DisplayHistory();
    void DisplayOrderedHistory();
    Player GetHighScore();
    void DisplayHighScore();
private:
    vector<shared_ptr<Player>> _history;
};
#endif