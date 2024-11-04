#define usepb_ds
#define usetr1







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

using namespace std;

#ifdef usetr1
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif

#ifdef usepb_ds
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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




const int V = 400100;
const int maxm = V;
const int maxn = V;
int cant[maxn];
struct edge {
	int to, nxt;
	int used;
} e[maxm];
int head[maxm], le;
inline void addedge(int a, int b) {
	e[le].to = b;
	e[le].nxt = head[a];
	head[a] = le++;
}



int id[V], pre[V], low[V], s[V], stop, cnt, scnt, dfsCounter;
int thr[V];
int cnts[V];

void tarjan(int i, int fa = -1) {
	low[i] = pre[i] = dfsCounter ++;
	for(int j = head[i]; j != -1; j = e[j].nxt) if(e[j].to != fa){
		if(cant[e[j].to]) continue;
		int to = e[j].to, ei = j / 2;
		if(pre[to] == -1) {
			s[stop++] = ei;
			tarjan(to, i);
			low[i] = min(low[i], low[to]);
			if(low[to] >= pre[i]) {
				if(pre[i] != 0 || j >= 1)
					thr[i] = 1;
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


int du[maxn], have[maxn], in[maxn];
int n, m;
vector <vi> ans;
int q[maxn];
pii fa[maxn];
pii del[maxn];
int ldel;
int rhave[maxn];
int realid;
set <int> cs[maxn];

int rdfs(int no, int deep) {
	if(have[no]) return -1;
	if(deep != 0 && du[no] >= 3)
		return no;
	have[no] = 1;
	for(int i = head[no]; i != -1; i = e[i].nxt) {
		if(id[i / 2] != realid) continue;
		int ans = rdfs(e[i].to, deep + 1);
		if(ans != -1) return ans;
	}
	return -1;
}

void bfsto(int be, int to, int flag = 0) {
	int lq = 0, rq = 0;
	memset(fa, -1, sizeof(fa));
	memset(rhave, 0, sizeof(rhave));
	rhave[be] = 1;
	q[rq++] = be;
	for(; lq != rq; lq++) {
		int no = q[lq];
		if(no == to) break;
		for(int i = head[no]; i != -1; i = e[i].nxt) {
			 if(cant[e[i].to] || rhave[e[i].to]) continue;
			 rhave[e[i].to] = 1;
			 fa[e[i].to] = mpr(no, i);
			 q[rq++] = e[i].to;
		}
	}
	ans.push_back(vi());
	for(int i = to; i != be; i = fa[i].first) {
		ans[ans.size() - 1].push_back(i);
		if(i != to && i != be) cant[i] = flag;
	}
	ans[ans.size() - 1].push_back(be);
	if(ans[ans.size() - 1].size() == 2 && flag) {
		del[ldel++] = mpr(be, to);
		for(int i = head[be], pre = -1; i != -1; pre = i, i = e[i].nxt){
			if(e[i].to == to) {
				if(pre == -1) head[be] = e[i].nxt;
				else e[pre].nxt = e[i].nxt;
			}
		}
		for(int i = head[to], pre = -1; i != -1; pre = i, i = e[i].nxt){
			if(e[i].to == be) {
				if(pre == -1) head[to] = e[i].nxt;
				else e[pre].nxt = e[i].nxt;
			}
		}
	}
}

bool dfs(int no, int to) {
	if(no == to)
		return 1;
	if(have[no]) return 0;
	have[no] = 1;
	bool flag = 0;
	for(int i = head[no]; i != -1; i = e[i].nxt) if(e[i].used == 0) {
		int cate = 0;
		if(in[e[i].to]) {
			cate = 1;
			for(int j = head[e[i].to]; j != -1; j = e[j].nxt) if(e[j].used)
				if(e[j].to != no)
					cate = -1;
		}

		if(cate == -1) {
			for(int j = head[e[i].to]; j != -1; j = e[j].nxt) if(e[j ^ 1].used){
				flag |= dfs(e[j].to, to);
				if(flag) {
					e[j ^ 1].used = 0;
					break;
				}
			}
		} else flag = dfs(e[i].to, to);
		if(flag) {
			if(e[i ^ 1].used) e[i ^ 1].used = 0;
			else e[i].used = 1;
			if(cate == 1) in[no] = 0;
			else in[no] = 1;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	#ifdef debug 

	freopen("input.txt", "r", stdin);
	int __size__ = 256 << 20; 

	char *__p__ = (char*)malloc(__size__) + __size__;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	#endif 


	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		addedge(a, b);
		addedge(b, a);
	}
	memset(pre, -1, sizeof(pre));
	stop = cnt = scnt = 0;
	for(int i = 0; i < n; i++) if(pre[i] == -1)
		tarjan(i);
	realid = -1;
	for(int i = 0; i < le; i += 2) {
		cs[id[i / 2]].insert(e[i].to);
		cs[id[i / 2]].insert(e[i + 1].to);
		cnts[id[i / 2]]++;
	}
	for(int i = 0; i < scnt; i++) {
		if(cs[i].size() < cnts[i]) {
			realid = i;
			break;
		}
	}
	if(realid == -1) {
		puts("NO");
		return 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = head[i]; j != -1; j = e[j].nxt) {
			if(id[j / 2] == realid)
				du[i]++;
		}
	}










	int be = -1, to = -1;
	for(int i = 0; i < n; i++) if(du[i] >= 3) {
		be = i;
		to = rdfs(be, 0);










		bfsto(be, to, 1);
		

		#ifdef debug 

		output2(ans);
		#endif 


		memset(pre, -1, sizeof(pre));
		stop = cnt = scnt = 0;
		for(int i = 0; i < n; i++) if(pre[i] == -1)
			tarjan(i);
		set <int> s;
		for(int j = head[to]; j != -1; j = e[j].nxt) if(!cant[e[j].to])
			s.insert(id[j / 2]);
		int rflag = -1;
		for(int j = head[be]; j != -1; j = e[j].nxt) if(!cant[e[j].to])
			if(s.find(id[j / 2]) != s.end())
				rflag = j / 2;

		if(rflag == -1) {
			bfsto(be, to, 0);
			int last = -1, rto = -1;
			for(int i = ans[1].size() - 1; i > 0; i--) {
				int no = ans[1][i], no1 = ans[1][i - 1];
				for(int j = head[no]; j != -1; j = e[j].nxt) if(e[j].to == no1){
					int p = id[j / 2];
					if(last != -1 && p != last) {
						rto = no;
						break;
					}
					last = p;
				}
				if(rto != -1) break;
			}
			to = rto;
		}
		break;
	}
	if(ldel) {
		addedge(del[0].first, del[0].second);
		addedge(del[0].second, del[0].first);
	}
	memset(have, 0, sizeof(have));
	in[be] = 0;
	assert(dfs(be, to) == 1);
	memset(have, 0, sizeof(have));


































	in[be] = 0;
	assert(dfs(be, to) == 1);
































	memset(have, 0, sizeof(have));
	in[be] = 0;
	assert(dfs(be, to) == 1);
	puts("YES");

	for(int i = head[be]; i != -1; i = e[i].nxt) if(e[i].used) {
		vi rans;
		rans.push_back(be);
		for(int j = e[i].to; ; ) {
			rans.push_back(j);
			if(j == to) break;
			for(int k = head[j]; k != -1; k = e[k].nxt)
				if(e[k].used){
					j = e[k].to;
					break;
				}
		}
		printf("%d ", rans.size());
		for(int j = 0; j < (int)rans.size(); j++) printf("%d ", rans[j] + 1);
		puts("");
	}

    return 0;
}

