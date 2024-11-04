#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> piii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> plll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<pll> vll;
typedef vector<piii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vl> vvl;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef int (*itoi) (int);
typedef int (*iitoi) (int, int);
typedef int (*iiitoi) (int, int, int);
typedef ll (*ltol) (ll);
typedef ll (*lltol) (ll, ll);
typedef ll (*llltol) (ll, ll, ll);

const ld PI = acos(0)*2;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll*INF*INF;
int X4[] = {-1, 0, 1, 0}, Y4[] = {0, -1, 0, 1};
int X8[] = {-1, -1, -1, 0, 1, 1, 1, 0}, Y8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int) (x).size())
#define NTH(v, x) ((int) (lower_bound(ALL(v), (x)) - (v).begin()))
#define SAME(v, x) ((int) (upper_bound(ALL(v), (x)) - lower_bound(ALL(v), (x))))
#define UNIQUE(v) v.erase(unique(ALL(v)), (v).end())
#define WER << ' ' <<

#define pb push_back
#define eb emplace_back
#define INP(t, x) t x; cin >> x

#define CPPIO ios::sync_with_stdio(0); cin.tie(0); cout << std::setprecision(10); cout << fixed

#define forn(x, n) for (int x=0; x<(n); x++)
#define for1(x, n) for (int x=1; x<=(n); x++)
#define ford(x, n) for (int x=(n)-1; x>=0; x--)
#define ford1(x, n) for (int x=(n); x>=1; x--)
#define forr(x, n, m) for (int x=(n); x<=(m); x++)
#define forrd(x, n, m) for (int x=(m); x>=(n); x--)

template<typename T> inline bool uax(T &a, T b) { return a<b? (a=b, 1) : 0; }
template<typename T> inline bool uin(T &a, T b) { return a>b? (a=b, 1) : 0; }
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	return is >> p.first >> p.second;
}
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
	return os << '(' << p.first << ", " << p.second << ")";
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i=0; i<(int)v.size(); i++) { os << v[i]; if (i+1<(int)v.size()) os << ' '; } return os;
}













#ifndef FENWICK_TREE_DEFINED
template <class sum_type>
class fenwick_tree {
	public:
		vector<sum_type> v;
		int max_index, min_index;
		int size;
	
		fenwick_tree<sum_type>(int min_index, int max_index) {
			this->max_index = max_index;
			this->min_index = min_index;
			size = max_index - min_index + 3;
			v.assign(size, 0); 

		}

		void init() {
			fill(v.begin(), v.end(), 0); 

		}

		void add(int p, sum_type x) {
			

			assert(p >= min_index-1  && p <= max_index);
			for (p=p-min_index+2; p<size; p+=p&-p) {
				v[p] += x;
				

			}
		}

		sum_type sum(int p) {
			

			assert(p >= min_index-1  && p <= max_index);
			sum_type s = 0;
			for (p=p-min_index+2; p; p&=p-1) {
				s += v[p];
				

			}
			return s;
		}

		sum_type sum(int a, int b) {
			sum_type s = sum(b) - sum(a-1);
			

			return s;
		}
};
#endif

#define FENWICK_TREE_DEFINED











#ifndef NUMBER_THEORY_DEFINED
namespace number_theory {
	typedef long long ll;
	typedef vector<pair<ll,int> > factor;

	ll MOD = 998244353;

	ll __gcd_two(ll a, ll b) {
		return a<0ll? __gcd_two(-a, b) :
			   b<0ll? __gcd_two(a, -b) :
			   a<b? __gcd_two(b, a) : b? __gcd_two(b, a%b) : a;
	}
	
	ll gcd(ll a) { return a<0ll? -a : a; }
	template<typename ... rests> ll gcd(ll a, const rests&... rest) {
		ll b = gcd(rest...);
		return __gcd_two(a, b);
	}

	void extended_euclid(ll a, ll b, ll &x, ll &y) {
		if (a<0) { extended_euclid(-a, b, x, y); x = -x; }
		else if (b<0) { extended_euclid(a, -b, x, y); y = -y; }
		else if (a<b) { extended_euclid(b, a, y, x); }
		else if (b>0) {
			extended_euclid(b, a%b, y, x);
			y -= a/b*x;
		} else { x = 1, y = 0; }
	}

	ll mod_clip(ll a, ll m) { return (a % m + m) % m; }
	ll mod_clip(ll a) { return mod_clip(a, MOD); }

