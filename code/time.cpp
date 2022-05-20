#include<iostream>
#include"time.h"

void Clock::tick(){
    time_t t = time(NULL); // current time
    while (time(NULL)==t);
    if(--m<0){
        m = 59;
        --h;
    }
}
void Clock::show(){
    if(m<10) cout << 0;
    cout << m << ":";
    if(s<10) cout << 0;
    cout << s << flush;
}
void Clock::run(){
    while (m!=0 || s!=0 || !flag)
    {
        tick();
        show();
    }
    if(flag)
    cout << ""
    
}
