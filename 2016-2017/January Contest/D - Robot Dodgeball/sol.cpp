#include <bits/stdc++.h>

using namespace std; 

const int BOUND = 10000;

int n, r;
vector<int> in [BOUND+1];
vector<int> out [BOUND+1];
int team [BOUND+1];

void set_teams (int cur) {
    for (int i : in[cur]) {
        if (team[i] == 0) {
            team[i] = 3 - team[cur];
            set_teams(i);
        }
        if (team[i] == team[cur])
            cout << "WOAH SAME TEAM!!!!!!!!!!!\n";
    }
    for (int i : out[cur]) {
        if (team[i] == 0) {
            team[i] = 3 - team[cur];
            set_teams(i);
        }
        if (team[i] == team[cur])
            cout << "WOAH SAME TEAM!!!!!!!!!!!\n";
    }
}

int main () { 
    cin >> n >> r;
    team[r] = 1;
    for (int i = 1; i <= n; i++) {
        int m, t; 
        cin >> m; 
        while (m--) { 
            cin >> t;
            out[i].push_back(t);
            in[t].push_back(i);
        }
    }
    set_teams(r);
    int one = 0, two = 0;
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0)
            cout << "BADBADBADBABDBADBADBABD\n";
        if (in[i].size() == 0)
            (team[i] == 1) ? (++one) : (++two);
    }
    cout << one << " " << two << "\n";
}
