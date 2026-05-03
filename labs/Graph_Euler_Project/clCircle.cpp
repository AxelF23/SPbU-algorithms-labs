#include "clCircle.h"
#include <graphics.h>
#include <iostream>
#include <string>


clCircle::clCircle(int x0, int y0) : x(x0), y(y0) {
    cout << x << "    clCircle(int x0, int y0)" << endl;
}

clCircle::~clCircle() {
    cout << x << "   ~clCircle()" << endl;
}

void clCircle::show(){
    circle(x, y, r);
}
