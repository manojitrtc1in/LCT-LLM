#ifndef DEBUG
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,abm,bmi,bmi2,lzcnt,popcnt")
#endif

#pragma ide diagnostic ignored "modernize-loop-convert"
#pragma clang diagnostic ignored "-Wunqualified-std-cast-call"
#pragma ide diagnostic ignored "google-explicit-constructor"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "modernize-use-nodiscard"
#pragma ide diagnostic ignored "readability-container-size-empty"
#pragma ide diagnostic ignored "modernize-use-emplace"
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "modernize-use-bool-literals"
#pragma ide diagnostic ignored "bugprone-easily-swappable-parameters"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#ifdef DEBUG
#include <bits/extc++.h>
#include <ranges>
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
#define vec vector
#define let auto
#define ret return
#define cont continue;
#define brk break
#define fpr for
#define fop for
#define fopr for
#define fi if
#define eles else
#define elif else if
#define elseif else if
#define eilf elif
#define elfi elif
#define loop while(true)
#define opt optional
#define cosnt const
#define cpnst const
#define clet const let
#define popcnt(x) popcount(uintmax_t(x))
#define bakc back


#define citn const itn
#define prqueue std::priority_queue
#define celt clet
#define lcet clet
#define nl endl
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define tie make_tuple
#define eps (numeric_limits<double>::epsilon())
#define len(x) (int((x).size()))











#define forc(x, a) for (const let &x: (a)) 

#define SET unordered_set
#define MAP unordered_map
#define RESET(x) memset((x), 0, sizeof((x)));

using vi = vec<int>;
using v2d = vec<vi>;
using v3d = vec<v2d>;
using vb = vec<bool>;
using tri = array<int, 3>;
using vtri = vec<tri>;
using pii = pair<int, int>;
using pi = pii;
using vpi = vec<pi>;
using spi = set<pi>;
using pvv = pair<vi, vi>;
using vtr = vec<tri>;
using cint = const int;
using cvi = const vi;
using cvpi = const vpi;
using cv2d = const v2d;
using cpi = const pi;
using cvtri = const vtri;

#define ordered_set(T, cmp) tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> 


#define INF ((numeric_limits<int>::max() - 1) / 4)
#define MNX pair{INF, -INF}
#define UMNX(mnx_pair, mn, mx) (mnx_pair).first = min((mnx_pair).first, (mn)), \
(mnx_pair).second = max((mnx_pair).second, (mx));
#define getchar (cin.get)
#define YES "YES"
#define Yes "Yes"
#define NO "NO"
#define No "No"
#define yes "yes"
#define no "no"

namespace std {
template<>
struct hash<pi> {
  size_t operator()(const pi& x) const {
      ret ((hash<int>()(x.first)
          ^ (hash<int>()(x.second) << 1)) >> 1);
  }
};

template<>
struct hash<tri> {
  size_t operator()(const tri& x) const {
      ret hash<pi>()(pi{
          x[0], x[1]
      }) ^ (hash<int>()(x[2]) << 1);
  }
};
}

