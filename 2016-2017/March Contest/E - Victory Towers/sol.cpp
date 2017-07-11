#include <bits/stdc++.h>

using namespace std; 

const int BOUND = 900;

bool dp [51][BOUND+1][BOUND+1];

int main () { 
    int n;
    cin >> n; 
    int h[n], sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        sum += h[i];
    }

    for (int i = 0; i <= n; ++i)
        dp[i][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= BOUND; ++j) {
            for (int k = 0; k <= BOUND; ++k) {
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= h[i])
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j-h[i]][k];
                if (k >= h[i])
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-h[i]];
            }
        }
    }

    int best = 9999;
    for (int i = 0; i <= BOUND; ++i) {
        for (int j = 0; j <= BOUND; ++j) {
            if (!dp[n][i][j])
                continue;
            int hi = max(i, max(j, sum - i - j));
            best = min(best, hi);
        }
    }

    cout << best << "\n";
}
