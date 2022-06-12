
#include "Team.hpp"
#include <map>
#include <vector>
#pragma once

namespace basketball{
    static const size_t MAX_TEAMS = 20;
    static const size_t MAX_PARAM_LEN = 11;
    class League{
        private:
            std::map<std::string,Team*> teams; 
            
        public:
            League();
            League(const std::vector<Team*>& _teams);
            League(const std::vector<std::string>& _teams);
            
            inline Team& getTeam(const std::string& name){
                
                return *teams[name];
            }
            inline std::string* getPName(const std::string& name){
                
                return teams[name]->getPName();
            }
            inline std::map<std::string,Team*>& getTeams(){
                return teams;
            }
            std::vector<std::string> topWinners(int amount)const;
            int getSeasonLongestStreak(bool win)const;
            int nPositiveDiff()const;
            int timesWonUnderDog(std::string team);
            friend std::ostream& operator<<(std::ostream& output, League& league);
            std::string getStats(int topNWinners);

            ~League();

    };
}