	ll mod_inverse(ll a, ll m) {
		

		assert(gcd(a, m) == 1);
		ll x, y;
		extended_euclid(a, m, x, y);
		return mod_clip(x, m);
	}
	ll mod_inverse(ll a) { return mod_inverse(a, MOD); }

	ll mod_mult(ll a, ll b, ll m) {
		if (b<0) return mod_clip(-mod_mult(a, -b, m), m);
		ll r = 0, x = a;
		while (b) {
			if (b & 1) r = (r + x) % m;
			x = (x + x) % m; b >>= 1;
		}
		return mod_clip(r, m);
	}
	ll mod_mult(ll a, ll b) { return mod_mult(a, b, MOD); }

	ll mod_mults(ll a) { return mod_clip(a); }
	template<typename ... rests> ll mod_mults(ll a, const rests&... rest) {
		ll b = mod_mults(rest...);
		return mod_mult(a, b);
	}

	ll mod_div(ll a, ll b, ll m) {
		assert(b != 0);
		return mod_mult(a, mod_inverse(b, m), m);
	}
	ll mod_div(ll a, ll b) { return mod_div(a, b, MOD); }

	ll mod_pow(ll a, ll p, ll m) {
		if (p<0) return mod_inverse(mod_pow(a, -p, m), m);
		ll r = 1, x = a;
		while (p) {
			if (p & 1) r = mod_clip(mod_mult(r, x, m), m);
			x = mod_mult(x, x, m); p >>= 1;
		}
		return r;
	}
	ll mod_pow(ll a, ll p) { return mod_pow(a, p, MOD); }


	vector<ll> primes, phi, mob;
	vector<bool> sieve;

	void make_sieve(int n) {
		sieve.assign(n+1, 1);
		sieve[0] = sieve[1] = 0;
		for (int i=2; i<=n; i++) {
			if (!sieve[i]) continue;
			for (int j=i+i; j<=n; j+=i) {
				sieve[j] = 0;
			}
		}
	}

	void make_primes(int n, bool naive_way=0) {
		primes.resize(0);
		if (naive_way) {
			if (n >= 2) primes.push_back(2);
			for (int i=3; i<=n; i+=2) {
				int flag = 0;
				for (auto &p : primes) {
					if (i%p == 0) { flag = 1; break; }
				}
				if (!flag) primes.push_back(i);
			}
		} else {
			if (((int) sieve.size()) <= n) make_sieve(n);
			for (int i=2; i<=n; i++)
				if (sieve[i]) primes.push_back(i);
		}
	}

	void make_primes_added(int n) {
		if (((int) primes.size()) > 0 && primes.back() >= n) return;
		int start = ((int) primes.size()) == 0? 2 : primes.back()+1;
		for (int i=start; i<=n; i++) {
			int flag = 0;
			for (auto &p : primes) {
				if (i%p == 0) { flag = 1; break; }
			}
			if (!flag) primes.push_back(i);
		}
	}

	void make_phi(int n) {
		phi.assign(n+1, 0);
		for (int i=0; i<=n; i++) phi[i] = i;
		for (int i=1; i<=n; i++) {
			for (int j=i+i; j<=n; j+=i)
				phi[j] -= phi[i];
		}
	}

	void make_mob(int n) {
		mob.assign(n+1, 0);
		mob[1] = 1;
		for (int i=1; i<=n; i++) {
			for (int j=i+i; j<=n; j+=i)
				mob[j] -= mob[i];
		}
	}


	long long __AUTO_POLLARD_RHO_BOUND = 1e14;
	long long __POLLARD_RHO_NAIVE_BOUND = 5e4;
	int __MAX_POLLARD_RHO_ITERATION = 1e5;

	int __MAX_MILLER_RABIN_TEST = 37;
	bool __MILLER_RABIN_BEFORE_POLLARD_RHO = 1;

	bool miller_rabin(ll n) {
		

		if (n <= 1) return 0;
		if (((int) primes.size()) == 0 || primes.back() < __MAX_MILLER_RABIN_TEST)
			make_primes_added(__MAX_MILLER_RABIN_TEST);
		for (int i=0; i<((int) primes.size()) && primes[i]<=__MAX_MILLER_RABIN_TEST; i++) {
			if (n == primes[i]) return 1;
			if (n % primes[i] == 0) return 0;
		}

		int s = 0;
		ll m = n-1;
		while ((m&1) == 0) m >>= 1, s++;

		for (int i=0; i<((int) primes.size()) && primes[i] <= __MAX_MILLER_RABIN_TEST; i++) {
			ll p = primes[i];
			ll q = mod_pow(p, m, n);
			if (q == 1) continue;
			bool flag = 1;
			for (int j=0; j<s; j++) {
				if (q == n-1) { flag = 0; break; }
				q = mod_mult(q, q, n);
			}
			if (flag) return 0;
		}
		return 1;
	}

