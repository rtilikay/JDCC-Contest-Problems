#include <bits/stdc++.h>

using namespace std; 

const int BOUND_POKE = 15;

int p, end_state;
int dist [BOUND_POKE][BOUND_POKE];
int dp [BOUND_POKE][1 << BOUND_POKE];
pair <int, int> home;
vector< pair <int, int> > pokemans;

int calc_dist (pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int solve (int cur, int states) {
    if (dp[cur][states] != 0)
        return dp[cur][states];
    if (states == end_state)
        return calc_dist(pokemans[cur], home);

    int best = 0x70707070;
    for (int i = 0; i < p; i++) {
        if ((states & (1 << i)) != 0)
            continue;
        best = min(best, dist[cur][i] + solve(i, states + (1 << i)));
    }
    return dp[cur][states] = best;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'H')
                home = pair<int, int> (i, j);
            else if (s[j] == 'P')
                pokemans.push_back(pair<int, int> (i, j));
        }
    }
    p = pokemans.size();
    end_state = (1 << p) - 1;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            dist[i][j] = calc_dist(pokemans[i], pokemans[j]);
        }
    }

    int best = 0x70707070;
    for (int i = 0; i < p; i++) {
        best = min(best, calc_dist(home, pokemans[i]) + solve(i, 1 << i));
    }
    cout << best << "\n";
}

