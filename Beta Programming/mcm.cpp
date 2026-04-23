#include <bits/stdc++.h>

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m[105][105];
    int s[105][105];
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    for (int d = 1;d < n-1;d++) {
        for (int i = 1;i < n-d;i++) {
            int j = i+d;
            int mn = INT_MAX;
            for (int k = i; k <= j - 1;k++) {
                int q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j]; 
                if (q < mn) {
                    mn = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = mn;
        }
    }

    cout << m[1][n-1];
}

