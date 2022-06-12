#include "League.hpp"
using namespace basketball;
using namespace std;



League::League(std::vector<Team>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.push_back(_teams[i]);
            teamGames.insert(pair<string,vector<Game*>>(teams[i].getName(),vector<Game*>()));
        }
        else{
            teams.push_back(Team("NoName "+i));
            teamGames.insert(pair<string,vector<Game*>>(teams[i].getName(),vector<Game*>()));
        }
    }
}
League::League(std::vector<string>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.push_back(Team(_teams[i]));
            teamGames.insert(pair<string,vector<Game*>>(teams[i].getName(),vector<Game*>()));
        }
        else{
            teams.push_back(Team("NoName "+i));
            teamGames.insert(pair<string,vector<Game*>>(teams[i].getName(),vector<Game*>()));
        }
    }
}

League::League(): teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        teams.push_back(Team("NoName "+i));
        teamGames.insert(pair<string,vector<Game*>>(teams[i].getName(),vector<Game*>()));
    }
}


void processGame(Game& game){
    
}


void League::addGame(Game*& game){
    teamGames[game->getHome()->getName()].push_back(game);
    teamGames[game->getAway()->getName()].push_back(game);
}


League::~League(){
    for (auto const& entry: teamGames){
        for(auto const& game: entry.second){
            delete game;
        }
    }
}