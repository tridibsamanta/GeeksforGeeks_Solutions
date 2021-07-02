/**
 * Title   : Count Palindrome Sub-Strings of a String
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends

// dp[i][j] = stores whether s[i..j] is palindrome
int dp[1001][1001];

bool (isPalindrome(char s[], int i, int j)) {

    if (i > j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != s[j])
        return dp[i][j] = 0;

    return dp[i][j] = isPalindrome(s, i + 1, j - 1);
}

int CountPS(char S[], int N) {

    memset(dp, -1, sizeof(dp));

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (isPalindrome(S, i, j))
                ++cnt;
        }
    }

    return cnt;
}

// T.C. - O(n^2)
// S.C. - O(n^2)
