















































namespace atcoder {

namespace internal {





int id2(int n) {
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


}  







namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct id8 {
  public:
    id8() : id8(0) {}
    id8(int n) : id8(std::vector<S>(n, e())) {}
    id8(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  



















namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  







namespace atcoder {



template <class T> struct id6 {
    using U = internal::to_unsigned_t<T>;

  public:
    id6() : _n(0) {}
    id6(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  















namespace atcoder {

namespace internal {

std::vector<int> id9(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> id7(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}









template <int id0 = 10, int id3 = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < id0) {
        return id9(s);
    }
    if (n < id3) {
        return id7(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> id5(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            id5[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> id1;
        id1.reserve(m);
        for (int v : sa) {
            if (id5[v] != -1) id1.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[id5[id1[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = id1[i - 1], r = id1[i];
            int end_l = (id5[l] + 1 < m) ? lms[id5[l] + 1] : n;
            int end_r = (id5[r] + 1 < m) ? lms[id5[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[id5[id1[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<id0, id3>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            id1[i] = lms[rec_sa[i]];
        }
        induce(id1);
    }
    return sa;
}

}  


std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}









template <class T>
std::vector<int> id4(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> id4(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return id4(s2, sa);
}









template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  










int op(int x, int y) {
  return std::min(x, y);
}

int unit() {
  return (int) 1e9;
}

using id8 = atcoder::id8<int, op, unit>;

using namespace std;

using int64 = int64_t;
using ii = pair<int, int>;

struct PalindromeSearcher {
  string s;
  int n;
  vector<int> d1;
  vector<int> d2;
  int first;
  int pright;
  int pleft;
  set<int> active;
  vector<int> p;
  vector<int> lcp;
  vector<int> where;
  vector<vector<int>> diesAt;
  id8 id10;
  id8 alive;

  explicit PalindromeSearcher(string s) : s(s) {
    n = sz(s);

    

    d1.assign(n, 0);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
      while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
      d1[i] = k;
      if (i+k-1 > r)
        l = i-k+1,  r = i+k-1;
    }

    d2.assign(n, 0);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
      while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
      d2[i] = k;
      if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }
    first = 0;
    pright = 0;
    active.insert(0);
    diesAt.assign(n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
      diesAt[i + d1[i]].push_back(2 * i);
      if (d2[i] > 0) {
        diesAt[i + d2[i]].push_back(2 * i - 1);
      }
    }

    p = atcoder::suffix_array(s);
    lcp = atcoder::id4(s, p);
    id10 = id8(lcp);
    where.assign(n, -1);
    for (int i = 0; i < n; ++i) where[p[i]] = i;

    alive = id8(n);
    alive.set(where[0], 0);
    pleft = 0;
  }

  bool addsNewPalindrome(int left, int right) {
    while (pright < right) {
      ++pright;
      if (pright < n) {
        alive.set(where[pright], pright);
        active.insert(2 * pright);
        if (d2[pright] > 0) {
          active.insert(2 * pright - 1);
        }
      }
      for (int x : diesAt[pright]) {
        active.erase(x);
      }
    }
    while (first < left + right) {
      active.erase(first);
      ++first;
    }
    while (pleft < left) {
      alive.set(where[pleft], unit());
      ++pleft;
    }
    assert(pleft == left);
    assert(pright == right);
    assert(first == left + right);
    if (active.empty()) return false;
    int cur = *active.begin();
    int start = cur - right;
    

    auto enough = [&](int val) { return val >= right - start + 1; };
    int from = id10.min_left(where[start], enough);
    int to = id10.max_right(where[start], enough);
    int pos = alive.prod(from, to + 1);
    assert(pos <= start);
    return pos == start;
  }
};

class HUporotiePalindromi {
 public:
  void solveOne() {
    int q;
    cin >> q;
    vector<int> ops;
    string s;
    for (int iq = 0; iq < q; ++iq) {
      string qs;
      cin >> qs;
      if (qs == "push") {
        char c;
        cin >> c;
        s += c;
        ops.push_back(1);
      } else if (qs == "pop") {
        ops.push_back(0);
      } else {
        assert(false);
      }
    }

    string sr = s;
    reverse(all(sr));
    PalindromeSearcher p(s);
    PalindromeSearcher pr(sr);

    int left = 0;
    int right = 0;
    vector<int> deltas(q);
    for (int iq = 0; iq < q; ++iq) {
      if (ops[iq] == 1) {
        if (p.addsNewPalindrome(left, right)) ++deltas[iq];
        ++right;
      } else {
        ++left;
      }
    }
    for (int iq = q - 1; iq >= 0; --iq) {
      if (ops[iq] == 1) {
        --right;
      } else {
        if (pr.addsNewPalindrome(sz(s) - right, sz(s) - left)) --deltas[iq];
        --left;
      }
    }

    int res = 0;
    for (int iq = 0; iq < q; ++iq) {
      res += deltas[iq];
      cout << res << "\n";
    }
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      

      solveOne();
      

    }
  }
};




int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    HUporotiePalindromi solver;


    solver.solve();
    return 0;
}