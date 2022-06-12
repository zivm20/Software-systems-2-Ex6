#include "League.hpp"

using namespace basketball;
using namespace std;



League::League(const std::vector<Team*>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            if(_teams[i]->getGames().size() > 0){
                throw runtime_error("cannot initialize League with teams that have played before!");
            }
            teams.emplace(pair<string,Team*>(_teams[i]->getName(),_teams[i]));
        }
        else{
            teams.emplace(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
        }
    }
}
League::League(const std::vector<string>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.emplace(pair<string,Team*>(_teams[i],new Team{_teams[i]}));
        }
        else{
            teams.emplace(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
        }
    }
}

League::League(): teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        teams.emplace(pair<string,Team*>("NoName "+to_string(i),new Team{"NoName "+to_string(i)}));
    }
}

vector<string> League::topWinners(int amount)const{
    vector<string> out;
    if(amount > MAX_TEAMS){
        throw runtime_error("Not enough teams!");
    }
    for(size_t i = 0; i<amount; i++){
        double bestRatio = 0;
        double bestDiff = INT32_MAX;
        string bestTeam;
        for (auto const& team: teams){
            if(std::find(out.begin(), out.end(), team.first) != out.end()){
                int wins = team.second->getWinCount();
                int losses = wins - (int)team.second->getGames().size();
                double ratio = 100*wins/((double)(wins+losses));
                if(bestRatio < ratio){
                    bestTeam = team.first;
                    bestRatio = ratio;
                    bestDiff = team.second->getScoreDiff();
                }
                else if(bestRatio == ratio){
                    int diff = team.second->getScoreDiff();
                    if(diff < bestDiff){
                        bestTeam = team.first;
                        bestRatio = ratio;
                        bestDiff = diff;
                    }
                }
            }

        }
        out.push_back(bestTeam);
    }
    return out;
}
int League::getSeasonLongestStreak(bool win)const{
    int bestStreak;
    for (auto const& team: teams){
        bestStreak = max(team.second->getLongestStreak(win),bestStreak);
    }
    return bestStreak;
}
int League::nPositiveDiff()const{
    int n;
    for (auto const& team: teams){
        if(team.second->getScoreDiff()>0){
            n++;
        }
    }
    return n;
}

int League::timesWonUnderDog(string team){
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


string League::getStats(int topNWinners){
    string out = "Teams-----------W/L ratio-------total point diff\n";
    vector<string> winners =  topWinners(topNWinners);
    for (auto const& team: winners){
        string team_string;
        if(team.length()>MAX_PARAM_LEN){
            team_string += team.substr(0,MAX_PARAM_LEN)+"...  ";
        }
        else{
            team_string += team + string(MAX_PARAM_LEN-team.length()+5,' ');
        }
        string stat2 = to_string(100*getTeam(team).getWinCount()/(double)getTeam(team).getGames().size());
        if(stat2.length()>MAX_PARAM_LEN){
            team_string += stat2.substr(0,MAX_PARAM_LEN)+"%    ";
        }
        else{
            team_string += stat2 + "%" +string(MAX_PARAM_LEN-stat2.length()+4,' ');
        }
        team_string += to_string(getTeam(team).getScoreDiff());

        out+=team_string+"\n";
    }
    out+="Longest win streak: "+to_string(getSeasonLongestStreak(true));
    out+="\n";
    out+="Longest lose streak: "+to_string(getSeasonLongestStreak(false));
    out+="\n";
    out+="Number of teams that scored more points then lost: "+to_string(nPositiveDiff());
    out+="\n";
    out+="Number of times each team won with less skill: ";
    out+="\n";
    for (auto const& team: winners){
        out+=team+": ";
        out+=to_string(timesWonUnderDog(team));
        out+="\n";
    }
    out+="AVG points per game: ";
    out+="\n";
    for (auto const& team: winners){
        out+=team+": ";
        out+=getTeam(team).getAvgPoints();
        out+="\n";
    }
    return out;
}
ostream& basketball::operator<<(std::ostream& output, League& league){
    output<<league.getStats(MAX_TEAMS);
    
    return output;
}

League::~League(){
    for (auto const& team: teams){
        delete team.second;
    }
}
