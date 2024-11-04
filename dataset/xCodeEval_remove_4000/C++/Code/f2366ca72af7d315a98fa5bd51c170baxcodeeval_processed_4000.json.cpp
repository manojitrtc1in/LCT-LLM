




using namespace std;














typedef pair < int ,int > pii;

typedef long long ll;

const long long linf = 1e15+5;
const int mod = (int) 1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 1e6 + 5;

int n, m, x, y, z, c[N], start[N], finish[N], w[N], T;
vector< int > v[N], add[N], del[N];
ll dp[N], ST[N << 2], L[N << 2];

void dfs(int node, int root) {
	start[node] = T + 1;
	foreach(it, add[node]) w[*it] = ++T;
	foreach(it, v[node]) {
		if(*it != root) {
			dfs(*it, node);
		}
	} finish[node] = T;
}

ll update(int k, int bas, int son, int x, ll D) {
	if(bas > x || son < x) return ST[k];
	if(bas == son) return ST[k] = D;
	ST[k] = min(update(sol, bas, orta, x, D), update(sag, orta + 1, son, x, D)) + L[k];
    if(ST[k] > linf) ST[k] = linf;
	return ST[k];

}

ll update(int k, int bas, int son, int x, int y, ll D) {
	if(bas > y || son < x) return ST[k];
	if(x <= bas && son <= y) {
		L[k] = min(linf, D + L[k]);
		ST[k] = min(linf, D + ST[k]);
		return ST[k];
	}
	ST[k] = min(update(sol, bas, orta, x, y, D), update(sag, orta + 1, son, x, y, D)) + L[k];
	if(ST[k] > linf) ST[k] = linf;
	return ST[k];
}

ll query(int k, int bas, int son, int x, int y) {
	if(bas > y || son < x) return linf;
	if(x <= bas && son <= y) return ST[k];
	return min(linf, min(query(sol, bas, orta, x, y), query(sag, orta + 1, son, x, y)) + L[k]);
}

ll solve(int node, int root) {
	ll all = 0;
	foreach(it, v[node]) {
		if(*it == root) continue;
		all += solve(*it, node);
		if(all != 2 * linf)
		    all = min(all, 2 * linf);
	}
	if(node == 1) return dp[node] = all;
	foreach(it, add[node]) update(1, 1, m, w[*it], c[*it] + all);
	foreach(it, del[node]) update(1, 1, m, w[*it], linf);
	foreach(it, v[node])
		if(*it != root)
			update(1, 1, m, start[*it], finish[*it], all - dp[*it]);
	dp[node] = query(1, 1, m, start[node], finish[node]);
	return dp[node];
}

int main() {

	scanf("%d %d", &n, &m);

	FOR(i, 2, n) {
		scanf("%d %d", &x, &y);
		v[x].pb(y); v[y].pb(x);
	}

	FOR(i, 1, m) {
		scanf("%d %d %d", &x, &y, &c[i]);
		add[x].pb(i);
		del[y].pb(i);
	}

	dfs(1, 0);

	ll ans = solve(1, 0);

	if(ans >= linf) ans = -1;

	printf("%lld\n", ans);

	return 0;
}


