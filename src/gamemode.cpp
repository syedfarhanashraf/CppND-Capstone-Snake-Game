#include "gamemode.h"

void GameMode::MainMenu(){
    cout << "/-------Welcome to CppND-Capstone-Snake-Game ----------/" << endl;
    cout << "/--------------------- Main Menu --------------------/" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. ScoreBoard" << endl;
}

void GameMode::GetPlayerName(){
    cout << "/------------------ How To Play -------------------/" << endl;
    cout << "           Eat Yellow Egg To Get Points             " << endl;
    cout << "         Eat Grean Egg to Slow Your Speed           " << endl;
    cout << "Do Not Eat Red Egg It Will Increase Your Speed Twice" << endl;
  
  
  
  cout << endl << endl << endl;
   cout << "/------------------ Insert Your Name -------------------/" << endl;
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