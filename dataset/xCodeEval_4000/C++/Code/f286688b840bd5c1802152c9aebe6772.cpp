#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <climits>
#include <ios>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <utility>
#include <vector>
#ifdef LOVE_LKT
	#include "code/formatting.hpp"
#else
	#define debug(...) (void)0
#endif

using namespace std;




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define vt std::vector
#define MP std::unordered_map
typedef std::queue<int> qq;
#define MG std::multiset<std::string, std::greater<std::string>>
#define ll long long
#define ld long double
#define pb push_back
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define all(c) (c).begin(), (c).end()
#define ar array
#define pp std::pair<ll,ll>
#define elif else if
#define fi(a) std::cout<<std::fixed<<std::setprecision(a)
#define TE true
#define FE false
#define sd second
#define ft first
#define sqr(a) a*a
#define sz(x) (int)(x).size()
#define vb vt<bool>
#define vpll vt<pp>
#define vtll vt<vt<ll>>
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FO(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define mp make_pair


template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) { return a<b?a=b, 1:0;} 
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {while(lb<rb) {ll mb=(lb+rb)/2;f(mb)?rb=mb:lb=mb+1; } return lb;}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {while(lb<rb) {ll mb=(lb+rb+1)/2;f(mb)?lb=mb:rb=mb-1; } return lb;}
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {string t;read(t);d=stod(t);}
void read(long double& d) {string t;read(t);d=stold(t);}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vt<A>& x) {EACH(a, x)read(a);}
template<class A, size_t S> void read(array<A, S>& x) {EACH(a, x)read(a);}
std::string to_string(char c) {return string(1, c);}
std::string to_string(bool b) {return b?"true":"false";}
std::string to_string(const char* s) {return string(s);}
std::string to_string(string s) {return s;}
std::string to_string(vt<bool> v) {string ans;FO(sz(v)) ans+=char('0'+v[i]);return ans;}
template<size_t S> string to_string(bitset<S> b) {string ans;FO(S) ans+=char('0'+b[i]);return ans;}
template<class T> string to_string(T v) {bool f=1;string ans;EACH(x, v) {if(!f)ans+=' ';f=0;ans+=to_string(x);}return ans;}
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) { write(h);write(t...);}
void print() {write("\n");}
template<class H, class... T> void print(const H& h, const T&... t) { write(h);if(sizeof...(t)) write(' ');print(t...);}


