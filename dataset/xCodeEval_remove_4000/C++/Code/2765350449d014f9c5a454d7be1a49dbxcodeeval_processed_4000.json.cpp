
using namespace std;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;






















bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int id5(ll x) { return int(ceil(log2(x))); }
int id2(ll x) { return int(floor(log2(x))); }
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id3(ll x) { ll m = (ll)sqrt((double)x); return m + (m*  m <= x ? 0 : -1); }
ll id8(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }




namespace mod_op {

	const ll MOD = (ll)1e9 + 7;

		class modll {
		private:
			ll val;
			ll modify(ll x) const { ll ret = x % MOD; if (ret < 0) ret += MOD; return ret; }
			ll inv(ll x) const {
				if (x == 0) return 1 / x;
				else if (x == 1) return 1;
				else return modify(inv(MOD % x) * modify(-MOD / x));
			}
		public:
			modll(ll init = 0) { val = modify(init); return; }
			modll(const modll& another) { val = another.val; return; }
			modll& operator=(const modll &another) { val = another.val; return *this; }
			modll operator+(const modll &x) const { return modify(val + x.val); }
			modll operator-(const modll &x) const { return modify(val - x.val); }
			modll operator*(const modll &x) const { return modify(val * x.val); }
			modll operator/(const modll &x) const { return modify(val * inv(x.val)); }
			modll& operator+=(const modll &x) { val = modify(val + x.val); return *this; }
			modll& operator-=(const modll &x) { val = modify(val - x.val); return *this; }
			modll& operator*=(const modll &x) { val = modify(val * x.val); return *this; }
			modll& operator/=(const modll &x) { val = modify(val * inv(x.val)); return *this; }
			bool operator==(const modll &x) { return val == x.val; }
			bool operator!=(const modll &x) { return val != x.val; }
			friend istream& operator >> (istream &is, modll& x) { is >> x.val; return is; }
			friend ostream& operator << (ostream &os, const modll& x) { os << x.val; return os; }
			ll get_val() { return val; }
	};

	modll pow(modll n, ll p) {
		modll ret;
		if (p == 0) ret = 1;
		else if (p == 1) ret = n;
		else {
			ret = pow(n, p >> 1);
			ret *= ret;
			if ((p & 1) == 1) ret *= n;
		}
		return ret;
	}

	vector<modll> facts;

	void id6(int n) {
		if (facts.empty()) facts.push_back(modll(1));
		for (int i = (int)facts.size(); i <= n; ++i) facts.push_back(modll(facts.back() * (ll)i));
		return;
	}

	vector<modll> ifacts;
	vector<modll> invs;

	void id1(int n) {
		if (invs.empty()) {
			invs.push_back(modll(0));
			invs.push_back(modll(1));
		}
		for (int i = (int)invs.size(); i <= n; ++i) {
			

			invs.push_back(invs[(int)MOD % i] * ((int)MOD - (int)MOD / i));
		}
		return;
	}

	void id0(int n) {
		id1(n);
		if (ifacts.empty()) ifacts.push_back(modll(1));
		for (int i = (int)ifacts.size(); i <= n; ++i) ifacts.push_back(modll(ifacts.back() * invs[i]));
		return;
	}

	

	modll combination(ll n, ll r) {
		if (n >= r && r >= 0) {
			modll ret;
			id6((int)n);
			id0((int)n);
			ret = facts[(unsigned)n] * ifacts[(unsigned)r] * ifacts[(unsigned)(n - r)];
			return ret;
		}
		else return 0;
	}

	modll get_fact(ll n) {
		id6((int)n);
		return facts[(int)n];
	}

	modll id4(ll n) {
		id0((int)n);
		return ifacts[(int)n];
	}

	

