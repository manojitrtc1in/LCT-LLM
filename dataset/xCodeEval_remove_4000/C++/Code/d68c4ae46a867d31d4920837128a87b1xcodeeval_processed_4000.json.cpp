




























                        

                        



using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
static const int id10 = INT32_MAX / 2;
static const int id5 = -id10;
static const int64_t id11 = INT64_MAX / 2;
static const int64_t id7 = -id11;
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }















static inline unsigned id13(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x;
}
static inline int id3(unsigned x) {
    int ans = 0;
    while (x >>= 1)
	++ans;
    return ans;
}
static inline bool id4(unsigned x) {
    return !(x & (x - 1));
}
static inline unsigned id0(unsigned x) {
    return id13(x) + 1;
}
static inline unsigned id8(unsigned x) {
    if (id4(x)) return x;
    return id0(x);
}


static inline int id15(unsigned int x) {
    x = id13(x);
    return x & ~(x >> 1);
}
static inline int id12(unsigned int x) {
    return x & -x;
}





template <typename Int>
Int gcd(Int a, Int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}
template <typename Int, typename RInt = Int>
Int lcm(Int a, Int b) {
    return a / gcd(a, b) * static_cast<RInt>(b);
}
template <typename Int, typename XInt>
Int id2(Int a, Int b, XInt &x, XInt &y) {
    static_assert(std::numeric_limits<XInt>::is_signed,
            "x, y must be signed");
    

    

    

    

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    Int g = id2(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
template <typename Int, typename TInt = int64_t>
Int mul_mod(Int a, Int b, Int m) {
    TInt p = a;
    p = (p * b) % m;
    return (Int)p;
}
template <typename Int, typename PInt, typename TInt = int64_t>
Int pow_mod(Int a, PInt p, Int m) {
    Int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}
template <typename Int,
          typename XInt = typename std::make_signed<Int>::type>
Int inv_mod(Int a, Int m) {
    

    XInt x, y;
    id2(a, m, x, y);
    if (x < 0)
        return x + m;
    return x;
}
template <typename Int>
Int id14(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id6(Int u, Int v, Int m) {
    Int r = u - v;
    if (r < 0) r += m;
    return r;
}
template <typename Int>
Int div_mod(Int u, Int v, Int m) {
    

    

    

    

    

    

    

    

    

    Int g = gcd(v, m);
    assert(u % g == 0);
    Int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}
template <typename Int>
Int id1(Int a, Int b, Int &r) {
    

    

    

    

    

    

    

    Int q = a / b;
    r = a % b;
    if (r < 0) {
        if (b < 0)
            q += 1, r -= b;
        else
            q -= 1, r += b;
    }
    return q;
}












template <typename T>
struct binary_plus {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 + t2; }
    T negate(const T &t) { return -t; }
};
template <typename T, T MOD>
struct modular_plus {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return (t1 + t2) % MOD; }
    T negate(const T &t) { return (MOD - t) % MOD; }
};
template <typename T, T MOD, typename TT = int64_t>
struct modular_times {
    T identity() const { return 1; }
    T operator()(const T &t1, const T &t2) const { return mul_mod(t1, t2, MOD); }
    T negate(const T &t) { return inv_mod(t, MOD); }
};
template <typename T>
struct binary_xor {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 ^ t2; }
    T negate(const T &t) { return t; }
};
template <typename T>
struct binary_max {
    T identity() const { return std::numeric_limits<T>::min(); }
    T operator()(const T &t1, const T &t2) const { return std::max(t1, t2); }
};
template <typename T>
struct binary_min {
    T identity() const { return std::numeric_limits<T>::max(); }
    T operator()(const T &t1, const T &t2) const { return std::min(t1, t2); }
};






















template <typename T, typename Op, typename F>
struct id9 {
    

    

    

    

    Op op;
    std::vector<T> vec;
    std::vector<F> lazy;
    int offset;
    int size; 
    id9(int n) {
        size = n;
        offset = id8(n);
        vec.resize(offset + size + 1, op.identity()); 
        lazy.resize(offset);
    }
    void update_range(int b, int e, const F &f) {
        if (b >= e) return; 

        return update_range_helper(1, 0, offset, b, e, f);
    }
    T query_range(int b, int e) {
        if (b >= e) return op.identity(); 

        return query_range_helper(1, 0, offset, b, e);
    }
    void rebuild() {
        for (int i = (offset + size - 1) / 2; i > 0; --i)
            vec[i] = op(vec[i + i], vec[i + i + 1]);
    }
    T &operator[](int p) {
        return vec[offset + p];
    }
private:
    void apply(int no, int len, const F &f) {
        vec[no] = f(vec[no], len);
        if (no < offset) lazy[no] = f * lazy[no];
    }
    

    

    void update_range_helper(int no, int left, int right, int b, int e, const F &f) {
        int len = right - left;
        

        if (left >= b && right <= e)
            apply(no, len, f);
        

        else {
            if (lazy[no]) {
                apply(no + no, len / 2, lazy[no]);
                apply(no + no + 1, len / 2, lazy[no]);
                lazy[no] = F();
            }
            int mid = left + len / 2;
            if (b < mid) update_range_helper(no + no, left, mid, b, e, f);
            if (e > mid) update_range_helper(no + no + 1, mid, right, b, e, f);
            

            vec[no] = op(vec[no + no], vec[no + no + 1]);
        }
    }
    T query_range_helper(int no, int left, int right, int b, int e) {
        int len = right - left;
        

        if (left >= b && right <= e)
            return vec[no];
        

        else {
            if (lazy[no]) {
                apply(no + no, len / 2, lazy[no]);
                apply(no + no + 1, len / 2, lazy[no]);
                lazy[no] = F();
            }
            int mid = left + len / 2;
            T v1 = op.identity(), v2 = op.identity();
            if (b < mid) v1 = query_range_helper(no + no, left, mid, b, e);
            if (e > mid) v2 = query_range_helper(no + no + 1, mid, right, b, e);
            return op(v1, v2);
        }
    }
};



















































static const int maxn = 35005;
int dp[55][maxn];
struct add_f {
    int x;
    add_f() : x(0) { }
    add_f(int x) : x(x) { }
    int operator()(int v, int len) const {
        return x + v;
    }
    operator bool() {
        return x;
    }
    add_f operator*(const add_f &that) const {
        return add_f(x + that.x);
    }
};
id9<int, binary_max<int>, add_f> seg(maxn); 

int arr[maxn];
int visit[maxn];
int pre[maxn];
int main() {
    int n, k;
    cin >> n >> k;
    FOR1(i, n) {
        cin >> arr[i];
    }
    FOR1(p, k) {
        seg = decltype(seg)(maxn); 

        seg[0] = 0;
        FOR1(j, n)
            seg[j] = dp[p - 1][j];
        seg.rebuild();
        memset(pre, 0, sizeof(pre));
        FOR1(i, n) {
            int v = arr[i];
            seg.update_range(pre[v], i, add_f(1));
            pre[v] = i;
            chmax(dp[p][i], seg.query_range(0, i + 1));
            pr_debug("dp[%d][%d] = %d\n", p, i, dp[p][i]);
        }
    }
    

        

    cout << dp[k][n] << '\n';
    return 0;
}
