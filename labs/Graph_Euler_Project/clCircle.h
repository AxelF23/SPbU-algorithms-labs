#ifndef CLCIRCLE_H_INCLUDED
#define CLCIRCLE_H_INCLUDED
#include "clDraw.h"
#include <cstdlib>
#include <iostream>
#include <graphics.h>
using namespace std;

class clCircle: public clDraw {
public:
    clCircle(int x0, int y0);
    ~clCircle();
    int Getx() {
        return x;
    }
    void setx(int val) {
        x = val;
    }
    int Gety() {
        return y;
    }
    void sety(int val) {
        y = val;
    }
    void show();
private:
    int x;
    int y;
    const int r = 20;
};

#endif // CLCIRCLE_H_INCLUDED
