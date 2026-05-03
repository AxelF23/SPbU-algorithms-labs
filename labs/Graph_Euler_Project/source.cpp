#include "header.h"
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <locale.h>
#include <stack>
#include "clNode.h"
#include "edge.h"
using namespace std;
bool ifEulerexist(vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        int  k = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != 0) {
                k++;
            }
            if (j == (n-1)) {
                if (k % 2 != 0) {
                    return false;
                }
            }
         }
    }
    return true;
 }
vector<pair<string,int>> EulerPath(vector<vector<double>>& matrix, vector<string>& nodeNames, int start) {
    vector<pair<string,int>> cycle;
    stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int v = stack.top();
        bool hasEdge = false;

        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[v][j] != 0) {
                hasEdge = true;
                matrix[v][j] = 0;
                matrix[j][v] = 0;
                stack.push(j);
                break;
            }
        }

        if (!hasEdge) {
            cycle.push_back({nodeNames[v],v});
            stack.pop();
        }
    }
    return cycle;
}


void show_Euler_Path(vector<pair<string, int>>& answer, vector<clNode*>& nodes) {
    for (int i = 1; i < answer.size(); i++) {
        clEdge edge(nodes[answer[i-1].second], nodes[answer[i].second], 1);
        cout << i <<"  "<< nodes[answer[i-1].second]->Getx() << " " << nodes[answer[i].second]->Getx() << " ";
        edge.paint();
        delay(2000);
    }
}


