#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 1000000007

using namespace std;

string addOne (string s){
    if (s[s.length () - 1] != '9')
        return s.substr (0, s.length () - 1) + (char)(s[s.length () - 1] + 1);
    return addOne (s.substr (0, s.length () - 1)) + "0";
}

int sum (string s){
    int ans = 0;
    for (int i = 0; i < s.length (); i++)
        ans += s[i] - 48;
    return ans;
}

string smallest (int target, int length){
    string ans = "";
    for(; target > 9; target -= 9)
        ans = ans + "9";
    if (target != 0)
        ans = (char)(target+48) + ans;
    while (ans.length () < length)
        ans = "0" + ans;
    return ans;
}

string greedy (int target, string s){
    if (s[0] - 48 > target || target > 9*s.length ())
        return "f";
    if (s.length () == 1){
        if (target < 10 && target >= s[0]-48){
            string temp (1, target + 48);
            return temp;
        }
        return "f";
    }
    string temp = greedy (target - s[0] + 48, s.substr (1));
    if (temp[0] == 'f'){
        if (s[0] == '9' || s[0] - 47 > target)
            return "f";
        char first = max(s[0] + 1, 48+target - 9*((int)s.length () - 1));
        return first + smallest (target - first + 48, s.length () - 1);
    }
    return s[0] + temp;
}

int main ()
{
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int cases = 0; cases < tt; cases++)
	{
        string s;
        cin >> s;
        int n = s.length ()/2;
        string left = s.substr (0, n), right = addOne (s.substr (n));
        if (right.length () != n){
            left = addOne (left);
            cout << left + smallest (sum (left), n) << endl;
            continue;
        }
        string ans = greedy (sum(left), right);
        if (ans[0] == 'f'){
            left = addOne (left);
            cout << left + smallest (sum (left), n) << endl;
        }
        else
            cout << left + ans << endl;
	}
}
