#ifndef CLDRAW_H_INCLUDED
#define CLDRAW_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <graphics.h>
using namespace std;
class clDraw {
public:
    virtual void show() = 0;
    virtual ~clDraw();
};

#endif // CLDRAW_H_INCLUDED