namespace {
string yn(const bool cond) {
    ret cond ? (yes) : (no);
}

class NullStream : public ostream {
};

template<typename T>
NullStream& operator<<(NullStream& ns, T _x) {
    ret ns;
}

NullStream NULL_STREAM; 


#ifndef DEBUG
#define cerr NULL_STREAM
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

auto min(const intmax_t a, const intmax_t b) {
    ret a < b ? a : b;
}

auto max(const intmax_t a, const intmax_t b) {
    ret a > b ? a : b;
}

template<typename T>
vec<T>& operator+=(vec<T>& lhs, const vec<T>& rhs) {
    lhs.reserve(lhs.size() + rhs.size());
    lhs.insert(lhs.end(), rhs.cbegin(), rhs.cend());
    ret lhs;
}

template<typename T>
vec<T> operator+(const vec<T>& lhs, const vec<T>& rhs) {
    vec<T> res = lhs;
    ret res += rhs;
}

inline vi mm1(vi v) {
    for (let& el: v) {
        el--;
    }
    ret v;
}

inline vpi mm1(vpi v) {
    for (let& [f, s]: v) {
        f--, s--;
    }
    ret v;
}

pi mm1(pi p) {
    --p.first, --p.second;
    ret p;
}

vi rd_vi(const int n) {
    vi res(n);
    for (let& el: res) {
        cin >> el;
    }
    ret res;
}

istream& operator>>(istream& is, pi& p) {
    ret is >> p.first >> p.second;
}

vpi rd_vpi(const int n) {
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

vtri rd_vtri(const int n) {
    vtri res(n);
    for (let& el: res) {
        cin >> el;
    }
    ret res;
}

v2d rd_v2d(const int n, int m = -1) {
    if (m == -1) {
        m = n;
    }
    v2d res(n);
    for (let& l: res) {
        l = rd_vi(m);
    }
    ret res;
}

vb rd_vb(const int n = 0) {
    string s{};
    if (n <= 0) {
        cin >> s;
    } else {
        for (int i = 0; i < n; ++i) {
            bool b;
            cin >> b;
            s.pb('0' + b);
        }
    }

    vb res(s.size());
    for (int i = 0; i < s.size(); ++i) {
        assert(s[i] == '1' || s[i] == '0');
        res[i] = s[i] == '1';
    }
    ret res;
}

pi Inc(pi p) {
    ++p.first, ++p.second;
    ret p;
}

pi Dec(pi p) {
    ret mm1(p);
}

string to_string(const vb& x) {
    string s{};
    forc(x, x) {
        s.pb('0' + x);
    }
    ret s;
}



class ModInt;
[[maybe_unused]] vector<ModInt> inverse();

using ModType = int64_t;

class ModInt {
 public:
  const static ModType mod = 998244353;

 private:
  static vec<ModInt> precalcInverse;

  [[maybe_unused]] void precalc() {
      precalcInverse = inverse();
  }

  static vec<ModInt> inverse();

 public:
  ModType val;

  constexpr ModInt(cosnt ModInt& x) = default;

  ModInt(string_view s) {
      val = 0;
      forc(c, s) {
          val = (val * 10 + (c - '0')) % ModInt::mod;
      }
  }

  constexpr ModInt(const ModType v = 0) : val(v % mod) {
  }

  

  


  

  

  

  

  

  


  ModInt& operator--() {
      ret this->operator-=(1);
  }

  ModInt operator--(int32_t) { 

      const ModInt old = *this;
      this->operator--();
      ret old;
  }

  ModInt& operator++() {
      ret this->operator+=(1);
  }

  ModInt operator++(int32_t) { 

      const ModInt old = *this;
      this->operator++();
      ret old;
  }

  ModInt& operator+=(const ModInt& other) {
      val += other.val % mod;
      if (val >= mod) {
          val -= mod;
      }
      ret *this;
  }

  ModInt& operator-=(const ModInt& other) {
      val -= other.val % mod;
      if (val < 0) {
          val += mod;
      }
      ret *this;
  }

  constexpr ModInt operator*(const ModInt& other) cosnt {
      ret ModInt(*this) *= other;
  }

  constexpr ModInt& operator*=(const ModInt& other) {
      val = (val * other.val) % mod;
      ret *this;
  }

  ModInt& operator/=(ModInt a) {
      if (precalcInverse.size() > static_cast<size_t>(a.val)) {
          *this *= precalcInverse[a.val];
          ret *this;
      }

      ModType u = 1, v = a.val, s = 0, t = mod;
      while (v) {
          const ModType q = t / v;
          swap(s -= u * q, u);
          swap(t -= v * q, v);
      }
      a.val = s < 0 ? s + mod : s;
      val /= t;
      ret (*this) *= a;
  }

  [[nodiscard]] ModInt inv() const {
      ret ModInt(1) /= (*this);
  }

  bool operator<(const ModInt& other) const {
      ret val < other.val;
  }

  bool operator>=(const ModInt& other) const {
      ret !(*this < other);
  }

  operator ModType() const {
      return val;
  }
};

vec<ModInt> ModInt::precalcInverse;

ostream& operator<<(ostream& os, ModInt& a) {
    os << a.val;
    ret os;
}

ModInt operator+(ModInt a, const ModInt& b) {
    ret a += b;
}

ModInt operator-(ModInt a, const ModInt& b) {
    ret a -= b;
}

constexpr ModInt operator*(cint a, const ModInt& b) {
    ret ModInt(a) *= b;
}

constexpr ModInt operator*(ModInt a, cint b) {
    ret a *= b;
}

ModInt operator/(ModInt a, const ModInt& b) {
    ret a /= b;
}

ModInt pow(ModInt a, ModType e) {
    ModInt x(1);
    for (; e > 0; e /= 2) {
        if (e % 2 == 1) {
            x *= a;
        }
        a *= a;
    }
    ret x;
}

vec<ModInt> ModInt::inverse() {
    vec<ModInt> inv(ModInt::mod);
    inv[1].val = 1;
    for (ModType a = 2; a < mod; ++a) {
        inv[a] = inv[mod % a] * ModInt(mod - mod / a);
    }
    ret inv;
}

#if !defined(DEBUG) && !defined(INTERACTIVE)
#define endl "\n"
#endif

class DSU {
 private:
  vi dsu_parent;
  vi dsu_rank;

  void make_dsu_set(cint v) {
      dsu_parent[v] = v;
      dsu_rank[v] = 0;
  }

 public:
  DSU(cint n) : dsu_parent(n), dsu_rank(n) {
      for (int i = 0; i < n; ++i) {
          make_dsu_set(i);
      }
  }

  int find_dsu_set(cint v) {
      if (v == dsu_parent[v]) {
          ret v;
      }
      ret dsu_parent[v] = find_dsu_set(dsu_parent[v]);
  }

  void union_dsu_sets(int a, int b) {
      a = find_dsu_set(a);
      b = find_dsu_set(b);
      if (a != b) {
          if (dsu_rank[a] < dsu_rank[b]) {
              swap(a, b);
          }
          dsu_parent[b] = a;
          if (dsu_rank[a] == dsu_rank[b]) {
              ++dsu_rank[a];
          }
      }
  }
};
}

#define PRE { \
};

