#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> data;
    int n, q;
    cin >> n >> q;
    while (n--) {
        int hold;
        cin >> hold;
        data.push_back(hold);
    }

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int c;
            cin >> c;
            rotate(data.begin(),data.begin() + c,data.end());
        } else {
            int l,r;
            cin >> l >> r;
            int sum = 0;
            for (int i = l-1;i < r;i++) {
                sum += data[i];
            }
            cout << sum << "\n";
        }
    }
}