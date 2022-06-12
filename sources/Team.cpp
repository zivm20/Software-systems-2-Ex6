#include "Team.hpp"
using namespace basketball;
using namespace std;


double basketball::random(){
    srand(time(NULL));
    return rand()/RAND_MAX;
}
int basketball::randomInt(int low=0, int high=RAND_MAX){
    srand(time(NULL));
    return (rand() % (high-low+1)) + low;
}

int basketball::normRandom(int low,int high, double mean, double std){
    normal_distribution<> dist{mean,std};
    mt19937 generator {randomInt()};
    double res = dist(generator);
    //make sure res is in range
    res = (high-low)*(res/dist.max()) + low;
    
    return (int)res;
}

Team::Team(std::string _name):name(_name),skill(random()){

}
Team::Team(std::string _name, double _skill):name(_name),skill(_skill){

}




