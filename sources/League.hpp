
#include "Team.hpp"
#include <map>
#include <vector>

namespace basketball{
    static const size_t MAX_TEAMS = 20;
    class League{
        private:
            std::map<std::string,Team> teams; 
            
        protected:
            void processGame(Game*& game);
            void addGame(Game*& game);
            

        public:
            League();
            League(std::vector<Team>& _teams);
            League(std::vector<std::string>& _teams);
            
            inline Team& getTeam(const string& name){
                return this->teams[name];
            }
            inline std::map<std::string,Team>& getTeams(){
                return this->teams;
            }
            

            

    };
}
