#include<iostream>
#include "map.h"
#include "player.h"
using namespace std;

int main(){
    Map m;
    
    m.initMap();
    while(!m.IsValid()){
        m.initMap();
    }
    m.printMap();
}