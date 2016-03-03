#include <bits/stdc++.h>

using namespace std;

const int maxval = 13; 
int n;
char maze [maxval][maxval];

bool valid (int x, int y){
    if (x < 0 || y < 0 || x == n || y == n || maze[x][y] == '#' || maze[x][y] == 'W')
        return false;
    return true;
}

int solve (int x, int y){
    if (maze[x][y] == 'E')
        return 0;
    int best = -1000;
    maze[x][y] = 'W';
    if (valid (x-1, y))
        best = max (best, 1 + solve (x-1, y));   
    if (valid (x+1, y))
        best = max (best, 1 + solve (x+1, y));   
    if (valid (x, y-1))
        best = max (best, 1 + solve (x, y-1));   
    if (valid (x, y+1))
        best = max (best, 1 + solve (x, y+1));   
    maze[x][y] = '.';
    return best;
}

int main (){
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
    int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        cin >> n;
        string s;
        pair <int, int> start;
        for (int i = 0; i < n; i++){
            cin >> s; 
            for (int j = 0; j < n; j++){
                maze[i][j] = s[j];
                if (s[j] == 'A')
                    start = pair <int, int> (i, j);
            }
        }
        cout << solve (start.first, start.second) << "\n";
    }
}
