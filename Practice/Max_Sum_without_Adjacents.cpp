/**
 * Title   : Max Sum without Adjacents
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:
    /*
	int findMaxSum(int *arr, int n) {

	    if (n == 1)
	        return arr[0];

	    vector<int> dp(n);

	    dp[0] = arr[0];
	    dp[1] = max(arr[0], arr[1]);

	    for (int i = 2; i < n; ++i) {
	        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
	    }

	    return dp[n - 1];
	}
	*/

    int findMaxSum(int *arr, int n) {

	    if (n == 1)
	        return arr[0];

	    int dp1 = arr[0];
	    int dp2 = max(arr[0], arr[1]);

	    int res = dp2;

	    for (int i = 2; i < n; ++i) {
	        res = max(arr[i] + dp1, dp2);
	        dp1 = dp2;
	        dp2 = res;
	    }

	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
