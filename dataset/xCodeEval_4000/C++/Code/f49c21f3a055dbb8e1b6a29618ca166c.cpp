#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define pb push_back
#define ppp pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define stie std::tie
#define vec vector
#define forn(i, l, r) for (int i=l; i<=r; i++)
#define forb(i, r, l) for (int i=r; i>=l; i--)
#define emp empty
#define beg begin
#define ins insert
#define cle clear
#define era erase
#define que queue
#define pque priority_queue
#define mset multiset
#define deq deque
#define sta stack
#define con const
#define rsz resize
#define ass assign
#define lowb lower_bound
#define uppb upper_bound
#define oper operator
#define fri friend
#define tem template
#define temt tem <class T>
#define temtv temt void

temtv mini(T& a, T b) { a = min(a, b); }
temtv maxi(T& a, T b) { a = max(a, b); }
temt T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
tem <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> con& a) {
    return os << "[" << a.fi << ", " << a.se << "]";
}
tem <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container con& a) {
    os << "{ "; for (auto& i : a) os << i << " "; return os << "}";
}
temtv out(T a) { cout << a << endl; }
tem <class T, class... Args> void out(T a, Args... b) { cout << a << " "; out(b...); }
temtv out(vec<vec<T>> a) { for (vec<T> i : a) out(i); }
temtv out_(T a[], int l, int r) { forn(i, l, r) cout << a[i] << " "; cout << endl; }
void out() { cout << "OK" << endl; }
temtv sort(vec<T>& a) { sort(a.beg(), a.end()); }
temtv rever(vec<T>& a) { reverse(a.beg(), a.end()); }
temtv uniq(vec<T>& a) { sort(a); a.era(unique(a.beg(), a.end()), a.end()); }
clock_t start_time; void start_timer() { start_time = clock(); }
double get_time() { return (double)(clock() - start_time) / CLOCKS_PER_SEC; }
temt using min_pque = priority_queue<T, vec<T>, greater<T>>;

void Solve();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    start_timer();
    Solve();
#ifdef LOCAL
    cerr << fixed << setprecision(3);
    cerr << endl << "Time spent: " << get_time() << endl;
#endif
    return 0;
}































template <int m>
struct mint {
    int x = 0;
    mint(int64_t a = 0) { if (a < 0) a = a % m + m; if (a >= m) a %= m; x = a; }
    friend istream& operator>>(istream& in, mint& a) { int64_t y; in >> y; a = y; return in; }
    friend ostream& operator<<(ostream& out, mint a) { return out << a.x; }
    explicit operator int() const { return x; }
    static int mod_inv(int a, int mod = m) {
        int g = mod, r = a, z = 0, y = 1;
        while (r != 0) { int q = g / r; g %= r; swap(g, r); z -= q * y; swap(z, y); }
        return z < 0 ? z + mod : z;
    }
    mint inv() const { return mod_inv(x, m); }
    friend mint binpow(mint a, int64_t b) { mint res = 1; while (b) { if (b & 1) res *= a; b >>= 1; a *= a; } return res; }
    mint pow(int64_t b) const { return binpow(*this, b); }
    mint operator-() const { return x ? m - x : 0; }
    mint& operator+=(const mint& a) { x += a.x; if (x >= m) x -= m; return *this; }
    mint& operator-=(const mint& a) { x -= a.x; if (x < 0) x += m; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned mod = m) {
#if defined(_WIN32) && !defined(_WIN64)
        

        

        unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (mod));
        return rem;
#else
        return x % mod;
#endif
    }
    mint& operator*=(const mint& a) { x = fast_mod((uint64_t) x * a.x); return *this; }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    mint& operator++() { x = x == m - 1 ? 0 : x + 1; return *this; }
    mint& operator--() { x = x == 0 ? m - 1 : x - 1; return *this; }
    mint operator++(int) { mint a = *this; ++*this; return a; }
    mint operator--(int) { mint a = *this; --*this; return a; }
    bool operator==(const mint& a) const { return x == a.x; }
    bool operator!=(const mint& a) const { return x != a.x; }
};

con int mod = 998244353;

#define mi mint<mod>

