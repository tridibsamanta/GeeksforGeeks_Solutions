/**
 * Title   : Inversion of array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-sort/1
 **/

// { Driver Code Starts
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     int len1 = m - l + 1;
     int len2 = r - m;

     int L[len1], R[len2];

     for (int i = 0; i < len1; ++i)
        L[i] = arr[i + l];
     for (int i = 0; i < len2; ++i)
        R[i] = arr[i + m + 1];

     int i = 0, j = 0, k = l;

     while (i < len1 && j < len2) {

         if (L[i] <= R[j])
            arr[k++] = L[i++];
         else
            arr[k++] = R[j++];
     }

     while (i < len1)
        arr[k++] = L[i++];
     while (j < len2)
        arr[k++] = R[j++];
}
