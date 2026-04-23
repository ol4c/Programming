#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> li(1005);
bool vs[1005];
bool sol(int n) {
    if (vs[n]) return 1;
    vs[n] = 1;
    for (int i : li[n]) {
        if (sol(i)) return 1;
    } 
    return 0;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1;i <= n;i++) {
        int k,a;
        cin >> k;
        while (k--) {
            int t;
            cin >> t;
            li[i].push_back(t);
        }
    }

    for (int i = 1;i <= n;i++) {
        memset(vs,0,sizeof(vs));
        if (sol(i)) cout << "YES\n";
        else cout << "NO\n";
    }
    
}