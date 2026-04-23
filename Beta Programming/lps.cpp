#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int sz = s.length();
    for (int i = sz - 1;i >= 0;i--) {
        for (int j = i;j < sz;j++) {
            dp[i][i] = 1;
            if (i == j) continue;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }   
    } 
    cout << dp[0][sz-1];
}