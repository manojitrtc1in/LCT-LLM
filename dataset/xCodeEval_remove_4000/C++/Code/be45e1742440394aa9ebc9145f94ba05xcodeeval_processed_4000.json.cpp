































using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pll> vpll;








template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

inline ll madd(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a + b) % MOD;
}
inline ll msub(ll a, ll b) {
	a %= MOD; b %= MOD;
	a += MOD;
	return (a - b) % MOD;
}
inline ll mmul(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a * b) % MOD;
}
inline ll mpow(ll a, ll r) {
	long long res = 1;
	while (r > 0) {
		if (r & 1) res = res * a % MOD;
		a = a * a % MOD;
		r >>= 1;
	}
	return res;
}
inline ll minv(ll a) {
	a %= MOD;
	ll b = MOD, u = 0, v = 1;
	while (a) {
		ll t = b / a;
		b -= t * a; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return u;
}
inline ll mdiv(ll a, ll b) {
	a %= MOD;
	a *= minv(b);
	return a % MOD;
}

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	ll size(int x) {
		return -data[root(x)];
	}
};



ll gcd(ll a, ll b) {
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	if (a < b) {
		ll c = b;
		b = a; a = c;
	}
	if ((a % b) == 0) return b;
	else return gcd(b, a % b);
}

pll id2(ll a, ll b) {
	if (a == 0) return pll(0, 1);
	if (b == 0) return pll(1, 0);
	return pll(a / gcd(a, b), b / gcd(a, b));
}
pll id1(ll a, ll b) {
	if (a == 0) return pll(0, b / abs(b));
	if (b == 0) return pll(a / abs(a), 0);
	return pll(a / gcd(abs(a), abs(b)), b / gcd(abs(a), abs(b)));
}



template< typename T = int >
struct Edge {
	int from, to;
	T cost;
	int idx;

	Edge() = default;

	Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

	operator int() const { return to; }
};

template< typename T = int >
struct Graph {
	vector< vector< Edge< T > > > g;
	int es;

	Graph() = default;

	explicit Graph(int n) : g(n), es(0) {}

	size_t size() const {
		return g.size();
	}

	void add_directed_edge(int from, int to, T cost = 1) {
		g[from].emplace_back(from, to, cost, es++);
	}

	void add_edge(int from, int to, T cost = 1) {
		g[from].emplace_back(from, to, cost, es);
		g[to].emplace_back(to, from, cost, es++);
	}

	void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			a += padding;
			b += padding;
			T c = T(1);
			if (weighted) cin >> c;
			if (directed) add_directed_edge(a, b, c);
			else add_edge(a, b, c);
		}
	}

	inline vector< Edge< T > >& operator[](const int& k) {
		return g[k];
	}

	inline const vector< Edge< T > >& operator[](const int& k) const {
		return g[k];
	}
};

template< typename T = int >
using Edges = vector< Edge< T > >;


template< typename T >
struct ShortestPath {
	vector< T > dist;
	vector< int > from, id;
};

template< typename T >
ShortestPath< T > dijkstra(const Graph< T >& g, int s) {
	const auto INF = numeric_limits< T >::max();
	vector< T > dist(g.size(), INF);
	vector< int > from(g.size(), -1), id(g.size(), -1);
	using Pi = pair< T, int >;
	priority_queue< Pi, vector< Pi >, greater<> > que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while (!que.empty()) {
		T cost;
		int idx;
		tie(cost, idx) = que.top();
		que.pop();
		if (dist[idx] < cost) continue;
		for (auto& e : g[idx]) {
			auto next_cost = cost + e.cost;
			if (dist[e.to] <= next_cost) continue;
			dist[e.to] = next_cost;
			from[e.to] = idx;
			id[e.to] = e.idx;
			que.emplace(dist[e.to], e.to);
		}
	}
	return { dist, from, id };
}

map< int64_t, int > prime_factor(int64_t n) {
	map< int64_t, int > ret;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}


struct Rat {
public:
	Rat(int y_, int x_) {
		x = x_;
		y = y_;
		d = 1.0 * y / x;
	}
	bool operator<(const Rat& rhs) const {
		if (abs(d - rhs.d) > EPS) {
			return (d < rhs.d);
		}
		return (rhs.x * y < rhs.y* x);
	}
	bool operator>=(const Rat& rhs) const {
		return !(*this < rhs);
	}
	ull x, y;
	double d;
};

