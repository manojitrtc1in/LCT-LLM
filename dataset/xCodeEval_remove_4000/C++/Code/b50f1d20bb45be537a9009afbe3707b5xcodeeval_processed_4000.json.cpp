



using namespace std;
template <typename T> void in(T &x) {
  T c = gc(); while(((c < 48) || (c > 57)) && (c!='-')) c = gc();
  bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=gc());
  for(;c > 47 && c < 58;c=gc()) x = (x*10) + (c - 48); if(neg)  x = -x;
}



LL expo(LL base, LL e, LL mod) {
  LL res = 1;
  while(e > 0) {
    if(e % 2) res = res * base % mod;
    base = base * base % mod;
    e /= 2;
  }
  return res;
}
LL FindPr(LL mod) {
  vector<LL> divs;
  LL temp = mod - 1;
  for(LL d = 2; d*d <= temp; d++) {
    if(temp % d == 0) {
      divs.push_back(d);
      int cnt = 0;
      while(temp % d == 0) temp /= d, cnt++;
    }
  }
  if(temp > 1) divs.push_back(temp);
  for(LL i = 2; ; i++) {
    bool ok = true;
    for(LL p: divs) {
      LL pwr = (mod - 1) / p;
      if(expo(i, pwr, mod) == 1) {
        ok = false;
        break;
      }
    }
    if(ok) {
      return i;
    }
  }
  return -1;
}

template<typename T>
ostream& operator<<(ostream &os, vector<T> v) {
  os << "[";
  for(int i = 0; i < v.size(); i++) {
    if(i) os << ", "; os << v[i];
  }
  os << "]";
  return os;
}




template<typename T>
struct NTT {
  T mod, pr, N;
  vector<T> Wn, inv_Wn;
  void BitReverse(vector<T> &A) const {
    int n = A.size();
    for(int i = 1, j = 0; i < n; i++) {
      int bit = n >> 1;
      for(; j >= bit; bit >>= 1) j -= bit;
      j += bit;
      if(i < j) swap(A[i], A[j]);
    }
  }
  void Ntt(vector<T> &A, bool invert) {
    long long n = A.size();
    BitReverse(A);
    T w, temp;
    

    for(int len = 2, P = 1; len <= n; len *= 2, P++) {
      

      int half = len/2, mm = N - P;
      for(int i = 0; i < n; i += len) {
        for(int j = 0; j < half; j++) {
          w = invert ? inv_Wn[j << mm] : Wn[j << mm];
          T u = A[i + j], v = (A[i + j + half] * w) % mod;
          A[i + j] = u + v < mod ? u + v : u + v - mod;
          A[i + j + half] = u - v < 0 ? (u - v + mod) : (u - v);
        }
      }
    }
    if(invert) {
      T x = expo((long long)n, mod - 2, mod);
      for(int i = 0; i < n; i++)
        A[i] = A[i] * x % mod;
    }
  }
  vector<T> Multiply(vector<T> fa, vector<T> fb) {
    int n = fa.size() + fb.size() - 1, p = 1;
    while(p < n) p <<= 1;
    fa.resize(p), fb.resize(p);
    Ntt(fa, false);
    Ntt(fb, false);
    vector<T> fc(p);
    for(int i = 0; i < p; i++) {
      fc[i] = fa[i] * fb[i] % mod;
    }
    Ntt(fc, true);
    return fc;
  }
  vector<T>& SelfSquare(vector<T> &fa) {
    int n = fa.size() + fa.size() - 1, p = 1;
    while(p < n) p <<= 1;
    fa.resize(p);
    Ntt(fa, false);
    for(auto &x: fa) x = (x * x) % mod;
    Ntt(fa, true);
    return fa;
  }
  NTT(T _mod, T _pr) : mod(_mod), pr(_pr) {
    N = 0;
    T temp = _mod - 1;
    while(temp % 2 == 0) temp /= 2, N++;
    Wn.resize(1 << N), inv_Wn.resize(1 << N);
    Wn[0] = inv_Wn[0] = 1;
    T wn = expo(pr, (mod - 1)/(1 << N), mod);
    T id7 = expo(wn, mod - 2, mod);
    for(int i = 1; i < Wn.size(); i++) {
      Wn[i] = Wn[i-1] * wn % mod;
      inv_Wn[i] = inv_Wn[i-1] * id7 % mod;
    }
  }
};






