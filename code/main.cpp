#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include "map.h"
#include "player.h"
using namespace std;

// init the game interface
void Welcome(){
    color_print(ROBOT, 1);
    cout << "Welcome to ";
    color_print("ZJU Nucleic Acid Testing Challenge! ! !", 3);
    cout << endl;
    color_print(ROBOT, 1);
    cout << "Here is the campus map." << endl;
    color_print(ROBOT, 1);
    cout << "'x' represents the nucleic-acid test available spot." << endl;
    // draw the map
    fstream fp;
    fp.open("./map.txt", ios::in);
    if(!fp){
        cerr << "openfile failed!" << endl;
        exit(1);
    }
    string s;
    while(!fp.eof()){
        getline(fp, s);
        cout << s << endl;
    }
    fp.close();

    color_print(ROBOT, 1);
    cout << "Begin? (yes/no)" << endl;
    color_print(PLAYER, 2);
}

int main(){
    srand((int)time(NULL)); // random
    Welcome();
    string a;
    cin >> a;
    while(a=="yes"){
        Map m;
        m.initMap(); // randomly generated a map

        Pos e, x;
        e = m.GetE();
        x = m.GetX();
        
        color_print(ROBOT, 1);
        // cout << e.x << "," << e.y << endl;
        cout << "You are currently at ";
        color_print(m.dict[e.loc], 6);
        cout << endl;
        color_print(ROBOT, 1);
        cout << "The nearest nucleic acid testing site is ";
        color_print(m.dict[x.loc], 6);
        cout << endl;
        color_print(ROBOT, 1);
        cout << "Attention! Your have only " << MOVENUM << " steps " << "to try" << endl;
        cout << "*If you need a help, just type 'help' before you choose a direction~\n" << endl;

        Player p(e, x);
        p.play(m); // begin play in the map m

        color_print(ROBOT, 1);
        cout << "Play Again? (yes/no)" << endl;
        color_print(PLAYER, 2);
        cin >> a;
    }
}