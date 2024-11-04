








using namespace std;
int n, m, k, c[100005], vis[100005], num, type[505], dis[505][505];
vector<pair<int, int> > g[100005];

void dfs(int u, int t) {
   if (c[u] == t) {
       num++;
   }
   vis[u] = 1;
   for (int i = 0; i < g[u].size(); i++) {
       pair<int, int> p = g[u][i];
       if (!vis[p.first] && !p.second) {
           dfs(p.first, t);
       }
   }
}

int main() {
    cin >> n >> m >> k;
    int sum = 1;
    int cnt;
    for (int i = 1; i <= k; i++) {
        type[i] = sum;
        cin >> cnt;
        for (int j = sum; j < sum + cnt; j++) {
            c[j] = i;
        }
        sum += cnt;
    }
    type[k + 1] = n + 1;
    int u, v, x;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i != j) {
                dis[i][j] = 999999999;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> x;
        g[u].push_back(make_pair(v, x));
        g[v].push_back(make_pair(u, x));
        if (c[u] != c[v]) {
            dis[c[u]][c[v]] = min(dis[c[u]][c[v]], x);
            dis[c[v]][c[u]] = min(dis[c[u]][c[v]], x);
        }
    }

    for (int i = 1; i <= k; i++) {
        num = 0;
        memset(vis, 0, sizeof vis);
        dfs(type[i], i);
        if (num != type[i + 1] - type[i]) {
            cout << "No" << endl;
            exit(0);
        }
    }


    for (int p = 1; p <= k; p++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (dis[i][j] > dis[i][p] + dis[p][j]) {
                    dis[i][j] = dis[i][p] + dis[p][j];
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            dis[i][j] = dis[i][j] == 999999999? -1 : dis[i][j];
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}























































