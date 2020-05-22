/**
 * Title   : Last index of One
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/last-index-of-1/0
 **/

#include<iostream>
using namespace std;

int findLastIndex(string s) {

    int len = s.length();

    int i;
    for (i = len - 1; i >= 0; --i) {
        if (s[i] == '1')
            break;
    }

    if (i >= 0)
        return len - (len - i);
    return i;
}

int main()
 {
	int t;
	cin >> t;
	while (t--) {

	    string s;
	    cin >> s;

	    int index = findLastIndex(s);
	    cout << index << '\n';

	}
	return 0;
}
