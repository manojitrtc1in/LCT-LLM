#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

char buf[maxn];

int n, m, q, ans[maxn];
int l[maxn], e;
string s[maxn], rs[maxn];
int A1_indo[maxn], A1_indr[maxn];
int S1_indo[maxn], S1_indr[maxn];
int qu[maxn], qv[maxn], qk[maxn], qp[maxn], qs[maxn];

struct Edge {
	int v, c, x;
} E[maxn<<1];

inline void addEdge(int u, int v, int c) {
	E[e].v = v, E[e].x = l[u], E[e].c = c, l[u] = e++;
}

struct BIT {
	int *sum, sz;
	BIT(int s) {
		sz = s;
		sum = new int[s+1];
		for (int i = 0; i <= s; i++) sum[i] = 0;
	}
	int lowbit(int x) {return x & (-x);}
	void add(int p, int v) {
		if (!p) return;
		for (int i = p; i <= sz; i += lowbit(i))
			sum[i] += v;
	}
	int ask(int p) {
		if (!p) return 0;
		int ret = 0;
		for (int i = p; i; i -= lowbit(i))
			ret += sum[i];
		return ret;
	}
	int ask(int l, int r) {
		return ask(r) - ask(l-1);
	}
};

struct segTree {
	vector<int> sta[maxn*4*4];
	void upd(int L, int R, int x, int l, int r, int rt) {
		if (L <= l && r <= R) {
			sta[rt].push_back(x);
			return;
		}
		int m = (l + r) >> 1;
		if (L <= m) upd(L, R, x, l, m, rt<<1);
		if (R > m) upd(L, R, x, m+1, r, rt<<1|1);
	}
	void cl(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			sta[rt].pop_back();
			return;
		}
		int m = (l + r) >> 1;
		if (L <= m) cl(L, R, l, m, rt<<1);
		if (R > m) cl(L, R, m+1, r, rt<<1|1);
	}
	void upd(int l, int r, int v) {
		upd(l, r, v, 1, 400000, 1);
	}
	void cl(int l, int r) {
		cl(l, r, 1, 400000, 1);
	}
	int ask(int p, int l, int r, int rt) {
		int ret = 0;
		if (!sta[rt].empty()) ret = * sta[rt].rbegin();
		if (l == r) return ret;
		int m = (l + r) >> 1;
		if (p <= m) return max(ret, ask(p, l, m, rt<<1));
		else return max(ret, ask(p, m+1, r, rt<<1|1));
	}
	int ask(int p) {
		return ask(p, 1, 400000, 1);
	}
};

struct ACAuto {
	int ch[maxn*2][26], fail[maxn*2], dfn[maxn*2], sz[maxn*2], tot, tim;
	vector<int> son[maxn*2];
	void init() {tot = 1, tim = 0; memset(ch[1], 0, sizeof(ch[1]));}
	ACAuto() {init();}
	int newNode() {
		++ tot;
		memset(ch[tot], 0, sizeof(ch[tot]));
		return tot;
	}
	int addStr(string s) {
		int cur = 1;
		for (int i = 0; i < s.size(); i++) {
			int x = s[i] - 'a';
			if (!ch[cur][x]) ch[cur][x] = newNode();
			cur = ch[cur][x];
		}
		return cur;
	}
	void dfs(int u) {
		sz[u] = 1, dfn[u] = ++ tim;
		for (int i = 0; i < son[u].size(); i++) {
			int v = son[u][i];
			dfs(v);
			sz[u] += sz[v];
		}
	}
	void build() {
		for (int i = 1; i <= tot; i++) {fail[i] = 0; son[i].clear();}
		queue<int> Q;
		fail[1] = 1;
		for (int i = 0; i < 26; i++) {
			if (!ch[1][i]) ch[1][i] = 1;
			else {
				fail[ch[1][i]] = 1;
				Q.push(ch[1][i]);
			}
		}
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int i = 0; i < 26; i++) {
				if (!ch[u][i]) ch[u][i] = ch[fail[u]][i];
				else {
					fail[ch[u][i]] = ch[fail[u]][i];
					Q.push(ch[u][i]);
				}
			}
		}
		for (int i = 2; i <= tot; i++) son[fail[i]].push_back(i);
		dfs(1);
	}
} A1;

