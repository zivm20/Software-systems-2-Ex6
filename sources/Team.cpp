#include "Team.hpp"
using namespace basketball;
using namespace std;

Team::Team(std::string _name):name(_name),skill(random()){

}
Team::Team(std::string _name, double _skill):name(_name),skill(_skill){

}

int Team::getWinCount()const{
    int n;
    for (auto const& game: teamGames){
        if(game->getWinner() == name) n++;
    }
    return n;
}
int Team::getLongestStreak(bool win)const{
    
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

int Team::getScoreDiff()const{
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

double Team::getAvgPoints()const{
    int sum = 0;
    for (auto const& game: teamGames){
        //if this team is home
        if((game->getHome() == name)) 
            sum +=  game->homeScore();
        else
            sum += game->awayScore();
    }
    return sum/(double)teamGames.size();
}



Team::~Team(){
    for (auto const& game: teamGames){
        delete game;
    }
}



