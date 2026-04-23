#include <bits/stdc++.h>
using namespace std;
int table[100005];
int val[100005];

int findroot(int a) {
    if (table[a] == a) return a;
    return table[a] = findroot(table[a]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        table[i] = i;
        cin >> val[i];
    }
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        int rtx = findroot(x);
        int rty = findroot(y);
        if (rtx == rty) {
            cout << -1 << "\n";
            continue;
        }
        if (val[rtx] > val[rty]) {
            table[rty] = rtx;
            val[rtx] += val[rty] / 2;
            val[rty] = -1;
            cout << rtx << "\n";
        } else if (val[rtx] < val[rty]) {
            table[rtx] = rty;
            val[rty] += val[rtx] / 2;
            val[rtx] = -1;
            cout << rty << "\n";
        } else {
            if (rtx < rty) {
                table[rty] = rtx;
                val[rtx] += val[rty] / 2;
                val[rty] = -1;
                cout << rtx << "\n";
            } else {
                table[rtx] = rty;
                val[rty] += val[rtx] / 2;
                val[rtx] = -1;
                cout << rty << "\n";
            }
        }
    }
}