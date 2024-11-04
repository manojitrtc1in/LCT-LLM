


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> pii;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define MP make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline int chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline int chkmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> inline T sqr(const T &val) { return val * val; }

namespace fastIO
{
	const int MAX_BUFFER_SIZE = 1 << 16;

	char buffer[MAX_BUFFER_SIZE], *cur = buffer, *ed = buffer;

	inline char getc() { return *(cur == ed ? ed = buffer + fread(buffer, 1, MAX_BUFFER_SIZE, stdin), cur = buffer : cur)++; }
}
using fastIO::getc;

template<typename T> inline T read()
{
	register T sum(0), fg(1);
	register char ch(getc());
	for(; !isdigit(ch); ch = getc()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getc()) sum = sum * 10 - '0' + ch;
	return sum * fg;
}




const int MAXN = (int) 5e4;

struct edge
{
	int u, v, c, w;

	edge() { }
	edge(int _u, int _v, int _c, int _w): u(_u), v(_v), c(_c), w(_w) { }
};

int n, m;

edge E[MAXN + 5];

inline void input()
{
	n = read<int>(), m = read<int>();
	for(int i = 1; i <= m; ++i) E[i].u = read<int>(), E[i].v = read<int>(), E[i].c = read<int>(), E[i].w = read<int>();
}

unordered_map<int, vector<int> > ids[MAXN + 5];
vector<int> all[MAXN + 5];
int uid[MAXN + 5], vid[MAXN + 5];
int auid[MAXN + 5], avid[MAXN + 5];

int cnt;

namespace SAT
{
	const int MAX_NODE = MAXN * 20;

	int N, X[MAXN + 5], Y[MAXN + 5];
	vector<int> adj[MAX_NODE + 5];

	inline void add_edge(int u, int v) { adj[u].push_back(v); }

	int dfn[MAX_NODE + 5], low[MAX_NODE + 5], dfn_cur;
	int sid[MAX_NODE + 5], scnt;

	inline void build(int _N)
	{
		for(int i = 1; i <= cnt; ++i) dfn[i] = low[i] = sid[i] = 0, adj[i].clear();

		N = _N, cnt = 0;
		for(int i = 1; i <= N; ++i) X[i] = ++cnt, Y[i] = ++cnt;
	}

	vector<int> stk;

	inline void dfs(int u, int fa)
	{
		dfn[u] = low[u] = ++dfn_cur;

		stk.push_back(u);
		for(auto v : adj[u]) if(v != fa)
		{
			if(!dfn[v])
			{
				dfs(v, u);
				chkmin(low[u], low[v]);
			}
			else if(!sid[v]) chkmin(low[u], dfn[v]);
		}

		if(low[u] == dfn[u])
		{
			++scnt;
			while(!stk.empty())
			{
				int p = stk.back();
				stk.pop_back();
				sid[p] = scnt;
				if(p == u) break;
			}
		}
	}

	inline int solve()
	{
		dfn_cur = scnt = 0;
		stk.clear();
		for(int i = 1; i <= N; ++i)
		{
			if(!dfn[X[i]]) dfs(X[i], 0);
			if(!dfn[Y[i]]) dfs(Y[i], 0);
		}
		for(int i = 1; i <= N; ++i) if(sid[X[i]] == sid[Y[i]]) return 0;
		return 1;
	}
}

