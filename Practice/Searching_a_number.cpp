/**
 * Title   : Searching a number
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/searching-a-number0324/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	int search(int arr[], int n, int k) {

	    for (int i = 0; i < n; ++i) {
	        if (arr[i] == k)
	            return i + 1;
	    }

	    return -1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, k;
        cin >> n >> k;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.search(a, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
