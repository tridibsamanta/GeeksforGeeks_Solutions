/**
 * Title   : Implement Atoi
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/implement-atoi/1
 **/

// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str)
{
    int len = str.length();
    int num = 0, i = 0;
    int sign = 1;
    if (str[0] == '-')
        sign = -1;
    if (sign == -1)
        i = 1;
    for (; i < len; ++i) {
        int asc = str[i];
        if (asc >= 48 && asc <= 57)
            num = (num * 10) + (asc - 48);
        else
            break;
    }
    if (i == len)
            return num * sign;
    else
        return -1;
}
