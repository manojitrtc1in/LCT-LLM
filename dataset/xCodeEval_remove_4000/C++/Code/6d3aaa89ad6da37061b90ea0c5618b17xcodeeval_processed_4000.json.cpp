


 
 






using namespace std;



template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}



using li = long long int;
using lu = long long unsigned;
using ld = long double;

using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

struct empty_t {};



int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); }





using rng_t = mt19937;
rng_t global_rng = rng_t(29803);

void random_reset(int seed = time(0), rng_t &rng = global_rng) { rng = rng_t(seed); }

li random(li r, rng_t &rng = global_rng) {
  return uniform_int_distribution<li>(0, r - 1)(rng);
}

li random(li l, li r, rng_t &rng = global_rng) {
  return uniform_int_distribution<li>(l, r)(rng);
}

ld randomDouble(rng_t &rng = global_rng) {
  return uniform_real_distribution<ld>(0.0, 1.0)(rng);
}



template<li M = 998'244'353>
struct Zn {
  static_assert(M > 2, "M > 2");
  static_assert(M < (1ll<<31), "M < (1ll<<31)");
  int value;

  Zn() : value(0) { }

  Zn(int x) : value(x%M) {
    if(value < 0) value += M;
  }

  Zn(li x) : value(x%M) {
    if(value < 0) value += M;
  }

  Zn& operator+=(Zn const& o) {
    value += o.value;
    if(value >= M) value -= M;
    return *this;
  }

  Zn& operator-=(Zn const& o) {
    value += M - o.value;
    if(value >= M) value -= M;
    return *this;
  }

  Zn& operator*=(Zn const& o) {
    value = ((li)value*(li)o.value)%M;
    return *this;
  }

  Zn& operator/=(Zn const& o) {
    return operator*=(o.inverse());
  }

  Zn operator+(Zn const& o) const { return Zn(value + o.value); }
  Zn operator-(Zn const& o) const { return Zn(value - o.value); }
  Zn operator*(Zn const& o) const { return Zn((li)value * (li)o.value); }
  Zn operator/(Zn const& o) const { Zn a = *this; a /= o; return a; }

  Zn inverse() const {
    int a = value, b = M, u = 0, v = 1;
    while (a != 0) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    return Zn(u);
  }

  bool operator==(Zn const& o) const { return value == o.value; }
  bool operator!=(Zn const& o) const { return value != o.value; }
  bool operator<(Zn const& o) const { return value < o.value; }
  bool operator>(Zn const& o) const { return value > o.value; }
  bool operator<=(Zn const& o) const { return value <= o.value; }
  bool operator>=(Zn const& o) const { return value >= o.value; }
};

template<li M>
Zn<M> pow(Zn<M> a, li b) {
  Zn<M> r = 1;
  while(b){
    if(b&1) r = r*a;
    a = a * a;
    b /= 2;
  }
  return r;
}

template<li M>
Zn<M> operator+(int const& x, Zn<M> const& o) { return Zn<M>(x) + o; }
template<li M>
Zn<M> operator+(li const& x, Zn<M> const& o) { return Zn<M>(x) + o; }

template<li M>
Zn<M> operator*(int const& x, Zn<M> const& o) { return Zn<M>(x) * o; }
template<li M>
Zn<M> operator*(li const& x, Zn<M> const& o) { return Zn<M>(x) * o; }

template<li M>
Zn<M> operator/(int const& x, Zn<M> const& o) { return Zn<M>(x) / o; }
template<li M>
Zn<M> operator/(li const& x, Zn<M> const& o) { return Zn<M>(x) / o; }


template<li M>
ostream& operator<<(ostream& ss, Zn<M> const& a) {
  return ss << a.value;
}

template<li M>
istream& operator>>(istream& ss, Zn<M> &a) {
  li x; ss>>x;
  a = Zn<M>(x);
  return ss;
}






template<li M = 998'244'353>
struct factorials {
  vector<Zn<M>> F, IF;

  factorials() {
    F.emplace_back(1); IF.emplace_back(1);
  }

  factorials(int n) {
    F.emplace_back(1); IF.emplace_back(1);
    reserve(n);
  }

