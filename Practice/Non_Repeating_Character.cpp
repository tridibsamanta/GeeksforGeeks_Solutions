/**
 * Title   : Non Repeating Character
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/non-repeating-character/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 256

void getFirstNonRepeatingCharacter(string s, int len) {

    int arr[MAX_SIZE];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; s[i]; ++i) {
        arr[s[i]]++;
    }

    for (int i = 0; s[i]; ++i) {
        if (arr[s[i]] == 1) {
            cout << s[i];
            return;
        }
    }

    cout << -1;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int len;
        cin >> len;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        string s;
        getline(cin, s);

        getFirstNonRepeatingCharacter(s, len);
        cout << '\n';

    }
    return 0;
}
