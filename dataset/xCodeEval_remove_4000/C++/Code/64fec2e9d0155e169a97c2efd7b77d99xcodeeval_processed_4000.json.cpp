const int mod = 998244353;









using namespace std;


template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
private:
    using ll = long long;

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

struct Modnum {
private:
    static int MOD; 

    using ll = long long;
    using modnum = Modnum;
    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    Modnum() : v(0) {}
    Modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    static void set_mod(const int &m) {
        assert(m > 0);
        MOD = m;
    }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return *this;
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
int Modnum::MOD = 1; 













template<typename A, typename B>
void Min(A &a, const B &b){
    if (b < a) a = b;
}
template<typename A, typename B>
void Max(A &a, const B &b){
    if (b > a) a = b;
}
int cas;

auto kase = []() {
    cout << "Case 

};

template<class Iterator>
std::reverse_iterator<Iterator> id0(Iterator it)
{
    return std::reverse_iterator<Iterator>(it);
}


template <typename iter_t>
struct iter_pair {
    iter_t _beg, _end;
    iter_t begin(){return _beg;}
    iter_t end(){return _end;}
};

template<class cont> iter_pair<reverse_iterator<decltype(begin(declval<cont>()))>>
reverse(cont &&r) {
    return {id0(end(r)), id0(begin(r))};
}

template<typename T> void dprintln(const T &t) { cout << t << endl; } 

template<typename T, typename ...Args> void dprintln(const T &t, const Args &...rest) { cout << t << ' '; dprintln(rest...); }
template<typename T> void println(const T &t) { cout << t << '\n'; }


template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }
template<typename T> void println(const vector<T>& vec) {
    for(const T& x: vec) {
        cout << x << ' ';
    }
    cout << endl;
}

template<typename T> void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t << ' '; print(rest...); }



template<class T> void scan(T &t) { cin >> t; }
template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
template <typename T> void read(vector<T> &vec) {for(auto &x: vec) cin >> x;}
using ull = unsigned long long;
using ll = long long;
using ul = unsigned long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int,int>;
using vb = vector<bool>;
using vpii = vector<pii>;
template <typename int_t>
inline int_t lowbit(int_t x) {return x & -x;}
















template <typename T, typename Comp = less<T>>
using pq = priority_queue<T, vector<T>, Comp>;










const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
auto bet = [](const ll x, const ll y, const ll i) {
    return x <= i && i <= y;
};

template<typename T1, typename T2>
T1 ceil(T1 x, T2 y) { 

    return (x + y - 1) / y;
}


inline int h_bit(unsigned long long x) {
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(x);
}

int pow2(int x){ 

    return 1 << (h_bit((ull)x) + (x != lowbit(x)));
}



template <typename T>
struct bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    explicit bit(int n,
                 function<T(T,T)> bin_op,
                 T init):bin_op(bin_op) {
        a.resize((size_t)n + 1);
        for (int i = 1; i <= n; ++i) a[i] = init;
    }

    T prefix(T x, T init) {
        while (x) {
            init = bin_op(a[x], init);
            x -= x & -x;
        }
        return init;
    }

    T sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void modify(int x, T v) {
        while (x < a.size()) {
            a[x] = bin_op(a[x], v);
            x += x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), 0);
    }
};

template <typename T>
struct r_bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    explicit r_bit(int n,
                   function<T(T,T)> bin_op,
                   T init):bin_op(move(bin_op)) {
        a.resize((size_t) n + 1);
        for (int i = 1; i <= n; ++i) a[i] = init;
    }

    T suffix(int x, T init) {
        while (x < SZ(a)) {
            init = bin_op(init, a[x]);


            x += x & -x;
        }
        return init;
    }

    T sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void modify(int x, T v) {
        while (x > 0) {
            a[x] = bin_op(a[x], v);
            x -= x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), 0);
    }
};



vi get_prime(int n) {
    vi minp((ul)n + 1), p;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            p.pb(i);
        }
        FOR(x, p) {
            if (x <= minp[i] && x * i <= n)
                minp[x * i] = x;
            else break;
        }
    }
    return p;
}



template<typename T> using vv = vector<vector<T>>;
template <typename T1, typename T2 = T1> using vp = vector<pair<T1,T2>>;
template<typename T, int n> using va = vector<array<T,n>>;




template <typename T>
using rank_tree = __gnu_pbds::tree<
        T,
        __gnu_pbds::null_type,
        less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;




