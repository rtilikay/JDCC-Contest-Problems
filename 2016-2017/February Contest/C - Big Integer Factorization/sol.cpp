#include <bits/stdc++.h>
#define ll long long

using namespace std; 

const int BOUND = 1 << 24;

int main () { 
    ll n, m;
    cin >> n;
    m = n;

    bool first = true;
    for (int i = 2; i < BOUND && n > 1; ++i) {
        ll num = 0;
        while (n % i == 0) {
            ++num;
            n /= i;
        }
        // cout << i << " " << num << "\n";
        if (!num)
            continue;
        if (!first) {
            cout << " * ";
        } else {
            first = false; 
        }
        cout << i << "^" << num*m;
    }
    if (n > 1) {
        if (!first)
            cout << " * ";
        cout << n << "^" << m;
    }
    cout << "\n";
}
