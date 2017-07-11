#include <bits/stdc++.h>

using namespace std; 

int main () { 
    string s; 
    cin >> s;
    int a = 1, b = 1, tot = 0;
    for (int i = 2; i < s.length(); ++i) {
        swap(a, b);
        if (s[i] == 'L') {
            tot += a += b; 
        } else {
            a = abs(a-b);
        }
    }
    cout << tot << "\n";
}
