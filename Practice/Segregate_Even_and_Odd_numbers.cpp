/**
 * Title   : Segregate Even and Odd numbers
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-numbers4629/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	void segregateEvenOdd(int arr[], int n) {

	    int even = 0, odd = n - 1;

	    while (even < odd) {

	        while (arr[even] % 2 == 0 && even < odd) {
	            ++even;
	        }

	        while (arr[odd] % 2 != 0 && even < odd) {
	            --odd;
	        }

	        if (even < odd) {
	            swap(arr[even++], arr[odd--]);
	        }

	    }

	    vector<int> dummy;

	    for (int i = 0; i < n; ++i) {
	        if (arr[i] % 2 == 0)
	            dummy.push_back(arr[i]);
	        else
	            break;
	    }

	    sort(dummy.begin(), dummy.end());

	    int evenCount = dummy.size();

	    for (int i = 0; i < evenCount; ++i) {
	        arr[i] = dummy[i];
	    }

	    dummy.clear();

	    for (int i = evenCount; i < n; ++i) {
	        dummy.push_back(arr[i]);
	    }

	    sort(dummy.begin(), dummy.end());

	    for (int i = 0; i < dummy.size(); ++i) {
	        arr[i + evenCount] = dummy[i];
	    }

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
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
