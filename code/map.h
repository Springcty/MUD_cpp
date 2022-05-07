#ifndef __MAP_H__
#define __MAP_H__

struct Pos{
    int x;
    int y;
    Pos(int px=0, int py=0){
        x=px;
        y=py;
    }
};

class Map{
private:
    static const int nrows = 20; //number of rows
    static const int ncols = 20; //number of columns
    bool node[nrows][ncols]; // if the node accessible
    struct Pos pin; //position of entrance
    struct Pos pout; //position of exit
public:
    Map(){
        //init

    }
    ~Map(){}
};


#endif /* map_h */