template<class Fun> class y_combinator_ansult {
	Fun fun_;
public:
	template<class T> explicit y_combinator_ansult(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_ansult<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef TRAN_KHANH_LINH
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


template<class T> void offset(ll o, T& x) {x+=o;}
template<class T> void offset(ll o, vt<T>& x) {EACH(a, x) offset(o, a);}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {EACH(a, x) offset(o, a);}
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {return uniform_int_distribution<ll>(a, b)(mt_rng);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {v=vt<T>(n);EACH(a, v) vti(a, x, m);}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

struct linhkhanhtran {
	string a;int sign;
	linhkhanhtran() {}
	void operator = (string b){a = (b[0] == '-' ? b.substr(1) : b);reverse(all(a));(*this).Remove0(b[0] == '-' ? -1 : 1);}
	linhkhanhtran(string x) {(*this) = x;}
	linhkhanhtran(ll x) { (*this) = to_string(x); }
	void operator = (ll x) {*this = to_string(x);}
	char operator[](int i) {return a[i];}
	int size() {return a.size();}
	linhkhanhtran inverseSign() {sign *= -1; return (*this);}
	linhkhanhtran Remove0(int newSign) {sign = newSign;for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--) a.pop_back();if (a.size() == 1 && a[0] == '0') sign = 1;return (*this);}
	bool operator == (linhkhanhtran x) {return sign == x.sign && a == x.a;}
	bool operator == (string x) {return *this == linhkhanhtran(x);}
	bool operator == (ll x) {return *this == linhkhanhtran(x);}
	bool operator != (linhkhanhtran x) {return !(*this == x);}
	bool operator != (string x) {return !(*this == x);}
	bool operator != (ll x) {return !(*this == x);}
	bool operator < (linhkhanhtran b) {if (sign != b.sign) return sign < b.sign;if (a.size() != b.size()) return a.size() * sign < b.size()* sign;for (int i = a.size() - 1; i >= 0; i--)if (a[i] != b[i]) return a[i] < b[i];return false;}
	bool operator <  (string x) {return *this < linhkhanhtran(x);}
	bool operator <  (ll x) {return *this < linhkhanhtran(x);}
	bool operator <= (linhkhanhtran b) {return *this == b || *this < b;}
	bool operator <= (string b) {return *this == b || *this < b;}
	bool operator <= (ll b) {return *this == b || *this < b;}
	bool operator >  (linhkhanhtran b) {return !(*this == b || *this < b);}
	bool operator >  (string x) {return !(*this == x || *this < x);}
	bool operator >  (ll b) {return !(*this == b || *this < b);}
	bool operator >= (linhkhanhtran b) {return *this == b || *this > b;}
	bool operator >= (string b) {return *this == b || *this > b;}
	bool operator >= (ll b) {return *this == b || *this > b;}
	linhkhanhtran operator + (linhkhanhtran b) {if (sign != b.sign) return (*this) - b.inverseSign();linhkhanhtran ans;for (int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++) {if (i < a.size()) carry += a[i] - '0';if (i < b.size()) carry += b[i] - '0';ans.a += (carry % 10 + 48);carry /= 10;}return ans.Remove0(sign);}
	linhkhanhtran operator +  (string x) {return *this + linhkhanhtran(x);}
	linhkhanhtran operator +  (ll x) {return *this + linhkhanhtran(x);}
	linhkhanhtran operator ++ (int) {*this += 1; return *this - 1;}
	linhkhanhtran operator ++ () {*this += 1; return *this;}
	void operator += (linhkhanhtran x) {*this = *this + x;}
	void operator += (string x) {*this = *this + x;}
	void operator += (ll x) {*this = *this + x;}
	linhkhanhtran operator - (linhkhanhtran b) {if (sign != b.sign) return (*this) + b.inverseSign();if (*this < b) return (b - *this).inverseSign();linhkhanhtran sub;for (int i = 0, borrow = 0; i < a.size(); i++) {borrow = a[i] - borrow - (i < b.size() ? b.a[i] : '0');sub.a += borrow >= 0 ? borrow + '0' : borrow + 58;borrow = borrow >= 0 ? 0 : 1;}return sub.Remove0(sign);}
	linhkhanhtran operator - (string x) {return *this - linhkhanhtran(x);}
	linhkhanhtran operator - (ll x) {return *this - linhkhanhtran(x);}
	linhkhanhtran operator -- (int) {*this -= 1; return *this + 1;}
	linhkhanhtran operator -- () {*this -= 1; return *this;}
	void operator -= (linhkhanhtran x) {*this = *this - x;}
	void operator -= (string x) {*this = *this - x;}
	void operator -= (ll x) {*this = *this - x;}
	linhkhanhtran operator * (linhkhanhtran b) {linhkhanhtran mult("0");for (int i = 0, k = a[i]; i < a.size(); i++, k = a[i]) {while (k-- - '0') mult = mult + b;b.a.insert(b.a.begin(), '0');}return mult.Remove0(sign * b.sign);}
	linhkhanhtran operator * (string x) {return *this * linhkhanhtran(x);}
	linhkhanhtran operator * (ll x) {return *this * linhkhanhtran(x);}
	void operator *= (linhkhanhtran x) {*this = *this * x;}
	void operator *= (string x) {*this = *this * x;}
	void operator *= (ll x) {*this = *this * x;}
	linhkhanhtran operator / (linhkhanhtran b) {if (b.size() == 1 && b[0] == '0') b.a[0] /= (b[0] - '0');linhkhanhtran c("0"), d;for (int j = 0; j < a.size(); j++) d.a += "0";int dSign = sign * b.sign; b.sign = 1;for (int i = a.size() - 1; i >= 0; i--) {c.a.insert(c.a.begin(), '0');c = c + a.substr(i, 1);while (!(c < b)) c = c - b, d.a[i]++;}return d.Remove0(dSign);}
	linhkhanhtran operator / (string x) {return *this / linhkhanhtran(x);}
	linhkhanhtran operator / (ll x) {return *this / linhkhanhtran(x);}
	void operator /= (linhkhanhtran x) {*this = *this / x;}
	void operator /= (string x) {*this = *this / x;}
	void operator /= (ll x) {*this = *this / x;}
	linhkhanhtran operator % (linhkhanhtran b) {if (b.size() == 1 && b[0] == '0') b.a[0] /= (b[0] - '0');linhkhanhtran c("0");int cSign = sign * b.sign; b.sign = 1;for (int i = a.size() - 1; i >= 0; i--) {c.a.insert(c.a.begin(), '0');c = c + a.substr(i, 1);while (!(c < b)) c = c - b;}return c.Remove0(cSign);}
	linhkhanhtran operator % (string x) {return *this % linhkhanhtran(x);}
	linhkhanhtran operator % (ll x) {return *this % linhkhanhtran(x);}
	void operator %= (linhkhanhtran x) {*this = *this % x;}
	void operator %= (string x) {*this = *this % x;}
	void operator %= (ll x) {*this = *this % x;}
	void print() {if (sign == -1) putchar('-');for (int i = a.size() - 1; i >= 0; i--) putchar(a[i]);}
	friend istream& operator >>(istream& in, linhkhanhtran& x) {string s; in >> s; x = s; return in;}
	friend ostream& operator <<(ostream& out, linhkhanhtran& x) {if (x.sign == -1) putchar('-');for (int i = x.size() - 1; i >= 0; i--)putchar(x[i]);putchar(' ');return out;}
	friend linhkhanhtran pow(linhkhanhtran base, linhkhanhtran pw) {linhkhanhtran linhkhanhtran = 1;while (pw != 0) {if (pw % 2 != 0) linhkhanhtran *= base;base *= base, pw /= 2;}return linhkhanhtran;}
	friend linhkhanhtran pow(linhkhanhtran a, linhkhanhtran b, linhkhanhtran mod) {if (b == 0) return linhkhanhtran(1);linhkhanhtran tmp = pow(a, b / 2, mod);if ((b % 2) == 0) return (tmp * tmp) % mod;else return (((tmp * tmp) % mod) * a) % mod;}
	friend linhkhanhtran sqrt(linhkhanhtran x) {linhkhanhtran linhkhanhtran = x, tmp = (x + 1) / 2;while (tmp < linhkhanhtran) linhkhanhtran = tmp, tmp = (tmp + x / tmp) / 2;return linhkhanhtran;}
	friend linhkhanhtran gcd(linhkhanhtran a, linhkhanhtran b) {return a % b == 0 ? b : gcd(b, a % b);}
	friend linhkhanhtran lcm(linhkhanhtran a, linhkhanhtran b) {return a / gcd(a, b);}
};

ll i,j;
#define MODS 100005
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
const int maxn = 1e3 + 5;
const int M = int(1e9) + 5;
const int N = 1e6 + 5;
struct iu{ std::string love ;} linh[100];
struct tranlinh{ int va;int in; };
struct segment_change {
	array<int, 2> sum_change;
	bool toggle;
 
	segment_change(array<int, 2> _sum_change = {0, 0}, bool _toggle = false)
		: sum_change(_sum_change), toggle(_toggle) {}
 
	bool has_change() const {
		return sum_change != array<int, 2>{0, 0} || toggle;
	}
 
	

	segment_change combine(const segment_change &other) const {
		return segment_change({sum_change[0] + other.sum_change[0], sum_change[1] + other.sum_change[1]},
							  toggle ^ other.toggle);
	}
};
 
struct segment {
	array<int, 2> max_sum_needs;  

	array<int64_t, 2> sum_up_edges;  

 
	segment(array<int, 2> sum_needs = {0, 0}, int up_edge = 0)
		: max_sum_needs(sum_needs), sum_up_edges({0, up_edge}) {}
 
	void apply(int, const segment_change &change) {
		for (int x = 0; x < 2; x++)
			max_sum_needs[x] += change.sum_change[x];
 
		if (change.toggle)
			swap(sum_up_edges[0], sum_up_edges[1]);
	}
 
	void join(const segment &other) {
		for (int x = 0; x < 2; x++) {
			max_sum_needs[x] = max(max_sum_needs[x], other.max_sum_needs[x]);
			sum_up_edges[x] += other.sum_up_edges[x];
		}
	}
 
	void join(const segment &a, const segment &b) {
		*this = a;
		join(b);
	}
};
 
pair<int, int> right_half[32];
 
struct seg_tree {
	static int highest_bit(unsigned x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}
 
	int tree_n = 0;
	vector<segment> tree;
	vector<segment_change> changes;
 
	seg_tree(int n = -1) {
		if (n >= 0)
			init(n);
	}
 
	void init(int n) {
		tree_n = 1;
 
		while (tree_n < n)
			tree_n *= 2;
 
		tree.assign(2 * tree_n, segment());
		changes.assign(tree_n, segment_change());
	}
 
	

	void build(const vector<segment> &initial) {
		int n = int(initial.size());
		init(n);
		assert(n <= tree_n);
 
		for (int i = 0; i < n; i++)
			tree[tree_n + i] = initial[i];
 
		for (int position = tree_n - 1; position > 0; position--)
			tree[position].join(tree[2 * position], tree[2 * position + 1]);
	}
 
	void apply_and_combine(int position, int length, const segment_change &change) {
		tree[position].apply(length, change);
 
		if (position < tree_n)
			changes[position] = changes[position].combine(change);
	}
 
	void push_down(int position, int length) {
		if (changes[position].has_change()) {
			apply_and_combine(2 * position, length / 2, changes[position]);
			apply_and_combine(2 * position + 1, length / 2, changes[position]);
			changes[position] = segment_change();
		}
	}
 
	

	void push_all(int a, int b) {
		assert(0 <= a && a < b && b <= tree_n);
		a += tree_n;
		b += tree_n - 1;
 
		for (int up = highest_bit(tree_n); up > 0; up--) {
			int x = a >> up, y = b >> up;
			push_down(x, 1 << up);
			if (x != y) push_down(y, 1 << up);
		}
	}
 
	void join_and_apply(int position, int length) {
		tree[position].join(tree[2 * position], tree[2 * position + 1]);
		tree[position].apply(length, changes[position]);
	}
 
	

	void join_all(int a, int b) {
		assert(0 <= a && a < b && b <= tree_n);
		a += tree_n;
		b += tree_n - 1;
		int length = 1;
 
		while (a > 1) {
			a /= 2;
			b /= 2;
			length *= 2;
			join_and_apply(a, length);
			if (a != b) join_and_apply(b, length);
		}
	}
 
	template<typename T_range_op>
	void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
		if (a == b) return;
		push_all(a, b);
		int original_a = a, original_b = b;
		int length = 1, r_size = 0;
 
		for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
			if (a & 1)
				range_op(a++, length);
 
			if (b & 1)
				right_half[r_size++] = {--b, length};
		}
 
		for (int i = r_size - 1; i >= 0; i--)
			range_op(right_half[i].first, right_half[i].second);
 
		if (needs_join)
			join_all(original_a, original_b);
	}
 
	segment query(int a, int b) {
		assert(0 <= a && a <= b && b <= tree_n);
		segment answer;
 
		process_range(a, b, false, [&](int position, int) {
			answer.join(tree[position]);
		});
 
		return answer;
	}
 
	segment query_full() const {
		return tree[1];
	}
 
	void update(int a, int b, const segment_change &change) {
		assert(0 <= a && a <= b && b <= tree_n);
 
		process_range(a, b, true, [&](int position, int length) {
			apply_and_combine(position, length, change);
		});
	}
 
	void update_single(int index, const segment &seg) {
		assert(0 <= index && index < tree_n);
		int position = tree_n + index;
 
		for (int up = highest_bit(tree_n); up > 0; up--)
			push_down(position >> up, 1 << up);
 
		tree[position] = seg;
 
		while (position > 1) {
			position /= 2;
			tree[position].join(tree[2 * position], tree[2 * position + 1]);
		}
	}
 
	vector<segment> to_array() {
		for (int i = 1; i < tree_n; i++)
			push_down(i, tree_n >> highest_bit(i));
 
		vector<segment> segs(tree_n);
 
		for (int i = 0; i < tree_n; i++)
			segs[i] = tree[tree_n + i];
 
		return segs;
	}
 
	

	template<typename T_bool>
	int find_last_subarray(T_bool &&should_join, int n, int first = 0) {
		assert(0 <= first && first <= n);
		segment current;
 
		

		if (!should_join(current, current))
			return first - 1;
 
		return y_combinator([&](auto search, int position, int start, int end) -> int {
			if (end <= first) {
				return end;
			} else if (first <= start && end <= n && should_join(current, tree[position])) {
				current.join(tree[position]);
				return end;
			} else if (end - start == 1) {
				return start;
			}
 
			push_down(position, end - start);
			int mid = (start + end) / 2;
			int left = search(2 * position, start, mid);
			return left < mid ? left : search(2 * position + 1, mid, end);
		})(1, 0, tree_n);
	}
};
 
 
struct subtree_heavy_light {
	int n = 0;
	bool vertex_mode;
 
