#include<iostream>
#include "map.h"


int boolRand(){
    return rand()&1;
}

Pos nodeRand(int nx, int ny){  //get a random position
    int px = rand()%(nx-1);
    int py = rand()%(ny-1);
    return Pos(px,py);
}

void Map::initMap(){
    srand((int)time(0));	//random
    for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            node[i][j] = boolRand();
        }
    }
    pin = nodeRand(nrows,ncols); //entrance
    pout = nodeRand(nrows, ncols); //exit
    node[pin.x][pin.y] = entrance;
    node[pout.x][pout.y] = exits;
    cnt = 300; //initialize cnt
}

void Map::printMap(){
    cout << "+";
    for(int i=0; i<ncols; i++){
        cout << "--";
    }
    cout << "-+" << endl;
    for(int i=0; i<nrows; i++){
        cout << "| ";
        for(int j=0; j<ncols; j++){
            switch(node[i][j]){
                case notgo:
                    cout<<"* "; //CANNOT access
                    break;
                case go:
                    cout<<"  "; //CAN access
                    break;
                case entrance:
                    cout<<"E "; //entrance
                    break;
                case exits:
                    cout<<"X ";
                    break;
                case star:
                    cout<<"Q ";
                    break;
                default:
                    break;
            }
        }
        cout << "|" << endl;
    }
    cout << "+";
    for(int i=0; i<ncols; i++){
        cout << "--";
    }
    cout << "-+" << endl;
}

int dir[4][2] = {
    {1,0},  // down
    {0,-1}, // left
    {-1,0}, // up
    {0,1}   // right
};

bool check(int x, int y){
    return x<=ROWNUM && x>=0 && y<=ROWNUM && y>=0;
}

bool dfs(int map[][ROWNUM], Pos start, Pos dest){
    if(start == dest) return true;

    for(int i=0; i<4; i++){ // search in four directions
        int a = start.x + dir[i][0];
        int b = start.y + dir[i][1];
        if(check(a,b) && map[a][b]!=0){
            map[a][b] = 0;
            if(dfs(map, Pos(a,b), dest)) return true;
            map[a][b] = 1;
        }
    }
    return false;
}

bool Map::IsValid(){
    int map_temp[ROWNUM][ROWNUM];
    Pos in_temp = pin;
    Pos out_temp = pout;
    for(int i=0; i<ROWNUM; i++){
        for(int j=0; j<ROWNUM; j++){
            map_temp[i][j] = node[i][j];
        }
    }
    if(dfs(map_temp, in_temp, out_temp)) return true;
    else return false;
}

/*
+-----------------------------------------+
|     * *   * *   * *   *   *     * * *   |
|       * * * * * *   * *   *     *   * * |
| *   *       *   * *     *     * *       |
|         * *   * *     * *   * *   *   * |
| * * * * * * *   * * *   * * * *     * * |
| * *   * *     * * *   * * *       *   * |
|     * * *   *   * * * *   *   *     * * |
|       *       * *   * * *           * * |
| *   *         * * * * *   *   * *   * * |
|     * *   *     * * *   *     *     *   |
|     *   *         *   *   *     * *   * |
|       *         *   * *   *   *   *     |
| * * *           *     *   *   *     *   |
| * *   *     * * *   *   *     *         |
| *     *     * * *   * * * * * *     * * |
| * *   * *     X   *   *   * * *   *     |
|   * *     *   * *   *   *   *     * * * |
|         * * *   * * *     *   *   *   * |
|       * * *           *   *       * *   |
| *         *     * * *   * *   *   * * * |
+-----------------------------------------+
*/