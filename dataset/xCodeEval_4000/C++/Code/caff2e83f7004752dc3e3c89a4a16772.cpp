


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
vi HashMod = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n, m, w, h; vi a, lazy, val;


void STBuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	

	if (st == en) {
		val[node] = a[st];
		return;
	}
	STBuild(node*2, st, (st+en)/2);
	STBuild(node*2+1, (st+en)/2+1, en);
	val[node] = max(val[node*2], val[node*2+1]);
}

void update(i64 node, i64 st, i64 en, i64 L, i64 R, i64 value) {
	if (st > en) return;
	if (lazy[node] != 0) {
		val[node] = max(val[node], lazy[node]);
		if (st != en) {
			lazy[node*2] = max(lazy[node*2], lazy[node]);
			lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
		}
		lazy[node] = 0;
	}
	if (en < L || R < st) return;
	if (L <= st && en <= R) {
		val[node] = max(val[node], value);
		if (st != en) {
			lazy[node*2] = max(lazy[node*2], value);
			lazy[node*2+1] = max(lazy[node*2+1], value);
		}
		return;
	}
	update(node*2, st, (st+en)/2, L, R, value);
	update(node*2+1, (st+en)/2+1, en, L, R, value);
	val[node] = max(val[node*2], val[node*2+1]);
}

i64 getMax(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en) return -LINF;
	if (lazy[node] != 0) {
		val[node] = max(val[node], lazy[node]);
		if (st != en) {
			lazy[node*2] = max(lazy[node*2], lazy[node]);
			lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
		}
		lazy[node] = 0;
	}
	if (en < L || R < st) return -LINF;
	if (L <= st && en <= R) return val[node];
	i64 p1 = getMax(node*2, st, (st+en)/2, L, R);
	i64 p2 = getMax(node*2+1, (st+en)/2+1, en, L, R);
	return max(p1, p2);
}


void VarInput() {
	

	cin >> n; a.rsz(n); lazy.rsz(4*n+4); val = lazy;
	for (i64 i=0; i<n; i++) cin >> a[i];
	STBuild(1, 0, n-1);
}

void ProSolve() {
	cin >> m;
	while (m--) {
		cin >> w >> h;
		i64 ground = getMax(1, 0, n-1, 0, w-1);
		update(1, 0, n-1, 0, w-1, ground+h);
		cout << ground << endl;
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
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}




