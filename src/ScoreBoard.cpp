#include "ScoreBoard.h"

// Default Constructor Definition
ScoreBoard::ScoreBoard(){};

// Methods Definition
void ScoreBoard::SaveHistory(Player &player, int duration){
    //Create Output file stream
    fstream Game_History;
    //format text file
    Game_History.open("Game_History.txt", ios::binary | ios::out | ios::app);

    if(Game_History.is_open()){
        Game_History << player.GetPlayerName() << " " << player.GetPlayerScore() << " " << duration << " seconds\n";
        Game_History.close();
    }
    else{
        cout << "ERROR: Requested file cannot be opened\n";
    }
}

vector<shared_ptr<Player>> ScoreBoard::ReadHistory(){
  
    string line, name;
    int score, game_time;
    ifstream Game_History("Game_History.txt");

    if(Game_History.is_open()){
        while(getline(Game_History, line))
        {
            istringstream linestream(line);
            if(linestream >> name >> score >> game_time){
                auto shared_player = make_shared<Player>(name, score, game_time);
                _history.emplace_back(move(shared_player));
            }
        }
        Game_History.close();
        return _history;
    }
}

vector<shared_ptr<Player>> ScoreBoard::SortHistory(vector<shared_ptr<Player>> &v){
    sort(v.begin(), v.end(), [] 
    (const shared_ptr<Player>& player_a, shared_ptr<Player>& player_b){
        return player_a->GetPlayerScore() > player_b->GetPlayerScore();
    });
    return v;
}

void ScoreBoard::DisplayOrderedHistory(){
auto ordered_history = _history;
ordered_history = this->SortHistory(ordered_history);
    if(ordered_history.size() > 0){
        cout << "\033[2J\033[1;1H";
        cout << "/------------------ Hall of Fame -------------------/" << endl;
        int count = 1;
        for(auto i : ordered_history){
            cout << count << ". " << i->GetPlayerName() << ", Score: " << i->GetPlayerScore() << ", Duration: " << i->GetPlayerGameTime() << " seconds\n";
            count++;
            if(count > 5){
                break;
            }
        }
    }
    else{
        cout << "ERROR: No data to display\n";
    }
}

void ScoreBoard::DisplayHistory(){
    if(_history.size() > 0){
        cout << "\033[2J\033[1;1H";
        cout << "/------------------ Game History -------------------/" << endl;
        int count = 1;
        for(auto i : _history){
            cout << count << ". " << i->GetPlayerName() << ", Score: " << i->GetPlayerScore() << ", Duration: " << i->GetPlayerGameTime() << endl;
            count++;
        }
    }
    else{
        cout << "ERROR: No data to display\n";
    }
}

Player ScoreBoard::GetHighScore(){
    auto history = _history;
    history = this->SortHistory(history);
    auto tmp = history.front();
    auto high_score = (*tmp.get());
    return high_score;
}

void ScoreBoard::DisplayHighScore(){
    auto high_score = this->GetHighScore();
    cout << "\033[2J\033[1;1H";
    cout << "/------------------ Highest Score Player -------------------/" << endl;
    cout << high_score.GetPlayerName() << ", Score: " << high_score.GetPlayerScore() << ", Duration: " << high_score.GetPlayerGameTime() << " seconds\n";
}
