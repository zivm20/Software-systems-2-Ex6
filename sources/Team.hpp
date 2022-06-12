#include "Game.hpp"
#pragma once


namespace basketball{
    //helper functions for random number generations
    
    
    class Team{
        private:
            std::vector<Game*> teamGames;
            double skill;
            std::string name;
        public:
            Team(std::string _name);
            Team(std::string _name, double _skill);

            inline double getSkill() const {return skill;}
            inline std::string getName() const{return name;}
            inline void addGame(Game* game){teamGames.push_back(game);}
            inline vector<Game*> getGames()const{return teamGames;}
            inline bool operator==(const Team& t2){return name==t2.getName();}

            int getWinCount()const;
            int getLongestStreak(bool win)const;
            int getScoreDiff()const;
            double getAvgPoints()const;

            ~Team();
    };
}