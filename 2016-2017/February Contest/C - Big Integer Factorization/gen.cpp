#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll big_primes[5] = {12121787, 12356789, 13112221, 15485863, 16431563};

const ll really_big_prime = 999998727899999LL; 

int main () {
    srand(time(0));
    // Use big primes.
    int n = rand()%10;
    if (n < 5) {
        cout << big_primes[rand()%5]*big_primes[rand()%5] << "\n"; 
    } else if (n < 8) {
        ll f = rand()+1, s = rand()+1, mod = 1LL << 57;
        cout << abs((f << 32)*s%mod) << "\n";
    } else {
        cout << really_big_prime << endl;
    }
}
