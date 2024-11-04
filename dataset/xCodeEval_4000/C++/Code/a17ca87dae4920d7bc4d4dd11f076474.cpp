#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }


struct ImplicitTarjan {
	int n;
	int(*unmarkedadj)(int);
	void(*mark)(int, int);
	int(*minmarkedadj)(int);
	void(*kill)(int, int);
	void init(int _n) { n = _n; }

	vector<int> comp; int ncomp;
	vector<int> id, low; int nid;
	vector<int> stck; int nstck;
	vector<vector<int>> compnodes;

	void tarjan(int at) {
		id[at] = low[at] = nid++; stck[nstck++] = at; mark(at, id[at]);
		while (true) {
			int to = unmarkedadj(at);
			

			if (to == -1) break;
			tarjan(to);
			low[at] = min(low[at], low[to]);
		}
		low[at] = min(low[at], minmarkedadj(at));
		

		if (low[at] == id[at]) {
			compnodes.push_back(vector<int>());
			while (comp[at] == -1) {
				int cur = stck[--nstck];
				comp[cur] = ncomp; kill(cur, id[cur]); compnodes[ncomp].PB(cur);
			}
			++ncomp;
		}
	}

	void calc() {
		ncomp = nid = nstck = 0; comp = id = low = stck = vector<int>(n, -1); compnodes.clear();
		REP(i, n) if (id[i] == -1) tarjan(i);
	}
};

struct HLD {
	int n;
	vector<vector<int>> adj;
	void init(int _n) { n = _n; adj = vector<vector<int>>(n); }

	vector<int> par;
	vector<int> dep;
	vector<int> sz;
	vector<int> heavy;
	vector<int> hroot;
	vector<int> hidx;
	
	void dfsinit(int at) {
		if (par[at] != -1) dep[at] = dep[par[at]] + 1;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (to == par[at]) continue;
			par[to] = at; dfsinit(to);
			sz[at] += sz[to]; if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
		}
	}

	void calc() {
		par = vector<int>(n, -1), dep = vector<int>(n, 0), sz = vector<int>(n, 1), heavy = vector<int>(n, -1);
		dfsinit(0);
		hroot = vector<int>(n, -1), hidx = vector<int>(n, -1); int nh = 0;
		REP(i, n) if (par[i] == -1 || heavy[par[i]] != i) for (int at = i; at != -1; at = heavy[at]) hroot[at] = i, hidx[at] = nh++;
		

	}

	vector<pair<int, int> > query(int a, int b) { 

		vector<pair<int, int> > ret;
		while (hroot[a] != hroot[b]) {
			if (dep[hroot[a]] < dep[hroot[b]]) swap(a, b);
			ret.PB(MP(hidx[hroot[a]], hidx[a]));
			a = par[hroot[a]];
		}
		if (dep[a] < dep[b]) swap(a, b);
		if (a != b) ret.PB(MP(hidx[b] + 1, hidx[a]));
		return ret;
	}
};

struct SNode { int cntunmarked; vector<int> unmarked; set<pair<int, int> > marked; pair<int, int> minmarked[3]; SNode() { cntunmarked = 0; minmarked[0] = minmarked[1] = minmarked[2] = MP(INT_MAX, -1); } };
struct STree {
	int n;
	vector<bool> marked;
	vector<SNode> s;
	void init(int _n,int _nid) { n = _n; marked = vector<bool>(_nid, false); s = vector<SNode>(4 * n); }

