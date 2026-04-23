#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n >> x;
    int a;
    int hold;
    while (n--) {
        cin >> a;
        if (x > a) {
            cout << 1 << "\n";
            x = a;
        } else {
            cout << 0 << "\n";
        }
    }
}