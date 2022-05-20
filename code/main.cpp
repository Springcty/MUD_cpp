#include<iostream>
#include <time.h>
#include "map.h"
#include "player.h"
using namespace std;

int main(){
    srand((int)time(NULL));	//random
    Pos P(5,8);
    Map m;
    
    m.initMap();
    m.printMap(P);
}