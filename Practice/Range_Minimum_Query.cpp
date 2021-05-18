/**
 * Title   : Range Minimum Query
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/range-minimum-query/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;

            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

void constructSTUtil(int *seg, int idx, int l, int r, int arr[]) {

    if (l == r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    constructSTUtil(seg, 2 * idx + 1, l, mid, arr);
    constructSTUtil(seg, 2 * idx + 2, mid + 1, r, arr);

    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int *constructST(int arr[],int n) {

    int *seg = new int[(4 * n) + 5];

    constructSTUtil(seg, 0, 0, n-1, arr);

    return seg;
}


int RMQUtil(int seg[], int idx, int curr_l, int curr_r, int l, int r) {

    if (curr_l > r || curr_r < l)
        return INT_MAX;

    if (curr_l >= l && curr_r <= r)
        return seg[idx];

    int mid = (curr_l + curr_r) / 2;

    return min(RMQUtil(seg, 2 * idx + 1, curr_l, mid, l, r),
           RMQUtil(seg, 2 * idx + 2, mid + 1, curr_r, l, r));
}

int RMQ(int st[] , int n, int a, int b) {
    return RMQUtil(st, 0, 0, n - 1, a, b);
}
