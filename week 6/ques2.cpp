// Week06_02_TransitiveClosure.cpp
#include <iostream>
#include <vector>
using namespace std;

void warshall(vector<vector<int>>& graph, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    warshall(graph, n);

    cout << "\nTransitive Closure:\n";
    for (const auto& row : graph) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
