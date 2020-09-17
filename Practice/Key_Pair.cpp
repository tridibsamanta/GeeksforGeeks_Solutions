/**
 * Title   : Key Pair
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/key-pair/0
 **/

 // { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	// Function to check if array has 2 elements
	// whose sum is equal to the given value

	// Approach 1 : T.C. - O(n), S.C. - O(n)
	/*
	bool hasArrayTwoCandidates(int arr[], int n, int x) {

	    unordered_map<int, int> hm;

	    for (int i = 0; i < n; ++i) {

	        if (hm[x - arr[i]] == 0) {
	            hm[arr[i]] = i + 1;
	        }
	        else {
	            return true;
	        }
	    }
	    return false;
	}
	*/

	// Approach 2 : T.C. - O(n log n), S.C. - O(1)

	bool hasArrayTwoCandidates(int arr[], int n, int x) {

	    sort(arr, arr + n);

	    int l = 0, r = n - 1;

	    while (l < r) {

	        if (arr[l] + arr[r] == x)
	            return true;

	        int l_val = arr[l], r_val = arr[r];

	        if (arr[l] + arr[r] < x) {
	            while (l < r && arr[l] == l_val)
	                ++l;
	        }
	        else {
	            while (l < r && arr[r] == r_val)
	                --r;
	        }
	    }

	    return false;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
// } Driver Code Ends
