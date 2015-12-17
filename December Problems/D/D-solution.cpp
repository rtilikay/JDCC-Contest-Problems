#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 1000000007

using namespace std;

int main ()
{
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        int n;
        cin >> n;
        int mat [n][n];
        for (int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            for (int j = 0; j < n; j++){
                if (temp[j] == 'O')
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    continue;
                mat[i][j] = 0;
                if (j > 0)
                    mat[i][j] = (mat[i][j] + mat[i-1][j-1])%MOD;
                if (j < n-1)
                    mat[i][j] = (mat[i][j] + mat[i-1][j+1])%MOD;
                mat[i][j] = (mat[i][j] + mat[i-1][j])%MOD;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = (sum + mat[n-1][i])%MOD;
        cout << sum << "\n";
	}
}
