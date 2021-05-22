/**
 * Title   : Number Game
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/number-game0303/1
 **/

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long numGame(long long n) {

        long long ans = 1;

        for (long long i = 2; i <= n; ++i) {
            ans = ((ans * i) / __gcd(ans, i)) % 1000000007;
        }

        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;

        cin>>n;

        Solution ob;
        cout << ob.numGame(n) << endl;
    }
    return 0;
}  // } Driver Code Ends
