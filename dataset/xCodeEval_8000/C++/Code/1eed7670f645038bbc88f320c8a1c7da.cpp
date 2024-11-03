#define ONLINE_JUDGE 0

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, m, k, j = 0, s, joja = 0;
bool vis[200000];
vector<int> g[200000], p;

void dfs(const int &v) {
    vis[v] = true;
    p.push_back(v);
    for(const int &to : g[v])
        if(!vis[to]) {
            dfs(to);
            p.push_back(v);
        }
}

void solve() {
    scanf("%d %d %d", &n, &m, &k);
    if(n == 1) {
        for(int i = 0;i < k;i++)
            printf("1 1\n");
        return;
    }
    s = (2 * n) / k + ((2 * n) % k != 0);
    assert(s > 1);
    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == y) continue;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    assert(n > 1); 

    if(n > 1) p.pop_back(); 





    for(int i = 0;i < k;i++) {
        printf("%d", s);
        for(int r = 0;r < s;r++, j = (j + 1) % p.size(), joja++) {
            printf(" %d", p[j] + 1);


        }
        printf("\n");
    }
    assert(joja >= p.size());
}

int main() {
    srand(time(nullptr));
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
