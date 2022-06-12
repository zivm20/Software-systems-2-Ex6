#include "League.hpp"
using namespace basketball;
using namespace std;



League::League(const std::vector<Team>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.emplace(pair<string,Team>(_teams[i].getName(),_teams[i]));
        }
        else{
            
            teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
        }
    }
}
League::League(const std::vector<string>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.emplace(pair<string,Team>(_teams[i],Team{_teams[i]}));
        }
        else{
            teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
        }
    }
}

League::League(): teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
    }
}


void League::addGame(Game*& game){
    getTeam(game->getHome()).addGame(game);
    getTeam(game->getAway()).addGame(game);
}


