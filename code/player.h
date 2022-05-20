#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <cstdlib>
#include "map.h"
using namespace std;

#define MOVENUM 20

class Player{
private:
    Pos temp;
    Pos x;
public:
    Player(Pos e, Pos x): temp(e), x(x) { }
    // Pos GetPos();
    void move(string d);
    void play(Map m);
};

#endif