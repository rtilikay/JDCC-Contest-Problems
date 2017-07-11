#include <bits/stdc++.h>

using namespace std;

int BOUND = 1000; // Change to 100 for 40% of cases

int main () {
    srand(time(0));
    int h = rand()%BOUND + 5;
    if (h % 2 == 0)
        ++h;
    cout << h << endl;
}
