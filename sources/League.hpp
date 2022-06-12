
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
            void addGame(Game*& game);

            

    };
}
