#include "ScoreBoard.h"

// Default Constructor Definition
ScoreBoard::ScoreBoard(){};

// Methods Definition
void ScoreBoard::SaveScore(Player &player, int duration){
    //Create Output file stream
    fstream Game_ScoreHistory;
    //format text file
    Game_ScoreHistory.open("ScoreBoard.txt", ios::binary | ios::out | ios::app);

    if(Game_ScoreHistory.is_open()){
        Game_ScoreHistory << player.GetPlayerName() << " " << player.GetPlayerScore() << " " << duration << " seconds\n";
        Game_ScoreHistory.close();
    }
    else{
        cout << "ERROR: Requested file cannot be opened\n";
    }
}

vector<shared_ptr<Player>> ScoreBoard::GetScoreFromFile(){
  
    string line, name;
    int score, game_time;
    ifstream Game_ScoreHistory("ScoreBoard.txt");

    if(Game_ScoreHistory.is_open()){
        while(getline(Game_ScoreHistory, line))
        {
            istringstream linestream(line);
            if(linestream >> name >> score >> game_time){
                auto shared_player = make_shared<Player>(name, score, game_time);
                _history.emplace_back(move(shared_player));
            }
        }
        Game_ScoreHistory.close();
        return _history;
    }
}

vector<shared_ptr<Player>> ScoreBoard::SortScoreBoard(vector<shared_ptr<Player>> &v){
    sort(v.begin(), v.end(), [] 
    (const shared_ptr<Player>& player_a, shared_ptr<Player>& player_b){
        return player_a->GetPlayerScore() > player_b->GetPlayerScore();
    });
    return v;
}

void ScoreBoard::DisplayScoreBoard(){
auto ordered_history = _history;
ordered_history = this->SortScoreBoard(ordered_history);
    if(ordered_history.size() > 0){
       
        cout << "/------------------ ScoreBoard By Rank -------------------/" << endl;
        int count = 1;
        for(auto i : ordered_history){
            cout <<  "Rank "<<count <<"      Name: " << i->GetPlayerName() << "      Score: " << i->GetPlayerScore() << "      Duration: " << i->GetPlayerGameTime() << "sec\n";
            count++;
            if(count > 9){
                break;
            }
        }
    }
    else{
        cout << "ERROR: No ScoreBoard Yet!!!!!\n";
    }
}
