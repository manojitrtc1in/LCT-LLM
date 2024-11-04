



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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

#ifndef CPPELEVEN
template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
#else
template <typename t, typename t1>
t min1(t a, t1 b) { return a < b ? a : b; }
template <typename t, typename... arg>
t min1(t a, arg... arr) { return min1(a, min1(arr...)); }
template <typename t, typename t1>
t max1(t a, t1 b) { return a > b ? a : b; }
template <typename t, typename... arg>
t max1(t a, arg... arr) { return max1(a, max1(arr...)); }
#endif

inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps) return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b) {
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if(na == 0) return 0;
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)) {
		if(f_lb == 0) while(be < en) {
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		} else while(be < en) {
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while (be < en) {
			int mid = (be + en + 1) / 2;
			if (jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		} else while (be < en) {
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
#ifdef GPP
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcountll(nValue); }
inline int bitnum(ll nValue) { return __builtin_popcountll(nValue); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { if(a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int bitmaxl(ll a) { if(a == 0) return 0; return 64 - __builtin_clzll(a); }
#else
#endif

long long pow(long long n, long long m, long long mod = 0) {
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define  MOD 1000000007
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if(mod == -1) mod = MOD;
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}




#ifndef SEGMENT_TREE_MAXN
#define SEGMENT_TREE_MAXN 200100
#define NODE_VAL_TYPE int
#endif
struct SegmentNode{
	int be, en;
	SegmentNode* left;
	SegmentNode* right;
	NODE_VAL_TYPE minv, add, cnt_minv;
};
struct SegmentTree{
	int used;
	SegmentNode tree[SEGMENT_TREE_MAXN * 40];

	inline SegmentTree(){ used = 0; }
	inline SegmentNode* GetNewNode(
			int l, int r,
			SegmentNode* left = nullptr,
			SegmentNode* right = nullptr) {
		tree[used].be = l;
		tree[used].en = r;
		tree[used].left = left;
		tree[used].right = right;
		tree[used].minv = tree[used].add = 0;
		tree[used].cnt_minv = r - l + 1;
		return tree + used++;
	}
	inline SegmentNode* GetNewNode(SegmentNode* old) {
		tree[used] = *old;
		return tree + used++;
	}
	inline void RevertTo(int old_used) {
		used = old_used;
	}

	SegmentNode* Build(int l, int r){
		if(l > r) r = l;
		if(l == r){
			return GetNewNode(l, l);
		}
		int mid = (l + r) / 2;
		return GetNewNode(
				l, r, Build(l, mid), Build(mid + 1, r));
	}
	inline SegmentNode* PushUp(SegmentNode* no) {
		SegmentNode* left = no->left;
		SegmentNode* right = no->right;
		no->minv = min(left->minv, right->minv);
		no->cnt_minv = 0;
		if (no->minv == left->minv) {
			no->cnt_minv += left->cnt_minv;
		}
		if (no->minv == right->minv) {
			no->cnt_minv += right->cnt_minv;
		}
		return no;
	}
	inline void PushDown(SegmentNode* no) {
		SegmentNode* left = GetNewNode(no->left);
		SegmentNode* right = GetNewNode(no->right);
		left->add += no->add;
		left->minv += no->add;
		right->add += no->add;
		right->minv += no->add;
		no->add = 0;
		no->left = left;
		no->right = right;
	}
	SegmentNode* Upd(int l, int r, SegmentNode* no, NODE_VAL_TYPE ranadd){
		if(l <= no->be && r >= no->en) {
			SegmentNode* new_no = GetNewNode(no);
			new_no->add += ranadd;
			new_no->minv += ranadd;
			return new_no;
		}
		no = GetNewNode(no);
		if(no->add && no->be != no->en) PushDown(no);
		if(r >= no->be && l <= no->left->en) {
			no->left = Upd(l, r, no->left, ranadd);
		}
		if(r >= no->right->be && l <= no->en) {
			no->right = Upd(l, r, no->right, ranadd);
		}
		PushUp(no);

		return no;
	}






















} sgt;

const int maxn = SEGMENT_TREE_MAXN;
map<char, pii> dir = map<char, pii>{
		{'U', {1, 0}},
		{'D', {-1, 0}},
		{'L', {0, 1}},
		{'R', {0, -1}}
};
int n, m;
vs mp;
int fa[maxn], anc[maxn];
vi e[maxn];
int arr[maxn], larr;
pii range[maxn];
SegmentNode* root[maxn];

bool In(const pii& co) {
	return co.first < n && co.first >= 0 &&
			co.second < m && co.second >= 0;
}
int Idx(const pii& co) {
	return co.first * m + co.second;
}
int GetZeroCnt(SegmentNode* no) {
	if (no->minv != 0) return 0;
	return no->cnt_minv;
}
void DfsInit(int no, int ranc) {
	anc[no] = ranc;
	range[no].first = larr;
	arr[larr++] = no;
	for (const auto nxt : e[no]) {
		DfsInit(nxt, ranc);
	}
	range[no].second = larr - 1;
}
map<pii, vector<pii>> all_tree_pairs;
pair<int, pair<SegmentNode*, int>> st[maxn];
int lst;

int main() {




	ios_base::sync_with_stdio(0);
	#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
	#endif 


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		mp.push_back(std::move(str));
	}

	memset(fa, -1, sizeof(fa));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		pii rfa = mpr(i + 2 * dir[mp[i][j]].first, j + 2 * dir[mp[i][j]].second);
		if (!In(rfa)) continue;
		fa[Idx({i, j})] = Idx(rfa);
		e[Idx(rfa)].push_back(Idx({i, j}));
	}

	larr = 0;
	for (int i = 0; i < n * m; i++) if (fa[i] == -1) {
		DfsInit(i, i);
		root[i] = sgt.Build(range[i].first, range[i].second);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		pii other = mpr(i + dir[mp[i][j]].first, j + dir[mp[i][j]].second);
		int idx_no = Idx({i, j});
		int idx_other = Idx(other);
		if (idx_other < idx_no) continue;
		int anc_no = anc[idx_no], anc_other = anc[idx_other];
		if (anc_no > anc_other) {
			swap(anc_no, anc_other);
			swap(idx_no, idx_other);
		}
		all_tree_pairs[{anc_no, anc_other}].push_back({idx_no, idx_other});
	}

	ll ans = 0;
	for (auto& one_tree_pair : all_tree_pairs) {
		auto& node_pairs = one_tree_pair.second;
		auto anc1 = one_tree_pair.first.first, anc2 = one_tree_pair.first.second;
		sort(node_pairs.begin(), node_pairs.end(), [&](const pii& a, const pii& b) {
			return range[a.first].first < range[b.first].first;
		});
		lst = 0;
		st[lst++] = mpr(anc1, mpr(root[anc2], sgt.used));
		for (const auto& node_pair : node_pairs) {
			int no1 = node_pair.first;
			int no2 = node_pair.second;
			while (range[st[lst - 1].first].second < range[no1].first) {
				lst--;
				sgt.RevertTo(st[lst].second.second);
			}
			SegmentNode* new_root =
					sgt.Upd(range[no2].first, range[no2].second, st[lst - 1].second.first, 1);
			ans += 1ll * (range[no1].second - range[no1].first + 1) *
					(GetZeroCnt(st[lst - 1].second.first) - GetZeroCnt(new_root));
			st[lst++] = mpr(no1, mpr(new_root, sgt.used));
		}
		sgt.RevertTo(st[0].second.second);
	}

	cout << ans << endl;

	return 0;
}
