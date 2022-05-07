#ifndef __MAP_H__
#define __MAP_H__
#define ROWNUM 20


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
    bool IsValid();
};


#endif /* map_h */