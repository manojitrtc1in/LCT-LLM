


























































































































































































































































#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 1000009
#define MAXM 900009
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi g[MAXN];
char op[MAXN][6];
int n;
bool out[MAXN], matter[MAXN];

void solve(int u) {
	if (op[u][0] == 'I') return;
	else if (op[u][0] == 'N') {
		solve(g[u][0]);
		out[u] = !out[g[u][0]];
	}
	else if (op[u][0] == 'X') {
		solve(g[u][0]);
		solve(g[u][1]);
		out[u] = out[g[u][0]] != out[g[u][1]];
	}
	else if (op[u][0] == 'A') {
		solve(g[u][0]);
		solve(g[u][1]);
		out[u] = out[g[u][0]] && out[g[u][1]];
	}
	else if (op[u][0] == 'O') {
		solve(g[u][0]);
		solve(g[u][1]);
		out[u] = out[g[u][0]] || out[g[u][1]];
	}
	

}

void dfs(int u) {
	if (op[u][0] == 'I') matter[u] = true;
	else if (op[u][0] == 'N') {
		dfs(g[u][0]);
	}
	else if (op[u][0] == 'X') {
		dfs(g[u][0]);
		dfs(g[u][1]);
	}
	else if (op[u][0] == 'A') {
		if (out[g[u][1]]) dfs(g[u][0]);
		if (out[g[u][0]]) dfs(g[u][1]);
	}
	else if (op[u][0] == 'O') {
		if (!out[g[u][1]]) dfs(g[u][0]);
		if (!out[g[u][0]]) dfs(g[u][1]);
	}
}

int main() {
	scanf("%d", &n);
	FOR1(u, n) {
		scanf(" %s", op[u]);
		if (op[u][0] == 'N') {
			int v;
			scanf("%d", &v);
			g[u].pb(v);
		}
		else if (op[u][0] == 'I') {
			int in;
			scanf("%d", &in);
			out[u] = in ? true : false;
		}
		else {
			int v, w;
			scanf("%d %d", &v, &w);
			g[u].pb(v);
			g[u].pb(w);
		}
	}
	mset(matter, false);
	solve(1);
	dfs(1);
	FOR1(u, n) {
		if (op[u][0] != 'I') continue;
		if (matter[u]) printf("%d", !out[1]);
		else printf("%d", out[1]);
	}
	return 0;
}