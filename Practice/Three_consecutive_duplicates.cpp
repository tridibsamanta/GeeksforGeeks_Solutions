/**
 * Title   : Three consecutive duplicates
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/three-consecutive-duplicates/0
 **/

#include<bits/stdc++.h>
using namespace std;

string removeKDuplicates(string s, int k) {

    vector<pair<int, char>> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (stk.size() ==0)
            stk.push_back({1, s[i]});
        else if (stk.back().second != s[i])
            stk.push_back({1, s[i]});
        else if (++stk.back().first == k)
            stk.pop_back();
    }

    string res;
    for (int i = 0; i < stk.size(); ++i)
        res.append(stk[i].first, stk[i].second);

    return res;
}

int main()
 {
	int t;
	cin >> t;
	while (t--) {

	    string s;
	    cin >> s;

	    int k = 3;

	    string res = removeKDuplicates(s, k);
	     cout << (res.size() == 0 ? "-1" : res) << '\n';


	}
	return 0;
}