struct UF {
    vi par, sz;
    int n_tree;
    explicit UF(int n) { 

        par.assign(n, 0);
        sz.assign(n, 1);
        rng (i, 0, n) par[i] = i;
        n_tree = n;
    }
    int n_cluster() const {
        return n_tree;
    }
    int size(int x) {
        return sz[root(x)];
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if(rx != ry) {
            par[rx] = ry;
            --n_tree;
            sz[ry] += sz[rx];
            return true;
        }
        return false;
    }
};



using idx_t = long;
template <typename  T, typename Compare = std::less<T>>
struct ST{
    size_t n{}; 

    vv<T> a;
    ST()=default;
    template <typename ptr_t>
    ST(ptr_t beg, ptr_t end):n(end-beg){
        a.resize((size_t)h_bit(n)+1); 

        a[0].assign(beg, end);
        rng (i, 0, SZ(a)-1) {
            a[i+1].resize(n);
            rng(j, 0, n - (1 << i)) {
                a[i+1][j] = min(a[i][j], a[i][j+(1<<i)], Compare());
            }
            rng(j, n-(1 << i), n) {
                a[i+1][j] = a[i][j];
            }
        }
    }

    T query(idx_t l, idx_t r) { 

        int i = h_bit(r - l + 1ul);
        return min(a[i][l], a[i][r+1-(1<<i)], Compare());
    }
};

vi id1(int n) {
    vi res((ul)n + 1);
    rng (i, 0, n) {
        if (i * 2 <= n) res[i * 2] = res[i];
        if ((i & 1) == 0) res[i + 1] = res[i] + 1;
    }
    return res;
}

vi get_mu(int n) {
    assert(n > 0);
    vi mu(n + 1);
    vi min_p(n + 1);
    vi prime;
    mu[1] = 1;
    rng (i, 2, n + 1) {
        if (!min_p[i]) {
            prime.pb(i);
            min_p[i] = i;
            mu[i] = -1;
        }
        FOR (p, prime) {
            if (p > min_p[i]) {
                break;
            }
            int t = p * i;
            if (t > n) break;
            min_p[t] = p;
            mu[t] = p == min_p[i] ? 0 : -mu[i];
        }
    }
    return mu;
}

template <typename num>
num fp (num x, ll n) { 

    if(n < 0) {
        x = fp(x, mod - 2);
        n = -n;
    }
    num ans = 1;
    while(n){
        if(n&1) ans *= x;
        n /= 2;
        x *= x;
    }
    return ans;
}
template <typename num>
void id2(vector<num> &a) {
    int n = SZ(a);
    for (int i = 1, j = n >> 1, k; i < n - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        

        for (k = n >> 1; j >= k; j -= k, k >>= 1);    

        j += k;
    }
}
template <typename num>
void FFT(vector<num> &a, int type) {
    id2(a);
    int n = SZ(a);
    for (int i = 2; i <= n; i *= 2) {
        const auto wi = fp(3, type * (mod - 1) / i); 

        for (int j = 0; j < n; j += i) {
            num w(1);
            for (int k = j, h = i >> 1; k < j + h; k++) {
                auto t = w * a[k + h], u = a[k];
                a[k] = u + t;
                a[k + h] = u - t;
                w *= wi;
            }
        }
    }
    const auto inv = num(n).inv();
    if (type == -1) for (auto &x : a) x *= inv;
}
template <typename num>
void fp(vector<num> &a, const int n) {
    a.resize((ul)pow2((SZ(a)-1) * n + 1));
    FFT(a, 1);
    for(auto &x: a) x = fp(x, n);
    FFT(a, -1);
}


string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}












struct e{
    int u, v, t;
    void read(){
        scan(u, v, t);
    }
};

int main() {
    FAST_READ
    cout << fixed << setprecision(4);

    ifstream in("main.in");
    cin.rdbuf(in.rdbuf());






    int n; scan(n);
    using num = modnum<mod>;
    vi cnt(n + 1);
    vector<num> fact(n + 1); fact[0] = 1; rng (i, 1, n + 1) fact[i] = i * fact[i - 1];
    rep (n) {
        int x; scan(x); cnt[x]++;
    }

    AT(num, n + 1, n + 1, f);

    f[0][0] = 1; 

    rng (i, 0, n) {
        rng (j, 0, n) {
            if (f[i][j] != 0) {
                f[i][j+1] += f[i][j];
                if (cnt[j + 1]) f[i+1][j + 1] += f[i][j] *  cnt[j + 1];
            }
        }
    }

    num ans = 0;
    int tot = 0;
    up (i, 1, n) {
        if (cnt[i] >= 2) {
            up(len, 0, tot) {
                ans += f[len][i - 1] * cnt[i] * (cnt[i] - 1) * fact[n - len - 2];
            }
        }
        tot += bool(cnt[i]);
    }

    println(ans * fact[n].inv());



    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}