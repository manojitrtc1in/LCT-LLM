


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



string s; i64 n; vs A; map<char, set<char>> interchangable;



void preprocess() {
	for (i64 i=0; i<26; i++) {
		interchangable[char(65+i)].insert(char(97+i));
		interchangable[char(97+i)].insert(char(65+i));
	}
	interchangable['0'].insert('O'); interchangable['0'].insert('o');
	interchangable['O'].insert('0'); interchangable['o'].insert('0');
	interchangable['1'].insert('L'); interchangable['1'].insert('l');
	interchangable['L'].insert('1'); interchangable['l'].insert('1');
	interchangable['1'].insert('I'); interchangable['1'].insert('i');
	interchangable['I'].insert('1'); interchangable['i'].insert('1');
	interchangable['L'].insert('I'); interchangable['L'].insert('i');
	interchangable['l'].insert('I'); interchangable['l'].insert('i');
	interchangable['I'].insert('L'); interchangable['I'].insert('l');
	interchangable['i'].insert('L'); interchangable['i'].insert('l');
}

bool similar(string x, string y) {
	if (x.size() != y.size()) return false;
	for (i64 i=0; i<x.size(); i++) {
		char a = x[i], b = y[i];
		if (a == b) continue;
		if (interchangable[a].find(b) == interchangable[a].end()) return false;
	}
	return true;
}

void Input() {
	cin >> s >> n; A.rsz(n);
	for (i64 i=0; i<n; i++) cin >> A[i];
}

void Solve() {
	preprocess();
	for (i64 i=0; i<n; i++) {
		if (similar(A[i], s)) {cout << "No"; return;}
	}
	cout << "Yes";
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


