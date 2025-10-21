#include <bits/stdc++.h>
using namespace std;

int dp[10000][10000];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string one, two;
    cin >> one >> two;

    int sz_one = one.length();
    int sz_two = two.length();
    int max_count = INT_MIN;
    int end_pos;
    string ans;
    for (int i = 1;i <= sz_one;i++) {
        for (int j = 1;j <= sz_two;j++) {
            if (one[i-1] == two[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_count) {
                    max_count = dp[i][j];
                    end_pos = i-1;
                    
                }
            }
        }    
    }
    cout << one.substr(end_pos-max_count+1,max_count);
}