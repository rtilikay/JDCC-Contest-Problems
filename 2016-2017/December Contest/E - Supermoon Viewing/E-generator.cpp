#include <bits/stdc++.h>

using namespace std; 

const int lim = 1000;

int main () {
    srand(time(0));
    int xw = rand()%lim + 1, yw = rand()%lim+1;
    int xm = rand()%lim+1, ym = rand()%lim+1;
    int rw = rand()%lim+1;
    int minr = sqrt(pow(xm-xw, 2) + pow(ym-yw, 2)) - rw + 1;
    minr = max(minr, 1);
    int rm = rand()%100 + minr;
    printf ("%d %d %d\n", xw, yw, rw);
    printf ("%d %d %d\n", xm, ym, rm);
}
