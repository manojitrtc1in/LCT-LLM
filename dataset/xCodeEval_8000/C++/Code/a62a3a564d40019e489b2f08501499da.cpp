#line 1 "/Users/nok0/Documents/Programming/nok0/cftemp.hpp"
#include <bits/stdc++.h>
using namespace std;

#pragma region Macros


#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)



#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;



template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  

#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)



template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}



namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  

#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif



template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
std::vector<std::pair<char, int>> rle(const string &s) {
	int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and s[l] == s[r]; r++) {}
		ret.emplace_back(s[l], r - l);
		l = r;
	}
	return ret;
}
template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T> &v) {
	int n = v.size();
	std::vector<std::pair<T, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and v[l] == v[r]; r++) {}
		ret.emplace_back(v[l], r - l);
		l = r;
	}
	return ret;
}
std::vector<int> iota(int n) {
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	return p;
}
template <class T>
struct cum_vector {
public:
	cum_vector() = default;
	template <class U>
	cum_vector(const std::vector<U> &vec) : cum((int)vec.size() + 1) {
		for(int i = 0; i < (int)vec.size(); i++)
			cum[i + 1] = cum[i] + vec[i];
	}
	T prod(int l, int r) {
		return cum[r] - cum[l];
	}

private:
	std::vector<T> cum;
};



template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}


