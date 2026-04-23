#include <bits/stdc++.h>
using namespace std;

int dp[1100][1100];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int w;
    cin >> w;
    
    vector<int> val;
    vector<int> wt;

    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        val.push_back(k);
    }

    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        wt.push_back(k);
    }


    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= w;j++) {
            int vl;
            if (j - wt[i-1] < 0) {   
                vl = -9999; 
            } else {
                vl = dp[i-1][j-wt[i-1]];
            }
            dp[i][j] = max(dp[i-1][j], vl + val[i-1]);
        }
    }

    cout << dp[n][w];

}