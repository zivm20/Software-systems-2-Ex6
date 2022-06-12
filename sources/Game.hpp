#include <string>
#include <time.h>
#include <random>
#include <algorithm>
#include <iostream>
#include <stdexcept>
namespace basketball{
    const int HOME_MIN_SCORE_ROLL = 55;
    const int AWAY_MIN_SCORE_ROLL = 50;
    const int MAX_SCORE_ROLL = 55;
    double random();
    int randomInt(int low=0, int high=RAND_MAX);
    int normRandom(int low,int high, double mean, double std);
    class Game{
        private:
            string* home;
            int home_baskets;
            string* away;
            int away_baskets;
            bool winner;
            
        public:
            Game(string* _home, double skillHome, string* _away, double skillAway);
            string& getWinner();
            
            inline string& getHome(){
                return *home;
            }
            inline string& getAway(){
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
