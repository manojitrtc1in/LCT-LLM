#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

vector<int> adj[100005];
bool mulpath[100005];
int dist[100005];
int notmemo[100][100];
int memo[100][100];
char c[100];
int k, x, ans1, ans2;

void bfs(int s) {
    fill(dist, dist + 100005, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                mulpath[v] = true;
            }
        }
    }
}

int changes(int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (notmemo[i][j] != -1) {
        return notmemo[i][j];
    }
    if (c[i] != c[j]) {
        notmemo[i][j] = 1 + changes(i + 1, j - 1);
    } else {
        notmemo[i][j] = changes(i + 1, j - 1);
    }
    return notmemo[i][j];
}

int dp(int i, int count) {
    if (count > k) {
        return INT_MAX;
    }
    if (i >= strlen(c)) {
        return 0;
    }
    if (memo[i][count] != -1) {
        return memo[i][count];
    }
    int ans = INT_MAX;
    for (int j = i; j < strlen(c); j++) {
        ans = min(ans, dp(j + 1, count + 1) + changes(i, j));
    }
    return memo[i][count] = ans;
}

void trace(int i, int count) {
    if (i >= strlen(c)) {
        return;
    }
    if (count > k) {
        return;
    }
    int ans = dp(i, count);
    for (int j = i; j < strlen(c); j++) {
        if (dp(j + 1, count + 1) + changes(i, j) == ans) {
            int end = j;
            int chaos = 0;
            for (int idx = i; idx <= j && end >= 0; idx++) {
                cout << c[idx];
                c[end] = c[idx];
                end--;
                chaos = idx;
            }
            if (chaos < strlen(c) - 1) {
                cout << "+";
            }
            trace(j + 1, count + 1);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[v - 1].push_back(u - 1);
    }
    cin >> k;
    int p[k];
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
    }
    bfs(p[k - 1]);
    int min = 0, max = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i + 1]] + 1 == dist[p[i]]) {
            if (mulpath[p[i]]) {
                max++;
            }
        } else {
            min++;
            max++;
        }
    }
    cout << min << " " << max << "\n";
    return 0;
}
