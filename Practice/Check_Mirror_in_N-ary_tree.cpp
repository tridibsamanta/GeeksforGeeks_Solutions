/**
 * Title   : Check Mirror in N-ary tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool checkMirror(int n, vector<stack<int> > t1, vector<queue<int> > t2) {

    for (int i = 1; i <= n; ++i) {

        while (!t1[i].empty() && !t2[i].empty()) {

            if (t1[i].top() != t2[i].front())
                return false;

            t1[i].pop();
            t2[i].pop();
        }

        if (!t1[i].empty() || !t2[i].empty())
            return false;
    }

    return true;
}


int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, e;
        cin >> n >> e;

        vector<stack<int> > t1(n + 1);
        vector<queue<int> > t2(n + 1);

        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            t1[u].push(v);
        }

        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            t2[u].push(v);
        }

        if (checkMirror(n, t1, t2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';

    }

    return 0;
}
