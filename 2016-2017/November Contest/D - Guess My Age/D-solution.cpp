#include <bits/stdc++.h>

using namespace std; 

int main () {
    int n, k;
    cin >> n >> k;
    int dp[n+1];
    dp[1] = 0;
    dp[2] = 100+k;
    for (int i = 3; i <= n; i++) {
        dp[i] = 0x70707070;
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], max(100 + dp[j], 100 + k + dp[i-j]));
        }
    }
    cout << dp[n] << "\n";
}
