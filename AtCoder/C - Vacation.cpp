#include <bits/stdc++.h>
using namespace std;

int table[100100][5];
int n;
int mx = INT_MIN;
void play(int choice, int sum, int old, int same, int row) {
    if (row > n) {
        mx = max(mx, sum);
        return;
    }
    if (old == choice) same++;
    else same = 1;
    if (same >= 2) {
        return;
    }
    sum += table[row][choice];
    play(1,sum,choice,same,row+1);
    play(2,sum,choice,same,row+1);
    play(3,sum,choice,same,row+1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;
    for (int i = 1;i <=n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        table[i][1] = a;
        table[i][2] = b;
        table[i][3] = c;
    }

    play(1,0,-1,1,1);
    play(2,0,-1,1,1);
    play(3,0,-1,1,1); 


    cout << mx;
}