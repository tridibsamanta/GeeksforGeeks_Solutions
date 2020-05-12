/**
 * Title   : Reverse a string using Stack
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
// } Driver Code Ends


void reverse(char *str, int len)
{
    stack<char> S;
    for (int i = 0; i < len; ++i)
        S.push(str[i]);

    for (int i = 0; i < len; ++i) {
        str[i] = S.top();
        S.pop();
    }
}
