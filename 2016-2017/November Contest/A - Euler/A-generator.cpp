#include <bits/stdc++.h>

using namespace std; 

int main () {
    srand(time(0));
    vector<int> years(2016);
    for (int i = 0; i < 2016; i++)
        years[i] = i+1;
    random_shuffle(years.begin(), years.end());
    int n = rand()%1000+1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << years[i] << " " << years[i] << "\n";
}
