#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned int uint;
typedef size_t usize;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<typename T, usize n>
using arr = T (&)[n];

template<typename T, usize n>
using c_arr = const T (&)[n];

template<typename T>
T gcd(const T* a, const T* b) {
    T a_val = *a;
    T b_val = *b;
    if (a_val < 0) {
        return gcd(&(-a_val), b);
    } else if (b_val < 0) {
        return gcd(a, &(-b_val));
    } else if (a_val > b_val) {
        return gcd(b, a);
    } else if (a_val == 0) {
        return b_val;
    } else {
        return gcd(&b_val % a_val, a);
    }
}

template<typename T>
T lcm(const T* a, const T* b) {
    T a_val = *a;
    T b_val = *b;
    return a_val / gcd(a, b) * b_val;
}

template<typename T>
struct pair {
    T first;
    T second;
};

template<typename T>
pair<T> id1(const T* a, const T* b) {
    T a_val = *a;
    T b_val = *b;
    pair<T> result;
    if (b_val == 0) {
        result.first = 1;
        result.second = 0;
        return result;
    }
    T g = gcd(&b_val, &a_val);
    T da = abs(b_val) / g;
    pair<T> p = id1(&b_val, &(a_val % b_val));
    T x = (da + p.second % da) % da;
    T y = (g - a_val * x) / b_val;
    result.first = x;
    result.second = y;
    return result;
}

template<typename T>
T inverse(const T* a, const T* mod) {
    return id1(a, mod)->first;
}

template<uint mod_value, bool dynamic>
struct id5 {
    template<typename UInt>
    static const UInt mod() {
        return mod_ref();
    }

    template<typename UInt>
    static const UInt mod() {
        return mod_value;
    }

    template<typename UInt>
    static void set_mod(const UInt* mod) {
        mod_ref() = mod;
        inv_ref() = {1, 1};
    }

    uint v;

    id5() {
        v = 0;
    }

