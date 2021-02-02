/**
 * Title   : Excel Sheet | Part - 2
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/excel-sheet-part-21138/1
 **/

// { Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;
int ExcelColumnNumber(string s);


 // } Driver Code Ends


//User function template for C++


int ExcelColumnNumber(string s) {

    int res = 0;

    for (int i = 0; s[i]; ++i) {
        res = (res * 26) + (s[i] - 'A' + 1);
    }

    return res;
}

// { Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<ExcelColumnNumber(s)<<endl;
    }
}  // } Driver Code Ends
