/**
 * Title   : Smallest window in a string containing all the characters of another string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0
 **/

#include<bits/stdc++.h>
using namespace std;

const int total_chars = 256;

void getSmallestSubstring(string str, string pat) {

    if (str.length() < pat.length()) {
        cout << -1;
        return;
    }

    int patFreq[total_chars];
    memset(patFreq, 0, sizeof(patFreq));

    int strFreq[total_chars];
    memset(strFreq, 0, sizeof(strFreq));

    for (int i = 0; pat[i]; ++i)
        ++patFreq[pat[i]];

    int charCount = 0, currStartIdx = 0, minStartIdx = -1, minLength = INT_MAX;

    for (int i = 0; str[i]; ++i) {

        ++strFreq[str[i]];

        if (patFreq[str[i]] != 0 && strFreq[str[i]] <= patFreq[str[i]])
            ++charCount;

        if (charCount == pat.length()) {

            while (patFreq[str[currStartIdx]] == 0 || strFreq[str[currStartIdx]] > patFreq[str[currStartIdx]]) {

                if (strFreq[str[currStartIdx]] > patFreq[str[currStartIdx]])
                    --strFreq[str[currStartIdx]];

                ++currStartIdx;
            }

            int currLength = i - currStartIdx + 1;
            if (minLength > currLength) {
                minLength = currLength;
                minStartIdx = currStartIdx;
            }
        }
    }

    if (minStartIdx == -1) {
        cout << -1;
        return;
    }

    cout << str.substr(minStartIdx, minLength);

}

int main() {

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while (t--) {

        string str, pat;
        getline(cin, str);
        getline(cin, pat);

        getSmallestSubstring(str, pat);

        cout << '\n';
    }

    return 0;
}
