/**
 * Title   : Heap Sort
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/heap-sort/1
 **/

// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


void heapify(int arr[], int n, int i)  {

    int max = i;

    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < n && arr[lchild] > arr[max])
        max = lchild;

    if (rchild < n && arr[rchild] > arr[max])
        max = rchild;

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void buildHeap(int arr[], int n)  {
    for (int i = (n / 2) - 1; i >= 0; --i)
        heapify(arr, n, i);
}