inline int check(int LIM)
{
	using SAT::X;
	using SAT::Y;

	static unordered_map<int, vector<int> > preX[MAXN + 5], preY[MAXN + 5], sufX[MAXN + 5], sufY[MAXN + 5];
	static vector<int> preaX[MAXN + 5], preaY[MAXN + 5], sufaX[MAXN + 5], sufaY[MAXN + 5];

	SAT::build(m);
	for(int i = 1; i <= n; ++i)
	{
		for(const auto &it : ids[i])
		{
			const vector<int> &id = it.snd;

			vector<int> &preX0 = preX[i][it.fst];
			vector<int> &preY0 = preY[i][it.fst];
			preX0.resize(SZ(it.snd));
			preY0.resize(SZ(it.snd));
			for(int j = 0; j < SZ(id); ++j)
			{
				preX0[j] = ++cnt;
				SAT::add_edge(preX0[j], X[id[j]]);
				if(j > 0) SAT::add_edge(preX0[j], preX0[j - 1]);

				preY0[j] = ++cnt;
				SAT::add_edge(preY0[j], Y[id[j]]);
				if(j > 0) SAT::add_edge(preY0[j], preY0[j - 1]);
			}

			vector<int> &sufX0 = sufX[i][it.fst];
			vector<int> &sufY0 = sufY[i][it.fst];
			sufX0.resize(SZ(it.snd));
			sufY0.resize(SZ(it.snd));
			for(int j = SZ(id) - 1; j >= 0; --j)
			{
				sufX0[j] = ++cnt;
				SAT::add_edge(sufX0[j], X[id[j]]);
				if(j + 1 < SZ(id)) SAT::add_edge(sufX0[j], sufX0[j + 1]);

				sufY0[j] = ++cnt;
				SAT::add_edge(sufY0[j], Y[id[j]]);
				if(j + 1 < SZ(id)) SAT::add_edge(sufY0[j], sufY0[j + 1]);
			}
		}

		preaX[i].resize(SZ(all[i]));
		preaY[i].resize(SZ(all[i]));
		for(int j = 0; j < SZ(all[i]); ++j)
		{
			preaX[i][j] = ++cnt;
			SAT::add_edge(preaX[i][j], X[all[i][j]]);
			if(j > 0) SAT::add_edge(preaX[i][j], preaX[i][j - 1]);

			preaY[i][j] = ++cnt;
			SAT::add_edge(preaY[i][j], Y[all[i][j]]);
			if(j > 0) SAT::add_edge(preaY[i][j], preaY[i][j - 1]);
		}

		sufaX[i].resize(SZ(all[i]));
		sufaY[i].resize(SZ(all[i]));
		for(int j = SZ(all[i]) - 1; j >= 0; --j)
		{
			sufaX[i][j] = ++cnt;
			SAT::add_edge(sufaX[i][j], X[all[i][j]]);
			if(j + 1 < SZ(all[i])) SAT::add_edge(sufaX[i][j], sufaX[i][j + 1]);

			sufaY[i][j] = ++cnt;
			SAT::add_edge(sufaY[i][j], Y[all[i][j]]);
			if(j + 1 < SZ(all[i])) SAT::add_edge(sufaY[i][j], sufaY[i][j + 1]);
		}
	}

	auto add_lim = [&] (int i, int p, int p0, int u)
	{
		int c0 = E[i].c;
		const vector<int> &id = ids[u][c0];
		const vector<int> &preX0 = preX[u][c0];
		const vector<int> &preY0 = preY[u][c0];
		const vector<int> &sufX0 = sufX[u][c0];
		const vector<int> &sufY0 = sufY[u][c0];

		if(p > 0)
		{
			SAT::add_edge(Y[i], preX0[p - 1]);
			SAT::add_edge(preY0[p - 1], X[i]);
		}
		if(p + 1 < SZ(id))
		{
			SAT::add_edge(Y[i], sufX0[p + 1]);
			SAT::add_edge(sufY0[p + 1], X[i]);
		}

		if(p0 > 0)
		{
			SAT::add_edge(X[i], preaY[u][p0 - 1]);
			SAT::add_edge(preaX[u][p0 - 1], Y[i]);
		}
		if(p0 + 1 < SZ(all[u]))
		{
			SAT::add_edge(X[i], sufaY[u][p0 + 1]);
			SAT::add_edge(sufaX[u][p0 + 1], Y[i]);
		}
	};

	for(int i = 1; i <= m; ++i)
	{
		if(E[i].w > LIM) SAT::add_edge(X[i], Y[i]);

		add_lim(i, uid[i], auid[i], E[i].u);
		add_lim(i, vid[i], avid[i], E[i].v);
	}

	return SAT::solve();
}

