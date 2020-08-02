/**
 * Title   : Design a tiny URL or URL shortener
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener/0
 **/

#include<bits/stdc++.h>
using namespace std;

string convertIdToTinyURL(int id) {

    char mp[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string tinyURL;

    while (id) {

        tinyURL += mp[id%62];
        id /= 62;
    }

    reverse(tinyURL.begin(), tinyURL.end());

    return tinyURL;
}

int convertTinyURLToId(string tinyURL) {

    int id = 0;

    for (int i = 0; i < tinyURL.length(); ++i) {

        if (tinyURL[i] >= 'a' && tinyURL[i] <= 'z')
            id = (id * 62) + tinyURL[i] - 'a';

        if (tinyURL[i] >= 'A' && tinyURL[i] <= 'Z')
            id = (id * 62) + tinyURL[i] - 'A' + 26;

        if (tinyURL[i] >= '0' && tinyURL[i] <= '9')
            id = (id * 62) + tinyURL[i] - '0' + 52;
    }

    return id;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int db_id;
        cin >> db_id;

        string tinyURL;
        tinyURL = convertIdToTinyURL(db_id);

        int getID;
        getID = convertTinyURLToId(tinyURL);

        cout << tinyURL << '\n' << getID << '\n';

    }

	return 0;
}
