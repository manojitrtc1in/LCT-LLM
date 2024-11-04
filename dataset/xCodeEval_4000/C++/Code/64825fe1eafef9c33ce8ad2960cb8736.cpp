#define ONLINE_JUDGE 0

#include <bits/stdc++.h>

#define x first
#define y second
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

namespace my {
    ii operator+(const ii &a, const ii &b) {return {a.x + b.x, a.y + b.y};}
    ii operator-(const ii &a, const ii &b) {return {a.x - b.x, a.y - b.y};}
    ii operator*(const ii &a, const ii &b) {return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
    ii operator*(const ii &a, const int &b) {return {a.x * b, a.y * b};}
    ii operator/(const ii &a, const int &b) {return {a.x / b, a.y / b};}
    ii conj(const ii &e) {return {e.x, -e.y};};
    ostream& operator<<(ostream &s, const ii &p) {s << '(' << p.x << ", " << p.y << ')';return s;}
}

using namespace my;

int n;
vector<int> g[100000];
int h[100000];
double ans = 0.0;

void dfs(const int &v, const int &p) {
    for(const int &ch : g[v])
        if(ch != p) {
            h[ch] = h[v] + 1;
            dfs(ch, v);
        }
}

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n - 1;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[0] = 1;
    dfs(0, -1);
    for(int i = 0;i < n;i++)
        ans += 1.0 / h[i];
    printf("%.12f", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
