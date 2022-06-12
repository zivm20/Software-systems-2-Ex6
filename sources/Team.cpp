#include "Team.hpp"
using namespace basketball;
using namespace std;




Team::Team(std::string _name):name(_name),skill(random()){

}
Team::Team(std::string _name, double _skill):name(_name),skill(_skill){

}
Team::~Team(){
    for (auto const& game: teamGames){
        delete game;
    }
}



