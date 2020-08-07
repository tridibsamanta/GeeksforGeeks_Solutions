/**
 * Title   : Complement
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/complement/0
 **/

#include<bits/stdc++.h>
using namespace std;

void getFlipRange(string s, int n) {

    if (n == 0) {
        cout << -1;
        return;
    }

    bool zeroPresent = false;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '0') {
            zeroPresent = true;
            break;
        }
    }

    if (!zeroPresent) {
        cout << -1;
        return;
    }

    int l = 0, r = 0;
    int currCount = 0, maxCount = INT_MIN, currStart = 0;

    for (int i = 0; s[i]; ++i) {

        if (s[i] == '0') {
            ++currCount;
            if (currCount > maxCount) {
                maxCount = currCount;
                l = currStart;
                r = i;
            }
        }
        else {
            --currCount;
            if (currCount < 0) {
                currCount = 0;
                currStart = i + 1;
            }
        }

    }
    cout << l + 1 << ' ' << r + 1;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        getFlipRange(s, n);
        cout << '\n';
    }
    return 0;
}
