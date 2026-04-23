#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> arr;
    int n;
    cin >> n;
    int mx = INT_MIN;
    int sum = 0;

    int bs = 0,be = 0, s = 0;

    for (int i = 0;i < n;i++) {
        int k;
        cin >> k;
        arr.push_back(k);
        sum += k;
        if (sum > mx) {
            mx = sum;
            bs = s;
            be = i;
        }

        if (sum < 0) {
            sum = 0;
            s = i+1;
        }
    }
    if (mx <= 0) {
        cout << "Empty sequence";
        return 0;
    }
    for (int i = bs;i <= be;i++) cout << arr[i] << " ";
    cout << "\n";
    cout << mx;

}