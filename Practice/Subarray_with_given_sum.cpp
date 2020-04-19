/**
 * Title   : Subarray with given sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
 **/

#include <iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
    int curr_sum = arr[0], start = 0, i;

    for (i = 1; i <= n; i++)
    {
        while (curr_sum > sum && start < i - 1)
        {
            curr_sum -= arr[start];
            ++start;
        }

        if (curr_sum == sum)
        {
            cout << start+1 << " " << i << '\n';
            return 1;
        }
        if (i < n)
            curr_sum += arr[i];
    }
    cout << "-1" << '\n';
    return 0;
}

int main()
{
    int T;
    cin>>T;
    while(T--) {

    int N,S;
    cin>>N>>S;
    int arr[N];
    for(int i=0;i<N;i++)
        cin >> arr[i];
    subArraySum(arr, N, S);

    }
    return 0;
}
