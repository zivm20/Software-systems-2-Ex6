#include "Game.hpp"
#include <random>
using namespace basketball;
using namespace std;


Game::Game(Team* _home, Team* _away):home(_home),away(_away){
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
    int bonus = (int)(10*(home->getSkill()-away->getSkill()));
    if(bonus<0){
        away_baskets += -bonus;
    }
    else{
        home_baskets += bonus;
    }

    if(home_baskets > away_baskets)
        winner = 1;
    else if(home_baskets < away_baskets)
        winner = 0;
    else{
        //winner is already 0
        double rnd = random();
        //weighted coin toss based on the difference between the team's skill
        //more skilled teams have a higher chance to win in overtime
        if(rnd + (home->getSkill()-away->getSkill()) >= 0.5)
            winner = 1;
    }
}

Team& Game::getWinner(){
    return (winner==1)? *home:*away;
}