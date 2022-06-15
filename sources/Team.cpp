#include "Team.hpp"
using namespace basketball;
using namespace std;

Team::Team(const string& _name):name(_name),skill(random()){
    if(skill < 0||skill>1){
        throw runtime_error("0<=skill<=1 ");
 
    }
}
Team::Team(const string& _name, const double& _skill):name(_name),skill(_skill){
        if(skill < 0||skill>1){
        throw runtime_error("0<=skill<=1 ");
 
    }
}

Team::Team(const Team& t2):name(t2.getName()),skill(t2.getSkill()){
    for (auto const& game: t2.getGames()){
        teamGames.push_back(new Game(*game));
    }
    if(skill < 0||skill>1){
        throw runtime_error("0<=skill<=1 ");
 
    }
}

int Team::getWinCount()const{
    int n = 0;
    
    for (auto const& game: teamGames){
        if(game->getWinner() == name){ 
            n++;
        }
    }
    return n;
}
int Team::getLongestStreak(bool win)const{
    
    int bestStreak=0;
    int n = 0;
    for (auto const& game: teamGames){
        //if truth value of has this team won equals to win
        if((game->getWinner() == name) == win){
            n++;
        }
        else{
            n = 0;
        }
        if(n>bestStreak){
            bestStreak = n;
        }
    }
    return bestStreak;
}

int Team::getScoreDiff()const{
    int diff=0;
    for (auto const& game: teamGames){
        //if this team is home
        if((game->getHome() == name)){
            diff +=  game->homeScore() - game->awayScore();
        }
        else{
            diff +=  game->awayScore() - game->homeScore();
        }
    }
    return diff;
}

Team& Team::operator=(const Team& t2){
    if(this != &t2){
        teamGames.clear();
        for (auto const& game: t2.getGames()){
            teamGames.push_back(new Game(*game));
        }
        name = t2.getName();
        skill = t2.getSkill();
    }
    return *this;
}

void Team::addGame(const string& _home, double skillHome,const string& _away, double skillAway){
    
    teamGames.push_back(new Game(_home,skillHome,_away,skillAway));
}

double Team::getAvgPoints()const{
    int sum = 0;
    for (auto const& game: teamGames){
        //if this team is home
        if((game->getHome() == name)){
            sum +=  game->homeScore();
        }
        else{
            sum += game->awayScore();
        }
    }
    return sum/(double)teamGames.size();
}
bool Team::operator<(const Team& t2)const{
    double val1 = getWinCount()/(double)teamGames.size();
    double val2 = t2.getWinCount()/(double)t2.getGames().size();
    
    if(val1 < val2){
        return true;
    }
    if(val1 == val2){
        return getScoreDiff() < t2.getScoreDiff();
    }
    return false;

}


Team::~Team(){
    for (auto const& game: teamGames){
        delete game;
    }
}



