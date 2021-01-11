/**
 * Title   : Longest Sub-Array with Sum K
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long

class Solution{
public:
    int lenOfLongSubarr(int A[],  int N, int K) {

        unordered_map<ll, int> ump;

        ll sum = 0;
        int maxLen = 0, i = 0;

        while (i < N) {

            sum += A[i];

            if (ump.find(sum) == ump.end())
                ump[sum] = i;

            if (sum == K)
                maxLen = i + 1;
            else if (ump.find(sum - K) != ump.end())
                maxLen = max(maxLen, i - ump[sum -K]);

            ++i;
        }

        return maxLen;
    }
};


// { Driver Code Starts.

int main() {
	//code

	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];

	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;

	}

	return 0;
}  // } Driver Code Ends
