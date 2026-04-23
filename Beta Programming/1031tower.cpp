#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> li;
vector<int> dist(10005, -1);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k,m,n;
    cin >> k >> m >> n;
    for (int i = 1;i <= m+1;i++) {
        li.push_back({});
    }
    for (int i = 1;i <= n;i++) {
        int a,b;
        cin >> a >> b;
        li[a].push_back(b);
        
    }
    dist[1] = 0;
    queue<int> qu;
    qu.push(1);
    int hi = 1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        if (dist[u] <= k) {
            hi = max(hi,u);
        } 

        if (dist[u] > k) continue;

        for (int i : li[u]) {
            if (dist[i] == -1) {
                dist[i] = dist[u]+ 1;
                qu.push(i);
            }
        }
    }
    
    cout << hi;
}