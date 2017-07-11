#include <bits/stdc++.h>

using namespace std;

const int BOUND = 50, BOUND_H = 900;
int n, h[BOUND];
int dp [BOUND+1][BOUND_H+1][BOUND_H+1];

pair<int, int> solve () {
    memset(dp, 0, sizeof(dp));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += h[i];
    }
    for (int i = 0; i <= n; ++i)
        dp[i][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= BOUND_H; ++j) {
            for (int k = 0; k <= BOUND_H; ++k) {
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= h[i])
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j-h[i]][k];
                if (k >= h[i])
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-h[i]];
            }
        }
    }

    int best = 9999;
    for (int i = 0; i <= BOUND_H; ++i) {
        for (int j = 0; j <= BOUND_H; ++j) {
            if (!dp[n][i][j])
                continue;
            int hi = max(i, max(j, sum - i - j));
            best = min(best, hi);
        }
    }
    return {best, sum};
}

int main () {
    srand(time(0));
    n = BOUND;
    cout << n << "\n";
    // 30% chance of random data
    while (1) {
        if (rand()%10 > 6) {
            for (int i = 0; i < n; ++i) {
                int m = 0;
                for (int j = 0; j < 10; ++j)
                    m += rand()%((BOUND-10)*2)+1;
                m = (m / 10)%BOUND + 1;
                h[i] = m;
            }
        } else {
            // 70% chance of only two numbers.
            int m = rand()%n;
            for (int i = 0; i < m; ++i) {
                h[i] = BOUND;
            }
            int k = rand()%BOUND+1;
            for (int i = m; i < n; ++i) {
                h[i] = k;
            }
        }
        // best, sum.
        pair<int, int> res = solve();
        if (res.first != (res.second+2)/3) {
            for (int i = 0; i < n; ++i) {
                if(i)
                    cout << " ";
                cout << h[i];
            }
            break;
        }
    }
}
