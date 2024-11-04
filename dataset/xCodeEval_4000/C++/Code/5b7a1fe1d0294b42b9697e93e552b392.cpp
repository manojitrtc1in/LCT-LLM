


#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

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
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
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
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
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










const int V = 201000;
const int maxn = V;
int id[V], pre[V], low[V], s[V], stop, cnt, scnt, depth[V], dfsCounter;
int thr[V];

int val[maxn];
int n, m, nq;
struct edge {
	int to, nxt;
} e[maxn], re[maxn];
int head[maxn], le, rhead[maxn], rle;
inline void addedge(int a, int b, edge *e, int *head, int &le) {
	e[le].to = b;
	e[le].nxt = head[a];
	head[a] = le++;
}
priority_queue <pii, vector <pii>, greater <pii> > pqbcc[maxn], *rpq;
void tarjan(int i, int fa = -1) {
	low[i] = pre[i] = dfsCounter ++;
	for(int j = head[i]; j != -1; j = e[j].nxt) if(e[j].to != fa){
		int to = e[j].to, ei = j / 2;
		if(pre[to] == -1) {
			depth[to] = depth[i] + 1;
			s[stop++] = ei;
			tarjan(to, i);
			low[i] = min(low[i], low[to]);
			if(pre[i] == 0 || low[to] >= pre[i]) {
				if(pre[i] != 0 || j >= 1)
					thr[i] = 0;
				while(stop) {
					int fi = s[stop - 1]; stop--;
					id[fi] = scnt;
					if(fi == ei) break;
				}
				++ scnt;
			}
		} else if(pre[to] < pre[i]){
			low[i] = min(low[i], pre[to]);
			s[stop++] = ei;
		}
	}
}
int range[maxn][2], loc[maxn], sz[maxn], hv[maxn], arr[maxn], larr, deep[maxn];
int fa[maxn], anc[maxn];
int ncut, cutno[maxn], trans[maxn];
void dfs(int no) {
	sz[no] = 1;
	hv[no] = -1;
	for(int i = rhead[no]; i != -1; i = re[i].nxt) if(re[i].to != fa[no]) {
		deep[re[i].to] = deep[no] + 1;
		fa[re[i].to] = no;
		dfs(re[i].to);
		sz[no] += sz[re[i].to];
		if(hv[no] == -1 || sz[hv[no]] < sz[re[i].to])
			hv[no] = re[i].to;
	}
}
void dfs1(int no) {
	range[no][0] = larr;
	loc[no] = larr;
	arr[larr++] = no;
	if(hv[no] != -1) {
		anc[hv[no]] = anc[no];
		dfs1(hv[no]);
	}
	for(int i = rhead[no]; i != -1; i = re[i].nxt) if(re[i].to != fa[no] && re[i].to != hv[no]) {
		anc[re[i].to] = re[i].to;
		dfs1(re[i].to);
	}
	range[no][1] = larr - 1;
}

