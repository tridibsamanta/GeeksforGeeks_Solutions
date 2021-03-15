/**
 * Title   : Word Break
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/word-break1352/1
 **/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {

        int n = A.length();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {

            for (int j = 0; j < i; ++j) {

                if (dp[j] && find(B.begin(), B.end(), A.substr(j, i - j)) != B.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
}
