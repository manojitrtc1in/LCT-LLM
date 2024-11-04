

















































































































































































































































































































#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)


#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };





LL read() { LL in; scanf("%lld", &in); return in; }
LL printLL(const LL out) { printf("%lld\n", out); }




std::vector<int> isBipartiteGraph(const std::vector<std::vector<int>>& g) {
	int n = g.size();
	std::vector<int> color(n, -1);
	std::queue<int> que;
	que.push(0);
	color[0] = 0; 

	while (!que.empty()) {
		int now = que.front(); que.pop();
		for (auto to : g[now]) {
			if (color[to] != -1) {
				if (color[now] == color[to]) {
					return std::vector<int>();
				}
			}
			else {
				color[to] = color[now] ^ 1;
				que.push(to);
			}
		}
	}
	return color;
}
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;
class SCC {
private:
	const int n;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int > vs;
	vector<bool> used;
	vector<int > cmp;
	int sccsize_k;
public:
	SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}
	void addEdge(int from, int to) {
		G[from].emplace_back(to);
		rG[to].emplace_back(from);
	}
	void dfs(int v) {
		used[v] = true;
		for (auto&& nxt : G[v]) {
			if (!used[nxt]) dfs(nxt);
		}
		vs.emplace_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (auto&& nxt : rG[v]) {
			if (!used[nxt]) rdfs(nxt, k);
		}
		vs.emplace_back(v);
	}
	int scc() {
		for (int v = 0; v < n; v++) {
			if (!used[v]) dfs(v);
		}
		used.assign(n, false);
		sccsize_k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			int v = vs[i];
			if (!used[v]) rdfs(v, sccsize_k++);
		}
		return sccsize_k;
	}
	bool same(int a, int b) {
		return cmp[a] == cmp[b];
	}
	vector<int >get_color() {
		return move(cmp);
	}
};

pair < vector<VVI>, map<PII, int> > ForestToGraphs(const vector<PII>&edge, int V) {

	int  scc_sz;
	vector<int>color; {
		SCC SccG(V);
		for (const auto&it : edge) {
			SccG.addEdge(it.first, it.second);
			SccG.addEdge(it.second, it.first);
		}
		scc_sz = SccG.scc();
		color = SccG.get_color();
	}

	

	vector<int>CC(scc_sz, 0);
	map<PII, int> revMap; 

	vector<vector<PII>> reid_edges(scc_sz); {
		map<PII, int>Map;
		auto reid = [&Map, &CC, &revMap](const int c, const int x) {
			auto it = Map.find(PII(c, x));
			if (it != Map.end()) {
				return it->second;
			}
			else {
				int nx = CC[c];
				Map[PII(c, x)] = nx;
				revMap[PII(c, nx)] = x;
				CC[c]++;
				return nx;
			}
		};
		FOR(i, 0, SZ(edge)) {
			int a = edge[i].first, b = edge[i].second;
			const int c = color[a];
			a = reid(c, a), b = reid(c, b);
			reid_edges[c].push_back(PII(a, b));
		}
	}
	vector<vector<int>>colV(scc_sz); { 

		FOR(i, 0, V) {
			colV[color[i]].push_back(i);
		}
		FOR(c, 0, scc_sz) {
			if ((int)colV[c].size() == 1) {
				revMap[PII(c, 0)] = colV[c].front();
			}
		}
	}

	vector<VVI> Graphs(scc_sz); {
		FOR(i, 0, scc_sz) {
			Graphs[i].resize(max(1, CC[i]));
			FOR(j, 0, SZ(reid_edges[i])) {
				const int a = reid_edges[i][j].first;
				const int b = reid_edges[i][j].second;
				Graphs[i][a].push_back(b);
				Graphs[i][b].push_back(a);
			}

		}
	}

	return pair<vector<VVI>, map<PII, int>>(Graphs, revMap);
}
int main() {
	int T = read();
	FOR(_, 0, T) {
		LL N = read(), M = read();
		map<PII, int>revid;
		vector<VVI>forest; {
			vector<PII>edge(M);
			FOR(i, 0, M) {
				int a = read() - 1, b = read() - 1;
				edge[i] = PII(a, b);
			}
			auto it = ForestToGraphs(edge, N);
			forest = it.first;
			revid = it.second;
		}

		int f = 1;
		mint ans = 1;
		FOR(j, 0, SZ(forest)) {
			assert(SZ(forest[j]));
			VI res = isBipartiteGraph(forest[j]);
			if (SZ(res)) {
				int B = 0;
				FOR(i, 0, SZ(forest[j])) {
					if (res[i] == 1) {
						B++;
					}
				}
				int R = SZ(forest[j]) - B;
				mint two = 2;
				mint ret = 0;
				ret += two.pow(R);
				ret += two.pow(B);
				ans *= ret;
			}
			else {
				f = 0;
				break;
			}
			DD(de(ans.get()));
		}
		if (f) {
			printLL(ans.get());
		}
		else {
			printLL(0);
		}
	}

	return 0;
}