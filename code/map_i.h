#ifndef __MAP_H__
#define __MAP_H__
#define ROWNUM_UNIT 3
#define ROWNUM 3*ROWNUM_UNIT + 4

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>
#include <time.h>
using namespace std;

// int ROWNUM_UNIT = 3;
// int ROWNUM = 3*ROWNUM_UNIT + 4;
enum state{Wall, go, entrance, exits, me};

struct Pos{
    int x;
    int y;
    int loc;
    Pos(int px=0, int py=0){
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
        loc = (x-2)/ROWNUM_UNIT + 3*((y-2)/ROWNUM_UNIT);
        return loc;
    }
};

class Map{
private:
    static const int nrows = ROWNUM-4; //number of rows
    static const int ncols = ROWNUM-4; //number of columns
    int node[ROWNUM][ROWNUM]; // state of the node
    Pos pin; //position of entrance
    Pos pout; //position of exit
    int cnt; //score
public:
    map<int,string> dict;
    Map(){
        for(int i=0;i<ROWNUM;i++){
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
    ~Map(){}
    void SetExit();
    void SetEntrance();
    void dig(int px, int py);
    void initMap();
    void printMap(Pos p);
    Pos GetE();
    Pos GetX();
    bool isBlock(Pos p); // return true for wall
};

#endif /* map_h */