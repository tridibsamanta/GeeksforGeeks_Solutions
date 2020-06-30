/**
 * Title   : Disjoint set (Union-Find)
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}// } Driver Code Ends


/*Complete the functions below*/
int find(int a[],int x)
{
    if (a[x] != x) {
        a[x] = find(a, a[x]);
    }
    return a[x];
}
void unionSet(int a[],int x,int z)
{
    int x_rep = find(a, x);
    int z_rep = find(a, z);

    a[x_rep] = z_rep;
}