long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	a = (a % mod + mod) % mod;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}
template <class T, class F>
T bin_search(T ok, T ng, const F &f) {
	while(abs(ok - ng) > 1) {
		T mid = (ok + ng) >> 1;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}
template <class T, class F>
T bin_search(T ok, T ng, const F &f, int loop) {
	for(int i = 0; i < loop; i++) {
		T mid = (ok + ng) >> 1;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}



struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

void main_();

int main() {
	main_();
	return 0;
}
#line 2 "/Users/nok0/Documents/Programming/nok0/data_structure/rangeadd_rangesum_bit.hpp"

template <class T>
struct rangeadd_rangesum_bit {
private:
	std::vector<T> vec1, vec2;
	size_t n;

public:
	rangeadd_rangesum_bit() = default;
	rangeadd_rangesum_bit(size_t n_) : n(n_ + 1), vec1(n_ + 2, 0), vec2(n_ + 2, 0) {}

	

	void add(int l, int r, T x = T(1)) {
		l++;
		r++;
		for(int i = l; i <= n; i += i & -i) vec1[i] -= x * l;
		for(int i = l; i <= n; i += i & -i) vec2[i] += x;
		for(int i = r; i <= n; i += i & -i) vec1[i] += x * r;
		for(int i = r; i <= n; i += i & -i) vec2[i] -= x;
	}

	

	T sum(int r) {
		r += 1;
		T ret = 0;
		for(int x = r; x > 0; x -= x & -x) ret += vec1[x];
		for(int x = r; x > 0; x -= x & -x) ret += vec2[x] * r;
		return ret;
	}

	

	T sum(int l, int r) { return sum(r) - sum(l); }
};
#line 10 "/Users/nok0/Documents/Programming/nok0/graph/graph.hpp"

struct Edge {
	int to;
	long long cost;
	Edge() = default;
	Edge(int to_, long long cost_) : to(to_), cost(cost_) {}
	bool operator<(const Edge &a) const { return cost < a.cost; }
	bool operator>(const Edge &a) const { return cost > a.cost; }
	friend std::ostream &operator<<(std::ostream &s, Edge &a) {
		s << "to: " << a.to << ", cost: " << a.cost;
		return s;
	}
};

class graph {
	std::vector<std::vector<Edge>> edges;

	template <class F>
	struct rec_lambda {
		F f;
		rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
		template <class... Args>
		auto operator()(Args &&... args) const {
			return f(*this, std::forward<Args>(args)...);
		}
	};

public:
	inline const std::vector<Edge> &operator[](int k) const { return edges[k]; }
	inline std::vector<Edge> &operator[](int k) { return edges[k]; }

	int size() const { return edges.size(); }
	void resize(const int n) { edges.resize(n); }

	graph() = default;
	graph(int n) : edges(n) {}
	graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
	const long long INF = 3e18;

	void input(int e = -1, bool weight = 0, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			long long cost = 1;
			std::cin >> u >> v;
			if(weight) std::cin >> cost;
			u -= idx, v -= idx;
			edges[u].emplace_back(v, cost);
			if(!directed) edges[v].emplace_back(u, cost);
		}
	}

	void add_edge(int u, int v, long long cost = 1, bool directed = false, int idx = 0) {
		u -= idx, v -= idx;
		edges[u].emplace_back(v, cost);
		if(!directed) edges[v].emplace_back(u, cost);
	}

	

	std::vector<long long> bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : edges[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	

	

	std::vector<long long> zero_one_bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::deque<int> deq;
		dist[s] = 0;
		deq.push_back(s);
		while(!deq.empty()) {
			int v = deq.front();
			deq.pop_front();
			for(auto &e : edges[v]) {
				assert(0LL <= e.cost and e.cost < 2LL);
				if(e.cost and dist[e.to] > dist[v] + 1) {
					dist[e.to] = dist[v] + 1;
					deq.push_back(e.to);
				} else if(!e.cost and dist[e.to] > dist[v]) {
					dist[e.to] = dist[v];
					deq.push_front(e.to);
				}
			}
		}
		return dist;
	}

	

	

	std::vector<long long> dijkstra(int s) {  

		std::vector<long long> dist(size(), INF);
		const auto compare = [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) { return a.first > b.first; };
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};
		dist[s] = 0;
		que.emplace(0, s);
		while(!que.empty()) {
			std::pair<long long, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		return dist;
	}

	

	

	

	std::vector<long long> bellman_ford(int s) {  

		int n = size();
		std::vector<long long> res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : edges[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}
		std::queue<int> que;
		std::vector<int> chk(n);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(res[e.to] > res[v] + e.cost and !chk[e.to]) {
					que.push(e.to);
					chk[e.to] = 1;
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					que.push(e.to);
				}
			}
		}
		for(int i = 0; i < n; i++)
			if(chk[i]) res[i] = -INF;
		return res;
	}

	

	std::vector<std::vector<long long>> warshall_floyd() {  

		int n = size();
		std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++) {
				if(dist[i][k] == INF) continue;
				for(int j = 0; j < n; j++) {
					if(dist[k][j] == INF) continue;
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		return dist;
	}

	

	

	std::vector<int> topological_sort() {  

		std::vector<int> res;
		int n = size();
		std::vector<int> used(n, 0);
		bool not_DAG = false;
		for(int i = 0; i < n; i++) {
			rec_lambda([&](auto &&dfs, int k) -> void {
				if(not_DAG) return;
				if(used[k]) {
					if(used[k] == 1) not_DAG = true;
					return;
				}
				used[k] = 1;
				for(auto &e : edges[k]) dfs(e.to);
				used[k] = 2;
				res.push_back(k);
			})(i);
		}
		if(not_DAG) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool is_DAG() { return !topological_sort().empty(); }  


	

	

	std::vector<long long> height() {  

		auto vec1 = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v1 = i;
		vec1 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v2 = i;
		auto vec2 = bfs(v2);
		for(int i = 0; i < int(size()); i++)
			if(vec1[i] < vec2[i]) vec1[i] = vec2[i];
		return vec1;
	}

	

	

	

	std::vector<int> bipartite_grouping() {
		std::vector<int> colors(size(), -1);
		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			for(auto &e : edges[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == -1 and !self(self, e.to, !col)) return false;
			}
			return true;
		};
		for(int i = 0; i < int(size()); i++)
			if(colors[i] == -1 and !dfs(dfs, i, 0)) return std::vector<int>{};
		return colors;
	}

	bool is_bipartite() { return !bipartite_grouping().empty(); }

	

	

	std::pair<std::pair<int, int>, long long> diameter() {  

		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		vec = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v2 = i;
		std::pair<std::pair<int, int>, long long> res = {{v1, v2}, dia};
		return res;
	}

	

	

	std::vector<int> diameter_path() {
		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		auto vec2 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec2[i]) dia = vec2[i], v2 = i;
		vec = bfs(v2);
		std::vector<int> ret;
		auto dfs = [&](auto self, int now, int p) -> void {
			ret.emplace_back(now);
			if(now == v2) return;
			for(auto &[to, cost] : (*this)[now]) {
				if(vec[to] + vec2[to] == dia and to != p)
					self(self, to, now);
			}
		};
		dfs(dfs, v1, -1);
		return ret;
	}

	

	

	std::vector<int> subtree_size(const int root) {
		int n = size();
		std::vector<int> ret(n, 1);
		rec_lambda([&](auto &&dfs, int now, int p) -> void {
			for(auto &[to, cost] : (*this)[now]) {
				if(to == p) continue;
				dfs(to, now);
				ret[now] += ret[to];
			}
		})(root, -1);
		return ret;
	}

	

	long long prim() {  

		long long res = 0;
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> que;
		for(auto &e : edges[0]) que.push(e);
		std::vector<int> chk(size());
		chk[0] = 1;
		int cnt = 1;
		while(cnt < size()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			cnt++;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e2 : edges[e.to]) que.push(e2);
		}
		return res;
	}

	

	long long kruskal() {  

		std::vector<std::tuple<int, int, long long>> Edges;
		for(int i = 0; i < int(size()); i++)
			for(auto &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);
		std::sort(Edges.begin(), Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int, int, long long> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		long long ret = 0;
		for(auto &e : Edges)
			if(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
		return ret;
	}

	

	std::vector<int> centroid() {
		int n = size();
		std::vector<int> centroid, sz(n);
		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool is_centroid = true;
			for(auto &e : edges[now]) {
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > n / 2) is_centroid = false;
				}
			}
			if(n - sz[now] > n / 2) is_centroid = false;
			if(is_centroid) centroid.push_back(now);
		};
		dfs(dfs, 0, -1);
		return centroid;
	}

	

	

	graph root_to_leaf(int root = 0) {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	

	

	graph leaf_to_root(int root = 0) {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	

};
#line 3 "/Users/nok0/Documents/Programming/nok0/graph/hld.hpp"

struct heavy_light_decomposition {
public:
	std::vector<int> sz, in, out, head, rev, par;

private:
	graph &g;

	void dfs_sz(int v, int p = -1) {
		par[v] = p;
		if(!g[v].empty() and g[v].front().to == p) std::swap(g[v].front(), g[v].back());
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			dfs_sz(e.to, v);
			sz[v] += sz[e.to];
			if(sz[g[v].front().to] < sz[e.to]) std::swap(g[v].front(), e);
		}
	}

	void dfs_hld(int v, int &t, int p = -1) {
		in[v] = t++;
		rev[in[v]] = v;
		for(auto &e : g[v]) {
			if(e.to == p) continue;
			head[e.to] = (g[v].front().to == e.to ? head[v] : e.to);
			dfs_hld(e.to, t, v);
		}
		out[v] = t;
	}

	void build(int root = 0) {
		dfs_sz(root);
		int t = 0;
		head[root] = root;
		dfs_hld(root, t);
	}

public:
	heavy_light_decomposition(graph &g_, int root = 0) : g(g_) {
		int n = g.size();
		sz.resize(n, 1);
		in.resize(n);
		out.resize(n);
		head.resize(n);
		rev.resize(n);
		par.resize(n);
		build(root);
	}

	int level_ancestor(int v, int level) {
		while(true) {
			int u = head[v];
			if(in[v] - level >= in[u]) return rev[in[v] - level];
			level -= in[v] - in[u] + 1;
			v = par[u];
		}
	}

	int lowest_common_ancestor(int u, int v) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) return u;
		}
	}

	

	template <typename T, typename Q, typename F>
	T query(int u, int v, const T &unit, const Q &q, const F &f, bool edge = false) {
		T l = unit, r = unit;
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v), std::swap(l, r);
			if(head[u] == head[v]) break;
			l = f(q(in[head[v]], in[v] + 1), l);
		}
		return f(f(q(in[u] + edge, in[v] + 1), l), r);
	}

	

	template <typename Q>
	void add(int u, int v, const Q &q, bool edge = false) {
		for(;; v = par[head[v]]) {
			if(in[u] > in[v]) std::swap(u, v);
			if(head[u] == head[v]) break;
			q(in[head[v]], in[v] + 1);
		}
		q(in[u] + edge, in[v] + 1);
	}

	std::pair<int, int> subtree(int v, bool edge = false) { return std::pair<int, int>(in[v] + edge, out[v]); }
};
#line 5 "i.cpp"

