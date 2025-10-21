#include <bits/stdc++.h>
using namespace std;

int split(int i) {
    string s = to_string(i);
    int sum = 0;
    int sz = s.size();
    for (int i = 0;i < sz;i++) {
        sum += s[i] - '0';
    }
    return sum;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> order;
    order.push_back(1);
    order.push_back(1);
    for (int i = 2;i <= n;i++) {
        int total = 0;
        for (int j = 0;j < i;j++) {
            if (order[j] >= 10) {
                total += split(order[j]);
            } else {
                total += order[j];
            }
            
        }
        order.push_back(total);
        
    }
    cout << order[n] << endl;
}