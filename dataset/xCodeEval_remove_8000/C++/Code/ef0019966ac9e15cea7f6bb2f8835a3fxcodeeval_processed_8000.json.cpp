











inline unsigned int id24(unsigned int x) { unsigned long r; _BitScanForward(&r, x); return r; }
inline unsigned int id14(unsigned long long x) { unsigned long r; _BitScanForward64(&r, x); return r; }


inline unsigned int id1(unsigned x) { return (unsigned int)__lzcnt(x); }
inline unsigned int id19(unsigned long long x) { return (unsigned int)__lzcnt64(x); }








using namespace std;











typedef long long ll;
typedef long double ld;
















constexpr int INF2 = std::numeric_limits<int>::max() / 2 - 10000000;
constexpr long long INF = std::numeric_limits<long long>::max() / 2 - 10000000;
const ld pi = acos(-1);



constexpr int MOD = 998244353;  







template<class T> inline void chmax(T& a, T b) {
	if (a < b) a = b;
}
template<class T> inline void chmin(T& a, T b) {
	if (a > b) a = b;
}






template<typename T = long long>
T id5(T a, T b) {
	if (b == (T)0) return a;
	return id5<T>(b, a % b);
}

template<typename T = long long>
T id7(T a, T b) {
	return a / id5<T>(a, b) * b;
}








long long id8(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}

	long long tempo = id8(b, a % b, y, x);

	

	

	

	y -= (a / b) * x;

	return tempo;
}












pair<long long, long long> CRT(long long base1, long long m1, long long base2, long long m2) {
	long long p, q;
	long long id21 = id8(m1, m2, p, q);
	if ((base2 - base1) % id21 != 0) return make_pair(0, -1);

	long long id11 = m1 * (m2 / id21);  


	p *= (base2 - base1) / id21;
	p %= (m2 / id21);

	

	


	long long r = (base1 + m1 * p) % id11;
	if (r < 0) r += id11;

	return make_pair(r, id11);
}






long long id9(long long a, long long M) {
	long long x = 0, y = 0;
	long long memo = id8(a, M, x, y);
	assert(memo == 1LL);
	x %= M;
	if (x < 0) x += M;
	return x;
}








template<typename T = long long>
constexpr T my_pow(T N, long long a, long long M) {
	assert(0 <= a);
	T x = N % M, res = (T)1;
	while (a) {
		if (a & 1) {
			res *= x;
			res %= M;
		}
		x *= x; 

		x %= M;
		a >>= 1;
	}
	return res;
}





template<typename T = long long>
constexpr T my_pow(T N, long long a) {
	assert(0 <= a);
	T x = N, res = (T)1;
	while (a) {
		if (a & 1) res *= x;
		x *= x; 

		a >>= 1;
	}
	return res;
}






vector<signed> id2(signed base, long long n) {
	long long tempo = n;
	long long tempo2 = n; 


	signed n_digit = 1;
	while (tempo2 >= base) {
		tempo2 /= base;
		n_digit++;
	}

	vector<signed> v(n_digit, 0);   

	long long denominator = my_pow<long long>((long long)base, (long long)(n_digit - 1));

	for (signed i = 0; i < n_digit; i++) {
		v.at(i) = tempo / denominator;
		tempo -= v.at(i) * denominator;

		denominator /= base;
	}

	return v;
}




vector<signed> id2(signed base, long long n, int M) {
	vector<signed> v = id2(base, n);
	


	if ((int)v.size() >= M) return v;
	else {
		int diff = M - v.size();
		vector<signed> res(diff, 0);
		for (int i = 0; i < (int)v.size(); i++) res.emplace_back(v.at(i));
		return res;
	}
}










template<typename T = int>
vector<bool> id18(T N) {
	vector<bool> res(N + 1, true);
	res.at(0) = false;
	res.at(1) = false;

	for (T i = 2; 2 * i <= N; i++) {
		res.at(2 * i) = false;
	}

	for (T i = 3; i * i <= N; i += 2) {
		

		if (res.at(i)) {
			T j = i * i;  

			while (j <= N) {
				res.at(j) = false;
				j += 2 * i;
			}
		}
	}

	return res;
};












