#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include <iostream>
class Map;
class Player //not much in this class, work in progress
{
    public:
        int getx(){return xp;};
        int gety(){return yp;};
        inline void delay( unsigned long ms );
        Player(int x, int y); //takes the players coords as parameters
        void InputChoice(Map& screen,char c,char map[][20], char bgmap[][20], int pN); //uses the current map to move across
        void SetStartPos(char c,char map[][20]); //set positions at the start so they are visible
        void FireG(int pN,Map& screen,char map[][20], char bgmap[][20], int xcord, int ycord); //fires an X horizontally across the map, uses the map and current player
        //i used the adress of the object so it would effect the current object(correct me if im wrong), i want the current xcord and ycord
        //(should those be byref? or am i just on the wrong track?)
    private:
    int xp;
    int yp;
};
#endif 
