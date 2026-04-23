#include <bits/stdc++.h>
using namespace std;

bool dp[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int sz = s.length(); 
    int mx = 1;
    int st = 0;
    for (int i = 0;i < sz;i++) {
        dp[i][i] = 1;
    }
    bool ch = 0;
    for (int i = 0;i < sz;i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            if (!ch) {
                st = i;
                mx = 2;
                ch = 1;
            }
        }
    }

    for (int l = 3;l <= sz;l++) {
        for (int i = 0;i < sz - l + 1;i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
                if (l > mx) {
                    st = i;
                    mx = l;
                }
            }
        }
    }

    string ans = s.substr(st,mx);
    cout << ans;
}