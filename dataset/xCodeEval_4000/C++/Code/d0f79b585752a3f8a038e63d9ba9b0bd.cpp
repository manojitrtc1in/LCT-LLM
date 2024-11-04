


#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 m, ans = 1; vi p;
unordered_map<i64, i64> Map;


i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}


void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> m; p.resize(m);
	for (i64 i=0; i<m; i++) {
		cin >> p[i]; Map[p[i]]++;
	}
}

void ProSolve() {
	vi a, b;
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 x = it->first, y = it->second;
		a.pub(x); b.pub(y);
	}
	i64 N = a.size(), d = 1, f = 1;
	for (i64 i=0; i<N; i++) {
		i64 fp = modPow(a[i], (b[i] + 1) * b[i] / 2);
		f = (modPow(f, (b[i] + 1)) * modPow(fp, d)) % MOD;
		d = (d * (b[i] + 1)) % (MOD - 1);
	}
	cout << f;
}


int main() {
			#ifdef Akikaze
			

			

			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}




