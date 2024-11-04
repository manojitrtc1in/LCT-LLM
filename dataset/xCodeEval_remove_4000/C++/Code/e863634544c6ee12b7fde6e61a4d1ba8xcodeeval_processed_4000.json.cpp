





















using namespace std;
typedef long long ll;












template<class T> 
inline void debug_v(const vector<T> &vec) {
    printf("vec: ");
    for (auto u : vec) cout << u << " ";
    cout << endl;
}

template<class T>
inline int cntOne(const T x) {
    bitset<64> res(x);
    return res.count();
}

inline ll qpow(ll a, int n) {
    ll ans = 1;
    for(; n; n >>= 1) {
        if(n & 1) ans *= 1ll * a;
        a *= a;
    }
    return ans;
}

template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll ksc(ll a, ll b, ll mod) {
    ll ans = 0;
    for(; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a * 2) % mod;
    }
    return ans;
}

ll ksm(ll a, ll b, ll mod) {
    ll ans = 1 % mod;
    a %= mod;

    for(; b; b >>= 1) {
        if (b & 1) ans = ksc(ans, a, mod);
        a = ksc(a, a, mod);
    }

    return ans;
}

template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool id2(vector<T> a, vector<T> b) {
    int n = a.size(), m = b.size();
    int i;
    for(i = 0; i < n && i < m; i++) {
        if (a[i] < b[i]) return true;
        else if (b[i] < a[i]) return false;
    }
    return (i == n && i < m);
}

constexpr int P = 1e9 + 7;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res *= a;
        a *= a;
    }
    return res;
}

struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}

    int val() const {
        return x;
    }
    mint operator-() const {
        return mint(norm(P-x));
    }
    mint &operator *= (const mint &rhs) {
        x = (ll)(x) * rhs.x % P;
        return *this;
    }
    mint &operator += (const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator -= (const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
    }
    mint inv() const {
        assert(x != 0);
        return power(*this, P-2);
    }
    friend mint operator* (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+ (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator- (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/ (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
};

struct Int {
    static constexpr int B = 10;
    vector<int> X;
    int size() const {
        return (int)X.size();
    }

    Int(int x = 0) {
        while (x) {
            X.push_back(x % B), x /= B;
        }
    }

    Int(string str) {
        reverse(str.begin(), str.end());
        for (auto u : str) X.push_back(u-'0');
    }

    friend Int operator+ (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return rhs + lhs;
        Int res;

        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t += lhs.X[i];
            if (i < rhs.size()) t += rhs.X[i];
            res.X.push_back(t % B), t /= B;
        }
        if (t) res.X.push_back(t);
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator- (const Int &lhs, const Int &rhs) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t = lhs.X[i] - t;
            if (i < rhs.size()) t -= rhs.X[i];
            res.X.push_back((t + B) % B);

            if (t < 0) t = 1;
            else t = 0;
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, int b) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.X.size() || t; i++) {
            if (i < lhs.X.size()) t += lhs.X[i] * b;
            res.X.push_back(t % B), t /= B;
        }
        return res;
    }

    friend Int operator/ (const Int &lhs, int b) {
        Int res;
        int r = 0;
        for (int i = lhs.X.size()-1; i >= 0; i--) {
            r = r * B + lhs.X[i];
            res.X.push_back(r / b), r %= b;
        }
        reverse(res.X.begin(), res.X.end());
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, const Int &rhs) {
        Int res;
        res.X.resize(lhs.size() + rhs.size() + B);
        fill(res.X.begin(), res.X.end(), 0);

        for (int i = 0; i < lhs.size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                res.X[i+j] += lhs.X[i] * rhs.X[j];
            }
        }
        for (int i = 0; i < res.X.size(); i++) {
            if (res.X[i] >= B) res.X[i+1] += res.X[i] / B, res.X[i] %= B;
        }

        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator/ (const Int& lhs, const Int &rhs) {
        int dv = lhs.size() - rhs.size();
        assert(dv >= 0);

        Int res;
        res.X.resize(dv+1);
        fill(res.X.begin(), res.X.end(), 0);

        

        Int a = lhs, b = rhs;
        reverse(b.X.begin(), b.X.end());
        for (int i = 0; i < dv; i++) b.X.push_back(0);
        reverse(b.X.begin(), b.X.end());

        for (int i = 0; i <= dv; i++) {
            while (b < a) {
                a = a-b;
                res.X[dv-i]++;
            }
            b.X.erase(b.X.begin());
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend bool operator< (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return true;
        if (lhs.size() > rhs.size()) return false;

        if (vector<int>(lhs.X.rbegin(), lhs.X.rend()) <= vector<int>(rhs.X.rbegin(), rhs.X.rend())) return true;
        return false;
    }
    void out() {
        if (X.size() == 0) {
            puts("0");
            return;
        }
        reverse(X.begin(), X.end());
        for (auto x : X) printf("%d", x);
        printf("\n");
    }
};

Int max_int(const Int &A, const Int &B) {
    if (A < B) return B;
    else return A;
}

int get_root(int P) {
    function<vector<int>(int x)> divide = [&](int x) {
        vector<int> primes;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i) continue;

            primes.push_back(i);
            while (x % i == 0) x /= i;
        }
        if (x > 1) primes.push_back(x);

        return primes;
    };

    vector<int> pr = divide(P-1);

    for (ll g = 2; g <= P-1; g++) {
        bool ok = true;
        
        for (auto p : pr) {
            if (ksm(g, (1LL * P-1)/p, P) == 1) {
                ok = false; break;
            }
        }

        if (ok) return g;
    }
    return -1;
}

namespace NTT {
    const int G = 3;

    vector<int> rev;
    void ntt(vector<mint> &a, int op) {
        int n = a.size();

        if ((int)rev.size() != n) {
            rev.resize(n);
            

            


            for (int i = 0; i < n; i++) {
                

            }
        }

        for (int i = 0; i < n; i++) {
            if (rev[i] < i) swap(a[i], a[rev[i]]);
        }

        

        for (int mid = 1; mid < n; mid <<= 1) {
            mint gn = power(mint(G), (P - 1) / (mid << 1));
            if (op == -1) gn = gn.inv();

            for (int i = 0; i < n; i += mid * 2) {
                mint gnk = 1;

                for (int j = 0; j < mid; j++) {
                    mint u = a[i+j], v = gnk * a[i+mid+j];
                    a[i+j] = u + v, a[i+mid+j] = u - v;
                    gnk = gnk * gn;
                }
            }
        }

        if (op == -1) {
            mint inv = mint((int)a.size()).inv();
            for (int i = 0; i < n; i++) {
                a[i] *= inv;
            }
        }
    }

    void dft(vector<mint> &a) {
        ntt(a, 1);
    }

    void idft(vector<mint> &a) {
        ntt(a, -1);
    }
};

struct Poly {
    vector<mint> a;
    Poly() {}
    Poly(const vector<mint> &a) : a(a) {}
    Poly(const initializer_list<mint> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }

    mint operator[] (int idx) const {
        if (idx < 0 || idx >= size()) {
            return 0;
        }
        return a[idx];
    }
    mint& operator[] (int idx) {
        return a[idx];
    }

    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = min(k, size());
        return Poly(vector<mint>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(vector<mint>(a.begin() + k, a.end()));
    }

    friend Poly operator+ (const Poly &a, const Poly &b) {
        vector<mint> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)res.size(); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }

    friend Poly operator- (const Poly &a, const Poly &b) {
        vector<mint> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)res.size(); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }

    friend Poly operator* (Poly a, Poly b) {
        using namespace NTT;

        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }

        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) sz *= 2;

        a.a.resize(sz), b.a.resize(sz);
        dft(a.a), dft(b.a);

        for (int i = 0; i < sz; i++) {
            a.a[i] = a[i] * b[i];
        }

        idft(a.a);
        a.resize(tot);
        return a;
    }

    friend Poly operator* (Poly a, mint b) {
        for (int i = 0; i < (int)a.size(); i++) {
            a[i] *= b;
        }
        return a;
    }

    friend Poly operator* (mint a, Poly b) {
        for (int i = 0; i < (int)b.size(); i++) {
            b[i] *= a;
        }
        return b;
    }

    Poly &operator+= (Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-= (Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*= (Poly b) {
        return (*this) = (*this) * b;
    }

    Poly deriv() const {
        if (a.empty()) return Poly();

        vector<mint> res(size() - 1);
        for (int i = 0; i < size()-1; i++) {
            res[i] = (i + 1) * a[i + 1];
        }

        return Poly(res);
    }

    Poly integr() const {
        vector<mint> res(size() + 1);
        for (int i = 0; i < size(); i++) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
};



mt19937_64 mrand(random_device{}());
int rnd(int x) {
    return mrand() % x;
}



namespace internal {





int id0(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}




















int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

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
struct id1 {
  public:
    id1() : id1(0) {}
    explicit id1(int n) : id1(std::vector<S>(n, e())) {}
    explicit id1(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id0(_n);
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

typedef array<int, 3> Arr;

struct S {
    ll sum;
    int len;
};

S e() {
    return S{0, 1};
}

S op(S a, S b) {
    return S{a.sum+b.sum, a.len+b.len};
}

S mapping(ll f, S x) {
    return S{ x.sum + f * 1LL * x.len , x.len };
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0LL;
}


int main() {
    

    int cas;
    cin >> cas;
    while (cas--) {
        int n;
        cin >> n;

        vector<vector<Arr> > col(n+1);

        map<int, int> mp, rm;
        int idx = 0;

        int maxr = 0, minl = 1e9;
        for (int i = 0; i < n; i++) {
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            col[c].push_back({l, r, i});
            mp[l] = mp[r] = 0;
        }

        for (auto &x : mp) x.second = idx, rm[idx++] = x.first;
        

        id1<S, op, e, ll, mapping, composition, id> tr(idx);
        multiset<ll> L, R;
        for (auto c : col) {
            for (auto [l, r, id] : c) {
                int _l = mp[l], _r = mp[r];
                tr.apply(_l, _r+1, 1LL);
                L.insert(l), R.insert(r);
            }
        }

        vector<ll> ans(n, 0);
        for (auto c : col) {
            for (auto [l, r, id] : c) {
                int _l = mp[l], _r = mp[r];
                tr.apply(_l, _r+1, -1LL);
                

                L.erase(L.find(l)), R.erase(R.find(r));
            }

            for (auto [l, r, id] : c) {
                int _l = mp[l], _r = mp[r];
                auto node = tr.prod(_l, _r+1);
                if (node.sum > 0) ans[id] = 0;
                else {
                    auto it1 = L.upper_bound(r);
                    auto it2 = R.lower_bound(l);

                    ll res = 1e18;
                    if (it1 != L.end()) chmin(res, llabs(*it1 - r));
                    if (it2 != R.begin()) it2--, chmin(res, llabs(*it2 - l));

                    if (res == 1e18) continue;
                    else ans[id] = res;
                }
            }

            for (auto [l, r, id] : c) {
                int _l = mp[l], _r = mp[r];
                tr.apply(_l, _r+1, 1LL);
                L.insert(l), R.insert(r);
            }
        }

        for (auto x : ans) printf("%lld ", x);
        printf("\n");
    }
}