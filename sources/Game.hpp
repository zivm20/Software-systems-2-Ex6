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
    const int MAX_SCORE_ROLL = 55;
    double random();
    int randomInt(int low=0, int high=RAND_MAX);
    int normRandom(int low,int high, double mean, double std);
    class Game{
        private:
            std::string* home;
            int home_baskets;
            std::string* away;
            int away_baskets;
            bool winner;
            
        public:
            Game(std::string* _home, double skillHome, std::string* _away, double skillAway);
            std::string& getWinner();
            
            inline std::string& getHome(){
                return *home;
            }
            inline std::string& getAway(){
                return *away;
            }
            inline int homeScore()const{
                return home_baskets;
            }
            inline int awayScore()const{
                return away_baskets;
            }

    };
}