template<typename T>
vector<T> Inverse(const vector<T> &A, int deg, T mod, NTT<T> &ntt) {
  int n = 1;
  vector<T> g;
  g.push_back(expo(A[0], mod - 2, mod));
  while(n < deg) {
    n <<= 1;
    vector<T> t = g;
    ntt.SelfSquare(t);
    for(auto &x: g) x = (x << 1) % mod;
    t = ntt.Multiply(vector<T>(A.begin(),
          A.begin() + min((int)A.size(), n)), t);
    g.resize(n, 0);
    for(int i = 0; i < n && i < t.size(); i++)
      g[i] = (g[i] - t[i] + mod) % mod;
  }
  return vector<T>(g.begin(), g.begin() + deg);
}






template<typename T>
vector<T> PolyDivision(vector<T> A, vector<T> B, T mod, NTT<T> &ntt) {
  while(B.size() > 0 and B.back() == 0) B.pop_back(); 

  if(A.size() < B.size()) return {0};
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  int m = A.size(), n = B.size();
  B = Inverse(B, m - n + 1, mod, ntt);
  auto res = ntt.Multiply(A, B);
  res.resize(m - n + 1);
  reverse(res.begin(), res.end());
  return res;
}






template<typename T>
vector<T> PolyMod(vector<T> A, vector<T> B, T mod, NTT<T> &ntt) {
  if(A.size() < B.size()) return A;
  vector<T> Q = PolyDivision(A, B, mod, ntt);
  Q = ntt.Multiply(Q, B);
  int n = A.size();
  Q.resize(n);
  for(int i = 0; i < n; i++) {
    A[i] = (A[i] - Q[i] + mod) % mod;
  }
  while(A.size() > 1 and A.back() == 0) A.pop_back();
  return A;
}






vector<LL> hack_v;
int hack_n;

void Go(vector<LL> &M, NTT<LL> &ntt) {
  hack_v = M;
  while(hack_v.size() > 0 and hack_v.back() == 0) hack_v.pop_back();
  reverse(hack_v.begin(), hack_v.end());
  hack_n = hack_v.size();
  hack_v = Inverse(hack_v, 1 << 16, ntt.mod, ntt);
}

template<typename T>
vector<T> id0(vector<T> A, T mod, NTT<T> &ntt) {
  

  reverse(A.begin(), A.end());
  

  int m = A.size();
  vector<T> B(hack_v.begin(), hack_v.begin() + m - hack_n + 1);
  auto res = ntt.Multiply(A, B);
  res.resize(m - hack_n + 1);
  reverse(res.begin(), res.end());
  return res;
}

template<typename T>
vector<T>& id3(vector<T> &A, const vector<T> &B, T mod, NTT<T> &ntt) {
  if(A.size() < B.size()) return A;
  

  vector<T> Q = id0(A, mod, ntt);
  Q = ntt.Multiply(Q, B);
  int n = A.size();
  Q.resize(n);
  for(int i = 0; i < n; i++) {
    A[i] = (A[i] - Q[i] + mod) % mod;
  }
  while(A.size() > 1 and A.back() == 0) A.pop_back();
  return A;
}

template<typename T>
vector<T> id6(const vector<T> &base, LL e, const vector<T> &mod,
    NTT<T> &ntt) {
  if(e == 0) return {1};
  else if(e & 1ll) {
    vector<T> res = ntt.Multiply(id6(base, e - 1, mod, ntt), base);
    id3(res, mod, ntt.mod, ntt);
    return res;
  } else {
    vector<T> res = id6(base, e / 2, mod, ntt);
    ntt.SelfSquare(res);
    id3(res, mod, ntt.mod, ntt);
    return res;
  }
}