template< int mod >
struct ModInt {
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt& operator+=(const ModInt& p) {
		if ((x += p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator-=(const ModInt& p) {
		if ((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}

	ModInt& operator*=(const ModInt& p) {
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt& operator/=(const ModInt& p) {
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt& p) const { return x == p.x; }

	bool operator!=(const ModInt& p) const { return x != p.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream& operator<<(ostream& os, const ModInt& p) {
		return os << p.x;
	}

	friend istream& operator>>(istream& is, ModInt& a) {
		int64_t t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

template< class T, size_t N >
struct SquareMatrix {
	array< array< T, N >, N > A;

	SquareMatrix() : A{ {} } {}

	size_t size() const { return N; }

	inline const array< T, N >& operator[](int k) const {
		return (A.at(k));
	}

	inline array< T, N >& operator[](int k) {
		return (A.at(k));
	}

	static SquareMatrix add_identity() {
		return SquareMatrix();
	}

	static SquareMatrix mul_identity() {
		SquareMatrix mat;
		for (size_t i = 0; i < N; i++) mat[i][i] = 1;
		return mat;
	}

	SquareMatrix& operator+=(const SquareMatrix& B) {
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				(*this)[i][j] += B[i][j];
			}
		}
		return *this;
	}

	SquareMatrix& operator-=(const SquareMatrix& B) {
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				(*this)[i][j] -= B[i][j];
			}
		}
		return *this;
	}

	SquareMatrix& operator*=(const SquareMatrix& B) {
		array< array< T, N >, N > C;
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				for (size_t k = 0; k < N; k++) {
					C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
				}
			}
		}
		A.swap(C);
		return (*this);
	}

	SquareMatrix& operator^=(uint64_t k) {
		SquareMatrix B = SquareMatrix::mul_identity();
		while (k > 0) {
			if (k & 1) B *= *this;
			*this *= *this;
			k >>= 1LL;
		}
		A.swap(B.A);
		return *this;
	}

	SquareMatrix operator+(const SquareMatrix& B) const {
		return SquareMatrix(*this) += B;
	}

	SquareMatrix operator-(const SquareMatrix& B) const {
		return SquareMatrix(*this) -= B;
	}

	SquareMatrix operator*(const SquareMatrix& B) const {
		return SquareMatrix(*this) *= B;
	}

	SquareMatrix operator^(uint64_t k) const {
		return SquareMatrix(*this) ^= k;
	}

	friend ostream& operator<<(ostream& os, SquareMatrix& p) {
		for (int i = 0; i < N; i++) {
			os << "[";
			for (int j = 0; j < N; j++) {
				os << p[i][j] << (j + 1 == N ? "]\n" : ",");
			}
		}
		return os;
	}
};


template< typename T >
vector< int > id0(const Graph< T >& g) {
	const int N = (int)g.size();
	vector< int > deg(N);
	for (int i = 0; i < N; i++) {
		for (auto& to : g[i]) ++deg[to];
	}
	stack< int > st;
	for (int i = 0; i < N; i++) {
		if (deg[i] == 0) st.emplace(i);
	}
	vector< int > ord;
	while (!st.empty()) {
		auto p = st.top();
		st.pop();
		ord.emplace_back(p);
		for (auto& to : g[p]) {
			if (--deg[to] == 0) st.emplace(to);
		}
	}
	return ord;
}


vll divisor(ll n) {
	vll  ret;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return ret;
}

long long merge_cnt(vector<long long>& a) {
	int n = a.size();

	if (n <= 1) {
		return 0;
	}

	long long cnt = 0;

	vector<long long> b(a.begin(), a.begin() + n / 2);
	vector<long long> c(a.begin() + n / 2, a.end());

	cnt += merge_cnt(b);
	cnt += merge_cnt(c);

	int ai = 0, bi = 0, ci = 0;
	

	while (ai < n) {
		if (bi < (int)b.size() && (ci == (int)c.size() || b[bi] <= c[ci])) {
			a[ai++] = b[bi++];
		}
		else {
			cnt += n / 2 - bi;
			a[ai++] = c[ci++];
		}
	}
	return cnt;
}

int main() {
	ll tt;
	cin >> tt;
	REP(cas, tt) {
		ll n;
		cin >> n;
		vll v(n);
		REP(i, n) cin >> v[i];
		ll x;
		cin >> x;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			if (v[0] + v[1] < x * 2) {
				cout << 1 << endl;
			}
			else {
				cout << 2 << endl;
			}
			continue;
		}
		REP(i, n) v[i] -= x;
		vll rui(n + 1);
		REP(i, n) rui[i + 1] = rui[i] + v[i];
		ll ma = 0, last = rui[1], cnt = 0;
		FOR(i, 2, n + 1) {
			if (rui[i] < ma) {
				ma = -300000000000;
				cnt++;
			}
			else chmax(ma, last);
			last = rui[i];
		}
		cout << n - cnt << endl;
	}
	return 0;
}
