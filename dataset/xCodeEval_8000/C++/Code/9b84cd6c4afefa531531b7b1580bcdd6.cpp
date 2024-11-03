


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



i64 a00, a01, a10, a11;



i64 solve(i64 z) {
	i64 r = sqrt(2*z);
	for (i64 i=r-4; i<=r+4; i++) {
		if (i <= 0) continue;
		if (i*(i-1)/2 == z) return i;
	}
	return (-1);
}

void Input() {
	cin >> a00 >> a01 >> a10 >> a11;
}

void Solve() {
	i64 Zero = solve(a00), Ichi = solve(a11);
	if (Zero == -1 || Ichi == -1) {cout << "Impossible"; return;}
	if (Zero == 1 && Ichi == 1) {
		if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 0) cout << "0";
		else if (a00 == 0 && a11 == 0 && a01 == 1 && a10 == 0) cout << "01";
		else if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 1) cout << "10";
		else cout << "Impossible"; return;
	}
	if (Zero == 1 || Ichi == 1) {
		if (a01 == 0 && a10 == 0) {
			if (Zero != 1) for (i64 i=0; i<Zero; i++) cout << "0";
			else for (i64 i=0; i<Ichi; i++) cout << "1";
		}
		else if (a01 + a10 == max(Zero, Ichi)) {
			if (Zero < Ichi) {
				for (i64 i=0; i<a10; i++) cout << "1";
				cout << "0";
				for (i64 i=0; i<a01; i++) cout << "1";
			}
			else {
				for (i64 i=0; i<a01; i++) cout << "0";
				cout << "1";
				for (i64 i=0; i<a10; i++) cout << "0";
			}
		}
		else cout << "Impossible";
		return;
	}
	if (a01 + a10 != Zero * Ichi) {cout << "Impossible"; return;}
	vi cnt(Zero+1, 0LL);
	for (i64 i=0; i<Ichi; i++) {
		if (a01 < a10) {
			i64 id = 0;
			if (a10 < Zero) id = Zero - a10;
			cnt[id]++; a01 -= id; a10 -= (Zero - id);
		}
		else {
			i64 id = Zero;
			if (a01 < Zero) id = a01;
			cnt[id]++; a01 -= id; a10 -= (Zero - id);
		}
	}
	for (i64 x=0; x<=Zero; x++) {
		for (i64 z=0; z<cnt[x]; z++) cout << "1";
		if (x != Zero) cout << "0";
	}
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


