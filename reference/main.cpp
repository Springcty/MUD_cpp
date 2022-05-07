<<<<<<< HEAD:main.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <windows.h>
#include "Map.h"
#include "Player.h"
#include "concol.h"
bool Game = true;
bool pOneTurn = true;
bool pTwoTurn = false;
int main()
{

    Map mObj(2);
    mObj.createmap();
    mObj.SSP();
    mObj.RefreshScreen();
    while(Game){ //while the game is running
        while(pOneTurn){ //player ones turn
            int moves = 0;
            while(moves <3){
                setcolor(red,backcolor());
                std::cout << "PLAYER ONE w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)"; //display controls and stats
                std::cout << "\n --- MOVES LEFT --- " << 3 - moves << std::endl;
                setcolor(white,backcolor());
                mObj.InputChoice(1); //run input function to see where to move
                mObj.RefreshScreen(); //rewrite the array
                moves++;
            }
            mObj.RefreshScreen();
            pTwoTurn = true; //set player twos turn to true
            pOneTurn = false; //set player ones turn to false
        }
        while(pTwoTurn){
            int moves=0;
            while(moves < 3){
                setcolor(green,backcolor());
                std::cout << "PLAYER TWO w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)";
                std::cout << "\n --- MOVES LEFT --- " << 3-moves << std::endl;
                setcolor(yellow,backcolor());
                mObj.InputChoice(2);
                setcolor(white,backcolor());
                mObj.RefreshScreen();
                moves++;
            }
            mObj.RefreshScreen();
            pOneTurn = true;
            pTwoTurn = false;
        }
    }
=======
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <windows.h>
#include "Map.h"
#include "Player.h"
#include "concol.h"
bool Game = true;
bool pOneTurn = true;
bool pTwoTurn = false;
int main()
{

    Map mObj(2);
    mObj.createmap();
    mObj.SSP();
    mObj.RefreshScreen();
    while(Game){ //while the game is running
        while(pOneTurn){ //player ones turn
            int moves = 0;
            while(moves <3){
                setcolor(red,backcolor());
                std::cout  << "PLAYER ONE w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)"; //display controls and stats
                std::cout  << "\n --- MOVES LEFT --- " << 3 - moves << std::endl;
                setcolor(white,backcolor());
                mObj.InputChoice(1); //run input function to see where to move
                mObj.RefreshScreen(); //rewrite the array
                moves++;
            }
            mObj.RefreshScreen();
            pTwoTurn = true; //set player twos turn to true
            pOneTurn = false; //set player ones turn to false
        }
        while(pTwoTurn){
            int moves=0;
            while(moves < 3){
                setcolor(green,backcolor());
                std::cout << "PLAYER TWO w(UP) s(DOWN) a(LEFT) d(RIGHT) g(SHOOT)";
                std::cout << "\n --- MOVES LEFT --- " << 3-moves << std::endl;
                setcolor(yellow,backcolor());
                mObj.InputChoice(2);
                setcolor(white,backcolor());
                mObj.RefreshScreen();
                moves++;
            }
            mObj.RefreshScreen();
            pOneTurn = true;
            pTwoTurn = false;
        }
    }
>>>>>>> 0b9a4a49cd10e48ab2ad4dd3f70abd0627d73b80:reference/main.cpp
}