template<typename T = int>
vector<T> sieve(T n) {
	n++; 


	vector<T> res(n, 0);
	for (T i = 1; i < n; i++) {
		if (i % 2 == 0) res.at(i) = 2;  

		else res.at(i) = i; 

	}

	for (T i = 3; i * i < n; i += 2) {
		

		if (res.at(i) == i) {
			T j = i * i;  

			while (j < n) {
				if (res.at(j) == j) res.at(j) = i;
				j += 2 * i;
			}
		}
	}

	return res;
};






constexpr bool is_prime(long long N) {
	

	if (N == 1000000007 || N == 1000000009) return true;
	if (N == 998244353 || N == 167772161 || N == 469762049 || N == 1224736769) return true; 

	if (N == 924844033 || N == 1012924417) return true; 

	if (N == 163577857) return true; 


	

	if (N <= 1) return false;
	if (N == 2 || N == 3) return true;
	if (N % 2 == 0) return false;
	if (N % 3 == 0) return false;

	for (long long i = 1; (6 * i + 1) * (6 * i + 1) <= N; ++i) {
		if (N % (6 * i + 1) == 0) return false;
	}
	for (long long i = 0; (6 * i + 5) * (6 * i + 5) <= N; ++i) {
		if (N % (6 * i + 5) == 0) return false;
	}
	return true;
}

template <int n> constexpr bool id23 = is_prime(n);








template<typename T = long long>
map<T, T> PrimeFactor(T N) {
	map<T, T> res;

	T i = 2;
	while (i * i <= N) {
		while (N % i == 0) {
			res[i]++;
			N /= i;
		}

		i += 1 + (i % 2); 

	}

	if (N > 1) res[N]++; 

	return res;
}








template<typename T = int>
map<T, T> id0(T target, vector<T>& min_factor) {
	map<T, T> res;
	if (min_factor.empty() || (T)min_factor.size() - 1 < target) min_factor = sieve<T>(target);

	while (target > 1) {
		res[min_factor[target]]++;
		target /= min_factor[target];
	}

	return res;
}






vector<long long> id15(long long target) {

	vector <long long> dividers, tempo;
	long long i = 1;
	while (i * i < target + 1) {
		if (target % i == 0) {
			dividers.push_back(i);
			if (i < target / i) tempo.push_back(target / i);  

		}
		i++;
	}

	for (long long j = 0; j < (long long)tempo.size(); j++) {
		dividers.push_back(tempo.at(tempo.size() - 1 - j));
	}

	return dividers;
}








template<typename T = int>
vector<T> id16(T target, vector<T>& min_factor, bool is_sort = false) {

	vector<T> dividers = { 1 };
	map<T, T> memo = id0<T>(target, min_factor);

	for (auto&& iter = memo.begin(); iter != memo.end(); iter++) {
		vector <T> tempo = dividers;
		for (T k = 0; k < (T)tempo.size(); k++) {
			T times = 1;
			for (T j = 1; j <= (iter->second); j++) {
				times *= iter->first;
				dividers.push_back(tempo[k] * times);
			}
		}
	}

	if (is_sort) sort(dividers.begin(), dividers.end());  

	return dividers;
}




class UnionFind {
public:
	vector<int> parent;
	vector<int> rank;
	vector<int> v_size;

	UnionFind(int N) : parent(N), rank(N, 0), v_size(N, 1) {
		rep(i, N) {
			parent[i] = i;
		}
	}

	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]); 

	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		if (rx == ry) return; 

		if (rank[rx] < rank[ry]) {
			parent[rx] = ry;
			v_size[ry] += v_size[rx];
		}
		else {
			parent[ry] = rx;
			v_size[rx] += v_size[ry];
			if (rank[rx] == rank[ry]) rank[rx]++;
		}
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}

	int count_tree() {
		int N = parent.size();
		int res = 0;

		rep(i, N) {
			if (root(i) == i) res++;
		}

		return res;
	}

	int size(int x) {
		return v_size[root(x)];
	}
};






