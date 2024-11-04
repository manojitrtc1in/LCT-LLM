

















using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;

















template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod; return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;
}
template <typename T, typename U> T divceil(T m, U d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}






class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {

    cerr << v;

return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, const map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *
itr; itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, const set<T>& set_var) { os << "{"; repi(
itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}";
return os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const
pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func(
) { debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail
&&... tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(forward
<Tail>(tail)...); }


<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)










template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  ll value;
  static constexpr ll Mod = MOD;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint& rhs) {
    return value != rhs.value;
  }
  constexpr modint operator-() const {
    return modint(0) - *this;
  }
  constexpr modint operator+(const modint& rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint& operator-=(const modint& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint& operator*=(const modint& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint& operator/=(const modint& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint& operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint& operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}



template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}




template <typename M>
class binomial {
public:
  vector<M> fact, invfact;
  binomial(int n) : fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * M(i+1);
    invfact[n] = M(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * M(i+1);
  }
  M operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return M(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};






constexpr ll mods(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}

constexpr int id2(int x) {
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template <int X = 2>
class NTT {
 public:
  static constexpr int md = mods(X);
  static constexpr int rt = id2(X);
  using mint = modint<md>;

 private:
  vector<vector<mint>> root, rroot;

  void prepare(int n) {
    if (root.size() >= n) return;
    root.resize(n);
    rroot.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!root[i].empty()) continue;
      mint w = pow(mint(rt), (md - 1) / (i << 1));
      mint rw = mint(1) / w;
      root[i].resize(i);
      rroot[i].resize(i);
      root[i][0] = mint(1);
      rroot[i][0] = mint(1);
      rep(k, 1, i) root[i][k] = root[i][k - 1] * w,
                   rroot[i][k] = rroot[i][k - 1] * rw;
    }
  }

 public:
  void ntt(vector<mint>& A, bool reverse) {
    int n = A.size();
    assert((n & (n - 1)) == 0);
    prepare(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1) {}
      if (i > j) swap(A[i], A[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          mint z = A[i + j + k] * (reverse ? rroot[i][k] : root[i][k]);
          A[i + j + k] = A[j + k] - z;
          A[j + k] += z;
        }
      }
    }

    if (reverse) {
      mint tmp = mint(1) / mint(n);
      rep(i, n) A[i] *= tmp;
    }
  }

  vector<mint> multiply(vector<mint> A, vector<mint> B) {
    int need = A.size() + B.size() - 1;
    int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

    A.resize(sz, mint(0));
    B.resize(sz, mint(0));

    ntt(A, 0);
    ntt(B, 0);
    rep(i, sz) A[i] *= B[i];
    ntt(A, 1);

    A.resize(need);
    return A;
  }

  vector<ll> multiply(vector<ll> A, vector<ll> B) {
    vector<mint> am(A.size()), bm(B.size());
    rep(i, am.size()) am[i] = mint(A[i]);
    rep(i, bm.size()) bm[i] = mint(B[i]);
    vector<mint> cm = multiply(am, bm);
    vector<ll> cs(cm.size());
    rep(i, cs.size()) cs[i] = cm[i].value;
    return cs;
  }
};


namespace Garner {

static NTT<0> id3;
static NTT<1> id1;
static NTT<2> id0;

static ll inv(ll x, ll md) { return power(x, md - 2, md); }

ll garner(ll c0, ll c1, ll c2, ll m01, ll mod) {
  static ll r01 = inv(id3.md, id1.md);
  static ll r02 = inv(id3.md, id0.md);
  static ll r12 = inv(id1.md, id0.md);

  c1 = (ll)(c1 - c0) * r01 % id1.md;
  if (c1 < 0) c1 += id1.md;

  c2 = (ll)(c2 - c0) * r02 % id0.md;
  c2 = (ll)(c2 - c1) * r12 % id0.md;
  if (c2 < 0) c2 += id0.md;

  c0 %= mod;
  c0 += (ll)c1 * id3.md % mod;
  if (c0 >= mod) c0 -= mod;
  c0 += (ll)c2 * m01 % mod;
  if (c0 >= mod) c0 -= mod;

  return c0;
}

vector<ll> garner(vector<vector<ll>> &cs, ll mod) {
  ll m01 = (ll)id3.md * id1.md % mod;
  ll sz = cs[0].size();
  vector<ll> res(sz);
  for (ll i = 0; i < sz; i++)
    res[i] = garner(cs[0][i], cs[1][i], cs[2][i], m01, mod);
  return res;
}

vector<ll> multiply(vector<ll> as, vector<ll> bs, ll mod) {
  vector<vector<ll>> cs(3);
  cs[0] = id3.multiply(as, bs);
  cs[1] = id1.multiply(as, bs);
  cs[2] = id0.multiply(as, bs);
  size_t sz = as.size() + bs.size() - 1;
  for (auto &v : cs) v.resize(sz);
  return garner(cs, mod);
}

template <ll Mod = 1000000007>
vector<modint<Mod>> multiply(vector<modint<Mod>> am, vector<modint<Mod>> bm) {
  vector<ll> as(am.size()), bs(bm.size());
  rep(i, am.size()) as[i] = am[i].value;
  rep(i, bm.size()) bs[i] = bm[i].value;
  vector<ll> cs = multiply(as, bs, Mod);
  vector<modint<Mod>> cm(cs.size());
  rep(i, cs.size()) cm[i] = modint<Mod>(cs[i]);
  return cm;
}

};  




using mint = modint<>;
int main() {
	cin.tie(0);	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	ll n0 = n;
	vector<mint> a(n); rep(i, n) cin >> a[i].value;

	if (n == 1) {
		cout << a[0].value << newl; exit(0);
	} else if (n == 2) {
		cout << (a[0] + a[1]).value << newl; exit(0);
	}

	if (n % 2 == 1) {
		vector<mint> b = a;
		rep(i, 1, n) {
			if (i % 2 == 0) b[i-1] -= a[i];
			else b[i-1] += a[i];
		}
		b.pop_back();
		swap(a, b);
		n--;
	}

	binomial<mint> binom(n/2);

	vector<mint> f(n);
	for (int i = 0; i <= n-2; i += 2) {
		f[i] = binom(n/2-1, i/2);
	}

	a = Garner::multiply(a, f);
	mint res;
	if (n0*(n0-1)/2 % 2 == 0) {
		res = a[n-2] - a[n-1];
	} else {
		res = a[n-2] + a[n-1];
	}

	cout << res.value << newl;
}
