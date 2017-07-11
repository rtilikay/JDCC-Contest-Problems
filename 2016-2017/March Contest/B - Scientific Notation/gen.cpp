#include <bits/stdc++.h>

using namespace std;

const char* const outputs[10] = {"1", "1.49 * 10^0", "2.45 * 10^1", "100", "420", "123456789", "300500300", "9.99 * 10^8", "1000000000", "1.00 * 10^9"};

int main () {
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        cout << outputs[i] << "\n";
    }
}
