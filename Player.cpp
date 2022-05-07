#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <windows.h>
#include "Map.h"
#include "Player.h"
#include <time.h>
Player::Player(int x, int y):xp(x), yp(y) { }
void Player::InputChoice(Map& screen,char c,char map[][20], char bgmap[][20], int pN)
{

        char x;
        std::cin >> x;
         switch(x){
                case 'w' :        //moves 'x' up one and replaces the coord before with what it originally had
                    if(yp <= 0) yp = 0;
                    else yp -= 1;
                    map[yp + 1][xp] = bgmap[yp + 1][xp]; //replace last coord with the background map, which stays constant.
                    break;
                case 's':
                    if(yp >= 19){
                        yp = 19;
                    }else{yp+=1;}
                        map[yp - 1][xp] = bgmap[yp - 1][xp];
                    break;
                case 'a':
                    if(xp <= 0){
                        xp = 0;
                    }else{xp -=1;}
                        map[yp][xp + 1] = bgmap[yp][xp + 1];
                    break;
                case 'd':
                    if(xp >= 19){
                        xp = 19;
                    }else{xp +=1;}
                        map[yp][xp - 1] = bgmap[yp][xp - 1];
                    break;
                case 'g':
                    screen.callFire(pN);
            }
            map[yp][xp] = c; //set current position to 'x', later in this project i will be using a varible when i ask how to put in multiple players
            // and study vectors a little more(lots of learning to do!).
}
void Player::SetStartPos(char c,char map[][20])
{
    map[xp][yp] = c;
}
void Player::FireG(int pN,Map& screen,char map[][20], char bgmap[][20], int xcord, int ycord) //FIRE function
{
    int Path = 1;
    if(pN==2){
        while(map[ycord][xcord - Path] != 'G'){
            xcord -= Path;
            map[ycord][xcord] = 'H'; //this is the "Object" the player fires
            delay(100); //wait 3 seconds before refreshing the screen, this function is not completely
            //finished yet, still working on deleting the H's on the map now.
             if(map[ycord][xcord - Path] == '#')
            {
                map[ycord][xcord - Path] = '^';
                break;
            }
            screen.cls();
            screen.RefreshScreen();
        }
    }else{
        while(map[ycord][xcord + Path] != 'G' && map[ycord][xcord - Path] != '#'){

            xcord += Path;
            map[ycord][xcord] = 'H'; //this is the "Object" the player fires
            delay(100); //wait 3 seconds before refreshing the screen, this function is not completely
            //finished yet, still working on deleting the H's on the map now.
            if(map[ycord][xcord + Path] == '#')
                        {
                            map[ycord][xcord + Path] = '^';
                            break;
                        }
            screen.cls();
            screen.RefreshScreen();

        }
    }
}
  inline void Player::delay( unsigned long ms )
    {
    Sleep( ms );
    }