#include <bits/stdc++.h>

using namespace std; 

const int BOUND_N = 100; // Multiply by BOUND_K to get true bound.
const int BOUND_K = 1000;

int main () {
    srand(time(0));
    int n = rand()%(BOUND_N*BOUND_K), k = rand()%BOUND_K + 1;
    cout << n << " " << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << rand()%BOUND_N + 1;
        if (i < k-1)
            cout << " ";
        else
            cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << rand()%k + 1;
        if (i < n-1)
            cout << " ";
        else
            cout << "\n";
    }
}
