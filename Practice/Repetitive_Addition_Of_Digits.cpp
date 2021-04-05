/**
 * Title   : Repetitive Addition Of Digits
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/repetitive-addition-of-digits2221/1#
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int singleDigit(long long N) {

        if (N % 9 == 0)
            return 9;
        else
            return N % 9;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends
