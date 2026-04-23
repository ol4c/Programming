#include <bits/stdc++.h>
using namespace std;
// S = free, P = Water, T = Tree
char mp[100][100];
int dp[100][100];
bool vs[100][100];
vector<pair<int,int>> co;
int mx = 0;   
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin >> a >> b;
    for (int i = 1;i <= b;i++) {
        for (int j = 1;j <= a;j++) {
            char in;
            cin >> in;
            mp[i][j] = in;
            if (in == 'S' || in == 'P') {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
            }
            if (in == 'T') {
                dp[i][j] = 0;
            }

            if (dp[i][j] > mx) {
                mx = dp[i][j];
                co.clear();
                co.push_back({i,j});
            } else if (dp[i][j] == mx) {
                co.push_back({i,j});
            }
        }
    }
    
    int dx[] = {-1,0,0,1};
    int dy[] = {0,1,-1,0};
    int mn = INT_MAX;
    for (auto x : co) {
        memset(vs,0,sizeof(vs));
        int u,v;
        int cnt = 0;
        u = x.first - mx + 1;
        v = x.second - mx + 1;

        for (int i = u;i <= x.first;i++) {
            for (int j = v;j <= x.second;j++) {
                if (mp[i][j] == 'P') {
                    if (vs[i][j]) continue;
                    vs[i][j] = 1;
                    // bfs
                    queue<pair<int,int>> q;
                    q.push({i,j}); 
                    cnt++;
                    while (!q.empty()) {
                        auto k = q.front();
                        q.pop();
                        int ki = k.first;
                        int kj = k.second;

                        for (int w = 0;w < 4;w++) {
                            if (ki+dx[w] < 1 || ki+dx[w] > b || kj+dy[w] < 1 || kj+dy[w] > a) continue;
                            if (mp[ki+dx[w]][kj+dy[w]] == 'P' && vs[ki+dx[w]][kj+dy[w]] == 0) {
                                q.push({ki+dx[w],kj+dy[w]});
                                vs[ki+dx[w]][kj+dy[w]] = 1;
                            }
                        }
                    }
                } 

            }
        }

        mn = min(cnt,mn);
    }

    cout << mx*mx << " " << mn;




}