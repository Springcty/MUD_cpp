#ifndef __TIME_H__
#define __TIME_H__

#include<iostream>
#include<ctime>
using namespace std;

class Clock
{
    int m;
    int s;
    int flag; // if gamewin flag=1, else flag=0
public:
    Clock(int min, int sec): m(min), s(sec), flag(0) { }
    void tick();
    void show();
    void run();
};

#endif