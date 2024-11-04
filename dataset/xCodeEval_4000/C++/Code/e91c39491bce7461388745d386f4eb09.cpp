



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
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
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




const int maxn = 300100;

int arr[maxn];
int n, nq;
int dp[maxn];
int last[maxn];

#define treap_type int
struct treap_node {
	int left, right, sz, fa, ge;
	double prio;
	treap_type val;
};
treap_node treap_arr[maxn];
int treap_head = 0, maxl = 0;
int nxt[maxn];
struct treap {
	int sz, root;
	unsigned int prea, preb;

	treap() {
		srand(unsigned (time(NULL)));
		root = -1;
		sz = 0;
		prea = preb = 1;
	}
	inline double rannum() {
		prea = prea * rand() % 32761 + 1;
		preb = preb * rand() % 32761 + 1;
		return 1.0 * prea / preb;
	}
	

	treap_node * getrank(int ranrank, int no = -1) {
		if(no == -1) no = root;
		if(treap_arr[no].left != -1 && ranrank <= treap_arr[treap_arr[no].left].sz)
			return getrank(ranrank, treap_arr[no].left);
		if(treap_arr[no].left != -1) ranrank -= treap_arr[treap_arr[no].left].sz;
		ranrank -= treap_arr[no].ge;
		if(ranrank <= 0 || treap_arr[no].right == -1) return treap_arr + no;
		return getrank(ranrank, treap_arr[no].right);
	}
	int getnotbig(treap_type val, int no = -1) {
		if(sz == 0) return 0;
		if(no == -1) no = root;
		if(treap_arr[no].val == val) {
			if(treap_arr[no].left != -1) return treap_arr[no].ge + treap_arr[treap_arr[no].left].sz;
			return treap_arr[no].ge;
		}
		if(treap_arr[no].val > val) {
			if(treap_arr[no].left != -1) return getnotbig(val, treap_arr[no].left);
			return 0;
		}else {
			if(treap_arr[no].right != -1) return getnotbig(val, treap_arr[no].right) + treap_arr[no].sz - treap_arr[treap_arr[no].right].sz;
			return treap_arr[no].sz;
		}
	}
	inline void relaxfa(int no) {
		if(treap_arr[no].fa == -1) return;
		if(treap_arr[treap_arr[no].fa].val > treap_arr[no].val) treap_arr[treap_arr[no].fa].left = no;
		else treap_arr[treap_arr[no].fa].right = no;
	}
	inline void relax(int no) {
		treap_arr[no].sz = treap_arr[no].ge;
		if(treap_arr[no].left != -1) treap_arr[no].sz += treap_arr[treap_arr[no].left].sz;
		if(treap_arr[no].right != -1) treap_arr[no].sz += treap_arr[treap_arr[no].right].sz;
	}
	inline void relaxtofa(int no) {
		while(no != -1) {
			relax(no);
			root = no;
			no = treap_arr[no].fa;
		}
	}
	inline void right_rot(int no) {
		int fa = treap_arr[no].fa;
		treap_arr[no].fa = treap_arr[fa].fa;
		treap_arr[fa].left = treap_arr[no].right;
		if(treap_arr[no].right != -1) treap_arr[treap_arr[no].right].fa = fa;
		treap_arr[no].right = fa;
		treap_arr[fa].fa = no;
		relax(fa);
		relaxfa(no);
		relax(no);
	}
	inline void left_rot(int no) {
		int fa = treap_arr[no].fa;
		treap_arr[no].fa = treap_arr[fa].fa;
		treap_arr[fa].right = treap_arr[no].left;
		if(treap_arr[no].left != -1) treap_arr[treap_arr[no].left].fa = fa;
		treap_arr[no].left = fa;
		treap_arr[fa].fa = no;
		relax(fa);
		relaxfa(no);
		relax(no);
	}
	void insert(treap_type val) {
		int ranmaxl = maxl;
		sz++;
		treap_arr[treap_head].prio = rannum();
		treap_arr[treap_head].left = treap_arr[treap_head].right = treap_arr[treap_head].fa = -1;
		if(treap_head == maxl) {
			maxl++;
			nxt[treap_head] = maxl;
		}
		treap_arr[treap_head].val = val;
		if(sz == 1) {
			root = treap_head;
			treap_arr[treap_head].sz = 1;
			treap_arr[treap_head].ge = 1;
			treap_head = nxt[treap_head];
			return;
		}
		int no = root;
		while(no != -1) {
			if(treap_arr[no].val == treap_arr[treap_head].val) break;
			treap_arr[treap_head].fa = no;
			if(treap_arr[no].val < treap_arr[treap_head].val) no = treap_arr[no].right;
			else no = treap_arr[no].left;
		}
		if(no != -1) {
			treap_arr[no].ge++;
			maxl = ranmaxl;
			relaxtofa(no);
			return;
		}
		treap_arr[treap_head].ge = 1; treap_arr[treap_head].sz = 1;
		if(treap_arr[treap_head].val < treap_arr[treap_arr[treap_head].fa].val) treap_arr[treap_arr[treap_head].fa].left = treap_head;
		else treap_arr[treap_arr[treap_head].fa].right = treap_head;
		while(treap_arr[treap_head].fa != -1 && treap_arr[treap_head].prio > treap_arr[treap_arr[treap_head].fa].prio) {
			if(treap_arr[treap_head].val < treap_arr[treap_arr[treap_head].fa].val) right_rot(treap_head);
			else left_rot(treap_head);
		}
		if(treap_arr[treap_head].fa == -1) root = treap_head;
		relaxtofa(treap_head);
		treap_head = nxt[treap_head];
	}
	void del(treap_type val) {
		if(sz == 0) return;
		int no = root;
		while(no != -1) {
			if(treap_arr[no].val == val) break;
			if(treap_arr[no].val > val) no = treap_arr[no].left;
			else no = treap_arr[no].right;
		}
		if(no == -1) return;
		sz--;
		if(sz == 0) {
			nxt[root] = treap_head;
			treap_head = root;
			root = -1;
			sz = 0;
			return;
		}
		treap_arr[no].ge--;
		if(treap_arr[no].ge != 0){
			relaxtofa(no);
			return;
		}
		while(treap_arr[no].left != -1 || treap_arr[no].right != -1) {
			if(treap_arr[no].left == -1) left_rot(treap_arr[no].right);
			else {
				if(treap_arr[no].right == -1 || treap_arr[treap_arr[no].left].prio > treap_arr[treap_arr[no].right].prio) right_rot(treap_arr[no].left);
				else left_rot(treap_arr[no].right);
			}
		}
		int no1 = no;
		if(treap_arr[treap_arr[no].fa].left == no) treap_arr[treap_arr[no].fa].left = -1;
		else treap_arr[treap_arr[no].fa].right = -1;
		relaxtofa(treap_arr[no].fa);
		nxt[no1] = treap_head;
		treap_head = no1;
	}
};

