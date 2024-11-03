


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



i64 n, m, MSTSize = 0; vector<pii> E; vector<ppi> A;
vi DSUsize, DSUpar;



bool edgesort(ppi x, ppi y) {
	if (x.fi.fi < y.fi.fi) return true;
	if (x.fi.fi > y.fi.fi) return false;
	if (x.fi.fi == y.fi.fi) return (x.fi.se > y.fi.se);
}

i64 DSUfind(i64 x) {
	while (DSUpar[x] != -1) x = DSUpar[x];
	return x;
}

void DSUmerge(i64 a, i64 b) {
	i64 u = DSUfind(a), v = DSUfind(b);
	if (u == v) return;
	if (DSUsize[u] < DSUsize[v]) swap(u, v);
	DSUsize[u] += DSUsize[v]; DSUpar[v] = u;
}

i64 TrueMST() {
	i64 res = 0; DSUsize.rsz(n+1, 1); DSUpar.rsz(n+1, -1);
	for (auto z: A) {
		i64 id = z.se, d = z.fi.fi;
		i64 u = E[id].fi, v = E[id].se;


		if (DSUfind(u) != DSUfind(v)) {
			res += d; DSUmerge(u, v);
		}


	}
	return res;
}

void Input() {
	cin >> n >> m; A.rsz(m); E.rsz(m);
	for (i64 i=0; i<m; i++) {
		cin >> A[i].fi.fi >> A[i].fi.se;
		A[i].se = i; MSTSize += A[i].fi.fi * A[i].fi.se;
	}
}

void Solve() {
	sort(A.begin(), A.end(), edgesort);
	vi Dist(n+1, 0LL), Ptr(n+1);
	set<pip> Set; i64 cnt = 1; set<pii> Missing;
	for (i64 i=2; i<=n; i++) {Ptr[i] = i+1; Missing.insert(mp(i+1, i));}
	for (auto x: A) {
		i64 id = x.se;
		i64 a = x.fi.fi, b = x.fi.se;










		if (b == 1) {
			while (!Missing.empty()) {
				pii Z = *Missing.begin(); i64 z = Z.se;
				if (Z.fi > cnt+1) break; Missing.erase(Z);
				Ptr[z] = Z.fi; Set.insert(mp(Dist[z]+a, mp(z, Z.fi)));
			}
			E[id].fi = 1; E[id].se = cnt+1; Dist[cnt] = a; cnt++; continue;
		}
		if (Set.empty()) {cout << "-1"; return;}
		pip Z = *Set.begin(); i64 L = Z.se.fi, R = Z.se.se; Set.erase(Z);
		if (R+1 <= cnt) {Set.insert(mp(Dist[L]+Dist[R+1], mp(L, R+1))); Ptr[L] = R+1;}
		else {Missing.insert(mp(R+1, L)); Ptr[L] = R+1;}
		E[id].fi = L; E[id].se = R; R++; Ptr[L]++;
	}


	if (TrueMST() < MSTSize) {cout << "-1"; return;}
	for (auto x: E) cout << x.fi << " " << x.se << endl;
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


