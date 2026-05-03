#ifndef CLNODE_H_INCLUDED
#define CLNODE_H_INCLUDED
#include <string>
#include "clCircle.h"
#include <cstdlib>
#include <iostream>
#include <graphics.h>
using namespace std;

class clNode: public clCircle {
public:
    clNode(int x0, int y0, string& num0);
    ~clNode();
    string Getnum() {
        return num;
    }
    void Setnum(string& val) {
        num = val;
    }
    void show();
private:
    string num;
};

#endif // CLNODE_H_INCLUDED
