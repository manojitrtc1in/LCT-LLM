


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







i64 n; string s;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> s;
}

void ProSolve() {
	string sb = s, sr = s; sb[0] = 'b'; sr[0] = 'r';
	for (i64 i=1; i<n; i++) {
		if (sb[i-1] == 'b') sb[i] = 'r'; else sb[i] = 'b';
		if (sr[i-1] == 'b') sr[i] = 'r'; else sr[i] = 'b';
	}
	set<i64> be, bo, re, ro;
	for (i64 i=0; i<n; i++) {
		if (s[i] == 'b' && i % 2 == 0) be.insert(i);
		if (s[i] == 'b' && i % 2 != 0) bo.insert(i);
		if (s[i] == 'r' && i % 2 == 0) re.insert(i);
		if (s[i] == 'r' && i % 2 != 0) ro.insert(i);
	}
	i64 ab = 0, ar = 0; string ss = s;
	for (i64 i=0; i<n; i++) {
		if (ss[i] != sb[i]) {
			if (i == n-1) ab++;
			else if (i % 2 == 0) {
				if (sb[i] == 'b' && bo.upper_bound(i) != bo.end()) {
					ab++; swap(ss[i], ss[*bo.upper_bound(i)]);
					bo.erase(bo.upper_bound(i));
				}
				else if (sb[i] == 'r' && ro.upper_bound(i) != ro.end()) {
					ab++; swap(ss[i], ss[*ro.upper_bound(i)]);
					ro.erase(ro.upper_bound(i));
				}
				else ab++;
			}
			else {
				if (sb[i] == 'b' && be.upper_bound(i) != be.end()) {
					ab++; swap(ss[i], ss[*be.upper_bound(i)]);
					be.erase(be.upper_bound(i));
				}
				else if (sb[i] == 'r' && re.upper_bound(i) != re.end()) {
					ab++; swap(ss[i], ss[*re.upper_bound(i)]);
					re.erase(re.upper_bound(i));
				}
				else ab++;
			}
		}
	}
	ss = s; be.clear(); bo.clear(); re.clear(); ro.clear();
	for (i64 i=0; i<n; i++) {
		if (s[i] == 'b' && i % 2 == 0) be.insert(i);
		if (s[i] == 'b' && i % 2 != 0) bo.insert(i);
		if (s[i] == 'r' && i % 2 == 0) re.insert(i);
		if (s[i] == 'r' && i % 2 != 0) ro.insert(i);
	}
	for (i64 i=0; i<n; i++) {
		if (ss[i] != sr[i]) {
			if (i == n-1) ar++;
			else if (i % 2 == 0) {
				if (sr[i] == 'b' && bo.upper_bound(i) != bo.end()) {
					ar++; swap(ss[i], ss[*bo.upper_bound(i)]);
					bo.erase(bo.upper_bound(i));
				}
				else if (sr[i] == 'r' && ro.upper_bound(i) != ro.end()) {
					ar++; swap(ss[i], ss[*ro.upper_bound(i)]);
					ro.erase(ro.upper_bound(i));
				}
				else ar++;
			}
			else {
				if (sr[i] == 'b' && be.upper_bound(i) != be.end()) {
					ar++; swap(ss[i], ss[*be.upper_bound(i)]);
					be.erase(be.upper_bound(i));
				}
				else if (sr[i] == 'r' && re.upper_bound(i) != re.end()) {
					ar++; swap(ss[i], ss[*re.upper_bound(i)]);
					re.erase(re.upper_bound(i));
				}
				else ar++;
			}
		}
	}
	cout << min(ab, ar);
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



