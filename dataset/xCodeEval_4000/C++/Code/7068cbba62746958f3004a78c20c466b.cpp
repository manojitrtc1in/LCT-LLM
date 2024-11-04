#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;
#define Loop(i, n) for(int i = 0; i < int(n); i++)
#define Loopll(i, n) for(ll i = 0; i < ll(n); i++)
#define Loop1(i, n) for(int i = 1; i <= int(n); i++)
#define Loopll1(i, n) for(ll i = 1; i <= ll(n); i++)
#define Loopr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = int(n); i >= 1; i--)
#define Looprll1(i, n) for(ll i = ll(n); i >= 1; i--)
#define Foreach(buf, container) for(const auto &buf : container)
#define Foreachr(buf, container)  for(const auto &buf : reversed(container))
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
#define INF INFINITY
bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { return int(ceil(log2(x))); }
int floorlog2(ll x) { return int(floor(log2(x))); }
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m * m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
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

	void make_facts(int n) {
		if (facts.empty()) facts.push_back(modll(1));
		for (int i = (int)facts.size(); i <= n; ++i) facts.push_back(modll(facts.back() * (ll)i));
		return;
	}

	vector<modll> ifacts;
	vector<modll> invs;

	void make_invs(int n) {
		if (invs.empty()) {
			invs.push_back(modll(0));
			invs.push_back(modll(1));
		}
		for (int i = (int)invs.size(); i <= n; ++i) {
			

			invs.push_back(invs[(int)MOD % i] * ((int)MOD - (int)MOD / i));
		}
		return;
	}

	void make_ifacts(int n) {
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

	vector<vector<modll>> Stirling_nums2;
	vector<vector<modll>> Stirling_nums2_sum;

	void make_Stirling_nums2(int n) {
		for (int i = (int)Stirling_nums2.size(); i <= n; ++i) {
			Stirling_nums2.push_back(vector<modll>(i + 1));
			Stirling_nums2_sum.push_back(vector<modll>(i + 1, 0));
			Loop(j, i + 1) {
				if (j == 0) Stirling_nums2[i][j] = 0;
				else if (j == 1) Stirling_nums2[i][j] = 1;
				else if (j == i) Stirling_nums2[i][j] = 1;
				else Stirling_nums2[i][j] = Stirling_nums2[i - 1][j - 1] + Stirling_nums2[i - 1][j] * modll(j);
				if (j > 0) Stirling_nums2_sum[i][j] = Stirling_nums2_sum[i][j - 1] + Stirling_nums2[i][j];
			}
		}
	}

	modll get_Stirling_num2(ll n, ll r) {
		if (n >= r && r >= 0) {
			make_Stirling_nums2((int)n);
			return Stirling_nums2[(int)n][(int)r];
		}
		else return 0;
	}

	modll get_Stirling_num2_sum(ll n, ll r) {
		if (n >= r && r >= 0) {
			make_Stirling_nums2((int)n);
			return Stirling_nums2_sum[(int)n][(int)r];
		}
		else return 0;
	}

	vector<vector<modll>> partition_nums;
	vector<vector<modll>> partition_nums_sum;

	void make_partition_nums(int n) {
		for (int i = (int)partition_nums.size(); i <= n; ++i) {
			partition_nums.push_back(vector<modll>(i + 1));
			partition_nums_sum.push_back(vector<modll>(i + 1, 0));
			Loop(j, i + 1) {
				if (j == 0) partition_nums[i][j] = 0;
				else if (j == 1) partition_nums[i][j] = 1;
				else if (j == i) partition_nums[i][j] = 1;
				else partition_nums[i][j] = partition_nums[i - 1][j - 1] + (i >= j * 2 ? partition_nums[i - j][j] : 0);
				if (j > 0) partition_nums_sum[i][j] = partition_nums_sum[i][j - 1] + partition_nums[i][j];
			}
		}
	}
	modll get_partition_num(ll n, ll r) {
		if (n >= r && n >= 0) {
			make_partition_nums((int)n);
			return partition_nums[(int)n][(int)r];
		}
		else return 0;
	}

	modll get_partition_num_sum(ll n, ll r) {
		if (n >= r && r >= 0) {
			make_partition_nums((int)n);
			return partition_nums_sum[(int)n][(int)r];
		}
		else return 0;
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




class Prefix_Sums {
private:
	int m = 0;
	vvmodll c;
	vvmodll p;
	vvmodll q;
public:
	Prefix_Sums() {
		c.push_back(vmodll(1));
	}
	

	

	

	

	vmodll get_prefix_sums(ll n, int m) {
		for (int i = this->m; i < m; ++i, ++this->m) {
			c.push_back(vmodll(i + 2));
			p.push_back(vmodll(i + 2));
			q.push_back(vmodll(i + 2));
			Loop(j, i + 2) {
				c[i + 1][j] = combination(i + 1, j);
			}
			if (i == 0) {
				p[0][1] = 1;
				q[0][1] = 1;
			}
			else {
				p[i][0] -= 1;
				Loop(k, i + 2) {
					p[i][k] += c[i + 1][k];
					Loop(j, i) {
						if (j + 2 <= k) continue;
						p[i][k] -= p[j][k] * c[i + 1][j];
					}
				}
				modll inv_i = modll(1) / (i + 1);
				Loop(k, i + 2) {
					p[i][k] *= inv_i;
				}
				Loop(k, i + 2) {
					Loop(j, i + 1) {
						if (j + 2 <= k) continue;
						q[i][k] += p[j][k] * q[i - 1][j];
					}
				}
			}
		}
		vmodll pow_n(m + 1, 1);
		Loop1(i, m) {
			pow_n[i] = pow_n[i - 1] * n;
		}
		vmodll ret(m);
		Loop(i, m) {
			Loop(k, i + 2) {
				ret[i] += pow_n[k] * q[i][k];
			}
		}
		return ret;
	}
};

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
	vvmodll prec(u.size());
	Prefix_Sums *ps = new Prefix_Sums;
	Loop(i, u.size()) {
		v[i] = u[i].snd - u[i].fst + 1;
		prec[i] = ps->get_prefix_sums(v[i], n + 3);
	}
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