#include <bits/stdc++.h>

using namespace std;

vector<int> A = {0};
vector<int> B = {0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            char in;
            cin >> in;
            if (in == '(') {
                A.push_back(A.back()+1);
            } else {
                A.push_back(A.back()-1);
            }
            B.push_back(min(A.back(),B.back()));
        } else {
            A.pop_back();
            B.pop_back();
        }

        if (A.back() == 0 && B.back() == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}