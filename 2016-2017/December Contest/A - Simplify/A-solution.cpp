#include <bits/stdc++.h>

using namespace std;

// This is Euclid's Algorithm, which runs in logarithmic time.
int gcd (int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main () {
    int n, d;
    string s;
    cin >> s;
    n = stoi(s.substr(0, s.find("/")));
    d = stoi(s.substr(s.find("/") + 1));
    int m = gcd(n, d);
    cout << n/m << "/" << d/m << "\n";
}
