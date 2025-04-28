#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist, int s) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (w > dist[u]) continue;
        
        for (auto x : adj[u]) {
            int v = x.first;
            int wt = x.second;
            
            if (w + wt < dist[v]) {
                dist[v] = w + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    
     int n, m;  
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        
    }
    
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    
    dijkstra(n, adj, dist, 0);
    
    for (auto x : dist) {
        if (x == INT_MAX)
            cout << "INF ";
        else
            cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
