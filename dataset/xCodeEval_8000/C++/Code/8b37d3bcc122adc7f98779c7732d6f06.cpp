


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



i64 n, a, b, T; string s;





void Input() {
	cin >> n >> a >> b >> T >> s;
}

void Solve() {
	vi dpR(n, LINF), dpL(n, LINF); i64 opt = 0;
	if (s[0] == 'h') {dpR[0] = 1; dpL[0] = 1;}
	else {dpR[0] = b + 1; dpL[0] = b + 1;}
	for (i64 i=1; i<n; i++) {
		dpR[i] = dpR[i-1] + a + 1;
		if (s[i] == 'w') dpR[i] += b;
	}
	for (i64 i=n-1; i>0; i--) {
		dpL[i] = dpL[(i+1)%n] + a + 1;
		if (s[i] == 'w') dpL[i] += b;
	}
	for (i64 i=0; i<n; i++) {
		if (dpR[i] <= T) {opt = max(opt, i + 1);}
		if (dpL[i] <= T) {opt = max(opt, (n - i) % n + 1);}
	}
	if (n < 3) {cout << opt; return;}
	i64 petrR = 1, petrL = 2;
	while (petrR < n - 1) {
		while (petrL < n && dpR[petrR] + petrR * a + dpL[petrL] - dpL[0] > T) petrL++;
		if (petrL == n) break;
		opt = max(opt, n - (petrL - petrR - 1));
		petrR++; petrL = max(petrL, petrR+1);
	}
	petrL = n - 1, petrR = n - 2;
	while (petrL > 1) {
		while (petrR > 0 && dpL[petrL] + (n - petrL) * a + dpR[petrR] - dpR[0] > T) petrR--;
		if (petrR == 0) break;
		opt = max(opt, n - (petrL - petrR - 1));
		petrL--; petrR = min(petrR, petrL-1);
	}
	cout << opt;
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

