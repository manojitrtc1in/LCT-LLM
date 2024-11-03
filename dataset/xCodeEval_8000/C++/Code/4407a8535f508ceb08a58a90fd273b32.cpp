


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



i64 n; vector<pip> A; set<pip> S;



bool customsort(pip x, pip y) {
	if (x.fi < y.fi) return true;
	if (x.fi > y.fi) return false;
	if (x.se.se == 0 && x.fi % 180 == 0) return false;
	if (y.se.se == 0 && y.fi % 180 == 0) return true;
	if (x.se.se == 0 && x.fi % 180 != 0) return true;
	if (y.se.se == 0 && y.fi % 180 != 0) return false;
	return (x.se.fi * y.se.se < y.se.fi * x.se.se);
}

pip Angle(i64 x, i64 y) {
	i64 res = 0;
	if (x == 0 && y < 0) return mp(180LL, mp(0LL, 1LL));
	if (x == 0 && y > 0) return mp(0LL, mp(0LL, 1LL));
	if (x < 0 && y == 0) return mp(270LL, mp(1LL, 0LL));
	if (x > 0 && y == 0) return mp(90LL, mp(1LL, 0LL));
	if (x < 0) {res += 180; x = -x; y = -y;}
	if (y < 0) {res += 90; swap(x, y); x = -x;}
	i64 g = __gcd(x, y); x /= g; y /= g;
	return mp(res, mp(x, y));
}

void Input() {
	cin >> n;
	for (i64 i=0; i<n; i++) {
		i64 x, y; cin >> x >> y;
		S.insert(Angle(x, y));
	}
}

void Solve() {
	cout << fixed << setprecision(12);
	ld Result = 1e18; i64 N = S.size();
	for (auto it=S.begin(); it!=S.end(); it++) A.pub(*it);
	sort(A.begin(), A.end(), customsort);
	

	for (i64 i=0; i<N; i++) {
		ld Sought = 0LL;
		Sought += A[(i+N-1)%N].fi / 90.0L * (Pi / 2.0L);
		if (A[(i+N-1)%N].se.se != 0) Sought += atan((ld)A[(i+N-1)%N].se.fi / A[(i+N-1)%N].se.se);
		

		Sought -= A[i].fi / 90.0L * (Pi / 2.0L);
		if (A[i].se.se != 0) Sought -= atan((ld)A[i].se.fi / A[i].se.se);
		

		if (Sought < -EPS) Sought += Pi * 2;
		

		Result = min(Result, Sought);
	}
	cout << (Result / (Pi * 2.0L) * 360);
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