	int findunmarked(int x, int l, int r, int L, int R, int SKIP) {
		

		if (s[x].cntunmarked == 0) return -1;
		while (SZ(s[x].unmarked) >= 1) {
			int ret = s[x].unmarked.back();
			

			if (marked[ret]) { s[x].unmarked.pop_back(); continue; }
			if (ret == SKIP && SZ(s[x].unmarked) == 1) break;
			if (ret == SKIP) { swap(s[x].unmarked[0], s[x].unmarked.back()); assert(s[x].unmarked.back() != SKIP); continue; }
			return ret;
		}
		int ret = -1;
		if (l != r) {
			int m = l + (r - l) / 2;
			if (L <= m && ret == -1) ret = findunmarked(2 * x + 1, l, m, L, R, SKIP);
			if (m + 1 <= R && ret == -1) ret = findunmarked(2 * x + 2, m + 1, r, L, R, SKIP);
		}
		return ret;
	}
	int findminmarked(int x, int l, int r, int L, int R, int SKIP) {
		if (L <= l && r <= R) {
			return s[x].minmarked[0].second != SKIP && s[x].minmarked[0].second != (SKIP ^ 1) ? s[x].minmarked[0].first : s[x].minmarked[1].second != SKIP && s[x].minmarked[1].second != (SKIP ^ 1) ? s[x].minmarked[1].first : s[x].minmarked[2].first;
		} else {
			int ret = INT_MAX;
			for (auto it = s[x].marked.begin(); it != s[x].marked.end(); ++it) if (it->second != SKIP&&it->second != (SKIP ^ 1)) { ret = it->first; break; }
			int m = l + (r - l) / 2;
			if (L <= m) ret = min(ret, findminmarked(2 * x + 1, l, m, L, R, SKIP));
			if (m + 1 <= R) ret = min(ret, findminmarked(2 * x + 2, m + 1, r, L, R, SKIP));
			return ret;
		}
	}
	bool update(int x, pair<int, int> cur) {
		if (cur.first < s[x].minmarked[0].first) {
			if (cur.second != s[x].minmarked[0].second && cur.second != s[x].minmarked[1].second) s[x].minmarked[2] = s[x].minmarked[1], s[x].minmarked[1] = s[x].minmarked[0];
			else if (cur.second != s[x].minmarked[0].second) s[x].minmarked[1] = s[x].minmarked[0];
			s[x].minmarked[0] = cur;
			return true;
		} else if (cur.second == s[x].minmarked[0].second) {
			return true;
		} else if (cur.first < s[x].minmarked[1].first) {
			if (cur.second != s[x].minmarked[1].second) s[x].minmarked[2] = s[x].minmarked[1];
			s[x].minmarked[1] = cur;
			return true;
		} else if (cur.second == s[x].minmarked[1].second) {
			return true;
		} else if (cur.first < s[x].minmarked[2].first) {
			s[x].minmarked[2] = cur;
			return true;
		} else {
			return false;
		}
	}
	void recalc(int x, bool leaf) {
		s[x].minmarked[0] = s[x].minmarked[1] = s[x].minmarked[2] = MP(INT_MAX, -1);
		for (auto it = s[x].marked.begin(); it != s[x].marked.end(); ++it) if (!update(x, *it)) break;
		if (!leaf) FORE(y, 2 * x + 1, 2 * x + 2) REP(i, 3) update(x, s[y].minmarked[i]);
	}
	void create(int x, int l, int r, int L, int R, int ID) {
		

		++s[x].cntunmarked;
		if (L <= l && r <= R) {
			s[x].unmarked.PB(ID);
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) create(2 * x + 1, l, m, L, R, ID);
			if (m + 1 <= R) create(2 * x + 2, m + 1, r, L, R, ID);
		}
	}
	void mark(int x, int l, int r, int L, int R, int ID, int VAL) {
		

		--s[x].cntunmarked;
		if (L <= l && r <= R) {
			s[x].marked.insert(MP(VAL, ID));
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) mark(2 * x + 1, l, m, L, R, ID, VAL);
			if (m + 1 <= R) mark(2 * x + 2, m + 1, r, L, R, ID, VAL);
		}
		recalc(x, l == r);
	}
	void kill(int x, int l, int r, int L, int R, int ID, int VAL) {
		

		if (L <= l && r <= R) {
			s[x].marked.erase(MP(VAL, ID));
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) kill(2 * x + 1, l, m, L, R, ID, VAL);
			if (m + 1 <= R) kill(2 * x + 2, m + 1, r, L, R, ID, VAL);
		}
		recalc(x, l == r);
	}
};

const int MAXN = 100000;
const int MAXQ = 10000;

int n;
vector<int> adj[MAXN];
int nq;
int q[MAXQ][4];
int ans[MAXQ];

