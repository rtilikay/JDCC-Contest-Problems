#include <bits/stdc++.h>

using namespace std;

const int BOUND = 10000;
const int BOUND_L = 1000000000;

int main () {
    srand(time(0));
    int n = BOUND, l = BOUND_L;
    cout << n << " " << l << "\n";
    for (int i = 0; i < n; ++i) {
        int x = rand()%(2*l+1)-l, y = rand()%l, v = rand()%n, w = rand()%n;
        cout << x << " " << y << " " << v << " " << w << "\n";
    }
}
