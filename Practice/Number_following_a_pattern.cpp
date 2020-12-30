/**
 * Title   : Number following a pattern
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
 **/

#include<bits/stdc++.h>
using namespace std;

string minPermPattern(string s) {

    int n = s.length();

    if (n >= 9)
        return "-1";

    string res(n + 1, ' ');

    int curr = 1, prev_I = -1;

    for (int i = 0; i <= n; ++i) {

        if (i == n || s[i] == 'I') {

            for (int k = i; k > prev_I; --k) {
                res[k] = '0' + curr++;
            }

            prev_I = i;
        }
    }

    return res;
}

/*
string minPermPattern(string s) {

    int n = s.length();

    string res = "";

    stack<int> stk;

    for (int i = 0; i <= n; ++i) {

        stk.push(i + 1);

        if (i == n || s[i] == 'I') {
            while (!stk.empty()) {
                res += to_string(stk.top());
                stk.pop();
            }
        }
    }

    return res;
}
*/

int main() {

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        string res = minPermPattern(s);
        cout << res << '\n';
    }

    return 0;
}
