


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

i64 n, cnt = 0, ans = 0; vs w; vi a;
map<string, int> Map; map<i64, i64> Size;



void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



void Input() {
	cin >> n; w.rsz(n); a.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> w[i];
		if (!Map[w[i]]) Map[w[i]] = ++cnt;
		a[i] = Map[w[i]]; Size[a[i]] = w[i].size();
		ans += w[i].size(); if (i > 0) ans++;
	}
}

void Solve() {
	map<vi, i64> Last, Cnt; i64 Max = ans;
	

	for (i64 i=0; i<n; i++) {
		for (i64 j=i; j<n; j++) {
			if (Last.find(vi(a.begin()+i, a.begin()+j+1)) == Last.end() || 
				Last[vi(a.begin()+i, a.begin()+j+1)] < i) {
				Last[vi(a.begin()+i, a.begin()+j+1)] = j;
				Cnt[vi(a.begin()+i, a.begin()+j+1)]++;
			}
		}
	}
	for (auto it=Cnt.begin(); it!=Cnt.end(); it++) {
		vi z = it->first; i64 cc = it->second, siz = 0;
		if (cc <= 1) continue;
		for (i64 i=0; i<z.size(); i++) {
			siz += Size[z[i]];
			siz += (i != 0);
		}
		

		ans = min(ans, Max - (siz - z.size()) * cc);
	}
	cout << ans;
}



int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
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



































































































































































































































































