/**
 * Title   : Remove character
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/remove-character/0
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeCharacter(string s1, string s2) {

            string res = "";

            bool arr[26];
            memset(arr, false, sizeof(arr));

            for (int i = 0; s2[i]; ++i) {
                arr[s2[i] - 'a'] = true;
            }

            for (int j = 0; s1[j]; ++j) {
                if (!arr[s1[j] - 'a'])
                    res += s1[j];
            }

            return res;
        }
};

int main() {

    int tc;
    cin >> tc;

    while (tc--) {

        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;

        string res = ob.removeCharacter(s1, s2);
        cout << res << '\n';

    }

    return 0;
}
