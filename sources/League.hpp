
#include "Team.hpp"
#include <map>
#include <vector>

namespace basketball{
    static const size_t MAX_TEAMS = 20;
    class League{
        private:
            std::map<std::string,Team> teams; 
            
        public:
            League();
            League(const std::vector<Team>& _teams);
            League(const std::vector<std::string>& _teams);
            
            inline Team& getTeam(const string& name){
                return this->teams[name];
            }
            inline std::map<std::string,Team>& getTeams(){
                return this->teams;
            }
            std::vector<std::string> topWinners(int amount)const;
            int getSeasonLongestStreak(bool win)const;
            int nPositiveDiff()const;
            friend ostream& operator<<(std::ostream& output, const League& league);
            std::string getStats(int topNWinners)const;

            

    };
}
