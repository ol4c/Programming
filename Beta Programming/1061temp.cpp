#include <bits/stdc++.h>
using namespace std;
int n;
int mp[25][25];
int vs[25][25];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int hi = INT_MIN;
void sol(int x,int y, int val,int ov) {
    if (vs[x][y]) return;
    if (val == 100) return;
    if (x <= 0 || y <= 0 || x > n || y > n) {
        return;
    }
    if (val > ov) hi = max(hi,val);
    else return;
    vs[x][y] = 1;
    for (int i = 0;i < 4;i++) {
        sol(x+dx[i],y+dy[i],mp[x+dx[i]][y+dy[i]],val);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;
    int sx,sy;
    cin >> sy >> sx;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> mp[i][j];
        }   
    }
    sol(sx,sy,mp[sx][sy],-1e9);
    cout << hi;

}