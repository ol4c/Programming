#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
int main () {
    int n,k;
    string s;
    cin >> n >> k >> s;
    int mx = INT_MIN;
    vector<string> ans;
    
    for (int i = 0;i <= n-k;i++) {
        string tar = s.substr(i,k);
        mp[tar]++;

        if (mp[tar] > mx) {
            mx = mp[tar];
            ans.clear();
            ans.push_back(tar);
        } else if (mp[tar] == mx) {
            ans.push_back(tar);
        }
    }
    sort(ans.begin(),ans.end());
    cout << mx << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }

}