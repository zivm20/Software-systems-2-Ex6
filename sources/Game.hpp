#include <string>
#include <time.h>
#include <random>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#pragma once

namespace basketball{
    const int HOME_MIN_SCORE_ROLL = 55;
    const int AWAY_MIN_SCORE_ROLL = 50;
    const int MAX_SCORE_ROLL = 100;
    const int PARAMATER_BUFFER = 5;
    const int ONE_HUNDRED = 100;

    const double STDHOME = 2.434512325014979;
    const double MEANHOME = 94.16310749151104;
    const double STDAWAY = 2.434512325014979;
    const double MEANAWAY = 94.16310749151104;
    const int MAX_BONUS = 10;
    const double COIN_TOSS = 0.5;
    double random();
    int randomInt(int low=0, int high=RAND_MAX);
    int normRandom(int low,int high, double mean, double std);
    class Game{
        private:
            std::string home;
            int home_baskets;
            std::string away;
            int away_baskets;
            bool winner;
            
        public:
            Game(const Game& g2);
            Game(const std::string& _home, double skillHome,const std::string& _away, double skillAway);
            std::string getWinner()const;
            inline Game& operator=(const Game& g2){
                if(this != &g2){
                   home = g2.getHome();
                   home_baskets = g2.homeScore();
                   away = g2.getAway();
                   away_baskets = g2.awayScore();
                   winner = g2.getWinner()==g2.getHome();
                }
                return *this;
            }
            inline std::string getHome()const{
                return home;
            }
            inline std::string getAway()const{
                return away;
            }
            inline int homeScore()const{
                return home_baskets;
            }
            inline int awayScore()const{
                return away_baskets;
            }
            ~Game();
    };
}
