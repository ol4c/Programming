#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        auto idx = lower_bound(v.begin(),v.end(),x);
        if (idx == v.end()) v.push_back(x);
        else *idx = x;
    }
    cout << v.size();
}