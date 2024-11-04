


#pragma comment(linker, "/stack:200000000")
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







i64 n, m; vi a; map<i64, i64> Map;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m; a.rsz(n);
	for (i64 i=0; i<n; i++) {cin >> a[i]; Map[a[i]]++;}
}

void ProSolve() {
	i64 optimal = n / m, change = 0;
	vector<pii> x; for (i64 i=0; i<n; i++) x.pub(mp(a[i], i));
	sort(x.begin(), x.end(), greater<pii>()); i64 i = 0, curr = 1;
	for (; curr <= m; curr++) {
		if (Map.find(curr) == Map.end()) break;
		if (Map[curr] < optimal) break;
	}
	while (curr <= m && i < n) {
		if (x[i].fi <= m) {i++; continue;}
		Map[x[i].fi]--; if (Map[x[i].fi] == 0) Map.erase(x[i].fi); a[x[i].se] = curr; change++;
		Map[curr]++; while (curr <= m && Map.find(curr) != Map.end() && Map[curr] >= optimal) curr++; i++;
	}
	i = 0;
	while (curr <= m && i < n) {
		if (Map[a[i]] <= optimal) {i++; continue;}
		Map[a[i]]--; a[i] = curr; change++; Map[curr]++;
		while (curr <= m && Map.find(curr) != Map.end() && Map[curr] >= optimal) curr++; i++;
	}
	cout << optimal << " " << change << endl;
	for (i64 z=0; z<n; z++) cout << a[z] << " ";
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



