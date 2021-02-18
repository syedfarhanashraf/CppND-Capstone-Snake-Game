#include <ctime>
#include "Player.h"

//Constructor Definition
Player::Player(string name, int score, int time){
    this->player_name = name;
    this->player._score = score;
    this->player._game_time = time;
}

// Copy Constructor 
Player::Player (const Player &source) {
    this->player_name = source.player_name;
    this->player._score = source.player._score;
    this->player._game_time = source.player._game_time;
}
// copy assignment overloading operator 
Player& Player::operator= (const Player &source) {
    if (this == &source)
        return *this;
    this->player_name = source.player_name;
    this->player._score = source.player._score;
    this->player._game_time = source.player._game_time;
    return *this;
}
// move constructor 
Player::Player (Player &&source) {
    // move data
    this->player_name = source.player_name;
    this->player._score = source.player._score;
    this->player._game_time = source.player._game_time;
    // delete original data
    source.player_name = "Dummy";
    source.player._score = 0;
    source.player._game_time = 0;
}
// Move assignment operator overloading
Player& Player::operator= (Player &&source) {
    if (this == &source)
        return *this;
    // move data
    this->player_name = source.player_name;
    this->player._score = source.player._score;
    this->player._game_time = source.player._game_time;
    // delete original data
    source.player_name = "Dummy";
    source.player._score = 0;
    source.player._game_time = 0;
    return *this;
}

// Definitions of setters and Getters
void Player::SetPlayerName(string name){
    this->player_name = name;
}

void Player::SetPlayerScore(int score){
    this->player._score = score;
}

void Player::SetPlayerGameTime(int game_time){
    //current date/time on local machine
    game_time = time(0);
    this->player._game_time = game_time;
}

string Player::GetPlayerName()const{ return player_name; }
int Player::GetPlayerScore()const{ return player._score; }
int Player::GetPlayerGameTime()const{ return player._game_time; }

//Overloading the (<) operator
bool Player::operator<(const Player &data){
    return this->GetPlayerScore() > data.GetPlayerScore();
}