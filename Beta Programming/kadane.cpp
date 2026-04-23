#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    while (n--) {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    int mx = INT_MIN;;
    int sum = 0;
    for (int i : arr) {
        sum += i;
        mx = max(sum,mx);
        if (sum < 0) sum = 0;
    }
    cout << mx;
}