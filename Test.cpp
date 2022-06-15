#include "doctest.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "sources/Schedule.hpp"
using namespace basketball;
using namespace std;






TEST_CASE("tests") {
    int high = 100;
    int low = 50;
    for(int i=0; i<1000; i++){
        int random_int = normRandom(low,high,basketball::random()+randomInt(),basketball::random()+randomInt());
        CHECK((low<=random_int && random_int<=high));
    }


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
    
    Schedule s{myTeams};
    CHECK_THROWS(Schedule s{myTeams});
    
    
    CHECK_THROWS(Team team1("Golden State Warriors", -0.5));
    CHECK_THROWS(Team team1("Golden State Warriors", 1.5));
    CHECK_NOTHROW(Team team1("Golden State Warriors"));
    vector<string> myTeams2;
    myTeams2.push_back("idk");
    CHECK_NOTHROW(Schedule s2{myTeams2});
    

    for (auto const& team: s.getTeams()){
        CHECK(team.second->getGames().size()==38);//everyone should have 38 games
    }
    cout<<s<<endl;
    

    
}


