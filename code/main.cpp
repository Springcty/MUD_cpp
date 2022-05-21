#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include "map.h"
#include "player.h"
#include "concol.h"
using namespace std;

void Welcome(){
    setcolor(blue, backcolor());
    cout << "Little Ice: ";
    setcolor(white, backcolor());
    cout << "Welcome to ZJU Nucleic Acid Testing Challenge! ! !" << endl;
    setcolor(blue, backcolor());
    cout << "Little Ice: ";
    setcolor(white, backcolor());
    cout << "Here is the map of Zijingang." << endl;
    setcolor(blue, backcolor());
    cout << "Little Ice: ";
    setcolor(white, backcolor());
    cout << "'x' represents the spot is nucleic-acid test available." << endl;
    fstream fp;
    // fp.open("./MUD_cpp/pic/map.txt", ios::in);
    fp.open("D:\\Codefield\\CODE_cpp\\project\\MUD_cpp\\pic\\map.txt", ios::in);
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

    setcolor(blue, backcolor());
    cout << "Little Ice: ";
    setcolor(white, backcolor());
    cout << "Begin? (yes/no)" << endl;
    setcolor(green, backcolor());
    cout << "Player: ";
    setcolor(white, backcolor());
}

int main(){
    srand((int)time(NULL));	//random
    // map<int,string> map_dict;
    Welcome();
    string a;
    cin >> a;
    while(a=="yes"){
        Map m;
        m.initMap();

        Pos e, x;
        e = m.GetE();
        x = m.GetX();
        
        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << "You are currently at " << m.dict[e.loc] << endl;
        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << "The nearest nucleic acid testing site is " << m.dict[x.loc] << endl;
        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << "Attention! Your have only " << MOVENUM << " chances " << "to try" << endl;
        cout << "*If you need a help, just type 'help' before you choose a direction~" << endl;

        Player p(e, x);
        p.play(m);

        setcolor(blue, backcolor());
        cout << "Little Ice: ";
        setcolor(white, backcolor());
        cout << "Play Again? (yes/no)" << endl;
        setcolor(green, backcolor());
        cout << "Player: ";
        setcolor(white, backcolor());
        cin >> a;
    }
}