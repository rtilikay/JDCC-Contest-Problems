#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int ROWS = 6;

long long adj [1 << ROWS][1 << ROWS];

void transitions (int cur, int ind, vector <bool> state){
    if (ind == state.size ()){
        int edge = 0;
        for (int i = 0; i < state.size (); i++)
            if (state[i])
                edge += (1 << i);
        adj[cur][edge] = 1;
        return;
    }
    if (state[ind]){
        state[ind] = 0;
        transitions (cur, ind+1, state);
        return;
    }
    state[ind] = 1;
    transitions (cur, ind+1, state);
    state[ind] = 0;
    if (ind < state.size () - 1 && !state[ind+1])
        transitions (cur, ind+2, state);
}

void gen_transitions (int n){
    vector <bool> state (n);
    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++)
            state[j] = i&(1 << j);
        transitions (i, 0, state);
    }
    adj[0][(1 << n) - 1] = 0;
}

void exp (int n, long long m){
    long long one = 1, bound = (1 << n), mat [bound][bound], temp[bound][bound];
    for (int i = 0; i < bound; i++)
        for (int j = 0; j < bound; j++){
            mat[i][j] = adj[i][j];
            adj[i][j] = 0;
            if (i == j)
                adj[i][j] = 1;
        }
    for (int it = 0; (one << it) <= m; it++){
        if ((one << it) & m){
            for (int i = 0; i < bound; i++)
                for (int j = 0; j < bound; j++){
                    temp[i][j] = adj[i][j];
                    adj[i][j] = 0;
                }
            for (int i = 0; i < bound; i++)
                for (int j = 0; j < bound; j++)
                    for (int k = 0; k < bound; k++)
                        adj[i][j] = (adj[i][j] + temp[i][k]*mat[k][j])%MOD;
        }
        for (int i = 0; i < bound; i++)
            for (int j = 0; j < bound; j++){
                temp[i][j] = mat[i][j];
                mat[i][j] = 0;
            }
        for (int i = 0; i < bound; i++)
            for (int j = 0; j < bound; j++)
                for (int k = 0; k < bound; k++)
                    mat[i][j] = (mat[i][j] + temp[i][k]*temp[k][j])%MOD;
    }
}

int main ()
{
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--)
	{
        int n; 
        long long m;
        cin >> n >> m;
        for (int i = 0; i < 64; i++)
            for (int j = 0; j < 64; j++)
                adj[i][j] = 0;
        gen_transitions (n);
        exp (n, m);
        cout << adj[0][0] << "\n";
    }
}
