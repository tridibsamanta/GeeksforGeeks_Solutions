/**
 * Title   : Nuts and Bolts Problem
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool compare(char a, char b) {
    return (int(a) < int(b));
}

void findMatches(char nuts[], char bolts[], int n) {

    /*
    unordered_map<char, int> hm;

    for (int i = 0; i < n; ++i)
        hm[nuts[i]]++;

    for (int i = 0; i < n; ++i)
        if (hm.find(bolts[i]) != hm.end())
            nuts[i] = bolts[i];
    */

    sort(nuts, nuts + n, compare);
    sort(bolts, bolts + n, compare);

    for (int i = 0; i < n; ++i)
        cout << nuts[i] << ' ';
    cout << '\n';

    for (int i = 0; i < n; ++i)
        cout << bolts[i] << ' ';
    cout << '\n';
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

    int n;
    cin >> n;

    char nuts[n];
    for (int i = 0; i < n; ++i)
        cin >> nuts[i];

    char bolts[n];
    for (int i = 0; i < n; ++i)
        cin >> bolts[i];

    findMatches(nuts, bolts, n);

    }

    return 0;
}
