#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int BOUND_N = 30;
const int BOUND_M = 100000; // Change to 1 for 20% of cases.

int main () {
    srand(time(0));
    cout << BOUND_N << " " << BOUND_M << "\n";
    unordered_set<string> m;
    while (m.size() < BOUND_M) {
        int len = rand()%7+1;
        string s;
        while (len--)
            s = s + (char)(rand()%26+65);
        m.insert(s);
    }
    for (auto &s : m)
        cout << s << endl;
}
