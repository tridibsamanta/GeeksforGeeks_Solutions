/**
 * Title   : Stock span problem
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/stock-span-problem/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findSpans(int arr[], int n, int span[]) {
    stack<int> S;
    S.push(0);
    span[0] = 1;
    for (int i = 1; i < n; ++i) {
        while (!S.empty() && arr[i] >= arr[S.top()])
            S.pop();
        if (S.empty())
            span[i] = i + 1;
        else
            span[i] = i - S.top();
        S.push(i);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int S[n];
        findSpans(arr, n, S);
        for (int i = 0; i < n; ++i)
            cout << S[i] << ' ';
        cout << '\n';
    }
    return 0;
}
