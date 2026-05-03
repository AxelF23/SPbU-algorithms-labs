#include "edge.h"
#include <graphics.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <dos.h>

using namespace std;


clEdge::clEdge(clNode* node1, clNode* node2, double w)
    : clLine(node1->Getx(), node1->Gety(), node2->Getx(), node2->Gety()),
      weight(w), startNode(node1), endNode(node2) {
    cout << weight << "    clEdge(clNode* node1, clNode* node2, double w)" << endl;
}


clEdge::~clEdge() {
    cout << weight << "   ~clEdge()" << endl;
}

void clEdge::show() {
     clLine::show();

    int midX = (Getx1() + Getx2()) / 2;
    int midY = (Gety1() + Gety2()) / 2;

    ostringstream oss;
    oss << fixed << setprecision(2) << weight;
    string weightStr = oss.str();


    setcolor(WHITE);

    outtextxy(midX, midY, const_cast<char*>(weightStr.c_str()));
}

void clEdge::paint() {
     setcolor(YELLOW);

     clLine::show();

    int midX = (Getx1() + Getx2()) / 2;
    int midY = (Gety1() + Gety2()) / 2;

    ostringstream oss;
    oss << fixed << setprecision(2) << weight;
    string weightStr = oss.str();




    outtextxy(midX, midY, const_cast<char*>(weightStr.c_str()));
}
