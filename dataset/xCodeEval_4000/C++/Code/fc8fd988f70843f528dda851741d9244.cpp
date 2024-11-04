


 #include <stdio.h>
 #include <bits/stdc++.h>






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
  li value;

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
    (value *= o.value) %= M;
    return *this;
  }

  Zn& operator/=(Zn const& o) {
    return operator*=(o.inverse());
  }

  Zn operator+(Zn const& o) const { return Zn(value + o.value); }
  Zn operator-(Zn const& o) const { return Zn(value - o.value); }
  Zn operator*(Zn const& o) const { return Zn(value * o.value); }
  Zn operator/(Zn const& o) const { Zn a = *this; a /= o; return a; }

  Zn inverse() const {
    return pow(*this, 998'244'353 -2);
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
    for(li i = (a); i <= (li)(n); ++i) F[i] = i * F[i-1];
    IF.resize(n+1);
    IF[n] = 1/F[n];
    for(li i = (n-1); i >= (li)(a); --i) IF[i] = IF[i+1] * (i+1);
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

  static void ntt(vector<Zn<M>>& a, bool reverse) {
    li N = a.size();
    Zn<M> h = pow(prim_root, (998'244'353 -1)/N);
    if(reverse) h = 1/h;
    for(li m = N; m >= 2; m /= 2){
      li mh = m/2;
      Zn<M> w = 1;
      for(li i = 0; i < (li)(mh); ++i){
        for(li j = i; j < N; j += m){
          li k = j+mh;
          li x = (a[j].value-a[k].value);
          a[j] += a[k];
          a[k] = (w*x);
        }
        w = (w*h);
      }
      h = (h*h);
    }
    li i = 0;
    for(li j = (1); j <= (li)(N-2); ++j){
      for(li k = N/2; k > (i^=k); k /= 2);
      if(j<i) swap(a[i],a[j]);
    }
    if(reverse) {
      Zn<M> IN = 1/Zn<M>(N);
      for(li j = 0; j < (li)(N); ++j) a[j] *= IN;
    }
  }
};

template<>
Zn<119*(1<<23) + 1> with_ntt<119*(1<<23) + 1>::prim_root = 15311432;

template<li M = 998'244'353>
struct polymod {
  vector<Zn<M>> A;

  polymod() { }

  polymod(int const& x) {
    A = {x};
  }

  polymod(li const& x) {
    A = {x};
  }

  polymod(Zn<M> const& x) {
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

  polymod& operator+=(polymod const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(li i = 0; i < (li)(n); ++i) A[i] += o.A[i];
    truncate();
    return *this;
  }

  polymod operator+(polymod const& o) const {
    polymod r = *this;
    r += o;
    return r;
  }

  polymod& operator-=(polymod const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(li i = 0; i < (li)(n); ++i) A[i] -= o.A[i];
    truncate();
    return *this;
  }

  polymod operator-(polymod const& o) const {
    polymod r = *this;
    r -= o;
    return r;
  }

  static polymod mul(polymod const& a, polymod const& b, int n) {
    int m = 1; while(m < (int)(a.A.size()+b.A.size()-1)) m *= 2;
    vector<Zn<M>> aa = a.A, bb = b.A;
    while((int)aa.size() < m) aa.emplace_back();
    while((int)aa.size() > m) aa.pop_back();
    while((int)bb.size() < m) bb.emplace_back();
    while((int)bb.size() > m) bb.pop_back();
    with_ntt<M>::ntt(aa,0);
    with_ntt<M>::ntt(bb,0);
    for(li i = 0; i < (li)(m); ++i) aa[i] *= bb[i];
    with_ntt<M>::ntt(aa,1);
    polymod r; r.A = move(aa);
    r.truncate(n);
    return r;
  }

  polymod operator*(polymod const& o) const {
    return mul(*this, o, A.size() + o.A.size());
  }

  polymod& operator*=(polymod const& o) {
    return *this = (*this) * o;
  }

  polymod operator*(Zn<M> const& o) const {
    polymod r = *this; r *= o;
    return r;
  }

  polymod& operator*=(Zn<M> const& o) {
    for(li i = 0; i < (li)((int)A.size()); ++i) A[i] *= o;
    return *this;
  }

  polymod operator/(Zn<M> const& o) const {
    polymod r = *this; r /= o;
    return r;
  }

  polymod& operator/=(Zn<M> const& o) {
    for(li i = 0; i < (li)((int)A.size()); ++i) A[i] /= o;
    return *this;
  }

  static polymod inverse(polymod const& a, int n) {
    assert(a[0] != 0);
    polymod b = 1/a[0];
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      b = mul(b, polymod(2) - mul(a,b,m), m);
    }
    b.truncate(n);
    return b;
  }

  static polymod power(polymod a, int k, int n) {
    if(k == 1) return a;
    polymod r = 1;
    while(k) {
      if(k&1) r = mul(r,a,n);
      a = mul(a,a,n);
      k /= 2;
    }
    return r;
  }

  static polymod sqroot(polymod const& a, int n) {
    assert(a[0] == 1);
    polymod b = 1;
    polymod c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, polymod(2) - mul(b,c,m), m);
      b = (b + mul(a,c,m)) / Zn<M>(2);
      c = mul(c, polymod(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

  static polymod root(polymod const& a, int k, int n) {
    assert(a[0] == 1);
    polymod b = 1;
    polymod c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, polymod(2) - mul(b,c,m), m);
      auto ck = power(c, k, m) / Zn<M>(k);
      b = mul(b, polymod(Zn<M>(k-1)/Zn<M>(k)) + mul(a, ck, m), m);
      c = mul(c, polymod(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

};

using ZN = Zn<998'244'353>;
using PZN = polymod<998'244'353>;

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  li n,m; cin>>n>>m; m+=1;
  vi c(n);
  for(li i = 0; i < (li)(n); ++i) cin >> c[i];

  PZN d;
 d[0] = 1;
  for(li i = 0; i < (li)(n); ++i) if(c[i] <= m) d[c[i]] = -4;
  PZN b = PZN::sqroot(d, m);
  b[0] += 1;
  b /= ZN(2);

  PZN ib = PZN::inverse(b, m);

  for(li i = (1); i <= (li)(m-1); ++i) cout << ib[i] << '\n';
  cout << flush;

  return 0;
}
