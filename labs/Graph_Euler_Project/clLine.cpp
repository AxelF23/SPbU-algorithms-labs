#include "clLine.h"
#include <graphics.h>
#include <string>

clLine::clLine(int x1_in, int y1_in, int x2_in, int y2_in): x1(x1_in), y1(y1_in), x2(x2_in), y2(y2_in) {
    cout << x1 << "    clLine(int x1, int y1, int x2, int y2)" << endl;
}

clLine::~clLine() {
    cout << x1 << "   ~clLine()" << endl;
}

void clLine::show() {
    line (x1, y1, x2, y2 );
}