#ifndef SEGMENT_TREE_MAXN
#define SEGMENT_TREE_MAXN 300100
#define NODE_VAL_TYPE int
#endif
struct SegmentNode{
	int be, en;
	vi t;
};
struct SegmentTree{
	int l;
	SegmentNode tree[SEGMENT_TREE_MAXN * 4];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	void Build(int no, int l, int r, NODE_VAL_TYPE orig = 0, NODE_VAL_TYPE *a = NULL){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			if(a == NULL) tree[no].t.push_back(orig);
			else tree[no].t.push_back(a[l]);
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		Build(GetLeft(no), l, mid, orig, a);
		Build(GetRight(no), mid + 1, r, orig, a);
		for (int i = l; i <= r; i++) {
			if (a) {
				tree[no].t.push_back(a[i]);
			} else {
				tree[no].t.push_back(0);
			}
		}
		sort(tree[no].t.begin(), tree[no].t.end());
		PushUp(no);
	}
	inline void PushUp(int no) {
	}
	inline void PushDown(int no) {
	}
	NODE_VAL_TYPE GetBigger(int l, int r, int no, int num){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].t.end() - upper_bound(tree[no].t.begin(), tree[no].t.end(), (num - 1));


		NODE_VAL_TYPE ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans += GetBigger(l, r, GetLeft(no), num);
		if(r >= mid + 1 && l <= tree[no].en) ans += GetBigger(l, r, GetRight(no), num);
		return ans;
	}
} sgt;

treap all;

int main() {




	ios_base::sync_with_stdio(0);
#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
#endif 


	scanf("%d%d", &n, &nq);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		arr[i]--;
	}
	memset(last, -1, sizeof(last));
	for (int i = 0; i < n; i++) {
		if (arr[i] == i) {
			dp[i] = i;
			all.insert(-i);
		} else if (arr[i] < i) {
			if (all.sz < i - arr[i]) dp[i] = -1;
			else dp[i] = -all.getrank(i - arr[i])->val;
			all.insert(-dp[i]);
		} else {
			dp[i] = -1;
		}
	}
	sgt.Build(1, 0, n - 1, 0, dp);

	for (int i = 0; i < nq; i++) {
		int pre, suf;
		scanf("%d%d", &pre, &suf);
		if (pre + suf >= n) {
			puts("0");
			continue;
		}
		int st = pre, en = n - suf - 1;
		printf("%d\n", sgt.GetBigger(st, en, 1, st));
	}

	return 0;
}
