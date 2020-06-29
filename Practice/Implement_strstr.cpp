/**
 * Title   : Implement strstr
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/implement-strstr/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;

        cin>>a;
        cin>>b;

        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     int len1 = s.length();
     int len2 = x.length();

     for (int i = 0; i <= len1 - len2; ++i) {

            int j;
            for (j = 0; j < len2; ++j) {
                if (s[i + j] != x[j])
                    break;
            }

            if (j == len2)
                return i;
     }
     return -1;
}
