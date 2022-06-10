#include<iostream>
#include "map.h"


int boolRand(){
    return rand()&1;
}

int intRand(int lower, int upper){
    return lower + rand() % (upper - lower + 1);
}

Pos Map::GetE(){
    return pin;
}

Pos Map::GetX(){
    return pout;
}

bool Map::isBlock(Pos p){ // return true for wall
    return !node[p.x][p.y];
}

void Map::SetExit(){  //get a random position
    int t1 = intRand(1+2*ROWNUM_UNIT+1,nrows-1+2);
    int t2 = intRand(1+ROWNUM_UNIT+1,2*ROWNUM_UNIT-1+2);
    int flag = boolRand();
    if(flag){
        pout = Pos(t1,t2);
    }
    else{
        pout = Pos(t2,t1);
    }
}

void Map::SetEntrance(){
    int flag = intRand(0,6);
    if(flag==5)flag=8;
    switch(flag){
        case 0:
            pin = Pos(intRand(2,1+ROWNUM_UNIT),intRand(2,1+ROWNUM_UNIT));
            break;
        case 1:
            pin = Pos(intRand(2+ROWNUM_UNIT,1+2*ROWNUM_UNIT),intRand(2,1+ROWNUM_UNIT));
            break;
        case 2:
            pin = Pos(intRand(2+2*ROWNUM_UNIT,1+3*ROWNUM_UNIT),intRand(2,1+ROWNUM_UNIT));
            break;
        case 3:
            pin = Pos(intRand(2,1+ROWNUM_UNIT),intRand(2+ROWNUM_UNIT,1+2*ROWNUM_UNIT));
            break;
        case 4:
            pin = Pos(intRand(2+ROWNUM_UNIT,1+2*ROWNUM_UNIT),intRand(2+ROWNUM_UNIT,1+2*ROWNUM_UNIT));
            break;
        case 6:
            pin = Pos(intRand(2,1+ROWNUM_UNIT),intRand(2+2*ROWNUM_UNIT,1+3*ROWNUM_UNIT));
            break;
        case 8:
            pin = Pos(intRand(2+2*ROWNUM_UNIT,1+3*ROWNUM_UNIT),intRand(2+2*ROWNUM_UNIT,1+3*ROWNUM_UNIT));
            break;
        default:
            break;
    }
}

void Map::initMap(){
    for (int i = 0; i<ROWNUM; ++i) {
		node[i][ROWNUM-1] = go;
		node[ROWNUM-1][i] = go;
		node[i][0] = go;
		node[0][i] = go;
	}
    SetExit();
    SetEntrance();
    dig(pout.x, pout.y);
    node[pin.x][pin.y]=entrance;
    node[pout.x][pout.y]=exits;
}

void Map::dig(int px, int py){ // start from (px,py)
    if(node[px][py] == Wall){
        if (node[px+1][py] + node[px-1][py] + node[px][py+1] + node[px][py-1] <= go) {
			node[px][py] = go;

			int dir[4] = {0,1,2,3};
			for (int i=3; i>=0; --i) {
				int r = rand()%(i+1);
				swap(dir[r], dir[i]);

				switch (dir[i]) {
				case 0:
					dig(px-1, py); //left
					break;
				case 1:
					dig(px+1, py); //right
					break;
				case 2:
					dig(px, py-1); //down
					break;
				case 3:
					dig(px, py+1); //up
					break;
				default:
					break;
				}
			}
		}
    }
}

void Map::printMap(Pos p){
    node[p.x][p.y] = me;
    cout << "+";
    for(int i=0; i<ncols; i++){
        cout << "--";
    }
    cout << "-+" << endl;
    for(int i=0; i<nrows; i++){
        cout << "| ";
        for(int j=0; j<ncols; j++){
            switch(node[j+2][i+2]){
                case Wall:
                    cout<<"* "; //CANNOT access
                    break;
                case go:
                    cout<<"  "; //CAN access
                    break;
                case entrance:
                    cout<<"E "; //entrance
                    break;
                case exits:
                    cout<<"X "; //exit
                    break;
                case me:
                    cout<<"P ";
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