ld calc_dist(int x1, int y1, int x2, int y2) {
	int tempo = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	ld res = sqrt((ld)tempo);
	return res;
}






vector<pair<int, char>> RunLength(const string& S) {
	int N = S.size();
	vector<pair<int, char>> memo;

	if (N == 1) {
		memo.push_back(MP(1, S.at(0)));
		return memo;
	}

	int tempo = 1;
	for (int i = 1; i < N; i++) {
		if (i != N - 1) {
			if (S.at(i) == S.at(i - 1)) tempo++;
			else {
				memo.push_back(MP(tempo, S.at(i - 1)));
				tempo = 1;
			}
		}
		else {
			if (S.at(i) == S.at(i - 1)) {
				tempo++;
				memo.push_back(MP(tempo, S.at(i - 1)));
			}
			else {
				memo.push_back(MP(tempo, S.at(i - 1)));
				memo.push_back(MP(1, S.at(i)));
			}
		}
	}

	return memo;
}




void printf_ld(ld res) {
	printf("%.12Lf\n", res);
	

}

template<typename T = long long>
void print_vec(vector<T> v) {
	int N = v.size();
	rep(i, N) {
		if (i != N - 1) cout << v.at(i) << " ";
		else cout << v.at(i) << endl;
	}
}

template<typename T = long long>
void print_vec(deque<T> v) {
	int N = v.size();
	rep(i, N) {
		if (i != N - 1) cout << v.at(i) << " ";
		else cout << v.at(i) << endl;
	}
}












template<int m, typename T = long long> class mint {
private:
	T _val;
public:
	

	constexpr mint(T v = 0LL) noexcept : _val(v% m) {
		if (_val < 0) _val += m;
	}

	constexpr T val() const noexcept {
		return _val;
	}

	

	constexpr mint& operator += (const mint& r) noexcept {
		_val += r._val;
		if (_val >= m) _val -= m;
		return *this;
	}
	constexpr mint& operator -= (const mint& r) noexcept {
		_val -= r._val;
		if (_val < 0) _val += m;
		return *this;
	}
	constexpr mint& operator *= (const mint& r) noexcept {
		_val *= r._val; _val %= m;
		return *this;
	}
	constexpr mint& operator /= (const mint& r) noexcept {
		if (!prime) {
			

			T a = r._val, b = m, u = 1, v = 0;
			while (b) {
				T q = a / b;
				a -= q * b; swap(a, b); 

				u -= q * v; swap(u, v);
			}
			

			_val *= u; _val %= m;
			if (_val < 0) _val += m;
		}
		else {
			

			*this *= r.modpow(m - 2);
		}
		return *this;
	}

	constexpr mint operator + (const mint& r) const noexcept { return mint(*this) += r; }
	constexpr mint operator - (const mint& r) const noexcept { return mint(*this) -= r; }
	constexpr mint operator * (const mint& r) const noexcept { return mint(*this) *= r; }
	constexpr mint operator / (const mint& r) const noexcept { return mint(*this) /= r; }

	constexpr bool operator == (const mint& r) const noexcept {
		return this->_val == r._val;
	}
	constexpr bool operator != (const mint& r) const noexcept {
		return this->_val != r._val;
	}

	

	

	constexpr mint operator ++() noexcept { this->_val++; if (this->_val == m) this->_val = 0; return mint(*this); }
	constexpr mint operator --() noexcept { if (this->_val == 0) this->_val = m;  this->_val--; return mint(*this); }
	

	constexpr mint operator++(signed) noexcept { mint temp(_val); ++_val; if (_val == m) _val = 0; return temp; }
	constexpr mint operator--(signed) noexcept { mint temp(_val); if (_val == 0) _val = m;  --_val; return temp; }

	constexpr mint operator -() const noexcept { return mint(-_val); }

	

	friend constexpr ostream& operator << (ostream& os, const mint<m, T>& x) noexcept {
		return os << x._val;
	}
	friend istream& operator >> (istream& is, mint<m, T>& x) noexcept {
		T init_val;
		is >> init_val;
		x = mint<m, T>(init_val);
		return is;
	}

	

	constexpr mint<m, T> inverse() const noexcept {
		mint<m, T> e(1);
		return e / (*this);
	}

private:
	

	

	static constexpr bool prime = id23<m>;


	

	constexpr mint<m, T> modpow(long long n) const noexcept {
		assert(0 <= n);
		mint<m, T> x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x; 

			n >>= 1;
		}
		return r;
	}
};

