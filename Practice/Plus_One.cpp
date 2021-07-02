/**
 * Title   : Plus One
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/plus-one/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {

        int carry = 1; // ♥ carryminati ♥ (www.youtube.com/user/AddictedA1)

        for (int i = N - 1; i >= 0; --i) {

            int sum = arr[i] + carry;

            if (sum > 9) {
                arr[i] = sum % 10;
                carry = 1;
            }
            else {
                arr[i] = sum;
                carry = 0;
            }
        }

        if (carry != 0)
            arr.insert(arr.begin(), 1);

        return arr;
    }
};
// T.C. - O(N)
// S.C. - O(1)

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;

        cin>>N;
        vector<int> arr(N);

        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
