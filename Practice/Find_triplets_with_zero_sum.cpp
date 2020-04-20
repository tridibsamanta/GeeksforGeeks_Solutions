/**
 * Title   : Find triplets with zero sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int arr[], int n)
{
    /* USING TWO POINTER TECHNIQUE */

    sort(arr, arr + n);

    int l, r;

    for(int i = 0; i < n - 2; ++i) {
        l = i + 1;
        r = n - 1;
        while(l < r) {
            if (arr[i] + arr[l] + arr[r] == 0)
                return true;
            else if (arr[i] + arr[l] + arr[r] < 0)
                ++l;
            else
                --r;
        }
    }
    return false;
}
