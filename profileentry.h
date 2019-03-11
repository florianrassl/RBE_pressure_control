#ifndef PROFILEENTRY_H
#define PROFILEENTRY_H

struct ProfileEntry{
    int time;
    int pressure;
    ProfileEntry(int t, int p) : time(t), pressure(p){

    }
};

#endif // PROFILEENTRY_H
