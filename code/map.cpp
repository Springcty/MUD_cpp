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