using modint = mint<MOD, long long>;




vector<modint> dp_fac;
vector<modint> id10;



template<typename T = modint>
void fac_initialize(int x, vector<T>& dp = dp_fac, vector<T>& dp_inv = id10) {
	if ((int)dp.size() <= x) {
		int n = dp.size(); if (n == 0) ++n;
		dp.resize(x + 1, (T)1);
		for (int i = n; i <= x; ++i) {
			dp.at(i) = dp.at(i - 1) * i;
		}
	}

	if ((int)dp_inv.size() <= x) {
		int n = dp_inv.size();
		dp_inv.resize(x + 1, (T)1);
		dp_inv.at(x) /= dp.at(x);
		for (int i = x - 1; i >= n; --i) {
			dp_inv.at(i) = dp_inv.at(i + 1) * (i + 1);
		}
	}
}





template<typename T = modint>
T factorial(int x, vector<T>& dp = dp_fac) {
	assert(x >= 0);

	

	if ((int)dp.size() > x) {
		return dp.at(x);
	}

	int n = dp.size();
	

	for (int i = n; i < x + 1; i++) {
		if (i == 0) dp.push_back((T)1);
		else dp.push_back(dp.back() * i);
	}

	return dp.at(x);
}

template<typename T = modint>
T id20(int x, vector<T>& dp = id10) {
	assert(x >= 0);

	

	if ((int)dp.size() > x) {
		return dp.at(x);
	}

	int n = dp.size();
	

	for (int i = n; i < x + 1; i++) {
		if (i == 0) dp.push_back((T)1);
		else dp.push_back(dp.back() / i);
	}

	return dp.at(x);
}




template<typename T = modint, typename U = int>
T my_comb(U N, U a, vector<T>& dp = dp_fac, vector<T>& dp_inv = id10) {
	if (N < a) return (T)0;

	T ans = factorial<T>(N, dp);
	ans *= id20<T>(a, dp_inv);
	ans *= id20<T>(N - a, dp_inv);

	return ans;
}



template<typename T, typename U = int>
T id4(U N, U a) {
	if (N < a) return (T)0;

	T answer = 1;
	for (U i = (U)0; i < a; i++) {
		answer *= (N - i);
		answer /= i + 1;
	}

	return answer;
}




ld now_clock() {
	ld t = (ld)clock() / (ld)CLOCKS_PER_SEC;
	return t;
}












template<typename T = long long>
struct edge {
	int to;
	T weight;
	int index; 


	constexpr bool operator < (const edge& r) const noexcept {
		if (weight != r.weight) return (weight < r.weight);
		else return (index < r.index);
	}
	constexpr bool operator > (const edge& r) const noexcept {
		if (weight != r.weight) return (weight > r.weight);
		else return (index > r.index);
	}
};
template<typename T> bool operator== (const edge<T>& a, const edge<T>& b) { return (a.to == b.to && a.weight == b.weight && a.index == b.index); };


template<typename T = long long>
struct edge2 {
	int from;
	int to;
	T weight;

	constexpr bool operator < (const edge2& r) const noexcept {
		if (weight != r.weight) return (weight < r.weight);
		else return (from < r.from);
	}
};


template<typename T = long long>
class tree {
public:
	vector<vector<edge<T>>> G;
	vector<edge2<T>> e;
	tree(int _n) : N(_n) { initialize(_n); };
	tree() : tree(0) {};

	

