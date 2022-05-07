#include "Map.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <windows.h>
Map::Map(int pN):
pObj(5,5),
ptObj(15,15) //player TWO object
{
}
void Map::SSP() //calls player function
{
    pObj.SetStartPos('B',map);
    ptObj.SetStartPos('O',map);
}
void Map::InputChoice(int pN) //player NUMBER
{
    /* i didnt know how to access the player class outside without making another object to player, so i just made a function that
    calls the object, i need this seperate because i need to call input, THEN cls(), then refresh, in that specific order. 
    Comment if you think i should move the refresh function into map aswell to make some giant function that handles it. 
    Problem is i feel like im stuffing to much stuff into Map.h and.cpp */
    switch(pN){
        case 1:
            pObj.InputChoice(*this,'B',map,bgmap,1); //calls player functions
            break;
        case 2:
            ptObj.InputChoice(*this,'O',map,bgmap,2);
            break;
    }
}
void Map::RefreshScreen() //reprint array
{
    cls();
    for(int nrow = 0; nrow < nrows; nrow++){
            for(int ncol = 0; ncol<ncols; ncol++)
                std::cout << map[nrow][ncol] << " ";
                std::cout << std::endl;
            }
}
void Map::cls() //windows h function to replace screen with nulls
{
    DWORD n;
    DWORD size;
    COORD coord = {0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo ( h, &csbi );
    size = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( h, &csbi );
    FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );
    SetConsoleCursorPosition ( h, coord );
}
void Map::callFire(int pN)
{
    switch(pN){
        case 1:
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            pObj.FireG(1,*this, map, bgmap, pObj.getx(), pObj.gety()); //ERRORS HERE!
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            break;
        case 2:
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            ptObj.FireG(2,*this, map, bgmap,ptObj.getx(),ptObj.gety()); //ERRORS HERE!
        //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            break;
    }
}
void Map::createmap() { //read map in from "Map.txt" file
    using namespace std;
    ifstream MapStruct("Map.txt");
    while(!MapStruct.eof()){
        for( int nrow = 0; nrow < nrows; nrow++){
            for(int ncol = 0; ncol < ncols;ncol++){
                    MapStruct >> map[nrow][ncol];
                    bgmap[nrow][ncol] = map[nrow][ncol];
                }
            }
        }
    MapStruct.close(); //close file to prevent leaks
}
