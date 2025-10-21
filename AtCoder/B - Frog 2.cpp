#include <bits/stdc++.h>
using namespace std;
int stone[100100];
int dp[100100];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    dp[0] = 0;
    for (int i = 0;i < n;i++) {
        int nn;
        cin >> nn;
        stone[i] = nn;
        if (i == 0) continue;
        int lowest = INT_MAX;
        for (int x = 1;x <= k;x++) {
            if (i - x >= 0) {
                lowest = min(dp[i-x] + abs(stone[i-x] - stone[i]), lowest); 
            }

        }

        dp[i] = lowest;
        
    }
    cout << dp[n-1];

}