	ll pollard_rho(ll n) {
		

		if (__MILLER_RABIN_BEFORE_POLLARD_RHO)
			if (miller_rabin(n)) return n;
		for (ll p=2; p<__POLLARD_RHO_NAIVE_BOUND; p++)
			if (n % p == 0) return p;
		int it = 0;
		ll d = 1;
		while (it < __MAX_POLLARD_RHO_ITERATION) {
			srand(time(0));
			if (n == 1) return n;
			if (n%2 == 0) return 2;
			ll x = (rand() % (n-2)) + 2, y = x;
			ll c = (rand() % (n-1)) + 1;

			while (it < __MAX_POLLARD_RHO_ITERATION && d == 1) {
				++it;
				x = (mod_mult(x, x, n) + c + n) % n;
				y = (mod_mult(y, y, n) + c + n) % n;
				y = (mod_mult(y, y, n) + c + n) % n;
				d = gcd(x-y, n);
				if (d == n) { d = 1; break; }
				else if (d > 1) return d;
			}
		}
		return n;
	}

	factor __merge_factors(factor a, factor b) {
		map<ll,int> m;
		for (auto &p : a) m[p.first] += p.second;
		for (auto &p : b) m[p.first] += p.second;
		factor v;
		for (auto &p : m) v.push_back(p);
		return v;
	}

	factor factorization(ll n, int calc_mode=0) {
		

		int orig_calc_mode = calc_mode;
		if (calc_mode == 0) calc_mode = (n > __AUTO_POLLARD_RHO_BOUND)? 2 : 1;
		if (calc_mode == 1) {
			if (((int) primes.size()) > 0 && primes.back() > n / primes.back()) {
				factor v;
				for (auto &p : primes) {
					if (p * p > n) break;
					if (n % p == 0) {
						v.emplace_back(p, 0);
						while (n % p == 0) { v.back().second++; n /= p; }
					}
				}
				if (n > 1) v.emplace_back(n, 1);
				return v;
			} else {
				factor v;
				for (ll p=2; p*p<=n; p++) {
					if (n % p == 0) {
						v.emplace_back(p, 0);
						while (n % p == 0) { v.back().second++; n /= p; }
					}
				}
				if (n > 1) v.emplace_back(n, 1);
				return v;
			}
		} else {
			ll d = pollard_rho(n);
			if (d == n || d == 1) {
				factor v;
				v.emplace_back(n, 1);
				return v;
			} else {
				return __merge_factors(factorization(d, orig_calc_mode), factorization(n/d, orig_calc_mode));
			}
		}
	}


	bool is_prime(ll n, int calc_mode=0) {
		

		if (n <= 1) return 0;
		if (((int) sieve.size()) > n) return sieve[n];
		if (calc_mode == 0) calc_mode = (n > __AUTO_POLLARD_RHO_BOUND)? 2 : 1;
		if (calc_mode == 1) {
			if (((int) primes.size()) > 0 && primes.back() >= n) {
				auto p = lower_bound(primes.begin(), primes.end(), n);
				return (*p == n);
			} else if (((int) primes.size()) > 0 && primes.back() * primes.back() >= n) {
				for (auto &p : primes) {
					if (n % p == 0) return 0;
					if (p * p >= n) return 1;
				}
				return 1;
			} else {
				for (ll p=2; p*p<=n; p++) {
					if (n % p == 0) return 0;
				}
				return 1;
			}
		} else {
			return miller_rabin(n);
		}
		return 0;
	}

	ll euler_phi(ll n, int calc_mode=0) {
		

		if (n <= 1) return max(0ll, n);
		if (((int) phi.size()) > n) return phi[n];
		if (calc_mode == 0) calc_mode = (n > __AUTO_POLLARD_RHO_BOUND)? 2 : 1;
		if (calc_mode == 1) {
			if (((int) primes.size()) > 0 && primes.back() * primes.back() >= n) {
				ll r = n;
				for (auto &p : primes) {
					if (n % p == 0) { r -= r/p; while (n % p == 0) n /= p; }
					if (p * p > n) break;
				}
				if (n > 1) r -= r/n;
				return r;
			} else {
				ll r = n;
				for (ll p=2; p*p<=n; p++) {
					if (n % p == 0) { r -= r/p; while (n % p == 0) n /= p; }
				}
				if (n > 1) r -= r/n;
				return r;
			}
		} else {
			factor f = factorization(n, 2);
			ll r = n;
			for (auto &pe : f) {
				r -= r/pe.first;
			}
			return r;
		}
	}

