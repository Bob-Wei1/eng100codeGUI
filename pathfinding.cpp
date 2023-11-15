#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <time.h> 
#include <stdlib.h>

using namespace std;

#define V 10
vector<vector<int>> graph;
int ctr = 1;

void addCockroach() {
    int x = rand() % 10;
    int y = rand() % 10;
    graph[x][y]++;
}

void printLocation(int i, int j) {
    cout << "at node " << i << " " << j << "\n";
}

void runcycle(vector<vector<int>> g) {
    map<pair<int, int>, int> unvisited;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            unvisited[{i, j}] = graph[i][j];
        }
    }

    //start at top left
    printLocation(0, 0);
    unvisited[{0, 0}]--;
    if (unvisited[{0, 0}] == 0) {
        unvisited.erase(unvisited.begin());
    }

    while (!unvisited.empty()) {
        srand(ctr++);
        int r = rand();
        cout << "r: " << r << endl;
        int n = unvisited.size();
        cout << "n: " << n << endl;
        int x = r % n; //randomly generate value in unvisited nodes to visit
        //assume go to that node is implemented

        cout << "x : " << x << endl;

        //simulate random cockroach activity
        if (rand() % 4 == 0) {
            addCockroach();
        }

        auto i1 = unvisited.begin();
        auto it = (x != 0) ? next(i1, x) : unvisited.begin();

        unvisited[{(it->first).first, (it->first).second}]--;
        cout << "val:" << unvisited[{(it->first).first, (it->first).second}] << endl;
        printLocation((it->first).first, (it->first).second);
        if (unvisited[{(it->first).first, (it->first).second}] == 0) {
            if (n == 1) {
                break;
            }
            unvisited.erase(it->first);
        }
    }
}
// driver's code
int main()
{
    //initialize starting graph
    for (int i = 0; i < V; i++) {
        vector<int> temp;
        for (int j = 0; j < V; j++) {
            temp.push_back(1);
        }
        graph.push_back(temp);
    }

    for (int i = 0; i < 10; i++) {
        runcycle(graph);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}