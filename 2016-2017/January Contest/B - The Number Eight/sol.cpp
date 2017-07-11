#include <bits/stdc++.h>

using namespace std; 

int h;

void line() {
    for (int i = 0; i < (h+1)/2; ++i)
        cout << "*";
    cout << "\n";
}

void hole() {
    cout << "*";
    for (int i = 1; i < h/2; ++i)
        cout << " ";
    cout << "*\n";
}

int main () { 
    cin >> h;
    int n = (h - 3)/2;
    line();
    for (int i = 0; i < n; ++i) hole();
    line();
    for (int i = 0; i < n; ++i) hole();
    line();
}