void solve() {
    int n;
    cin >> n;
    let a = rd_vi(n);
    if (n <= 2) {
        cout << 1;
        ret;
    }

    sort(all(a));
    map<int, int> mp;
    forc(x, a) {
        mp[x]++;
    }

    set<int> tw;
    forc(x, mp) {
        if (x.second >= 2) {
            tw.insert(x.first);
        }
    }

    set<int> is, ds;
    forc(x, tw) {
        is.insert(x);
        ds.insert(x);
    }

    let lis = [=](cvi& a) -> int {
        cint n = len(a);
        vi dp(n + 1, INF);
        dp[0] = -INF;

        forc(x, a) {
            let lb = lower_bound(dp.begin(), dp.end(), x);
            if (lb == dp.end()) {
                cont;
            }
            *lb = x;
        }

        int res{};
        for (int i = 0; i < len(dp); ++i) {
            cerr << "dp[" << i << "] = " << dp[i] << nl;
            if (dp[i] < INF) {
                res = i;
            }
        }
        ret res;
    };

    let clc_n_rev = [=](vi& a) {
        int ans = lis(a);
        cerr << "ans = " << ans << nl;
        reverse(a.begin(), a.end());
        ret min(ans, lis(a));
    };

    int cur{};
    int lst;
    forc(x, mp) {
        if (tw.contains(x.first)) {
            cont;
        }

        set<int>* hv[2] = {&is, &ds};
        hv[cur]->insert(hv[cur]->lower_bound(x.first), x.first);
        cur = !cur;
        lst = x.first;
    }
    fi (len(tw) == len(mp)) {
        a = vi(all(is)) + vi(ds.rbegin(), ds.rend());
        cout << clc_n_rev(a);
        ret;
    }

    a.clear();
    if (cur) {
        let it = is.cbegin();
        for (int i = 0; i < len(is); ++i, ++it) {
            a.pb(*it);
            if (*it == lst) {
                clet ub = ds.upper_bound(*it);
                vi tmp(ub, ds.end());
                reverse(all(tmp));
                a = tmp + a;

                tmp = vi(ds.begin(), ub);
                reverse(all(tmp));
                a += tmp;
            }
        }
    } else {
        let it = ds.cbegin();
        for (int i = 0; i < len(ds); ++i, ++it) {
            a.pb(*it);
            if (*it == lst) {
                clet ub = is.upper_bound(*it);
                vi tmp(ub, is.end());
                reverse(all(tmp));
                a = tmp + a;

                tmp = vi(is.begin(), ub);
                reverse(all(tmp));
                a += tmp;
            }
        }
    }
    forc(x, tw) {
        for (int i = 0; i < mp[x] - 2; ++i) {
            a.pb(x);
        }
    }
    assert(len(a) == n);

    itn res = clc_n_rev(a);
    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
#if !defined(DEBUG) && !defined(INTERACTIVE)
#undef tie
    cin.tie(nullptr);
#endif
    cin.exceptions(istream::failbit | istream::badbit);

#ifdef PRE
    PRE;
#endif

    int t = 1;
    cin >> t;
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