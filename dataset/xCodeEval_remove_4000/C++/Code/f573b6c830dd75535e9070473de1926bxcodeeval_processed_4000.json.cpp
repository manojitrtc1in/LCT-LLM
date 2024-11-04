
using namespace std;
















using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using mii = map<int, int>;
using pqll = priority_queue<long long>;
using pqllg = priority_queue<long long, vector<long long>, greater<long long>>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;


template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;


template <class T = ll>
using pqdn = priority_queue<T>;






long long const limLL = 9223372036854775807;  

long long const dekai = 1e15;
const long double pi = acos(-1);
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;






























template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}







template <class T>
T divup(T a, T b) {
	

	assert(b != 0);
	T x = abs(a);
	T y = abs(b);
	T z = (x + y - 1) / y;
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		return -z;
	else if(a == 0)
		return 0;
	else
		return z;
}

long long POW(long long a, long long n) {
	

	

	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

template <class T>
bool prime(T N) {
	

	

	

	

	if(N <= 1) return false;
	T p = sqrt(N);
	for(long long i = 2; i <= p; i++)
		if(N % i == 0) return false;
	return true;
}

vector<long long> eratos(long long n) {
	

	

	assert(n >= 0);
	vll v(n + 1, 1);
	if(n >= 0) v[0] = 0;
	if(n >= 1) v[1] = 0;
	Rep(i, 2, n + 1) {
		if(v[i]) {
			for(ll k = i * 2; k < n + 1; k += i) {
				v[k] = 0;
			}
		}
	}
	return v;
}

vector<long long> primevec(long long n) {  

	vll v = eratos(n);
	vll ret;
	Rep(i, 2, n + 1) if(v[i]) ret.push_back(i);
	return ret;
}

set<long long> id9(long long n) {	

	vll v = eratos(n);
	sll s;
	Rep(i, 2, n + 1) if(v[i]) s.insert(i);
	return s;
}

vector<long long> id3(long long n) {  

	vector<long long> ret;
	long long sq = sqrt(n);
	for(long long i = 1; i <= sq; ++i) {
		if(n % i == 0) {
			ret.push_back(i);
			if(i * i != n) {
				ret.push_back(n / i);
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

map<long long, long long> id6(long long n) {  

	map<long long, long long> m;
	long long p = sqrt(n);
	while(n % 2 == 0) {
		n /= 2;
		if(m.count(2)) {
			m[2]++;
		} else {
			m[2] = 1;
		}
	}
	for(long long i = 3; i * i <= n; i += 2) {
		while(n % i == 0) {
			n /= i;
			if(m.count(i)) {
				m[i]++;
			} else {
				m[i] = 1;
			}
		}
	}
	if(n != 1) m[n] = 1;
	return m;
}

vector<long long> keta(ll x) {
	

	

	

	vll w;
	while(x > 0) {
		w.push_back(x % 10);
		x /= 10;
	}
	reverse(all(w));
	return w;
}

long long id8(ll x) {  

	ll ret = 0;
	while(x > 0) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

string bits(long long n, long long k) {	 

	string s = "";
	rep(i, k) {
		char c = '0' + (n % 2);
		s += c;
		n /= 2;
	}
	reverse(all(s));
	return s;
}

long long modpow(long long a, long long n, long long mod) {	 

	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {	

	

	return modpow(a, mod - 2, mod);
}

vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {  

	assert(n < 100 && k < 100);
	if(n < k || k < 0 || n < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	ll res;
	if(n - k < k)
		res = com(n, n - k);
	else if(k == 0)
		res = 1;
	else
		res = com(n - 1, k - 1) + com(n - 1, k);
	comb[n][k] = res;
	return res;
}



const ll MAX = 510000;






long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	

	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(ll n, ll k) {	

	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(ll n, ll k) {  

	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
long long hmod(ll n, ll k) {  

	

	

	return commod(n + k - 1, n);
}

long long id0(long long sub) {	 

	long long x = sub & -sub, y = sub + x;
	return (((sub & ~y) / x) >> 1) | y;
}






vector<long long> vin(long long n) {  

	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}





template <class T>
void vout(vector<T> &v) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) cout << " ";
		}
	}
	cout << endl;
}

template <class T>
void add(vector<T> &v, T val) {	 

	for(auto &a : v) a += val;
	return;
}







template <class T>
vector<T> id5(vector<T> &v) {
	set<T> s;
	vector<T> ret;
	for(auto seg : v) {
		if(!s.count(seg)) {
			ret.push_back(seg);
			s.insert(seg);
		}
	}
	return ret;
}







template <class T>
vector<long long> press(vector<T> &v) {
	long long n = v.size();
	vector<long long> w(n);
	map<T, long long> m;
	for(T &p : v) m[p] = 0;
	long long i = 0;
	for(auto &p : m) {
		p.second = i;
		i++;
	}
	for(long long i = 0; i < n; i++) w.at(i) = m[v.at(i)];
	return w;
}







template <class T>
vector<long long> ranking(vector<T> &v) {
	vector<pair<T, long long>> r;
	long long n = v.size();
	rep(i, n) r.push_back({v[i], i});
	sort(all(r));
	vll res(n);
	rep(i, n) { res[r[i].second] = i; }
	return res;
}





template <class T>
vector<long long> sortedplace(vector<T> &v) {
	auto w = ranking(v);
	ll n = v.size();
	vll res(n);
	rep(i, n) res[w[i]] = i;
	return res;
}



template <class T>
map<T, long long> countv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}
















































template <class T>	

void warshall(vector<vector<T>> &v) {
	ll n = v.size();
	rep(i, n) rep(j, n) rep(k, n) v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
	return;
}









template <class T>
vector<T> id2(vector<T> &v) {
	ll h = v.size();
	V<T> ret(h + 1);
	ret[0] = 0;
	rep(i, h) ret[i + 1] = v[i] + ret[i];
	return ret;
}
template <class T>
T barsum(vector<T> &v, ll x0, ll x1) {
	if(x1 <= x0) return 0;
	return v[x1] - v[x0];
}


template <class T>
vector<vector<T>> id10(vector<vector<T>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v.at(0).size();
	VV<T> ret(h + 1, V<T>(w + 1));
	rep(i, h + 1) ret[i][0] = 0;
	rep(i, w + 1) ret[0][i] = 0;
	rep(i, h) rep(j, w) ret[i + 1][j + 1] = v[i][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i + 1][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i][j + 1];
	return ret;
}




template <class T>
T id7(vector<vector<T>> &v, ll x0, ll y0, ll x1, ll y1) {
	if(x0 >= x1 || y0 >= y1) return 0;
	return v[x0][y0] + v[x1][y1] - v[x0][y1] - v[x1][y0];
}


template <class T>
vector<vector<vector<T>>> id1(vector<vector<vector<T>>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v[0].size();
	assert(w != 0);
	ll z = v[0][0].size();
	VVV<T> ret(h + 1, VV<T>(w + 1, V<T>(z + 1)));
	rep(i, h + 1) rep(j, w + 1) rep(k, z + 1) { ret[i][j][k] = (i == 0 || j == 0 || k == 0 ? 0 : v[i - 1][j - 1][k - 1]); }
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j + 1][k];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j][k + 1];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i][j + 1][k + 1];
	return ret;
}




template <class T>
T id4(vector<vector<vector<T>>> &v, ll x0, ll y0, ll z0, ll x1, ll y1, ll z1) {
	if(x0 >= x1 || y0 >= y1 || z0 >= z1) return 0;
	return v[x1][y1][z1] - v[x1][y1][z0] - v[x1][y0][z1] - v[x0][y1][z1] + v[x1][y0][z0] + v[x0][y1][z0] + v[x0][y0][z1] - v[x0][y0][z0];
}







struct mint {
	

	

	

	

	ll x;  

	mint(ll x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a) {
		if((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator-=(const mint a) {
		if((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if(!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if(t & 1) a *= *this;
		return a;
	}

	

	mint inv() const { return pow(mod - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct UF {						

	vector<long long> par, sz;	

	

	UF(long long N) : par(N), sz(N) {  

		for(long long i = 0; i < N; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	long long root(long long x) {  

		if(par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(long long x, long long y) {	

		long long rx = root(x);				

		long long ry = root(y);				

		if(rx == ry) return;				

		par[rx] = ry;						

		sz[ry] += sz[rx];
		sz[rx] = 0;	 

	}

	bool same(long long x, long long y) {  

		long long rx = root(x);
		long long ry = root(y);
		return rx == ry;
	}
	long long size(long long x) { return sz[root(x)]; }
};

template <class T = ll>
struct BIT {
	

	vector<T> vec;
	ll n;
	BIT(long long sz) : vec(sz + 1, 0), n(sz) {}
	

	void add(long long place, T val, bool index = 0) {
		if(!index) place++;
		for(long long x = place; x <= n; x += x & -x) vec[x] += val;
	}
	

	T sum0(long long a, bool index = 0) {
		

		if(index) a--;
		T ret = 0;
		for(int x = a; x > 0; x -= x & -x) ret += vec[x];
		return ret;
	}
	

	T sum(long long a, long long b) { return sum0(b) - sum0(a); }
	

	void update(long long place, T val, bool index = 0) {
		T old = sum(place, place + 1);
		add(place, val - old);
		return;
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

};

template <class T = ll>
struct edge {
	T len;
	ll to;
};

template <class T = ll>
struct graph {	

	vector<vector<edge<T>>> edges;
	bool directed, weight;
	long long ver;

	

	graph(long long vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	

	void update(long long from, long long to, T len = 1, bool direction = 1) {
		edge<T> e;
		e.to = to;
		e.len = len;
		edges[from].push_back(e);
		if(!direction) {
			e.to = from;
			edges[to].push_back(e);
		}
	}

	

	void input(long long edge_num, long long index = 1) {
		rep(i, edge_num) {
			ll a;
			ll b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, directed);
		}
	}

	

	vector<T> dijkstra(long long start) {
		vector<T> ret(ver, (T)dekai);
		pqup<pair<T, long long>> p;	 

		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			ll place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				ll nextplace = next.to;
				T dis = next.len;
				if(chmin(ret[nextplace], dist + dis)) {
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	

	

	vector<T> BellmanFord(long long start) {
		vector<T> ret(ver, dekai);
		ret[start] = 0;
		rep(loop, ver - 1) {
			rep(v, ver) {
				for(auto &e : edges[v]) {
					chmin(ret[e.to], ret[v] + e.len);
				}
			}
		}

		

		queue<ll> q;
		vb chk(ver, 0);
		rep(v, ver) {
			for(auto &e : edges[v]) {
				if(chmin(ret[e.to], ret[v] + e.len)) {
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		rep(i, ver) if(chk[i]) ret[i] = -dekai;

		return ret;
	}

	

	

	vector<long long> topo_sort() {
		assert(directed);
		vector<long long> num_input(ver);
		

		for(long long i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		

		queue<long long> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<long long> ans;
		while(!que.empty()) {
			auto node = que.front();
			que.pop();
			ans.push_back(node);
			

			for(auto e : edges[node]) {
				num_input[e.to]--;
				

				if(num_input[e.to] == 0) {
					que.push(e.to);
				}
			}
		}
		return ans;
	}

	pair<pair<long long, long long>, T> DiameterOfTree() {	

		ll v1, v2;											

		V<T> dis(ver, -1);
		dis[0] = 0;
		queue<ll> q;
		q.push(0);
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(dis[e.to] != -1) continue;
				dis[e.to] = dis[now] + e.len;
				q.push(e.to);
			}
			if(q.empty()) v1 = now;
		}
		rep(i, ver) dis[i] = -1;
		dis[v1] = 0;
		q.push(v1);
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(dis[e.to] != -1) continue;
				dis[e.to] = dis[now] + e.len;
				q.push(e.to);
			}
			if(q.empty()) v2 = now;
		}
		pair<pll, T> ans = {{v1, v2}, dis[v2]};
		return ans;
	}

	

	graph<T> RootToLeaf(ll root) {	

		graph<T> ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	

	graph<T> LeafToRoot(ll root) {	

		graph<T> ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	

	vector<long long> par(ll root) {  

		vll ret(ver, -1);
		ret[root] = root;  

		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge<T>> ParentAndDistance(ll root) {  

		V<edge<T>> ret(ver);
		rep(i, ver) ret[i].to = -1;
		ret[root].to = root;  

		ret[root].len = 0;	  

		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(ret[e.to].to != -1) continue;
				ret[e.to].to = now;
				ret[e.to].len = e.len;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	

	VV<T> GraphArray(void) {
		VV<T> ret(ver, V<ll>(ver, dekai));
		rep(from, ver) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}
};



template <class T = ll>
struct STmax {	

	ll size;	

	ll m;		

	vector<T> seg;
	STmax(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(-99999999977); }
	}
	void update(ll i, T k) {  

		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = max(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 

		if(r <= a || b <= l) return -99999999977;
		if(a <= l && r <= b) return seg[k];
		

		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	T largest(ll a, ll b) {
		if(a >= b) return -99999999977;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct STmin {	

	ll size;	

	ll m;		

	vector<T> seg;
	STmin(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(99999999977); }
	}
	void update(ll i, T k) {  

		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = min(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 

		if(r <= a || b <= l) return 99999999977;
		if(a <= l && r <= b) return seg[k];
		

		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return min(vl, vr);
	}
	T smallest(ll a, ll b) {
		if(a >= b) return 99999999977;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct STsum {	

	ll size;	

	ll m;		

	vector<T> seg;
	STsum(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;

		rep(i, size) { seg.push_back(0); }
		

	}
	void update(ll i, T k) {  

		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;

			seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
			

		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 

		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return seg[k];
		

		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return vl + vr;	 

	}
	T sum(ll a, ll b) {
		if(a >= b) return 0;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct ST {	 

	STmax<T> stmax;
	STmin<T> stmin;
	STsum<T> stsum;
	ST(long long n) : stmax(n), stmin(n), stsum(n) {}
	void update(ll place, T val) {
		stmax.update(place, val);
		stmin.update(place, val);
		stsum.update(place, val);
	}
	T largest(ll a, ll b) { return stmax.largest(a, b); }
	T smallest(ll a, ll b) { return stmin.smallest(a, b); }
	T sum(ll a, ll b) { return stsum.sum(a, b); }
};

















































































































































int main() {
	ll n;
	cin >> n;
	

	vll a(n);
	rep(i, n) {
		ll aa;
		scanf("%lld", &aa);
		a[i] = aa;
	}
	ll res = 0;
	vll sums = id2(a);
	vll b = a;
	rep(i, n) b[i] *= -1;
	vll v = sortedplace(b);
	sll s = {-1, n};
	vpll range(n);
	rep(i, n) {
		auto mini = s.lower_bound(v[i]);
		auto maxi = s.lower_bound(v[i]);
		

		mini--;
		pll p = {1 + *mini, *maxi};
		range[v[i]] = p;
		s.insert(v[i]);
	}

	STmax<> lef(n + 1), rig(n + 1);
	rep(i, n + 1) {
		lef.update(i, barsum(sums, i, n));
		rig.update(i, barsum(sums, 0, i));
	}
	rep(i, n) {
		if(a[i] <= 0) continue;
		ll l, r;
		l = range[i].first;
		r = range[i].second;
		ll k = 0, c = 0;
		k += lef.largest(l, i + 1) - barsum(sums, i + 1, n);
		c += rig.largest(i + 1, r + 1) - barsum(sums, 0, i);
		chmax(res, k + c - a[i] * 2);
	}

	cout << res << endl;
}