	vector<vector<int>> adj;
	vector<int> parent, depth, subtree_size;
 
	vector<int> tour_start, tour_end;
	vector<int> chain_root;
	seg_tree full_tree;
 
	subtree_heavy_light() {}
 
	subtree_heavy_light(int _n, bool _vertex_mode) {
		init(_n, _vertex_mode);
	}
 
	void init(int _n, bool _vertex_mode) {
		n = _n;
		vertex_mode = _vertex_mode;
 
		adj.assign(n, {});
		parent.resize(n);
		depth.resize(n);
		subtree_size.resize(n);
 
		tour_start.resize(n);
		tour_end.resize(n);
		chain_root.resize(n);
	}
 
	void add_edge(int a, int b) {
		 adj[a].push_back(b);
		 adj[b].push_back(a);
	}
 
	void dfs(int node, int par) {
		parent[node] = par;
		depth[node] = par < 0 ? 0 : depth[par] + 1;
		subtree_size[node] = 1;
 
		

		adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());
 
		for (int child : adj[node]) {
			dfs(child, node);
			subtree_size[node] += subtree_size[child];
		}
 
		

		sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
			return subtree_size[a] > subtree_size[b];
		});
	}
 
	int tour;
 
	void chain_dfs(int node, bool heavy) {
		chain_root[node] = heavy ? chain_root[parent[node]] : node;
		tour_start[node] = tour++;
		bool heavy_child = true;
 
		for (int child : adj[node]) {
			chain_dfs(child, heavy_child);
			heavy_child = false;
		}
 
		tour_end[node] = tour;
	}
 
	void build(const segment &initial) {
		tour = 0;
		parent.assign(n, -1);
 
		for (int i = 0; i < n; i++)
			if (parent[i] < 0) {
				dfs(i, -1);
				chain_dfs(i, false);
			}
 
		full_tree.init(n);
		full_tree.build(vector<segment>(n, initial));
	}
 
	void update_subtree(int v, const segment_change &change) {
		full_tree.update(tour_start[v] + (vertex_mode ? 0 : 1), tour_end[v], change);
	}
 
	segment query_subtree(int v) {
		return full_tree.query(tour_start[v] + (vertex_mode ? 0 : 1), tour_end[v]);
	}
 
	void update_single(int v, const segment &seg) {
		full_tree.update_single(tour_start[v] + (vertex_mode ? 0 : 1), seg);
	}
 
	template<typename T_tree_op>
	int process_path(int u, int v, T_tree_op &&op) {
		while (chain_root[u] != chain_root[v]) {
			

			if (depth[chain_root[u]] > depth[chain_root[v]])
				swap(u, v);
 
			int root = chain_root[v];
			op(full_tree, tour_start[root], tour_start[v] + 1);
			v = parent[root];
		}
 
		if (depth[u] > depth[v])
			swap(u, v);
 
		

		op(full_tree, tour_start[u] + (vertex_mode ? 0 : 1), tour_start[v] + 1);
		return u;
	}
 
	int get_lca(int u, int v) {
		return process_path(u, v, [&](seg_tree &, int, int){});
	}
 
	segment query_path(int u, int v) {
		segment answer;
 
		process_path(u, v, [&](seg_tree &tree, int a, int b) {
			answer.join(tree.query(a, b));
		});
 
		return answer;
	}
 
	void update_path(int u, int v, const segment_change &change) {
		process_path(u, v, [&](seg_tree &tree, int a, int b) {
			tree.update(a, b, change);
		});
	}
}c;

