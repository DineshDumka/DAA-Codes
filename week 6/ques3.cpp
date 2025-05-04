// Week06_03_PathReconstruction.cpp
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n;

void printPath(vector<vector<int>>& next, int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path\n";
        return;
    }
    vector<int> path;
    for (int at = u; at != v; at = next[at][v]) {
        path.push_back(at);
        if (at == -1) {
            cout << "No path\n";
            return;
        }
    }
    path.push_back(v);

    for (int node : path)
        cout << node << " ";
    cout << "\n";
}

void floydWarshallWithPath(vector<vector<int>>& dist, vector<vector<int>>& next) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> next(n, vector<int>(n));

    cout << "Enter adjacency matrix (use 1000000000 for INF):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }

    floydWarshallWithPath(dist, next);

    cout << "\nEnter source and destination to find path (0-indexed): ";
    int u, v;
    cin >> u >> v;
    cout << "Path: ";
    printPath(next, u, v);

    return 0;
}
