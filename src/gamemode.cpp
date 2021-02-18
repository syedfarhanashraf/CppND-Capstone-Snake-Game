#include "gamemode.h"

void GameMode::MainMenu(){
    cout << "\033[2J\033[1;1H";
    cout << "/------------- Welcome to 2D Snake Game -------------/" << endl;
    cout << "/--------------------- Main Menu --------------------/" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show Game History" << endl;
}

void GameMode::GetPlayerName(){
    cout << "\033[2J\033[1;1H";
    cout << "/------------------ Game Settings -------------------/" << endl;
    cout << "Please enter your name: ";
}


int GameMode::Input_number(){
    int _key;
    while(!(cin >> _key)){
        cin.clear();
        while(cin.get() != '\n')
            continue;
        //Ask user to try again
        cout << "Warning Invalid Input, Please Try Again.";
    }
    return _key;
}
string GameMode::Input_string(){
    string _key;
    while(!(cin >> _key)){
        cin.clear();
        while(cin.get() != '\n')
            continue;
        //Ask user to try again
        cout << "Warning Invalid Input, Please Try Again.";
    }
    return _key;
}