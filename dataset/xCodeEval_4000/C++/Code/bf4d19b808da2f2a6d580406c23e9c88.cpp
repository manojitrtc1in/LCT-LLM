



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
#define SEGMENT_TREE_MAXN 100100
#define NODE_VAL_TYPE int
#endif
struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE minv[2][2][2][2];
	bool flip[2];
	union {
		struct {
			NODE_VAL_TYPE sum_b[2], sum_r[2];
		};
		NODE_VAL_TYPE sum[2][2];
	};
};
struct SegmentTree{
	int l, add_per_diff;
	SegmentNode tree[SEGMENT_TREE_MAXN * 4];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	SegmentTree() : l(0), add_per_diff(0) {}

	void InitMinvBySum(int no) {
		for (int flip0 = 0; flip0 < 2; flip0++) for (int flip1 = 0; flip1 < 2; flip1++) {
			for (int cate = 0; cate < 2; cate++) {
				tree[no].minv[flip0][flip1][cate][cate] =
						tree[no].sum[(1 - cate) ^ flip0][0] + tree[no].sum[(1 - cate) ^ flip1][1];
				tree[no].minv[flip0][flip1][cate][1 - cate] = 1 << 29;
			}
		}
	}

	void Build(int no, int l, int r, pii a[2][SEGMENT_TREE_MAXN]){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			for (int level = 0; level < 2; level++) {
				tree[no].flip[level] = 0;
				tree[no].sum_b[level] = a[level][l].first;
				tree[no].sum_r[level] = a[level][l].second;
			}
			InitMinvBySum(no);
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		Build(GetLeft(no), l, mid, a);
		Build(GetRight(no), mid + 1, r, a);
		tree[no].flip[0] = tree[no].flip[1] = 0;
		PushUp(no);
	}
	inline void PushUp(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		memset(tree[no].minv, 0x3f, sizeof(tree[no].minv));
		for (int flip0 = 0; flip0 < 2; flip0++) for (int flip1 = 0; flip1 < 2; flip1++)
			for (int from = 0; from < 2; from++) for (int mid1 = 0; mid1 < 2; mid1++)
				for (int mid2 = 0; mid2 < 2; mid2++) for (int to = 0; to < 2; to++) {
					tree[no].minv[flip0][flip1][from][to] = min(
							tree[no].minv[flip0][flip1][from][to],
							tree[le].minv[flip0 ^ tree[le].flip[0]][flip1 ^ tree[le].flip[1]][from][mid1] +
							tree[ri].minv[flip0 ^ tree[ri].flip[0]][flip1 ^ tree[ri].flip[1]][mid2][to] +
									(mid1 != mid2) * add_per_diff);
				}
		for (int cate = 0; cate < 2; cate++) for (int level = 0; level < 2; level++) {
			tree[no].sum[cate][level] =
					tree[le].sum[cate ^ tree[le].flip[level]][level] +
					tree[ri].sum[cate ^ tree[ri].flip[level]][level];
		}
 	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		if (tree[no].flip[0]) {
			for (int cate0 = 0; cate0 < 2; cate0++) for (int cate1 = 0; cate1 < 2; cate1++) {
				for (int flip1 = 0; flip1 < 2; flip1++) {
					swap(tree[no].minv[0][flip1][cate0][cate1],
							tree[no].minv[1][flip1][cate0][cate1]);
					swap(tree[no].sum[0][0], tree[le].sum[1][0]);
				}
			}
			tree[no].flip[0] = 0;
			tree[le].flip[0] ^= 1;
			tree[ri].flip[0] ^= 1;
		}
		if (tree[no].flip[1]) {
			for (int cate0 = 0; cate0 < 2; cate0++) for (int cate1 = 0; cate1 < 2; cate1++) {
				for (int flip0 = 0; flip0 < 2; flip0++) {
					swap(tree[no].minv[flip0][0][cate0][cate1],
							tree[no].minv[flip0][1][cate0][cate1]);
					swap(tree[no].sum[0][1], tree[le].sum[1][1]);
				}
			}
			tree[no].flip[1] = 0;
			tree[le].flip[1] ^= 1;
			tree[ri].flip[1] ^= 1;
		}
	}
	void Upd(int l, int r, int no, int level){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].flip[level] ^= 1;
			return;
		}
		if((tree[no].flip[0] | tree[no].flip[1]) && tree[no].be != tree[no].en) {
			PushDown(no);
		}
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) Upd(l, r, GetLeft(no), level);
		if(r >= mid + 1 && l <= tree[no].en) Upd(l, r, GetRight(no), level);
		PushUp(no);
	}
	void UpdTo(int loc, int no, pii a) {
		if (tree[no].be == tree[no].en) {
			tree[no].sum_b[0] = a.first;
			tree[no].sum_r[0] = a.second;
			tree[no].sum_b[1] = tree[no].sum_r[1] = 0;
			InitMinvBySum(no);
			return;
		}
		if((tree[no].flip[0] | tree[no].flip[1]) && tree[no].be != tree[no].en) {
			PushDown(no);
		}
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(loc <= mid) UpdTo(loc, GetLeft(no), a);
		else UpdTo(loc, GetRight(no), a);
		PushUp(no);
	}
	pii GetSum(int l, int r, int no, int level) {
		pii ans = {0, 0};
		if (l <= tree[no].be && r >= tree[no].en) {
			ans.first += tree[no].sum[0 ^ tree[no].flip[level]][level];
			ans.second += tree[no].sum[1 ^ tree[no].flip[level]][level];
			return ans;
		}
		if((tree[no].flip[0] | tree[no].flip[1]) && tree[no].be != tree[no].en) {
			PushDown(no);
		}
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) {
			pii temp = GetSum(l, r, GetLeft(no), level);
			ans.first += temp.first;
			ans.second += temp.second;
		}
		if(r >= mid + 1 && l <= tree[no].en) {
			pii temp = GetSum(l, r, GetRight(no), level);
			ans.first += temp.first;
			ans.second += temp.second;
		}
		return ans;
	}
};


