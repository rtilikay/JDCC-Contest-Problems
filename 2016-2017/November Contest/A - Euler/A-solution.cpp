#include <bits/stdc++.h>

using namespace std; 

int main () {
    int n; 
    cin >> n;
    string s, first;
    int x, lowest = 0x7FFFFFFF;
    while (n--) {
        cin >> s >> x;
        if (x < lowest) {
            lowest = x;
            first = s;
        }
    }
    cout << first << "\n";
}
