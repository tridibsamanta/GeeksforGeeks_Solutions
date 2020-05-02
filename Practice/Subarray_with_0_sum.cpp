/**
 * Title   : Subarray with 0 sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
 **/

#include<iostream>
#include<unordered_set>
using namespace std;

bool findSubarray(int arr[], int n) {
    int sum = 0;
    unordered_set<int> preSum;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum == 0 || preSum.find(sum) != preSum.end())
            return true;
        preSum.insert(sum);
    }
    return false;
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
	    cout << (findSubarray(arr, n) ? "Yes" : "No") << '\n';
	}
	return 0;
}
