#include "clNode.h"
#include <graphics.h>
#include <string>


clNode::clNode(int x0, int y0, string& num0) : clCircle(x0, y0), num(num0) {
    cout << num << "    clNode(int x0, int y0, string& num0)" << endl;
}


clNode::~clNode() {
    cout << num << "   ~clNode()" << endl;
}

void clNode::show() {
    clCircle::show();
    const char* text = num.c_str();
    int text_width = textwidth(text);
    int text_height = textheight(text);
    int text_x = Getx() - text_width/2;
    int text_y = Gety() - text_height/2;
    setcolor(WHITE);
    outtextxy(text_x, text_y, const_cast<char*>(text));
}
