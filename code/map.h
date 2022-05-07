#ifndef __MAP_H__
#define __MAP_H__
#define ROWNUM 20


#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

enum state{notgo, go, entrance, exits, star};

struct Pos{
    int x;
    int y;
    Pos(int px=0, int py=0){
        x=px;
        y=py;
    }
    bool operator== (const Pos& that){
        if(x==that.x && y==that.y) return true;
        else return false;
    }
};

class Map{
private:
    static const int nrows = ROWNUM; //number of rows
    static const int ncols = ROWNUM; //number of columns
    int node[nrows][ncols]; // if the node accessible
    Pos pin; //position of entrance
    Pos pout; //position of exit
    int cnt; //score
public:
    Map(){}
    ~Map(){}
    void initMap();
    void printMap();
    bool IsValid();
};

#endif /* map_h */
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
| E   * *   *     * * *   *     *     *   |
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