#include <bits/stdc++.h>

using namespace std; 

int main () { 
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[2] < 90)
        cout << "acute";
    else if (a[2] > 90)
        cout << "obtuse";
    else
        cout << "right";

    if (a[2] == 60)
        cout << " equilateral";
    else if (a[0] == a[1] || a[1] == a[2])
        cout << " isoseles";
    else
        cout << " scalene";
    cout << endl;
}
