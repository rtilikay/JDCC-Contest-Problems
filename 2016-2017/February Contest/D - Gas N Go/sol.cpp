#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int main () { 
    int n, m; 
    cin >> n >> m;

    ll adj[n+1][n+1];
    ll gas[n+1];
    memset(adj, 0x30303030, sizeof(adj));

    for (int i = 1; i <= n; ++i) {
        cin >> gas[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c; 
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (gas[i] <= gas[j] && j != n) {
                adj[i][j] = 0x30303030;
            } else {
                adj[i][j] *= gas[i];
            }
        }
    }
     
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    cout << adj[1][n] << "\n";
}
