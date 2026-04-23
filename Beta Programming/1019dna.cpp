#include <bits/stdc++.h>
using namespace std;
int dp[250][250];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    a = "p" + a;
    b = "n" + b;
    int sza = a.length();
    int szb = b.length();
    int mx = INT_MIN;
    int ei = -1;
    int ej = -1;
    for (int i = 1;i < sza;i++) {
        for (int j = 1;j < szb;j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > mx) {
                    mx = max(mx,dp[i][j]);
                    ei = i;
                    ej = j;
                }
                
            }
        }
    }

    for (int i = ei-mx+1;i <= ei;i++) {
        cout << a[i];
    }
}