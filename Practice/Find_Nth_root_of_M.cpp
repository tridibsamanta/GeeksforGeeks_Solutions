/**
 * Title   : Find Nth root of M
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
 **/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	bool getMultiple(double val, int n, int num) {
	    double ans = 1.0;
	    for (int i = 1; i <= n; ++i) {
		    ans *= val;
	    }
	    return ans < (double)num;
    }

	int NthRoot(int n, int m) {

	    double lo = 1, hi = m;

	    while (lo <= hi) {

		    double mid = (lo + hi) / 2.0;

		    if (getMultiple(mid, n, m))
			    lo = mid + 1e-6;
		    else
			    hi = mid - 1e-6;
	    }

        int nth_root = round(lo);
	    return (pow(nth_root, n) != m) ? -1 : nth_root;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
