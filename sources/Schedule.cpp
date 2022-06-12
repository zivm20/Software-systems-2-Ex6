#include "Schedule.hpp"
using namespace basketball;
using namespace std;

Schedule::Schedule():League(){
    init();
}

Schedule::Schedule(vector<Team>& _teams):League(_teams){
    init();
}
Schedule::Schedule(vector<string>& _teams):League(_teams){
    init();
}

void Schedule::init(){
    for(size_t i = 0; i<MAX_TEAMS/2; i++){
        matchups[0][i] = i;
        matchups[1][i] = i+MAX_TEAMS/2;
    }
}

void Schedule::roundRobin(){
    if(round < 2*(MAX_TEAMS-1)){
        //the last number in the top array and first in the bottom array will get overwritten
        //example for [[0, 1, 2, 3],[4, 5, 6, 7]]
        int temp1 = matchups[0][MAX_TEAMS/2 -1]; //3
        int temp2 = matchups[1][0]; //4

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
        Team team1 = getTeam(matchups[0][i]);
        Team team2 = getTeam(matchups[1][i]);
        //after MAX_TEAMS -1 rounds we are now repeating the cycle so now we will
        //switch the home and away teams
        if(round >= MAX_TEAMS -1){
            team1 = getTeam(matchups[1][i]);
            team2 = getTeam(matchups[0][i]);
        }
        Game* newGame = new Game(&team1,&team2);
        //handle processing the game
        processGame(newGame);
        addGame(newGame);
    }

}


void Schedule::endGame(){
    while(round < 2*(MAX_TEAMS-1)){
        roundRobin();
    }
}






