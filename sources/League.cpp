#include "League.hpp"

using namespace basketball;
using namespace std;


League::League(League& league2){
    for (auto const& team: league2.getTeams()){
        teams.insert(pair<string,Team*>(team.first,new Team(*team.second)));
    }
}
League::League(const std::vector<Team*>& _teams){
    
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            if(!_teams[i]->getGames().empty()){
                throw runtime_error("cannot initialize League with teams that have played before!");
            }
            teams.insert(pair<string,Team*>(_teams[i]->getName(),_teams[i]));
        }
        else{
            teams.insert(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
        }
    }
    
}
League::League(const std::vector<string>& _teams){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.insert(pair<string,Team*>(_teams[i],new Team{_teams[i]}));
        }
        else{
            teams.insert(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
        }
    }
}

League::League(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        teams.insert(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
    }
}

League& League::operator=(League& league2){
    if(this != &league2){
        for (auto const& team: league2.getTeams()){
            teams.insert(pair<string,Team*>(team.first,new Team(*team.second)));
        }
    }
    return *this;
}


vector<string> League::topWinners(int amount)const{
    vector<string> out;
    vector<Team*> temp;
    if(amount > MAX_TEAMS){
        throw runtime_error("Not enough teams!");
    }
    for (auto const& team: teams){
        temp.push_back(team.second);
    }
    
    //simple buble sort such that the n last numbers will be our the n largest 
    //values
    for (size_t i= 0; i < amount; i++){
        for (size_t j = 0; j < MAX_TEAMS - i - 1; j++){
            
            if (*temp[j+1] < *temp[j]){
                Team* temp2 = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = temp2;
            }
        }
        
    }

    for(size_t i = 0; i<amount; i++){
        out.push_back(temp[MAX_TEAMS-i-1]->getName());
    }
    return out;
}
int League::getSeasonLongestStreak(bool win)const{
    int bestStreak=0;
    for (auto const& team: teams){
        bestStreak = max(team.second->getLongestStreak(win),bestStreak);
    }
    return bestStreak;
}
int League::nPositiveDiff()const{
    int n=0;
    for (auto const& team: teams){
        if(team.second->getScoreDiff()>0){
            n++;
        }
    }
    return n;
}

int League::timesWonUnderDog(const string& team){
    int n = 0;
    for(auto const& game: getTeam(team).getGames()){
        //get the other team
        string opponent = (game->getAway()==team)? game->getHome():game->getAway();
        if(getTeam(team).getSkill() < getTeam(opponent).getSkill()){
            n++;
        }
    }
    return n;
}

void League::addGame(const string& _home, double skillHome,const string& _away, double skillAway){
    //printLeague();

    //cout <<_home<<"   "<< teams[_home]->getName()<<endl;
    teams[_home]->addGame(_home,skillHome,_away,skillAway);
    teams[_away]->addGame(_home,skillHome,_away,skillAway);
    
}

string League::getStats(int topNWinners){
    string out = "Teams";
    out+=string(MAX_PARAM_LEN+PARAMATER_BUFFER-out.length(),'-');
    out+= "W/L ratio";
    
    out+=string(2*(MAX_PARAM_LEN+PARAMATER_BUFFER)-out.length(),'-');
    out+= "total point diff";
    
    out+=string(3*(MAX_PARAM_LEN+PARAMATER_BUFFER)-out.length(),'-');
    out+="\n";
    vector<string> winners =  topWinners(topNWinners);
    
    
    for (auto const& team: winners){
        string team_string;
        if(team.length()>MAX_PARAM_LEN){
            team_string += team.substr(0,MAX_PARAM_LEN)+"...  ";
        }
        else{
            team_string += team + string(MAX_PARAM_LEN-team.length()+PARAMATER_BUFFER,' ');
        }
        
        string stat2 = to_string(ONE_HUNDRED*getTeam(team).getWinCount()/(double)getTeam(team).getGames().size());
        if(stat2.length()>MAX_PARAM_LEN){
            team_string += stat2.substr(0,MAX_PARAM_LEN)+"%    ";
        }
        else{
            team_string += stat2 + "%" +string(MAX_PARAM_LEN-stat2.length()+PARAMATER_BUFFER-1,' ');
        }
        team_string += to_string(getTeam(team).getScoreDiff());

        out+=team_string+"\n";
    }
    
    return out;
}
ostream& basketball::operator<<(std::ostream& output, League& league){
    output<<league.getStats(MAX_TEAMS);
    output<<"------------------------------------"<<endl;
    output<<"Longest win streak: "+to_string(league.getSeasonLongestStreak(true))<<endl;
    output<<"------------------------------------"<<endl;
    output<<"Longest lose streak: "+to_string(league.getSeasonLongestStreak(false))<<endl;
    output<<"------------------------------------"<<endl;
    output<<"Number of teams that scored more points then lost: "+to_string(league.nPositiveDiff())<<endl;
    output<<"------------------------------------"<<endl;
    output<<"Number of times each team won with less skill: "<<endl<<endl;
 
    for (auto const& team: league.getTeams()){
        output<<team.first+": ";
        output<<to_string(league.timesWonUnderDog(team.first));
        output<<endl;
    }
    output<<"------------------------------------"<<endl;
    output<<"AVG points per game: "<<endl<<endl;
   
    for (auto const& team: league.getTeams()){
        output<<team.first+": ";
        output<<league.getTeam(team.first).getAvgPoints();
        output<<endl;
    }
    output<<"------------------------------------";
    return output;
}

League::~League(){
    for (auto const& team: teams){
        delete team.second;
    }
}
