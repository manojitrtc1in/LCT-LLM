#include<bits/stdc++.h>
using namespace std;

namespace Sim {
const int md = 998244353;
 
namespace faq{
 
inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}
 
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}
 
inline int mul(int x, int y) {
  return (long long) x * y % md;
}
 
inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      res = mul(res, x);
    }
  }
  return res;
}
 
inline int inv(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}
 
namespace ntt {
int base = 1, root = -1, max_base = -1;
vector<int> rev = {0, 1}, roots = {0, 1};
 
void init() {
  int temp = md - 1;
  max_base = 0;
  while (temp % 2 == 0) {
    temp >>= 1;
    ++max_base;
  }
  root = 2;
  while (true) {
    if (power(root, 1 << max_base) == 1 && power(root, 1 << max_base - 1) != 1) {
      break;
    }
    ++root;
  }
}
 
void ensure_base(int nbase) {
  if (max_base == -1) {
    init();
  }
  if (nbase <= base) {
    return;
  }
  assert(nbase <= max_base);
  rev.resize(1 << nbase);
  for (int i = 0; i < 1 << nbase; ++i) {
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << nbase - 1;
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = power(root, 1 << max_base - 1 - base);
    for (int i = 1 << base - 1; i < 1 << base; ++i) {
      roots[i << 1] = roots[i];
      roots[i << 1 | 1] = mul(roots[i], z);
    }
    ++base;
  }
}
 
void dft(vector<int> &a) {
  int n = a.size(), zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i < rev[i] >> shift) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = mul(a[j + k + i], roots[i + k]);
        a[j + k] = (x + y) % md;
        a[j + k + i] = (x + md - y) % md;
      }
    }
  }
}
 
vector<int> multiply(vector<int> a, vector<int> b) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int sz = 1 << nbase;
  a.resize(sz);
  b.resize(sz);
  bool equal = a == b;
  dft(a);
  if (equal) {
    b = a;
  } else {
    dft(b);
  }
  int inv_sz = inv(sz);
  for (int i = 0; i < sz; ++i) {
    a[i] = mul(mul(a[i], b[i]), inv_sz);
  }
  reverse(a.begin() + 1, a.end());
  dft(a);
  a.resize(need);
  return a;
}
 
vector<int> inverse(vector<int> a) {
  int n = a.size(), m = n + 1 >> 1;
  if (n == 1) {
    return vector<int>(1, inv(a[0]));
  } else {
    vector<int> b = inverse(vector<int>(a.begin(), a.begin() + m));
    int need = n << 1, nbase = 0;
    while (1 << nbase < need) {
      ++nbase;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    dft(a);
    dft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; ++i) {
      a[i] = mul(mul(md + 2 - mul(a[i], b[i]), b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    dft(a);
    a.resize(n);
    return a;
  }
}
}
 
using ntt::multiply;
using ntt::inverse;
 
vector<int>& operator += (vector<int> &a, const vector<int> &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    add(a[i], b[i]);
  }
  return a;
}
 
vector<int> operator + (const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c += b;
}
 
vector<int>& operator -= (vector<int> &a, const vector<int> &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    sub(a[i], b[i]);
  }
  return a;
}
 
vector<int> operator - (const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c -= b;
}
 
vector<int>& operator *= (vector<int> &a, const vector<int> &b) {
  if (min(a.size(), b.size()) < 128) {
    vector<int> c = a;
    a.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < c.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        add(a[i + j], mul(c[i], b[j]));
      }
    }
  } else {
    a = multiply(a, b);
  }
  return a;
}
 
vector<int> operator * (const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c *= b;
}
 
vector<int>& operator /= (vector<int> &a, const vector<int> &b) {
  int n = a.size(), m = b.size();
  if (n < m) {
    a.clear();
  } else {
    vector<int> c = b;
    reverse(a.begin(), a.end());
    reverse(c.begin(), c.end());
    c.resize(n - m + 1);
    a *= inverse(c);
    a.erase(a.begin() + n - m + 1, a.end());
    reverse(a.begin(), a.end());
  }
  return a;
}
 
vector<int> operator / (const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c /= b;
}
 
vector<int>& operator %= (vector<int> &a, const vector<int> &b) {
  int n = a.size(), m = b.size();
  if (n >= m) {
    vector<int> c = (a / b) * b;
    a.resize(m - 1);
    for (int i = 0; i < m - 1; ++i) {
      sub(a[i], c[i]);
    }
  }
  return a;
}
 
vector<int> operator % (const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c %= b;
}
 
vector<int> derivative(const vector<int> &a) {
  int n = a.size();
  vector<int> b(n - 1);
  for (int i = 1; i < n; ++i) {
    b[i - 1] = mul(a[i], i);
  }
  return b;
}
 