struct SAM {
	int ch[maxn*4][26], maxlen[maxn*4], par[maxn*4], tot, last;
	int dfn[maxn*4], sz[maxn*4], tim;
	vector<int> son[maxn*4];
	int newNode() {
		++ tot;
		maxlen[tot] = par[tot] = 0;
		memset(ch[tot], 0, sizeof(ch[tot]));
		return tot;
	}
	SAM() {tot = tim = 0; last = newNode();}
	void addchar(int c, int l) {
		if (ch[last][c] && maxlen[ch[last][c]] == l) {
			last = ch[last][c];
			return;
		}
		int np = newNode(); maxlen[np] = l;
		while (last && !ch[last][c]) {
			ch[last][c] = np;
			last = par[last];
		}
		if (!last) par[np] = 1;
		else {
			int q = ch[last][c];
			if (maxlen[q] == maxlen[last] + 1) {
				par[np] = q;
			} else {
				int nq = newNode();
				par[nq] = par[q];
				memcpy(ch[nq], ch[q], sizeof(ch[nq]));
				maxlen[nq] = maxlen[last] + 1;
				par[q] = par[np] = nq;
				while (last && ch[last][c] == q) {
					ch[last][c] = nq;
					last = par[last];
				}
			}
		}
		last = np;
	}
	int addStr(string s) {
		last = 1;
		for (int i = 0; i < s.size(); i++) {
			addchar(s[i] - 'a', i+1);
		}
		return last;
	}
	void dfs(int u) {
		sz[u] = 1, dfn[u] = ++ tim;
		for (int i = 0; i < son[u].size(); i++) {
			int v = son[u][i];
			dfs(v);
			sz[u] += sz[v];
		}
	}
	void build() {
		for (int i = 1; i <= tot; i++) son[i].clear();
		for (int i = 2; i <= tot; i++) son[par[i]].push_back(i);
		dfs(1);
	}
} S1;

namespace N_Q {
	int _len;
	vector<int> vi[maxn], vp[maxn], vs[maxn];
	ACAuto Ao, Ar;
	vector<int> t_vs[maxn], t_vi[maxn];
	BIT B2(maxn*2);
	

	void dfs(int u) {
		int tl = _len - (u - 1);
		B2.add(Ar.dfn[tl + 1], 1);
		B2.add(Ar.dfn[tl + 1] + Ar.sz[tl + 1], -1);
		for (int i = 0; i < t_vs[u].size(); i++) {
			ans[t_vi[u][i]] += B2.ask(Ar.dfn[t_vs[u][i] + 1]);
		}
		for (int i = 0; i < Ao.son[u].size(); i++) {
			int v = Ao.son[u][i];
			dfs(v);
		}
		B2.add(Ar.dfn[tl + 1], -1);
		B2.add(Ar.dfn[tl + 1] + Ar.sz[tl + 1], 1);
	}
	void _solve(int ind) {
		_len = int (s[ind].size());
		Ao.init(); Ar.init(); Ao.addStr(s[ind]); Ar.addStr(rs[ind]);
		Ao.build(); Ar.build();
		for (int i = 1; i <= s[ind].size()+1; i++) t_vs[i].clear(), t_vi[i].clear();
		for (int i = 0; i < vi[ind].size(); i++) t_vs[1 + vp[ind][i]].push_back(vs[ind][i]), t_vi[1 + vp[ind][i]].push_back(vi[ind][i]);
		dfs(1);
	}
	void solve() {
		for (int i = 1; i <= m; i++) _solve(i);
	}
}

