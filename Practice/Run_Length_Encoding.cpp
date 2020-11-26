/**
 * Title   : Run Length Encoding
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/run-length-encoding/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

char *encode(char *src);

int main() {

	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;

		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends

/*You are required to complete this function */

char *encode(char *src)
{
    int len = 0;
    while(*(src + len))
        len++;

    string res = "";

    int i = 0;
    while (i < len) {

        int freq = 1;

        while (i < len - 1 && src[i + 1] == src[i]) {
			++freq;
            ++i;
        }

		res += src[i];
		res += to_string(freq);

        ++i;
    }

    int res_len = res.length();

    char *rle = new char[res_len + 1];

    for(i = 0; i < res_len; ++i)
        rle[i]=res[i];

    rle[i]='\0';

    return rle;
}
