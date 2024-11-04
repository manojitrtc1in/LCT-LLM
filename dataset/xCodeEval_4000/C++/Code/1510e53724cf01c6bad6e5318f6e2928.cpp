


#include <bits/stdc++.h>
using pii=std::pair<int,int>;
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}


pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { 

    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<long long> trial_division2(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int fermat(int n) {
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = round(sqrt(b2));
    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = round(sqrt(b2));
    }
    return a - b;
}



long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

long long rho(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

int solve(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * 1ll * an) % m;
    }

    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * 1ll * a) % m;
    }
    return -1;
}

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}







template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        

        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const { return val; }
    explicit operator int64_t() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        

        

        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const _m_int &other) const { return val == other.val; }
    bool operator!=(const _m_int &other) const { return val != other.val; }
 
    _m_int inv() const {
        return mod_inv(val);
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
extern const int MOD = 2130706433;
using mod_int = _m_int<MOD>;
 
int tasdf, a, b;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tasdf;
    for(int cases = 0; cases < tasdf; cases++)
    {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}
 
template<const int &MOD>
struct NTT {
    using ntt_int = _m_int<MOD>;
 
    vector<ntt_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ntt_int root;
 
    void reset() {
        roots = {0, 1};
        max_size = -1;
    }
 
    static bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    static int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    

    static int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    

    

    void bit_reorder(int n, vector<ntt_int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 1; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) | ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        

        while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        

        

        while (1 << length < n) {
            

            ntt_int z = root.pow(max_size >> (length + 1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<ntt_int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    ntt_int even = values[start + i];
                    ntt_int odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }
 
    void invert_fft(int N, vector<ntt_int> &values) {
        ntt_int inv_N = ntt_int(N).inv();
 
        for (int i = 0; i < N; i++)
            values[i] *= inv_N;
 
        reverse(values.begin() + 1, values.end());
        fft_iterative(N, values);
    }
 
    const int FFT_CUTOFF = 150;
 
    

    

    template<typename T>
    vector<T> mod_multiply(const vector<T> &_left, const vector<T> &_right, bool circular = false) {
        if (_left.empty() || _right.empty())
            return {};
 
        vector<ntt_int> left(_left.begin(), _left.end());
        vector<ntt_int> right(_right.begin(), _right.end());
 
        int n = left.size();
        int m = right.size();
 
        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;
 
        

        if (min(n, m) < FFT_CUTOFF) {
            auto &&mod_output_size = [&](int x) {
                return x < output_size ? x : x - output_size;
            };
 
            static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(output_size, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = mod_output_size(i + j);
                    result[index] += (uint64_t) (int64_t) left[i] * (int64_t) right[j];
 
                    if (result[index] > U64_BOUND)
                        result[index] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<T>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(output_size);
        left.resize(N, 0);
        right.resize(N, 0);
 
        if (left == right) {
            fft_iterative(N, left);
            right = left;
        } else {
            fft_iterative(N, left);
            fft_iterative(N, right);
        }
 
        for (int i = 0; i < N; i++)
            left[i] *= right[i];
 
        invert_fft(N, left);
        return vector<T>(left.begin(), left.begin() + output_size);
    }
 
    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent) {
        assert(exponent >= 0);
        vector<T> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
 
    template<typename T>
    vector<T> mod_multiply_all(const vector<vector<T>> &polynomials) {
        if (polynomials.empty())
            return {1};
 
        struct compare_size {
            bool operator()(const vector<T> &x, const vector<T> &y) {
                return x.size() > y.size();
            }
        };
 
        priority_queue<vector<T>, vector<vector<T>>, compare_size> pq(polynomials.begin(), polynomials.end());
 
        while (pq.size() > 1) {
            vector<T> a = pq.top(); pq.pop();
            vector<T> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }
 
        return pq.top();
    }
};

NTT<MOD> ntt;




int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

struct item {
    int key, prior;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

void erase (pitem & t, int key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

struct SqrtTreeItem {};

SqrtTreeItem op(const SqrtTreeItem &a, const SqrtTreeItem &b);

inline int log2Up(int n) {
    int res = 0;
    while ((1 << res) < n) {
        res++;
    }
    return res;
}

class SqrtTree {
private:
    int n, lg, indexSz;
    vector<SqrtTreeItem> v;
    vector<int> clz, layers, onLayer;
    vector< vector<SqrtTreeItem> > pref, suf, between;

    inline void buildBlock(int layer, int l, int r) {
        pref[layer][l] = v[l];
        for (int i = l+1; i < r; i++) {
            pref[layer][i] = op(pref[layer][i-1], v[i]);
        }
        suf[layer][r-1] = v[r-1];
        for (int i = r-2; i >= l; i--) {
            suf[layer][i] = op(v[i], suf[layer][i+1]);
        }
    }

    inline void buildBetween(int layer, int lBound, int rBound, int betweenOffs) {
        int bSzLog = (layers[layer]+1) >> 1;
        int bCntLog = layers[layer] >> 1;
        int bSz = 1 << bSzLog;
        int bCnt = (rBound - lBound + bSz - 1) >> bSzLog;
        for (int i = 0; i < bCnt; i++) {
            SqrtTreeItem ans;
            for (int j = i; j < bCnt; j++) {
                SqrtTreeItem add = suf[layer][lBound + (j << bSzLog)];
                ans = (i == j) ? add : op(ans, add);
                between[layer-1][betweenOffs + lBound + (i << bCntLog) + j] = ans;
            }
        }
    }

    inline void buildBetweenZero() {
        int bSzLog = (lg+1) >> 1;
        for (int i = 0; i < indexSz; i++) {
            v[n+i] = suf[0][i << bSzLog];
        }
        build(1, n, n + indexSz, (1 << lg) - n);
    }

    inline void updateBetweenZero(int bid) {
        int bSzLog = (lg+1) >> 1;
        v[n+bid] = suf[0][bid << bSzLog];
        update(1, n, n + indexSz, (1 << lg) - n, n+bid);
    }

    void build(int layer, int lBound, int rBound, int betweenOffs) {
        if (layer >= (int)layers.size()) {
            return;
        }
        int bSz = 1 << ((layers[layer]+1) >> 1);
        for (int l = lBound; l < rBound; l += bSz) {
            int r = min(l + bSz, rBound);
            buildBlock(layer, l, r);
            build(layer+1, l, r, betweenOffs);
        }
        if (layer == 0) {
            buildBetweenZero();
        } else {
            buildBetween(layer, lBound, rBound, betweenOffs);
        }
    }

    void update(int layer, int lBound, int rBound, int betweenOffs, int x) {
        if (layer >= (int)layers.size()) {
            return;
        }
        int bSzLog = (layers[layer]+1) >> 1;
        int bSz = 1 << bSzLog;
        int blockIdx = (x - lBound) >> bSzLog;
        int l = lBound + (blockIdx << bSzLog);
        int r = min(l + bSz, rBound);
        buildBlock(layer, l, r);
        if (layer == 0) {
            updateBetweenZero(blockIdx);
        } else {
            buildBetween(layer, lBound, rBound, betweenOffs);
        }
        update(layer+1, l, r, betweenOffs, x);
    }

    inline SqrtTreeItem query(int l, int r, int betweenOffs, int base) {
        if (l == r) {
            return v[l];
        }
        if (l + 1 == r) {
            return op(v[l], v[r]);
        }
        int layer = onLayer[clz[(l - base) ^ (r - base)]];
        int bSzLog = (layers[layer]+1) >> 1;
        int bCntLog = layers[layer] >> 1;
        int lBound = (((l - base) >> layers[layer]) << layers[layer]) + base;
        int lBlock = ((l - lBound) >> bSzLog) + 1;
        int rBlock = ((r - lBound) >> bSzLog) - 1;
        SqrtTreeItem ans = suf[layer][l];
        if (lBlock <= rBlock) {
            SqrtTreeItem add = (layer == 0) ? (
                query(n + lBlock, n + rBlock, (1 << lg) - n, n)
            ) : (
                between[layer-1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]
            );
            ans = op(ans, add);
        }
        ans = op(ans, pref[layer][r]);
        return ans;
    }
public:
    inline SqrtTreeItem query(int l, int r) {
        return query(l, r, 0, 0);
    }

    inline void update(int x, const SqrtTreeItem &item) {
        v[x] = item;
        update(0, 0, n, 0, x);
    }

    SqrtTree(const vector<SqrtTreeItem>& a)
        : n((int)a.size()), lg(log2Up(n)), v(a), clz(1 << lg), onLayer(lg+1) {
        clz[0] = 0;
        for (int i = 1; i < (int)clz.size(); i++) {
            clz[i] = clz[i >> 1] + 1;
        }
        int tlg = lg;
        while (tlg > 1) {
            onLayer[tlg] = (int)layers.size();
            layers.push_back(tlg);
            tlg = (tlg+1) >> 1;
        }
        for (int i = lg-1; i >= 0; i--) {
            onLayer[i] = max(onLayer[i], onLayer[i+1]);
        }
        int betweenLayers = max(0, (int)layers.size() - 1);
        int bSzLog = (lg+1) >> 1;
        int bSz = 1 << bSzLog;
        indexSz = (n + bSz - 1) >> bSzLog;
        v.resize(n + indexSz);
        pref.assign(layers.size(), vector<SqrtTreeItem>(n + indexSz));
        suf.assign(layers.size(), vector<SqrtTreeItem>(n + indexSz));
        between.assign(betweenLayers, vector<SqrtTreeItem>((1 << lg) + bSz));
        build(0, 0, n, 0);
    }
};

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

float InvSqrt (float x){
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    return x;
}

