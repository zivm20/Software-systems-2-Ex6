#include "sources/Schedule.hpp"
#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/League.hpp"
#include <vector>
using namespace std;
using namespace basketball;

int main(){
    vector<Team*> myTeams;
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));

    League myLeague{myTeams};


    return 0;
}

