


#pragma comment(linker, "/stack:227420978")
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
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#undef OImode 






void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();

bool isPrime(i64 z) {
	for (i64 i=2; i<=sqrt(z); i++) {
		if (z % i == 0) return false;
	}
	return true;
}

void Input() {
	
}

void Solve() {
	i64 divisors = -1;
	string verdict;
	for (i64 i=2; i<=10; i++) {
		if (!isPrime(i)) continue; i64 z = i;
		while (z <= 100) {
			cout << z << endl; fflush(stdout);
			cin >> verdict; if (verdict == "no") {break;}
			if (divisors != -1) {cout << "composite"; return;}
			divisors = i; z *= i;
		}
	}
	if (divisors == -1) {cout << "prime"; return;}
	for (i64 i=2; i<=100LL/divisors; i++) {
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) continue;
		if (i <= 10) continue;
		cout << i << endl; fflush(stdout);
		cin >> verdict; if (verdict == "no") {continue;}
		cout << "composite"; return;
	}
	cout << "prime";
}



int main(int argc, char* argv[]) {
	

	ControlIO(argc, argv);
	Input(); TimerStart();
	Solve(); TimerStop();
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("filename.inp", "r", stdin);
	freopen("filename.out", "w", stdout);
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



































































































































































































































































