#include <bits/stdc++.h>
using namespace std;
struct Job{
    int s,f,w;
    bool operator<(const Job&o) {
        return f < o.f;
    }
};
int p[100100];
int opt[100100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<Job> jobs;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int s,f,w;

        cin >> s >> f >> w;
        jobs.push_back({s,f,w});
    }

    sort(jobs.begin(),jobs.end());

    for (int i = 1;i <= n;i++) {
        Job u = jobs[i-1];
        int su = u.s;

        auto it = upper_bound(jobs.begin(),jobs.begin() + i - 1,su,
        [](int su, const Job&o) {
            return su < o.f;
        }
        );

        if (it == jobs.begin()) {
            p[i] = 0;
        } else {
            p[i] = distance(jobs.begin(), prev(it)) + 1;
        }
    }

    for (int i = 1;i <= n;i++) {
        opt[i] = max(jobs[i-1].w + opt[p[i]], opt[i-1]);
    }

    cout << opt[n];
}