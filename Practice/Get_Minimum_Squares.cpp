/**
 * Title   : Get Minimum Squares
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1
 **/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution{
	public:
	int MinSquares(int n) {

	    if (n <= 0) {
	        return 0;
	    }

	    vector<int> dp(n + 1, INT_MAX);
	    dp[0] = 0;

	    for (int i = 1; i <= n; ++i) {

	        for (int j = 1; j * j <= i; ++j) {

	            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
	        }
	    }

	    return dp[n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
