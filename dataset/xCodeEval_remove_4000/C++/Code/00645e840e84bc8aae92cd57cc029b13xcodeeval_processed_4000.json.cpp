













template <class T0, class T1, class T2>
inline bool in_range(T0 x, T1 lef, T2 rig) {
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

void Yes(bool flag = true) { std::cout << (flag ? "Yes" : "No") << '\n'; }
void YES(bool flag = true) { std::cout << (flag ? "YES" : "NO") << '\n'; }

template <class T>
void drop(T answer) {
	std::cout << answer << '\n';
	exit(0);
}

template <class T>
void vout(std::vector<T> const &v, bool vertically = 0) {
	if(vertically) {
		for(auto const &a : v) {
			std::cout << a << '\n';
		}
		return;
	}
	for(auto it = v.begin(); it != v.end(); it++) {
		std::cout << (*it);
		if(it != v.end() - 1) {
			std::cout << ' ';
		}
	}
	std::cout << '\n';
	return;
}

inline void print() { std::cout << '\n'; }
template <class T>
inline void print(const T &x) {
	std::cout << x << '\n';
	return;
}
template <typename Head, typename... Tail>
void print(const Head &H, const Tail &... T) {
	std::cout << H << " ";
	print(T...);
}

template <class T>
void add(std::vector<T> &v, T value) {
	for(auto &a : v) a += value;
	return;
}

template <class T>
T id5(T x, T d) {
	if(d == 0) return 0;
	if(d < 0) d *= -1;
	T y = x % d;
	if(y < 0) y += d;
	return x - y;
}

template <class T>
T id2(T x, T d) {
	return -id5(-x, d);
}



template <class T>
T dup(T a, T b) {
	assert(b);
	if(b < 0) {
		a *= -1;
		b *= -1;
	}
	return id2(a, b) / b;
}

long long pow_ll(long long a, long long n) {
	assert(n >= 0LL);
	if(n == 0) return 1LL;
	if(a == 0) return 0LL;
	if(a == 1) return 1LL;
	if(a == -1) return (n & 1LL) ? -1LL : 1LL;
	long long res = 1;
	while(n > 1LL) {
		if(n & 1LL) res *= a;
		a *= a;
		n >>= 1;
	}
	return res * a;
}

long long modpow(long long a, long long n, long long mod) {	 

	assert(n >= 0 && mod);
	if(mod == 1) return 0LL;
	long long res = 1;
	a %= mod;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res < 0 ? res + mod : res;
}





long long modinv(long long a, const long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		std::swap(a, b);
		u -= t * v;
		std::swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

template <class T>
int lb(const std::vector<T> &a, const T x) {
	return (int)std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), x));
}
template <class T>
int ub(const std::vector<T> &a, const T x) {
	return (int)std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), x));
}
template <class T>
void id4(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<int> press(const std::vector<T> &a) {
	std::vector<T> vec = a;
	id4(vec);
	std::vector<int> ret;
	for(const auto &v : a) ret.push_back(lb(vec, v));
	return ret;
}










constexpr int inf = 1000'000'000;
constexpr long long INF = 1'000'000'000'000'000'000LL;
constexpr int id1 = 1000000007;
constexpr int id6 = 998244353;
const long double pi = acosl(-1.);
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


namespace viewer {

template <typename T, typename U>
void view(const std::pair<T, U> &p);

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p);

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p);

void view(const long long &e);

void view(const int &e);

template <typename T>
void view(const T &e);

template <typename T>
void view(const std::set<T> &s);

template <typename T>
void view(const std::unordered_set<T> &s);

template <typename T>
void view(const std::multiset<T> &s);

template <typename T>
void view(const std::unordered_multiset<T> &s);

template <typename T>
void view(const std::vector<T> &v);

template <typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v);

template <typename T>
void view(const std::vector<std::vector<T>> &vv);

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v);

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v);

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v);

template <typename map_type>
void id0(const map_type &m);

template <typename T, typename U>
void view(const std::map<T, U> &m);

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m);

template <typename container_type>
void view_container(const container_type &c, bool vertically = false) {
	typename container_type::const_iterator begin = c.begin();
	const typename container_type::const_iterator end = c.end();
	if(vertically) {
		std::cerr << "{\n";
		while(begin != end) {
			std::cerr << '\t';
			view(*(begin++));
			if(begin != end) std::cerr << ',';
			std::cerr << '\n';
		}
		std::cerr << '}';
		return;
	}
	std::cerr << "{ ";
	while(begin != end) {
		view(*(begin++));
		if(begin != end) std::cerr << ',';
		std::cerr << ' ';
	}
	std::cerr << '}';
}

template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << '(';
	view(p.first);
	std::cerr << ", ";
	view(p.second);
	std::cerr << ')';
}

template <class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p) {
	std::cerr << '(';
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ')';
}

template <class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p) {
	std::cerr << '(';
	view(std::get<0>(p));
	std::cerr << ", ";
	view(std::get<1>(p));
	std::cerr << ", ";
	view(std::get<2>(p));
	std::cerr << ", ";
	view(std::get<3>(p));
	std::cerr << ')';
}

void view(const long long &e) {
	if(e == INF)
		std::cerr << "INF";
	else if(e == -INF)
		std::cerr << "-INF";
	else
		std::cerr << e;
}