    id5(const ll* val) {
        v = norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())));
    }

    id5(const id5* n) {
        v = n->v;
    }

    bool operator!() {
        return !static_cast<bool>(*this);
    }

    id5* operator=(const id5* m) {
        v = m->v;
        return this;
    }

    id5* operator=(const ll* val) {
        v = norm(uint(val % static_cast<ll>(mod()) + static_cast<ll>(mod())));
        return this;
    }

    friend id5 operator+(const id5* m) {
        return *m;
    }

    friend id5 operator-(const id5* m) {
        return make(norm(mod() - m->v));
    }

    friend id5 operator+(const id5* m1, const id5* m2) {
        return make(norm(m1->v + m2->v));
    }

    friend id5 operator-(const id5* m1, const id5* m2) {
        return make(norm(m1->v + mod() - m2->v));
    }

    friend id5 operator*(const id5* m1, const id5* m2) {
        return make(static_cast<uint>(static_cast<ll>(m1->v) * static_cast<ll>(m2->v) % static_cast<ll>(mod())));
    }

    friend id5 operator/(const id5* m1, const id5* m2) {
        return m1 * inv(m2->v);
    }

    friend id5 operator+(const id5* m, const ll* val) {
        return id5{static_cast<ll>(m->v) + val};
    }

    friend id5 operator-(const id5* m, const ll* val) {
        return id5{static_cast<ll>(m->v) - val};
    }

    friend id5 operator*(const id5* m, const ll* val) {
        return id5{static_cast<ll>(m->v) * (val % static_cast<ll>(mod()))};
    }

    friend id5 operator/(const id5* m, const ll* val) {
        return id5{static_cast<ll>(m->v) * inv(val)};
    }

    friend id5 operator+(const ll* val, const id5* m) {
        return id5{static_cast<ll>(m->v) + val};
    }

    friend id5 operator-(const ll* val, const id5* m) {
        return id5{-static_cast<ll>(m->v) + val};
    }

    friend id5 operator*(const ll* val, const id5* m) {
        return id5{static_cast<ll>(m->v) * (val % static_cast<ll>(mod()))};
    }

    friend id5 operator/(const ll* val, const id5* m) {
        return id5{val * inv(static_cast<ll>(m->v))};
    }

    friend id5* operator+=(id5* m1, const id5* m2) {
        *m1 = *m1 + *m2;
        return m1;
    }

    friend id5* operator-=(id5* m1, const id5* m2) {
        *m1 = *m1 - *m2;
        return m1;
    }

    friend id5* operator*=(id5* m1, const id5* m2) {
        *m1 = *m1 * *m2;
        return m1;
    }

    friend id5* operator/=(id5* m1, const id5* m2) {
        *m1 = *m1 / *m2;
        return m1;
    }

    friend id5* operator+=(id5* m, const ll* val) {
        *m = *m + val;
        return m;
    }

    friend id5* operator-=(id5* m, const ll* val) {
        *m = *m - val;
        return m;
    }

    friend id5* operator*=(id5* m, const ll* val) {
        *m = *m * val;
        return m;
    }

    friend id5* operator/=(id5* m, const ll* val) {
        *m = *m / val;
        return m;
    }

    friend id5 operator^(const id5* m, const ll* n) {
        return power(m->v, n);
    }

    friend id5* operator^=(id5* m, const ll* n) {
        *m = *m ^ n;
        return m;
    }

    friend bool operator==(const id5* m1, const id5* m2) {
        return m1->v == m2->v;
    }

    friend bool operator!=(const id5* m1, const id5* m2) {
        return !(m1 == m2);
    }

    friend bool operator==(const id5* m, const ll* val) {
        return m->v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod())));
    }

    friend bool operator!=(const id5* m, const ll* val) {
        return !(m == val);
    }

    friend bool operator==(const ll* val, const id5* m) {
        return m->v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod())));
    }

    friend bool operator!=(const ll* val, const id5* m) {
        return !(m == val);
    }

    uint operator()() {
        return v;
    }

    static id5 small_inv(const usize* n) {
        auto& in = inv_ref();
        if (*n < in.size()) {
            return in[*n];
        }
        for (usize i = in.size(); i <= *n; i++) {
            in.push_back(-in[id5::mod() % i] * (id5::mod() / i));
        }
        return in.back();
    }

private:
    template<typename UInt>
    static UInt& mod_ref() {
        static UInt mod = 0;
        return mod;
    }

    static uint norm(const uint* x) {
        return *x < mod() ? *x : *x - mod();
    }

    static id5 make(const uint* x) {
        id5 m;
        m.v = *x;
        return m;
    }

    static id5 power(id5* x, ull n) {
        id5 ans = 1;
        for (; n; n >>= 1, *x *= *x) {
            if (n & 1) {
                ans *= *x;
            }
        }
        return ans;
    }

    static id5 inv(const ll* v) {
        return *v < 1000000 ? small_inv(static_cast<usize>(v)) : id5{inverse(v, static_cast<ll>(mod()))};
    }

    static std::vector<id5>& inv_ref() {
        static std::vector<id5> in{1, 1};
        return in;
    }
};

template<uint mod>
using modint = id5<mod, false>;

template<uint id>
using dynamic_modint = id5<id, true>;

template<typename T>
constexpr T popcount(const T* u) {
    T u_val = *u;
    return u_val ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u_val))) : static_cast<T>(0);
}

template<typename T>
constexpr T id0(const T* u) {
    T u_val = *u;
    return u_val ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u_val))) : static_cast<T>(0);
}

template<typename T>
constexpr T id6(const T* u) {
    return id0(u);
}

template<typename T>
constexpr T id4(const T* u) {
    return __builtin_ffsll(*u);
}

template<typename T>
constexpr T clog(const T* u) {
    T u_val = *u;
    return u_val ? id0(u_val - 1) : static_cast<T>(u_val);
}

template<typename T>
constexpr bool id2(const T* u) {
    T u_val = *u;
    return u_val && (static_cast<u64>(u_val) & static_cast<u64>(u_val - 1)) == 0;
}

