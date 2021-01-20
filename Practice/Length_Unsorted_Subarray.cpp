/**
 * Title   : Length Unsorted Subarray
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/length-unsorted-subarray3022/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	vector<int> printUnsorted(int arr[], int n) {

	    int l = -1, r = -1;

	    for (int i = 0; i < n - 1; ++i) {
	        if (arr[i] > arr[i + 1]) {
	            l = i;
	            break;
	        }
	    }

	    if (l == -1)
	        return vector<int> {0, 0};

	    for (int i = n - 1; i > 0; --i) {
	        if (arr[i] < arr[i - 1]) {
	            r = i;
	            break;
	        }
	    }

	    int mx = INT_MIN, mn = INT_MAX;

	    for (int i = l; i <= r; ++i) {
	        mn = min(mn, arr[i]);
	        mx = max(mx, arr[i]);
	    }

	    for (int i = 0; i < l; ++i) {
	        if (mn < arr[i]) {
	            l = i;
	            break;
	        }
	    }

	    for (int i = n - 1; i > r; --i) {
	        if (mx > arr[i]) {
	            r = i;
	            break;
	        }
	    }

	    return vector<int> {l, r};
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
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends
