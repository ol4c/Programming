#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s,a,b,x;
    cin >> s >> a >> b >> x;
    int cnt = 0;
    int steps = 0;
    bool check = 0;
    for (int i = 1;i <= x;i++) {
        
        if (check ==0) {
            cnt++;
            steps+=s;
            if (cnt == a) {
                cnt = 0;
                check = 1;
            }
        } else {
            cnt++;
            if (cnt == b) {
                cnt = 0;
                check = 0;
            }
        }
    }
    cout << steps;


}