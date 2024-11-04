
#include <cstdio>
#include <cmath>
#include <climits>      

#include <cfloat>       

#include <cstring>      

#include <cstdlib>      

#include <cstdint>      

#include <cinttypes>    

#include <ctime>        

#include <cassert>      

#include <limits>       

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>        

#include <iostream>     

                        

                        

#include <sstream>
#include <algorithm>
using namespace std;    

#ifdef LOCAL_JUDGE
#  define pr_debug(...) fprintf(stderr, __VA_ARGS__)
#  define pr_line() fprintf(stderr, "%s: %d\n", __FILE__, __LINE__)
#else
#  define pr_debug(...)
#  define pr_line()
#endif
template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
static const int HMAX32 = INT32_MAX / 2;
static const int HMIN32 = -HMAX32;
static const int64_t HMAX64 = INT64_MAX / 2;
static const int64_t HMIN64 = -HMAX64;
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
#define read_int(id) scanf("%d", &id)
#define read_int64(id) scanf("%" PRId64, &id)
#define new_int(id) int id; read_int(id)
#define new_int64(id) int64_t id; read_int64(id)
#define ALL(x) begin(x), end(x)
#define FOR0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define FOR1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define FOR(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define FOD0(i,n) for(int i=(n)-1;~i;i--)
#define FOD1(i,n) for(int i=n;i;i--)
#define FOD(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define FORE(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)
#include <utility>


static inline unsigned all_ones(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x;
}
static inline int floor_log2(unsigned x) {
    int ans = 0;
    while (x >>= 1)
	++ans;
    return ans;
}
static inline bool is_pow2(unsigned x) {
    return !(x & (x - 1));
}
static inline unsigned next_pow2(unsigned x) {
    return all_ones(x) + 1;
}
static inline unsigned ceil_pow2(unsigned x) {
    if (is_pow2(x)) return x;
    return next_pow2(x);
}


static inline int msb32(unsigned int x) {
    x = all_ones(x);
    return x & ~(x >> 1);
}
static inline int lsb32(unsigned int x) {
    return x & -x;
}
#include <type_traits>




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
Int extended_gcd(Int a, Int b, XInt &x, XInt &y) {
    static_assert(std::numeric_limits<XInt>::is_signed,
            "x, y must be signed");
    

    

    

    

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    Int g = extended_gcd(b, a % b, y, x);
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
    extended_gcd(a, m, x, y);
    if (x < 0)
        return x + m;
    return x;
}
template <typename Int>
Int addx_mod(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int subx_mod(Int u, Int v, Int m) {
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
Int div_pos_r(Int a, Int b, Int &r) {
    

    

    

    

    

    

    

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




#define INV_MOD(x)      inv_mod((x), MOD)
#define MUL_MOD(x, y)   mul_mod((x), (y), MOD)
#define MULM_MOD(x, y)  (x) = mul_mod((x), (y), MOD)
#define POW_MOD(x, y)   pow_mod((x), (y), MOD)
#define ADDX_MOD(x, y)  addx_mod((x), (y), MOD)
#define ADDM_MOD(x, y)  (x) = addx_mod((x), (y), MOD)
#define SUBX_MOD(x, y)  subx_mod((x), (y), MOD)
#define SUBM_MOD(x, y)  (x) = subx_mod((x), (y), MOD)
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
struct lazy_segtree {
    

    

    

    

    Op op;
    std::vector<T> vec;
    std::vector<F> lazy;
    int offset;
    int size; 
    lazy_segtree(int n) {
        size = n;
        offset = ceil_pow2(n);
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
lazy_segtree<int, binary_max<int>, add_f> seg(maxn); 

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
