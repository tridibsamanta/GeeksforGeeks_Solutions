/**
 * Title   : Print matrix in diagonal pattern
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> matrixDiagonally(int mat[MAX][MAX], int );

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;

        int a[MAX][MAX];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
      vector<int> vec = matrixDiagonally(a,n);
      for(int x : vec){
          cout<<x<<" ";
      }
      cout<<endl;


    }
}// } Driver Code Ends


/*You are required to complete this method */

vector<int> matrixDiagonally(int mat[MAX][MAX], int n)
{
    int r = n, c = n;
    int k;

    for (k = 0; k < c; ++k) {

        if (k % 2 == 0) {

            int row = k, col = 0;

            while (row >= 0) {
                cout << mat[row][col] << ' ';
                --row;
                ++col;
            }
        }
        else {

            int row = 0, col = k;

            while (col >= 0) {
                cout << mat[row][col] << ' ';
                ++row;
                --col;
            }
        }
    }

    for (; k < (r + c - 1); ++k) {

        if (k % 2 == 0) {

            int row = r - 1, col = k % c + 1;

            while (col < c) {
                cout << mat[row][col] << ' ';
                --row;
                ++col;
            }
        }
        else {

            int row = k % r + 1, col = c - 1;

            while (row < r) {
                cout << mat[row][col] << ' ';
                ++row;
                --col;
            }
        }
    }
}
