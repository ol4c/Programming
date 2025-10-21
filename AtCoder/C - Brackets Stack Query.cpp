#include <bits/stdc++.h>
using namespace std;
vector<int> a = {0}; // bal
vector<int> b = {0}; // min
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int cc;
        cin >> cc;
        if (cc == 1) {
            char k;
            cin >> k;
            if (k == '(') {
                a.push_back(a.back()+1);
                b.push_back(min(b.back(), a.back()));
            } else {
                a.push_back(a.back()-1);
                b.push_back(min(b.back(), a.back()));
            }
        } else {
            a.pop_back();
            b.pop_back();
        }

        if (a.back() == 0 && b.back() == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }
}