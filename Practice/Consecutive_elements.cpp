/**
 * Title   : Consecutive elements
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/consecutive-elements/0
 **/

#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char str[]) {
    int len = strlen(str);
    if (len < 2)
        return;
    int j = 0;
    for(int i = 1; i < len; ++i) {
        if (str[j] != str[i])
            str[++j] = str[i];
    }
    str[++j] = '\0';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char str[100];
        cin >> str;
        removeDuplicates(str);
        cout << str << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
