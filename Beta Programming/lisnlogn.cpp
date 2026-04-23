#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr;
    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    vector<int> ans;

    for (auto i : arr) {
        auto it = lower_bound(ans.begin(),ans.end(),i);
        if (it == ans.end()) {
            ans.push_back(i);
        } else {
            *it = i;
        }

    }

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
}