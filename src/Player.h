#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>

using namespace std;

class Player{
public:
    //Constructors and Destructors
    Player(){};
    Player(string name, int score, int time);
    ~Player(){};
    //Copy Semantics
        Player(const Player &source);
        Player &operator=(const Player &source);
    //Move Semantics
        Player(Player &&source);
        Player &operator=(Player &&source);
    //Setters
        void SetPlayerName(string name);
        void SetPlayerScore(int score);
        void SetPlayerGameTime(int game_time);
    //Getters
        string GetPlayerName() const;
        int GetPlayerScore() const;
        int GetPlayerGameTime() const;
    //Overloading the (<) operator for players socres comparison
    bool operator<(const Player &data); 

private:
    string player_name;
    //Struct holding the score and gametime of the player
    struct stats{
        int _score, _game_time;
    }player;
};
#endif