	ll mobius(ll n, int calc_mode=0) {
		

		assert(n > 0);
		if (((int) mob.size()) > n) return mob[n];
		if (calc_mode == 0) calc_mode = (n > __AUTO_POLLARD_RHO_BOUND)? 2 : 1;
		if (calc_mode == 1) {
			if (((int) primes.size()) > 0 && primes.back() * primes.back() >= n) {
				ll r = 1;
				for (auto &p : primes) {
					if (n % (p*p) == 0) return 0;
					if (n % p == 0) r = -r, n /= p;
					if (p * p > n) break;
				}
				if (n > 1) r = -r;
				return r;
			} else {
				ll r = 1;
				for (ll p=2; p*p<=n; p++) {
					if (n % (p*p) == 0) return 0;
					if (n % p == 0) r = -r, n /= p;
				}
				if (n > 1) r = -r;
				return r;
			}
		} else {
			factor f = factorization(n, 2);
			ll r = 1;
			for (auto &pe : f) {
				if (pe.second >= 2) return 0;
				r = -r;
			}
			return r;
		}
	}


	ll to_number(factor f) {
		ll r = 1;
		for (auto &pe : f)
			for (int i=0; i<pe.second; i++) r *= pe.first;
		return r;
	}

	struct divisor_iterator {
		ll n;
		factor f;

		void init() { f = factorization(n); }
		divisor_iterator(ll n_) : n(n_) { init(); }
		void set_number(ll n_) { n = n_; init(); }
		ll next_divisor(ll d) {
			assert(n % d == 0);
			factor iter = f;
			for (auto &pe : iter) pe.second = 0;
			for (auto &pe : iter) { while (d % pe.first == 0) pe.second++, d /= pe.first; }
			for (int i=0; i<((int) iter.size()); i++) {
				if (iter[i].second == f[i].second) iter[i].second = 0;
				else { iter[i].second++; break; }
			}
			return to_number(iter);
		}
	};

	vector<ll> divisors(ll n) {
		vector<ll> r;
		divisor_iterator iter(n);
		ll d = 1;
		while (d != n) {
			r.push_back(d);
			d = iter.next_divisor(d);
		}
		r.push_back(n);
		return r;
	}

	vector<ll> prime_divisors(ll n) {
		factor f = factorization(n);
		vector<ll> r;
		for (auto &pe : f) r.push_back(pe.first);
		return r;
	}
	 

	
	vector<ll> facts;
	vector<vector<ll> > binoms;

	bool __FACTS_ENABLE_MOD = 1;
	ll __FACTS_MOD = MOD;
	bool __BINOMS_ENABLE_MOD = 1;
	ll __BINOMS_MOD = MOD;
	
	void make_facts(int n, bool enable_mod=1, ll mod=0) {
		

		if (enable_mod && mod == 0) mod = MOD;
		__FACTS_ENABLE_MOD = enable_mod;
		__FACTS_MOD = enable_mod? mod : 0;

		facts.assign(n+1, 1);
		for (int i=1; i<=n; i++) {
			facts[i] = enable_mod? mod_mult(facts[i-1], i, mod) : facts[i-1] * i;
		}
	}

