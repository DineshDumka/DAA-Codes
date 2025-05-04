// Week06_01_FloydWarshall.cpp
#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {         // Intermediate node
        for (int i = 0; i < n; i++) {     // Source node
            for (int j = 0; j < n; j++) { // Destination node
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter adjacency matrix (use 1000000000 for INF):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    floydWarshall(dist, n);

    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
