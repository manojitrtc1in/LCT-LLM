











using namespace std;

constexpr long long INF = 1e18;


constexpr int MOD = 1000000007;


constexpr long double EPS = 1e-10;
constexpr long double PI = M_PI;

using ll = long long; using ull = unsigned long long; using ld = long double; using pll = pair<ll, ll>; using pii = pair<int, int>; using pli = pair<ll, int>; using pil = pair<int, ll>; using vvl = vector<vector<ll>>; using vvi = vector<vector<int>>; using vvpll = vector<vector<pll>>; using vvpli = vector<vector<pli>>; using vvpil = vector<vector<pil>>;














constexpr ll INF = 1e18; constexpr int MOD = 1000000007; constexpr ld EPS = 1e-10; constexpr ld PI = M_PI;

template<int mod> struct ModInt { int x; ModInt() : x(0) {} ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {} ModInt &operator++() { x++; if (x == mod) x = 0; return *this; } ModInt &operator--() { if (x == 0) x = mod; x--; return *this; } ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; } ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; } ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; } ModInt &operator/=(const ModInt &p) { *this *= p.inv(); return *this; } ModInt operator++(int) { ModInt result = *this; ++*this; return result; } ModInt operator--(int) { ModInt result = *this; --*this; return result; } ModInt operator-() const { return ModInt(-x); } ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; } ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; } ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; } ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; } bool operator==(const ModInt &p) const { return x == p.x; } bool operator!=(const ModInt &p) const { return x != p.x; } ModInt inv() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); } ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; } friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; } friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); } static int get_mod() { return mod; }

operator ll() const { return x; }

}; using mint = ModInt<MOD>;
template<typename T> vector<vector<T>> id9(int N, int M, T init) { return vector<vector<T>>(N, vector<T>(M, init)); } template<typename T> vector<vector<vector<T>>> id3(int N, int M, int L, T init) { return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L, init))); } template<typename T> vector<vector<vector<vector<T>>>> id5(int N, int M, int L, int O, T init) { return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init)))); }
template<typename T=ll> vector<T> LIST(ll N) { vector<T> A(N); rep(i, N) { cin >> A[i]; } return A; } template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; } template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in: v) is >> in; return is; }
void print() { cout << '\n'; } template<typename T> void print(T out) { cout << out << '\n'; } template<typename T1, typename T2> void print(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << '\n'; } template<typename T1, typename T2, typename T3> void print(const tuple<T1, T2, T3> &tp) { cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\n'; } template<typename T1, typename T2, typename T3, typename T4> void print(const tuple<T1, T2, T3, T4> &tp) { cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\n'; } template<typename T1, typename T2> void print(const vector<pair<T1, T2>> &V) { for (auto& p : V) print(p); } template<typename T> void print(const vector<T> &V) { rep(i, V.size()) { cout << V[i]; if (i != V.size()-1) cout << ' '; } cout << '\n'; } template<typename T, size_t SZ> void print(const array<T, SZ> &arr) { rep(i, arr.size()) { cout << arr[i]; if (i != arr.size()-1) cout << ' '; } cout << '\n'; } template<typename T, size_t SZ> void print(const vector<array<T, SZ>> &V) { for (auto& arr : V) print(arr); } template<typename T> void print(const deque<T> &que) { vector<T> V(ALL(que)); print(V); } template<typename T> void print(const set<T> &se) { vector<T> V(ALL(se)); print(V); }

