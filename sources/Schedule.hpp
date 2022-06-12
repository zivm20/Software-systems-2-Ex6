#include "League.hpp"
#include <map>
#include <vector>
#pragma once

namespace basketball{
    class Schedule:public League{
        
        private:
            std::string matchups[2][MAX_TEAMS/2];
            size_t round;
            League league;
            void init();
            void processRound();
            void addGame(Game*& game);
            
        public:
            Schedule();
            Schedule(const League& _league);
            Schedule(const std::vector<Team*>& _teams);
            Schedule(const std::vector<std::string>& _teams);
            void roundRobin();
            void endGame();
            
            
            inline size_t getRound(){return round;}
            

    };
}
