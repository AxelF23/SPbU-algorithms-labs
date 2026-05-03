#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include "Graph.h"
#include "clNode.h"
#include "header.h"
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество вершин: ";
    cin >> n;

    vector<string> nodeNames(n);
    cout << "Введите названия вершин:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i + 1 << ": ";
        cin >> nodeNames[i];    }

    vector<clNode*> nodes;
    int center_x = 400, center_y = 300, radius = 200;

   for (int i = 0; i < n; i++) {
        double angle = 2 * 3.14 * i / n;
        int x = center_x + radius * cos(angle);
        int y = center_y + radius * sin(angle);
        nodes.push_back(new clNode(x, y, nodeNames[i]));
    }

    vector<vector<double>> matrix(n, vector<double>(n, 0));
    cout << "Введите матрицу смежности:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Вес ребра из " << nodeNames[i] << " в " << nodeNames[j] << ": ";
               cin >> matrix[i][j];
            }
       }
    }

    Graph graph(matrix, nodes);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    graph.show();
    if (ifEulerexist(matrix)) {
        cout << "В графе существует эйлеровы циклы" << endl;
        vector<pair<string,int>> answer = EulerPath(matrix, nodeNames, 0);
        for (const auto& node : answer) {
            cout << node.first << " ";
        }
        cout << endl;

        show_Euler_Path(answer, nodes);
    }
    else {
        cout << "В графе не существует эйлеровых циклов" << endl;
    }
readkey();
return 0;
}
