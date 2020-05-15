/**
 * Title   : Stock buy and sell
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findMaxProfit(int price[], int n) {

    if (n == 1)
        return;

    int flag = 0;
    for (int i = 0; i < n - 1; ) {

        while (i < n - 1 && (price[i + 1] <= price[i]))
            i++;

        if (i == (n - 1)) {
            if (flag == 0)
                cout << "No Profit";
            break;
        }

        ++flag;
        int buy = i++;

        while ((i < n) && price[i] > price[i - 1])
            i++;

        int sell = i - 1;

        cout << "(" << buy << " " << sell << ") ";
    }
    cout << '\n';
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
        findMaxProfit(arr, n);
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
