#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    a = "#" + a;
    b = "!" + b;
    int sza = a.length();
    int szb = b.length();

    int mx = 0;
    for (int i = 1;i < sza;i++) {
        for (int j = 1;j < szb;j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

            if (dp[i][j] > mx) {
                mx = dp[i][j];
            }
        }
    }
    string ans = "";
    int i = sza-1;
    int j = szb-1;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            ans += a[i];
            i--;
            j--;
        } else {
            if (dp[i-1][j] > dp[i][j-1]) {
                i -= 1;
            } else {
                j -= 1;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    cout << mx;
}