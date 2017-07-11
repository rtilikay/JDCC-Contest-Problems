#include <bits/stdc++.h>
#define ll long long 

using namespace std; 

struct interval {
    double l, r;

    interval() {}
    interval(double l, double r) : l(l), r(r) {}

    bool operator< (const interval &other) {
        return l < other.l;
    }
};

int main () {
    cin.sync_with_stdio(0);
    cin.tie();
    ll n, l;
    cin >> n >> l;
    double x[n], y[n], v[n], w[n];
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> v[i] >> w[i];

    double lo = 0, hi = 9999999999L, mi;
    while (hi - lo > 0.0001) {
        mi = (hi+lo)/2;
        vector<interval> inv;

        for (int i = 0; i < n; ++i) {
            if (v[i]*mi < y[i]) {
                continue;
            }
            double t = mi - y[i]/v[i];
            inv.push_back({x[i]-t*w[i], x[i]+t*w[i]});
        }
        if (inv.size() == 0) {
            lo = mi;
            continue;
        }
        sort(inv.begin(), inv.end());
        double lowest = inv[0].l, highest = inv[0].r;
        bool bad = false;
        for (int i = 1; i < inv.size(); ++i) {
            if (inv[i].l > highest) {
                bad = true;
                break;
            }
            highest = max(highest, inv[i].r);
        }
        if (bad || lowest > -l || highest < l) {
            lo = mi;
            continue;
        } else {
            hi = mi;
            continue;
        }
    }
    cout << fixed << setprecision(2) << mi << "\n";
}
