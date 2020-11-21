/**
 * Title   : Boolean Parenthesization
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
 **/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

int booleanParenthesization(string str, int i, int j, int isTrue) {

    if (i > j)
        return false;
    if (i ==j) {
        if (isTrue == 1)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {

        int leftT, leftF, rightT, rightF;

        if (dp[i][k - 1][1] != -1)
            leftT = dp[i][k - 1][1];
        else
            leftT = booleanParenthesization(str, i, k - 1, 1);

        if (dp[i][k - 1][0] != -1)
            leftF = dp[i][k - 1][0];
        else
            leftF = booleanParenthesization(str, i, k - 1, 0);

        if (dp[k + 1][j][1] != -1)
            rightT = dp[k + 1][j][1];
        else
            rightT = booleanParenthesization(str, k + 1, j, 1);

        if (dp[k + 1][j][0] != -1)
            rightF = dp[k + 1][j][0];
        else
            rightF = booleanParenthesization(str, k + 1, j, 0);

        if (str[k] == '&') {
            if (isTrue == true)
                ans += leftT * rightT;
            else
                ans += leftT * rightF + leftF * rightT + leftF * rightF;
        }
        else if (str[k] == '|') {
            if (isTrue == true)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans += leftF * rightF;
        }
        else if (str[k] == '^') {
            if (isTrue == true)
                ans += leftT * rightF + leftF * rightT;
            else
                ans += leftT * rightT + leftF * rightF;
        }
    }

    return dp[i][j][isTrue] = ans % 1003;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        cin.ignore();

        string str;
        cin >> str;

        memset(dp, -1, sizeof(dp));

        int count = booleanParenthesization(str, 0, n - 1, 1);
        cout << count << '\n';

    }

    return 0;
}
