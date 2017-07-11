#include <bits/stdc++.h>

using namespace std; 

int main () { 
    string s; 
    cin >> s;
    int n = s.size();
    int l = 0, r = n-1;
    long long total = 0;
    while (l < n) { 
        if (s[l] == '1' && s[r] == '1') {
            total += abs(l - (n-1-r));
            l++; r--;
        } else if (s[l] == '0')
            l++;
        else if (s[r] == '0')
            r--;
    }
    cout << total << "\n";
}
