#include <bits/stdc++.h>

using namespace std;;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sa = 0;
    int sb = 0;
    int sc = 0;
    int sd = 0;
    int se = 0;
    for (int i = 1;i <= n;i++) {
        int a,b,c,d,e;
        cin >> a>>b>>c>>d>>e;

        sa+= a*8;
        sb+= b*6;
        sc+= c*4;
        sd+= d*2;
        se+= e*1;
    }
    cout << ceil((sa+sb+sc+sd+se)/8.0);
}