vector<int> primitive(const vector<int> &a) {
  int n = a.size();
  vector<int> b(n + 1), invs(n + 1);
  for (int i = 1; i <= n; ++i) {
    invs[i] = i == 1 ? 1 : mul(md - md / i, invs[md % i]);
    b[i] = mul(a[i - 1], invs[i]);
  }
  return b;
}
 
vector<int> logarithm(const vector<int> &a) {
  vector<int> b = primitive(derivative(a) * inverse(a));
  b.resize(a.size());
  return b;
}
 
vector<int> exponent(const vector<int> &a) {
  vector<int> b(1, 1);
  while (b.size() < a.size()) {
    vector<int> c(a.begin(), a.begin() + min(a.size(), b.size() << 1));
    add(c[0], 1);
    vector<int> old_b = b;
    b.resize(b.size() << 1);
    c -= logarithm(b);
    c *= old_b;
    for (int i = b.size() >> 1; i < b.size(); ++i) {
      b[i] = c[i];
    }
  }
  b.resize(a.size());
  return b;
}
 
vector<int> power(const vector<int> &a, int m) {
  int n = a.size(), p = -1;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    b[0] = !m;
    return b;
  }
  if ((long long) m * p >= n) {
    return b;
  }
  int mu = power(a[p], m), di = inv(a[p]);
  vector<int> c(n - m * p);
  for (int i = 0; i < n - m * p; ++i) {
    c[i] = mul(a[i + p], di);
  }
  c = logarithm(c);
  for (int i = 0; i < n - m * p; ++i) {
    c[i] = mul(c[i], m);
  }
  c = exponent(c);
  for (int i = 0; i < n - m * p; ++i) {
    b[i + m * p] = mul(c[i], mu);
  }
  return b;
}
 
vector<int> sqrt(const vector<int> &a) {
  vector<int> b(1, 1);
  while (b.size() < a.size()) {
    vector<int> c(a.begin(), a.begin() + min(a.size(), b.size() << 1));
    vector<int> old_b = b;
    b.resize(b.size() << 1);
    c *= inverse(b);
    for (int i = b.size() >> 1; i < b.size(); ++i) {
      b[i] = mul(c[i], md + 1 >> 1);
    }
  }
  b.resize(a.size());
  return b;
}
 
vector<int> multiply_all(int l, int r, vector<vector<int>> &all) {
  if (l > r) {
    return vector<int>();
  } else if (l == r) {
    return all[l];
  } else {
    int y = l + r >> 1;
    return multiply_all(l, y, all) * multiply_all(y + 1, r, all);
  }
}
 
vector<int> evaluate(const vector<int> &f, const vector<int> &x) {
  int n = x.size();
  if (!n) {
    return vector<int>();
  }
  vector<vector<int>> up(n * 2);
  for (int i = 0; i < n; ++i) {
    up[i + n] = vector<int>{(md - x[i]) % md, 1};
  }
  for (int i = n - 1; i; --i) {
    up[i] = up[i << 1] * up[i << 1 | 1];
  }
  vector<vector<int>> down(n * 2);
  down[1] = f % up[1];
  for (int i = 2; i < n * 2; ++i) {
    down[i] = down[i >> 1] % up[i];
  }
  vector<int> y(n);
  for (int i = 0; i < n; ++i) {
    y[i] = down[i + n][0];
  }
  return y;
}
 
vector<int> interpolate(const vector<int> &x, const vector<int> &y) {
  int n = x.size();
  vector<vector<int>> up(n * 2);
  for (int i = 0; i < n; ++i) {    up[i + n] = vector<int>{(md - x[i]) % md, 1};
  }
  for (int i = n - 1; i; --i) {
    up[i] = up[i << 1] * up[i << 1 | 1];
  }
  vector<int> a = evaluate(derivative(up[1]), x);
  for (int i = 0; i < n; ++i) {
    a[i] = mul(y[i], inv(a[i]));
  }
  vector<vector<int>> down(n * 2);
  for (int i = 0; i < n; ++i) {
    down[i + n] = vector<int>(1, a[i]);
  }
  for (int i = n - 1; i; --i) {
    down[i] = down[i << 1] * up[i << 1 | 1] + down[i << 1 | 1] * up[i << 1];
  }
  return down[1];
}
}
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
}
template<class T>
bool chmax(T&a, T b){
    if(a < b){
        a = b;
        return 1;
    }
    return 0;
}
template<class T>
bool chmin(T&a, T b){
    if(a > b){
        a = b;
        return 1;
    }
    return 0;
}
template<class T>
void o(const T &a,bool space=false){
    cout << a << (space?' ':'\n');
}


const int mod = 998244353;
template<class T>
void add(T&a,T b){
    a+=b;
    if(a >= mod) a-=mod;
}

