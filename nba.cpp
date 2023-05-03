#include <iostream>
#include <cstdio>
#include<vector>
#include <stdlib.h>
#include <fstream>

using namespace std;
// NBA PLAYER DATABASE
class Interface{
    public :
        void menu();
};


// Player
class Player{
    public:
        void playerMenu();
        void ShowPlayer();
        void UpdatePlayer();
    protected:
        string player_name;
        string team;
        int jersey_num;
        bool injured;

};
void Player::ShowPlayer(){
    string player_choice;
    cout << "Please enter a player you would like to view" << endl;
    cin >> player_choice;

    ifstream ifs("players.txt");

    string word = player_choice;
    string line;
    while ( getline(ifs, line))
    {
        size_t pos = line.find(word);
        if (pos != string::npos){
            cout << line << endl;
        }
    }
    if (player_choice == "q"){
        Player p;
        p.playerMenu();
    }
    ShowPlayer();

}
void Player::UpdatePlayer() {
    string update_choice;
    string new_pos;
    string new_team;
    string new_ppg;

    string new_entry;

    cout << "Enter player you would like to edit" << endl;
    cin >> update_choice;
    if (update_choice == "q"){
        Player p;
        p.playerMenu();
    }
    else{
        cin >> new_pos >> new_ppg >> new_team;
    }

    new_entry = update_choice + " | " + new_pos + " | " + new_ppg + " | " + new_team + " |";
    cout << new_entry << endl;

    fstream filein("players.txt");
    ofstream fileout("temp_players.txt");
    string strTemp;

    while (filein >> strTemp){
        if(strTemp == update_choice){
            strTemp = new_entry;
        }
        fileout << strTemp;
    }
    UpdatePlayer();

}
void Player::playerMenu(){
    int choice2;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||| Player Menu  |||||||||||||" << endl;
    cout << "|||||||||1. View Player        |||||||||" << endl;
    cout << "|||||||||2. Edit Player        |||||||||" << endl;
    cout << "|||||||||3. Exit               |||||||||" << endl;
    cout << "|||||||||                      |||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cin >> choice2;
    Player P;
    switch(choice2){
        case 1: {
            P.ShowPlayer();
            break;
        }
        case 2: {
            P.UpdatePlayer();
            break;
        }
        case 3: {
            Interface i;
            i.menu();
            break;
        }
        default:
            break;
    }

}
// Player Team
class Team {
    public:
        void ShowTeam();
        void UpdateTeam();
        void teamMenu();

        string team1_name;
        string team2_name;

        // NOTE: only add 6 players per team
};
void Team::UpdateTeam(){
    string update_choice;
    string new_win;
    string new_loss;
    string new_entry;
    cout << "Please enter a valid team you would like to update and the new win and loss stat" << endl;
    cin >> update_choice;

    if (update_choice == "q"){
        Team t;
        t.teamMenu();
    }
    else{
        cin >> new_win >> new_loss;
    }

    new_entry = update_choice +" | W: " + new_win + " | L: " + new_loss;
    cout << new_entry << endl;


    fstream filein("teams.txt");
    ofstream fileout("temp_teams.txt");
    string strTemp;

    while (filein >> strTemp){
        if(strTemp == update_choice){
            strTemp = new_entry;
        }
        fileout << strTemp;
    }
    UpdateTeam();

}

void Team::ShowTeam(){
    string team_choice;
    cout << "Please enter team you would like to view" << endl;
    cin >> team_choice;

    ifstream ifs("teams.txt");

    string word = team_choice;
    string line;

    while ( getline(ifs, line))
    {
        size_t pos = line.find(word);
        if (pos != string::npos){
            cout << line << endl;
        }
    }
    if(team_choice == "q") {
        Team t;
        t.teamMenu();
    }
    ShowTeam();
}
class Matches {
    public:
        void ShowMatch();

};
void Matches::ShowMatch(){
    string match_choice;
    cout << "Please enter a valid match date" << endl;
    cin >> match_choice;

    ifstream ifs("matches.txt");
    string word = match_choice;
    string line;
    while (getline(ifs,line)) {
        size_t pos = line.find(word);
        if (pos != string::npos){
            cout << line << endl;
        }
    }
    if (match_choice == "q"){
        Interface i;
        i.menu();
    }
    ShowMatch();
}
void Team::teamMenu(){
    int choice;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||| Team Menu    |||||||||||||" << endl;
    cout << "|||||||||1. View Team          |||||||||" << endl;
    cout << "|||||||||2. Edit Team          |||||||||" << endl;
    cout << "|||||||||3. Exit               |||||||||" << endl;
    cout << "|||||||||                      |||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cin >> choice;
    Team t;
    switch(choice){
        case 1: {
            t.ShowTeam();
            break;
        }
        case 2: {
            t.UpdateTeam();
            break;
        }
        case 3: {
            Interface i;
            i.menu();
            break;
        }
        default:
            break;
    }
}
// MAIN MENU
void Interface::menu(){
    int choice;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||| NBA DATABASE |||||||||||||" << endl;
    cout << "|||||||||1. Current Players    |||||||||" << endl;
    cout << "|||||||||2. Current Teams      |||||||||" << endl;
    cout << "|||||||||3. Find match         |||||||||" << endl;
    cout << "|||||||||4. Exit               |||||||||" << endl;
    cout << "|||||||||                      |||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cin >> choice;

    switch(choice){
        case 1: {
            Player p;
            p.playerMenu();
            break;
        }
        case 2: {
            Team t;
            t.teamMenu();
            break;
        }
        case 3: {
            Matches m;
            m.ShowMatch();
            break;
        }
        case 4: {
            abort();
            break;
        }
        default:
            cout << "Please choose a valid option" << endl;
            menu();
            break;
    }
}
// MAIN FUNCTION
int main () {
    Team team;
    Player player;

    Interface i;
    i.menu();
    return 0;
}