void Yes() { print("Yes"); } void No() { print("No"); } void YES() { print("YES"); } void NO() { print("NO"); }
ll toint(string s) { assert(s.size() < 20); ll res = 0; for (char &c : s) { res *= 10; res += c - '0'; } return res; } int toint(char num) { return num - '0'; }
char tochar(int num) { return '0' + num; }
template<typename T> T ceil(T a, T b) { if (a >= 0) return (a+b-1) / b; else return a / b; }
template<typename T> T modulo(T a, T b) { return ((a % b) + b) % b; }
template<typename T> pair<T, T> divmod(T a, T b) { T d = a / b; T m = a % b; return {d, m}; }
template<typename T> bool chmin(T &x, T y) { return (y < x) ? x = y, true : false; }
template<typename T> bool chmax(T &x, T y) { return (y > x) ? x = y, true : false; }
template<typename T> T sum(const vector<T> &A) { return accumulate(ALL(A), (T)0); } template<typename key, typename val> val sum(const map<key, val> &mp) { val res = 0; for (auto& [k, v] : mp) res += v; return res; }
template<typename T> T min(const vector<T> &A) { return *min_element(ALL(A)); } template<typename key, typename val> val min(const map<key, val> &mp) { val res = numeric_limits<val>::max(); for (auto& [k, v] : mp) chmin(res, v); return res; }
template<typename T> T max(const vector<T> &A) { return *max_element(ALL(A)); } template<typename key, typename val> val max(const map<key, val> &mp) { val res = numeric_limits<val>::min(); for (auto& [k, v] : mp) chmax(res, v); return res; }
ll pow(ll x, ll n) { ll res = 1; rep(_, n) res *= x; return res; } ll pow(int x, ll n) { return pow((ll)x, n); } ll pow(ll x, int n) { return pow(x, (ll)n); } ll pow(int x, int n) { return pow((ll)x, (ll)n); } ll pow(ll x, ll n, int mod) { x %= mod; ll res = 1; while (n > 0) { if (n & 1) { res = (res * x) % mod; } x = (x * x) % mod; n >>= 1; } return res; }
int popcount(ll S) { return __builtin_popcountll(S); }
int bit_length(ll x) { return x != 0 ? floor(log2((ld)x))+1 : 0; }
template<typename T> int id1(const vector<T> &A, T val, int lo=0) { return lower_bound(A.begin()+lo, A.end(), val) - A.begin(); } template<typename T> int id10(const vector<T> &A, T val, int lo=0) { return upper_bound(A.begin()+lo, A.end(), val) - A.begin(); }
template<typename T> map<T, ll> Counter(const vector<T> &A) { map<T, ll> res; for (T a : A) { res[a]++; } return res; } template<typename T> vector<ll> Counter(const vector<T> &A, int mx) { vector<ll> res(mx+1); for (T a : A) { res[a]++; } return res; } map<char, ll> Counter(const string &S) { map<char, ll> res; for (char c : S) { res[c]++; } return res; } template<typename T> vector<pair<ll, T>> most_common(const map<T, ll>& C) { vector<pair<ll, T>> res; for (auto [k, v] : C) { res.eb(v, k); } sort(res.rbegin(), res.rend()); return res; }
template<typename F> ll id6(ll mn, ll mx, const F &func) { ll ok = mx; ll ng = mn; while (ng+1 < ok) { ll mid = (ok+ng) / 2; if (func(mid)) { ok = mid; } else { ng = mid; } } return ok; } template<typename F> ll id13(ll mn, ll mx, const F &func) { ll ok = mn; ll ng = mx; while (ok+1 < ng) { ll mid = (ok+ng) / 2; if (func(mid)) { ok = mid; } else { ng = mid; } } return ok; }
template<typename T1, typename T2> pair<vector<T1>, vector<T2>> zip(const vector<pair<T1, T2>> &A) { int N = A.size(); pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)}; rep(i, N) { res.first[i] = A[i].first; res.second[i] = A[i].second; } return res; } template<typename T1, typename T2, typename T3> tuple<vector<T1>, vector<T2>, vector<T3>> zip(const vector<tuple<T1, T2, T3>> &A) { int N = A.size(); tuple<vector<T1>, vector<T2>, vector<T3>> res = {vector<T1>(N), vector<T2>(N), vector<T3>(N)}; rep(i, N) { get<0>(res)[i] = get<0>(A[i]); get<1>(res)[i] = get<1>(A[i]); get<2>(res)[i] = get<2>(A[i]); } return res; }
template<typename T> struct Compress { int N; vector<T> dat; Compress(vector<T> A) { sort(A.begin(), A.end()); A.erase(unique(A.begin(), A.end()), A.end()); N = A.size(); dat = A; } int zip(T x) { return id1(dat, x); } T unzip(int x) { return dat[x]; } int operator[](T x) { return zip(x); } int size() { return dat.size(); } vector<ll> zip(const vector<T> &A) { int M = A.size(); vector<ll> res(M); rep(i, M) res[i] = zip(A[i]); return res; } };
template<typename T> vector<pair<T, int>> RLE(const vector<T> &A) { if (A.empty()) return {}; int N = A.size(); vector<pair<T, int>> res; T cur = A[0]; int cnt = 1; rep(i, 1, N) { if (A[i] == A[i-1]) { cnt++; } else { res.pb({cur, cnt}); cnt = 1; cur = A[i]; } } res.pb({cur, cnt}); return res; } vector<pair<char, int>> RLE(const string &S) { if (S.empty()) return {}; int N = S.size(); vector<pair<char, int>> res; char cur = S[0]; int cnt = 1; rep(i, 1, N) { if (S[i] == S[i-1]) { cnt++; } else { res.pb({cur, cnt}); cnt = 1; cur = S[i]; } } res.pb({cur, cnt}); return res; }
template<typename T> bool id11(T x, T y) { T z; return __builtin_mul_overflow(x, y, &z); }
vector<ll> split(const string &S, char separator) { int N = S.size(); vector<ll> res; string cur; rep(i, N) { if (S[i] == separator) { res.eb(toint(cur)); cur = ""; } else { cur += S[i]; } } if (cur.size()) res.eb(toint(cur)); return res; }
string to_string(const string &S) { return S; } string to_string(char c) { return {c}; }
template<typename T> string join(const vector<T> &A, char separator=0) { int N = A.size(); string res; rep(i, N) { res += tostr(A[i]); if (separator != 0 and i != N-1) res += separator; } return res; }
template<typename T> vector<T> sorted(vector<T> A, bool reverse=false) { sort(ALL(A)); if (reverse) std::reverse(ALL(A)); return A; } string sorted(string S, bool reverse=false) { sort(ALL(S)); if (reverse) std::reverse(ALL(S)); return S; }
template<typename T> vector<T> reversed(vector<T> A) { reverse(ALL(A)); return A; } string reversed(string S) { reverse(ALL(S)); return S; }
template<typename T> vector<T> concat(const vector<T>& A, const vector<T>& B) { vector<T> res = A; res.insert(res.end(), B.begin(), B.end()); return res; }
template<typename Mint> struct ModTools { int MAX; vector<Mint> _fact, _factinv, inv; ModTools(int mx) : MAX(++mx) { _fact.resize(MAX); _factinv.resize(MAX); inv.resize(MAX); _fact[0] = _fact[1] = 1; rep(i, 2, MAX) { _fact[i] = _fact[i-1]*(Mint)i; } _factinv[MAX-1] = (Mint)1/_fact[MAX-1]; rep(i, MAX-2, -1, -1) { _factinv[i] = _factinv[i+1]*(Mint)(i+1); } rep(i, MAX-1, 0, -1) { inv[i] = _factinv[i]*_fact[i-1]; } } Mint div(Mint a, int b) { return a*inv[b]; } Mint fact(int x) { assert(x < MAX); return _fact[x]; } Mint factinv(int x) { assert(x < MAX); return _factinv[x]; } Mint nCr(int n, int r) { if (n < r or r < 0) return 0; r = min(r, n-r); Mint num = _fact[n]; Mint den = _factinv[r] * _factinv[n-r]; return num * den; } Mint nHr(int n, int r) { assert(r+n-1 < MAX); return nCr(r+n-1, r); } Mint nPr(int n, int r) { if (n < r or r < 0) return 0; return _fact[n] * _factinv[n-r]; } Mint double_factorial(int n) { if (n%2 == 0) { int k = n/2; return Mint(2).pow(k)*fact(k); } else { int k = (n+1)/2; return fact(2*k)/Mint(2).pow(k)/fact(k); } } };
template<typename T> vector<vector<T>> id4(const vector<T> &A, int N=-1) { if (N == -1) N = A.size(); int M = A.size(); assert(N <= M); vector<vector<T>> comb; rep(bit, 1<<M) { if (popcount(bit) != N) continue; vector<T> res; rep(i, M) { if (bit>>i & 1) { res.pb(A[i]); } } comb.pb(res); } vector<vector<T>> res; for (auto &perm : comb) { sort(ALL(perm)); do { res.pb(perm); } while (next_permutation(ALL(perm))); } return res; }
template<typename T> vector<vector<T>> combinations(const vector<T> &A, int N) { int M = A.size(); vector<vector<T>> res; auto rec = [&](auto&& f, vector<T> &cur, ll x, ll n) -> void { if (n == N) { res.pb(cur); return; } rep(i, x, M) { cur.pb(A[i]); f(f, cur, i+1, n+1); cur.pop_back(); } }; vector<T> cur; rec(rec, cur, 0, 0); return res; }
ll id12(ll n) { if (n < 2) return 0; return n*(n-1)/2; }
template<typename T> T factorial(int x) { T res = 1; for (int i=1; i<=x; i++) res *= i; return res; }
struct UnionFind { int n, groupcnt; vector<int> par, rank, sz; vector<bool> tree; UnionFind(int n) : n(n) { par.assign(n, 0); rank.assign(n, 0); sz.assign(n, 1); tree.assign(n, true); rep(i, n) par[i] = i; groupcnt = n; } UnionFind() {} void resize(int _n) { n = _n; par.assign(n, 0); rank.assign(n, 0); sz.assign(n, 1); tree.assign(n, true); rep(i, n) par[i] = i; groupcnt = n; } int find(int x) { if (par[x] == x) { return x; } else { par[x] = find(par[x]); return par[x]; } } int merge(int a, int b) { int x = find(a); int y = find(b); if (x == y) { tree[x] = false; return x; } if (!tree[x] or !tree[y]) { tree[x] = tree[y] = false; } groupcnt--; if (rank[x] < rank[y]) { par[x] = y; sz[y] += sz[x]; return y; } else { par[y] = x; sz[x] += sz[y]; if (rank[x] == rank[y]) { rank[x]++; } return x; } } bool same(int a, int b) { return find(a) == find(b); } ll size(int x) { return sz[find(x)]; } int size() { return groupcnt; } bool is_tree(int x) { return tree[find(x)]; } set<int> get_roots() { set<int> res; rep(i, n) { res.insert(find(i)); } return res; } };
const vector<pii> dir4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ll id15(ll i, ll j, ll W) { return i*W+j; }
pll id14(ll id, ll W) { return divmod(id, W); }
template<typename _Key, typename _Tp> struct defaultdict : map<_Key, _Tp> { const _Tp init; defaultdict() : init(_Tp()) {}; defaultdict(_Tp init) : init(init) {} _Tp& operator[](const _Key& k) { if (this->count(k)) { return map<_Key, _Tp>::operator[](k); } else { return map<_Key, _Tp>::operator[](k) = init; } } _Tp& operator[](_Key&& k) { if (this->count(k)) { return map<_Key, _Tp>::operator[](k); } else { return map<_Key, _Tp>::operator[](k) = init; } } };
ll gcd(ll a, ll b) { return __gcd(a, b); } template<typename T> T gcd(const vector<T> &A) { T res = 0; for (auto a : A) res = gcd(res, a); return res; }
ll lcm(ll x, ll y) { return x/gcd(x, y)*y; } template<typename T> T lcm(const vector<T> &A) { T res = 1; for (auto a : A) res = lcm(res, a); return res; }
template<typename T> vector<pair<T, int>> factorize(T n) { vector<pair<T, int>> ret; for (T i=2; i*i<=n; i++) { int cnt = 0; while (n % i == 0) { n /= i; cnt++; } if (cnt) ret.emplace_back(i, cnt); } if (n > 1) ret.emplace_back(n, 1); return ret; }
template<typename T> vector<T> id0(T n) { vector<T> res; for (T i=1; i*i<=n; i++) { if (n%i == 0) { res.eb(i); if (n/i != i) res.eb(n/i); } } return res; }
ll isqrt(ll n, bool ceil=false) { ll ok = 0; ll ng = 3037000500; while (ng - ok > 1) { ll m = ok + (ng - ok) / 2; if (m * m <= n) { ok = m; } else { ng = m; } } if (ceil and ok*ok != n) ok++; return ok; }
template<typename T> struct Accumulate { vector<T> dat; int N; Accumulate(int N) : N(N) { dat.resize(N); } Accumulate(const vector<T> &A) : N(A.size()), dat(A) { build(); } void set(int i, T a) { dat[i] = a; } void add(int i, T a) { dat[i] += a; } void build() { rep(i, N-1) { dat[i+1] += dat[i]; } dat.insert(dat.begin(), 0); } T query(int l, int r) { assert(0 <= l and l <= N and 0 <= r and r <= N); return dat[r]-dat[l]; } T get(int i) { return query(i, i+1); } T operator[](int i) { return query(i, i+1); } ll bisearch_fore(int l, int r, ll x) { if (l > r) return -1; ll l_sm = query(0, l); int ok = r + 1; int ng = l - 1; while (ng+1 < ok) { int mid = (ok+ng) / 2; if (query(0, mid+1) - l_sm >= x) { ok = mid; } else { ng = mid; } } if (ok != r+1) { return ok; } else { return -1; } } ll bisearch_back(int l, int r, ll x) { if (l > r) return -1; ll r_sm = query(0, r+1); int ok = l - 1; int ng = r + 1; while (ok+1 < ng) { int mid = (ok+ng) / 2; if (r_sm - query(0, mid) >= x) { ok = mid; } else { ng = mid; } } if (ok != l-1) { return ok; } else { return -1; } } };
template<typename T> struct BIT { int sz; vector<T> tree; BIT(int n) { n++; sz = 1; while (sz < n) { sz *= 2; } tree.resize(sz); } T sum(int i) { T s = 0; i++; while (i > 0) { s += tree[i-1]; i -= i & -i; } return s; } void add(int i, T x) { i++; while (i <= sz) { tree[i-1] += x; i += i & -i; } } T query(int l, int r) { return sum(r-1) - sum(l-1); } T get(int i) { return query(i, i+1); } void update(int i, T x) { add(i, x - get(i)); } T operator[](int i) { return query(i, i+1); } void print(int n) { rep(i, n) { cout << query(i, i+1); if (i == n-1) cout << endl; else cout << ' '; } } ll bisearch_fore(int l, int r, ll x) { if (l > r) return -1; ll l_sm = sum(l-1); int ok = r + 1; int ng = l - 1; while (ng+1 < ok) { int mid = (ok+ng) / 2; if (sum(mid) - l_sm >= x) { ok = mid; } else { ng = mid; } } if (ok != r+1) { return ok; } else { return -1; } } ll bisearch_back(int l, int r, ll x) { if (l > r) return -1; ll r_sm = sum(r); int ok = l - 1; int ng = r + 1; while (ok+1 < ng) { int mid = (ok+ng) / 2; if (r_sm - sum(mid-1) >= x) { ok = mid; } else { ng = mid; } } if (ok != l-1) { return ok; } else { return -1; } } };
template<typename Monoid, typename F> struct SegmentTree { int sz; vector<Monoid> seg; const F f; const Monoid M1; SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) { sz = 1; while(sz < n) sz <<= 1; seg.assign(2 * sz, M1); } SegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {} void resize(int n) { sz = 1; while(sz < n) sz <<= 1; seg.resize(2 * sz, M1); } void clear() { seg.clear(); } void set(int k, const Monoid &x) { seg[k+sz] = x; } void build() { for(int k = sz - 1; k > 0; k--) { seg[k] = f(seg[2*k], seg[2*k+1]); } } void build(const vector<Monoid> &A) { int n = A.size(); resize(n); rep(i, n) set(i, A[i]); build(); } void update(int k, const Monoid &x) { k += sz; seg[k] = x; while(k >>= 1) { seg[k] = f(seg[2*k], seg[2*k+1]); } } Monoid query(int a, int b) { Monoid L = M1, R = M1; for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) { if(a & 1) L = f(L, seg[a++]); if(b & 1) R = f(seg[--b], R); } return f(L, R); } Monoid operator[](const int &k) const { return seg[k+sz]; } Monoid all() { return seg[1]; } void print(int n) { for (int i=0; i<n; i++) { cout << query(i, i+1); if (i == n-1) cout << endl; else cout << ' '; } } template<typename C> int id7(int a, const C &check, Monoid &M, bool type) { while(a < sz) { Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]); if(check(nxt)) a = 2 * a + type; else M = nxt, a = 2 * a + 1 - type; } return a - sz; } template<typename C> int find_first(int a, const C &check) { Monoid L = M1; if(a <= 0) { if(check(f(L, seg[1]))) return id7(1, check, L, false); return -1; } int b = sz; for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) { if(a & 1) { Monoid nxt = f(L, seg[a]); if(check(nxt)) return id7(a, check, L, false); L = nxt; ++a; } } return -1; } template<typename C> int find_last(int b, const C &check) { Monoid R = M1; if(b >= sz) { if(check(f(seg[1], R))) return id7(1, check, R, true); return -1; } int a = sz; for(b += sz; a < b; a >>= 1, b >>= 1) { if(b & 1) { Monoid nxt = f(seg[--b], R); if(check(nxt)) return id7(b, check, R, true); R = nxt; } } return -1; } }; template<typename Monoid, typename F> SegmentTree<Monoid, F> id8(int N, const F& f, const Monoid& M1) { return {N, f, M1}; } template<typename Monoid, typename F> SegmentTree<Monoid, F> id8(const F& f, const Monoid& M1) { return {f, M1}; }
const string digits = "0123456789";
const string id2 = "abcdefghijklmnopqrstuvwxyz";
const string id16 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string zfill(string str, int len) { string zeros; int n = str.size(); rep(i, len-n) zeros += '0'; return zeros+str; }
string bin(ll x) { string res; while (x) { if (x & 1) { res += '1'; } else { res += '0'; } x >>= 1; } reverse(ALL(res)); if (res == "") res += '0'; return res; }