template<typename T>
constexpr T ceil2(const T* u) {
    return static_cast<T>(1) << clog(u);
}

template<typename T>
constexpr T floor2(const T* u) {
    T u_val = *u;
    return u_val == 0 ? static_cast<T>(0) : static_cast<T>(1) << (id0(u_val) - 1);
}

template<typename T>
constexpr bool btest(const T* mask, const usize* ind) {
    return static_cast<bool>((static_cast<u64>(*mask) >> *ind) & static_cast<u64>(1));
}

template<typename T>
void bset(T* mask, const usize* ind) {
    *mask |= (static_cast<T>(1) << *ind);
}

template<typename T>
void breset(T* mask, const usize* ind) {
    *mask &= ~(static_cast<T>(1) << *ind);
}

template<typename T>
void bflip(T* mask, const usize* ind) {
    *mask ^= (static_cast<T>(1) << *ind);
}

template<typename T>
void bset(T* mask, const usize* ind, const bool* b) {
    if (*b) {
        bset(mask, ind);
    } else {
        breset(mask, ind);
    }
}

template<typename T>
constexpr T bcut(const T* mask, const usize* ind) {
    return *ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(*mask) << (64 - *ind)) >> (64 - *ind));
}

template<typename T>
bool chmin(T* a, const T* b) {
    if (*a > *b) {
        *a = *b;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T* a, const T* b) {
    if (*a < *b) {
        *a = *b;
        return true;
    }
    return false;
}

constexpr unsigned int mod = 1000000007;

template<typename T>
constexpr T inf_v = std::numeric_limits<T>::max() / 4;

template<typename Real>
constexpr Real pi_v = Real{3.141592653589793238462643383279502884};

auto mfp = [](auto&& f) {
    return [=](auto&&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
};

template<typename T>
T in() {
    T v;
    scanf("%d", &v);
    return v;
}

template<typename T, typename Uint, usize n, usize i>
auto in_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type) {
    return in<T>();
}

template<typename T, typename Uint, usize n, usize i>
auto in_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type szs) {
    const usize s = (usize)szs[i];
    std::vector<decltype(in_v<T, Uint, n, i + 1>(szs))> ans(s);
    for (usize j = 0; j < s; j++) {
        ans[j] = in_v<T, Uint, n, i + 1>(szs);
    }
    return ans;
}

template<typename T, typename Uint, usize n>
auto in_v(c_arr<Uint, n> szs) {
    return in_v<T, Uint, n, 0>(szs);
}

int main() {
    constexpr uint mod = 998244353;
    using mint = modint<mod>;
    const auto n = in<int>();
    const auto m = in<int>();
    const auto a = in_v<bool>({n});
    const auto w = in_v<int>({n});
    int zw = 0, ow = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            ow += w[i];
        } else {
            zw += w[i];
        }
    }
    const int s = zw + ow;
    std::vector<mint> inv(2 * m + 1);
    for (int d = -m; d <= m; d++) {
        if (s + d > 0) {
            inv[d + m] = mint(1) / (s + d);
        }
    }
    auto dp = make_v({m + 1, 2}, mint(0));
    dp[0] = {1, 1};
    for (int i = 0; i < m; i++) {
        auto ndp = make_v({m + 1, 2}, mint(0));
        for (int z = 0; z <= i; z++) {
            const int o = i - z;
            const int wz = zw - z;
            const int wo = ow + o;
            if (wz < 0) {
                continue;
            }
            for (int dz = -1; dz <= 0; dz++) {
                const int nwz = wz + dz;
                const int nz = z + (-dz);
                if (nwz < 0) {
                    continue;
                }
                const mint eps = inv[wz + wo - s + m];
                const mint p = mint(dz == -1 ? wz : wo) * eps;
                ndp[nz][-dz] += dp[z][-dz] * p;
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz];
            }
        }
        dp = ndp;
    }
    mint cz = 0, co = 0;
    for (int i = 0; i <= m; i++) {
        cz += dp[i][0];
        co += dp[i][1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", w[i] * (a[i] == 0 ? cz : co));
    }
    return 0;
}
