#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <vector>
#include "clNode.h"
using namespace std;
bool ifEulerexist(vector<vector<double>>& matrix);
vector<pair<string,int>> EulerPath(vector<vector<double>>& matrix, vector<string>& nodeNames, int start);
void show_Euler_Path(vector<pair<string, int>>& answer, vector<clNode*>& nodes);
#endif // HEADER_H_INCLUDED
