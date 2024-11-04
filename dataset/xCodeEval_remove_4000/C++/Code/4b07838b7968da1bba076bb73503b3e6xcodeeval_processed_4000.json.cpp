



















using namespace std;










std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 500000;
const int MAXQ = 500000;
const int MAXS = 4 * MAXN;
const int MAXLG = 18;

int n, m;
vector<int> adj[MAXN];
int nq;
int qa[MAXQ], qb[MAXQ];

int anspaid;
pair<int, int> ansav[2];

int par[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];
int pre[MAXN], lpre[MAXN], rpre[MAXN], npre;
int sz[MAXN], heavy[MAXN];

int qc[MAXQ];
int qcnt[MAXN]; 

int ecnt[MAXN]; 

int esum1[MAXN], esum2[MAXN];


void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	pre[npre] = at, lpre[at] = npre, ++npre;
	sz[at] = 1, heavy[at] = -1;
	for (int to : adj[at]) {
		if (par[to] != -2) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
	rpre[at] = npre - 1;
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
int calcup(int a, int nstep) {
	for (int k = MAXLG; k >= 0; --k) if (nstep & (1 << k)) a = up[a][k];
	return a;
}

void updans(int cur, int a, int b) {
	if (cur <= anspaid) return;
	anspaid = cur;
	if (ansav[0] != MP(a, b) && ansav[0] != MP(b, a)) ansav[1] = MP(a, b); else ansav[0] = MP(a, b);
}
void updans(int cur, int a, int b, int c, int d) {
	if (cur <= anspaid) return;
	anspaid = cur;
	ansav[0] = MP(a, b), ansav[1] = MP(c, d);
}

void id5() {
	REP(i, n) if (par[i] != -1 && ecnt[i] == 0) updans(qcnt[i], par[i], i);
}
void id0() {
	int best = -1, a = -1, b = -1;
	REP(i, n) if (par[i] != -1 && ecnt[i] == 0) {
		if (best != -1) updans(best + qcnt[i], a, b, par[i], i);
		if (qcnt[i] > best) best = qcnt[i], a = par[i], b = i;
	}
}
void id9() {
	REP(i, n) if (par[i] != -1 && ecnt[i] == 1) updans(qcnt[i], par[i], i, esum1[i], esum2[i]);

}
int mxdep;
int path[MAXN];
vector<int> qheavy[MAXN];
vector<int> qleaf[MAXN];
int edesc[MAXN];
int sval[MAXS], slazyval[MAXS], scnt[MAXS], slazycnt[MAXS], swho[MAXS];
pair<int, int> slazy[MAXS];
void id3(int x, int by) { sval[x] += by; slazyval[x] += by; }
void id4(int x, int by) { scnt[x] += by; slazycnt[x] += by; }
void spush(int x) {
	if (slazyval[x] != 0) id3(2 * x + 1, slazyval[x]), id3(2 * x + 2, slazyval[x]), slazyval[x] = 0;
	if (slazycnt[x] != 0) id4(2 * x + 1, slazycnt[x]), id4(2 * x + 2, slazycnt[x]), slazycnt[x] = 0;
}
void spull(int x) {
	sval[x] = sval[2 * x + 1], scnt[x] = scnt[2 * x + 1], swho[x] = swho[2 * x + 1];
	if (scnt[2 * x + 2] < scnt[x] || scnt[2 * x + 2] == scnt[x] && sval[2 * x + 2] > sval[x]) sval[x] = sval[2 * x + 2], scnt[x] = scnt[2 * x + 2], swho[x] = swho[2 * x + 2];
}
void sinit(int x, int l, int r) {
	slazyval[x] = slazycnt[x] = 0;
	if (l == r) {
		sval[x] = scnt[x] = 0, swho[x] = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	

	

	if (L <= l && r <= R) {
		id3(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
void sblock(int x, int l, int r, int L, int R, int BY) {
	

	

	if (L <= l && r <= R) {
		id4(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sblock(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) sblock(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
pair<pair<int, int>, int> sget(int x, int l, int r, int L, int R) { 

	pair<pair<int, int>, int> ret = MP(MP(INT_MIN, INT_MAX), -1);
	

	if (L <= l && r <= R) {
		ret = MP(MP(sval[x], scnt[x]), swho[x]);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) { pair<pair<int, int>, int> sub = sget(2 * x + 1, l, m, L, R); if (sub.first.second < ret.first.second || sub.first.second == ret.first.second && sub.first.first > ret.first.first) ret = sub; }
		if (m + 1 <= R) { pair<pair<int, int>, int> sub = sget(2 * x + 2, m + 1, r, L, R); if (sub.first.second < ret.first.second || sub.first.second == ret.first.second && sub.first.first > ret.first.first) ret = sub; }
	}
	return ret;
}
void id8(int at, int root, int delta) {
	for (int qtop : qleaf[at]) if (dep[qtop] < dep[root]) smod(0, 1, mxdep, dep[qtop] + 1, dep[at], delta);
	for (int to : adj[at]) {
		if (par[to] != at) continue;
		id8(to, root, delta);
	}
}
void id6(int at, int root, int delta) {
	for (int to : adj[at]) {
		if (par[at] == to) continue;
		if (par[to] == at) id6(to, root, delta);
		if (dep[to] < dep[root]) {
			if (dep[to] >= 1) sblock(0, 1, mxdep, 1, dep[to], -delta);
			sblock(0, 1, mxdep, dep[to] + 1, dep[root], +delta);
		}
	}
}
void id1(int at) {
	

	path[dep[at]] = at;
	if (dep[at] - 1 >= 1) {
		

		pair<pair<int, int>, int> cur = sget(0, 1, mxdep, 1, dep[at] - 1);
		if (cur.first.second == 0) updans(cur.first.first + qcnt[at], path[cur.second - 1], path[cur.second], par[at], at);
	}
	if (par[at] != -1) {
		smod(0, 1, mxdep, dep[at], dep[at], +qcnt[at]);
	}
	for (int qtop : qleaf[at]) {
		smod(0, 1, mxdep, dep[qtop] + 1, dep[at], +2);
	}
	
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		if (dep[to] >= dep[at]) continue;
		sblock(0, 1, mxdep, dep[to] + 1, dep[at], +1); 

		if (dep[to] >= 1) sblock(0, 1, mxdep, 1, dep[to], -1); 

	}
	for (int to : adj[at]) {
		if (par[to] != at) continue;
		if (to != heavy[at]) {
			id8(to, at, +2);
			id6(to, at, +1);
			

		}
	}
	if (heavy[at] != -1) {
		for (int qbot : qheavy[at]) smod(0, 1, mxdep, dep[at] + 1, dep[qbot], -2);
		if (dep[at] >= 1) sblock(0, 1, mxdep, 1, dep[at], +edesc[heavy[at]]); 

		id1(heavy[at]);
	}
	for (int to : adj[at]) {
		if (par[to] != at) continue;
		if (to == heavy[at]) continue;
		id8(to, to, -2);
		id6(to, at, -1);
		if (dep[at] >= 1) sblock(0, 1, mxdep, 1, dep[at], +edesc[to]); 

		id1(to);
	}
	for (int to : adj[at]) {
		if (par[to] != at) continue;
	}
	if (par[at] != -1) {
		smod(0, 1, mxdep, dep[at], dep[at], -qcnt[at]);
	}
	if (dep[at] >= 1) sblock(0, 1, mxdep, dep[at], dep[at], -ecnt[at]);
	path[dep[at]] = -1;
	

}
bool isanc(int a, int b) { return lpre[a] <= lpre[b] && rpre[b] <= rpre[a]; }
void id7() {
	

	

	

	

	

	

	

	

	

	

	mxdep = 0;
	REP(at, n) mxdep = max(mxdep, dep[at]);
	sinit(0, 1, mxdep);
	REP(at, n) edesc[at] = 0;
	REP(i, nq) {
		if (qa[i] != qc[i]) qleaf[qa[i]].PB(qc[i]);
		if (qb[i] != qc[i]) qleaf[qb[i]].PB(qc[i]);
		if (heavy[qc[i]] != -1 && isanc(heavy[qc[i]], qa[i])) qheavy[qc[i]].PB(qa[i]);
		if (heavy[qc[i]] != -1 && isanc(heavy[qc[i]], qb[i])) qheavy[qc[i]].PB(qb[i]);
	}
	REP(a, n) for (int b : adj[a]) { 
		assert(dep[a] != dep[b]); 
		if (dep[a] > dep[b]) continue; 
		if (a == par[b]) continue; 
		++edesc[calcup(b, dep[b] - dep[a] - 1)];
	}
	id1(0);
	REP(i, n) qheavy[i] = vector<int>(), qleaf[i] = vector<int>();
}

void solve() {
	REP(i, n) par[i] = -2;
	npre = 0;
	par[0] = -1;
	dfsinit(0);
	assert(npre == n);
	
	REP(i, nq) qc[i] = lca(qa[i], qb[i]);
	REP(i, n) qcnt[i] = 0;
	REP(i, nq) { int a = qa[i], b = qb[i], c = qc[i]; ++qcnt[a], ++qcnt[b], qcnt[c] -= 2; }
	for (int i = n - 1; i >= 0; --i) { int at = pre[i]; if (par[at] != -1) qcnt[par[at]] += qcnt[at]; }
	REP(i, n) ecnt[i] = esum1[i] = esum2[i] = 0;
	REP(a, n) for (int b : adj[a]) { assert(dep[a] != dep[b]); if (dep[a] > dep[b]) continue; if (a == par[b]) continue; assert(a == lca(a, b)); ++ecnt[b], --ecnt[a], esum1[b] ^= a, esum1[a] ^= a, esum2[b] ^= b, esum2[a] ^= b; }
	for (int i = n - 1; i >= 0; --i) { int at = pre[i]; if (par[at] != -1) ecnt[par[at]] += ecnt[at], esum1[par[at]] ^= esum1[at], esum2[par[at]] ^= esum2[at]; }

	int nonleaf = -1;
	REP(i, n) if (SZ(adj[i]) >= 2) { nonleaf = i; break; }
	assert(nonleaf != -1);
	anspaid = 0;
	ansav[0] = MP(nonleaf, adj[nonleaf][0]);
	ansav[1] = MP(nonleaf, adj[nonleaf][1]);
	id5();
	id0();
	id9();
	id7();
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	solve();
	printf("%d\n", anspaid);
	REP(i, 2) printf("%d %d\n", ansav[i].first + 1, ansav[i].second + 1);
	REP(i, n) adj[i] = vector<int>();
}

int calc(pair<int, int> x, pair<int, int> y) {
	int ret = 0;
	REP(i, nq) {
		vector<int> d(n, INT_MAX); deque<int> q;
		auto relax = [&](int to, int dst, bool lastcost) { if (dst >= d[to]) return; d[to] = dst; if (!lastcost) q.push_front(to); else q.push_back(to); };
		relax(qa[i], 0, false);
		while (!q.empty()) {
			int at = q.front(); q.pop_front();
			for (int to : adj[at]) {
				bool cost = MP(at, to) == x || MP(at, to) == y || MP(to, at) == x || MP(to, at) == y;
				relax(to, d[at] + (cost ? 1 : 0), cost);
			}
		}
		ret += d[qb[i]];
	}
	return ret;
}

int id2() {
	int ret = 0;
	vector<pair<int, int>> e;
	REP(at, n) for (int to : adj[at]) { if (at > to) continue; e.PB(MP(at, to)); }
	REPSZ(i, e) FORSZ(j, i + 1, e) { int cur = calc(e[i], e[j]); if (cur > ret) ret = cur; }
	return ret;
}

void stress() {
	std::mt19937 rnd(1231);
	int mxn = 10, mxq = 10;
	

	REP(rep, 1000000) {
		n = rnd() % (mxn - 3 + 1) + 3;
		m = rnd() % (min(n * (n - 1) / 2, 2 * n) - (n - 1) + 1) + (n - 1);
		set<pair<int, int>> seen;
		vector<pair<int, int>> e;
		while (true) {
			seen = set<pair<int, int>>(); e = vector<pair<int, int>>();
			REP(i, m) while (true) { int a = rnd() % n, b = rnd() % n; if (a == b || seen.count(MP(a, b)) || seen.count(MP(b, a))) continue; seen.insert(MP(a, b)); adj[a].PB(b); adj[b].PB(a); e.PB(MP(a, b)); break; }
			vector<bool> reach(n, false); queue<int> q;
			auto relax = [&](int to) { if (reach[to]) return; reach[to] = true; q.push(to); };
			relax(0);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				for (int to : adj[at]) relax(to);
			}
			bool ok = true; REP(i, n) if (!reach[i]) ok = false;
			if (ok) break;
			REP(i, n) adj[i] = vector<int>();
		}
		nq = rnd() % mxq + 1;
		REP(i, nq) while (true) { int a = rnd() % n, b = rnd() % n; if (a == b) continue; qa[i] = a, qb[i] = b; break; }
		solve();
		if (rep % 1000 == 999) printf(".");
		

		

		assert(ansav[0] != ansav[1] && MP(ansav[0].second, ansav[0].first) != ansav[1]);
		assert(seen.count(ansav[0]) || seen.count(MP(ansav[0].second, ansav[0].first)));
		assert(seen.count(ansav[1]) || seen.count(MP(ansav[1].second, ansav[1].first)));
		assert(calc(ansav[0], ansav[1]) == anspaid);
		int want = id2();
		

		assert(anspaid == want);
		REP(i, n) adj[i] = vector<int>();
	}

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	

	return 0;
}