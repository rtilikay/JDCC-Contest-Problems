#include <bits/stdc++.h>
#define ll long long

using namespace std; 

const ll MOD = 1000000007;

// Credit to Standford ACM Codebook.
// returns g = gcd(a, b); finds x, y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a / b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}

// Credit to Standford ACM Codebook.
// computes b such that ab = 1 (mod n), returns -1 on failure
ll inv(int a) {
	int x, y;
	int g = extended_euclid(a, MOD, x, y);
	if (g > 1) return -1;
	return x%MOD;
}

ll fact (int n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans * i)%MOD;
    }
    return ans;
}

ll choose (ll n, ll k) {
	if (n < k)
		return 0;
	ll ans = inv(fact(k));
	for (ll i = n; i > n-k; i--)
		ans = (ans*i)%MOD;
	return ans;
}

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    n -= k;
    ll tot = choose(n+m, n);
    ll bad = choose(n+m, n+1);
    ll ans = (tot - bad + MOD) % MOD;
    cout << ans << "\n";
}
