#include <bits/stdc++.h>

using namespace std; 

int BOUND = 100;

int main () {
    srand(time(0));
    int n = BOUND, m = BOUND;
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << (char)(65 + rand()%26);
        cout << "\n";
    }
}
