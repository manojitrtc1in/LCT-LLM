


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
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace tr1;
using namespace __gnu_pbds;

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


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;

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
		cerr << arr[i].first << '|' << arr[i].second << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}







const int maxq = 5010;
const int maxn = 100100;
#ifndef N
#define N 200100
#endif
template <class t> struct segment_node{
	int be, en;
	t maxv, add, sum;
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
			tree[no].add = 0;
			if(a == NULL) tree[no].maxv = orig;
			else tree[no].maxv = a[l];
			tree[no].add = 0;
			tree[no].sum = tree[no].maxv;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].add = 0;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	inline void relax(int no) {
		int le = gleft(no), ri = gright(no);
		tree[le].add += tree[no].add;
		tree[le].sum += tree[no].add * (tree[le].en - tree[le].be + 1);
		tree[le].maxv += tree[no].add;
		tree[ri].add += tree[no].add;
		tree[ri].sum += tree[no].add * (tree[ri].en - tree[ri].be + 1);
		tree[ri].maxv += tree[no].add;
		tree[no].add = 0;
	}
	void down(int l, int r, int no, t ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
			tree[no].maxv += ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	t getmax(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].maxv;
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		t ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans = max(ans, getmax(l, r, gleft(no)));
		if(r >= mid + 1 && l <= tree[no].en) ans = max(ans, getmax(l, r, gright(no)));
		return ans;
	}

};
segment_tree <int> sgt;
struct q {
	int l, r, maxv, deep;
	double p;
} que[maxq];
vi son[maxq];
int arr[maxn], fa[maxq];
vector <pair <double, int> > dp[maxq];
int n, nq, be, en;

void dfs(int no, int deep = 0) {
	que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1);
	be = max(be, que[no].maxv);
	en = max(en, que[no].maxv + deep + 1);
	que[no].deep = deep;
	for(int i = 0; i < (int)son[no].size(); i++)
		dfs(son[no][i], deep + 1);
}

pair <double, int> operator + (const pair <double, int> &a, const pair <double, int> &b) {
	return mpr(a.first + b.first, a.second);
}
void dfsdp(int no) {
	dp[no].push_back(mpr(1, que[no].maxv));
	for(int i = 0; i < (int)son[no].size(); i++) {
		int rno = son[no][i];
		dfsdp(rno);
		vector <pair <double, int> > rdp, rdp1;
		double sum1 = dp[no][0].first, sum2 = dp[rno][0].first, p = que[rno].p;
		for(int link1 = 0, link2 = 0; link1 < (int)dp[no].size() || link2 < (int)dp[rno].size(); ) {
			rdp.push_back(mpr(sum1 * sum2 * (1 - p), max(dp[no][link1].second, dp[rno][link2].second)));
			if(link1 == (int)dp[no].size() - 1) {
				link2++;
				if(link2 == dp[rno].size()) break;
				sum2 += dp[rno][link2].first;
			} else if(link2 == (int)dp[rno].size() - 1) {
				link1++;
				sum1 += dp[no][link1].first;
			} else if(dp[no][link1 + 1].second > dp[rno][link2 + 1].second) {
				link2++;
				sum2 += dp[rno][link2].first;
			} else {
				link1++;
				sum1 += dp[no][link1].first;








			}
		}
		for(int i = (int)rdp.size() - 1; i > 0; i--)
			rdp[i].first -= rdp[i - 1].first;
		int rsz = 1;


		for(int i = 1; i < (int)rdp.size(); i++) {
			if(rdp[i].second == rdp[i - 1].second)
				rdp[rsz - 1].first += rdp[i].first;
			else rdp[rsz++] = rdp[i];
		}
		rdp.resize(rsz);










		sum1 = dp[no][0].first, sum2 = dp[rno][0].first;
		for(int link1 = 0, link2 = 0; link1 < (int)dp[no].size() || link2 < (int)dp[rno].size(); ) {
			if(sum1 * sum2 > eps)
				rdp1.push_back(mpr(sum1 * sum2 * p, max(dp[no][link1].second, dp[rno][link2].second + 1)));
			if(link1 == (int)dp[no].size() - 1) {
				link2++;
				if(link2 == dp[rno].size()) break;
				sum2 += dp[rno][link2].first;
			} else if(link2 == (int)dp[rno].size() - 1) {
				link1++;
				sum1 += dp[no][link1].first;
			} else if(dp[no][link1 + 1].second > dp[rno][link2 + 1].second + 1) {
				link2++;
				sum2 += dp[rno][link2].first;
			} else {
				link1++;
				sum1 += dp[no][link1].first;








			}
		}
		for(int i = (int)rdp1.size() - 1; i > 0; i--)
			rdp1[i].first -= rdp1[i - 1].first;
		rsz = 1;
		for(int i = 1; i < (int)rdp1.size(); i++) {
			if(rdp1[i].second == rdp1[i - 1].second)
				rdp1[rsz - 1].first += rdp1[i].first;
			else rdp1[rsz++] = rdp1[i];
		}
		rdp1.resize(rsz);










		dp[no].clear();
		for(int link1 = 0, link2 = 0; link1 < (int)rdp.size() || link2 < (int)rdp1.size(); ) {
			if(link2 == (int)rdp1.size()) {
				dp[no].push_back(rdp[link1]);
				link1++;
			} else if(link1 == (int)rdp.size()) {
				dp[no].push_back(rdp1[link2]);
				link2++;
			} else if(rdp[link1].second > rdp1[link2].second) {
				dp[no].push_back(rdp1[link2]);
				link2++;
			} else if(rdp[link1].second == rdp1[link2].second) {
				dp[no].push_back(rdp[link1] + rdp1[link2]);
				link2++; link1++;
			} else if(rdp[link1].second < rdp1[link2].second) {
				dp[no].push_back(rdp[link1]);
				link1++;
			}
		}













	}
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef debug 

	freopen("input.txt", "r", stdin);
	int __size__ = 256 << 20; 

	char *__p__ = (char*)malloc(__size__) + __size__;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	#endif 


	scanf("%d%d", &n, &nq);
	for(int i = 0; i < n; i++) scanf("%d", arr + i);
	for(int i = 0; i < nq; i++) {
		scanf("%d%d%lf", &que[i].l, &que[i].r, &que[i].p);
		que[i].l--;
		que[i].r--;
	}
	memset(fa, -1, sizeof(fa));
	for(int i = 0; i < nq; i++) {
		for(int j = 0; j < i; j++) if(j != i){
			if(que[j].r - que[j].l == que[i].r - que[i].l && que[j].r == que[i].r)
				fa[i] = j;
		}
		if(fa[i] != -1) continue;
		for(int j = 0; j < nq; j++) if(j != i) {
			if(que[j].r - que[j].l == que[i].r - que[i].l)
				continue;
			if(que[j].l <= que[i].l && que[j].r >= que[i].r) {
				if(fa[i] == -1) {
					fa[i] = j;
					continue;
				}
				if(que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l) {
					fa[i] = j;
					continue;
				}
			}
		}
	}
	for(int i = 0; i < nq; i++) {
		if(fa[i] != -1) son[fa[i]].push_back(i);
		else {
			fa[i] = nq;
			son[nq].push_back(i);
		}
	}
	que[nq].l = 0; que[nq].r = n - 1;
	sgt.build(1, 0, n - 1, 0, arr);

	dfs(nq);
	dfsdp(nq);
	double ans = 0;
	for(int i = 0; i < (int)dp[nq].size(); i++) {
		ans += dp[nq][i].first * dp[nq][i].second;
	}
	printf("%.10lf\n", ans);

    return 0;
}
