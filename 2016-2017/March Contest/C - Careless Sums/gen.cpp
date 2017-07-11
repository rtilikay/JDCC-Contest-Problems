#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll BOUND = 1000000000000000000L; // Change to 100000 for 40% of cases.

ll r(ll n) {
    ll m = rand()*0x7FFFFFFFL + rand();
    return m%BOUND+1;
}

int main () {
    srand(time(0));
    ll n = r(BOUND), m = r(BOUND);
    if (n > m) {
        swap(n, m);
    }
    cout << n << " " << m << "\n";
}
