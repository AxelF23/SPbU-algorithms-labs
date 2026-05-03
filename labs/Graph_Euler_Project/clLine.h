#ifndef CLLINE_H_INCLUDED
#define CLLINE_H_INCLUDED
#include "clDraw.h"
#include <graphics.h>
class clLine: public clDraw {
public:
    clLine(int x1, int y1, int x2, int y2);
    ~clLine();
    void show();
    int Getx1() {
        return x1;
    }
    int Gety1() {
        return y1;
    }
    int Getx2() {
        return x2;
    }
    int Gety2() {
        return y2;
    }
    void Setx1(int val) {
        x1 = val;
    }
    void Sety1(int val) {
        y1 = val;
    }
    void Setx2(int val) {
        x2 = val;
    }
    void Sety2(int val) {
        y2 = val;
    }
private:
    int x1;
    int y1;
    int x2;
    int y2;
};


#endif // CLLINE_H_INCLUDED
