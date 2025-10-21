#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string one, two;
    cin >> one >> two;

    int sz_one = one.length();
    int sz_two = two.length();
    int max_count = INT_MIN;
    string ans;
    for (int i = 0;i < sz_one;i++) {
        char check = one[i];
        for (int j = 0;j < sz_two;j++) {
            if (check == two[j]) {
                int ix = i;
                int jx = j;
                int cnt = 0;
                while (one[ix] == two[jx]) {
                    if (ix >= sz_one || jx >= sz_two) break;
                    cnt++;
                    ix++;
                    jx++;
                }
                if (cnt > max_count) {
                    max_count = cnt;
                    ans = one.substr(i,cnt);
                }
            }
        }    
    }
    cout << ans;
}