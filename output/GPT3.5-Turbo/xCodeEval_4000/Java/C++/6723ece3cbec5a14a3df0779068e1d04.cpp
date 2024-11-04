#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[100000];
int dist[100000];
bool mulpath[100000];

void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if (dist[v] == dist[u] + 1) {
                mulpath[v] = true;
            }
        }
    }
}

int main() {
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
    int min = 0;
    int max = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i + 1]] + 1 == dist[p[i]]) {
            if (mulpath[p[i]]) {
                max++;
            }
        }
        else {
            min++;
            max++;
        }
    }
    cout << min << " " << max << endl;

    return 0;
}
