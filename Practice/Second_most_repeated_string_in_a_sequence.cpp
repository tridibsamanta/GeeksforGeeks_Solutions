/**
 * Title   : Second most repeated string in a sequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence/0
 **/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> arr, int n) {

    unordered_map<string, int> hm;

    for (int i = 0; i < n; ++i) {
        ++hm[arr[i]];
    }

    int first = -1, second = -1;

    for (auto it : hm) {

        if (it.second > first) {
            second = first;
            first = it.second;
        }

        else if (it.second > second && it.second != first)
            second = it.second;
    }


    string res = "";

    for (auto it : hm) {

        if (it.second == second) {
            res = it.first;
            break;
        }
    }

    cout << res << '\n';
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    vector<string> arr(n);

	    for (int i = 0; i < n; ++i) {
	        cin >> arr[i];
	    }

	    solve(arr, n);

	}

	return 0;
}
