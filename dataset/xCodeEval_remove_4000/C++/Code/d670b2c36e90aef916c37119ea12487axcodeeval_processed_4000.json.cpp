
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
int id4(ll x) { return int(ceil(log2(x))); }
int id1(ll x) { return int(floor(log2(x))); }
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll id12(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll id9(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return m * n / gcd(m, n); }




namespace mod_op {

	const ll MOD = 998244353;

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

	void id11(int n) {
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
		id11(n);
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

	modll id3(ll n) {
		id0((int)n);
		return ifacts[(int)n];
	}

	vector<vector<modll>> id10;
	vector<vector<modll>> id5;

	void id13(int n) {
		for (int i = (int)id10.size(); i <= n; ++i) {
			id10.push_back(vector<modll>(i + 1));
			id5.push_back(vector<modll>(i + 1, 0));
			Loop(j, i + 1) {
				if (j == 0) id10[i][j] = 0;
				else if (j == 1) id10[i][j] = 1;
				else if (j == i) id10[i][j] = 1;
				else id10[i][j] = id10[i - 1][j - 1] + id10[i - 1][j] * modll(j);
				if (j > 0) id5[i][j] = id5[i][j - 1] + id10[i][j];
			}
		}
	}

	modll id14(ll n, ll r) {
		if (n >= r && r >= 0) {
			id13((int)n);
			return id10[(int)n][(int)r];
		}
		else return 0;
	}

	modll id16(ll n, ll r) {
		if (n >= r && r >= 0) {
			id13((int)n);
			return id5[(int)n][(int)r];
		}
		else return 0;
	}

	vector<vector<modll>> partition_nums;
	vector<vector<modll>> id8;

	void id17(int n) {
		for (int i = (int)partition_nums.size(); i <= n; ++i) {
			partition_nums.push_back(vector<modll>(i + 1));
			id8.push_back(vector<modll>(i + 1, 0));
			Loop(j, i + 1) {
				if (j == 0) partition_nums[i][j] = 0;
				else if (j == 1) partition_nums[i][j] = 1;
				else if (j == i) partition_nums[i][j] = 1;
				else partition_nums[i][j] = partition_nums[i - 1][j - 1] + (i >= j * 2 ? partition_nums[i - j][j] : 0);
				if (j > 0) id8[i][j] = id8[i][j - 1] + partition_nums[i][j];
			}
		}
	}
	modll id7(ll n, ll r) {
		if (n >= r && n >= 0) {
			id17((int)n);
			return partition_nums[(int)n][(int)r];
		}
		else return 0;
	}

	modll id15(ll n, ll r) {
		if (n >= r && r >= 0) {
			id17((int)n);
			return id8[(int)n][(int)r];
		}
		else return 0;
	}

	

	ll disc_log(modll a, modll b) {
		ll ret = -1;
		ll m = id9(MOD);
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





modll grouping(ll n, ll r, bool distinct_n, bool distinct_r, bool id18) {
	int mode = (distinct_n ? 0b100 : 0) + (distinct_r ? 0b010 : 0) + (id18 ? 0b001 : 0);
	if (n < 0 || r < 0) return 0;
	switch (mode) {
	case 0b000:
		return id7(n, r);
	case 0b001:
		return id15(n, r);
	case 0b010:
		return combination(n - 1, r - 1);
	case 0b011:
		return combination(n + r - 1, r - 1);
	case 0b100:
		return id14(n, r);
	case 0b101:
		return id16(n, r);
	case 0b110:
		return id14(n, r) * get_fact(r);
	case 0b111:
		return pow(modll(r), n);
	default:
		return 0;
	}
}







vvmodll id2(vll n, int m) {
	vvmodll c(m + 1, vmodll(m + 1));
	Loop(i, m + 1) {
		Loop(j, m + 1) {
			c[i][j] = combination(i, j);
		}
	}
	vvmodll p(m, vmodll(m + 1));
	p[0][1] = 1;
	Loop1(i, m - 1) {
		p[i][0] -= 1;
		Loop(k, i + 2) {
			p[i][k] += c[i + 1][k];
			Loop(j, i) {
				p[i][k] -= p[j][k] * c[i + 1][j];
			}
		}
		modll inv_i = modll(1) / (i + 1);
		Loop(k, i + 2) {
			p[i][k] *= inv_i;
		}
	}
	vvmodll pow_n(n.size(), vmodll(m + 1, 1));
	Loop(s, n.size()) {
		Loop1(i, m) {
			pow_n[s][i] = pow_n[s][i - 1] * n[s];
		}
	}
	vvmodll q(m, vmodll(m + 1));
	q[0][1] = 1;
	Loop1(i, m - 1) {
		Loop(k, i + 2) {
			Loop(j, i + 1) {
				q[i][k] += q[i - 1][j] * p[j][k];
			}
		}
	}
	vvmodll ret(n.size(), vmodll(m));
	Loop(s, n.size()) {
		Loop(i, m) {
			Loop(k, i + 2) {
				ret[s][i] += pow_n[s][k] * q[i][k];
			}
		}
	}
	return ret;
}

int main() {
	quickio();
	int n; cin >> n;
	vll l(n), r(n);
	Loop(i, n) cin >> l[i] >> r[i];
	vmodll inv_s(n);
	Loop(i, n) inv_s[i] = modll(1) / (r[i] - l[i] + 1);
	set<ll> st;
	Loop(i, n) {
		st.insert(l[i]);
		st.insert(r[i]);
	}
	vector<Pll> u;
	Loopitr(itr, st) {
		if (u.size() == 0) u.push_back({ *itr, *itr });
		else {
			ll buf = u.back().fst + 1;
			if (buf < *itr)	u.push_back({ buf, (*itr) - 1 });
			u.push_back({ *itr, *itr });
		}
	}
	vll v(u.size());
	Loop(i, u.size()) v[i] = u[i].snd - u[i].fst + 1;
	vvmodll prec = id2(v, n + 3);
	vvmodll coeff = prec;
	Loop(i, u.size()) {
		Loop(j, n + 3) {
			if (j == 0) coeff[i][j] = 1;
			else coeff[i][j] = prec[i][j] / prec[i][j - 1];
		}
	}
	vvvmodll dp(n + 1, vvmodll(u.size(), vmodll(n + 2)));
	dp[0][u.size() - 1][0] = 1;
	Loop(i, n) {
		Loop(j, u.size()) {
			Loop(k, u.size()) {
				if (l[i] <= u[k].fst && u[k].snd <= r[i] && j >= k) {
					if (j == k) {
						Loop(x, n + 1) {
							dp[i + 1][k][x + 1] += dp[i][j][x] * coeff[j][x + 1] * inv_s[i];
						}
					}
					else {
						Loop(x, n + 2) {
							dp[i + 1][k][0] += dp[i][j][x] * v[k] * inv_s[i];
						}
					}
				}
			}
		}
	}
	modll ans = 0;
	Loop(j, u.size()) {
		Loop(x, n + 2) {
			ans += dp[n][j][x];
		}
	}
	cout << ans << endl;
	return 0;
}