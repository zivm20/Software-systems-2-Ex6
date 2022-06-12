#include "Team.hpp"

namespace basketball{
    const int HOME_MIN_SCORE_ROLL = 55;
    const int AWAY_MIN_SCORE_ROLL = 50;
    const int MAX_SCORE_ROLL = 55;
    class Game{
        private:
            Team* home;
            int home_baskets;
            Team* away;
            int away_baskets;
            int winner;
            
        public:
            Game(Team* _home, Team* _away);
            Team& getWinner();
            
            inline Team& getHome(){
                return *home;
            }
            inline Team& getAway(){
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
