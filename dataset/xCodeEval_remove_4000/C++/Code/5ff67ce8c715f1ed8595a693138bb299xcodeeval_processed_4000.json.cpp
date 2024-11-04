















































































































 
using namespace std;
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}












using ll = long long;
using ld = long double; 
const int MAXN = 200228;


int n, m;
vector<pair<int, int> > g[MAXN];
int parent[MAXN];


int findset(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = findset(parent[a]);
}


int timer = 0;
int in[MAXN];
int out[MAXN];
vector<int> zxc[MAXN];
int who[MAXN];
int add[MAXN];
int good[MAXN];
int prs[MAXN];
int f[MAXN];
map<pair<int, int>, int> e;


void dfs(int u, int pr = -1) {
	timer++;
	who[timer] = u;
	in[u] = timer;
	for (auto h: g[u]) {
		if (h.second == 1 && h.first != pr) {
			prs[h.first] = u; 
			dfs(h.first, u);
			zxc[u].pb(in[h.first]);
		}
	}
	out[u] = timer;
}


bool isParent(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int used[MAXN];
int uk = 0;
int pd[MAXN];

int getv(int a, int b) {
	int son;
	if (isParent(a, b)) {
		int pos = upper_bound(all(zxc[a]), in[b]) - zxc[a].begin() - 1;
		son = who[zxc[a][pos]]; 
	} else {
		son = prs[a];
	}
	return son;
}

int reqs;


void addval(int i, int j) {
	reqs++;
	if (prs[j] == i) {
		add[in[j]]++;
		add[out[j] + 1]--;
	} else {
		add[1]++;
		add[in[i]]--;
		add[out[i] + 1]++;
	}
}


void solve() {
	cin >> n >> m;
	e.clear();
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		parent[i] = i;
		zxc[i].clear();
		add[i] = 0;
		good[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[mp(a, b)] = e[mp(b, a)] = i;
		if (findset(a) != findset(b)) {
			g[a].pb(mp(b, 1));
			g[b].pb(mp(a, 1)); 
			parent[findset(a)] = findset(b);
		} else {
			g[a].pb(mp(b, 0));
			g[b].pb(mp(a, 0));
		}
	}	
	dfs(0);
	reqs = 0;
	for (int i = 0; i < n; i++) {
		for (auto h: g[i]) {
			if (h.second == 0) {
				int j = h.first;
				{
					if (isParent(i, j)) {
						int k = getv(i, j);
						add[1]++;
						add[in[k]]--;
						add[out[k] + 1]++;
						add[in[j]]++;
						add[out[j] + 1]--;
						reqs++;
					} else if (isParent(j, i)) {
	
					} else {
						add[in[i]]++;
						add[out[i] + 1]--;
						add[in[j]]++;
						add[out[j] + 1]--;
						reqs++;
					}
				}
				int k = getv(i, j);
				
				if (e[mp(k, i)] > e[mp(j, i)]) {
					addval(i, k);
				}
			}
		}
	}
	int bal = 0;
	for (int i = 1; i <= n; i++) {
		bal += add[i];
		if (bal == reqs) {
		} else {
			good[who[i]] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << good[i];
	}
	cout << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	

	while (t--) {
		solve();
	}
}