	ll disc_log(modll a, modll b) {
		ll ret = -1;
		ll m = id8(MOD);
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

class id7 {
private:
	int n;
	string s;
	

	

	

	

	struct node_t {
		int l; int r; array<node_t*, 2> childs; int dep; node_t* parent; int cnt; node_t* suf; int v = INT_MAX;
	};
	const char base = '0';
	node_t* root;
	

	vector<node_t*> sufnodes;
	inline node_t* proceed(node_t* cur, int &k, int &i) {
		if (i == n) return cur;
		if (k == cur->r - cur->l) {
			if (cur->childs[s[i] - base] == nullptr) return cur;
			else {
				cur = cur->childs[s[i] - base];
				k = 1;
				i++;
				return proceed(cur, k, i);
			}
		}
		else {
			if (s[cur->l + k] != s[i]) return cur;
			else {
				k++;
				i++;
				return proceed(cur, k, i);
			}
		}
	}
	inline node_t* insert(node_t* cur, const int k, const int i) {
		if (k < cur->r - cur->l) {
			node_t* branch = new node_t{ cur->l, cur->l + k, {}, cur->parent->dep + k, cur->parent, 0, nullptr };
			branch->childs[s[cur->l + k] - base] = cur;
			branch->parent->childs[s[cur->l] - base] = branch;
			cur->l = cur->l + k;
			cur->parent = branch;
			cur = branch;
		}
		if (i < n) {
			node_t* leaf = new node_t{ i, n, {}, cur->dep + n - i, cur, 1, nullptr };
			cur->childs[s[i] - base] = leaf;
			sufnodes[n - leaf->dep] = leaf;
		}
		else {
			cur->cnt++;
			sufnodes[n - cur->dep] = cur;
		}
		return cur;
	}
	inline node_t* proceed_suf(node_t* pre, int &k) {
		if (pre == root) return root;
		node_t* cur;
		int j;
		if (pre->parent == root) {
			cur = root;
			j = 1;
		}
		else {
			cur = pre->parent->suf;
			j = 0;
		}
		k = cur->r - cur->l;
		while (j < pre->r - pre->l) {
			cur = cur->childs[s[pre->l + j] - base];
			k = pre->r - pre->l - j;
			if (k > cur->r - cur->l) {
				j += cur->r - cur->l;
			}
			else {
				break;
			}
		}
		return cur;
	}
	void construct() {
		node_t* cur = root;
		node_t* pre = nullptr;
		int k = 0;
		int i = 0;
		root->suf = root;
		while (i != n || cur != root) {
			cur = proceed(cur, k, i);
			cur = insert(cur, k, i);
			if (pre != nullptr) {
				pre->suf = cur;
			}
			pre = cur;
			if (pre == root) i++;
			cur = proceed_suf(pre, k);
			if (k == cur->r - cur->l) {
				pre->suf = cur;
				pre = nullptr;
			}
		}
		sufnodes.push_back(root);
		Loop(i, n) {
			sufnodes[i]->suf = sufnodes[i + 1];
		}
		sufnodes.pop_back();
	}
	

	

	bool get_pos(node_t* &a, int &k, const string &t) {
		Loop(i, t.length()) {
			if (k == a->r - a->l) {
				if (a->childs[t[i] - base] == nullptr) return false;
				a = a->childs[t[i] - base];
				k = 1;
			}
			else if (t[i] == s[a->l + k]) {
				k++;
			}
			else {
				return false;
			}
		}
		return true;
	}
	void get_suffix_array_rec(const node_t* const a, vi &ary, int &k) {
		if (a->cnt) ary[k++] = n - a->dep;
		Loop(i, 2) {
			if (a->childs[i] != nullptr) {
				get_suffix_array_rec(a->childs[i], ary, k);
			}
		}
	}
public:
	id7(const string &s) {
		this->root = new node_t{ 0, 0, {}, 0, nullptr, 0, nullptr };
		this->n = s.length();
		this->s = s;
		this->sufnodes = vector<node_t*>(n, nullptr);
		this->construct();
		return;
	}
	

	bool is_suffix(const string &t) {
		node_t* a = root;
		int k = 0;
		bool judge = get_pos(a, k, t);
		if (judge && k == a->r - a->l) {
			return a->cnt;
		}
		else {
			return false;
		}
	}
	

	bool is_substring(const string &t) {
		node_t* a = root;
		int k = 0;
		return get_pos(a, k, t);
	}
	

	vi get_suffix_array() {
		vi ret(n, -1);
		int k = 0;
		get_suffix_array_rec(root, ret, k);
		return ret;
	}
	void acc_rec(node_t *a) {
		Loop(i, 2) {
			if (a->childs[i] != nullptr) {
				acc_rec(a->childs[i]);
				a->v = min(a->v, a->childs[i]->v);
			}
		}
	}
	void acc() {
		Loop(i, n) {
			sufnodes[i]->v = i;
		}
		acc_rec(root);
	}
	vi solve(int i) {
		vi ret(n + 1, -1);
		node_t * a = root;
		int k = 0;
		for (int j = i; j < n; ++j) {
			get_pos(a, k, string(1, s[j]));
			ret[j + 1] = a->v;
		}
		return ret;
	}
};

int main() {
	quickio();
	int n; cin >> n;
	string s(n, '0');
	Loop(i, n) cin >> s[i];
	vvmodll f(n, vmodll(n + 1, 0));
	Loop(i, n) {
		f[i][i] = 1;
		for (int j = i + 1; j <= n; ++j) {
			Loop1(k, 4) {
				if (j - k >= 0) {
					if (k <= 3) f[i][j] += f[i][j - k];
					else {
						string t = s.substr(j - k, 4);
						if (t != "0011" && t != "0101" && t != "1110" && t != "1111") {
							f[i][j] += f[i][j - k];
						}
					}
				}
			}
		}
	}
	id7 *sft = new id7(s);
	sft->acc();
	vvi pre(n);
	Loop(i, n) {
		pre[i] = sft->solve(i);
	}
	vmodll ans(n);
	Loop1(j, n) {
		for (int i = 0; i < j; ++i) {
			ans[j - 1] += (pre[i][j] == i ? f[i][j] : 0);
		}
	}
	Loop(i, n - 1) {
		ans[i + 1] += ans[i];
	}
	Loop(i, n) {
		cout << ans[i] << endl;
	}
}