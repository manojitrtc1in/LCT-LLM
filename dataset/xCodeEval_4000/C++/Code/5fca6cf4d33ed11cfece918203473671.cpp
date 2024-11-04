



#include <ctime>
#include <random>
#include <vector>
#include <algorithm>

constexpr int mod = 998244353 ;
constexpr int I2 = (mod + 1) >> 1;
constexpr int N = 1 << 19;
constexpr int G = 3 ;
constexpr int I = 86583718;

int inv[N], fac[N], ifac[N];

using std::vector;

std::mt19937 rnd(time(nullptr) + (unsigned long long)(new char) + 20051107);

inline int fp(int x, int y = mod - 2) {
    int res = 1 ;

    for (; y; y >>= 1, x = 1ll * x * x % mod)
        if (y & 1)
            res = 1ll * res * x % mod ;

    return res ;
}


namespace poly {

static unsigned long long t[N];
static int lim, rev[N], w[N];

inline void init() {
    for (int len = 1; len < N; len <<= 1) {
        const int tmp = fp(G, (mod - 1) / (len << 1)) ;
        w[len] = 1 ;

        for (int i = 1; i < len; ++i)
            w[len + i] = 1ll * w[len + i - 1] * tmp % mod ;
    }

    inv[0] = inv[1] = fac[0] = fac[1] = 1;

    for (int i = 2; i < N; ++i)
        inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod, fac[i] = 1ll * fac[i - 1] * i % mod;
}

inline void Getrev(const int len) {
    for (lim = 1; lim <= len; lim <<= 1) ;

    for (int i = 0; i < lim; ++i)
        rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? lim >> 1 : 0) ;
}

inline void dev(vector<int> &a) {
    const int len = a.size() ;

    for (int i = 0; i < len - 1; ++i)
        a[i] = 1ll * (i + 1) * a[i + 1] % mod ;

    a[len - 1] = 0 ;
}

inline void itg(vector<int> &a) {
    const int len = a.size() ;

    for (int i = len - 1; i >= 1; --i)
        a[i] = 1ll * a[i - 1] * inv[i] % mod ;

    a[0] = 0 ;
}

inline void ntt(vector<int> &a, const int lim, const int opt) {
    for (int i = 0; i < lim; ++i)
        t[i] = a[rev[i]] ;

    for (int len = 1; len < lim; len <<= 1) {
        if (len == 1 << 16)
            for (int i = 0; i < lim; ++i)
                t[i] %= mod ;

        for (int i = 0; i < lim; i += len << 1)
            for (int j = 0; j < len; ++j) {
                const unsigned long long x = t[i | j | len] * w[j | len] % mod ;
                t[i | j | len] = t[i | j] + mod - x, t[i | j] += x;
            }
    }

    for (int i = 0; i < lim; ++i)
        a[i] = t[i] % mod ;

    if (opt == -1) {
        const int IN = fp(lim) ;
        std::reverse(a.begin() + 1, a.begin() + lim) ;

        for (int i = 0; i < lim; ++i)
            a[i] = 1ll * a[i] * IN % mod ;
    }
}

inline auto operator * (vector<int> a, vector<int> b) {
    const int len = a.size() + b.size() - 1 ;

    if (len <= 100) {
        vector<int> res(len) ;

        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
                res[i + j] = (res[i + j] + 1ll * a[i] * b[j] % mod) % mod ;

        return res ;
    }

    Getrev(len), a.resize(lim), b.resize(lim), ntt(a, lim, 1), ntt(b, lim, 1) ;

    for (int i = 0; i < lim; ++i)
        a[i] = 1ll * a[i] * b[i] % mod ;

    ntt(a, lim, -1), a.resize(len) ;
    return a;
}

auto Inv(vector<int> a) {
    const int len = a.size() ;

    if (len <= 100) {
        std::vector<int> b(len) ;

        b[0] = fp(a[0]) ;

        for (int i = 1; i < len; ++i) {
            int sum = 0;

            for (int j = 1; j <= i; ++j)
                sum = (sum + 1ll * a[j] * b[i - j] % mod) % mod ;

            b[i] = mod - 1ll * sum * b[0] % mod ;
        }

        return b ;
    }

    vector<int> ta = a;

    ta.resize((len + 1) >> 1) ;

    vector<int> tb = Inv(ta) ;

    Getrev(len << 1), a.resize(lim), tb.resize(lim), ntt(a, lim, 1), ntt(tb, lim, 1) ;

    for (int i = 0; i < lim; ++i)
        tb[i] = 1ll * tb[i] * (mod + 2 - 1ll * a[i] * tb[i] % mod) % mod ;

    return ntt(tb, lim, -1), tb.resize(len), tb ;
}

inline auto Ln(vector<int> a) {
    if (a.size() <= 100) {
        const int len = a.size() ;
        vector<int> b(len) ;

        b[0] = 0 ;

        for (int i = 1; i < len; ++i) {
            int sum = 0 ;

            for (int j = 1; j < i; ++j) 
                sum = (sum + 1ll * j * b[j] % mod * a[i - j] % mod) % mod ;
            
            b[i] = (a[i] + mod - 1ll * inv[i] * sum % mod ) % mod;
        }
        return b ;
    }
    vector<int> ta = a ;
    const int len = a.size() ;
    return dev(ta), a = ta * Inv(a), itg(a), a.resize(len), a;
}

