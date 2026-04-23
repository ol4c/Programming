#include <bits/stdc++.h>
using namespace std;
// 'a' - 96 = 1
vector<vector<int>> li(29);
vector<double> we[35][35] = {};
bool vs[1000];
double med(vector<double> vd) {
    int sz = vd.size();
    sort(vd.begin(),vd.end());
    if (sz == 0) return 0;
    if (sz == 1) return vd[0];
    if (sz == 2) return (vd[0] + vd[1]) / 2.0;
    if (sz % 2 == 0) {
        double a = vd[floor((sz+1)/2.0) - 1];
        double b = vd[ceil((sz+1)/2.0) - 1];
        return (a+b) / 2.0;
    } else {
        return vd[((sz+1)/2.0) - 1];
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    while (n--) {
        char s, e;
        double w;
        cin >> s >> e >> w;
        int si = s - 96;
        int ei = e - 96;

        if (s == 'X') {
            si = 27;
        }
        if (s == 'Y') {
            si = 28;
        }
        if (e == 'X') {
            ei = 27;
        }
        if (e == 'Y') {
            ei = 28;
        }

        we[si][ei].push_back(w);
        we[ei][si].push_back(w);
        li[si].push_back(ei);
        li[ei].push_back(si);
    }
    double cost = 0;
    queue<int> q;
    q.push(27);
    char last;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vs[u] = 1;
        map<int,int> mp;
        char ch;
        if (u == 27) ch = 'X';
        else if (u == 28) ch = 'Y';
        else ch = u+96;
        for (int v : li[u]) {
            char cv;
            if (vs[v]) continue;
            if (mp[v]) continue;

            if (v == 27) cv = 'X';
            else if (v == 28) cv = 'Y';
            else cv = v+96;
            last = cv;
            q.push(v);
            mp[v] = 1;
        }
    }
    if (last != 'Y') cout << "broken";
    else {
        memset(vs,0,sizeof(vs));
        q.push(27);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vs[u] = 1;
            map<int,int> mp;
            char ch;
            if (u == 27) ch = 'X';
            else if (u == 28) ch = 'Y';
            else ch = u+96;
            for (int v : li[u]) {
                char cv;
                if (vs[v]) continue;
                if (mp[v]) continue;

                if (v == 27) cv = 'X';
                else if (v == 28) cv = 'Y';
                else cv = v+96;

                double medi = med(we[u][v]);
                cout << fixed << setprecision(1) << ch << " " << cv << " " << medi << "\n";
                cost += medi;
                q.push(v);
                mp[v] = 1;
            }
        }
        cout << cost;
    }
    
}