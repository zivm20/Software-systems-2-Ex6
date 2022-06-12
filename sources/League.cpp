#include "League.hpp"

using namespace basketball;
using namespace std;



League::League(const std::vector<Team>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            if(_teams[i].getGames().size() > 0){
                throw runtime_error("cannot initialize League with teams that have played before!");
            }
            teams.emplace(pair<string,Team>(_teams[i].getName(),_teams[i]));
        }
        else{
            teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
        }
    }
}
League::League(const std::vector<string>& _teams):teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        if(i<_teams.size()){
            teams.emplace(pair<string,Team>(_teams[i],Team{_teams[i]}));
        }
        else{
            teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
        }
    }
}

League::League(): teams(){
    for(size_t i = 0; i<MAX_TEAMS; i++){
        teams.emplace(pair<string,Team>("NoName "+i,Team{"NoName "+i}));
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
                int wins = team.second.getWinCount();
                int losses = wins - team.second.getGames().size();
                double ratio = 100*wins/(double(wins+losses));
                if(bestRatio < ratio){
                    bestTeam = team.first;
                    bestRatio = ratio;
                    bestDiff = team.second.getScoreDiff();
                }
                else if(bestRatio == ratio){
                    int diff = team.second.getScoreDiff();
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
    
}
int League::getSeasonLongestStreak(bool win)const{
    int bestStreak;
    for (auto const& team: teams){
        bestStreak = max(team.second.getLongestStreak(win),bestStreak);
    }
    return bestStreak;
}
int League::nPositiveDiff()const{
    int n;
    for (auto const& team: teams){
        if(team.second.getScoreDiff()>0){
            n++;
        }
    }
    return n;
}
string League::getStats(int topNWinners)const{
    string out = "-----Teams-----\n";
    vector<string> winners =  topWinners(topNWinners);
    for (auto const& team: winners){
        out+=team+"\n";
    }
    out+="-----Longest win streak-----\n"+getSeasonLongestStreak(true);
    out+="\n";
    out+="-----Longest lose streak-----\n"+getSeasonLongestStreak(false);
    out+="\n";
    out+="-----Number of teams that scored more points then lost-----\n"+nPositiveDiff();
    out+="\n";
    return out;
}
ostream& basketball::operator<<(std::ostream& output, const League& league){
    output<<league.getStats(MAX_TEAMS);
    


    return output;
}