	void initialize(int n) {
		G.assign(n, vector<edge<T>>());
		dist.assign(n, 0);
		depth.assign(n, 0);

		

		parents.assign(1, vector<int>(N, -1)); 

	}


	

	void add_biedge(int from, int to, T weight) {
		assert(0 <= from && from < N);
		assert(0 <= to && to < N);
		assert((T)0 < weight);

		G.at(from).emplace_back(edge<T>{ to, weight, (int)e.size() });
		G.at(to).emplace_back(edge<T>{ from, weight, (int)e.size() });
		e.push_back(edge2<T>{from, to, weight});
	}


	

	void LCA_initialize(int _root) {
		assert(0 <= _root && root < N);
		root = _root;

		dfs_depth(root, -1);

		logN = 1;
		while ((1LL << logN) < D + 1) logN++; 

		parents.resize(logN, vector<int>(N, -1));

		for (int i = 1; i < logN; i++) {
			for (int v = 0; v < N; v++) {
				if (parents[i - 1][v] != -1) parents[i][v] = parents[i - 1][parents[i - 1][v]];
				else parents[i][v] = -1;
			}
		}
	}


	

	void dfs_depth(int v, int parent) {
		parents[0][v] = parent;

		for (int i = 0; i < (int)G.at(v).size(); i++) {
			int next_v = G.at(v).at(i).to;
			if (next_v == parent) continue;

			dist.at(next_v) = dist.at(v) + G.at(v).at(i).weight; 

			depth.at(next_v) = depth.at(v) + 1; 

			if (D < depth.at(v) + 1) D = depth.at(v) + 1; 

			dfs_depth(next_v, v);
		}
	}


	

	

	pair<vector<int>, vector<int>> route(int v) {
		vector<int> res = { v }; 

		vector<int> res2; 


		T d = dist.at(v);
		while (d > (T)0) {
			int v = res.back();

			for (auto&& x : G.at(v)) {
				int next_v = x.to;
				T w = x.weight;

				if (dist.at(next_v) == dist.at(v) - w) {
					d = dist.at(next_v);
					res.push_back(next_v);
					res2.push_back(x.index);
					break;
				}
			}
		}

		return MP(res, res2);
	}




	int get_lca(int u, int v) {
		assert(root != -1); 

		assert(0 <= u && u < N);
		assert(0 <= v && v < N);

		if (depth.at(u) < depth.at(v)) swap(u, v);  


		

		for (int i = 0; i < logN; i++) {
			if ((depth.at(u) - depth.at(v)) & (1LL << i)) u = parents.at(i).at(u);
			if (depth.at(u) == depth.at(v)) break;
		}

		

		if (u == v) return u;
		for (int i = logN - 1; i >= 0; i--) {
			if (parents[i][u] != parents[i][v]) {
				u = parents[i][u];
				v = parents[i][v];
			}
		}
		return parents[0][u];
	}


	

	int get_dist(int u, int v) {
		return dist[u] + dist[v] - 2 * dist[get_lca(u, v)];
	}

	

	int get_depth(int u, int v) {
		return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
	}

	

	

	int jump(int from, int to, int _depth) {
		assert(0 <= from && from < N);
		assert(0 <= to && to < N);
		assert(0 <= _depth);
		if (_depth > get_depth(from, to)) return -1;

		int id17 = get_lca(from, to);
		if (_depth <= depth[from] - depth[id17]) {
			

			int res = from;
			for (int i = 0; i < logN; i++) {
				if ((depth[res] - (depth[from] - _depth)) & (1LL << i)) res = parents[i][res];
				if (depth[res] == (depth[from] - _depth)) break;
			}
			return res;
		}
		else {
			_depth -= depth[from] - depth[id17]; 

			_depth = depth[to] - depth[id17] - _depth; 


			int res = to;
			for (int i = 0; i < logN; i++) {
				if ((depth[res] - (depth[to] - _depth)) & (1LL << i)) res = parents[i][res];
				if (depth[res] == (depth[to] - _depth)) break;
			}
			return res;
		}
	};
	







	int N;
	int logN = 1;
	int root = -1; 

