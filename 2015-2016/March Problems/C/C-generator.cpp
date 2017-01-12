#include <bits/stdc++.h>

using namespace std;

const int maxval = 10, prob = 60;
int maxturns;

int random (int mod)
{
	return abs(rand () * 0x0008000 + rand ()) % mod;
}

int mat [maxval][maxval], n, turns;

bool valid (pair <int, int> p){
    return !(p.first < 0 || p.second < 0 || p.first >= n || p.second >= n);
}

pair <int, int> next (pair <int, int> p, int dir){
    int x = p.first, y = p.second;
    if (dir == 0)
        x--;
    if (dir == 1)
        x++;
    if (dir == 2)
        y--; 
    if (dir == 3)
        y++;
    return pair <int, int> (x, y);
}

void dfs (pair <int, int> p, int dir){
    if (!mat[p.first][p.second])
        mat[p.first][p.second] = 1;
    int ndir = dir;
    if (random (3) == 0)
        ndir = random (4);
    while (!valid (next (p, ndir)))
        ndir = (ndir + 1)%4;
    if (dir != ndir){
        turns ++;
        if (turns > maxturns && mat[p.first][p.second] != 2){
            mat[p.first][p.second] = 3;
            return;
        }
    }
    dfs (next (p, ndir), ndir);
}

int main (int argc, char* argv[]){
	if (argc != 3)
	{
		cerr << "Incorrect number of arguments!\n";
		return 1;
	}
	freopen ("C.in", "w", stdout);
	int seed = stoi (argv[1]), tt = stoi (argv[2]);
	srand (seed);
    cout << tt << "\n";
	for (int cases = 0; cases < tt; cases++){
        n = random (maxval - 4) + 5;
        cout << n << "\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;
        turns = 0;
        maxturns = n + 2;
        int x = random (n), y = random (n);
        mat[x][y] = 2;
        dfs (pair <int ,int> (x, y), random (4));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    cout << ((random (100) < prob)?"#":".");
                else if (i == x && j == y)
                    cout << "A";
                else if (mat[i][j] == 1)
                    cout << ".";
                else
                    cout << "E";
            }
            cout << "\n";
        }
    }
}
