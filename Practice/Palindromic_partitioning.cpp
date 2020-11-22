/**
 * Title   : Palindromic partitioning
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
 **/

// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// User function Template for C++

class Solution{
public:
    bool palindrome[2001][2001];

    int palindromicPartition(string str)
    {
        int n = str.length();

        memset(palindrome, false, sizeof(palindrome));

        for (int i = 0; i < n; ++i) {
            palindrome[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1])
                palindrome[i][i + 1] = true;
        }

        for (int currLen = 3; currLen <= n; ++currLen) {

            for (int startIdx = 0; startIdx <= n - currLen; ++startIdx) {

                int endIdx = startIdx + currLen - 1;

                if (str[startIdx] == str[endIdx] && palindrome[startIdx + 1][endIdx - 1])
                    palindrome[startIdx][endIdx] = true;
            }
        }

        int minCuts[n];

        for (int i = 0; i < n; ++i) {

            int currCuts = INT_MAX;

            if (palindrome[0][i])
                minCuts[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (palindrome[j + 1][i] && currCuts > minCuts[j] + 1)
                        currCuts = minCuts[j] + 1;
                }
                minCuts[i] = currCuts;
            }
        }

        return minCuts[n - 1];
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
