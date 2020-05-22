/**
 * Title   : Circular tour
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/circular-tour/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump arr[],int n)
{
   int start = 0, stop = 1;

    int currPetrol = arr[start].petrol - arr[start].distance;

    while (stop != start || currPetrol < 0) {

        while (start != stop && currPetrol < 0) {

            currPetrol -= (arr[start].petrol - arr[start].distance);
            start = (start + 1) % n;

            if (start == 0)
                return -1;
        }

        currPetrol += (arr[stop].petrol - arr[stop].distance);
        stop = (stop + 1) % n;
    }
    return start;
}
