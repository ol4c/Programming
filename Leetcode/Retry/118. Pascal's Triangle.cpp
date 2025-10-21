#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int r) {
    vector<vector<int>> result = {{1}};

    for (int i = 2;i <= r;i++) {
        vector<int> temp;
        if (i == 2) {
            temp.push_back(1);
            temp.push_back(1);
            result.push_back(temp);
            continue;
        }

        temp.push_back(1);

        for (int j = 1;j < i - 1;j++) {
            vector<int> k = result.back();
            temp.push_back(k[j] + k[j-1]);
        }

        temp.push_back(1);
        result.push_back(temp);
    }

    return result;

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
}