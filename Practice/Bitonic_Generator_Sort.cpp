/**
 * Title   : Bitonic Generator Sort
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/bitonic-generator-sort3343/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
	void bitonicGenerator(int arr[], int n) {

		int oddIdx = 1, evenIdx = n - 1;

		if (evenIdx & 1)
		    --evenIdx;

		while (oddIdx < evenIdx) {
		    swap(arr[oddIdx], arr[evenIdx]);
		    oddIdx += 2;
		    evenIdx -= 2;
		}

		sort(arr, arr + (n + 1) / 2);
		sort(arr + (n + 1) / 2, arr + n, greater<int>());
	}
};

// { Driver Code Starts.

int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];




        Solution ob;
        ob.bitonicGenerator(arr, n);

        for (int i = 0; i < n; i++)
        	cout << arr[i] << " ";

	    cout << "\n";

    }
    return 0;
}

  // } Driver Code Ends
