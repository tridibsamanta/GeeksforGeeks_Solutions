/**
 * Title   : Excel Sheet | Part - 1
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/excel-sheet5448/1
 **/

// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;
string ExcelColumn(int n);


 // } Driver Code Ends


//User function template for C++

string ExcelColumn(int N) {

    string res = "";

    while (N > 0) {

        int rem = N % 26;

        if (rem == 0) {
            res += 'Z';
            N = N / 26 - 1;
        }
        else {
            res += 'A' + --rem;
            N /= 26;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}


// { Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends
