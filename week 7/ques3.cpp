#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int shortestPathWithKEdges(vector<vector<int>>& adj, int u, int v, int k, vector<vector<int>>& dp) {
    if (k == 0 && u == v) return 0;
    if (k == 0) return INF;
    if (dp[u][k] != -1) return dp[u][k];

    int res = INF;
    int n = adj.size();

    for (int i = 0; i < n; i++) {
        if (adj[u][i] != 0) {
            int subPath = shortestPathWithKEdges(adj, i, v, k - 1, dp);
            if (subPath != INF)
                res = min(res, adj[u][i] + subPath);
        }
    }

    return dp[u][k] = res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int src, dest, k;
    cin >> src >> dest;
    src--; dest--; // Convert to 0-based index
    cin >> k;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int result = shortestPathWithKEdges(adj, src, dest, k, dp);

    if (result == INF)
        cout << "no path of length k is available." << endl;
    else
        cout << "Weight of shortest path from (" << src + 1 << "," << dest + 1 << ") with " << k << " edges : " << result << endl;

    return 0;
}
