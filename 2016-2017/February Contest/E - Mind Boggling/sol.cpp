#include <bits/stdc++.h>
#define ll long long

using namespace std; 

const int BOUND = 30;
const int dir[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}};

bool vis[BOUND+2][BOUND+2];
int n, m;

int paths[8];


void count_paths (int i, int j, int p, int origlen) {
    if (i == 0 || i == n+1 || j == 0 || j == n+1 || p == 0)
        return;
    vis[i][j] = true;
    ++paths[origlen-p+1];
    if (p == 1) {
        vis[i][j] = false;
        return;
    }
    for (int l = 0; l < 8; ++l) {
        if (!vis[i + dir[l][0]][j+dir[l][1]])
            count_paths(i + dir[l][0], j+dir[l][1], p-1, origlen);
    }
    vis[i][j] = false;
}

int main () { 
    cin >> n >> m;
    vector<double> len(8, 0);
    for (int i = 0; i < m; ++i) {
        string s; 
        cin >> s;
        ++len[s.length()];
    }
    for (int j = 1; j <= n/2; j++) {
        for (int k = 1; k <= n/2; k++) {
            count_paths(j, k, 7, 7);
        }
    }
    for (int i = 1; i <= 7; i++)
        paths[i] *= 4;
    
    if (n%2 == 1) {
        count_paths(n/2+1, n/2+1, 7, 7);
        for (int i = 1; i <= n; i++) {
            if (i == n/2+1)
                continue;
            count_paths(i, n/2+1, 7, 7);
            count_paths(n/2+1, i, 7, 7);
        }
    }

    double exp = 0;
    for (int i = 1; i < len.size(); ++i) {
        exp += len[i]*paths[i]/pow(26.0, i);
    }
    cout << fixed << setprecision(3) << exp << "\n";
}
