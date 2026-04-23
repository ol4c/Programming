#include <bits/stdc++.h>

using namespace std;

struct Job {
    int s,f,w;

    bool operator<(const Job&o) {
        return f < o.f;
    }
};
int p[100005];
int opt[100005];
int main () {
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
    for (int i = 0;i < n;i++) {
        Job u = jobs[i];
        int start_u = u.s;

        auto it = upper_bound(jobs.begin(),jobs.begin()+i,start_u,
        [](int start_u, const Job&o) {
            return start_u < o.f;
        }
        );

        if (it == jobs.begin()) {
            p[i] = -1;
        } else {
            p[i] = distance(jobs.begin(),prev(it));
        }

    }

    for (int i = 0;i < n;i++) {
        int val;
        if (p[i] == -1) val = 0;
        else val = opt[p[i]];
        int val2;
        if (i == 0) val2 = 0;
        else val2 = opt[i-1];
        opt[i] = max(jobs[i].w + val, val2);
    }

    cout << opt[n-1];

}