inline void output(int LIM)
{
	printf("%d ", LIM);

	using SAT::X;
	using SAT::Y;

	static unordered_map<int, vector<int> > preX[MAXN + 5], preY[MAXN + 5], sufX[MAXN + 5], sufY[MAXN + 5];
	static vector<int> preaX[MAXN + 5], preaY[MAXN + 5], sufaX[MAXN + 5], sufaY[MAXN + 5];

	SAT::build(m);
	for(int i = 1; i <= n; ++i)
	{
		for(const auto &it : ids[i])
		{
			const vector<int> &id = it.snd;

			vector<int> &preX0 = preX[i][it.fst];
			vector<int> &preY0 = preY[i][it.fst];
			preX0.resize(SZ(it.snd));
			preY0.resize(SZ(it.snd));
			for(int j = 0; j < SZ(id); ++j)
			{
				preX0[j] = ++cnt;
				SAT::add_edge(preX0[j], X[id[j]]);
				if(j > 0) SAT::add_edge(preX0[j], preX0[j - 1]);

				preY0[j] = ++cnt;
				SAT::add_edge(preY0[j], Y[id[j]]);
				if(j > 0) SAT::add_edge(preY0[j], preY0[j - 1]);
			}

			vector<int> &sufX0 = sufX[i][it.fst];
			vector<int> &sufY0 = sufY[i][it.fst];
			sufX0.resize(SZ(it.snd));
			sufY0.resize(SZ(it.snd));
			for(int j = SZ(id) - 1; j >= 0; --j)
			{
				sufX0[j] = ++cnt;
				SAT::add_edge(sufX0[j], X[id[j]]);
				if(j + 1 < SZ(id)) SAT::add_edge(sufX0[j], sufX0[j + 1]);

				sufY0[j] = ++cnt;
				SAT::add_edge(sufY0[j], Y[id[j]]);
				if(j + 1 < SZ(id)) SAT::add_edge(sufY0[j], sufY0[j + 1]);
			}
		}

		preaX[i].resize(SZ(all[i]));
		preaY[i].resize(SZ(all[i]));
		for(int j = 0; j < SZ(all[i]); ++j)
		{
			preaX[i][j] = ++cnt;
			SAT::add_edge(preaX[i][j], X[all[i][j]]);
			if(j > 0) SAT::add_edge(preaX[i][j], preaX[i][j - 1]);

			preaY[i][j] = ++cnt;
			SAT::add_edge(preaY[i][j], Y[all[i][j]]);
			if(j > 0) SAT::add_edge(preaY[i][j], preaY[i][j - 1]);
		}

		sufaX[i].resize(SZ(all[i]));
		sufaY[i].resize(SZ(all[i]));
		for(int j = SZ(all[i]) - 1; j >= 0; --j)
		{
			sufaX[i][j] = ++cnt;
			SAT::add_edge(sufaX[i][j], X[all[i][j]]);
			if(j + 1 < SZ(all[i])) SAT::add_edge(sufaX[i][j], sufaX[i][j + 1]);

			sufaY[i][j] = ++cnt;
			SAT::add_edge(sufaY[i][j], Y[all[i][j]]);
			if(j + 1 < SZ(all[i])) SAT::add_edge(sufaY[i][j], sufaY[i][j + 1]);
		}
	}

	auto add_lim = [&] (int i, int p, int p0, int u)
	{
		int c0 = E[i].c;
		const vector<int> &id = ids[u][c0];
		const vector<int> &preX0 = preX[u][c0];
		const vector<int> &preY0 = preY[u][c0];
		const vector<int> &sufX0 = sufX[u][c0];
		const vector<int> &sufY0 = sufY[u][c0];

		if(p > 0)
		{
			SAT::add_edge(Y[i], preX0[p - 1]);
			SAT::add_edge(preY0[p - 1], X[i]);
		}
		if(p + 1 < SZ(id))
		{
			SAT::add_edge(Y[i], sufX0[p + 1]);
			SAT::add_edge(sufY0[p + 1], X[i]);
		}

		if(p0 > 0)
		{
			SAT::add_edge(X[i], preaY[u][p0 - 1]);
			SAT::add_edge(preaX[u][p0 - 1], Y[i]);
		}
		if(p0 + 1 < SZ(all[u]))
		{
			SAT::add_edge(X[i], sufaY[u][p0 + 1]);
			SAT::add_edge(sufaX[u][p0 + 1], Y[i]);
		}
	};

	for(int i = 1; i <= m; ++i)
	{
		if(E[i].w > LIM) SAT::add_edge(X[i], Y[i]);

		add_lim(i, uid[i], auid[i], E[i].u);
		add_lim(i, vid[i], avid[i], E[i].v);
	}

	SAT::solve();

	vector<int> ans;
	for(int i = 1; i <= m; ++i) if(SAT::sid[X[i]] < SAT::sid[Y[i]]) ans.push_back(i);
	printf("%d\n", SZ(ans));
	for(auto i : ans) printf("%d ", i);
	puts("");
}

inline void solve()
{
	for(int i = 1; i <= m; ++i)
	{
		ids[E[i].u][E[i].c].push_back(i);
		ids[E[i].v][E[i].c].push_back(i);
		all[E[i].u].push_back(i);
		all[E[i].v].push_back(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto &it : ids[i]) sort(ALL(it.snd)), it.snd.erase(unique(ALL(it.snd)), it.snd.end());
		sort(ALL(all[i])), all[i].erase(unique(ALL(all[i])), all[i].end());
	}

	for(int i = 1; i <= m; ++i)
	{
		uid[i] = lower_bound(ALL(ids[E[i].u][E[i].c]), i) - ids[E[i].u][E[i].c].begin();
		vid[i] = lower_bound(ALL(ids[E[i].v][E[i].c]), i) - ids[E[i].v][E[i].c].begin();
		auid[i] = lower_bound(ALL(all[E[i].u]), i) - all[E[i].u].begin();
		avid[i] = lower_bound(ALL(all[E[i].v]), i) - all[E[i].v].begin();
	}

	if(!check((int) 1e9)) { puts("No"); return; }
	int l = 0, r = (int) 1e9;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	puts("Yes");
	output(r);
}

int main()
{
#ifdef K_ON
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif

	input();
	solve();

	return 0;
}


