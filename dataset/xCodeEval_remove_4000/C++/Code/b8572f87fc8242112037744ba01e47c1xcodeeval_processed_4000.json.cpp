









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();








void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n, m, u, v, t, x, val; vector<vi> Tree, Lazy; vi Lvl;
vi a; vector<vi> adj; map<i64, i64> Map; map<i64, pii> Range;



void DFS(i64 z, i64 last, i64 level) {
	i64 cnt = Map.size(); Map[z] = cnt; Lvl[Map[z]] = level;
	for (auto t: adj[z]) {
		if (last == t) continue;
		DFS(t, z, level + 1);
	}
	Range[Map[z]] = mp(Map[z], Map.size()-1);
}

void Update(i64 id, i64 node, i64 st, i64 en, i64 L, i64 R, i64 val) {
	if (st > en || R < st || en < L) return;
	if (Lazy[id][node] != 0) {
		Tree[id][node] += Lazy[id][node] * (en - st + 1);
		if (st != en) {
			Lazy[id][node*2+0] += Lazy[id][node];
			Lazy[id][node*2+1] += Lazy[id][node];
		}
		Lazy[id][node] = 0;
	}
	if (L <= st && en <= R) {
		Tree[id][node] += val * (en - st + 1);
		if (st != en) {
			Lazy[id][node*2+0] += val;
			Lazy[id][node*2+1] += val;
		}
		return;
	}
	Update(id, node*2, st, (st+en)/2, L, R, val);
	Update(id, node*2+1, (st+en)/2+1, en, L, R, val);
	Tree[id][node] = (Tree[id][node*2] + Tree[id][node*2+1]);
}

i64 Get(i64 id, i64 node, i64 st, i64 en, i64 pos) {
	if (st > en || pos < st || en < pos) return 0;
	if (Lazy[id][node] != 0) {
		Tree[id][node] += Lazy[id][node] * (en - st + 1);
		if (st != en) {
			Lazy[id][node*2+0] += Lazy[id][node];
			Lazy[id][node*2+1] += Lazy[id][node];
		}
		Lazy[id][node] = 0;
	}
	if (pos <= st && en <= pos) return Tree[id][node];
	i64 p1 = Get(id, node*2, st, (st+en)/2, pos);
	i64 p2 = Get(id, node*2+1, (st+en)/2+1, en, pos);
	return (p1 + p2);
}

void Input() {
	cin >> n >> m; Tree.rsz(2, vi(4*n, 0LL)); Lvl.rsz(n);
	a.rsz(n); adj.rsz(n); Lazy.rsz(2, vi(4*n, 0LL));
	for (i64 i=0; i<n; i++) cin >> a[i];
	for (i64 i=1; i<n; i++) {
		cin >> u >> v; u--; v--;
		adj[u].pub(v); adj[v].pub(u);
	}
}

void Solve() {
	DFS(0, -1, 0);
	while (m--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> val; x--;
			i64 L = Range[Map[x]].fi, R = Range[Map[x]].se;
			Update(Lvl[Map[x]] % 2, 1, 0, n-1, L, R, val);
			Update((Lvl[Map[x]] + 1) % 2, 1, 0, n-1, L, R, -val);
		}
		else if (t == 2) {
			cin >> x; x--;
			cout << a[x] + Get(Lvl[Map[x]] % 2, 1, 0, n-1, Map[x]) << endl;
		}
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
		Input(); TimerStart();
		Solve(); TimerStop();
	
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by 
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-' 
	     << (now->tm_mon + 1) << '-'
	     <<  now->tm_mday << " | "
	     <<  now->tm_hour << ":"
	     <<  now->tm_min << ":"
	     <<  now->tm_sec
	     << "\n\n";
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
	
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