const int maxn = SEGMENT_TREE_MAXN;
int n, m, q;
SegmentTree sgt[2];

int main() {




	ios_base::sync_with_stdio(0);
	#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
	#endif 


	scanf("%d%d%d", &n, &m, &q);
	sgt[0].add_per_diff = n;
	sgt[1].add_per_diff = m;
	for (int i = 1; i >= 0; i--) {
		char str[2][maxn];
		scanf("%s%s", str[0 ^ i], str[1 ^ i]);
		pii arr[2][maxn];
		int l = i == 1 ? n : m;
		for (int level = 0; level < 2; level++) for (int j = 0; j < l; j++) {
			arr[level][j + 1] = {0, 0};
			if (str[level][j] == 'B') arr[level][j + 1].first = 1;
			else arr[level][j + 1].second = 1;
		}
		sgt[i].Build(1, 0, l + 1, arr);
	}
	for (int i = 0; i < 2; i++) {
		int l = i == 1 ? n : m;
		int rl = n + m - l;
		sgt[i].UpdTo(0, 1, sgt[1 - i].GetSum(1, rl, 1, 1 - i));
		sgt[i].UpdTo(l + 1, 1, sgt[1 - i].GetSum(1, rl, 1, i));
	}
	int ans = 1 << 29;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		ans = min(ans, sgt[0].tree[1].minv[0][0][i][j]);
		ans = min(ans, sgt[1].tree[1].minv[0][0][i][j]);
	}
	printf("%d\n", ans);
	for (int i = 0; i < q; i++) {
		char str[2];
		int be, en, sgt_no, level, ridx;
		scanf("%s%d%d", str, &be, &en);
		switch (str[0]) {
		case 'L':
			sgt_no = 1;
			level = 1;
			ridx = 0;
			break;
		case 'R':
			sgt_no = 1;
			level = 0;
			ridx = m + 1;
			break;
		case 'U':
			sgt_no = 0;
			level = 0;
			ridx = 0;
			break;
		case 'D':
			sgt_no = 0;
			level = 1;
			ridx = n + 1;
			break;
		}
		int l = sgt_no == 0 ? m : n;
		sgt[sgt_no].Upd(be, en, 1, level);
		sgt[1 - sgt_no].UpdTo(ridx, 1, sgt[sgt_no].GetSum(1, l, 1, level));

		ans = 1 << 29;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
			ans = min(ans, sgt[0].tree[1].minv[0][0][i][j]);
			ans = min(ans, sgt[1].tree[1].minv[0][0][i][j]);
		}
		printf("%d\n", ans);
	}

	return 0;
}
