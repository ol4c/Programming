#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a;
    cin >> a;
    bool dp[1005][1005];
    memset(dp,0,sizeof(dp));
    int n = a.length();
    int mx = 1;
    int idx = 0;
    bool ch = 0;
    for (int i = 0;i < n;i++) {
        dp[i][i] = 1;
        int j = i+1;
        if (j >= n) continue;

        if (a[i] == a[j] && dp[i][j-1]) {
            if (!ch) {
                ch = 1;
                mx = 2;
                idx = i;
            }
            dp[i][j] = 1;
        }
    }

    for (int d = 2;d < n;d++) {
        for (int i = 0;i < n - 1;i++) {
            int j = i+d;
            if (j >= n) continue;

            if (a[i] == a[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
                if (d+1 > mx) {
                    mx = d+1;
                    idx = i;
                }
            }
        }
    }
    cout << mx << "\n";
    cout << a.substr(idx,mx);

}