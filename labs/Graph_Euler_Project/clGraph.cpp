#include "Graph.h"
#include "edge.h"
#include <graphics.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;


Graph::Graph(vector<vector<double>>& matrix, vector<clNode*>& nodes)
    : adjacencyMatrix(matrix), nodes(nodes)
{
    cout << "Graph    Graph(...)" << endl;
}


Graph::~Graph() {
    cout << "Graph   ~Graph()" << endl;
    for (auto node : nodes) {
        delete node;
    }
}

void Graph::show() {
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");


    int n = nodes.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j] > 0) {
                clEdge edge(nodes[i], nodes[j], adjacencyMatrix[i][j]);
                edge.show();
            }
        }
    }


    for (auto node : nodes) {
        node->show();
    }
    readkey();
    //closegraph();
}
