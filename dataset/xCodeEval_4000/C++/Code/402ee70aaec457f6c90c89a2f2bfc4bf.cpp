


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define endl '\n'
#define i64 short int
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



i64 n, m; vector<vector<vector<pii>>> adj; vector<vc> a;





void Input() {
	cin >> n >> m; a.rsz(n, vc(m, '.'));
	adj.rsz(n, vector<vector<pii>>(m));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	queue<pii> Q;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (a[i][j] == '*') continue;
			if (i-1 >= 0 && a[i-1][j] == '.') {
				adj[i][j].pub(mp(i-1, j));
			}
			if (i+1 < n && a[i+1][j] == '.') {
				adj[i][j].pub(mp(i+1, j));
			}
			if (j-1 >= 0 && a[i][j-1] == '.') {
				adj[i][j].pub(mp(i, j-1));
			}
			if (j+1 < m && a[i][j+1] == '.') {
				adj[i][j].pub(mp(i, j+1));
			}
			if (adj[i][j].size() == 1) Q.push(mp(i, j));
		}
	}
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		i64 i = z.fi, j = z.se;
		if (adj[i][j].empty()) continue;
		if (a[i][j] != '.') continue;
		pii z1 = *adj[i][j].begin();
		i64 i1 = z1.fi, j1 = z1.se;
		if (i == i1) {
			a[i][j] = '<'; a[i1][j1] = '>';
			if (j > j1) swap(a[i][j], a[i1][j1]);
		}
		else {
			a[i][j] = '^'; a[i1][j1] = 'v';
			if (i > i1) swap(a[i][j], a[i1][j1]);
		}
		for (auto zazz: adj[i1][j1]) {
			i64 u = zazz.fi, v = zazz.se;
			adj[u][v].erase(find(adj[u][v].begin(), adj[u][v].end(), mp(i1, j1)));
			if (adj[u][v].size() == 1) Q.push(mp(u, v));
		}
		adj[i1][j1].clear();
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (a[i][j] == '.') {cout << "Not unique"; return;}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	#ifndef Interactive
		

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
	#ifdef Akikaze
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by #Team4T-Akikaze.\n";
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
	#elif OImode
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
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