void view(const int &e) {
	if(e == inf)
		std::cerr << "inf";
	else if(e == -inf)
		std::cerr << "-inf";
	else
		std::cerr << e;
}

template <typename T>
void view(const T &e) {
	std::cerr << e;
}

template <typename T>
void view(const std::set<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::unordered_set<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::multiset<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::unordered_multiset<T> &s) {
	view_container(s);
}

template <typename T>
void view(const std::vector<T> &v) {
	view_container(v);
}

template <typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v) {
	view_container(v);
}

template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	view_container(vv, true);
}

template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	view_container(v, true);
}

template <class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v) {
	view_container(v, true);
}

template <class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v) {
	view_container(v, true);
}

template <typename map_type>
void id0(const map_type &m) {
	std::cerr << "{\n";
	for(typename map_type::const_iterator it = m.begin(); it != m.end(); it++) {
		std::cerr << "\t[";
		view(it->first);
		std::cerr << "] : ";
		view(it->second);
		std::cerr << '\n';
	}
	std::cerr << "}";
}

template <typename T, typename U>
void view(const std::map<T, U> &m) {
	id0(m);
}

template <typename T, typename U>
void view(const std::unordered_map<T, U> &m) {
	id0(m);
}

}  





void debug_out() {}
template <typename T>
void debug_out(const T &x) {
	viewer::view(x);
}
template <typename Head, typename... Tail>
void debug_out(const Head &H, const Tail &... T) {
	viewer::view(H);
	std::cerr << ", ";
	debug_out(T...);
}

	do {                                                          \
		std::cerr << __LINE__ << " [" << 
		debug_out(id3);                                   \
		std::cerr << "]\n";                                       \
	} while(0)







namespace scanner {
template <class T>
void scan(T &a) {
	std::cin >> a;
}

template <class T, class L>
void scan(std::pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}

template <class T0, class T1, class T2>
void scan(std::tuple<T0, T1, T2> &p) {
	T0 t0;
	T1 t1;
	T2 t2;
	scan(t0);
	scan(t1);
	scan(t2);
	p = std::make_tuple(t0, t1, t2);
}

template <class T0, class T1, class T2, class T3>
void scan(std::tuple<T0, T1, T2, T3> &p) {
	T0 t0;
	T1 t1;
	T2 t2;
	T3 t3;
	scan(t0);
	scan(t1);
	scan(t2);
	scan(t3);
	p = std::make_tuple(t0, t1, t2, t3);
}

template <class T>
void scan(std::vector<T> &a) {
	for(auto &i : a) scan(i);
}

void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  




	vector<type> name(size);  \
	scanner::INPUT(name)

	vector<vector<type>> name(h, vector<type>(w)); \
	scanner::INPUT(name)

	int id3; \
	scanner::INPUT(id3)

	long long id3; \
	scanner::INPUT(id3)

	string id3; \
	scanner::INPUT(id3)

	char id3; \
	scanner::INPUT(id3)

	double id3; \
	scanner::INPUT(id3)

	long double id3; \
	scanner::INPUT(id3)

	std::tuple<type0, type1, type2> name; \
	scanner::INPUT(name);

	std::tuple<type0, type1, type2, type3> name; \
	scanner::INPUT(name);

template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
	os << p.first << ' ' << p.second;
	return os;
}

struct fast_io {
	fast_io() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout << std::fixed << std::setprecision(15);
		srand((unsigned)time(NULL));
	}
} id7;



















using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vvvi = std::vector<std::vector<std::vector<int>>>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
template <class T = ll>
using V = std::vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
template <class T = ll>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T = ll>
using pqdn = std::priority_queue<T>;


using namespace std;


void solve() {
	INT(n, k);
	vector<vector<int>> s(n);
	vector<int> zeros;
	vector<set<int>> z_place;
	foa(v, s) {
		rep(i, n) {
			char c;
			cin >> c;
			v.push_back(int(c - '0'));
		}
		int z = 0;
		set<int> zs;
		rep(i, n) {
			int c = v[i];
			if(c == 0) {
				z++;
				zs.insert(i);
			}
		}
		zeros.push_back(z);
		z_place.push_back(zs);
	}

	vector<vi> ans(n, vi(n, 0));

	rep(i, k - 1) {
		const int start_y = n - 1 + i - (k - 2);
		int x = 0;
		int y = start_y;

		auto is_valid = [&](int new_x, int new_y) -> bool {
			if(!in_range(new_x, 0, n)) return false;
			if(!in_range(new_y, 0, n)) return false;
			if(ans[new_x][new_y]) return false;
			return true;
		};

		auto erase_zero = [&]() -> void {
			ans[x][y] = 1;
			if(s[x][y] == 0) {
				zeros[x]--;
				z_place[x].erase(y);
			}
			return;
		};

		erase_zero();

		while(y > 0 || x < start_y) {
			auto& zs = z_place[x];
			debug(x, y);

			if((zs.empty() || y < *(zs.begin())) && x + 1 <= start_y && is_valid(x + 1, y)) {
				debug(x, y);
				x++;
				erase_zero();
			} else if(is_valid(x, y - 1)) {
				debug(x, y);
				y--;
				erase_zero();
			} else {
				debug(x, y);
				debug(ans);
				cout << "NO\n";
				return;
			}
		}
	}

	foa(z, zeros) if(z) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	foa(v, ans) {
		foa(c, v) { cout << c; }
		cout << '\n';
	}
	return;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
