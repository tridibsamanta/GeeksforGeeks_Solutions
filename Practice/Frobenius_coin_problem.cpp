/**
 * Title   : Frobenius coin problem
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/frobenius-coin-problem5532/1
 **/

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	int gcd(int a, int b) {
	    return (b == 0) ? a : gcd(b, a % b);
	}

   	vector<int> forbenius(int X, int Y){
   	    if (gcd(X, Y) != 1) {
   	        return vector<int> {-1};
   	    }
   	    else {
   	        int maxAmount = (X * Y) - (X + Y);
   	        int total = ((X - 1) * (Y - 1)) / 2;
   	        return vector<int> {maxAmount, total};
   	    }
    }
};
// T.C. - O(log max(X, Y))

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int X, Y;
		cin >> X >> Y;
		Solution ob;
		vector<int> ans = ob.forbenius(X, Y);
		for(auto i : ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
