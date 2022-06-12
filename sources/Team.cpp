#include "Team.hpp"
using namespace basketball;
using namespace std;




Team::Team(std::string _name):name(_name),skill(random()){

}
Team::Team(std::string _name, double _skill):name(_name),skill(_skill){

}

int Team::getWinCount(){
    int n;
    for (auto const& game: teamGames){
        if(game->getWinner() == name) n++;
    }
    return n;
}
int Team::getLongestStreak(bool win){
    
    int bestStreak;
    int n;
    for (auto const& game: teamGames){
        //if truth value of has this team won equals to win
        if((game->getWinner() == name) == win ) 
            n++;
        else 
            n = 0;
        
        if(n>bestStreak) 
            bestStreak = n;
    }
    return bestStreak;
}

int Team::getScoreDiff(){
    int diff;
    for (auto const& game: teamGames){
        //if this team is home
        if((game->getHome() == name)) 
            diff +=  game->homeScore() - game->awayScore();
        else 
            diff +=  game->awayScore() - game->homeScore();
    }
    return diff;
}

int Team::getHardestWin(){

}


Team::~Team(){
    for (auto const& game: teamGames){
        delete game;
    }
}



