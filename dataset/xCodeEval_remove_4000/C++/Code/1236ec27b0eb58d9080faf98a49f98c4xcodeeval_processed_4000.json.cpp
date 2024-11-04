


using namespace std;
















using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using qll = queue<long long>;
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

long long const dekai = 3e16;
const long double pi = acos(-1);
const char el = '\n';
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;







template <class T>
inline bool isin(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}

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

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
template <class T>
void drop(T answer) {
	cout << answer << "\n";
	exit(0);
}
void err() {
	cout << -1 << "\n";
	exit(0);
}

vector<long long> vin(long long n) {  

	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}





template <class T>
void vout(vector<T> &v, bool tate = 0) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) {
				if(tate)
					cout << endl;
				else
					cout << " ";
			}
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
map<T, long long> cntv(vector<T> v) {
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
int sgn(T x) {	

	if(x < 0) return -1;
	if(x == 0) return 0;
	return 1;
}

long long modpow(long long a, long long n, long long mod) {	 

	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}





long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
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



const ll MAX = 5100000;






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




	vector<type> name(size);  \
	INPUT(name)

	vector<vector<type>> name(h, vector<type>(w)); \
	INPUT(name)

	int id2; \
	INPUT(id2)

	long long id2; \
	INPUT(id2)

	string id2; \
	INPUT(id2)

	char id2; \
	INPUT(id2)

	double id2; \
	INPUT(id2)

	long double id2; \
	INPUT(id2)

template <class T>
void scan(T &a) {
	cin >> a;
}
template <class T>
void scan(vector<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
template <class T>
inline void print(T x) {
	cout << x << '\n';
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}




template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	rep(i, v.size()) {
		if(i) os << " ";
		os << v[i];
	}
	return os;
}

template <typename T>
void view(const std::vector<T> &v) {
	std::cerr << "{ ";
	for(const auto &e : v) {
		std::cerr << e << ", ";
	}
	std::cerr << "\b\b }";
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cerr << "{\n";
	for(const auto &v : vv) {
		std::cerr << "\t";
		view(v);
		cerr << "\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cerr << "{\n";
	for(const auto &c : v) {
		std::cerr << "\t(" << c.first << ", " << c.second << ")\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(auto &t : m) {
		std::cerr << "\t[" << t.first << "] : " << t.second << "\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}
template <typename T>
void view(T e) {
	std::cerr << e;
}




void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
	cerr << ", ";
	debug_out(T...);
}

	do {                                                     \
		cerr << __LINE__ << " [" << 
		debug_out(id2);                              \
		cerr << "\b\b]\n";                                   \
	} while(0)

	do {                                        \
		cerr << __LINE__ << " " << 
		view(x);                                \
		cerr << "\n";                           \
	} while(0)









template <class T = long long>
struct edge {
	T len;
	int from;
	int to;
	bool operator<(const edge a) const {
		if(len != a.len) return len < a.len;
		if(from != a.from) return from < a.from;
		return to < a.to;
	}
	bool operator>(const edge a) const {
		if(len != a.len) return len > a.len;
		if(from != a.from) return from > a.from;
		return to > a.to;
	}
};
template <class T = long long>
struct graph {	

	T const INF = numeric_limits<T>::max() / 3;
	vector<vector<edge<T>>> edges;
	int ver;

	

	graph() = default;
	graph(int vertex) : ver(vertex), edges(vertex) {}

	

	void update(int from, int to, T len = 1, bool direction = 1) {	

		edge<T> e;
		e.len = len;
		e.from = from;
		e.to = to;
		edges[from].push_back(e);
		if(!direction) {
			swap(e.to, e.from);
			edges[to].push_back(e);
		}
	}

	

	void input(int edge_num, bool direction = false, bool weight = false, int index = 1) {	

		for(int i = 0; i < edge_num; i++) {
			int a;
			int b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, direction);
		}
	}

	

	vector<T> bfs(int start) {	

		

		vector<T> ret(ver, INF);
		queue<int> q;
		q.push(start);
		ret[start] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(ret[e.to] != INF) continue;
				q.push(e.to);
				ret[e.to] = ret[now] + 1;
			}
		}
		return ret;
	}

	

	vector<T> dijkstra(int start) {	 

		

		vector<T> ret(ver, (T)INF);													  

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> p;  

		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			int place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				int nextplace = next.to;
				T dis = next.len;
				if(ret[nextplace] > dist + dis) {
					ret[nextplace] = dist + dis;
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	

	

	

	vector<T> BellmanFord(int start) {	

		

		vector<T> ret(ver, INF);
		ret[start] = 0;
		for(int loop = 0; loop < ver - 1; loop++) {
			for(int v = 0; v < ver; v++) {
				if(ret[v] == INF) continue;
				for(auto &e : edges[v]) {
					ret[e.to] = min(ret[e.to], ret[v] + e.len);
				}
			}
		}

		

		queue<int> q;
		vector<bool> chk(ver, 0);
		for(int v = 0; v < ver; v++) {
			if(ret[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(ret[e.to] > ret[v] + e.len) {
					ret[e.to] = ret[v] + e.len;
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		for(int i = 0; i < ver; i++)
			if(chk[i]) ret[i] = -INF;

		return ret;
	}

	

	

	vector<int> topo_sort() {  

		

		

		vector<int> num_input(ver);
		

		for(int i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		

		queue<int> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<int> ans;
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

	

	pair<pair<int, int>, T> DiameterOfTree(bool weigh = true) {	 

		

		vector<T> vec;
		vec = weigh ? dijkstra(0) : bfs(0);
		int v1 = -1;
		T dia = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				dia = vec[i];
				v1 = i;
			}

		vec = weigh ? dijkstra(v1) : bfs(v1);
		dia = -1;
		int v2 = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				v2 = i;
				dia = vec[i];
			}

		pair<pair<int, int>, T> ans = {{v1, v2}, dia};
		return ans;
	}

	

	graph<T> RootToLeaf(int root) {	 

		graph<T> ret(ver);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	

	graph<T> LeafToRoot(int root) {	 

		graph<T> ret(ver);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	

	vector<int> par(int root) {	 

		vector<int> ret(ver, -1);
		ret[root] = root;  

		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	vector<edge<T>> ParentAndDistance(int root) {  

		vector<edge<T>> ret(ver);
		for(int i = 0; i < ver; i++) ret[i].to = -1;
		ret[root].to = root;  

		ret[root].len = 0;	  

		function<void(int)> dfs = [&](int now) {
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

	

	vector<vector<T>> GraphArray(void) {  

		

		vector<vector<T>> ret(ver, vector<T>(ver, INF));
		for(int from = 0; from < ver; from++) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}

	graph<T> Prim(bool direction = 0, int start = 0) {	

		

		graph<T> ret(ver);
		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> p;
		for(auto &e : edges[start]) {
			p.push(e);
		}
		vector<bool> chk(ver, 0);
		chk[start] = 1;
		while(!p.empty()) {
			auto ed = p.top();
			p.pop();
			if(chk[ed.to]) continue;
			chk[ed.to] = 1;
			ret.update(ed.from, ed.to, ed.len, direction);
			for(auto &e : edges[ed.to]) {
				p.push(e);
			}
		}
		return ret;
	}

	

	vector<T> height(int start = 0) {  

		

		vector<T> fir(ver, -1), sec(ver, -1);
		function<T(int, int)> dfs = [&](int now, int par) {
			T f = 0, s = 0;	 

			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				s = max(s, dfs(e.to, now) + e.len);
				if(f < s) swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};
		dfs(start, -1);
		function<void(int, int, T, T, T)> sol = [&](int now, int par, T parf, T pars, T parlen) {
			if(fir[now] + parlen == parf) parf = pars;
			sec[now] = max(sec[now], parf + parlen);
			if(fir[now] < sec[now]) swap(fir[now], sec[now]);
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				sol(e.to, now, fir[now], sec[now], e.len);
			}
			return;
		};
		sol(start, -1, -1, -1, -1);
		return fir;
	}

	

	

	

	template <class U>
	vector<U> id1(function<U(U, U)> f, function<U(U)> g, U unit, int root = 0) {
		auto tr = RootToLeaf(root);
		vector<vector<U>> v(ver);
		vector<U> ret(ver);	 


		function<U(int)> dfs = [&](int now) {
			U res = unit;
			vector<U> vec;
			for(auto &e : tr.edges[now]) {
				U k = dfs(e.to);
				vec.push_back(k);
				res = f(res, k);
			}
			v[now] = vec;
			return g(res);
		};
		dfs(root);

		function<void(int, U)> dfs2 = [&](int now, U ans_par) {
			int sz = v[now].size();
			vector<U> mae(sz + 1), rev(sz + 1);
			mae[0] = rev[sz] = unit;
			for(int i = 0; i < sz; i++) mae[i + 1] = f(mae[i], v[now][i]);
			for(int i = sz - 1; i >= 0; i--) rev[i] = f(rev[i + 1], v[now][i]);
			for(int i = 0; i < sz; i++) {
				auto id3 = f(ans_par, f(mae[i], rev[i + 1]));
				dfs2(tr.edges[now][i].to, g(id3));
			}
			ret[now] = f(ans_par, mae[sz]);
			return;
		};
		dfs2(root, unit);

		return ret;
	}

	

};

bool sol() {
	LL(n, a, b, da, db);
	a--, b--;
	graph<> gra(n);
	gra.input(n - 1, 0);
	auto v = gra.bfs(a);
	dump(v);
	if(da * 2 >= db) return true;
	if(v[b] <= da) return true;
	ll dist = v[b];
	dist -= da;
	if(db - dist > da) {
		dist = db - da;
	}
	ll cnt = 0;
	while(dist >= da + db) {
		cnt++;
		dist -= (da + db);
		if(db - dist > da) {
			dist = db - da;
		}
	}
	dump(cnt);
	vi par = gra.par(a);
	ll now = b;
	dump(now);
	rep(i, cnt * db) { now = par[now]; }
	ll id0 = db;
	while(id0 > 0 && dist > 1) {
		if(id0 + dist - 2 > da) {
			id0--;
			dist--;
			now = par[now];
		} else
			break;
	}

	auto tr = gra.RootToLeaf(now);
	function<pll(int)> dfs = [&](int ima) {
		if(ima == now) {
			ll fir = 0, sec = 0;
			foa(e, tr.edges[ima]) {
				if(chmax(sec, dfs(e.to).first)) {
					if(fir < sec) swap(fir, sec);
				}
			}
			return (pll){fir, sec};
		}
		ll ret = 0;
		foa(e, tr.edges[ima]) { chmax(ret, dfs(e.to).first); }
		return (pll){ret + 1, 0};
	};
	pll result = dfs(now);
	dump(result);
	if(result.first <= da * 2) return true;
	return false;
}

bool sol2() {
	LL(n, a, b, da, db);
	a--, b--;
	graph<> gra(n);
	gra.input(n - 1, 0);
	auto v = gra.bfs(a);
	

	if(da * 2 >= db) return true;
	if(v[b] <= da) return true;
	ll dist = v[b];
	vll h = gra.height();
	dump(h);
	rep(i, n) {
		if(h[i] <= da) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));

	int t;
	cin >> t;
	vector<bool> ans(t);
	for(int i = 0; i < t; i++) {
		bool res = 0;
		res = sol2();
		ans[i] = res;
	}
	for(int i = 0; i < t; i++) {
		cout << (ans[i] ? "Alice" : "Bob") << endl;
	}

	return 0;
}
