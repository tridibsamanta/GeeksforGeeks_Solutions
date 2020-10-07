/**
 * Title   : Peak element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/peak-element/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n) {

    int low = 0, high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

            if (mid > 0 && mid < n - 1) {

                if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
                    return mid;
                else if (arr[mid - 1] > arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (mid == 0) {

                if (arr[mid] >= arr[mid + 1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == n - 1) {

                if (arr[n - 1] >= arr[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
    }
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);

		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;

		cout<<f<<endl;

	}

	return 0;
}  // } Driver Code Ends
