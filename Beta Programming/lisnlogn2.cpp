#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        
        auto it = lower_bound(arr.begin(),arr.end(),k);
        if (it == arr.end()) arr.push_back(k);
        else *it = k;
    }

    cout << arr.size();
}