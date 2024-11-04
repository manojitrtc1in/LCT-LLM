
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

















































































































































































































































































































































































































































































































































































































bool __hack = std::ios::sync_with_stdio(false);


auto id1 = cin.tie(nullptr);


















namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

template<class T>
vector<T> next_vec(istream& in, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; ++i) {
    ret[i] = next<T>(in);
  }
  return ret;
}























template<class T>
vector<T> getReverse(int n, const T MOD) {
  vector<T> res(n, 0);
  if (n > 1) {
    res[1] = 1;
  }
  for (int i = 2; i < n; ++i) {
    res[i] = (MOD - MOD / i * res[((int) (MOD % i))] % MOD) % MOD;
  }
  return res;
}




template<class T>
vector<T> id2(int n, const T MOD) {
    vector<T> res(n);
    res[0] = 1;
    for (int i = 1; i < n; ++i) {
        res[i] = (T)((res[i-1] * 1LL * i) % MOD);
    }
    return res;
}


template<class T>
vector<T> id3(int n, const T MOD) {
    vector<T> revs = getReverse(n, MOD);
    vector<T> res(n);
    res[0] = 1;
    for (int i = 1; i < n; ++i) {
        res[i] = (T)((res[i-1] * 1LL * revs[i]) % MOD);
    }
    return res;
}


template<class T>
T pow(T x, T p, const T MOD) {
    T res = 1;
    for (T i = p; i > 0; i >>= 1) {
        if (i & 1) {
            res = (T)((res * 1LL * x) % MOD);
        }
        x = (T)((x * 1LL * x) % MOD);
    }
    return res;
}














































const int MAXN = 5000004;













const int64_t MOD = 1000000007;

vec<int64_t> fs = id2(MAXN, MOD);
vec<int64_t> rfs = id3(MAXN, MOD);

int64_t C(int n, int k) {
  if (n < 0 || k < 0) {
    while (true);
  }
  int64_t res = fs[n] * rfs[k] % MOD;
  if (n < k) {
    while (1);
  }
  res *= rfs[n - k];
  res %= MOD;
  return res;
}

int64_t process(int left, int right, const vec<pair<int, int>>& ps, int t, int n) {
  int64_t res = 1;
  FOR(i, ps.size()) {
    int curTime = ps[i].first - t - 1;
    t = ps[i].first;
    int pos = ps[i].second;
    if (pos < left) {
      int id4 = left - pos - 1;
      if (id4 > curTime) {
        return 0;
      }
      res *= C(curTime, id4);
      res %= MOD;
      left = pos;
      right += curTime - id4;
    } else if (pos > right) {
      int id0 = pos - right - 1;
      if (id0 > curTime) {
        return 0;
      }
      res *= C(curTime, id0);
      res %= MOD;
      right = pos;
      left -= (curTime - id0);
    } else {
      return 0;
    }
    if (left < 0 || right >= n) {
      return 0;
    }
  }

  int restLeft = left;
  int restTotal = restLeft + (n - 1 - right);
  res = res * C(restTotal, restLeft);
  res %= MOD;
  return res;
}

void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto a = next_vec<int>(in, n);

  bool all0 = all_of(all(a), [] (int x) { return x == 0; });
  if (all0) {
    out << pow<int64_t>(2, n - 1, MOD) << "\n";
    return;
  }

  vec<pair<int, int>> ps;
  FOR(i, n) {
    if (a[i]) {
      ps.push_back({a[i], i});
    }
  }
  

  sort(all(ps));
  int64_t res = 0;
  auto f = ps[0];

  ps.erase(ps.begin());
  int64_t add = 1;
  if (f.first - 1 >= 1) {
    add = pow<int64_t>(2, f.first - 2, MOD);
  }
  if (f.second - (f.first - 1) >= 0) {
    res = res + (process(f.second - (f.first - 1), f.second, ps, f.first, n) * add) % MOD;
  }
  if (f.first > 1 && f.second + (f.first - 1) < n) {
    res = res + (process(f.second, f.second + (f.first - 1), ps, f.first, n) * add) % MOD;
  }
  res %= MOD;
  out << res << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

