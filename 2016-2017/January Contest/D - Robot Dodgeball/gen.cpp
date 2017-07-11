#include <bits/stdc++.h>

using namespace std;

int BOUND = 10000;
int EDGE_BOUND = 100000;

int main () {
    srand(time(0));
    int n = rand()%(BOUND-99) + 100, m = rand()%(n-10) + 5;
    
    cout << n << " " << 1 << "\n";
    vector<int> adj[n+1];
    for (int k = 0; k < EDGE_BOUND; k++) {
        int i = rand()%n+1, j;
        if (i <= m)
            j = rand()%(n-m-3)+(m+4); 
        else
            j = rand()%(m-3)+4;
        adj[i].push_back(j);
    }
    for (int i = 1; i <= n; i++) {
        cout << adj[i].size();
        for (int j : adj[i])
            cout << " " << j;
        cout << "\n";
    }
}
