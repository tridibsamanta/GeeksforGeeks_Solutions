/**
 * Title   : Power of Four
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/power-of-four/1
 **/

// { Driver Code Starts
#include<iostream>
using namespace std;

int isPowerOfFour(unsigned int n);

/*Driver program to test above function*/
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
if(isPowerOfFour(n))
	cout<<1<<endl;
else
	cout<<0<<endl;
}
//getchar();
}
// } Driver Code Ends


int isPowerOfFour(unsigned int n)
{
  return n > 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA);
}
