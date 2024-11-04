
















































































































































































































































































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