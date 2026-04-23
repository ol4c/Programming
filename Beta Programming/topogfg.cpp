#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V;
    cin >> V;
    vector<vector<int>> edges;

    int E;
    cin >> E;
    for (int i = 1;i <= E;i++) {
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    E = edges.size();

    vector<vector<int>> n(V+5);
    vector<int> ind(V+5);
    for (int i = 0;i < E;i++) {
        n[edges[i][0]].push_back(edges[i][1]);
        ind[edges[i][1]]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0;i < V;i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int id = q.top();
        q.pop();
        order.push_back(id);
        for (auto i : n[id]) {
            ind[i]--;
            if (ind[i] == 0) {
                q.push(i);
            }
        }
    }

    if (order.size() != V) cout << "false";
    else cout << "true";
}