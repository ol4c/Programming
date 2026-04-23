#include <bits/stdc++.h>

using namespace std;
int dp[1100][1100];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int W;
    cin >> W; 

    vector<int> val; vector<int> wt;
    
    for (int i = 1;i <= W-1;i++) {
        int k;
        cin >> k;
        val.push_back(k);
    }
    for (int i = 1;i <= W-1;i++) {
        int k;
        cin >> k;
        wt.push_back(k);
    }
    int n = val.size();
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= W;j++) {
            int vv;
            if (j - wt[i-1] < 0) vv = 0;
            else vv = dp[i-1][j - wt[i-1]] + val[i-1];
            dp[i][j] = max(dp[i-1][j], vv);
        }
    }
    cout << dp[n][W];
}