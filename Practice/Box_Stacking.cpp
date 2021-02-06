/**
 * Title   : Box Stacking
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/box-stacking/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;


 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

} // } Driver Code Ends


/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/

static bool comparator(const vector<int>& a, const vector<int>& b) {
    return (a[1] * a[2]) >= (b[1] * b[2]);
}

int maxHeight(int height[],int width[],int length[],int n) {

    vector<vector<int> > dims(3*n, vector<int>(3));

    // dims[i] = {height, length, width}

    int idx = 0;

    for (int i = 0; i < n; ++i) {

        dims[idx][0] = height[i];
        dims[idx][1] = max(width[i], length[i]);
        dims[idx][2] = min(width[i], length[i]);
        ++idx;

        dims[idx][0] = width[i];
        dims[idx][1] = max(height[i], length[i]);
        dims[idx][2] = min(height[i], length[i]);
        ++idx;

        dims[idx][0] = length[i];
        dims[idx][1] = max(height[i], width[i]);
        dims[idx][2] = min(height[i], width[i]);
        ++idx;
    }

    n *= 3;

    sort(dims.begin(), dims.end(), comparator);

    vector<int> dp(n);

    for (int i = 0; i < n; ++i)
        dp[i] = dims[i][0];

    int maxHt = dp[0];

    for (int i = 1; i < n; ++i) {

        for (int j = 0; j < i; ++j) {

            if (dims[i][1] < dims[j][1] && dims[i][2] < dims[j][2])
                dp[i] = max(dp[i], dp[j] + dims[i][0]);
        }

        maxHt = max(maxHt, dp[i]);
    }

    return maxHt;
}

// T.C. - O(n*n)
// S.C. - O(n)
