#include <bits/stdc++.h>
using namespace std;
int stone[100100];
int dp[100100];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> stone[i];
        if (i == 0) {
            continue;
        } else if (i == 1) {
            dp[i] = abs(stone[i] - stone[i-1]);
        } else {
            dp[i] = min(dp[i-1] + abs(stone[i] - stone[i-1]),dp[i-2] + abs(stone[i] - stone[i-2]));
        }
    }

    cout << dp[n-1];


}