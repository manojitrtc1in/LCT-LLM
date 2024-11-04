#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int MOD = 1000000007;
vector<int> adj[100005];
bool mulpath[100005];
int dist[100005];
long long fib[100005];
long long comb[100005][100005];
char c[100005];
int notmemo[1005][1005];
int memo[1005][1005];

void bfs(int s) {
    fill(dist, dist + 100005, 1e9);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == 1e9) {
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
        return 1e9;
    }
    if (i >= c.length()) {
        return 0;
    }
    if (memo[i][count] != -1) {
        return memo[i][count];
    }
    int ans = 1e9;
    for (int j = i; j < c.length(); j++) {
        ans = min(ans, dp(j + 1, count + 1) + changes(i, j));
    }
    return memo[i][count] = ans;
}

void trace(int i, int count) {
    if (i >= c.length()) {
        return;
    }
    if (count > k) {
        return;
    }
    int ans = dp(i, count);
    for (int j = i; j < c.length(); j++) {
        if (dp(j + 1, count + 1) + changes(i, j) == ans) {
            int end = j;
            int chaos = 0;
            for (int idx = i; idx <= j && end >= 0; idx++) {
                cout << c[idx];
                c[end] = c[idx];
                end--;
                chaos = idx;
            }
            if (chaos < c.length() - 1) {
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
    
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
    }
    
    bfs(p[k - 1]);
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i + 1]] + 1 == dist[p[i]]) {
            if (mulpath[p[i]]) {
                maxCount++;
            }
        } else {
            minCount++;
            maxCount++;
        }
    }
    
    cout << minCount << " " << maxCount << endl;
    
    return 0;
}
