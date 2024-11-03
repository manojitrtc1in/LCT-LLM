


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
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
#define OImode 227420978
#define MultiTest 227420978
#define Interactive 227420978

#undef OImode 

#undef MultiTest 

#undef Interactive 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";



i64 n, q, type, v, x, k; vi p;
vector<vi> adj; vi d, Euler, OP, ED;
vi TreeAdd, TreeSDeg, LazyAdd, LazySDeg;



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
	if (LazySDeg[node] != 0) {
		TreeSDeg[node] += (LazySDeg[node] * (en - st + 1)) % Mod;
		TreeSDeg[node] %= Mod;
		if (st != en) {
			LazySDeg[node*2+0] += LazySDeg[node];
			LazySDeg[node*2+1] += LazySDeg[node];
			LazySDeg[node*2+0] %= Mod;
			LazySDeg[node*2+1] %= Mod;
		}
		LazySDeg[node] = 0;
	}
}

void Update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 v, i64 x, i64 k) {
	Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		LazyAdd[node] += (x + d[v] * k) % Mod; LazySDeg[node] += k;
		LazyAdd[node] %= Mod; LazySDeg[node] %= Mod;
		Propagate(node, st, en); return;
	}
	Update(node*2, st, (st+en)/2, L, R, v, x, k);
	Update(node*2+1, (st+en)/2+1, en, L, R, v, x, k);
	TreeAdd[node] = (TreeAdd[node*2] + TreeAdd[node*2+1]) % Mod;
	TreeSDeg[node] = (TreeSDeg[node*2] + TreeSDeg[node*2+1]) % Mod;
}

i64 GetVal(i64 node, i64 st, i64 en, i64 id, i64 v) {
	Propagate(node, st, en);
	if (st > en || en < id || id < st) return 0;
	if (id <= st && en <= id) {
		i64 res = TreeAdd[node];
		res -= (TreeSDeg[node] * d[v]) % Mod;
		res %= Mod; while (res < 0) res += Mod;
		return res;
	}
	i64 p1 = GetVal(node*2, st, (st+en)/2, id, v);
	i64 p2 = GetVal(node*2+1, (st+en)/2+1, en, id, v);
	return ((p1 + p2) % Mod);
}

void DFS(i64 z) {
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
	for (i64 i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[i].pub(p[i]); adj[p[i]].pub(i);
	}
}

void Solve() {
	TreeAdd.rsz(n*4, 0); TreeSDeg.rsz(n*4, 0);
	LazyAdd.rsz(n*4, 0); LazySDeg.rsz(n*4, 0);
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

	#ifndef Interactive
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	#else
		ios_base::sync_with_stdio(0);
	#endif
	
	#ifndef MultiTest
		Input(); TimerStart();
		Solve(); TimerStop();
	#else
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	#endif

	return 0;
}



void ControlIO(int argc, char* argv[]) {
	char* infile = new char[cppstr_infile.size()+1];
	char* outfile = new char[cppstr_outfile.size()+1];
	strcpy(infile, cppstr_infile.c_str());
	strcpy(outfile, cppstr_outfile.c_str());
	#ifdef Akikaze
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Current time: ";
		cout << (now->tm_year + 1900) << '-' 
			 << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
			 << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
			 << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
			 << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
			 << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
			 << "\n\n";
		
		#ifdef OImode
			cout << "OI-Mode: ON\n";
			cout << "Input file: " << infile << endl;
			cout << "Output file: " << outfile << endl;
			cout << "\n";
		#else
			cout << "OI-Mode: OFF\n";
			cout << "Input file: NULL\n";
			cout << "Output file: NULL\n";
			cout << "\n";
		#endif
		
		#ifdef MultiTest
			cout << "MultiTest-Mode: ON\n";
		#else
			cout << "MultiTest-Mode: OFF\n";
		#endif
		
		#ifdef Interactive
			cout << "Interactive-Mode: ON\n\n";
		#else
			cout << "Interactive-Mode: OFF\n\n";
		#endif
		
		if (argc > 1) assert(freopen(argv[1], "r", stdin));
		if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
		freopen(infile, "r", stdin);
		freopen(outfile, "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
		TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
		TimeEnd = chrono::steady_clock::now();
		auto ElapsedTime = TimeEnd - TimeStart;
		cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}


