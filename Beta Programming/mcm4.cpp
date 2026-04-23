#include <bits/stdc++.h>

using namespace std;
int m[500][500];
int s[500][500];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    for (int d = 1;d <= n-1;d++) {
        for (int i = 1;i <= n - d;i++) {
            int j = i+d;
            int mn = INT_MAX;
            for (int k = i;k <= j-1;k++) {
                int q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (q < mn) {
                    s[i][j] = k;
                    mn = q;
                }
            }
            m[i][j] = mn;
        }
    }

    cout << m[1][n-1];
}