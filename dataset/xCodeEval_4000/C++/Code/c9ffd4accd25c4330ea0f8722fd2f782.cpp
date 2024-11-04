
 



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
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());



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



i64 n, m; vector<pii> P; vi a;
vector<map<i64, i64>> Fact;



i64 Dinic_DFS(i64 z, i64 src, i64 sink, i64 MinCap, vector<vi> &CapacityMatrix, vector<vi> &adj, vi &dist) {
	if (z == sink) return MinCap;
	i64 Total = 0;
	for (auto t: adj[z]) {
		if (dist[z] >= dist[t]) continue;
		if (CapacityMatrix[z][t] == 0) continue;
		i64 Reduced = Dinic_DFS(t, src, sink, min(MinCap, CapacityMatrix[z][t]), CapacityMatrix, adj, dist);
		CapacityMatrix[z][t] -= Reduced; CapacityMatrix[t][z] += Reduced;
		Total += Reduced; MinCap -= Reduced; if (MinCap == 0) break;
	}
	return Total;
}

void ConstructGraph(i64 &N, vector<vi> &CapacityMatrix, vector<vi> &adj, i64 &src, i64 &sink) {
	vector<map<i64, i64>> MapID(n);
	for (i64 i=0; i<n; i++) {
		for (auto it=Fact[i].begin(); it!=Fact[i].end(); it++) {
			i64 k = it->fi, val = it->se;
			N++; MapID[i][k] = N;
		}
	}
	src = 0; sink = N+1; N += 2;
	CapacityMatrix.rsz(N, vi(N, 0)); adj.rsz(N);
	for (i64 i=0; i<n; i++) {
		for (auto it=Fact[i].begin(); it!=Fact[i].end(); it++) {
			i64 k = it->fi, val = it->se, id = MapID[i][k];
			if (i % 2 == 0) {CapacityMatrix[src][id] = val; adj[src].pub(id); adj[id].pub(src);}
			else {CapacityMatrix[id][sink] = val; adj[id].pub(sink); adj[sink].pub(id);}
		}
	}
	for (auto Pair: P) {
		i64 i = Pair.fi, j = Pair.se;
		if (i % 2 != 0) swap(i, j);
		for (auto it=MapID[i].begin(); it!=MapID[i].end(); it++) {
			i64 k = it->fi, id_i = it->se;
			if (MapID[j].find(k) == MapID[j].end()) continue;
			i64 id_j = MapID[j][k];
			CapacityMatrix[id_i][id_j] = LINF;
			adj[id_i].pub(id_j); adj[id_j].pub(id_i);
		}
	}
}
 
i64 MaxFlow(vector<vi> CapacityMatrix = vector<vi>(0), vector<vi> adj = vector<vi>(0), i64 N = 0, i64 src = 0, i64 sink = 0) {
	ConstructGraph(N, CapacityMatrix, adj, src, sink);
	i64 res = 0;
	while (true) {
		vb vis(N, false); vi dist(N, LINF);
		queue<i64> Q; Q.push(src);
		vis[src] = true; dist[src] = 0;
		while (!Q.empty()) {
			i64 z = Q.front(); Q.pop();
			for (auto t: adj[z]) {
				if (vis[t]) continue;
				if (CapacityMatrix[z][t] == 0) continue;
				vis[t] = true; dist[t] = dist[z] + 1; Q.push(t);
			}
		}
		if (dist[sink] == LINF) break;
		i64 DinicCall = Dinic_DFS(src, src, sink, LINF, CapacityMatrix, adj, dist);
		res += DinicCall;
	}
	return res;
}

void Input() {
	cin >> n >> m; a.rsz(n); P.rsz(m);
	for (auto &z: a) cin >> z;
	for (auto &Pair: P) {
		i64 i, j; cin >> i >> j;
		i--; j--; Pair = {i, j};
	}
}

void Solve() {
	Fact.rsz(n);
	for (i64 i=0; i<n; i++) {
		i64 curr = a[i];
		for (i64 f=2; f<=sqrt(curr); f++) {
			i64 e = 0;
			while (curr % f == 0) {curr /= f; e++;}
			if (e > 0) Fact[i][f] += e;
		}
		if (curr > 1) Fact[i][curr]++;
	}
	cout << MaxFlow() << endl;
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


