/**
 * Title   : String Ignorance
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/string-ignorance/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while (t--) {

        string str;
        getline(cin, str);

        string res;
        bool toggle[27];
        memset(toggle, false, sizeof(toggle));

        for (int i = 0; str[i]; ++i) {

            if (str[i] >= 'A' && str[i] <= 'Z') {
                if (!toggle[tolower(str[i])-'a']) {
                    res += toupper(str[i]);
                    toggle[tolower(str[i])-'a'] = true;
                }
                else
                    toggle[tolower(str[i])-'a'] = false;
            }
            else if (str[i] >= 'a' && str[i] <= 'z') {
                if (!toggle[str[i]-'a']) {
                    res += str[i];
                    toggle[str[i]-'a'] = true;
                }
                else
                    toggle[str[i]-'a'] = false;
            }
            else {
                if (!toggle[26]) {
                    res += str[i];
                    toggle[26] = true;
                }
                else
                    toggle[26] = false;
            }
        }

        cout << res << '\n';

    }
    return 0;
}
