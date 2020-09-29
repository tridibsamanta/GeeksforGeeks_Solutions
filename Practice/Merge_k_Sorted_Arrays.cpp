/**
 * Title   : Merge k Sorted Arrays
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k) {

    int *res = new int[k * k];

    if (k == 0)
        return res;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int index[k];
    memset(index, 0, sizeof(index));

    for (int i = 0; i < k; ++i) {
        pq.push(make_pair(arr[i][0], i));
    }

    int resIdx = 0;

    while (!pq.empty()) {

        pair<int, int> top = pq.top();
        pq.pop();

        res[resIdx++] = top.first;

        ++index[top.second];

        if (index[top.second] < k)
            pq.push(make_pair(arr[top.second][index[top.second]], top.second));

    }

    return res;
}
