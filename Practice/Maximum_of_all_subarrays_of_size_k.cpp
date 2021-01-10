/**
 * Title   : Maximum of all subarrays of size k
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


vector <int> max_of_subarrays(int *arr, int n, int k){

    vector<int> maxVals;

    multiset<int, greater<int> > mst;

        int i = 0, j = 0;

        while (j < n) {

            mst.insert(arr[j]);

            if (j - i + 1 < k) {
                ++j;
            }
            else if (j - i + 1 == k) {

                maxVals.push_back(*(mst.begin()));

                mst.erase(mst.find(arr[i]));

                ++i;
                ++j;
            }
        }

    return maxVals;
}


// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int n, k;
	    cin >> n >> k;

	    int arr[n];
	    for(int i = 0;i<n;i++)
	        cin >> arr[i];

	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	    cout << endl;

	}

	return 0;
}  // } Driver Code Ends
