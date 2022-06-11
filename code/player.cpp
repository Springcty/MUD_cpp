#include<iostream>
#include "player.h"
#include "map.h"
using namespace std;

void color_print(string s, int color){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    cout << s;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

void Player::move(string d){
    switch (d[0])
    {
    case 'N': // up
        temp.y--;
        break;
    case 'E': // right
        temp.x++;
        break;
    case 'S': // down
        temp.y++;
        break;
    case 'W': // left
        temp.x--;
        break;
    default:
        break;
    }
}

void Player::play(Map m, int mode){
    int play_cnt = 0;
    int MOVENUM = mode ? MOVENUM_I : MOVENUM_P;
    while(temp != x){
        color_print(ROBOT, 1);
        cout << "You can choose ";
        Pos a = temp;
        string s = ""; // remember the dirction able to move
        a.y --;
        if(!m.isBlock(a)){
            cout << "North(N) ";
            s += "N";
        }
        a.y ++; a.x ++;
        if(!m.isBlock(a)){
            cout << "East(E) ";
            s += "E";
        }
        a.x --; a.y ++;
        if(!m.isBlock(a)){
            cout << "South(S) ";
            s += "S";
        }
        a.y --; a.x --;
        if(!m.isBlock(a)){
            cout << "West(W) ";
            s += "W";
        }
        cout << "to go" << endl;
        
        string d;
        color_print(PLAYER, 2);
        cin >> d;
        if(s.find(d) != s.npos) move(d); // check if d is valid
        else if(d=="help"){ // help mode: print current map
            m.printMap(temp);
        }
        else if(d=="exit") exit(1);
        else{
            color_print(ROBOT, 1);
            cout << "This direction is blocked! Choose another please~" << endl;
        }

        int i_loc = temp.loc;
        temp.UpdateLoc();
        // cout << temp.x << "," << temp.y << "  " << temp.loc << endl;
        // show when the player comes a new place
        if(temp.loc != i_loc){
            color_print(ROBOT, 1);
            cout << "You've arrived at ";
            color_print(m.dict[temp.loc], 6);
            cout << "! Keep Going ~" << endl;
        }

        // show the steps remained
        play_cnt ++;
        color_print(ROBOT, 1);
        cout << MOVENUM - play_cnt << " steps left\n" << endl;
        if(play_cnt==MOVENUM) break;
    }
    color_print(ROBOT, 1);
    if(play_cnt==MOVENUM){
        color_print("Game Over!", 4);
        cout << endl;
        color_print(ROBOT, 1);
        color_print("Sorry, your health code is failed for invalid nucleic acid test result!\n", 4);
        cout << endl;
    }
    else{
        color_print("Congratulations!", 4);
        cout << "You've arrived at ";
        color_print("Nucleic Acid Testing site\n", 6);
        cout << endl;
    } 
}