auto Exp(vector<int> a) {
     if (a.size() <= 100) {
        const int len = a.size() ;
        vector<int> b(len) ;

        b[0] = 1 ;

        for (int i = 1; i < len; ++i) {
            int sum = 0 ;

            for (int j = 1; j <= i; ++j) 
                sum = (sum + 1ll * j * a[j] % mod * b[i - j] % mod) % mod ;
            
            b[i] = 1ll * inv[i] * sum % mod ;
        }

        return b;
    }

    const int len = a.size() ;
    vector<int> ta = a;
    ta.resize((len + 1) >> 1) ;
    vector<int> tb = Exp(ta) ;
    tb.resize(len) ;
    vector<int> Lnb = Ln(tb) ;
    for (int i = 0; i < len; ++i)
        Lnb[i] = (a[i] - Lnb[i] + mod) % mod ;
    return Lnb[0] = (Lnb[0] + 1) % mod, tb = tb * Lnb, tb.resize(len), tb ;
}

inline auto Sqrt(vector<int> a) {
    if (a.size() == 1)
        return vector<int> (1, 1);

    const int len = a.size() ;
    auto ta = a;
    ta.resize((len + 1) >> 1) ;
    auto tb = Sqrt(ta);
    tb.resize(len) ;
    auto tc = tb * tb;
    tc.resize(len) ;

    for (auto &it : tb)
        it = 2ll * it % mod ;

    for (int i = 0; i < len; ++i)
        tc[i] = (tc[i] + a[i]) % mod ;

    return tc = tc * Inv(tb), tc.resize(len), tc ;
}

inline auto Pow(vector<int> a, const int k) {
    const int len = a.size() ;
    auto ta = Ln(a) ;

    for (int i = 0; i < len; ++i)
        ta[i] = 1ll * ta[i] * k % mod ;

    return Exp(ta) ;
}

inline auto mult(vector<int> a, vector<int> b) {
    const unsigned int n = a.size(), m = b.size(), len = n - m + 1 ;
    vector<int> res(len) ;

    if (len <= 50) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m && j <= i; ++j)
                if (i - j <= n - m)
                    res[i - j] = (res[i - j] + 1ll * a[i] * b[j]) % mod;

        return res ;
    }

    Getrev(n), std::reverse(b.begin(), b.end()), a.resize(lim), b.resize(lim), ntt(a, lim, 1), ntt(b, lim, 1);

    for (int i = 0; i < lim; ++i)
        a[i] = 1ll * a[i] * b[i] % mod;

    ntt(a, lim, -1) ;

    for (int i = m - 1, j = 0; i < n; ++i, ++j)
        res[j] = a[i] ;

    return res ;
}

inline auto eval(vector<int> a, vector<int> x) {
    unsigned int n = a.size(), m = x.size() ;
    n = std::max(n, m), a.resize(n), x.resize(n) ;
    vector < vector<int>> F(n << 2), T(n << 2) ;
    std::function<void(int, int, int)> dfs1 = [&](int u, int l, int r) {
        if (l == r)
            return T[u] = {1, mod - x[l]}, void();
        const int mid = (l + r) >> 1;
        dfs1(u << 1, l, mid), dfs1(u << 1 | 1, mid + 1, r), T[u] = T[u << 1] * T[u << 1 | 1] ;
    };
    vector<int> ret(m) ;
    std::function<void(int, int, int)> dfs2 = [&](int u, int l, int r) {
        if (l >= m)
            return ;

        if (l == r)
            return ret[l] = F[u][0], void() ;

        const int mid = (l + r) >> 1 ;
        F[u << 1] = mult(F[u], T[u << 1 | 1]), F[u << 1 | 1] = mult(F[u], T[u << 1]), dfs2(u << 1, l, mid),
                    dfs2(u << 1 | 1, mid + 1, r) ;
    };
    dfs1(1, 0, n - 1) ;
    vector<int> tmp = Inv(T[1]) ;
    a.resize(n << 1), F[1] = mult(a, tmp) ;
    return dfs2(1, 0, n - 1), ret;
}

inline auto Cos(vector<int> f) {
    const int len = f.size() ;

    for (int i = 0; i < len; ++i)
        f[i] = 1ll * f[i] * I % mod ;

    auto g = Exp(f), h = Inv(g) ;

    for (int i = 0; i < len; ++i)
        g[i] = 1ll * I2 * (g[i] + h[i]) % mod ;

    return g ;
}

inline auto Sin(vector<int> f) {
    const int len = f.size() ;

    for (int i = 0; i < len; ++i)
        f[i] = 1ll * f[i] * I % mod ;

    auto g = Exp(f), h = Inv(g) ;
    const int x = fp(I << 1) ;

    for (int i = 0; i < len; ++i)
        g[i] = 1ll * x * (g[i] - h[i] + mod) % mod ;

    return g ;
}

