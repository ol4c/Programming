#include <bits/stdc++.h>

using namespace std;
int dp[1000][1000];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin >> a >> b;
    
    int sz_a = a.length();
    int sz_b = b.length();

    int mx = INT_MIN;
    int end_pos;
    for (int i = 1;i <= sz_a;i++) {
        for (int j = 1;j <= sz_b;j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > mx) {
                    mx = dp[i][j];
                    end_pos = i-1;
                } 
            }
        }
    }
    cout << a.substr(end_pos - mx + 1,mx);
}