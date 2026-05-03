#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include "clLine.h"
#include "clNode.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class clEdge: public clLine {
public:
    clEdge(clNode* node1, clNode* node2, double w);
    ~clEdge();
    void show();
    void paint();
    double GetWeight() {
        return weight;
    }
    void SetWeight(double w) {
        weight = w;
    }
private:
    double weight;
    clNode* startNode;
    clNode* endNode;
};

#endif // EDGE_H_INCLUDED
