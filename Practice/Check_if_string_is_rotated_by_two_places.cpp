/**
 * Title   : Check if string is rotated by two places
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool validateRotation(string s1, string s2) {

    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 != len2)
        return false;

    string rotate_anticlock = "", rotate_clock = "";

    rotate_anticlock = s1.substr(2) + s1.substr(0, 2);
    rotate_clock = s1.substr(len1 - 2) + s1.substr(0, len1 - 2);

    return (s2.compare(rotate_anticlock) == 0 || s2.compare(rotate_clock) == 0);

}

int main() {

    int t;
    cin >> t;
    while(t--) {

        string s1, s2;
        cin >> s1 >> s2;

        if (validateRotation(s1, s2))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
