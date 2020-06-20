/**
 * Title   : Anagram
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/anagram/0
 **/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin >> t;
    while (t--) {

        string s1, s2;
        cin >> s1 >> s2;

        if (s1.length() != s2.length())
            cout << "NO\n";
        else {
            int asc_s1 = 0, asc_s2 = 0;
            for (int i = 0; i < s1.length(); ++i) {
                asc_s1 += s1[i];
                asc_s2 += s2[i];
            }

            cout << (asc_s1 == asc_s2 ? "YES" : "NO") << '\n';
        }
    }
	return 0;
}
