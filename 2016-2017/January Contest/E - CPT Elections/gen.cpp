#include <bits/stdc++.h>

using namespace std;

int BOUND = 1000000; // Change to 1000 for 70% of cases

int main () {
    srand(time(0));
    int n = rand()%BOUND+1, m = rand()%(n-2)+1, k = rand()%(n-m)+1;
    printf("%d %d %d\n", n, m, k);
}