	void make_binoms(int n, int m, bool enable_mod=1, ll mod=0) {
		

		if (enable_mod && mod == 0) mod = MOD;
		__BINOMS_ENABLE_MOD = enable_mod;
		__BINOMS_MOD = enable_mod? mod : 0;

		binoms.assign(n, vector<ll>(m, 0));
		binoms[0][0] = 1;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				binoms[i][j] = binoms[i-1][j] + (j>0? binoms[i-1][j-1] : 0);
				if (enable_mod) binoms[i][j] %= mod;
			}
		}
	}

	ll factorial(ll n, bool enable_mod=1, ll mod=0) {
		if (enable_mod && mod == 0) mod = MOD;
		if (((int) facts.size()) > n && enable_mod == __FACTS_ENABLE_MOD && mod == __FACTS_MOD)
			return facts[n];
		ll r = 1;
		for (int i=1; i<=n; i++) {
			r = enable_mod? mod_mult(r, i, mod) : r * i;
		}
		return r;
	}

	ll binomial(ll n, ll m, bool enable_mod=1, ll mod=0) {
		if (enable_mod && mod == 0) mod = MOD;
		if (((int) binoms.size()) > n && ((int) binoms[0].size()) > m &&
				enable_mod == __BINOMS_ENABLE_MOD && mod == __BINOMS_MOD)
			return binoms[n][m];
		else {
			if (enable_mod) return mod_div(mod_div(factorial(n, 1, mod), factorial(n-m, 1, mod)), factorial(m, 1, mod));
			else {
				ll a = m, b = n-m; if (a<b) swap(a, b);
				ll r = 1;
				for (ll c=a+1; c<=n; c++) r *= c;
				return r / factorial(b, 0);
			}
		}
	}
	
};
#endif

#define NUMBER_THEORY_DEFINED




using namespace number_theory;

const int MAX_N = 2e5 + 20;

ll Fwa[MAX_N], Fwpp[MAX_N];

void init_fw() {
	fill(Fwa, Fwa+MAX_N, 0);
	fill(Fwpp, Fwpp+MAX_N, 0);
}

void add_a(int p, int v) {
	for (p+=10; p<MAX_N; p+=p&-p) {
		Fwa[p] = mod_clip(Fwa[p] + v);
	}
}

void add_pp(int p, int v) {
	for (p+=10; p<MAX_N; p+=p&-p) {
		Fwpp[p] = mod_clip(Fwpp[p] + v);
	}
}

ll sum_a(int p) {
	ll s = 0;
	for (p+=10; p; p&=p-1) {
		s = s + Fwa[p];
	}
	return s;
}

ll sum_pp(int p) {
	ll s = 0;
	for (p+=10; p; p&=p-1) {
		s = s + Fwpp[p];
		if (s >= MOD) s -= MOD;
	}
	return s;
}

ll sum_a(int l, int r) {
	return mod_clip(sum_a(r) - sum_a(l-1));
}

ll sum_pp(int l, int r) {
	return mod_clip(sum_pp(r) - sum_pp(l-1));
}


int n;

int prev(int p) {
	int l = 1, r = p-1, m;
	int s = sum_a(r);
	while (l<r) {
		m = (l+r) >> 1;
		if (sum_a(m) == s) r = m;
		else l = m+1;
	}
	return l;
}

int next(int p) {
	int l = p+1, r = n+1, m;
	int s = sum_a(p);
	while (l<r) {
		m = (l+r) >> 1;
		if (sum_a(m) > s) r = m;
		else l = m+1;
	}
	return l;
}

ll PP[MAX_N];

inline ll interval(int l, int r) {
	ll dprod = PP[r-1];
	ll inter = sum_pp(l-1, r-2);
	return mod_div(inter, dprod);
}








int main() {
	

	
	init_fw();

	int q;
	scanf("%d%d", &n, &q);
	

	ll p_prod = 1;
	add_pp(0, p_prod);

	for (int i=1; i<=n; i++) {
		int p;
		scanf("%d", &p);
		

		ll p100 = mod_div(p, 100);
		p_prod = mod_mult(p_prod, p100);
		add_pp(i, p_prod);
		PP[i] = p_prod;
	}

	add_a(1, 1);
	add_a(n+1, 1);

	vi chk(n+1, 0);
	chk[1] = 1;

	ll sum = interval(1, n+1);

	while (q--) {
		int u;
		scanf("%d", &u);
		


		if (chk[u] == 1) {
			int pv = prev(u);
			int nx = next(u);

			sum = sum - interval(pv, u);
			sum = sum - interval(u, nx);
			sum = sum + interval(pv, nx);
			sum %= MOD;
			sum = sum<0? sum+MOD : sum;

			chk[u] = 0;
			add_a(u, -1);
			printf("%d\n", (int) sum);
		} else {
			add_a(u, 1);
			chk[u] = 1;

			int pv = prev(u);
			int nx = next(u);

			sum = sum + interval(pv, u);
			sum = sum + interval(u, nx);
			sum = sum - interval(pv, nx);
			sum %= MOD;
			sum = sum<0? sum+MOD : sum;

			printf("%d\n", (int) sum);
		}
	}
	
	
#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
	return 0;
}
