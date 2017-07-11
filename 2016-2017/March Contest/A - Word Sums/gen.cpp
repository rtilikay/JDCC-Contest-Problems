#include <bits/stdc++.h>

using namespace std;

const int BOUND = 1000;

int main () {
    srand(time(0));
    int n = rand()%BOUND+1, m = rand()%BOUND+1;
    while (n--) {
        cout << (char)(rand()%26+65);
    }
    cout << "\n";
    while (m--) {
        cout << (char)(rand()%26+65);
    }
    cout << "\n";
}
