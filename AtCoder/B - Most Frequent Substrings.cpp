#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0;i + k <= n;i++) {
        string target = s.substr(i,k);
        //cout << target << endl;
        mp[target]++;
    }
    int cnt = 0;
    vector<string> eep;
    for (auto i : mp) {
        if (i.second >= 1) {
            if (i.second >= cnt) {
                if (i.second > cnt) {
                    eep.clear();
                }
                cnt = i.second;
                eep.push_back(i.first);
            }  
        }
    }
    cout << cnt << "\n";
    for (auto i : eep) {
        cout << i << " ";
    }
}