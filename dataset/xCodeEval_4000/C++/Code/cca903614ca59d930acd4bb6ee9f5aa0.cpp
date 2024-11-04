



#define USETR1
#define CPPELEVEN
#define GPP




#if __cplusplus < 201500L
#include <bits/stdc++.h>
#else
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <cmath>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <tuple>
#endif

using namespace std;

#ifndef CPPELEVEN
#ifdef USETR1
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif

#ifdef USEPB_DS
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;
#endif

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 1 }, {
		1, 1 }, { 1, -1 }, { -1, -1 } };

template<class T> inline T abs1(T a) {
	return a < 0 ? -a : a;
}

#ifndef CPPELEVEN
template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T p) { return max1(max1(a, b), p); }
template <class T> inline T max1(T a, T b, T p, T d) { return max1(max1(a, b, p), d); }
template <class T> inline T max1(T a, T b, T p, T d, T e) { return max1(max1(a, b, p, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T p) { return min1(min1(a, b), p); }
template <class T> inline T min1(T a, T b, T p, T d) { return min1(min1(a, b, p), d); }
template <class T> inline T min1(T a, T b, T p, T d, T e) { return min1(min1(a, b, p, d), e); }
#else
template<typename t, typename t1>
t min1(t a, t1 b) {
	return a < b ? a : b;
}
template<typename t, typename ... arg>
t min1(t a, arg ... arr) {
	return min1(a, min1(arr...));
}
template<typename t, typename t1>
t max1(t a, t1 b) {
	return a > b ? a : b;
}
template<typename t, typename ... arg>
t max1(t a, arg ... arr) {
	return max1(a, max1(arr...));
}
#endif

inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps)
		return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template<typename t> inline int jud(t a, t b) {
	if (a < b) return -1;
	if (a == b) return 0;
	return 1;
}



template<typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if (na == 0) return 0;
	int be = 0, en = na - 1;
	if (*a <= *(a + na - 1)) {
		if (f_lb == 0)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != 1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != -1)
					en = mid;
				else
					be = mid + 1;
			}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if (f_lb)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != -1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != 1)
					en = mid;
				else
					be = mid + 1;
			}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template<class T> inline T lowb(T num) {
	return num & (-num);
}
#ifdef GPP
inline int bitnum(ui nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(int nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(ull nValue) {
	return __builtin_popcountll(nValue);
}
inline int bitnum(ll nValue) {
	return __builtin_popcountll(nValue);
}
inline int bitmaxl(ui a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int bitmaxl(ull a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}
inline int bitmaxl(ll a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}
#else
#endif

long long pow(long long n, long long m, long long mod = 0) {
	if (m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if (m & 1) {
			ans *= k;
			if (mod) ans %= mod;
		}
		k *= k;
		if (mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define  MOD 1000000007
template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod)
		a -= mod;
	while (a < 0)
		a += mod;
}
template<class t>
void output1(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		output1(arr[i]);
}




const int maxn = 110;
const int mod =  998244353;

bool can = 1;
struct Group {
	vector<vector<Group*>> links;
	bitset<maxn> unassigned, all;
} all_group[maxn * 100];
int lall_group = 1;

Group* NewGroup() {
	return all_group + lall_group++;
}

int n, m;
Group* top = all_group;


int Test(const bitset<maxn>& rb) {
	return bitnum(*(ull*)(&rb)) + bitnum(*((ull*)(&rb) + 1) & ((1ll << (maxn % 64)) - 1));
}

int GetTails(const vi& have) {
	if (have.size() == 1) {
		return have[0] == 1;
	}
	set<int> boundary;
	for (int i = 0; i < (int)have.size(); i++) {
		if (have[i] == 1) boundary.insert(i);
		if (i < (int)have.size() - 1) {
			if (have[i] == 0 && have[i + 1] != 0) {
				boundary.insert(i + 1);
			}
			if (have[i + 1] == 0 && have[i] != 0) {
				boundary.insert(i);
			}
		}
	}
	for (int i = 0; i < (int)have.size(); i++) {
		if (have[i] < have[0] && have[i] < have.back()) {
			return 3;
		}
	}
	return boundary.size();
}

vector<Group*> Split(const bitset<maxn>& rb, Group* g) {
	if ((g->all & rb) == g->all) {
		return {g};
	}

	vi tail, others;
	vector<vi> thave;
	set<Group*> need_recur;
	int cnt_tail = 0;
	for (int i = 0; i < (int)g->links.size(); i++) {
		vi have(g->links[i].size());
		int cross = 0;
		for (int j = 0; j < (int)g->links[i].size(); j++)  {
			if ((rb & g->links[i][j]->all) == g->links[i][j]->all) {
				have[j] = 2;
				cross = 1;
			} else if (Test(rb & g->links[i][j]->all)) {
				have[j] = 1;
				need_recur.insert(g->links[i][j]);
				cross = 1;
			} else {
				have[j] = 0;
			}
		}
		if (have.back() > *have.begin()) {
			reverse(have.begin(), have.end());
			reverse(g->links[i].begin(), g->links[i].end());
		}

		if (!cross) continue;
		cnt_tail += GetTails(have);
		if (have.back() != 2) {
			tail.push_back(i);
			thave.push_back(have);
		} else {
			others.push_back(i);
		}
	}
	if (cnt_tail > 2 || (int)need_recur.size() > 2) {
		can = 0;
		return {};
	}
	if (cnt_tail == 2 && (rb & g->all) != rb) {
		can = 0;
		return {};
	}
	if (cnt_tail == 2 && tail.size() == 1) {
		if (others.size() || Test(g->unassigned & rb)) {
			can = 0;
			return {};
		}
	}
	vector<Group*> new_link;
	auto push = [&](const int idx, int dual, const vi& have) {
		int meet_bound = 0;
		for (int j = 0; j < (int)g->links[idx].size(); j++) {
			if (need_recur.find(g->links[idx][j]) != need_recur.end()) {
				auto to_add = Split(rb, g->links[idx][j]);
				if (dual && !meet_bound) {
					reverse(to_add.begin(), to_add.end());
				}
				for (Group* rg : to_add) {
					new_link.push_back(rg);
				}
			} else {
				new_link.push_back(g->links[idx][j]);
			}
			meet_bound |= have[j] == 1;
			if (j) {
				meet_bound |= have[j] > have[j - 1];
			}
		}
	};
	Group* mid = NewGroup();
	mid->all = mid->unassigned = g->unassigned & rb;
	for (const int i : others) {
		mid->links.push_back(g->links[i]);
		for (Group* rg : g->links[i]) {
			mid->all |= rg->all;
		}
	}

	if (tail.size()) {
		push(tail[0], tail.size() == 1 && cnt_tail == 2, thave[0]);
		reverse(new_link.begin(), new_link.end());
	}
	if (Test(mid->all)) new_link.push_back(mid);
	if (tail.size() > 1) {
		push(tail[1], 0, thave[1]);
	}

	for (int i = g->links.size() - 1; i >= 0; i--) {
		bool rm = 0;
		for (const auto it : tail) if (it == i) rm = 1;
		for (const auto it : others) if (it == i) rm = 1;
		if (rm) g->links.erase(g->links.begin() + i);
	}
	g->unassigned ^= mid->unassigned;
	if ((rb & g->all) != rb) {
		for (Group* rg : new_link) {
			g->all ^= rg->all;
		}
		reverse(new_link.begin(), new_link.end());
		if (Test(g->all)) new_link.push_back(g);
		return new_link;
	} else {
		g->links.push_back(new_link);
		return {g};
	}

	return {};
}

ll fac[maxn];
ll GetAns(Group* g) {
	ll ans = fac[Test(g->unassigned) + g->links.size()];
	for (int i = 0; i < (int)g->links.size(); i++) {
		for (Group* rg : g->links[i]) {
			ans *= GetAns(rg);
			ans %= mod;
		}
		if (g->links[i].size() >= 2) {
			ans *= 2;
			ans %= mod;
		}
	}
	return ans;
}

void Debug(const Group* top) {
	printf("%d: ", top - all_group);
	printf("links:\n");
	for (const auto& it : top->links) {
		for (const auto* no : it) {
			printf("%d ", no - all_group);
		}
		puts("");
	}
	printf("unassigned:\n");
	for (int i = 0; i < n; i++) if (top->unassigned.test(i)) {
		printf("%d ", i + 1);
	}
	puts("");
	printf("all:\n");
	for (int i = 0; i < n; i++) if (top->all.test(i)) {
		printf("%d ", i + 1);
	}
	puts("");
	puts("");

	for (const auto& it : top->links) {
			for (const auto* no : it) {
				Debug(no);
			}
		}
}

int main() {




	ios_base::sync_with_stdio(0);
#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
#endif 



	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		top->unassigned.set(i, 1);
		top->all.set(i, 1);
	}
	vector<bitset<maxn>> all;
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		scanf("%d", &cnt);
		bitset<maxn> rb;
		rb.reset();
		for (int j = 0; j < cnt; j++) {
			int num;
			scanf("%d", &num);
			num--;
			rb.set(num, 1);
		}














		Split(rb, top);
		all.push_back(rb);

		if (!can) {


			break;
		}








	}























	fac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	if (!can) {
		puts("0");
		return 0;
	} else {
		printf("%I64d\n", GetAns(top));
	}

	return 0;
}
