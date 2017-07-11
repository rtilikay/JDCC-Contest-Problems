#include <bits/stdc++.h>
#define ll long long

using namespace std; 

string reverse (string s) {
    string t(s);
    for (int i = 0; i < s.length()/2; ++i)
        swap(t[i], t[s.length() - 1 - i]);
    return t;
}

string range (ll n) {
    string s = reverse(to_string(n - n%20));
    for (ll i = n - n%20 + 1; i<= n; ++i) {
        string num = reverse(to_string(i));
        while (num.length() > s.length()) {
            s += "0";
        }
        for (int j = 0; j < num.length(); ++j) {
            int l = s[j] - 48;
            int r = num[j] - 48;
            s[j] = ((l+r)%10)+48;
        }
    }
    return s;
}

int main () { 
    ll n, m;
    cin >> n >> m;
    string s = range(n-1);
    string t = range(m);
    
    for (int i = 0; i < s.length(); ++i) {
        t[i] = (t[i] - s[i] + 10)%10+48;
    }
    cout << reverse(t) << "\n";
}