namespace N_CC {
	segTree T;
	BIT B(2*maxn);
	int _ind[maxn];
	int vis[maxn], sz[maxn], mx[maxn], col[maxn], dep[maxn], sta[maxn], top;
	vector<int> vu[maxn], vv[maxn], delo[maxn], delr[maxn];
	void dfs1(int u, int f, vector<int> &nl) {
		nl.push_back(u); sz[u] = 1; mx[u] = 0;
		for (int p = l[u]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (v != f && !vis[v]) {
				dfs1(v, u, nl);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
		}
	}
	void dfs2(int u, int f) {
		sz[u] = 1;
		for (int p = l[u]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (v != f && !vis[v]) {
				dep[v] = dep[u] + 1;
				dfs2(v, u);
				sz[u] += sz[v];
			}
		}
	}
	void dfs3(int u, int f, int c) {
		col[u] = c;
		for (int p = l[u]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (v != f && !vis[v]) {
				dfs3(v, u, c);
			}
		}
	}
	void dfs4(int u, int f, int cA, int cS) {
		sta[++ top] = u;
		B.add(A1.dfn[cA], 1);
		if (cS) T.upd(S1.dfn[cS], S1.dfn[cS] + S1.sz[cS] - 1, dep[u]);
		for (int i = 0; i < vu[u].size(); i++) {
			int x = vu[u][i];
			

			if (dep[u] > s[qk[x]].size()) {
				ans[x] += B.ask(A1.dfn[A1_indr[qk[x]]] + A1.sz[A1_indr[qk[x]]] - 1) - B.ask(A1.dfn[A1_indr[qk[x]]] - 1);
				delr[sta[1+s[qk[x]].size()]].push_back(x);
			}
			

			qp[x] = T.ask(S1.dfn[S1_indr[qk[x]]]);
		}
		for (int i = 0; i < vv[u].size(); i++) {
			int x = vv[u][i];
			

			if (dep[u] > s[qk[x]].size()) {
				ans[x] += B.ask(A1.dfn[A1_indo[qk[x]]] + A1.sz[A1_indo[qk[x]]] - 1) - B.ask(A1.dfn[A1_indo[qk[x]]] - 1);
				delo[sta[1+s[qk[x]].size()]].push_back(x);
			}
			qs[x] = T.ask(S1.dfn[S1_indo[qk[x]]]);
		}
		for (int p = l[u]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (v != f && !vis[v]) {
				dfs4(v, u, A1.ch[cA][E[p].c], S1.ch[cS][E[p].c]);
			}
		}
		for (int i = 0; i < delr[u].size(); i++) {
			int x = delr[u][i];
			ans[x] -= B.ask(A1.dfn[A1_indr[qk[x]]] + A1.sz[A1_indr[qk[x]]] - 1) - B.ask(A1.dfn[A1_indr[qk[x]]] - 1);
		}
		for (int i = 0; i < delo[u].size(); i++) {
			int x = delo[u][i];
			ans[x] -= B.ask(A1.dfn[A1_indo[qk[x]]] + A1.sz[A1_indo[qk[x]]] - 1) - B.ask(A1.dfn[A1_indo[qk[x]]] - 1);
		}
		if (cS) T.cl(S1.dfn[cS], S1.dfn[cS] + S1.sz[cS] - 1);
		B.add(A1.dfn[cA], -1);
		-- top;
	}
	void __solve(int c, vector<int> nl, vector<int> cur) {
		for (int i = 0; i < nl.size(); i++) {
			int x = nl[i];
			vu[x].clear(); vv[x].clear();
			delo[x].clear(); delr[x].clear();
		}
		for (int i = 0; i < cur.size(); i++) {
			int x = cur[i];
			int u = qu[x], v = qv[x];
			vu[u].push_back(x), vv[v].push_back(x);
		}
		dfs4(c, 0, 1, 1);
		for (int i = 0; i < cur.size(); i++) {
			int x = cur[i];
			N_Q::vi[qk[x]].push_back(x);
			N_Q::vp[qk[x]].push_back(qp[x]);
			N_Q::vs[qk[x]].push_back(qs[x]);
		}
	}
	void _solve(int u, int s, vector<int> vq) {
		vector<int> nl;
		dfs1(u, 0, nl);
		int c = 0;
		for (int i = 0; i < nl.size(); i++) {
			int x = nl[i];
			mx[x] = max(mx[x], s - sz[x]);
			if (!c || mx[x] < mx[c]) c = x;
		}
		dep[c] = 0;
		dfs2(c, 0);
		col[c] = 0;
		for (int p = l[c]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (!vis[v]) {
				dfs3(v, c, v);
			}
		}
		vector<int> cv, cs;
		for (int p = l[c]; p >= 0; p = E[p].x) {
			int v = E[p].v;
			if (!vis[v]) {
				cv.push_back(v);
				cs.push_back(sz[v]);
				_ind[v] = (int) cv.size() - 1;
			}
		}
		vector<int> cur;
		vector<vector<int> > cq(cv.size(), vector<int>());
		for (int i = 0; i < vq.size(); i++) {
			int u = qu[vq[i]], v = qv[vq[i]];
			if (col[u] != col[v]) cur.push_back(vq[i]);
			else cq[_ind[col[u]]].push_back(vq[i]);
		}
		__solve(c, nl, cur);
		vis[c] = 1;
		for (int i = 0; i < cv.size(); i++) _solve(cv[i], cs[i], cq[i]);
	}
	void solve() {
		vector<int> vq;
		for (int i = 1; i <= q; i++) vq.push_back(i);
		_solve(1, n, vq);
	}
}

int main() {
	memset(l, -1, sizeof(l));
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d%s", &u, &v, buf);
		addEdge(u, v, buf[0] - 'a'), addEdge(v, u, buf[0] - 'a');
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s", buf);
		s[i] = rs[i] = buf;
		reverse(rs[i].begin(), rs[i].end());
		A1_indo[i] = A1.addStr(s[i]); A1_indr[i] = A1.addStr(rs[i]);
		S1_indo[i] = S1.addStr(s[i]); S1_indr[i] = S1.addStr(rs[i]);
	}
	A1.build(), S1.build();
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d", &qu[i], &qv[i], &qk[i]);
	}
	N_CC::solve();
	N_Q::solve();
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}