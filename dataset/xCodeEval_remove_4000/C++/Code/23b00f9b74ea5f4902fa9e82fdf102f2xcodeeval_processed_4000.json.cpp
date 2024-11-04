
using namespace std;
using ll = long long;
using ld = long double;























template<class T> using PQ_max = priority_queue<T>;
template<class T> using PQ_min = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = (1 << 30) - 1;   

constexpr ll INF = (1LL << 62) - 1;  


    
    
    
    
    
    void view() {}
    void view(const int& a) { if (abs(a) == inf) { cerr << "+-"[signbit(a)] << "inf"; } else { cerr << a; } }
    void view(const ll& a) { if (abs(a) == INF) { cerr << "+-"[signbit(a)] << "INF"; } else { cerr << a; } }
    template<class T> void view(const T& a) { cerr << a; }
    template<class P1, class P2> void view(const pair<P1, P2>& a) { cerr << "("; view(a.first); cerr << ", "; view(a.second); cerr << ")"; }
    template<class T1, class T2, class T3> void view(const tuple<T1, T2, T3>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ")"; }
    template<class T1, class T2, class T3, class T4> void view(const tuple<T1, T2, T3, T4>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ", "; view(get<3>(a)); cerr << ")"; }
    template<class T> void view(const vector<T>& v){ cerr << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) { cerr << ", "; } view(v[i]); } cerr << "]"; }
    template<class T> void view(const vector<vector<T>>& vv){ cerr << "["; for (int i = 0; i < (int)vv.size(); i++) { if (i) { cerr << ", "; } view(vv[i]); } cerr << "]"; }
    template<class K, class V> void view(const map<K, V>& mp){ cerr << "["; for (auto it = mp.begin(); it != mp.end(); it++) { if (it != mp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class K, class V> void view(const multimap<K, V>& mmp){ cerr << "["; for (auto it = mmp.begin(); it != mmp.end(); it++) { if (it != mmp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class T> void view(const set<T>& s){ cerr << "["; for (auto it = s.begin(); it != s.end(); it++) { if (it != s.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const multiset<T>& ms){ cerr << "["; for (auto it = ms.begin(); it != ms.end(); it++) { if (it != ms.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const deque<T>& d){ cerr << "(front)<-["; for (auto it = d.begin(); it != d.end(); it++) { if (it != d.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(stack<T> s){ vector<T> v; while (not s.empty()) { v.push_back(s.top()); s.pop(); } reverse(v.begin(), v.end()); view(v); cerr << "->(top)"; }
    template<class T> void view(queue<T> q){ vector<T> v; while (not q.empty()) { v.push_back(q.front()); q.pop(); } cerr << "(front)<-"; view(v); }
    template<class T> void view(PQ_max<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void view(PQ_min<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void id0(const vector<vector<T>>& vv){ for (int i = 0; i < (int)vv.size(); i++) { cerr << "    "; view(vv[i]); cerr << ",\n"; } }
    template<class T> void id3(const vector<vector<vector<T>>>& vvv) { for (int i = 0; i < (int)vvv.size(); i++) { for (int j = 0; j < (int)vvv[i].size(); j++) { cerr << "    " << " ["[j == 0]; view(vvv[i][j]); if (j == (int)vvv[i].size() - 1) { cerr << "]"; } cerr << ",\n"; } if (i < (int)vvv.size() - 1) { cerr << "\n"; } } }
    template<class T, class... Ts> void view(const T& a, const Ts&... b) { view(a); cerr << ", "; view(b...); }

    
    
    
    
    

template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
template<class T> void print(const T& a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void cout_line(const vector<T>& ans, int l, int r) { for (int i = l; i < r; i++) { if (i != l) { cout << ' '; } cout << ans[i]; } cout << '\n'; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> T SUM(const vector<T>& A) { return accumulate(ALL(A), T(0)); }
template<class T> vector<T> cumsum(const vector<T>& A, bool offset = false) { int N = A.size(); vector<T> S(N+1, 0); for (int i = 0; i < N; i++) { S[i+1] = S[i] + A[i]; } if (not offset) { S.erase(S.begin()); } return S; }
template<class T> string to_binary(T x, int B) { string s; while (x) { s += ('0' + (x & 1)); x >>= 1; } while ((int)s.size() < B) { s += '0'; } reverse(s.begin(), s.end()); return s; }
ll min(int a, ll b) { return min((ll)a, b); }
ll min(ll a, int b) { return min(a, (ll)b); }
ll max(int a, ll b) { return max((ll)a, b); }
ll max(ll a, int b) { return max(a, (ll)b); }
ll mod(ll x, ll m) { assert(m != 0); return (x % m + m) % m; }
ll ceil(ll a, ll b) { if (b < 0) { return ceil(-a, -b); } assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
ll floor(ll a, ll b) { if (b < 0) { return floor(-a, -b); } assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
ll powint(ll x, ll n) { assert(n >= 0); if (n == 0) { return 1; }; ll res = powint(x, n>>1); res *= res; if (n & 1) { res *= x; } return res; }
pair<ll,ll> divmod(ll a, ll b) { assert(b != 0); ll q = floor(a, b); return make_pair(q, a - q * b); }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
ll digit_len(ll n) { assert(n >= 0); if (n == 0) { return 1; } ll sum = 0; while (n > 0) { sum++; n /= 10; } return sum; }
ll digit_sum(ll n) { assert(n >= 0); ll sum = 0; while (n > 0) { sum += n % 10; n /= 10; } return sum; }
ll digit_prod(ll n) { assert(n >= 0); if (n == 0) { return 0; } ll prod = 1; while (n > 0) { prod *= n % 10; n /= 10; } return prod; }
ll xor_sum(ll x) { assert(0 <= x); switch (x % 4) { case 0: return x; case 1: return 1; case 2: return x ^ 1; case 3: return 0; } assert(false); }
string toupper(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = toupper(T[i]); } return T; }
string tolower(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = tolower(T[i]); } return T; }
int id9(const char& c) { assert(islower(c)); return (c - 'a'); }
int id5(const char& c) { assert(isupper(c)); return (c - 'A'); }
int id12(const char& d) { assert(isdigit(d)); return (d - '0'); }
char id11(const int& i) { assert(0 <= i && i < 26); return ('a' + i); }
char id6(const int& i) { assert(0 <= i && i < 26); return ('A' + i); }
char id8(const int& i) { assert(0 <= i && i <= 9); return ('0' + i); }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
const ld EPS = 1e-10;
const ld PI  = acosl(-1.0);













namespace atcoder {

namespace internal {

int id1(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int id2(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  



namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id10 {
  public:
    id10() : id10(0) {}
    explicit id10(int n) : id10(std::vector<S>(n, e())) {}
    explicit id10(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id1(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  


using namespace atcoder;



using Mono = int;
using Func = int;
Mono op(Mono a, Mono b) { return min(a, b); }
Mono e() { return inf; }
Mono mapping(Func f, Mono a) { return a + f; }
Func composition(Func f, Func g) { return f + g; }
Func id() { return 0; }


template<class T = ll>
vector<T> compress(vector<T>& X) {
    int N = X.size();
    vector<T> XS(X);  


    

    sort(XS.begin(), XS.end());
    XS.erase(unique(XS.begin(), XS.end()), XS.end());

    

    for (int i = 0; i < N; i++) {
        X[i] = lower_bound(XS.begin(), XS.end(), X[i]) - XS.begin();
    }
    return XS;
}











namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  



namespace atcoder {

template <class T> struct id7 {
    using U = internal::to_unsigned_t<T>;

  public:
    id7() : _n(0) {}
    explicit id7(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  


using namespace atcoder;


template<class T = ll>
ll id4(vector<T> A) {
    int N = A.size();

    

    vector<T> X(A);
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
    }

    

    id7<int> fw(N);
    ll res = 0;
    for (int i = 0; i < N; i++) {
        res += fw.sum(A[i] + 1, N);
        fw.add(A[i], 1);
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int tt; cin >> tt;
    while (tt--) {
        int N, M; input(N, M);
        VI A(N); REP(i,N) { input(A[i]); }
        VI B(M); REP(i,M) { input(B[i]); }

        VI C(N+M);
        REP(i,N) C[i] = A[i];
        REP(j,M) C[j+N] = B[j];
        auto ZC = compress(C);
        REP(i,N) A[i] = C[i];
        REP(j,M) B[j] = C[j+N];
        int K = SZ(ZC);

        vector<Mono> seg_init(N + 1, 0);
        id10<Mono, op, e, Func, mapping, composition, id> seg(seg_init);
        REP(i,N) seg.apply(i + 1, N + 1, 1);

        VVI query(K); REP(i,N) query[A[i]].push_back(i);
        VLL cnt(K);   REP(j,M) cnt[B[j]]++;

        ll ans = id4(A);
        REP(k,K) {
            for (const auto& i : query[k]) { seg.apply(i + 1, N + 1, -1); }
            ans += seg.all_prod() * cnt[k];
            for (const auto& i : query[k]) { seg.apply(0, i + 1, 1); }
        }
        print(ans);
    }

    return 0;
}