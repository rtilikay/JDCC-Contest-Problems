#include <bits/stdc++.h>

using namespace std; 

int main () {
    int tt; 
    cin >> tt;
    while (tt--) {
        bool bad = false;
        int n; 
        cin >> n;
        string a, b;
        cin >> a;
        while (--n) {
            int c = 0;
            cin >> b;
            for (int i = 0; i < min(a.length(), b.length()); ++i)
                if (a[i] != b[i])
                    c++;
            if ((c > 1 || a.length() != b.length()) && !bad) {
                cout << "Hooligans!\n";
                bad = true;
            }
            a = b;
        }
        if (!bad)
            cout << "Fair Game\n";
    }
}