inline auto Asin(vector<int> f) {
    auto g = f ;
    int n = f.size() ;
    dev(f), g = g * g;

    for (auto &it : g)
        it = mod - it ;

    g[0] = (g[0] + 1) % mod, g.resize(n);
    g = Sqrt(g), g = Inv(g), f = f * g, f.resize(n), itg(f);
    return f;
}

inline auto Atan(vector<int> f) {
    auto g = f ;
    int n = f.size() ;
    dev(f), g = g * g, g[0] = (g[0] + 1) % mod, g.resize(n);
    f = f * Inv(g), f.resize(n), itg(f) ;
    return f ;
}

inline std::pair<vector<int>, vector<int>> Div(vector<int> f, vector<int> g) {
    int n = f.size(), m = g.size();

    if (n - m < 0)
        return std::make_pair(vector<int> (1, 0), f) ;

    vector<int> fr(n), gr(m), igr, q(n - m + 1), r(m);

    for (int i = 0; i < n; ++i)
        fr[n - i - 1] = f[i] ;

    for (int i = 0; i < m; ++i)
        gr[m - i - 1] = g[i] ;

    gr.resize(n - m + 1) ;
    igr = Inv(gr), fr = fr * igr ;

    for (int i = 0; i < n - m + 1; ++i)
        q[i] = fr[n - m - i] ;

    g = q * g ;

    for (int i = 0; i < m; ++i)
        r[i] = (f[i] - g[i] + mod) % mod ;

    return std::make_pair(q, r) ;
}

inline int LR(vector<int> a, vector<int> p, int n) {
    int k = p.size();
    vector<int> f(2), res(1), q(k + 1);

    for (auto &it : p)
        it = mod - it ;

    for (int i = 0; i < k; ++i)
        q[i] = p[k - 1 - i] ;

    q[k] = f[1] = res[0] = 1;

    while (n) {
        if (n & 1) {
            res = res * f;
            auto tmp = Div(res, q) ;
            res = tmp.second ;
        }

        f = f * f ;
        auto temp = Div(f, q) ;
        f = temp.second, n >>= 1;
    }

    int ans = 0 ;

    for (int i = 0; i < k; ++i)
        ans = (ans + 1ll * a[i] * res[i] % mod) % mod ;

    return ans ;
}

vector<int> BM(vector<int> a) {
    vector<int> ans, lst ;
    int w = 0, delta = 0, n = a.size() - 1;

    for (int i = 1; i <= n; ++i) {
        int tmp = 0;

        for (int j = 0; j < (int)ans.size(); ++j)
            tmp = (tmp + 1ll * a[i - 1 - j] * ans[j] % mod) % mod ;

        if ((a[i] - tmp) % mod == 0)
            continue ;

        if (!w) {
            w = i, delta = a[i] - tmp ;

            for (int j = i; j; --j)
                ans.push_back(0) ;

            continue ;
        }

        vector<int> now = ans;
        int mul = 1ll * (a[i] - tmp) * fp(delta) % mod ;

        if (ans.size() < lst.size() + i - w)
            ans.resize(lst.size() + i - w) ;

        ans[i - w - 1] = (ans[i - w - 1] + mul) % mod ;

        for (int j = 0; j < (int)lst.size(); ++j)
            ans[i - w + j] = (ans[i - w + j] - 1ll * mul * lst[j] % mod) % mod;

        if (now.size() - i < lst.size() - w)
            lst = now, w = i, delta = a[i] - tmp ;
    }

    return ans ;
}

}
struct Initalize {
  Initalize() {
    poly::init();
  }
} initalize;


#include "bits/stdc++.h"

using std::cin;
using std::cout;
using poly::operator*;

constexpr int M = 2.5e5 + 5;

int n;
int d[M];
int head[M], to[M << 1], nxt[M << 1];

inline void add(int u, int v) noexcept {
  static int cnt = 0;
  to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}

void prepare(int p, int u) {
  for (int i = head[u]; i; i = nxt[i]) {
    if (int v = to[i]; v != p) {
      ++d[u];
      prepare(u, v);
    }
  }
}

vector<int> calc(int l, int r) {
  if (l == r) {
    return vector<int> {1, d[l]};
  }
  int mid = (l + r) >> 1;
  auto ls = calc(l, mid), rs = calc(mid + 1, r);
  return ls * rs;
}

int main(int argc, const char** argv) {
#ifdef Feicheng
  freopen("input.in", "r", stdin);
  freopen("output.ans", "w", stdout);
#endif 
  std::basic_ios<char>::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  prepare(0, 1);
  

  

  

  

  auto f = calc(1, n);
  

  

  

  

  

  

  

  

  for (int i = 0; i < n; ++i) {
    f[i] = 1ll * f[i] * fac[n - i] % mod;
  } 
  

  

  

  

  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer = (answer + ((i & 1) ? mod - f[i] : f[i])) % mod; 
  }
  cout << answer << '\n';
  return 0;
} 