	int D = 0; 

	vector<vector<int>> parents; 

	vector<int> dist; 

	vector<int> depth; 

};







const vector<int> vdh = { 1, -1, 0, 0 };
const vector<int> vdw = { 0, 0, 1, -1 };

























template<typename T = long long>
class graph {
	int sp = -1; 

public:
	vector<vector<edge<T>>> G;
	vector<edge2<T>> edges;
	vector<T> dist; 

	vector<int> prev; 

	vector<int> prev_edge; 


	graph(int _n) : N(_n) { initialize(_n); };
	graph() : N(0) {};


	

	void add_edge(int from, int to, T weight = (T)1) {
		assert(0 <= from && from < N);
		assert(0 <= to && to < N);
		assert((T)0 <= weight);

		G.at(from).emplace_back(edge<T>{ to, weight, (int)edges.size() });
		edges.push_back(edge2<T>{from, to, weight});
	}


	

	void add_biedge(int from, int to, T weight = (T)1) {
		add_edge(from, to, weight);
		add_edge(to, from, weight);
	}


	

	void bfs01(vector<int> vs) {
		const T ini_dist = -1;
		


		deque<int> que;
		dist.assign(N, ini_dist);
		prev.assign(N, -1);
		prev_edge.assign(N, -1);

		for (auto&& s : vs) {
			assert(0 <= s && s < N);
			que.push_front(s); dist.at(s) = 0;
		}

		while (!que.empty()) {
			int v = que.front(); que.pop_front();
			for (edge<T> e : G.at(v)) {
				int nextv = e.to;

				

				if (dist.at(nextv) != ini_dist && dist.at(nextv) <= dist.at(v) + e.weight) continue;
				dist.at(nextv) = dist.at(v) + e.weight;
				if ((int)vs.size() == 1) {
					prev.at(nextv) = v;
					prev_edge.at(nextv) = e.index;
				}

				if (e.weight) que.push_back(nextv);
				else que.push_front(nextv);
			}
		}
	}


	

	void bfs01(int s) {
		vector<int> vs = { s };
		sp = s;
		bfs01(vs);
	}


	

	void dijkstra(int s) {
		assert(0 <= s && s < N);
		sp = s;

		dist.assign(N, INF);
		prev.assign(N, -1);
		prev_edge.assign(N, -1);

		

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
		dist.at(s) = (T)0; que.push(make_pair((T)0, s));

		while (!que.empty()) {
			pair<T, int> p = que.top(); que.pop();
			int v = p.second;
			if (dist.at(v) < p.first) continue;  


			for (int i = 0; i < (int)G.at(v).size(); i++) {
				edge<T> e = G.at(v).at(i);
				if (dist.at(e.to) > dist.at(v) + e.weight) {
					dist.at(e.to) = dist.at(v) + e.weight;
					prev.at(e.to) = v;
					prev_edge.at(e.to) = e.index;
					que.push(make_pair(dist.at(e.to), e.to));
				}
			}
		}
	}


	

	

	vector<int> route(int v) {
		assert(sp != -1);
		vector<int> res = { v }; 


		while (res.back() != sp) {
			int now = res.back();
			int next_v = prev.at(now);
			res.push_back(next_v);
		}

		reverse(res.begin(), res.end());
		return res;
	}


	

	

	template<typename U = modint>
	U cnt_route(int i, vector<U>& cnt, vector<bool>& seen) {
		assert(sp != -1);
		assert((int)cnt.size() == N);
		assert((int)seen.size() == N);

		if (seen.at(i)) return cnt.at(i);
		else if (i == sp) {
			seen.at(i) = true;
			return cnt.at(i) = (U)1;
		}
		else {
			U sum = 0;
			for (auto& e : G.at(i)) {
				int nextv = e.to;
				if (dist.at(i) == dist.at(nextv) + e.weight) {
					sum += cnt_route(nextv, cnt, seen);
				}
			}

			seen.at(i) = true;
			return cnt.at(i) = sum;
		}
	}





	

