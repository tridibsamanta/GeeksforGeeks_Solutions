/**
 * Title   : Check for subsequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-for-subsequence/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {

        string str1, str2;
        cin >> str1 >> str2;

        int len1 = str1.length(), len2 = str2.length();

        int str1_ptr = 0, str2_ptr = 0;

        while (str1_ptr < len1 && str2_ptr < len2) {
            if (str1[str1_ptr] == str2[str2_ptr]) {
                ++str1_ptr;
                ++str2_ptr;
            }
            else {
                ++str2_ptr;
            }
        }

        if (str1_ptr == len1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
