








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
string id1 = "FILE.IN";
string id2 = "FILE.OUT";



int n, q, type, v; i64 x, k; vector<int> p;
vector<vector<int>> adj; vector<int> d, Euler, OP, ED;
vi TreeAdd, id0, LazyAdd, id3;



void Propagate(i64 node, i64 st, i64 en) {
	if (LazyAdd[node] != 0) {
		TreeAdd[node] += (LazyAdd[node] * (en - st + 1)) % Mod;
		TreeAdd[node] %= Mod;
		if (st != en) {
			LazyAdd[node*2+0] += LazyAdd[node];
			LazyAdd[node*2+1] += LazyAdd[node];
			LazyAdd[node*2+0] %= Mod;
			LazyAdd[node*2+1] %= Mod;
		}
		LazyAdd[node] = 0;
	}
	if (id3[node] != 0) {
		id0[node] += (id3[node] * (en - st + 1)) % Mod;
		id0[node] %= Mod;
		if (st != en) {
			id3[node*2+0] += id3[node];
			id3[node*2+1] += id3[node];
			id3[node*2+0] %= Mod;
			id3[node*2+1] %= Mod;
		}
		id3[node] = 0;
	}
}

void Update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 v, i64 x, i64 k) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		LazyAdd[node] += (x + k * d[v]) % Mod; id3[node] += k;
		LazyAdd[node] %= Mod; id3[node] %= Mod;
		Propagate(node, st, en); return;
	}
	Update(node*2, st, (st+en)/2, L, R, v, x, k);
	Update(node*2+1, (st+en)/2+1, en, L, R, v, x, k);
	TreeAdd[node] = (TreeAdd[node*2] + TreeAdd[node*2+1]) % Mod;
	id0[node] = (id0[node*2] + id0[node*2+1]) % Mod;
}

i64 GetVal(i64 node, i64 st, i64 en, i64 id, i64 v) {
	Propagate(node, st, en);
	if (st > en || en < id || id < st) return 0;
	if (id <= st && en <= id) {
		i64 res = TreeAdd[node];
		res -= (id0[node] * d[v]) % Mod;
		res %= Mod; while (res < 0) res += Mod;
		return res;
	}
	i64 p1 = GetVal(node*2, st, (st+en)/2, id, v);
	i64 p2 = GetVal(node*2+1, (st+en)/2+1, en, id, v);
	return ((p1 + p2) % Mod);
}

void DFS(int z) {
	OP[z] = Euler.size(); Euler.pub(z);
	for (auto t: adj[z]) {
		if (p[z] == t) continue;
		d[t] = d[z] + 1; DFS(t);
	}
	ED[z] = Euler.size() - 1;
}

void ProcessEuler() {
	OP.rsz(n); ED.rsz(n);
	d.rsz(n); DFS(0);
}

void Input() {
	cin >> n; p.rsz(n, -1); adj.rsz(n);
	for (int i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[i].pub(p[i]); adj[p[i]].pub(i);
	}
}

void Solve() {
	TreeAdd.rsz(n*4, 0); id0.rsz(n*4, 0);
	LazyAdd.rsz(n*4, 0); id3.rsz(n*4, 0);
	ProcessEuler(); cin >> q;
	while (q--) {
		cin >> type >> v; v--;
		i64 L = OP[v], R = ED[v];
		if (type == 1) {
			cin >> x >> k;
			Update(1, 0, n-1, L, R, v, x, k);
		}
		else if (type == 2) {
			cout << GetVal(1, 0, n-1, L, v) << endl;
		}
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	
		ios_base::sync_with_stdio(0);
	
	
	
		Input(); TimerStart();
		Solve(); TimerStop();
	
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	

	return 0;
}



void ControlIO(int argc, char* argv[]) {
	char* infile = new char[id1.size()+1];
	char* outfile = new char[id2.size()+1];
	strcpy(infile, id1.c_str());
	strcpy(outfile, id2.c_str());
	
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << "Source code by 
		cout << "Current time: ";
		cout << (now->tm_year + 1900) << '-' 
			 << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
			 << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
			 << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
			 << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
			 << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
			 << "\n\n";
		
		
			cout << "OI-Mode: ON\n";
			cout << "Input file: " << infile << endl;
			cout << "Output file: " << outfile << endl;
			cout << "\n";
		
			cout << "OI-Mode: OFF\n";
			cout << "Input file: NULL\n";
			cout << "Output file: NULL\n";
			cout << "\n";
		
		
		
			cout << "MultiTest-Mode: ON\n";
		
			cout << "MultiTest-Mode: OFF\n";
		
		
		
			cout << "Interactive-Mode: ON\n\n";
		
			cout << "Interactive-Mode: OFF\n\n";
		
		
		if (argc > 1) assert(freopen(argv[1], "r", stdin));
		if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
		freopen(infile, "r", stdin);
		freopen(outfile, "w", stdout);
	
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


