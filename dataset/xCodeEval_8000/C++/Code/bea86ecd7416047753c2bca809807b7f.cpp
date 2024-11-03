


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



i64 n; vi a, Log2; vector<vi> TableGCD, TableMin;
i64 len; vi ID, Tmp;



void BuildTable() {
	Log2.rsz(n+1, 0);
	TableGCD.rsz(n); TableMin.rsz(n);
	for (i64 i=0; i<=n; i++) {
		for (i64 j=20; j>=0; j--) {
			if ((1LL << j) <= i) {
				Log2[i] = j;
				break;
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		TableGCD[i].pub(a[i]);
		TableMin[i].pub(a[i]);
	}
	for (i64 j=1; j<=20; j++) {
		for (i64 i=0; i<n; i++) {
			if (TableGCD[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (TableGCD[i + (1LL << (j - 1))].size() < j) continue;
			TableGCD[i].pub(__gcd(TableGCD[i][j-1], TableGCD[i + (1LL << (j - 1))][j-1]));
		}
	}
	for (i64 j=1; j<=20; j++) {
		for (i64 i=0; i<n; i++) {
			if (TableMin[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (TableMin[i + (1LL << (j - 1))].size() < j) continue;
			TableMin[i].pub(min(TableMin[i][j-1], TableMin[i + (1LL << (j - 1))][j-1]));
		}
	}
}

i64 GetGCD(i64 L, i64 R) {
	i64 res = 0;
	while (L <= R) {
		i64 dist = R - L + 1;
		res = __gcd(res, TableGCD[L][Log2[dist]]);
		L += (1LL << Log2[dist]);
	}
	return res;
}

i64 GetMin(i64 L, i64 R) {
	i64 res = LINF;
	while (L <= R) {
		i64 dist = R - L + 1;
		res = min(res, TableMin[L][Log2[dist]]);
		L += (1LL << Log2[dist]);
	}
	return res;
}

void calculate(i64 siz) {
	Tmp.clear();
	for (i64 i=0; i<=n-siz; i++) {
		if (GetMin(i, i+siz-1) == GetGCD(i, i+siz-1)) {
			Tmp.pub(i+1);
		}
	}
}

void binsearch(i64 top, i64 bot) {
	if (top > bot) return;
	i64 mid = (top + bot) / 2;
	calculate(mid);
	if (!Tmp.empty()) {
		ID = Tmp; len = mid - 1;
		binsearch(mid+1, bot);
	}
	else binsearch(top, mid-1);
}

void Input() {
	cin >> n; a.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	BuildTable(); binsearch(1, n);
	cout << ID.size() << " " << len << endl;
	for (auto x: ID) cout << x << " ";
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


