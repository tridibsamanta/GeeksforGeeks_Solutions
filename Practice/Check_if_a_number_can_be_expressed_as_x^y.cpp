/**
 * Title   : Check if a number can be expressed as x^y
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-if-a-number-can-be-expressed-as-xy1606/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:
    int checkPower(int N){

        if (N == 1)
            return 1;

        for (int x = 2; x <= sqrt(N); ++x) {

            int y = x;

            while (y <= N) {

                y *= x;

                if (y == N)
                    return 1;
            }
        }

        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkPower(N) << endl;
    }
    return 0;
}   // } Driver Code Ends
