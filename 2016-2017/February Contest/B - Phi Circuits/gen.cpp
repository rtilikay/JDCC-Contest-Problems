#include <bits/stdc++.h>

using namespace std;

const int BOUND = 50;

int main () {
    srand(time(0));
    cout << "PP";
    for (int i = 2; i < BOUND; ++i) {
        cout << (rand()%2 ? 'L' : 'R');
    }
    cout << "\n";
}