void RNG() {
  const LL mod = 104857601; 

  LL pr = FindPr(mod);
  LL n, k;
  scanf("%lld %lld", &k, &n);
  vector<LL> A(k), C(k);
  for(int i = 0; i < k; i++) scanf("%lld", &A[i]);
  for(int i = 0; i < k; i++) scanf("%lld", &C[i]);
  n--;
  if(n < k) {
    printf("%lld\n", A[n]);
    return ;
  }
  vector<LL> Q(k + 1);
  Q[0] = 1;
  for(int i = 0; i < C.size(); i++) {
    Q[i + 1] = -C[i];
  }
  vector<LL> M = Q;
  reverse(M.begin(), M.end());
  NTT<LL> ntt(mod, pr);
  vector<LL> res = {1};
  vector<LL> base = {0, 1};
  Go(M, ntt);
  res = id6(base, n, M, ntt);
  LL ans = 0;
  for(int i = 0; i < k; i++) {
    ans += (A[i] * res[i]) % mod;
  }
  ans %= mod;
  printf("%lld\n", ans);
}



void id8() {
  const int MAXN = 5 + (1e5);
  const LL mod = 663224321;
  NTT<LL> ntt(mod, 3);
  vector<LL> h, g;
  vector<int> facts(MAXN), ifacts(MAXN);
  {
    facts[0] = 1;
    for(LL i = 1; i < facts.size(); i++) facts[i] = (facts[i - 1] * i) % mod;
    ifacts[MAXN-1] = expo(facts[MAXN-1], mod - 2, mod);
    for(LL i = MAXN - 2; i >= 0; i--) {
      ifacts[i] = ifacts[i + 1] * (i + 1) % mod;
    }
    assert(ifacts[2] * facts[2] % mod == 1);
  }
  h.resize(MAXN); g.resize(MAXN);
  for(int i = 0; i < MAXN; i++) {
    h[i] = expo(2ll, (i*1ll*(i-1))/2, mod);
    h[i] *= ifacts[i];
    h[i] %= mod;
    g[i] = h[i];
    h[i] = i * h[i] % mod;
  }
  vector<LL> invG = Inverse(g, MAXN, mod, ntt);
  vector<LL> f = ntt.Multiply(h, invG);
  for(int i = 1; i < MAXN; i++){
    f[i] *= facts[i-1];
    f[i] %= mod;
    if(f[i] < 0) f[i] += mod;
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", f[x]);
  }
}

void PolyEval() {
  const LL mod = 786433;
  const LL pr = 10;
  NTT<long long> Ntt(mod, pr);
  vector<LL> arr(mod + 1), ans(mod + 1);
  int n;
  

  int p = 18;
  in(n);
  for(int i = 0; i <= n; i++) {
    in(arr[i]);
  }
  ans[0] = arr[0];
  vector<LL> ff[3];
  for(int i = 0; i < 3; i++) {
    ff[i].resize(1 << p);
    for(int j = i, idx = 0; j <= n; j += 3, idx++)
      ff[i][idx] = arr[j];
  }
  Ntt.Ntt(ff[0], false);
  Ntt.Ntt(ff[1], false);
  Ntt.Ntt(ff[2], false);
  {
    LL g = 1;
    int nn = 1 << 18;
    for(int i = 0; i < mod - 1; i++) {
      ans[g] = ff[0][i % nn];
      ans[g] += g * ff[1][i % nn] % mod;
      ans[g] += (g * g % mod) * ff[2][i % nn] % mod;
      ans[g] %= mod;
      g = g * pr % mod;
    }
  }
  int q, x;
  in(q);
  while(q--) {
    in(x);
    printf("%lld\n", ans[x]);
  }
}

