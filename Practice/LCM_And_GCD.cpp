/**
 * Title   : LCM And GCD
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long

class Solution {
  private:
    ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
    	return  (a / gcd(a, b)) * b;
    }

  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<ll> res(2);
        res[1] = gcd(A, B);
        res[0] = lcm(A, B);
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;

        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
