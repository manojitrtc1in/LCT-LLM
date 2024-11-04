



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




const int maxn = 10000100;
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
#define SEGMENT_TREE_MAXN 200100
#define NODE_VAL_TYPE ll
#endif
struct SegmentNode{
	int be, en, mid;
	int left, right;
	treap all_val;
	ll inversion[2], cross_inversion[2];
};
struct SegmentTree{
	int l;
	SegmentNode tree[SEGMENT_TREE_MAXN * 30];

	inline int GetLeft(int no) {return tree[no].left;}
	inline int GetRight(int no) {return tree[no].right;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	int Build(int no, int l, int r, int* orig, int* weight){
		if(l == r - 1){
			tree[no].be = l; tree[no].en = r;
			tree[no].left = tree[no].right = -1;
			tree[no].all_val.insert(orig[l]);
			tree[no].inversion[0] = tree[no].inversion[1] = 0;
			return no;
		}
		int mid = l + 1;
		for (int i = l + 1; i < r; i++) {
			if (weight[i] < weight[mid]) mid = i;
		}
		int left = Build(no, l, mid, orig, weight);
		int right = Build(left + 1, mid, r, orig, weight);
		no = right + 1;
		tree[no].be = l; tree[no].en = r;
		tree[no].left = left;
		tree[no].right = right;
		tree[no].mid = mid;

		for (int i = l; i < r; i++) tree[no].all_val.insert(orig[i]);
		auto get_inversion = [&](const int from, const int to, treap& t) {
			ll ans = 0;
			for (int i = from; i < to; i++) {
				ans += t.getnotbig(orig[i] - 1);
			}
			return ans;
		};
		tree[no].inversion[0] = tree[no].inversion[1] =
				min(tree[GetLeft(no)].inversion[0], tree[GetLeft(no)].inversion[1]) +
				min(tree[GetRight(no)].inversion[0], tree[GetRight(no)].inversion[1]);
		tree[no].cross_inversion[0] = get_inversion(l, mid, tree[GetRight(no)].all_val);
		tree[no].cross_inversion[1] = get_inversion(mid, r, tree[GetLeft(no)].all_val);
		tree[no].inversion[0] += tree[no].cross_inversion[0];
		tree[no].inversion[1] += tree[no].cross_inversion[1];

		return no;
	}
	void Upd(int loc, int no, const int old_val, const int new_val){
		tree[no].all_val.del(old_val);
		tree[no].all_val.insert(new_val);
		if(tree[no].be == tree[no].en - 1){
			return;
		}
		int cate;
		SegmentNode* child;
		SegmentNode* other;
		if(loc < tree[no].mid) {
			cate = 0;
			child = &tree[GetLeft(no)];
			other = &tree[GetRight(no)];
		} else {
			cate = 1;
			child = &tree[GetRight(no)];
			other = &tree[GetLeft(no)];
		}
		Upd(loc, child - tree, old_val, new_val);
		tree[no].inversion[cate] = tree[no].inversion[1 - cate] =
				min(child->inversion[0], child->inversion[1]) +
				min(other->inversion[0], other->inversion[1]);
		tree[no].cross_inversion[cate] +=
				other->all_val.getnotbig(new_val - 1) - other->all_val.getnotbig(old_val - 1);
		tree[no].cross_inversion[1 - cate] -=
				other->all_val.getnotbig(new_val) - other->all_val.getnotbig(old_val);
		tree[no].inversion[0] += tree[no].cross_inversion[0];
		tree[no].inversion[1] += tree[no].cross_inversion[1];
	}
} sgt;

int orig[maxn], weight[maxn];
int n, nq;

int main() {




	ios_base::sync_with_stdio(0);
	#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
	#endif 


	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", orig + i);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", weight + i);
	}
	int root = sgt.Build(1, 0, n, orig, weight);
	scanf("%d", &nq);
	for (int i = 0; i < nq; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		if (a != b) {
			sgt.Upd(a, root, orig[a], orig[b]);
			sgt.Upd(b, root, orig[b], orig[a]);
			swap(orig[a], orig[b]);
		}
		printf("%I64d\n", min(sgt.tree[root].inversion[0], sgt.tree[root].inversion[1]));
	}

	return 0;
}

