


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







i64 n;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
}

void ProSolve() {
	if (n < 4) {cout << "NO"; return;}
	cout << "YES\n";
	if (n % 2 == 0) {
		cout << "4 * 3 = 12\n";
		cout << "12 * 2 = 24\n";
		cout << "24 * 1 = 24\n";
		i64 rem = n - 1 - 3;
		for (i64 i=6; i<=n; i+=2) {
			cout << i << " - " << i-1 << " = 1\n";
			rem--;
		}
		for (i64 i=1; i<rem; i++) cout << "1 * 1 = 1\n";
		if (rem != 0) cout << "24 * 1 = 24\n"; return;
	}
	else if (n % 2 != 0) {
		cout << "5 * 4 = 20\n";
		cout << "20 + 3 = 23\n";
		cout << "23 + 2 = 25\n";
		cout << "25 - 1 = 24\n";
		i64 rem = n - 1 - 4;
		for (i64 i=7; i<=n; i+=2) {
			cout << i << " - " << i-1 << " = 1\n";
			rem--;
		}
		for (i64 i=1; i<rem; i++) cout << "1 * 1 = 1\n";
		if (rem != 0) cout << "24 * 1 = 24\n"; return;
	}
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