con int N = 2000 * 2000 + 5;

typedef bitset<N> V;
typedef vec<V> M;

M tr(vec<vec<int>> a) {
	M res;
	int n = a.size();
	int m = a[0].size();
	forn(i, 0, n - 1) {
		forn(j, 0, m - 1) {
			V v;
			forn(k, 0, n - 1) {
				v[k * m + j] = 1;
			}
			forn(k, 0, m - 1) {
				v[i * m + k] = 1;
			}
			if (a[i][j] == 1) {
				v[n * m] = 1;
			}
			res.pb(v);
		}
	}
	return res;
}

struct S {
	M a;
	vec<int> piv;
	int n, m;
	S(vec<vec<int>> a) {
		n = a.size();
		m = a[0].size();
		M m = tr(a);
		for (V v : m) {
			add(v);
		}
	}
	S(int n, int m) : n(n), m(m) {}
	void add(V v) {
		forn(i, 0, (int) a.size() - 1) {
			if (v[piv[i]] == 1) {
				v ^= a[i];
			}
		}
		if (v.none()) return;
		int p = v._Find_first();
		piv.pb(p);
		forn(i, 0, (int) a.size() - 1) {
			if (a[i][p] == 1) {
				a[i] ^= v;
			}
		}
		a.pb(v);
	}
	int rank() {
		return a.size();
	}
	bool good() {
		for (V& v : a) {
			if (v._Find_first() == n * m) {
				return 0;
			}
		}
		return 1;
	}
};


int slow(vec<vec<int>> a, bool pr = 0) {
	int n = a.size();
	int m = a[0].size();
	vec<pii> b;
	forn(i, 0, n - 1) {
		forn(j, 0, m - 1) {
			if (a[i][j] == -1) b.pb({i, j});
		}
	}
	vec<vec<int>> c = a;
	int res = 0;
	forn(mask, 0, (1 << b.size()) - 1) {
		forn(k, 0, (int) b.size() - 1) {
			int i, j;
			stie(i, j) = b[k];
			if (mask & (1 << k)) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = 0;
			}
		}
		S s(c);
		if (s.good()) {
			res++;
			if (pr) {
                forn(i, 0, n - 1) {
                    forn(j, 0, m - 1) {
                        cout << c[i][j];
                    }
                    cout << endl;
                }
                cout << endl;
			}
		}
	}
	return res;
}

mt19937 rnd;

vec<vec<int>> Read() {
	int n, m;
	cin >> n >> m;
	vec<vec<int>> b(n, vec<int>(m));
	forn(i, 0, n - 1) {
		forn(j, 0, m - 1) {
			char c;
			cin >> c;
			if (c == '?') b[i][j] = -1;
			else b[i][j] = c - '0';
		}
	}
	return b;
}

vec<vec<int>> Gen() {
	int n, m;
	n = rnd() % 2000 + 1;
	m = rnd() % 2000 + 1;
	vec<vec<int>> b(n, vec<int>(m));
	forn(i, 0, n - 1) {
		forn(j, 0, m - 1) {
			char c;
			int cur = rnd() % 3;
			if (cur == 0) c = '?';
			else if (cur == 1) c = '0';
			else c = '1';
			if (c == '?') b[i][j] = -1;
			else b[i][j] = c - '0';
		}
	}
	return b;
}

void guess() {
	forn(i, 0, 10) {
		vec<vec<int>> a = Read();
		out(slow(a));
		out("");
	}
}

con int K = 4005;

int p[K];
int d[K];
int sum_r[K];
int sum_c[K];
int cnt_q[K];

void init(int tar) {
	forn(i, 0, K - 1) {
		p[i] = i;
		d[i] = 0;
		sum_r[i] = 0;
		sum_c[i] = 0;
		cnt_q[i] = 0;
	}
}