  void reserve(int n) {
    if((int)F.size() > n) return;
    n = max<int>(n, 2*F.size());
    F.reserve(n+1);
    int a = F.size();
    for(int i = (a); i <= (int)(n); ++i) F[i] = i * F[i-1];
    IF.resize(n+1);
    IF[n] = 1/F[n];
    for(int i = (n-1); i >= (int)(a); --i) IF[i] = IF[i+1] * (i+1);
  }

  Zn<M> operator[](int n) {
    reserve(n+1);
    return F[n];
  }

  Zn<M> I(int n) {
    reserve(n+1);
    return IF[n];
  }
};

template<li M = 998'244'353>
static factorials<M> Factorials;

template<li M = 998'244'353>
Zn<M> Fact(int n) { return Factorials<M>[n]; }

template<li M = 998'244'353>
Zn<M> IFact(int n) { return Factorials<M>.I(n); }

template<li M = 998'244'353>
Zn<M> SmallInv(int n) {
  assert(n>=1);
  return IFact(n)*Fact(n-1);
}

template<li M = 998'244'353>
Zn<M> cnk(int n, int k) {
  if(k < 0 || k > n) return 0;
  return Fact(n) * IFact(k) * IFact(n-k);
}



template<li M>
struct with_ntt {
  static Zn<M> prim_root;
  static int MAXN;
  static vector<int> roots;
  static vector<int> rroots;

  static void calc_roots(int N) {
    if(N <= MAXN) return;
    MAXN = N;
    li h = pow(prim_root, (998'244'353 -1)/N).value;
    li ih = (1/Zn<M>(h)).value;
    li w = 1;
    roots.resize(N);
    for(int i = 0; i < (int)(N); ++i) {
      roots[i] = w;
      w = (w*h)%M;
    }
    w = 1;
    rroots.resize(N);
    for(int i = 0; i < (int)(N); ++i) {
      rroots[i] = w;
      w = (w*ih)%M;
    }
  }

  static void ntt(int N, vector<int>& a, bool reverse) {
    assert((N & (N - 1)) == 0);
    calc_roots(max(N, 1<<17));
    vector<int> const& id0 = reverse ? rroots : roots;

    for(int m = N; m >= 2; m /= 2){
      int mh = m/2;
      int im = MAXN/m;
      for(int i = 0; i < (int)(mh); ++i){
        li w = id0[im*i];
        for(int j = i; j < N; j += m){
          int k = j+mh;
          li x = (M+a[j]-a[k]);
          if(x>=M) x -= M;
          a[j] += a[k];
          if(a[j]>=M) a[j] -= M;
          a[k] = (w*x) % M;
        }
      }
    }
    int i = 0;
    for(int j = (1); j <= (int)(N-2); ++j){
      for(int k = N/2; k > (i^=k); k /= 2);
      if(j<i) swap(a[i],a[j]);
    }
    if(reverse) {
      li IN = (1/Zn<M>(N)).value;
      for(int j = 0; j < (int)(N); ++j) a[j] = ((li)a[j]*IN) % M;
    }
  }
};

template<li M>
int with_ntt<M>::MAXN = 0;

template<li M>
vector<int> with_ntt<M>::roots;

template<li M>
vector<int> with_ntt<M>::rroots;

template<>
Zn<119*(1<<23) + 1> with_ntt<119*(1<<23) + 1>::prim_root = 15311432;

template<li M = 998'244'353>
struct id1 {
  vector<Zn<M>> A;

  id1() { }

  id1(int const& x) {
    A = {x};
  }

  id1(li const& x) {
    A = {x};
  }

  id1(Zn<M> const& x) {
    A = {x};
  }

  void truncate() {
    while(!A.empty() && A.back() == 0) A.pop_back();
  }

  void truncate(int n) {
    while(!A.empty() && (A.back() == 0 || (int)A.size() > n)) A.pop_back();
  }

  Zn<M>& operator[](int i) {
    while(i >= (int)A.size()) A.push_back(0);
    return A[i];
  }

  Zn<M> operator[](int i) const {
    return i<(int)A.size()?A[i]:0;
  }

  int degree() {
    truncate();
    return (int)A.size() - 1;
  }

  id1& operator+=(id1 const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(int i = 0; i < (int)(n); ++i) A[i] += o.A[i];
    truncate();
    return *this;
  }

