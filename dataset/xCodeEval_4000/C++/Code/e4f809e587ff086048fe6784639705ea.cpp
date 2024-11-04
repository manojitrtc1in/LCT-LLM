#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forall(it, x) for(auto it = (x).begin(); it != (x).end(); it++)
#define OUT(x) {cout << x; exit(0);}


#define ft first
#define sd second
#define pb(x) push_back(x)
#define pb2(x, y) push_back(x, y)
#define mp(x, y) make_pair(x, y)
#define fora0(ITER, LIMIT) for(int ITER = 0; ITER < LIMIT; ITER++)
#define fora1(ITER, LIMIT) for(int ITER = 1; ITER <= LIMIT; ITER++)
#define ford0(ITER, LIMIT) for(int ITER = LIMIT - 1; ITER >= 0; ITER--)
#define ford1(ITER, LIMIT) for(int ITER = LIMIT; ITER >= 1; ITER--)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "assert.h"
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <array>
#include <list>
#include <sstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace::std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

const int INF = numeric_limits<int>::max() / 10;
const ll INFn = numeric_limits<ll>::min();



void problem();

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef _DEBUG
	int tstn = 5;
	while (tstn--) {
#endif
		problem();
#ifdef _DEBUG
		cout << '\n';
	}
#endif
	return 0;
}

const ll mod = 1'000'000'000 + 7;
const ll p = 37;

ll bin_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	assert(b > 0);
	ll a2 = bin_pow(a, b / 2);
	a2 = (a2 * a2) % mod;
	if (b % 2 == 1) {
		return (a2 * a) % mod;
	}
	else {
		return a2;
	}
}

ll rev_mod(ll a) {
	assert(a > 0);
	return bin_pow(a, mod - 2);
}

vector<string> s;
//Prefix hashes
//vector<ll> ph;
vector<ll> pp;
vector<ll> pha;
vector<ll> phb;

ll revp = rev_mod(p);