template<typename T>
void id1(int l, int r, int base, vector<T> &ans, vector<T> &C, NTT<T> &ntt) {
  if(r - l == 1) {
    if(l > base) {
      ans[l] = ans[l] * expo((LL)l, ntt.mod - 2, ntt.mod) % ntt.mod;
    }
    return ;
  }
  int mid = (l + r) >> 1;
  id1(l, mid, base, ans, C, ntt);
  int sz = mid - l;
  vector<LL> aa(ans.begin() + l, ans.begin() + mid);
  vector<LL> bb(C.begin() + 1, C.begin() + 1 + 2 * aa.size());
  vector<LL> res = ntt.Multiply(aa, bb);
  for(int i = mid, j = aa.size() - 1; i < r; i++, j++) {
    if(i > base) {
      ans[i] += res[j], ans[i] -= ans[i] >= ntt.mod ? ntt.mod : 0;
    }
  }
  id1(mid, r, base, ans, C, ntt);
}

void id5() {
  const LL mod = 924844033;
  const int limit = 1 << 17;
  vector<LL> facts(limit), ifacts(limit);
  {
    facts[0] = 1;
    for(LL i = 1; i < limit; i++) facts[i] = i * facts[i - 1] % mod;
    ifacts[limit - 1] = expo(facts[limit - 1], mod - 2, mod);
    for(LL i = limit - 2; i >= 0; i--) ifacts[i] = (i + 1) * ifacts[i + 1] % mod;
    assert(facts[2] * ifacts[2] % mod == 1);
  }
  NTT<LL> ntt(mod, FindPr(mod));
  int n, m;
  in(n), in(m);
  vector<vector<LL> > g(limit + 1, vector<LL>(m + 1, 0));
  g[1][1] = 1;
  for(int i = 2; i < g.size(); i++) {
    g[i][1] = 1;
    for(int j = 2; j < g[i].size(); j++) {
      g[i][j] = (g[i-1][j-1] + g[i-1][j] * j) % mod;
    }
  }
  for(int i = 1; i < g.size(); i++) {
    g[i][m] = (g[i][m] * facts[m]) % mod;
  }
  vector<LL> C(limit), h(limit);
  {
    h[0] = 1;
    if(m == 1) h[m] = 1;
    else {
      h[m] = (expo(m, m - 2, mod) * g[m][m] % mod) * ifacts[m] % mod;
    }
    C[1] = g[1][m];
    for(LL i = 2; i < limit; i++) {
      C[i] = (expo(i, i - 2, mod) * g[i][m] % mod) * ifacts[i - 1] % mod;
    }
  }
  id1(0, limit, m, h, C, ntt);
  for(int i = 1; i <= n; i++) {
    LL ans = h[i] * facts[i] % mod;
    printf("%lld\n", ans);
  }
}



template<typename T>
vector<T> id2(const vector<T> &A, int deg, NTT<T> &ntt) {
  vector<T> res;
  LL two = expo(2ll, ntt.mod - 2, ntt.mod);
  res.push_back(1);
  int n = 1;
  while(n < deg) {
    n <<= 1;
    vector<T> inv = Inverse(res, n, ntt.mod, ntt);
    ntt.SelfSquare(res);
    int up = min((int)A.size(), n);
    if(res.size() < up) res.resize(up);
    for(int i = 0; i < up; i++)
      res[i] += A[i], res[i] >= ntt.mod ? res[i] - ntt.mod : res[i];
    res = ntt.Multiply(res, inv);
    res.resize(n);
    for(T &x: res) x = x * two % ntt.mod;
  }
  return res;
}



void id4() {
  const int limit = 1 << 17;
  const LL mod = 998244353;
  vector<LL> C(limit);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> inp(n);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x), C[x] = mod - 4;
  }
  C[0] = 1;
  NTT<LL> ntt(mod, FindPr(mod));
  C = id2(C, limit, ntt);
  C[0]++;
  C = Inverse(C, limit, mod, ntt);
  for(LL &x: C) x = x * 2 % mod;
  for(int i = 1; i <= m; i++) {
    printf("%lld\n", C[i]);
  }
}

int main() {
  

  

  

  

  id4();
  return 0;
}
