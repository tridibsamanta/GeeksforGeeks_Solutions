/**
 * Title   : Uncommon characters
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/uncommon-characters/0/
 **/

#include<bits/stdc++.h>
using namespace std;

void getUncommonCharacters(string str1, string str2) {

    map<char, int> hm;

    for (int i = 0; str1[i]; ++i) {
        hm[str1[i]] = 1;
    }

    for (int i = 0; str2[i]; ++i) {
        if (hm[str2[i]] == 0)
            hm[str2[i]] = 2;
        else if (hm[str2[i]] != 2)
            hm[str2[i]] = 3;
    }

    for (auto it : hm) {
        if (it.second != 3)
            cout << it.first;
    }

}

int main() {

	int t;
	cin >> t;
	cin.ignore();
	while (t--) {

        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);

        getUncommonCharacters(str1, str2);
	    cout << '\n';
	}

	return 0;

}