	void from_grid(const vector<string>& S) {
		assert(!S.empty());

		int H = S.size();
		int W = S.at(0).size();

		int N = H * W;
		initialize(N);
		for (int h = 0; h < H; ++h) {
			for (int w = 0; w < W; ++w) {
				for (int i = 0; i < (int)vdh.size(); ++i) {
					int dh = vdh.at(i), dw = vdw.at(i);
					if (h + dh < 0 || H <= h + dh) continue;
					if (w + dw < 0 || W <= w + dw) continue;

					int v = h * W + w;
					int nextv = (h + dh) * W + (w + dw);
					if (S.at(h + dh).at(w + dw) == '

						continue;
					}
					else {
						add_edge(v, nextv, 1);
					}

				}
			}
		}
	}





	

	

	

	template<typename U = T>
	pair<U, int> Prim(int sp = 0) {
		assert(0 <= sp && sp < N);

		U sum = 0;
		int marked_cnt = 0;
		vector<bool> marked(N, false);

		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> que;

		

		++marked_cnt;
		marked[sp] = true;
		for (auto&& e : G[sp]) que.push(e);
		


		while (marked_cnt < N && !que.empty()) {
			auto e = que.top(); que.pop();
			int nextv = e.to;

			if (marked[nextv]) continue;
			++marked_cnt;
			marked[nextv] = true;
			for (auto&& id3 : G[nextv]) que.push(id3);

			sum += e.weight;
		}

		return make_pair(sum, marked_cnt);
	}


	

	

	

	

	

	template<typename U = T>
	pair<U, vector<edge2<T>>> id22() {
		assert(edges.size() % 2 == 0);
		int E = edges.size() / 2;

		vector<edge2<T>> es;
		for (int i = 0; i < (int)edges.size(); i += 2) {
			int v1 = edges.at(i).from;
			int v2 = edges.at(i).to;
			T w = edges.at(i).weight;

			assert(edges.at(i + 1).from == v2);
			assert(edges.at(i + 1).to == v1);
			assert(edges.at(i + 1).weight == w);

			es.push_back(edge2<T>{v1, v2, w});
		}
		std::sort(es.begin(), es.end());


		U sum = 0;
		vector<edge2<T>> vres;
		UnionFind tree(N);

		rep(i, E) {
			edge2<T> e = es.at(i);
			if (!tree.same(e.from, e.to)) {
				tree.unite(e.from, e.to);
				sum += e.weight;
				vres.push_back(e);
			}
		}

		

		rep(v, N) {
			if (!tree.same(0, v)) return { INF, vector<edge2<T>>(0) };
		}

		return { sum, vres };
	}





	

	

	pair<bool, vector<int>> id12() {
		vector<int> CntIn(N, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < (int)G.at(i).size(); ++j) {
				int v = G.at(i).at(j).to;
				++CntIn.at(v);
			}
		}

		vector<int> res;
		queue<int> que;
		


		for (int i = 0; i < N; ++i) {
			if (CntIn.at(i) == 0) {
				que.push(i);
				--CntIn.at(i);
			}
		}

		while (!que.empty()) {
			int v = que.front(); que.pop();
			

			res.push_back(v);

			for (int i = 0; i < (int)G.at(v).size(); ++i) {
				int next_v = G.at(v).at(i).to;

				if (CntIn.at(next_v) == -1) {
					

					return make_pair(false, vector<int>());
				}

				--CntIn.at(next_v);
				if (CntIn.at(next_v) == 0) {
					que.push(next_v);
				}
			}
		}


