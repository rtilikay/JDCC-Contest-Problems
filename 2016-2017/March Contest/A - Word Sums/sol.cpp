#include <bits/stdc++.h>

using namespace std; 

int main () { 
    string s, t; 
    cin >> s >> t;
    int mi = min(s.length(), t.length()), ma = max(s.length(), t.length());
    for (int i = 0; i < mi; ++i) {
        int sum = s[i] + t[i] - 128;
        if (sum > 26)
            sum -= 26;
        cout << (char)(sum + 64);
    }
    cout << s.substr(mi) << t.substr(mi) << "\n";
}
