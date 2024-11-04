

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>
#include<cmath>
#include<set>
#include<cstring>
#include<string.h>
using namespace std;
typedef long long ll;
typedef long double lb;
const int inf = 0x3f3f3f3f;


#define int long long
#define double long double


#define file(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
#define rd(x) scanf("%lld", &x)
#define sdf(x) x=read()
#define asd(x) scanf("%Lf",&x)

#define For(i, a, b) for (int i = a; i <= b; i++)
#define FFor(i, a, b) for (int i = a; i >= b; i--)
#define me(a, b) memset(a, b, sizeof(a))
#define addmod(x, y) (x) = ((x) % mod + (y) % mod) % mod
#define mulmod(x, y) (x) = (((x) % mod) * ((y) % mod)) % mod
#define chkmin(x, y) (x) = (x) <= (y) ? (x) : (y)
#define chkmax(x, y) (x) = (x) >= (y) ? (x) : (y)
#define mid ((l + ((r - l)/2)))
#define Edge struct edge{int to, nx, w;}e[N << 1];int fi[N];int ce = 1;
#define star_link inline void add(int u, int v, int w){e[++ce] = (edge){v, fi[u], w};fi[u] = ce;}
#define Qmul inline ll qmul(ll x,ll y){ll ans=1;for(;y;y>>=1,mulmod(x,x))if(y&1)mulmod(ans,x);return ans;}
#define Go(u) for (int i = fi[u]; ~i; i = e[i].nx)
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
typedef pair<int, int> Pair;
#define cnm cout<<"d"
#define bg1(x) cout<<(#x)<<":"<<x<<" "<<endl
#define bg2(x,y) cout<<(#x)<<":"<<x<<" "<<(#y)<<":"<<y<<" "<<endl
#define bg3(x,y,z) cout<<(#x)<<":"<<x<<" "<<(#y)<<":"<<y<<" "<<(#z)<<":"<<z<<" "<<endl
#define bg4(x,y,z,w) cout<<(#x)<<":"<<x<<" "<<(#y)<<":"<<y<<" "<<(#z)<<":"<<z<<" "<<(#w)<<":"<<w<<" "<<endl
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define root 1, 1, n
const double eps = 1e-9;


ll mod = 998244353;
const int N = 2e6 + 5;


int n, m;
Edge;
star_link;
int son[N], sz[N], fa[N], top[N], tim = 0, tg[N], tr[N], id[N];

void dfs(int x) {
	son[x] = 0;
	sz[x] = 1;
	Go(x) {
		int y = e[i].to;
		if (fa[x] == y)continue;
		fa[y] = x;
		dfs(y);
		sz[x] += sz[y];
		if (sz[y] > sz[son[x]])son[x] = y;
	}
}
void getpos(int x, int tp) {
	top[x] = tp;
	id[x] = ++tim;
	if (son[x])getpos(son[x], tp);
	Go(x) {
		int y = e[i].to;
		if (y == fa[x] || y == son[x])continue;
		getpos(y, y);
	}
}
void wk(int rt, int k) {
	tg[rt] = tr[rt] = k;
}
void down(int p) {
	if (~tg[p]) {
		wk(p << 1, tg[p]), wk(p << 1 | 1, tg[p]);
		tg[p] = -1;
	}
}
void upd(int ql, int qr, int k, int p, int l, int r) {
	if (ql > r || l > qr)return;
	if (ql <= l && r <= qr) {
		tg[p] = tr[p] = k;
		return;
	}
	down(p);
	upd(ql, qr, k, lson), upd(ql, qr, k, rson);
}
int ask(int x, int p, int l, int r) {
	if (l == r)return tr[p];
	down(p);
	if (x <= mid)return ask(x, lson);
	else return ask(x, rson);
}
void clean(int x) {
	while (1 != top[x]) {
		upd(id[top[x]], id[x], 0, root);
		x = fa[top[x]];
	}
	upd(1, id[x], 0, root);
}
signed main()
{
#ifndef ONLINE_JUDGE
	file("test");
#endif
	me(fi, -1), me(tg, -1);
	sdf(n);
	int u, v;
	For(i, 1, n - 1) {
		sdf(u), sdf(v);
		add(u, v, 0), add(v, u, 0);
	}
	dfs(1);
	getpos(1, 1);
	sdf(m);
	int t, x;
	while (m--) {
		sdf(t), sdf(x);
		if (t == 1)upd(id[x], id[x] + sz[x] - 1, 1, root);
		else if (t == 2)clean(x);
		else printf("%lld\n", ask(id[x], root) );
	}
}





































































































































































































































































































































































































































































































































































































































































































