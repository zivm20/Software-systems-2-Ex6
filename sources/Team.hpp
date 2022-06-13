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
            Team(const std::string& _name);
            Team(const std::string& _name, const double& _skill);
            Team(const Team& t2);
            Team& operator=(const Team& t2);
            inline double getSkill() const {return skill;}
            inline std::string getName() const{return name;}
            
            void addGame(const std::string& _home, double skillHome,const std::string& _away, double skillAway);
            inline std::vector<Game*> getGames()const{return teamGames;}
            inline bool operator==(const Team& t2){return name==t2.getName();}
            bool operator<(const Team& t2)const;
            
            int getWinCount()const;
            int getLongestStreak(bool win)const;
            int getScoreDiff()const;
            double getAvgPoints()const;

            ~Team();
    };
}