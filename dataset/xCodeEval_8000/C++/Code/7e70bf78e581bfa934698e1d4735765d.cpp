


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



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

#undef OImode 

#undef MultiTest 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n, x, y; vi a, dp; vector<vi> adj; map<i64, i64> Map;



void DFS(i64 z, i64 last) {
	for (auto t: adj[z]) {
		if (t == last) continue;
		dp[t] = __gcd(dp[z], a[t]);
		DFS(t, z);
	}
}

void ProcessDivisors() {
	for (i64 i=1; i<=sqrt(a[0]); i++) {
		if (a[0] % i != 0) continue;
		Map[a[0] / i] = 1;
		if (i * i != a[0]) Map[i] = 1;
	}
}

void DFS_WithRoot(i64 z, i64 last, i64 d) {
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 k = it->fi, v = it->se;
		if (a[z] % k == 0) Map[k]++;
	}
	for (auto t: adj[z]) {
		if (t == last) continue;
		dp[t] = __gcd(dp[z], a[t]);
		DFS_WithRoot(t, z, d+1);
	}
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 k = it->fi, v = it->se;
		if (v >= d) dp[z] = max(dp[z], k);
	}
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 k = it->fi, v = it->se;
		if (a[z] % k == 0) Map[k]--;
	}
}

void Input() {
	cin >> n; a.rsz(n); dp.rsz(n, 0); adj.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
	for (i64 i=1; i<n; i++) {
		cin >> x >> y; x--; y--;
		adj[x].pub(y); adj[y].pub(x);
	}
}

void Solve() {
	dp[0] = a[0]; for (auto z: adj[0]) {dp[z] = a[z]; DFS(z, 0);}
	ProcessDivisors(); for (auto z: adj[0]) DFS_WithRoot(z, 0, 1);
	for (auto x: dp) cout << x << " ";
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
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


