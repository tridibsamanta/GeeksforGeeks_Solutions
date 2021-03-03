/**
 * Title   : Maximum Product Subarray
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {

        if (n == 0)
            return 0;

        if (n == 1)
            return arr[0];

        long long maxProd = arr[0], minProd = arr[0], ans = arr[0];

        for (int i = 1; i < n; ++i) {

            if (arr[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(maxProd * arr[i], (long long)arr[i]);
            minProd = min(minProd * arr[i], (long long)arr[i]);

            ans = max(ans, maxProd);
        }

        return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
