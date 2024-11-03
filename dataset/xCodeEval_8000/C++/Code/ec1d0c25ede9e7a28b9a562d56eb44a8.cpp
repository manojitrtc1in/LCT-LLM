


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



i64 n, m, sa = 0, sb = 0, p, q;
vector<vi> adj; vi a, b;
vector<vi> UsageMatrix;
vector<vi> FlowNetAdj;
vector<vi> CapacityMatrix; i64 N; vb vis; vi dist;



void GenerateFlowNetwork() {
	N = n * 2 + 2; FlowNetAdj.rsz(N);
	CapacityMatrix.rsz(N, vi(N, 0));
	for (i64 i=0; i<n; i++) {
		FlowNetAdj[0].pub(i+1);
		CapacityMatrix[0][i+1] = a[i];
		FlowNetAdj[i+1].pub(0);
		CapacityMatrix[i+1][0] = a[0];
	}
	for (i64 i=0; i<n; i++) {
		FlowNetAdj[n+i+1].pub(n*2+1);
		CapacityMatrix[n+i+1][n*2+1] = b[i];
		FlowNetAdj[n*2+1].pub(n+i+1);
		CapacityMatrix[n*2+1][n+i+1] = 0;
	}
	for (i64 i=0; i<n; i++) {
		FlowNetAdj[i+1].pub(n+i+1);
		CapacityMatrix[i+1][n+i+1] = LINF;
		FlowNetAdj[n+i+1].pub(i+1);
		CapacityMatrix[n+i+1][i+1] = 0;
		for (auto j: adj[i]) {
			FlowNetAdj[i+1].pub(n+j+1);
			CapacityMatrix[i+1][n+j+1] = LINF;
			FlowNetAdj[n+i+1].pub(j+1);
			CapacityMatrix[n+i+1][j+1] = 0;
		}
	}
}

i64 Dinic_DFS(i64 z, i64 MinCap, vi &dist) {
	if (z == N-1) return MinCap;
	i64 Total = 0;
	for (auto t: FlowNetAdj[z]) {
		if (dist[z] >= dist[t]) continue;
		if (CapacityMatrix[z][t] == 0) continue;
		i64 Reduced = Dinic_DFS(t, min(MinCap, CapacityMatrix[z][t]), dist);
		CapacityMatrix[z][t] -= Reduced; CapacityMatrix[t][z] += Reduced;
		if (z > 0 && t < N-1) {
			if (z <= n && t > n) UsageMatrix[z-1][t-n-1] += Reduced;
			else UsageMatrix[t-1][z-n-1] -= Reduced;
		}
		Total += Reduced; MinCap -= Reduced;
		if (MinCap == 0) break;
	}
	return Total;
}

i64 MaxFlow() {
	i64 res = 0;
	while (true) {
		vis.clear(); vis.rsz(N, false);
		dist.clear(); dist.rsz(N, LINF);
		queue<i64> Q; Q.push(0); vis[0] = true; dist[0] = 0;
		while (!Q.empty()) {
			i64 z = Q.front(); Q.pop();
			for (auto t: FlowNetAdj[z]) {
				i64 d = CapacityMatrix[z][t];
				if (vis[t] || d == 0) continue;
				vis[t] = true; dist[t] = dist[z] + 1; Q.push(t);
			}
		}
		if (dist[N-1] == LINF) break;
		i64 DinicCall = Dinic_DFS(0, LINF, dist);
		res += DinicCall;
	}
	return res;
}

void Input() {
	cin >> n >> m; a.rsz(n); b.rsz(n);
	UsageMatrix.rsz(n, vi(n, 0)); adj.rsz(n);
	for (auto &x: a) {cin >> x; sa += x;}
	for (auto &x: b) {cin >> x; sb += x;}
	while (m--) {
		cin >> p >> q; p--; q--;
		adj[p].pub(q); adj[q].pub(p);
	}
}

void Solve() {
	if (sa != sb) {cout << "NO"; return;}
	GenerateFlowNetwork();
	i64 Max = MaxFlow();
	if (Max != sa) {cout << "NO"; return;}
	cout << "YES\n";
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cout << UsageMatrix[i][j] << " ";
		}
		cout << endl;
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

