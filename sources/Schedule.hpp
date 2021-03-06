#include "League.hpp"
#include <map>
#include <vector>
#pragma once

namespace basketball{
    class Schedule:public League{
        
        private:
            std::string matchups[2][MAX_TEAMS/2];
            size_t round;
            void init();
            void processRound();
            void roundRobin();
            void endGame();
            
            
        public:
            Schedule();
            
            Schedule(const std::vector<Team*>& _teams);
            Schedule(const std::vector<std::string>& _teams);
            
            
            
            inline size_t getRound()const{return round;}
            

    };
}
