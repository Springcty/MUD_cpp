#include<iostream>
#include "map.h"
using namespace std;

int dir[4][2] = {
    {1,0},  // down
    {0,-1}, // left
    {-1,0}, // up
    {0,1}   // right
};
bool check(int x, int y){
    return x<=ROWNUM && x>=0 && y<=ROWNUM && y>=0;
}

bool dfs(bool map[][ROWNUM], Pos start, Pos dest){
    if(start == dest) return true;

    for(int i=0; i<4; i++){ // search in four directions
        int a = start.x + dir[i][0];
        int b = start.y + dir[i][1];
        if(check(a,b) && !map[a][b]){
            map[a][b] = 1;
            if(dfs(map, Pos(a,b), dest)) return true;
            map[a][b] = 0;
        }
    }
    // s.pop(); // if all of the four directions are walls,
    return false;
}

Map::IsValid(){
    if(dfs(node, pin, pout)) return true;
    else return false;
}