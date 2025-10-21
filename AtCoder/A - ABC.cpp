#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int sz = s.length();

    for (int i = 0;i < sz;i++) {
        if (i != ((sz+1) / 2) - 1) cout << s[i];
    }
}