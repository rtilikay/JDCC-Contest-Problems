#include <bits/stdc++.h>

using namespace std; 

int parse (string s) {
    int split = s.find(":");
    string h = s.substr(0, split), m = s.substr(split+1);
    int hours = stoi(h);
    if (hours < 9)
        hours+= 12;
    return hours*60 + stoi(m);
}

int main () {
    int n;
    cin >> n; 
    int start = 0, fin = 0, tot = 0;
    while (n--) {
        string a, b;
        int s, f;
        cin >> a >> b;
        s = parse(a), f = parse(b);
        if (s > fin) {
            tot += fin - start;
            start = s;
            fin = f;
        } else {
            fin = max(f, fin);
        }
    }
    tot += fin - start;
    int reddit = 480 - tot;
    string hours = to_string(reddit/60);
    string mins = to_string(reddit%60);
    if (mins.length() == 1)
        mins = "0" + mins;
    cout << hours + ":" + mins << "\n";
}
