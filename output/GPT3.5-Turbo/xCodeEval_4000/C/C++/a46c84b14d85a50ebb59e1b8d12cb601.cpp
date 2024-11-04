#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Dinic {
    int n;
    vector<vector<int>> to;
    vector<vector<ll>> cap;
    vector<vector<int>> rev;
    vector<int> min_cost;
    vector<int> iter;

    void add(int from, int to, ll cap) {
        rev[from].push_back(to);
        rev[to].push_back(from);
        to[from].push_back(to);
        to[to].push_back(from);
        cap[from].push_back(cap);
        cap[to].push_back(0);
    }

    bool bfs(int s, int t) {
        vector<int> min_cost(n, -1);
        min_cost[s] = 0;
        vector<int> q;
        q.push_back(s);
        int head = 0;
        while (head < q.size() && min_cost[t] == -1) {
            int p = q[head++];
            for (int i = 0; i < to[p].size(); i++) {
                int to = to[p][i];
                if (cap[p][i] > 0 && min_cost[to] == -1) {
                    ll cost = min_cost[p] + 1;
                    min_cost[to] = cost;
                    q.push_back(to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    ll dfs(int idx, int t, ll flow) {
        if (idx == t) return flow;
        for (int& i = iter[idx]; i < cap[idx].size(); i++) {
            ll cap = cap[idx][i];
            int to = to[idx][i];
            if (cap > 0 && min_cost[idx] < min_cost[to]) {
                ll delta = dfs(to, t, min(flow, cap));
                if (delta > 0) {
                    cap -= delta;
                    cap[to][rev[idx][i]] += delta;
                    return delta;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        while (bfs(s, t)) {
            iter.assign(n, 0);
            ll f = 0;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

void solve() {
    ll n;
    ll ans = 0;
    cin >> n;

    ll a[3];
    ll b[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    ll ma = 0;

    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    Dinic d;
    d.n = 8;
    d.to.resize(8);
    d.cap.resize(8);
    d.rev.resize(8);
    d.min_cost.resize(8);
    d.iter.resize(8);

    d.add(6, 0, a[0]);
    d.add(6, 1, a[1]);
    d.add(6, 2, a[2]);

    d.add(0, 3, INF);
    d.add(0, 5, INF);
    d.add(1, 3, INF);
    d.add(1, 4, INF);
    d.add(2, 4, INF);
    d.add(2, 5, INF);

    d.add(3, 7, b[0]);
    d.add(4, 7, b[1]);
    d.add(5, 7, b[2]);

    cout << n - d.max_flow(6, 7) << " " << ma << endl;
}

int main() {
    ll T = 1;

    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
