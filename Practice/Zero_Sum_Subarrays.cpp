/**
 * Title   : Zero Sum Subarrays
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0/
 **/

#include<bits/stdc++.h>
using namespace std;

int SubarrayCount(int arr[], int n) {
    int sum = 0, count = 0;
    unordered_map<int, int> prefixSum;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum == 0)
            ++count;
        if (prefixSum.find(sum) != prefixSum.end())
            count += prefixSum[sum];
        ++prefixSum[sum];
    }
    return count;
}

int main()
 {
	int tc;
	cin >> tc;
	while(tc--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; ++i)
	        cin >> arr[i];
	    cout << SubarrayCount(arr, n) << '\n';
	}
	return 0;
}
