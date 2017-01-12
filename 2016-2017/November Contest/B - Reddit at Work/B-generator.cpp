#include <bits/stdc++.h>

using namespace std; 

string parse (int n) {
    int hours = n/60, mins = n%60;
    if (hours > 12) hours -= 12;
    string h = to_string(hours), m = to_string(mins);
    if (m.length() == 1)
        m = "0" + m;
    return h + ":" + m;
}

int main () {
    srand(time(0));
    vector<int> mins(480);
    for (int i = 0; i < 480; i++)
        mins[i] = 540 + i;
    int n = rand()%100 + 1;
    vector<int> sample(n);
    random_shuffle(mins.begin(), mins.end());
    for (int i = 0; i < n; i++)
        sample[i] = mins[i];
    sort(sample.begin(), sample.end());

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int fin = rand()%(1021 - sample[i]) + sample[i] + 1;
        if (fin == 1021) fin--;
        cout << parse(sample[i]) << " " << parse(fin) << "\n";
    }
}