template<const int md>
struct ntt{
    inline void add(int &a, int b) { a += b; if(a >= md) a -= md; }
    inline void sub(int &a, int b) { a -= b; if(a < 0) a += md; }
    inline int mul(int a, int b) { return (int)((ll)a*b%md); }
    inline int power(int a, long long b) {
        int res = 1;
        while (b > 0) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }
    inline int inv(int a) {
        a %= md;
        if (a < 0) a += md;
        int b = md, u = 0, v = 1;
        while (a) {
            int t = b / a;
            b -= t * a; swap(a, b);
            u -= t * v; swap(u, v);
        }
        assert(b == 1);
        if (u < 0) u += md;
        return u;
    }
    
    int max_base, root;
    vector<int> dw, idw;
    ntt() {
        int tmp = md - 1;
        max_base = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            max_base++;
        }
        root = 2;
        while (power(root, (md-1)>>1) == 1) root++;
        dw.resize(max_base); idw.resize(max_base);
        rep(i, max_base){
            sub(dw[i], power(root, (md-1) >> (i+2)));
            idw[i] = inv(dw[i]);
        }
    }
    void fft(vector<int> &a, bool inv) {
        const int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        if(!inv){
            for(int m=n;m>>=1;){
                int w = 1;
                for(int s=0,k=0; s<n; s += 2*m){
                    for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
                        int x = a[i], y = mul(a[j], w);
                        a[j] = (x>=y?x-y:x+md-y);
                        a[i] = (x+y>=md?x+y-md:x+y);
                    }
                    w = mul(w, dw[__builtin_ctz(++k)]);
                }
            }
        }
        else{
            for(int m=1;m<n;m*=2){
                int w = 1;
                for(int s=0,k=0; s<n; s += 2*m){
                    for(int i=s, j=s+m ; i < s+m; ++i, ++j) {
                        int x = a[i], y = a[j];
                        a[j] = (x>=y?x-y:x+md-y);
                        a[j] = mul(a[j], w);
                        a[i] = (x+y>=md?x+y-md:x+y);
                    }
                    w = mul(w, idw[__builtin_ctz(++k)]);
                }
            }
        }
    }
    vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
        int need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        int sz = 1 << nbase;
        a.resize(sz);
        b.resize(sz);
        fft(a, 0);
        if (eq) b = a; else fft(b, 0);
        int inv_sz = inv(sz);
        for (int i = 0; i < sz; i++) {
            a[i] = mul(mul(a[i], b[i]), inv_sz);
        }
        fft(a, 1);
        a.resize(need);
        return a;
    }
    vector<int> square(vector<int> a) {
        return multiply(a, a, 1);
    }
};
ntt<998244353>kaede;
ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
typedef vector<int> vi;
vi mul_int(vi a, int M){
    for(auto &b: a) b = (int)((ll)(b) * M) % mod;
    return a;
}
vi mul(vi a, vi b, int eq = 0){
    return kaede.multiply(a, b, eq);
}
vi add(vi a, vi b,int M=-1){
    if(a.size() < b.size()) swap(a,b);
    for(int i=0;i<b.size();i++){
        a[i]+=b[i];
        if(a[i] < 0) a[i] += mod;
        if(a[i] >= mod) a[i] -= mod;
    }
    if(M >= 0 && a.size() > M) a.resize(M);
    return a;
}
vi sub(vi a, vi b,int M=-1){
    if(a.size() < b.size()) a.resize(b.size(),0);
    for(int i=0;i<b.size();i++){
        a[i]-=b[i];
        if(a[i] < 0) a[i] += mod;
        if(a[i] >= mod) a[i] -= mod;
    }
    if(M >= 0 && a.size() > M) a.resize(M);
    return a;
}
vi inv(vi a,int M){
    if(a.empty() || a[0] == 0) return vi();
    vi r[30];
    r[0].pb(modpow(a[0],mod-2));
    int cur = 1;
    int nxt = 1;
    vi vec3;
    while(cur < M){
        int nw = min(cur*2,(int)(a.size()));
        int sz = vec3.size();
        vec3.resize(nw,0);
        for(int t=sz;t<nw;t++){
            vec3[t] = a[t];
        }
        r[nxt] = sub(mul_int(r[nxt-1],2),mul(mul(r[nxt-1],r[nxt-1], 1),vec3));
        r[nxt].resize(r[nxt-1].size()*2);
        nxt++;
        cur *= 2;
    }
    assert(r[nxt-1].size() >= M);
    r[nxt-1].resize(M);
    assert(r[nxt-1].size() == M);
    return r[nxt-1];
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;

    const int N = 1e5+7;

    vector <int> c(N);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x] = 1;
    }   

    using namespace Sim;
    using namespace faq;

    vector <int> one = {1};
    vector <int> two = {2};
    vector <int> four = {4};

    vector <int> nom = two;
    vector <int> den = one + sqrt(one - (four * c));

        

    assert(den.size() == N);
    auto in = inv(den, N);

    auto f = nom * in;

    for (int i = 1; i <= m; ++i) {
        cout << f[i] << endl;
    }   
}