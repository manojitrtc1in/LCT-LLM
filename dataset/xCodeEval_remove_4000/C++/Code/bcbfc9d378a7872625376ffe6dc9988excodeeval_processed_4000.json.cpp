









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();




i64 n, m, u, v; vector<vi> adj, Adj; vi d;
vb attacked, included; map<pii, i64> Map;



void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();

void DFS(i64 z, i64 last) {
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z);
	}
	if (included[z] && last >= 0) {
		if (!Map[mp(z, last)]) {
			Adj[z].pub(last); Adj[last].pub(z);
			Map[mp(z, last)]++; Map[mp(last, z)]++;
		}
		included[z] = true; included[last] = true;
	}
}

void Input() {
	cin >> n >> m; adj.rsz(n); Adj.rsz(n); d.rsz(m);
	attacked.rsz(n, false); included.rsz(n, false);
	for (i64 i=1; i<n; i++) {
		cin >> u >> v; u--; v--;
		adj[u].pub(v); adj[v].pub(u);
	}
	for (i64 i=0; i<m; i++) {
		cin >> d[i]; d[i]--; attacked[d[i]] = true;
		included[d[i]] = true;
	}
}

void Solve() {
	if (m == 1) {cout << d[0]+1 << "\n0"; return;}
	sort(d.begin(), d.end()); DFS(d[0], -1);
	i64 chosen = -1, length = 0;
	for (i64 i=0; i<m; i++) {
		if (Adj[d[i]].size() == 1) {
			chosen = d[i]; break;
		}
	}
	for (i64 i=0; i<n; i++) {
		if (included[i]) length += Adj[i].size();
	}
	vi dist(n, -LINF); dist[chosen] = 0;
	vb vis(n, false); vis[chosen] = true;
	queue<i64> Q; Q.push(chosen);
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (auto t: Adj[z]) {
			if (vis[t]) continue;
			vis[t] = true; Q.push(t);
			dist[t] = dist[z] + 1;
		}
	}
	chosen = max_element(dist.begin(), dist.end()) - dist.begin();
	dist.clear(); dist.rsz(n, -LINF); dist[chosen] = 0;
	vis.clear(); vis.rsz(n, false); vis[chosen] = true;
	while (!Q.empty()) Q.pop(); Q.push(chosen);
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (auto t: Adj[z]) {
			if (vis[t]) continue;
			vis[t] = true; Q.push(t);
			dist[t] = dist[z] + 1;
		}
	}
	chosen = min((i64)(max_element(dist.begin(), dist.end()) - dist.begin()), chosen);
	length -= *max_element(dist.begin(), dist.end());
	cout << chosen+1 << endl << length;
}



int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	Input(); TimerStart();
	Solve(); TimerStop();
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("filename.inp", "r", stdin);
	freopen("filename.out", "w", stdout);
	
}

void TimerStart() {
	
	TimeStart = chrono::steady_clock::now();
	
}

void TimerStop() {
	
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	
}

void Exit() {
	TimerStop(); exit(0);
}



































































































































































































































































