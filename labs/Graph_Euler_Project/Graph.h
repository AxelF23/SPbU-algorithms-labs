#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "clNode.h"
#include <vector>
using namespace std;

class Graph: public clDraw {
private:
    vector<vector<double>> adjacencyMatrix;
    vector<clNode*> nodes;

public:
    Graph(vector<vector<double>>& matrix, vector<clNode*>& nodes);
    ~Graph();

    void show();

    const vector<vector<double>>& getMatrix() const;
    const vector<clNode*>& getNodes() const;
};
#endif
