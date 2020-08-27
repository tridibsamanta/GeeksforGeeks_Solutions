/**
 * Title   : First element to occur k times
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times/0/
 **/

#include<bits/stdc++.h>
using namespace std;

int getKthOccurence(int nums[], int n, int k) {

    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        ++freq[nums[i]];
    }

    for (int i = 0; i < n; ++i) {
        if (freq[nums[i]] == k)
            return nums[i];
    }

    return -1;
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n, k;
	    cin >> n >> k;

	    int nums[n];
	    for (int i = 0; i < n; ++i)
	        cin >> nums[i];

	    cout << getKthOccurence(nums, n, k) << '\n';
	}

	return 0;
}
