/**
 * Title   : Permutations of a given string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
 **/

#include<bits/stdc++.h>
using namespace std;

void printPermutations(string str, int l, int r, vector<string> &perms) {
    if (l == r)
        //cout << str << ' ';
        perms.emplace_back(str);
    else {
        for (int i = l; i <= r; ++i) {
            swap(str[l], str[i]);
            printPermutations(str, l + 1, r, perms);
            swap(str[l], str[i]);
        }
    }
}

int main()
 {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    int n = s.length();
	    vector<string> perms;
	    printPermutations(s, 0, n - 1, perms);
	    sort(perms.begin(), perms.end());
	    for(int i = 0; i < perms.size(); ++i)
	        cout << perms[i] << ' ';
	    cout << '\n';
	}
	return 0;
}
