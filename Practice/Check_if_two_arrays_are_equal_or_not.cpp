/**
 * Title   : Check if two arrays are equal or not
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0/
 **/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool checkEquality(vector<ll>& arr1, vector<ll>& arr2, int n) {

    unordered_map<ll, int> hm;

    for (int i = 0; i < n; ++i) {
        ++hm[arr1[i]];
    }

    for (int i = 0; i < n; ++i) {
        --hm[arr2[i]];
    }

    for (auto it : hm) {
        if (it.second != 0)
            return false;
    }

    return true;
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    vector<ll> arr1(n);
	    vector<ll> arr2(n);

	    for (int i = 0; i < n; ++i)
	        cin >> arr1[i];

	    for (int i = 0; i < n; ++i)
	        cin >> arr2[i];

	    if (checkEquality(arr1, arr2, n))
	        cout << 1 << '\n';
	    else
	        cout << 0 << '\n';
	}

	return 0;
}
