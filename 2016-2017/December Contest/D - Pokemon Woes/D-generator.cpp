#include <bits/stdc++.h>

using namespace std; 

const int BOUND_POKE = 15; // Change this to 10 for 50% of cases.
const int BOUND_N = 20;

int main () {
    srand(time(0));
    int n = 20;
    cout << 20 << "\n";
    vector<int> gen(n*n);
    for (int i = 0; i < n*n; i++) 
        gen[i] = i+1;
    random_shuffle(gen.begin(), gen.end());
    char board[n][n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
    // Home
    board[gen[0]/n][gen[0]%n] = 'H';
    // Pokemon
    int start_poke = rand()%(BOUND_N*BOUND_N - BOUND_POKE) + 1;
    for (int i = start_poke; i < start_poke + BOUND_POKE; i++)
        board[gen[i]/n][gen[i]%n] = 'P';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << "\n";
    }
}
