


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







i64 n; vi a;





void VarInput() {
	

	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void ProSolve() {
	i64 tmp = n; vi prm;
	for (i64 i=2; i<=sqrt(tmp); i++) {
		if (tmp % i == 0) {
			prm.pub(i);
			while (tmp % i == 0) tmp /= i;
		}
	}
	if (tmp != 1) prm.pub(tmp);
	if (n % 4 == 0) {
		for (i64 i=0; i<n/4; i++) {
			bool flag = true;
			for (i64 j=i; j<n; j+=n/4) {
				if (!a[j]) {flag = false; break;}
			}
			if (flag) {cout << "YES"; return;}
		}
	}
	for (i64 i=0; i<prm.size(); i++) {
		i64 x = prm[i];
		if (x < 3) continue;
		for (i64 j=0; j<n/x; j++) {
			bool flag = true;
			for (i64 z=j; z<n; z+=n/x) {
				if (!a[z]) {flag = false; break;}
			}
			if (flag) {cout << "YES"; return;}
		}
	}
	cout << "NO";
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




