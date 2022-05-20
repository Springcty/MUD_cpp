#include<iostream>
#include "player.h"
#include "map.h"
#include "concol.h"
using namespace std;

Pos Player::GetPos(){
    return temp;
}
void Player::move(string d){
    switch (d)
    {
    case "N": // up
        temp.y++;
        break;
    case "E": // right
        temp.x++;
        break;
    case "S": // down
        temp.y--;
        break;
    case "W": // left
        temp.x--;
        break;
    default:
        break;
    }
}

void Player::play(Map m){
    int play_cnt = 0;
    while(temp != x){
        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << "You can choose ";
        Pos a = temp;
        string s = ""; // remember the dirction able to move
        a.y ++;
        if(!a.IsBlock()){
            cout << "North(N) ";
            s += "N";
        }
        a.y --; a.x ++;
        if(!a.IsBlock()){
            cout << "East(E) ";
            s += "E";
        }
        a.x --; a.y --;
        if(!a.IsBlock()){
            cout << "South(S) ";
            s += "S";
        }
        a.y ++; a.x --;
        if(!a.IsBlock()){
            cout << "West(W) ";
            s += "W";
        }
        cout << "to go" << endl;
        
        string d;
        setcolor(green, backcolor());
        cout << "Player: ";
        setcolor(white, backcolor());
        cin >> d;
        if(d in s) move(d);
        else if(d=="help"){
            m.printMap(temp);
        }
        else{
            setcolor(blue, backcolor());
            cout << "Little Ice: ";
            setcolor(white, backcolor());
            cout << "This direction is blocked! Choose another please~" << endl;
        }

        int i_loc = temp.loc;
        temp.update();
        if(temp.loc != i_loc){
            cout << "You've arrived at " << dict[temp.loc] << "!" << endl;
            cout << "Keep Going!" << endl;
        }

        play_cnt ++;
        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << MOVENUM - play_cnt << "steps left" << endl;
    }
    setcolor(blue, backcolor());
    cout << "Little Ice: ";
    setcolor(white, backcolor());
    cout << "Congratulations!" << endl;
    cout << "You've arrived at Nucleic Acid Testing site!" << endl;
}