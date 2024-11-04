#include<bits/stdc++.h>
using namespace std;
#define cl(a,b) memset(a,b,sizeof(a))
#define fastIO ios::sync_with_stdio(false);cin.tie(0);
#define ll  long long
#define pb push_back
#define gcd __gcd

const double EPS = 1e-8;
const int maxn = 1e6 + 1000;
const int inf  = 1 << 28;

int n, m;
struct Edge {
	int to, next;
} es[maxn << 1];
int head[maxn], tot;
void addEdge(int u, int v) {
	es[tot].to = v; es[tot].next = head[u]; head[u] = tot++;
}


int num[maxn], p[maxn], fp[maxn], fa[maxn], son[maxn], top[maxn], deep[maxn], pos;
void init() {
	tot = 0;
	pos = 1;
	cl(head, -1);
}
void dfs(int u, int pre, int d) {
	num[u] = 1;
	fa[u] = pre;
	son[u]=0;
	for (int i = head[u]; ~i; i = es[i].next) {
		int v = es[i].to;
		if (v != pre) {
			dfs(v, u, d + 1);
			num[u] += num[v];
			if (num[son[u]] < num[v])son[u] = v;
		}
	}
}
void getpos(int u, int sp) {
	top[u] = sp;
	p[u] = pos++;
	if (son[u])
	getpos(son[u], sp);
	for (int i = head[u]; ~i; i = es[i].next) {
		int v = es[i].to;
		if (v != fa[u] && v != son[u])getpos(v, v);
	}
}



int val[maxn << 2], tag[maxn << 2];
void pushdown(int rt) {
	if (~tag[rt]) {
		tag[rt << 1] = tag[rt << 1 | 1] = tag[rt];
		val[rt << 1] = val[rt << 1 | 1] = tag[rt];
		tag[rt] = -1;
	}
}
void build(int rt, int l, int r) {
	tag[rt] = -1; val[rt] = 0;
	if (l == r) {
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int l, int r, int x, int y, int v) {
	if(x>r||l>y)return;
	if (x <= l && r <= y) {
		tag[rt] = val[rt] = v;
		return ;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	update(rt << 1, l, mid, x, y, v);
	update(rt << 1 | 1, mid + 1, r, x, y, v);
}
int query(int rt, int l, int r, int k) {
	if (l == r)return val[rt];
	pushdown(rt);
	int mid = l + r >> 1;
	if (k <= mid)return query(rt << 1, l, mid, k);
	else return query(rt << 1 | 1, mid + 1, r, k);
}
void modify(int v) {
	while (top[1] != top[v]) {
		update(1, 1, pos - 1, p[top[v]], p[v], 0);
		v = fa[top[v]];
	}
	update(1, 1, pos - 1, 1, p[v], 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	init();
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		addEdge(u, v); addEdge(v, u);
	}
	dfs(1, 1, 0); getpos(1, 1);
	build(1, 1, pos - 1);

	scanf("%d", &m);
	while (m--) {
		int x, y; scanf("%d%d", &x, &y);
		if (x == 1) {
			update(1, 1, pos - 1, p[y], p[y] + num[y] - 1, 1);
		}
		else if (x == 2) {
			modify(y);
		}
		else {
			printf("%d\n", query(1, 1, pos - 1, p[y]));
		}
	}

}






































































































































































































































































































































































































































































































































































































































































































