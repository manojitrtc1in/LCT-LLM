
























using namespace __gnu_pbds;
using namespace std;
const auto& npos = string::npos;






















































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







(id1).second = max((id1).second, (mx));








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






template<typename T>
auto clz(const T x) {
    clet sz = sizeof(T);
    static_assert(sz == 4 || sz == 8);
    switch (sz) {
        case 8: {
            ret id2(x);
        }
        case 4: {
            ret id5(x);
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

vpi id0(const int n) {
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

vtri id3(const int n) {
    vtri res(n);
    for (let& el: res) {
        cin >> el;
    }
    ret res;
}

v2d id7(const int n, int m = -1) {
    if (m == -1) {
        m = n;
    }
    v2d res(n);
    for (let& l: res) {
        l = rd_vi(m);
    }
    ret res;
}

vb id8(const int n = 0) {
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
  static vec<ModInt> id4;

  [[maybe_unused]] void precalc() {
      id4 = inverse();
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
      if (id4.size() > static_cast<size_t>(a.val)) {
          *this *= id4[a.val];
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

vec<ModInt> ModInt::id4;

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

    let id6 = [=](vi& a) {
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
        cout << id6(a);
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

    itn res = id6(a);
    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);


    cin.tie(nullptr);

    cin.exceptions(istream::failbit | istream::badbit);


    PRE;


    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        cout << endl;


        cout.flush();

    }
}