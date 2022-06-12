#include "Game.hpp"
#include <random>
using namespace basketball;
using namespace std;

double basketball::random(){
    srand(time(NULL));
    return rand()/RAND_MAX;
}
int basketball::randomInt(int low, int high){
    srand(time(NULL));
    return (rand() % (high-low+1)) + low;
}

int basketball::normRandom(int low,int high, double mean, double std){
    normal_distribution<> dist{mean,std};
    std::random_device rd{};
    mt19937 generator {rd()};
    double res = dist(generator);
    //make sure res is in range
    res = (high-low)*(res/dist.max()) + low;
    
    return (int)res;
}

Game::Game(string* _home, double skillHome, string* _away, double skillAway):home(_home),away(_away),winner(false){
    //mean and std sourced from https://www.teamrankings.com/nba/stat/points-per-game?date=2022-06-13
    //for years 2005 - 2021
    //run NBA_data.py for more information
    double stdHome = 2.434512325014979;
    double meanHome = 94.16310749151104;
    home_baskets = normRandom(HOME_MIN_SCORE_ROLL,MAX_SCORE_ROLL,meanHome,stdHome);

    double stdAway = 2.434512325014979;
    double meanAway = 94.16310749151104;
    away_baskets = normRandom(AWAY_MIN_SCORE_ROLL,MAX_SCORE_ROLL,meanAway,stdAway);
    //in range (-10,10)
    int bonus = (int)(10*(skillHome-skillAway));
    if(bonus<0){
        away_baskets += -bonus;
    }
    else{
        home_baskets += bonus;
    }

    if(home_baskets > away_baskets)
        winner = true;
    else if(home_baskets < away_baskets)
        winner = false;
    else{
        //winner is already false
        double rnd = random();
        //weighted coin toss based on the difference between the team's skill
        //more skilled teams have a higher chance to win in overtime
        if(rnd + (skillHome-skillAway) >= 0.5)
            winner = true;
    }
}

string& Game::getWinner(){
    return (winner)? *home:*away;
}