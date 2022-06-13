#include "Schedule.hpp"
using namespace basketball;
using namespace std;

Schedule::Schedule():round(0){
    init();
}

Schedule::Schedule(const vector<Team*>& _teams):League(_teams),round(0){
    init();
}
Schedule::Schedule(const vector<string>& _teams):League(_teams),round(0){
    init();
}


void Schedule::init(){
    size_t i = 0;
    for (auto const& team: getTeams()){
        matchups[i/(MAX_TEAMS/2)][i%(MAX_TEAMS/2)] = team.first;
        i++;
    }
    
}

void Schedule::roundRobin(){
    if(round < 2*(MAX_TEAMS-1)){
        //the last number in the top array and first in the bottom array will get overwritten
        //example for [[0, 1, 2, 3],[4, 5, 6, 7]]
        string temp1 = matchups[0][MAX_TEAMS/2 -1]; //3
        string temp2 = matchups[1][0]; //4

        for(size_t i = 0; i<MAX_TEAMS/2 -1; i++){
            //[0, 1, 2, 3] -> [0, 1, 2, 2] -> [0, 1, 1, 2] -> [0, 0, 1, 2]
            matchups[0][MAX_TEAMS/2 - 1 -i] = matchups[0][MAX_TEAMS/2-2-i];
            //[4, 5, 6, 7] -> [5, 5, 6, 7] -> [5, 6, 6, 7] -> [5, 6, 7, 7]
            matchups[1][i] = matchups[1][i+1];
            
        }
        //[[0, 0, 1, 2],
        // [5, 6, 7, 7]]

        //we want to keep matchups[0][0] the same
        //so we set the next matchup to temp2 instead
        matchups[0][1] = temp2;
        //[[0, 4, 1, 2],
        // [5, 6, 7, 7]]

        //value that used to be in the top right should now be in the bottom right
        matchups[1][MAX_TEAMS/2 -1] = temp1;
        //[[0, 4, 1, 2],
        // [5, 6, 7, 3]]

        //process this round
        processRound();
        
        round++;
    }
    
    
}
void Schedule::processRound(){
    for(size_t i = 0; i<MAX_TEAMS/2; i++){

        //after MAX_TEAMS -1 rounds we are now repeating the cycle so now we will
        //switch the home and away teams
        if(round >= MAX_TEAMS -1){
            addGame(getTeam(matchups[1][i]).getName(),
                    getTeam(matchups[1][i]).getSkill(),
                    getTeam(matchups[0][i]).getName(), 
                    getTeam(matchups[0][i]).getSkill());
            
        }
        else{
            addGame(getTeam(matchups[0][i]).getName(),
                    getTeam(matchups[0][i]).getSkill(),
                    getTeam(matchups[1][i]).getName(), 
                    getTeam(matchups[1][i]).getSkill());
            
        }
       
        
    }

}


void Schedule::endGame(){
    while(round < 2*(MAX_TEAMS-1)){
        roundRobin();
    }
}






