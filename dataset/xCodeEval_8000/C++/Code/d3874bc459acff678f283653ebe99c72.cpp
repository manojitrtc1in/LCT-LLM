


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
#define Interactive 227420978

#undef OImode 

#undef MultiTest 

#undef Interactive 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n, m, r, c, x, y; vector<vc> a;





void Input() {
	cin >> n >> m >> r >> c >> x >> y;
	a.rsz(n, vc(m, '.')); r--; c--;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	priority_queue<pip> Q; vector<vb> vis(n, vb(m, false));
	vector<vi> Dist(n, vi(m, LINF*4)); Dist[r][c] = 0;
	Q.push(mp(-Dist[r][c], mp(r, c)));
	while (!Q.empty()) {
		pip Token = Q.top(); Q.pop();
		i64 d = -Token.fi, i = Token.se.fi, j = Token.se.se;
		if (vis[i][j]) continue; vis[i][j] = true;
		if (i-1 >= 0 && a[i-1][j] == '.' && !vis[i-1][j] && Dist[i][j] < Dist[i-1][j]) {
			Dist[i-1][j] = Dist[i][j]; Q.push(mp(-Dist[i-1][j], mp(i-1, j)));
		}
		if (i+1 < n && a[i+1][j] == '.' && !vis[i+1][j] && Dist[i][j] < Dist[i+1][j]) {
			Dist[i+1][j] = Dist[i][j]; Q.push(mp(-Dist[i+1][j], mp(i+1, j)));
		}
		if (j-1 >= 0 && a[i][j-1] == '.' && !vis[i][j-1] && Dist[i][j]+1 < Dist[i][j-1]) {
			Dist[i][j-1] = Dist[i][j]+1; Q.push(mp(-Dist[i][j-1], mp(i, j-1)));
		}
		if (j+1 < m && a[i][j+1] == '.' && !vis[i][j+1] && Dist[i][j]+0 < Dist[i][j+1]) {
			Dist[i][j+1] = Dist[i][j]+0; Q.push(mp(-Dist[i][j+1], mp(i, j+1)));
		}
	}
	i64 ans = 0;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			ans += (Dist[i][j] <= x && Dist[i][j] + (j - c) <= y);
		}
	}
	cout << ans;
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


