#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    int a= 0, b= 1, c=1;
    for (int i = 3;i <= n;i++) {
        int next= a+b+c;
        a = b;
        b = c;
        c = next;
    }
    return c;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    cout << solve(n);
}