void slove(){
	int N;
	cin >> N;
	subtree_heavy_light HLD(N, true);
	vector<array<int, 2>> edges(N - 1);
 
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		HLD.add_edge(u, v);
		edges[i] = {u, v};
	}
 
	HLD.build(segment());
	vector<int> up_edge(N, 0);
 
	for (int i = 0; i < N - 1; i++) {
		int u = edges[i][0], v = edges[i][1];
		int deeper = HLD.depth[u] > HLD.depth[v] ? u : v;
		up_edge[deeper] = i + 1;
	}
 
	auto activate = [&](int v) -> void {
		int depth = HLD.depth[v];
		array<int, 2> sum_needs = depth % 2 ? array<int, 2>{-M, 0} : array<int, 2>{0, -M};
		HLD.update_single(v, segment(sum_needs, up_edge[v]));
		array<int, 2> sum_change = depth % 2 ? array<int, 2>{+1, -1} : array<int, 2>{-1, +1};
 
		if (HLD.parent[v] >= 0)
			HLD.update_path(HLD.parent[v], 0, segment_change(sum_change, true));
	};
 
	activate(0);
 
	auto query = [&]() -> int64_t {
		segment seg = HLD.query_subtree(0);
 
		if (max(seg.max_sum_needs[0], seg.max_sum_needs[1]) >= 2)
			return 0;
 
		if (HLD.query_path(0, 0).max_sum_needs[0] != 1)
			return 0;
 
		return seg.sum_up_edges[1];
	};
 
	auto print_edges = [&]() -> void {
		if (query() == 0) {
			cout << 0 << endl;
			return;
		}
 
		vector<int> answer;
 
		for (int v = 1; v < N; v++)
			if (HLD.query_path(v, v).sum_up_edges[1] > 0)
				answer.push_back(up_edge[v]);
 
		sort(answer.begin(), answer.end());
		cout << answer.size();
 
		for (int e : answer)
			cout << ' ' << e;
 
		cout << endl;
	};
 
	int type;
 
	while (cin >> type) {
		if (type == 0 || type == 3) {
			return;
		} else if (type == 1) {
			int v;
			cin >> v;
			v--;
			activate(v);
			cout << query() << endl;
			continue;
		} else if (type == 2) {
			print_edges();
		} else {
			assert(false);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
#ifndef TRAN_KHANH_LINH
	std::cin.tie(nullptr);
#endif
	
	slove();
	return 0;
}