#ifndef N
#define N 200100
#endif
template <class t> struct segment_node{
	int be, en;
	t minv;
};
template <class t> struct segment_tree{
	int l;
	segment_node <t> tree[N * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	void build(int no, int l, int r, t orig = 0, t *a = NULL){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			if(a == NULL) tree[no].minv = orig;
			else tree[no].minv = a[l];
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	void down(int loc, int no, t ranadd){
		assert(loc >= 0 && loc <= tree[1].en);
		if(loc <= tree[no].be && loc >= tree[no].en){
			tree[no].minv = ranadd;
			return;
		}
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(loc <= mid) down(loc, gleft(no), ranadd);
		else down(loc, gright(no), ranadd);
		tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	t getmin(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].minv;
		t ans = MOD;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans = min(ans, getmin(l, r, gleft(no)));
		if(r >= mid + 1 && l <= tree[no].en) ans = min(ans, getmin(l, r, gright(no)));
		return ans;
	}
};

segment_tree <int> sgt;

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef debug1 

	freopen("input.txt", "r", stdin);
	int __size__ = 256 << 20; 

	char *__p__ = (char*)malloc(__size__) + __size__;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	#endif 


	memset(head, -1, sizeof(head));
	memset(rhead, -1, sizeof(rhead));
	scanf("%d%d%d", &n, &m, &nq);
	for(int i = 0; i < n; i++) scanf("%d", val + i);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		addedge(a, b, e, head, le);
		addedge(b, a, e, head, le);
	}

	memset(pre, -1, sizeof(pre));
	stop = cnt = scnt = 0;
	for(int i = 0; i < n; i++) thr[i] = 1;
	tarjan(0);
	for(int i = 0; i < m; i++) {
		if(thr[e[i * 2].to])
			thr[e[i * 2].to] = id[i] + 1;
		if(thr[e[i * 2 + 1].to])
			thr[e[i * 2 + 1].to] = id[i] + 1;
	}
	for(int i = 0; i < n; i++) if(!thr[i]) {
		trans[i] = ncut;
		cutno[ncut++] = i;
	}
	for(int i = 0; i < ncut; i++) {
		set <int> s;
		for(int j = head[cutno[i]]; j != -1; j = e[j].nxt) {
			if(s.find(id[j / 2] + ncut) != s.end()) continue;
			s.insert(id[j / 2] + ncut);
			addedge(i, id[j / 2] + ncut, re, rhead, rle);
			addedge(id[j / 2] + ncut, i, re, rhead, rle);
		}
	}

	

	#ifdef debug 

	cerr << "id:" <<endl;
	for(int i = 0; i < m; i++) cerr << id[i] << ' ';
	cerr << endl << "thr:" << endl;
	for(int i = 0; i < n; i++) cerr << thr[i] << ' ';
	cerr << endl << endl;
	#endif 


	fa[0] = -1; anc[0] = 0;
	assert(rle == (ncut + scnt - 1) * 2);
	dfs(0);
	dfs1(0);

	for(int i = 0; i < n; i++) {
		if(thr[i]) pqbcc[thr[i] - 1].push(mpr(val[i], i));
		else {
			int rid = fa[trans[i]];
			if(rid < 0) continue;
			rid = rid - ncut;
			pqbcc[rid].push(mpr(val[i], i));
		}
	}
	

	#ifdef debug 

	for(int i = 0; i < ncut + scnt; i++) cerr << arr[i] << ' ';
	cerr << endl;
	cerr << "hv sz deep anc range" << endl;
	for(int i = 0; i < scnt + ncut; i++)
		cerr << hv[i] << ' ' << sz[i] << ' ' << deep[i] << ' ' << anc[i] << ' ' <<
		      range[i][0] << '|' << range[i][1] << endl;
	#endif 


	sgt.build(1, 0, ncut + scnt);
	for(int i = 0; i < ncut; i++)
		sgt.down(loc[i], 1, val[cutno[i]]);
	for(int j = 0; j < scnt; j++)
		sgt.down(loc[ncut + j], 1, pqbcc[j].top().first);

	for(int i = 0; i < nq; i++) {
		char cate[2];
		int a, b;
		scanf("%s%d%d", cate, &a, &b);
		if(cate[0] == 'A') {
			a--; b--;
			if(a == b) {
				printf("%d\n", val[a]);
				continue;
			}
			int ra = trans[a], rb = trans[b];
			int ans = MOD;
			if(thr[a]) ra = thr[a] - 1 + ncut;
			if(thr[b]) rb = thr[b] - 1 + ncut;
			while(anc[ra] != anc[rb]) {
				if(deep[anc[ra]] < deep[anc[rb]]) swap(ra, rb);
				int rno = anc[ra];
				ans = min(ans, sgt.getmin(loc[rno], loc[ra], 1));
				ra = fa[rno];
			}
			if(deep[ra] < deep[rb]) swap(ra, rb);
			ans = min(ans, sgt.getmin(loc[rb], loc[ra], 1));
			if(rb >= ncut) {
				int rfa = fa[rb];
				ans = min(ans, val[cutno[rfa]]);
			}
			printf("%d\n", ans);
		} else {
			a--;
			val[a] = b;
			if(thr[a]) {
				rpq = &pqbcc[thr[a] - 1];
				while(rpq->size() && val[rpq->top().second] != rpq->top().first)
					rpq->pop();
				rpq->push(mpr(val[a], a));
				sgt.down(loc[thr[a] - 1 + ncut], 1, rpq->top().first);
			}
			else {
				sgt.down(loc[trans[a]], 1, val[a]);
				int rid = fa[trans[a]];
				if(rid < 0) continue;
				rid -= ncut;
				rpq = &pqbcc[rid];
				while(rpq->size() && val[rpq->top().second] != rpq->top().first)
					rpq->pop();
				rpq->push(mpr(val[a], a));
				sgt.down(loc[rid + ncut], 1, rpq->top().first);
			}
		}
	}


    return 0;
}
