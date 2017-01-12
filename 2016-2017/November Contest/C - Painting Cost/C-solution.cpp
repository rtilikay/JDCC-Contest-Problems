#include <bits/stdc++.h>

using namespace std; 

int main () {
    int n, m;
    cin >> n >> m; 
    char wall [n][m];
    for (int i = 0; i < n; i++)
        cin >> wall[i];
    int total = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            vector<char> sq(4);
            sq[0] = wall[i][j];
            sq[1] = wall[i][j+1];
            sq[2] = wall[i+1][j];
            sq[3] = wall[i+1][j+1];
            sort(sq.begin(), sq.end());
            total++;
            for (int k = 1; k < 4; k++)
                if (sq[k] != sq[k-1]) total++;
        }
    }
    cout << total << "\n";
}
