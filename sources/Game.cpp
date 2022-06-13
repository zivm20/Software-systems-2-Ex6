#include "Game.hpp"
#include <random>
using namespace basketball;
using namespace std;

double basketball::random(){
    std::random_device rd{};
    mt19937 generator {rd()};
    return rand()/(double)RAND_MAX;
}
int basketball::randomInt(int low, int high){
    std::random_device rd{};
    mt19937 generator {rd()};
    return (rand() % (high-low+1)) + low;
}

int basketball::normRandom(int low,int high, double mean, double std){
    normal_distribution<> dist{mean,std};
    std::random_device rd{};
    mt19937 generator {rd()};
    double res = 0;
    //make sure res is in range
    do{
        res = dist(generator);
        
    }while(res > high || res<low);

    return (int)res;
}
std::string home;
int home_baskets;
std::string away;
int away_baskets;
bool winner;
Game::Game(const Game& g2): home(g2.getHome()), home_baskets(g2.homeScore()), away(g2.getAway()), away_baskets(g2.awayScore()), winner(g2.getWinner()==g2.getHome()){

}
Game::Game(const string& _home, double skillHome,const string& _away, double skillAway):home(_home),away(_away),winner(false){
    //mean and std sourced from https://www.teamrankings.com/nba/stat/points-per-game?date=2022-06-13
    //for years 2005 - 2021
    //run NBA_data.py for more information
    double stdHome = STDHOME;
    double meanHome = MEANHOME;
    home_baskets = normRandom(HOME_MIN_SCORE_ROLL,MAX_SCORE_ROLL,meanHome,stdHome);

    double stdAway = STDAWAY;
    double meanAway = MEANAWAY;
    away_baskets = normRandom(AWAY_MIN_SCORE_ROLL,MAX_SCORE_ROLL,meanAway,stdAway);
    //in range (-10,10)
    int bonus = (int)(MAX_BONUS*(skillHome-skillAway));
    if(bonus<0){
        away_baskets += -bonus;
    }
    else{
        home_baskets += bonus;
    }

    if(home_baskets > away_baskets){
        winner = true;
    }
    else if(home_baskets < away_baskets){
        winner = false;
    }
    else{
        //winner is already false
        double rnd = random();
        //weighted coin toss based on the difference between the team's skill
        //more skilled teams have a higher chance to win in overtime
        if(rnd + (skillHome-skillAway) >= COIN_TOSS){
            winner = true;
        }
    }
}

string Game::getWinner()const{
    return (winner)? home:away;
}
Game::~Game(){
    
}