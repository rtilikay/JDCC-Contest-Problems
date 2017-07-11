#include <bits/stdc++.h>

using namespace std; 

int main () { 
    int v = 0, c = 0;
    string s;
    unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    while (cin >> s) {
        int vo = 0;
        for (char c : s)
            if (vowels.count(c) > 0)
                ++vo;
        if (2*vo >= s.length()) {
            ++v;
        } if (2*vo <= s.length()) {
            ++c;
        }
    }
    if (v > c) {
        cout << "Vibberish\n"; 
    } else if (c > v) {
        cout << "Cibberish\n";
    } else if (c == v) {
        cout << "Gibberish\n";
    }
}