		if (res.size() == N) {
			return make_pair(true, res);
		}
		else {
			return make_pair(false, vector<int>());
		}
	}





	

	

	

	pair<bool, vector<int>> IsClosed() {
		vector<bool> seen(N, false);

		for (int v = 0; v < N; ++v) {
			if (seen.at(v)) continue;
			vector<int> vec;
			bool flag = dfs_closed(v, -1, vec, seen);

			if (flag) {
				vector<int> res;
				while (!vec.empty()) {
					res.push_back(vec.back());
					vec.pop_back();

					if (res.size() > 1 && res.front() == res.back()) break;
				}

				assert((int)res.size() > 1);
				return make_pair(true, res);
			}
		}


		vector<int> vec;
		return make_pair(false, vec);
	}





	

	vector<pair<int, int>> id6(int root = 0) {
		assert(0 <= root && root < N);

		vector<pair<int, int>> res; 

		vector<int> edge_index; 


		queue<int> que;
		que.push(root);
		UnionFind uf(N);

		while (!que.empty()) {
			int v = que.front(); que.pop();

			for (const auto& e : G.at(v)) {
				int nv = e.to;
				if (uf.same(root, nv)) continue;
				uf.unite(root, nv);

				que.push(nv);
				res.push_back({ v, nv });
				edge_index.push_back(e.index);
			}
		}

		

		for (int i = 0; i < (int)edge_index.size(); ++i) edge_index.at(i) /= 2;
		

		


		return res;
	}


	

	

	vector<pair<int, int>> dfs_tree(int root = 0) {
		assert(0 <= root && root < N);

		vector<pair<int, int>> res; 

		vector<int> edge_index; 

		vector<bool> seen(N, false);
		id13(root, root, res, edge_index, seen);

		

		for (int i = 0; i < (int)edge_index.size(); ++i) edge_index.at(i) /= 2;
		

		


		return res;
	}





private:
	int N;

	

	void initialize(int n) {
		G.assign(n, vector<edge<T>>());
		sp = -1;
		dist.assign(n, INF);
		prev.assign(n, -1);
		prev_edge.assign(n, -1);
	}



	

	bool dfs_closed(int v, int from, vector<int>& vec, vector<bool>& seen) {
		vec.push_back(v);
		if (seen.at(v)) return true;
		else seen.at(v) = true;

		for (auto&& ed : G.at(v)) {
			int next_v = ed.to;
			if (next_v == from) continue;

			bool flag = dfs_closed(next_v, v, vec, seen);
			if (flag) return true;
		}

		vec.pop_back();
		return false;
	}



	

	void id13(const int& root, int v, vector<pair<int, int>>& res, vector<int>& edge_index, vector<bool>& seen) {
		seen.at(v) = true;

		for (const auto& e : G.at(v)) {
			int nv = e.to;
			if (seen.at(nv)) continue;

			res.push_back({ v, nv });
			edge_index.push_back(e.index);

			id13(root, nv, res, edge_index, seen);
		}
	}
};





signed main() {
	int N, M;
	cin >> N >> M;

	vector<int> u(M), v(M);
	rep(i, M) {
		cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}


	graph<int> G(N);
	rep(i, M) G.add_biedge(u[i], v[i], i + 1);
	auto mst = G.id22();
	



	tree t(N);
	for (auto&& e : mst.second) {
		t.add_biedge(e.from, e.to, 1);
	}
	t.LCA_initialize(0);


	vector<int> imos(N, 0);
	int pos = 0;

	rep(i, M) {
		if (pos < mst.second.size() && i + 1 == mst.second.at(pos).weight) {
			++pos;
			continue;
		}
		edge2<int> e = { u[i], v[i], i + 1 };
		


		int lca = t.get_lca(e.from, e.to);
		if (e.from != lca && e.to != lca) {
			imos[0]++;
			imos[e.from]--;
			imos[e.to]--;
		}
		else {
			if (e.from == lca) swap(e.from, e.to);
			int dist = t.get_depth(e.from, e.to);
			int x = t.jump(e.from, e.to, dist - 1);
			imos[x]++;
			imos[e.from]--;
		}
	}


	queue<int> que;
	que.push(0);

	while (!que.empty()) {
		int v = que.front(); que.pop();

		for (auto&& e : t.G[v]) {
			int nv = e.to;
			

			if (nv == t.parents[0][v]) continue;

			imos[nv] += imos[v];
			que.push(nv);
		}
	}

	rep(i, N) {
		if (imos[i] == 0) cout << 1;
		else cout << 0;
	}
	cout << endl;

}