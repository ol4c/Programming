#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(int n) {
    vector<vector<int>> rs;
    rs.push_back({1});
    //rs.push_back(vector<int>(1,1));
    
    for (int i = 1;i < n;i++) {
        vector<int> temp;
        temp.push_back(1);

        for (int j = 1;j < i;j++) {
            temp.push_back(rs[i-1][j-1] + rs[i-1][j]);
        }

        temp.push_back(1);
        rs.push_back(temp);
    }

    //for (auto x : rs) {
      //  for (auto y : x) {
        //    cout << y << " ";
        //}
        //cout << endl;
    //}
    return rs;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);

}