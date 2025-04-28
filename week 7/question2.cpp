#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, vector<vector<int>>& adjMatrix, int source) {
    vector<int> dist(n, INT_MAX);
    vector<int> previous(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    previous[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << i + 1 << " : INF" << endl;
        } else {
            vector<int> path;
            for (int v = i; v != -1; v = previous[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            cout << i + 1 << " : ";
            for (int j = 0; j < path.size(); j++) {
                cout << path[j] + 1;
                if (j != path.size() - 1) {
                    cout << " ";
                }
            }
            cout << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int source;
    cin >> source;
    source--;

    bellmanFord(n, adjMatrix, source);

    return 0;
}



//output format 
//destination_vertex_number : path_from_destination_to_source : minimum_path_weight
