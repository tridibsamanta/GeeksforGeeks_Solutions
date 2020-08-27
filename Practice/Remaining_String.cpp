/**
 * Title   : Remaining String
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/remaining-string/0/
 **/

#include<bits/stdc++.h>
using namespace std;

string getRemainingString(string str, char ch, int k) {

    if (k == 0)
        return str;

    int i;
    for (i = 0; str[i]; ++i) {
        if (str[i] == ch) {
            if (--k == 0)
                break;
        }
    }

    if (k != 0 || i == str.length() - 1)
        return ("Empty string");

    return str.substr(i + 1);

}

int main() {

	int t;
	cin >> t;
	cin.ignore();
	while (t--) {

	    string str;
	    cin >> str;

	    char ch;
	    cin >> ch;

	    int k;
	    cin >> k;

	    string res = getRemainingString(str, ch, k);
	    cout << res << '\n';
	}

	return 0;
}
