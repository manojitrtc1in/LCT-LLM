


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
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));


template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n, k, id, ans = 0, Rem = 0;
vi val; vb vis;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k; val.rsz(n); vis.rsz(n, false);
	for (i64 i=0; i<n; i++) {
		cin >> val[i]; Rem += val[i];
		if (i > 0) ans += val[i] * val[i-1];
		if (i == n-1) ans += val[0] * val[n-1];
	}
}

void ProSolve() {
	while (k--) {
		cin >> id; id--; i64 tmp = Rem; tmp -= val[id];
		if (id == 0) tmp -= (!vis[n-1]) ? val[n-1] : 0; else tmp -= (!vis[id-1]) ? val[id-1] : 0;
		if (id == n-1) tmp -= (!vis[0]) ? val[0] : 0; else tmp -= (!vis[id+1]) ? val[id+1] : 0;
		ans += val[id] * tmp; Rem -= val[id]; vis[id] = true;
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
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.\n";
			#endif
	return 0;
}




