#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <windows.h>
#include "map.h"
using namespace std;

#define MOVENUM 10
#define ROBOT  "Little Ice: "
#define PLAYER "Player:     "

class Player{
private:
    Pos temp; // current pos
    Pos x; // exit of the maze
public:
    Player(Pos e, Pos x): temp(e), x(x) { }
    void move(string d); // move one step to d(N,E,S,W)
    void play(Map m); // play in the map m
};

void color_print(string s, int color);
/*
0=black
1=blue
2=green
3=light green
7=white
*/
#endif