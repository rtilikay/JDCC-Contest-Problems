#include <bits/stdc++.h>

using namespace std;

const int BOUND = 10;

const char* words [3][10] = {
    {"a", "ae", "aiggi", "ieelai", "lllaaaa", "abcdeeeee", "u", "uvu", "o", "oo"},
    {"y", "bcd", "b", "abb", "abc", "eodfg", "hello", "world", "not", "earth"},
    {"ab", "ay", "lmao", "look", "at", "thesee", "cool", "aqde", "yo", "lloonnggiiee"}};

int main () {
    srand(time(0));
    for (int i = 0; i < BOUND; ++i) {
        if (i != 0)
            cout << " ";
        cout << words[rand()%3][rand()%10];
    }
    cout << "\n";
}
