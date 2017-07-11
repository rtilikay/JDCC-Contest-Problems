#include <bits/stdc++.h>

using namespace std; 

int main () { 
    string s;
    cin >> s;
    if (s.find(".") == string::npos) {
        double m = stod(s);
        int n = 0;
        while (m >= 10) {
            m /= 10.0;
            ++n;
        }
        cout << fixed << setprecision(2) << m << " * 10^" << n << "\n";
        return 0;
    }
    double m = stod(s);
    cin >> s;
    cin >> s;
    int n = stoi(s.substr(s.find("^") + 1));
    while (n--) { m *= 10.0; }
    cout << ((int)(m + 0.5) > (int)m ? (int)m+1 : (int)m) << "\n";
}