int find(int v) {
	if (p[v] == v) return v;
	return p[v] = find(p[v]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (d[u] < d[v]) swap(u, v);
	p[v] = u;
	if (d[u] == d[v]) d[u]++;
	sum_r[u] ^= sum_r[v];
	sum_c[u] ^= sum_c[v];
	cnt_q[u] += cnt_q[v];
}

mi sol(vec<vec<int>> a) {
	int n = a.size();
	int m = a[0].size();
	if (n % 2 == 0 && m % 2 == 0) {
		int cnt = 0;
		forn(i, 0, n - 1) {
			forn(j, 0, m - 1) {
				if (a[i][j] == -1) cnt++;
			}
		}
		return mi(2).pow(cnt);
	}
	else if ((n + m) & 1) {
		if (n & 1) {
			vec<vec<int>> new_a(m, vec<int>(n, 0));
			forn(i, 0, n - 1) {
				forn(j, 0, m - 1) {
					new_a[j][i] = a[i][j];
				}
			}
			a = new_a;
			swap(n, m);
		}
		int qs = 0;
		int one = 0;
		int one_qs = 0;
		forn(j, 0, m - 1) {
			if (a[0][j] == -1) {
				qs++;
				one_qs++;
			}
			else if (a[0][j] == 1) {
				one ^= 1;
			}
		}
		int rank = 0;
		int odd = 0;
		int even = 0;
		forn(i, 1, n - 1) {
			int cur = one;
			int cur_qs = 0;
			forn(j, 0, m - 1) {
				if (a[i][j] == -1) {
					qs++;
					cur_qs++;
				}
				else if (a[i][j] == 1) {
					cur ^= 1;
				}
			}
			if (cur_qs + one_qs == 0 && cur) return 0;
			if (cur_qs == 0) {
				if (cur) odd++;
				else even++;
				continue;
			}
			rank++;
		}
		if (odd && even) return 0;
		if (one_qs == 0 && odd) return 0;
		if (one_qs && odd + even) rank++;
		assert(qs >= rank);
		return mi(2).pow(qs - rank);
	}
	else {
		mi res = 0;
		for (int tar : {0, 1}) {
			init(tar);
			forn(i, 0, n - 1) {
				sum_r[i + 1] = tar;
			}
			forn(j, 0, m - 1) {
				sum_c[n + j + 1] = tar;
			}
			int qs = 0;
			forn(i, 0, n - 1) {
				forn(j, 0, m - 1) {
					if (a[i][j] == -1) {
						qs++;
						cnt_q[i + 1]++;
					}
					else {
						sum_r[i + 1] ^= a[i][j];
						sum_c[n + j + 1] ^= a[i][j];
					}
				}
			}
			forn(i, 0, n - 1) {
				forn(j, 0, m - 1) {
					if (a[i][j] == -1) {
						unite(i + 1, n + j + 1);
					}
				}
			}
			int rank = 0;
			forn(i, 0, n - 1) {
				forn(j, 0, m - 1) {
					if (a[i][j] == -1) {
						rank++;
						break;
					}
				}
			}
			forn(j, 0, m - 1) {
				forn(i, 0, n - 1) {
					if (a[i][j] == -1) {
						rank++;
						break;
					}
				}
			}
			bool ok = 1;
			forn(i, 1, n + m) {
				if (p[i] != i) continue;
				if (sum_r[i] != sum_c[i]) {
					ok = 0;
					break;
				}
				if (cnt_q[i] == 0 && sum_r[i]) {
					ok = 0;
					break;
				}
				if (cnt_q[i]) rank--;
			}
			if (!ok) continue;
			assert(qs >= rank);
			res += mi(2).pow(qs - rank);
		}
		return res;
	}
	return 0;
}

void stress() {
	while (1) {
		vec<vec<int>> a = Gen();
		out(a);
		mi slow_ans = slow(a);
		mi sol_ans = sol(a);
		if (slow_ans != sol_ans) {
			out(slow_ans, sol_ans);
			exit(0);
		}
		out();
	}
}

void test() {
    vec<vec<int>> a = {{ -1, 1, -1, }};
	int n = a.size();
	int m = a[0].size();
	forn(i, 0, n - 1) {
		forn(j, 0, m - 1) {
			if (a[i][j] == -1) {
				cout << '?';
			}
			else {
				cout << a[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	out(slow(a, 1));
	out(sol(a));
	exit(0);
}

void Solve() {
	

	

	

	

    vec<vec<int>> b = Read();
    out(sol(b));
}
