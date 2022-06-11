#ifndef __MAP_H__
#define __MAP_H__
#define ROWNUM_UNIT_P 3
#define ROWNUM_P 3*ROWNUM_UNIT_P + 4
#define ROWNUM_UNIT_I 6
#define ROWNUM_I 3*ROWNUM_UNIT_I + 4

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>
#include <time.h>
using namespace std;

enum state{Wall, go, entrance, exits, me};

struct Pos{
    int x;
    int y;
    int mode;
    int loc;
    Pos(int m, int px=0, int py=0){
        mode = m;
        x=px;
        y=py;
        loc = UpdateLoc();
    }
    bool operator== (const Pos& that){
        if(x==that.x && y==that.y) return true;
        else return false;
    }
    bool operator!=(const Pos& that){
        if(x!=that.x || y!=that.y) return true;
        else return false;
    }
    inline int UpdateLoc(){
        if(mode==0) loc = (x-2)/ROWNUM_UNIT_P + 3*((y-2)/ROWNUM_UNIT_P);
        else loc = (x-2)/ROWNUM_UNIT_I + 3*((y-2)/ROWNUM_UNIT_I);
        return loc;
    }
};

class Map{
private:
    int nrows; // number of rows
    int ncols; // number of columns
    int **node; // state of node
    Pos pin; //position of entrance
    Pos pout; //position of exit

    int mode; // mode 0(primary), 1(inferno)
    int ROWNUM;
    int ROWNUM_UNIT;
public:
    map<int,string> dict;
    Map(int mode):pin(mode), pout(mode){
        this->mode = mode;
        ROWNUM = mode ? ROWNUM_I : ROWNUM_P;
        ROWNUM_UNIT = mode ? ROWNUM_UNIT_I : ROWNUM_UNIT_P;
        nrows = ROWNUM - 4;
        ncols = ROWNUM - 4;
        node = new int*[ROWNUM];
        for(int i=0;i<ROWNUM;i++){
            node[i] = new int[ROWNUM];
            for(int j=0;j<ROWNUM;j++){
                node[i][j] = Wall;
            }
        }
        dict[0] = "Lantian Hall";
        dict[1] = "GangWan Community";
        dict[2] = "Swimming Pool";
        dict[3] = "Qiushi Lecture Hall";
        dict[4] = "West Building";
        dict[5] = "East Building";
        dict[6] = "Yuhu Hall";
        dict[7] = "Graduate School Building";
        dict[8] = "Agriculture & Medicine Library";
    }
    virtual ~Map(){
        for(int i=0; i<ROWNUM; i++){
            delete [] node[i];
        }
        delete []node;
    }
    virtual void SetExit();
    virtual void SetEntrance();
    virtual void dig(int px, int py);
    virtual void initMap();
    virtual void printMap(Pos p);
    virtual Pos GetE();
    virtual Pos GetX();
    virtual bool isBlock(Pos p); // return true for wall
};

#endif /* map_h */