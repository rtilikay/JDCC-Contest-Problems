#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int BOUND = 300;

int main () {
    srand(time(0));
    
    cout << BOUND << " " << BOUND*(BOUND+1)/2 << "\n";
    for (int i = 1; i <= BOUND; ++i) {
        if (i != 1)
            cout << " ";
        cout << rand()%10000+1;
    }
    cout << endl;
    for (int i = 1; i <= BOUND; ++i)
        for (int j = i + 1; j <= BOUND; ++j)
            cout << i << " " << j << " " << rand()%100000+1 << endl;
}