  id1 operator+(id1 const& o) const {
    id1 r = *this;
    r += o;
    return r;
  }

  id1& operator-=(id1 const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(int i = 0; i < (int)(n); ++i) A[i] -= o.A[i];
    truncate();
    return *this;
  }

  id1 operator-(id1 const& o) const {
    id1 r = *this;
    r -= o;
    return r;
  }

  static id1 mul(id1 const& a, id1 const& b, int n) {
    int m = 1; while(m < (int)(a.A.size()+b.A.size()-1)) m *= 2;
    static vector<int> aa, bb;
    if((int)aa.size() < m) aa.resize(m);
    if((int)bb.size() < m) bb.resize(m);
    memset(aa.data(),0,m*sizeof(int));
    memset(bb.data(),0,m*sizeof(int));
    for(int i = 0; i < (int)(min(m,(int)a.A.size())); ++i) aa[i] = a.A[i].value;
    for(int i = 0; i < (int)(min(m,(int)b.A.size())); ++i) bb[i] = b.A[i].value;
    with_ntt<M>::ntt(m,aa,0);
    with_ntt<M>::ntt(m,bb,0);
    for(int i = 0; i < (int)(m); ++i) aa[i] = ((li)aa[i]*(li)bb[i]) % M;
    with_ntt<M>::ntt(m,aa,1);
    id1 r;
    r.A.resize(m);
    for(int i = 0; i < (int)(m); ++i) r.A[i] = aa[i];
    r.truncate(n);
    return r;
  }

  id1 operator*(id1 const& o) const {
    return mul(*this, o, A.size() + o.A.size());
  }

  id1& operator*=(id1 const& o) {
    return *this = (*this) * o;
  }

  id1 operator*(Zn<M> const& o) const {
    id1 r = *this; r *= o;
    return r;
  }

  id1& operator*=(Zn<M> const& o) {
    for(int i = 0; i < (int)((int)A.size()); ++i) A[i] *= o;
    return *this;
  }

  id1 operator/(Zn<M> const& o) const {
    auto io = 1/o;
    id1 r = *this; r *= io;
    return r;
  }

  id1& operator/=(Zn<M> const& o) {
    auto io = 1/o;
    for(int i = 0; i < (int)((int)A.size()); ++i) A[i] *= io;
    return *this;
  }

  static id1 inverse(id1 const& a, int n) {
    assert(a[0] != 0);
    id1 b = 1/a[0];
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      b = mul(b, id1(2) - mul(a,b,m), m);
    }
    b.truncate(n);
    return b;
  }

  static id1 power(id1 a, int k, int n) {
    if(k == 1) return a;
    id1 r = 1;
    while(k) {
      if(k&1) r = mul(r,a,n);
      a = mul(a,a,n);
      k /= 2;
    }
    return r;
  }

  static id1 sqroot(id1 const& a, int n) {
    assert(a[0] == 1);
    id1 b = 1;
    id1 c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, id1(2) - mul(b,c,m), m);
      b = (b + mul(a,c,m)) / Zn<M>(2);
      c = mul(c, id1(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

  static id1 root(id1 const& a, int k, int n) {
    assert(a[0] == 1);
    id1 b = 1;
    id1 c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, id1(2) - mul(b,c,m), m);
      auto ck = power(c, k, m) / Zn<M>(k);
      b = mul(b, id1(Zn<M>(k-1)/Zn<M>(k)) + mul(a, ck, m), m);
      c = mul(c, id1(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

};

using ZN = Zn<998'244'353>;
using PZN = id1<998'244'353>;

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  li n,m; cin>>n>>m; m+=1;
  vi c(n);

  for(int i = 0; i < (int)(n); ++i) cin >> c[i];

  PZN d;
  d[0] = 1;
  for(int i = 0; i < (int)(n); ++i) if(c[i] <= m) d[c[i]] = -4;
  PZN b = PZN::sqroot(d, m);
  b[0] += 1;
  b /= ZN(2);

  PZN ib = PZN::inverse(b, m);

  for(li i = (1); i <= (li)(m-1); ++i) cout << ib[i] << '\n';
  cout << flush;

  return 0;
}