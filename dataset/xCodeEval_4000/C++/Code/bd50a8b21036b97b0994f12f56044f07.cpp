








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







i64 n, x1, y1, x2, y2; vector<ppi> a;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> x1 >> y1 >> x2 >> y2 >> n; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
}

void ProSolve() {
    i64 ans = 0;
    for (i64 i=0; i<n; i++) {
        i64 A = a[i].fi.fi * x1 + a[i].fi.se * y1 + a[i].se;
        i64 B = a[i].fi.fi * x2 + a[i].fi.se * y2 + a[i].se;
        if (A < 0 && B > 0 || A > 0 && B < 0) ans++;
    }
    cout << ans;
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