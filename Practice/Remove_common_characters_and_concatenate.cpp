/**
 * Title   : Remove common characters and concatenate
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/remove-common-characters-and-concatenate/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;
	cin.ignore();
	while (t--) {

	    string s1, s2;
	    getline(cin, s1);
	    getline(cin, s2);

        int freq1[26], freq2[26];
        memset(freq1, 0, sizeof(freq1));
        memset(freq2, 0, sizeof(freq2));

        for (int i = 0; s1[i]; ++i) {
            ++freq1[s1[i] - 'a'];
        }

	    for (int i = 0; s2[i]; ++i) {
            ++freq2[s2[i] - 'a'];
        }

	    string res = "";

	    for (int i = 0; s1[i]; ++i) {
            if (freq2[s1[i] - 'a'] == 0)
                res += s1[i];
        }

        for (int i = 0; s2[i]; ++i) {
            if (freq1[s2[i] - 'a'] == 0)
                res += s2[i];
        }

        if (res == "")
            cout << -1 << '\n';
        else
            cout << res << '\n';
	}

	return 0;
}
