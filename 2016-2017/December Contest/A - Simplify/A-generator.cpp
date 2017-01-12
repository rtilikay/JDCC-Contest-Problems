#include <bits/stdc++.h>

using namespace std; 

const int BOUND = 10000;

int main () {
    srand(time(0));
    int n = rand()%BOUND+1, d = rand()%BOUND+1;
    cout << min(n, d) << "/" << max(n, d) << "\n";
}
