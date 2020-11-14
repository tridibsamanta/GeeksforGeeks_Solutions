/**
 * Title   : Shortest Common Supersequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
 **/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{

    int t;
    char X[10001], Y[10001];

    //taking total testcases
    cin >> t;
    while(t--){

    //taking String X and Y
	cin >> X >> Y;

	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n

int dp[1001][1001];

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {

    for (int i = 0; i < n + 1; ++i)
        dp[0][i] = 0;
    for (int i = 0; i < m + 1; ++i)
        dp[i][0] = 0;

    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return m + n - dp[m][n];
}
