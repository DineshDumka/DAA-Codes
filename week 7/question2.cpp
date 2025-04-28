#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, vector<Edge>& edges, int source) {
   
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;
            
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;  
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    int source;
    cin >> source;  
    
    bellmanFord(n, m, edges, source);
    
    return 0;
}