void solve() {
    ll N, K;
    cin >> N >> K;
    auto B = LIST(N);

    

    vector<ll> F;
    

    rep(i, K, 0, -1) {
        F.eb(-i);
    }
    

    auto diff = F;
    rep(_, 2) {
        diff.eb(0);
        rep(i, diff.size()-1, 0, -1) {
            diff[i] = diff[i] - diff[i-1];
        }
    }
    

    vector<pll> sdiff;
    rep(i, diff.size()) {
        if (diff[i] != 0) {
            sdiff.eb(i, diff[i]);
        }
    }
    auto imos = id9(N, 3, 0LL);
    

    auto add = [&](ll i, ll x) {
        for (auto [k, d] : sdiff) {
            if (i+k >= N) break;
            imos[i+k][0] += d*x;
        }
    };

    reverse(ALL(B));
    ll ans = 0;
    rep(i, N-K+1) {
        if (i > 0) {
            

            rep(j, 1, 3) {
                imos[i][j] = imos[i-1][j] + imos[i][j-1];
            }
        }
        ll rest = B[i] + imos[i][2];
        if (rest > 0) {
            ll need = ceil(rest, K);
            ans += need;
            add(i, need);
            

            rep(j, 1, 3) {
                imos[i][j] += -K*need;
            }
        }
    }
    

    ll mx = 0;
    rep(k, 1, K) {
        ll i = N-K+k;
        if (i > 0) {
            rep(j, 1, 3) {
                imos[i][j] = imos[i-1][j] + imos[i][j-1];
            }
        }
        ll rest = B[i] + imos[i][2];
        if (rest > 0) {
            ll need = ceil(rest, K-k);
            chmax(mx, need);
        }
    }
    ans += mx;
    print(ans);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    

    solve();

    

    

    

    


    return 0;
}
