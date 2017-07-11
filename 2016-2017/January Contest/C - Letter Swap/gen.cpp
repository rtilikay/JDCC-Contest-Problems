#include <bits/stdc++.h>

using namespace std;

int BOUND = 100000; // Change to 100 for 40% of cases

int main () {
    srand(time(0));
    for (int i = 0; i < BOUND; i++)
        cout << rand()%2;
    cout << "\n";
}
