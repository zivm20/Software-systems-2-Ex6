
#include "Team.hpp"
#include <map>
#include <vector>
#pragma once

namespace basketball{
    static const size_t MAX_TEAMS = 20;
    static const size_t MAX_PARAM_LEN = 20;
    class League{
        private:
            std::map<std::string,Team*> teams;
        protected:
            void addGame(const std::string& _home, double skillHome,const std::string& _away, double skillAway);

            
        public:
            League();
            League(const std::vector<Team*>& _teams);
            League(const std::vector<std::string>& _teams);
            League(League& league2);
            
            inline Team& getTeam(const std::string& name){
                
                return *teams[name];
            }
            League& operator=(League& league2);
            inline std::map<std::string,Team*>& getTeams(){
                return teams;
            }
            std::vector<std::string> topWinners(int amount)const;
            int getSeasonLongestStreak(bool win)const;
            int nPositiveDiff()const;
            int timesWonUnderDog(const std::string& team);
            friend std::ostream& operator<<(std::ostream& output, League& league);
            std::string getStats(int topNWinners);

            inline void printLeague(){
                for (auto const& team: getTeams()){
                    std::cout<<team.first<<", "<<team.second->getName()<<std::endl;
                }
            }

            ~League();

    };
}
