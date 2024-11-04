#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-emplace"
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "bugprone-easily-swappable-parameters"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#ifdef DEBUG
#include <bits/extc++.h>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

using namespace __gnu_pbds;
using namespace std;
const auto& npos = string::npos;

#define itn int
#define int int64_t
#define str string
#define vec vector
#define vi vec<int>
#define v2d vec<vi>
#define v3d vec<v2d>
#define vtri vec<tri>
#define let auto
#define ret return
#define cont continue
#define elif else if
#define eilf elif
#define elfi elif
#define loop while(true)
#define opt optional
#define cint const int
#define cvi const vi
#define clet const let
#define cv2d const v2d
#define cpi const pi
#define popcnt(x) popcount(uintmax_t(x))
#define cvpi const vpi
#define bakc back
#define cvec const vec
#define cvtri const vtri
#define citn const itn
#define celt clet
#define nl endl
#define eb emplace_back

#define CONCAT(a, b) CONCAT_INNER(a,b)
#define CONCAT_INNER(a, b) a ## b
#define ITER_CNT CONCAT(CONCAT(iter_cnt, __LINE__), _)
#define INTERNAL_FOR(N, v) for (int v = 0; (v) < int(N); ++(v)) 

#define forn(v, n) INTERNAL_FOR(n,v)
#define forc(x, a) for (const let &x: (a)) 

#define fi(N) INTERNAL_FOR(N,i)
#define fj(N) INTERNAL_FOR(N,j)
#define fk(N) INTERNAL_FOR(N,k)
#define SET unordered_set
#define MAP unordered_map

using tri = array<int, 3>;
using pii = pair<int, int>;
using pi = pii;
using vpi = vec<pi>;
using spi = set<pi>;
using pvv = pair<vec<int>, vec<int>>;
using vtr = vec<tri>;

#define ordered_set(T, cmp) tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> 


cint MOD = 1e9 + 7;
#define INF (numeric_limits<int>::max() / 2)
#define INFP pair{INF, INF}
#define PINF INFP

class NullStream : public streambuf {
 public:
  int overflow(cint c) {
      ret c;
  }
};

NullStream __null_stream__base__;
ostream __null_stream__(&__null_stream__base__);

#ifndef DEBUG
#define cerr __null_stream__
#endif

template<typename T>
auto clz(const T x) {
    clet sz = sizeof(T);
    static_assert(sz == 4 || sz == 8);
    switch (sz) {
        case 8: {
            ret __builtin_clzll(x);
        }
        case 4: {
            ret __builtin_clz(x);
        }
        default: {
            abort();
        }
    }
}

namespace std {
template<>
struct hash<pi> {
  size_t operator()(const pi& x) const {
      return ((hash<int>()(x.first)
          ^ (hash<int>()(x.second) << 1)) >> 1);
  }
};
}

namespace std {
template<>
struct hash<tri> {
  size_t operator()(const tri& x) const {
      return hash<pi>()(pi{
          x[0], x[1]
      }) ^ (hash<int>()(x[2]) << 1);
  }
};
}

auto min(const intmax_t a, const intmax_t b) {
    ret a < b ? a : b;
}

auto max(const intmax_t a, const intmax_t b) {
    ret a > b ? a : b;
}

template<typename T>
vec<T>& operator+=(vec<T>& lhs, cvec<T>& rhs) {
    lhs.insert(lhs.end(), rhs.cbegin(), rhs.cend());
    ret lhs;
}

template<typename T>
vec<T> operator+(cvec<T>& lhs, cvec<T>& rhs) {
    vec<T> res = lhs;
    ret res += rhs;
}

vi mm1(vi v) {
    for (let& el: v) {
        el--;
    }
    ret v;
}

vpi mm1(vpi v) {
    for (let& [f, s]: v) {
        f--, s--;
    }
    ret v;
}

vi rd_vi(cint n) {
    vi res(n);
    for (let& el: res) {
        cin >> el;
    }
    ret res;
}

istream& operator>>(istream& is, pi& p) {
    ret is >> p.first >> p.second;
}

vpi rd_vpi(cint n) {
    vpi res(n);
    for (let& p: res) {
        cin >> p;
    }
    ret res;
}

istream& operator>>(istream& is, tri& t) {
    for (let& x: t) {
        is >> x;
    }
    ret is;
}

vtri rd_vtri(cint n) {
    vtri res(n);
    for (let& el: res) {
        cin >> el;
    }
    ret res;
}

v2d rd_v2d(cint n, int m = -1) {
    if (m == -1) {
        m = n;
    }
    v2d res(n);
    for (let& l: res) {
        l = rd_vi(m);
    }
    ret res;
}

pi Inc(pi p) {
    ++p.first, ++p.second;
    ret p;
}
















#if !defined(DEBUG) && !defined(INTERACTIVE)
#define endl "\n"
#endif

void solve() {
    itn n;
    cin >> n;
    vi a(n);
    forn(i, n) {
        char c;
        cin >> c;
        if (c == '-') {
            a[i] = -1;
        } else {
            cin >> a[i];
        }
    }
    a = vi{0} + a;

    int res = 0;
    for (int chk = 1; chk <= n; ++chk) {
        clet cur = a[chk];
        if (cur == -1) {
            continue;
        }

        v2d dp(n + 1, vi(n + 1));
        dp[0][0] = 1;

        for (int pos = 1; pos <= n; ++pos) {
            for (int s = 0; s <= n; ++s) {
                if (a[pos] == -1) {
                    dp[pos][max(s - 1, 0)] += dp[pos - 1][s];
                    dp[pos][max(s - 1, 0)] %= 998'244'353;
                } else {
                    if (pi{a[pos], pos} > pi{a[chk], chk}) {
                        dp[pos][s] += dp[pos - 1][s];
                        dp[pos][s] %= 998'244'353;
                    } else {
                        if (s < n) {
                            dp[pos][s + 1] += dp[pos - 1][s];
                            dp[pos][s + 1] %= 998'244'353;
                        }
                    }
                }

                if (chk != pos) {
                    dp[pos][s] += dp[pos - 1][s];
                    dp[pos][s] %= 998'244'353;
                }
            }

            if (pos > chk) {
                dp[pos][0] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            cerr << "dp[" << n << "][" << i << "] = " << dp[n][i]
                 << ", a[" << chk << "] = " << a[chk] << nl;
            res = (res + (dp[n][i] % 998'244'353 * a[chk]) % 998'244'353) % 998'244'353;
        }
    }

    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
#if !defined(DEBUG) && !defined(INTERACTIVE)
    cin.tie(nullptr);
#endif
    cin.exceptions(istream::failbit | istream::badbit);
    int t = 1;
    

    while (t--) {
        solve();
#ifndef INTERACTIVE
        cout << endl;
#endif
#if defined(INTERACTIVE) || defined(DEBUG)
        cout.flush();
#endif
    }
}

#pragma clang diagnostic pop