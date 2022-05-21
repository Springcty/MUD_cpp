#include<iostream>
#include "player.h"
#include "map.h"
// #include "concol.h"
using namespace std;

// Pos Player::GetPos(){
//     return temp;
// }
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

void Player::play(Map m){
    int play_cnt = 0;
    while(temp != x){
        // setcolor(blue, backcolor());
        cout << "Little Ice: ";
        // setcolor(white, backcolor());
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
        // setcolor(green, backcolor());
        cout << "Player: ";
        // setcolor(white, backcolor());
        cin >> d;
        if(s.find(d) != s.npos) move(d); // check if d is valid
        else if(d=="help"){ // help mode: print current map
            m.printMap(temp);
        }
        else{
            // setcolor(blue, backcolor());
            cout << "Little Ice: ";
            // setcolor(white, backcolor());
            cout << "This direction is blocked! Choose another please~" << endl;
        }

        int i_loc = temp.loc;
        temp.UpdateLoc();
        // show when the player comes a new place
        if(temp.loc != i_loc){
            cout << "You've arrived at " << m.dict[temp.loc] << "!" << endl;
            cout << "Keep Going!" << endl;
        }

        // show the steps remained
        play_cnt ++;
        // setcolor(blue, backcolor());
        cout << "Little Ice: ";
        // setcolor(white, backcolor());
        cout << MOVENUM - play_cnt << "steps left" << endl;
    }
    // setcolor(blue, backcolor());
    cout << "Little Ice: ";
    // setcolor(white, backcolor());
    cout << "Congratulations!" << endl;
    cout << "You've arrived at Nucleic Acid Testing site!" << endl;
}