//int m;
//int sind;
int sinda;
int sindb;
int ma;
int mb;
bool string_cmp(const int& a, const int& b) {
	if (ma == 1 && a == 0) {
		if (mb == 1 && b == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	if (mb == 1 && b == 0) {
		//ma > 1 || a != 0
		return false;
	}
	//length of common prefixes are counted correctly
	//on "ssshhhiiittt" (checked on sort comparations)

	//l - prefixes of length l are equal,
	//r - prefixes of length r are not equal
	//l, r - lengths of string
	int m = min(ma, mb);
	ll minlen;
	if (ma < mb) {
		minlen = (a != m ? m - 1 : m);
	}
	else if (ma == mb) {
		minlen = (a != m || b != m ? m - 1 : m);
	}
	else {
		minlen = (b != m ? m - 1 : m);
	}
	ll l = 0, r = minlen + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		ll hasha = -1;
		ll hashb = -1;
		if (mid > a) {
			hasha = pha[a];
			ll right = min(m, mid);
			ll rest = ((pha[right + 1] + mod - pha[a + 1]) * revp) % mod;
			hasha = (hasha + rest) % mod;
		}
		else {
			hasha = pha[mid];
		}
		if (mid > b) {
			hashb = phb[b];
			ll right = min(m, mid);
			ll rest = ((phb[right + 1] + mod - phb[b + 1]) * revp) % mod;
			hashb = (hashb + rest) % mod;
		}
		else {
			hashb = phb[mid];
		}
		if (hasha == hashb) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	//one is a prefix of another
	if (l == minlen) {
		int actual_a = ma + (a == ma ? 0 : -1);
		int actual_b = mb + (b == mb ? 0 : -1);
		if (actual_a < actual_b) {
			//a is a prefix of b and a != b
			return true;
		}
		else {
			return false;
		}
	}
	else {
		int a1 = (l >= a ? l + 1 : l);
		int b1 = (l >= b ? l + 1 : l);
		bool res = s[sinda][a1] < s[sindb][b1];
		return res;
	}
}

vector<int> sort_indexes(int s_index, vector<ll>& ph) {
	int sind = s_index;
	int m = s[sind].size();
	ph.assign(m + 1, 0);
	fora0(i, m) {
		ph[i + 1] = (ph[i] + (int(s[sind][i]) - int('a') + 1) * pp[i]) % mod;
	}
	vector<int> ind(m + 1, -1);
	fora0(i, m + 1) {
		ind[i] = i;
	}
	pha = ph;
	phb = ph;
	sinda = sindb = sind;
	ma = mb = m;
	sort(all(ind), string_cmp);
	return ind;
}

void count_pp() {
	pp.assign(1e6 + 100, 1);
	for (int i = 1; i < pp.size(); i++) {
		pp[i] = (pp[i - 1] * p) % mod;
	}
	return;
}

void problem() {
	int n;
	cin >> n;
	s.assign(n, string());
	fora0(i, n) {
		cin >> s[i];
	}
	count_pp();
	vector<vector<ll> > dp(n);
	dp[0].assign(s[0].size() + 1, 1);
	vector<ll> pref_hash_prev;
	vector<int> prev = sort_indexes(0, pref_hash_prev);
	for (int i = 1; i < n; i++) {
		dp[i].assign(s[i].size() + 1, 0);
		vector<ll> pref_hash_now;
		vector<int> now = sort_indexes(i, pref_hash_now);
		int ip = 0, in = 0;
		phb = pref_hash_prev;
		pha = pref_hash_now;
		sindb = i - 1;
		sinda = i;
		mb = s[i - 1].size();
		ma = s[i].size();
		ll sum = dp[i - 1][ip];
		for (int j = 0; j < dp[i].size(); j++) {
			while (true) {
				if (ip + 1 < dp[i - 1].size() && !string_cmp(now[j], prev[ip + 1])) {
					ip++;
					sum = (sum + dp[i - 1][ip]) % mod;
				}
				else {
					break;
				}
			}
			if (!string_cmp(now[j], prev[ip])) {
				dp[i][j] = sum;
			}
		}
		swap(now, prev);
		swap(pref_hash_prev, pref_hash_now);
	}
	ll ans = 0;
	fora0(i, dp.back().size()) {
		ans = (ans + dp.back()[i]) % mod;
	}
	cout << ans << '\n';
	return;
}


////v0.1 - working string indexes sorting
//#define all(x) (x).begin(), (x).end()
//#define rall(x) (x).rbegin(), (x).rend()
//#define forall(it, x) for(auto it = (x).begin(); it != (x).end(); it++)
//#define OUT(x) {cout << x; exit(0);}
////#define sz size()
//#define ft first
//#define sd second
//#define pb(x) push_back(x)
//#define pb2(x, y) push_back(x, y)
//#define mp(x, y) make_pair(x, y)
//#define fora0(ITER, LIMIT) for(int ITER = 0; ITER < LIMIT; ITER++)
//#define fora1(ITER, LIMIT) for(int ITER = 1; ITER <= LIMIT; ITER++)
//#define ford0(ITER, LIMIT) for(int ITER = LIMIT - 1; ITER >= 0; ITER--)
//#define ford1(ITER, LIMIT) for(int ITER = LIMIT; ITER >= 1; ITER--)
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <string>
//#include <iomanip>
//#include "assert.h"
//#include <stack>
//#include <queue>
//#include <set>
//#include <cstdio>
//#include <array>
//#include <list>
//#include <sstream>
//
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//
//using namespace::std;
//
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//typedef unsigned int uint;
//
//const int INF = numeric_limits<int>::max() / 10;
//const ll INFn = numeric_limits<ll>::min();
////const ll ll_INFn = numeric_limits<ll>::min() / 10;
//
//void problem();
//
//int main() {
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//#ifdef _DEBUG
//	int tstn = 1;
//	while (tstn--) {
//#endif
//		problem();
//#ifdef _DEBUG
//		cout << '\n';
//	}
//#endif
//	return 0;
//}
//
//ll mod = 1'000'000'000 + 7;












































































































































































































































































































































































































































































































































































































































































































