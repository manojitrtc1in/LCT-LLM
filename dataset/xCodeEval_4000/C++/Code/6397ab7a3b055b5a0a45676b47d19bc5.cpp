#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-9;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loopll(i, n) for(ll i = 0; i < (ll)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopll1(i, n) for(ll i = 1; i <= (ll)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = (ll)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define Looprll1(i, n) for(ll i = (ll)n; i >= 1; i--)
#define Foreach(buf, container) for(auto buf : container)
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= (h) ? (h) - 1 : (sum)), j = (sum) - i; i >= 0 && j < (w); i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= (w) ? (w) - 1 : (sum)), i = (sum) - j; j >= 0 && i < (h); j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define printv(vector) Loop(ex_i, vector.size()) { cout << vector[ex_i] << " "; } cout << endl;
#define printmx(matrix) Loop(ex_i, matrix.size()) { Loop(ex_j, matrix[ex_i].size()) { cout << matrix[ex_i][ex_j] << " "; } cout << endl; }
#define quickio() ios::sync_with_stdio(false); cin.tie(0);
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
#define Comp(type_t) bool operator<(const type_t &another) const
#define fst first
#define snd second
bool nearlyeq(double x, double y) { return abs(x - y) < eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { int ret = 0;	x--; while (x > 0) { ret++; x >>= 1; } return ret; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }



template<class T>
class SegTree {
protected:
	int n, N; 

	int base;
	vector<T> nodes;
	int left_of(int index) {
		if (index >= base) return -1;
		else return index * 2 + 1;
	}
	int right_of(int index) {
		if (index >= base) return -1;
		else return index * 2 + 2;
	}
	int parent_of(int index) {
		if (index == 0) return -1;
		else return (index - 1) >> 1;
	}
	

	void update_rec(int s, int t, int l, int r, int index, T v) {
		if (s == l && t == r) {
			nodes[index] = v;
		}
		else {
			int mid = (l + r) / 2;
			int index_l = left_of(index);
			int index_r = right_of(index);
			if (s < mid && mid < t) {
				update_rec(s, mid, l, mid, index_l, v);
				update_rec(mid, t, mid, r, index_r, v);
			}
			else if (s < mid) {
				update_rec(s, t, l, mid, index_l, v);
			}
			else if (mid < t) {
				update_rec(s, t, mid, r, index_r, v);
			}
			nodes[index] = nodes[index_l] + nodes[index_r];
		}
	}
	

	T add_rec(int s, int t, int l, int r, int index) {
		if (s == l && t == r) {
			return nodes[index];
		}
		else {
			int mid = (l + r) / 2;
			int index_l = left_of(index);
			int index_r = right_of(index);
			T v0 = 0, v1 = 0;
			if (s < mid && mid < t) {
				v0 = add_rec(s, mid, l, mid, index_l);
				v1 = add_rec(mid, t, mid, r, index_r);
			}
			else if (s < mid) {
				v0 = add_rec(s, t, l, mid, index_l);
			}
			else if (mid < t) {
				v1 = add_rec(s, t, mid, r, index_r);
			}
			return v0 + v1;
		}
	}
public:
	SegTree(int n, T init) {
		SegTree::n = n;
		N = (int)pow(2, ceil(log2(n)));
		base = N - 1;
		nodes = vector<T>(base + N, init);
	}
	

	vi get_index_above(int index, bool from_base = false) {
		if (from_base) index += base;
		vi ret;
		while (index >= 0) {
			ret.push_back(index);
			index = parent_of(index);
		}
		return ret;
	}
	int cover_size(int index) {
		int cnt = 1;
		while (left_of(index) != -1) {
			index = left_of(index);
			cnt *= 2;
		}
		int l = index - base;
		int r = min(l + cnt, n);
		return max(0, r - l);
	}
	void update(int k, T v) {
		update_rec(k, k + 1, 0, N, 0, v);
	}
	T sum(int s, int t) {
		return add_rec(s, t, 0, N, 0);
	}
};





template<typename val_t, typename bsargv_t>
val_t lower_binary_search(val_t l, val_t r, const bsargv_t &v, bool(*evalfunc)(val_t, const bsargv_t&)) {
	if (r - l == 1) {
		if (evalfunc(l, v)) return l;
		else return l - 1;
	}
	val_t m = (l + r) / 2;
	if (evalfunc(m, v)) return lower_binary_search<val_t, bsargv_t>(m, r, v, evalfunc);
	else return lower_binary_search<val_t, bsargv_t>(l, m, v, evalfunc);
}


struct bsargv_t {
	SegTree<ll> *st;
	int s;
	ll sum;
};

bool evalfunc(int val, const bsargv_t &v) {
	ll buf = v.st->sum(v.s, val + 1);
	if (buf <= v.sum / 2) return true;
	else return false;
}

namespace mod_op {

	const ll MOD = (ll)1e9 + 7;

	class modll {
	private:
		ll val;
		inline ll modify(ll x) { ll ret = x % MOD; if (ret < 0) ret += MOD; return ret; }
		inline ll inv(ll x) {
			if (x == 0) return 1 / x;
			else if (x == 1) return 1;
			else return modify(inv(MOD % x) * modify(-MOD / x));
		}
	public:
		modll(ll init = 0) { val = modify(init); return; }
		modll(const modll& another) { val = another.val; return; }
		inline modll& operator=(const modll &another) { val = another.val; return *this; }
		inline modll operator+(const modll &x) { return modify(val + x.val); }
		inline modll operator-(const modll &x) { return modify(val - x.val); }
		inline modll operator*(const modll &x) { return modify(val * x.val); }
		inline modll operator/(const modll &x) { return modify(val * inv(x.val)); }
		inline modll& operator+=(const modll &x) { val = modify(val + x.val); return *this; }
		inline modll& operator-=(const modll &x) { val = modify(val - x.val); return *this; }
		inline modll& operator*=(const modll &x) { val = modify(val * x.val); return *this; }
		inline modll& operator/=(const modll &x) { val = modify(val * inv(x.val)); return *this; }
		inline bool operator==(const modll &x) { return val == x.val; }
		inline bool operator!=(const modll &x) { return val != x.val; }
		friend inline istream& operator >> (istream &is, modll& x) { is >> x.val; return is; }
		friend inline ostream& operator << (ostream &os, const modll& x) { os << x.val; return os; }
		ll get_val() { return val; }
	};

	modll pow(modll n, ll p) {
		modll ret;
		if (p == 0) ret = 1;
		else if (p == 1) ret = n;
		else {
			ret = pow(n, p / 2);
			ret *= ret;
			if (p % 2 == 1) ret *= n;
		}
		return ret;
	}

	vector<modll> facts;

	inline void make_facts(int n) {
		if (facts.empty()) facts.push_back(modll(1));
		for (int i = (int)facts.size(); i <= n; ++i) facts.push_back(modll(facts.back() * (ll)i));
		return;
	}

	vector<modll> ifacts;
	vector<modll> invs;

	inline void make_invs(int n) {
		if (invs.empty()) {
			invs.push_back(modll(0));
			invs.push_back(modll(1));
		}
		for (int i = (int)invs.size(); i <= n; ++i) {
			

			invs.push_back(invs[(int)MOD % i] * ((int)MOD - (int)MOD / i));
		}
		return;
	}

	inline void make_ifacts(int n) {
		make_invs(n);
		if (ifacts.empty()) ifacts.push_back(modll(1));
		for (int i = (int)ifacts.size(); i <= n; ++i) ifacts.push_back(modll(ifacts.back() * invs[i]));
		return;
	}

	

	modll combination(ll n, ll r) {
		if (n >= r && r >= 0) {
			modll ret;
			make_facts((int)n);
			make_ifacts((int)n);
			ret = facts[(unsigned)n] * ifacts[(unsigned)r] * ifacts[(unsigned)(n - r)];
			return ret;
		}
		else return 0;
	}

	modll get_fact(ll n) {
		make_facts((int)n);
		return facts[(int)n];
	}

	modll get_ifact(ll n) {
		make_ifacts((int)n);
		return ifacts[(int)n];
	}

	

	ll disc_log(modll a, modll b) {
		ll ret = -1;
		ll m = ceilsqrt(MOD);
		unordered_map<ll, ll> mp;
		modll x = 1;
		Loop(i, m) {
			mp[x.get_val()] = i;
			x *= a;
		}
		x = modll(1) / pow(a, m);
		modll k = b;
		Loop(i, m) {
			if (mp.find(k.get_val()) == mp.end()) k *= x;
			else {
				ret = i * m + mp[k.get_val()];
				break;
			}
		}
		return ret;
	}
}

using namespace mod_op;
using vmodll = vector<modll>;
using vvmodll = vector<vmodll>;
using vvvmodll = vector<vvmodll>;

int main() {
	quickio();
	int n, q; cin >> n >> q;
	vll a(n); Loop(i, n) cin >> a[i];
	SegTree<ll> *st = new SegTree<ll>(n, 0);
	SegTree<modll> *ast = new SegTree<modll>(n, 0);
	SegTree<modll> *lst = new SegTree<modll>(n, 0);
	SegTree<modll> *rst = new SegTree<modll>(n, 0);
	Loop(i, n) {
		ll w; cin >> w;
		st->update(i, w);
		ast->update(i, modll(w) * a[i]);
		lst->update(i, modll(w) * (n - 1 - i));
		rst->update(i, modll(w) * i);
	}
	vmodll ans;
	Loop(unused, q) {
		int x; cin >> x;
		if (x < 0) {
			x++;
			ll y; cin >> y;
			st->update(-x, y);
			ast->update(-x, modll(y) * a[-x]);
			lst->update(-x, modll(y) * (n - 1 - (-x)));
			rst->update(-x, modll(y) * (-x));
		}
		else {
			int y; cin >> y;
			x--; y--;
			if (x == y) {
				ans.push_back(0);
			}
			else {
				int halfid;
				if (y - x == 1) {
					halfid = x;
				}
				else {
					bsargv_t v = { st, x, st->sum(x, y + 1) };
					halfid = lower_binary_search(x + 1, y, v, evalfunc);
				}
				ll cand0 = st->sum(x, halfid + 1);
				ll cand1 = st->sum(halfid + 1, y + 1);
				ll dst;
				int dstid;
				if (cand0 <= cand1) {
					dst = a[halfid + 1];
					dstid = halfid + 1;
				}
				else {
					dst = a[halfid];
					dstid = halfid;
				}
				modll buf = 0;
				buf += modll(dst) * st->sum(x, dstid) - ast->sum(x, dstid) - (lst->sum(x, dstid) - modll(st->sum(x, dstid)) * (n - 1 - dstid));
				buf += modll(ast->sum(dstid, y + 1)) - modll(dst) * st->sum(dstid, y + 1) - (rst->sum(dstid, y + 1) - modll(st->sum(dstid, y + 1)) * dstid);
				ans.push_back(buf);
			}
		}
	}
	Loop(i, ans.size()) {
		cout << ans[i] << endl;
	}
}