struct LevelAncestor {
	vector<vector<int> > G, par, lad;
	vector<int> dep, nxt, len, pth, ord, hs;
	LevelAncestor(int n) : G(n), dep(n), nxt(n, -1), len(n), pth(n), ord(n), hs(n + 1, 0) {
		int h = 1;
		while((1 << h) <= n) h++;
		par.assign(h, vector<int>(n, -1));
		for(int i = 2; i <= n; i++) hs[i] = hs[i >> 1] + 1;
	}

	void add_edge(int u, int v) {
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	void dfs(int v, int p, int d, int f) {
		if(nxt[v] < 0) {
			par[0][nxt[v] = v] = p;
			len[v] = dep[v] = d;
			for(int u : G[v]) {
				if(u == p) continue;
				dfs(u, v, d + 1, 0);
				if(len[v] < len[u]) nxt[v] = u, len[v] = len[u];
			}
		}
		if(!f) return;
		pth[v] = lad.size();
		lad.emplace_back();
		for(int k = v;; k = nxt[k]) {
			lad.back().emplace_back(k);
			pth[k] = pth[v];
			if(k == nxt[k]) break;
		}
		for(;; p = v, v = nxt[v]) {
			for(int u : G[v])
				if(u != p and u != nxt[v]) dfs(u, v, d + 1, 1);
			if(v == nxt[v]) break;
		}
	}

	void build(int r = 0) {
		int n = G.size();
		dfs(r, -1, 0, 1);
		for(int k = 0; k + 1 < (int)par.size(); k++) {
			for(int v = 0; v < n; v++) {
				if(par[k][v] < 0)
					par[k + 1][v] = -1;
				else
					par[k + 1][v] = par[k][par[k][v]];
			}
		}
		for(int i = 0; i < (int)lad.size(); i++) {
			int v = lad[i][0], p = par[0][v];
			if(~p) {
				int k = pth[p], l = min(ord[p] + 1, (int)lad[i].size());
				lad[i].resize(l + lad[i].size());
				for(int j = 0, m = lad[i].size(); j + l < m; j++)
					lad[i][m - (j + 1)] = lad[i][m - (j + l + 1)];
				for(int j = 0; j < l; j++)
					lad[i][j] = lad[k][ord[p] - l + j + 1];
			}
			for(int j = 0; j < (int)lad[i].size(); j++)
				if(pth[lad[i][j]] == i) ord[lad[i][j]] = j;
		}
	}

	int lca(int u, int v) {
		int h = par.size();

		if(dep[u] > dep[v]) swap(u, v);
		for(int k = 0; k < h; k++)
			if((dep[v] - dep[u]) >> k & 1)
				v = par[k][v];

		if(u == v) return u;
		for(int k = h - 1; k >= 0; k--) {
			if(par[k][u] == par[k][v]) continue;
			u = par[k][u];
			v = par[k][v];
		}
		return par[0][u];
	}

	int distance(int u, int v) {
		return dep[u] + dep[v] - dep[lca(u, v)] * 2;
	}

	int up(int v, int d) {
		if(d == 0) return v;
		v = par[hs[d]][v];
		d -= 1 << hs[d];
		return lad[pth[v]][ord[v] - d];
	}

	

	int next(int u, int v) {
		if(dep[u] >= dep[v]) return par[0][u];
		int l = up(v, dep[v] - dep[u] - 1);
		return par[0][l] == u ? l : par[0][u];
	}
};

const int bs = 100000;
void main_() {
	INT(n, q);
	VEC(int, a, n);
	graph g(n);
	LevelAncestor la(n);
	REP(i, n - 1) {
		INT(u, v);
		--u, --v;
		g.add_edge(u, v);
		la.add_edge(u, v);
	}
	la.build();
	heavy_light_decomposition hld(g);
	rangeadd_rangesum_bit<ll> bt(n);

	V<bool> is_large(n);
	V<> large;
	auto op = [&](ll x, ll y) {
		return max(abs(x + y), abs(x - y));
	};
	REP(i, n) {
		if(SZ(g[i]) >= bs) is_large[i] = 1, large.pb(i);
		for(auto [to, cost] : g[i]) {
			if(to < i) continue;
			hld.add(
			    i, to, [&](int l, int r) { bt.add(l, r, op(a[i], a[to])); }, true);
		}
	}
	V<> nowval = a;
	while(q--) {
		INT(t, u, v);
		--u;
		if(t == 2) {
			--v;
			auto res = hld.query(
			    u, v, 0ll, [&](int l, int r) { return bt.sum(l, r); }, [](ll a, ll b) { return a + b; }, true);
			auto D = la.distance(u, v);
			for(auto &x : large) {
				if(la.distance(x, u) + la.distance(x, v) != D) continue;
				auto y = la.next(x, u);
				auto z = la.next(x, v);
				if(y != -1) {
					if(is_large[y]) {
						if(x > y) continue;
						res -= op(a[y], a[x]);
						res += op(nowval[y], nowval[x]);
					} else {
						res -= op(a[y], a[x]);
						res += op(a[y], nowval[x]);
					}
				}
				if(z != -1) {
					if(is_large[z]) {
						if(x > z) continue;
						res -= op(a[z], a[x]);
						res += op(nowval[z], nowval[x]);
					} else {
						res -= op(a[z], a[x]);
						res += op(a[z], nowval[x]);
					}
				}
			}
			print(res);
		} else {
			if(!is_large[u]) {
				for(auto [to, cost] : g[u]) {
					hld.add(
					    u, to, [&](int l, int r) { bt.add(l, r, -op(a[u], a[to])); }, true);
				}
				a[u] = v;
				for(auto [to, cost] : g[u]) {
					hld.add(
					    u, to, [&](int l, int r) { bt.add(l, r, op(a[u], a[to])); }, true);
				}
			} else {
				nowval[u] = v;
			}
		}
	}
}
