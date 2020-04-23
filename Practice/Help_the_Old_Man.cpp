/**
 * Title   : Help the Old Man
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/help-the-old-man/0
 **/

#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int disk, int move, int &count, int source, int destination, int auxiliary) {
    if (disk == 1) {
        ++count;
        if (count == move)
                cout << source << " " << destination << "\n";
        return;
    }
    TowerOfHanoi(disk - 1, move, count, source, auxiliary, destination);
    ++count;
    if (count == move)
            cout << source << " " << destination << "\n";
    TowerOfHanoi(disk - 1, move, count, auxiliary, destination, source);
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
    int N, m, count = 0;
    cin >> N >> m;
    TowerOfHanoi(N, m, count, 1, 3, 2);
    }
    return 0;
}