HLD hld;
vector<pair<int, int> > segs[2 * MAXQ];
STree stree;
ImplicitTarjan imptar;

int unmarkedadj(int at) { REPSZ(i, segs[at]) { int cur = stree.findunmarked(0, 0, stree.n - 1, segs[at][i].first, segs[at][i].second, at); if (cur != -1) return cur ^ 1; } return -1; }
int minmarkedadj(int at) { int ret = INT_MAX; REPSZ(i, segs[at]) { int cur = stree.findminmarked(0, 0, stree.n - 1, segs[at][i].first, segs[at][i].second, at); ret = min(ret, cur); }  return ret; }
void mark(int at, int val) { at ^= 1; REPSZ(i, segs[at]) stree.mark(0, 0, stree.n - 1, segs[at][i].first, segs[at][i].second, at, val); stree.marked[at] = true; }
void kill(int at, int val) { at ^= 1; REPSZ(i, segs[at]) stree.kill(0, 0, stree.n - 1, segs[at][i].first, segs[at][i].second, at, val); }

bool solve() {
	hld.init(n);
	REP(i, n) REPSZ(j, adj[i]) hld.adj[i].PB(adj[i][j]);
	hld.calc();
	REP(i, nq) REP(j, 2) {
		int a = q[i][2 * j + 0], b = q[i][2 * j + 1];
		segs[2 * i + j] = hld.query(a, b);
		

	}

	stree.init(n,2*nq);
	REP(at, 2 * nq) REPSZ(i, segs[at]) stree.create(0, 0, stree.n - 1, segs[at][i].first, segs[at][i].second, at);

	imptar.init(2 * nq); imptar.unmarkedadj = unmarkedadj, imptar.mark = mark, imptar.minmarkedadj = minmarkedadj, imptar.kill = kill;
	imptar.calc();
	
	REP(i, nq) if (imptar.comp[2 * i + 0] == imptar.comp[2 * i + 1]) return false;
	REP(i, nq) ans[i] = -1;
	REP(i, imptar.ncomp) REPSZ(j, imptar.compnodes[i]) { int at = imptar.compnodes[i][j]; if (ans[at >> 1] == -1) ans[at >> 1] = at % 2 == 0 ? 1 : 2; }
	return true;
}

void run() {
	scanf("%d", &n); REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq); REP(i, nq) REP(j, 4) scanf("%d", &q[i][j]), --q[i][j];

	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, nq) printf("%d\n", ans[i]);
}

struct UF {
	vector<int> par, sz;
	UF(int n) { par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int a, int b) { a = find(a), b = find(b); if (a == b) return false; if (sz[a] < sz[b]) swap(a, b); par[b] = a, sz[a] += sz[b]; return true; }
};
set<pair<int, int> > seen;
bool verifypath(int a, int b, int prev) {
	if (a == b) return true;
	REPSZ(i, adj[a]) {
		int c = adj[a][i]; if (c == prev) continue;
		if (!verifypath(c, b, a)) continue;
		pair<int, int> e = MP(a, c); if (e.first > e.second) swap(e.first, e.second);
		assert(!seen.count(e)); seen.insert(e);
		return true;
	}
	return false;
}
void verify() {
	seen.clear();
	REP(i, nq) {
		int a = q[i][2 * (ans[i] - 1) + 0], b = q[i][2 * (ans[i] - 1) + 1];
		assert(verifypath(a, b, -1));
	}
}
int myrand() { return rand() % 1000 * 1000 + rand() % 1000; }
void stress() {
	REP(rep, 10000) {
		n = 20; REP(i, n) adj[i].clear();
		UF uf(n); REP(i, n - 1) while (true) { int a = myrand() % n, b = myrand() % n; if (!uf.unite(a, b)) continue; adj[a].PB(b); adj[b].PB(a); break; }
		

		nq = 5; REP(i, nq) REP(j, 4) q[i][j] = rand() % n;
		

		

		bool have = solve();
		printf("%c", have ? 'V' : 'x');
		if (have) verify();
	}
}

int main() {
	run();
	

	return 0;
}
