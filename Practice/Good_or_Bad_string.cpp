/**
 * Title   : Good or Bad string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/good-or-bad-string1417/1
 **/

// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int isGoodorBad(string S) {

        int vowelCount = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == '?') {
                if (++vowelCount > 5)
                    return 0;
            }
            else {
                vowelCount = 0;
            }
        }

        int consonantCount = 0;

        for (int i = 0; i < S.length(); ++i) {
            if (!(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') || S[i] == '?'){
                if (++consonantCount > 3)
                    return 0;
            }
            else {
                consonantCount = 0;
            }
        }

        return 1;
    }

    // T.C. - O(n)
    // S.C. - O(1)
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;

        cin >> S;

        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0;
}  // } Driver Code Ends
