
using namespace std;
using ll = long long int;

const size_t id0 = 100000;
template<class T> struct is_cstr: std::false_type {}; template<int N> struct is_cstr<char[N]> : std::true_type {};
template<typename T> constexpr string formcomm(const T& a) {if constexpr (is_same_v<T, int> || is_same_v<T, size_t>) return "%d"; else if constexpr (is_same_v<T, long long int>) return "%lld"; else if constexpr (is_same_v<T, short int>) return "%hd"; else if constexpr (is_same_v<T, unsigned int>) return "%u"; else if constexpr (is_same_v<T, unsigned long long int>) return "%llu"; else if constexpr (is_same_v<T, unsigned short int>) return "%hu"; else if constexpr (is_same_v<T, char>) return "%c"; else {printf("Type %s non prévu\n", typeid(a).name()); terminate();}}
template<typename T> constexpr string formout(const T& a) {if constexpr (is_same_v<T, float>) return "%.16f"; else if constexpr (is_same_v<T, double>) return "%.16lf"; else if constexpr (is_same_v<T, long double>) return "%.16Lf"; else if constexpr (is_same_v<T, string>) return "%s"; else if constexpr (is_cstr<T>::value) return "%s"; else return formcomm(a);}
template<typename T> const T& addout(const T& a) {return a;} const char* addout(const string& a) {return a.c_str();} 
template<typename... Ts> void out(Ts&&... ts) {printf((formout(ts)+...).c_str(), addout(ts)...);}
template<typename It> void outs(It a, It b, string mid = " ", string fin = "\n") {if (a != b) {out(*a); ++a; for (; a != b; ++a) out (mid, *a);} out(fin);}
template<typename T> void outs(const T& l, string mid = " ", string fin = "\n") {outs(l.begin(), l.end(), mid, fin);}
template<typename T> constexpr string formin(const T& a) {if constexpr (is_same_v<T, float>) return "%f"; else if constexpr (is_same_v<T, double>) return "%lf"; else if constexpr (is_same_v<T, long double>) return "%Lf"; else if constexpr (is_same_v<T, string>) return "%s"; else if constexpr (is_cstr<T>::value) return "%s"; else return formcomm(a);}
template<typename T> constexpr int nstring(const T& a) {if constexpr (is_same_v<T, string>) return 1; else return 0;}
template<typename T> T* addin(T& a, char*& buf, string**& as) {return &a;} char* addin(string& a, char*& buf, string**& as) {char* ob = buf;buf+=id0+1;*as = &a;++as;return ob;} 
template<typename... Ts> void in(Ts&&... ts) {int ns=(nstring(ts)+...);string* as[max(ns,1)];char buf[1+(id0+1)*ns];char* b=buf;string** c=as;
 scanf((formin(ts)+...).c_str(), addin(ts, b, c)...); while (c > as) {--c; b-=id0+1; **c = string(b);}}
template<typename It> void ins(It a, It b) {for (; a != b; ++a) in (*a);} template<typename T> void ins(T& l) {ins(l.begin(), l.end());} 
void inl(char* s) {scanf("%[^\n]", s);} void inl(string& s) {char buf[id0+1]; inl(buf); s = string(buf);}





class eratos
{
public:
 eratos() {throw "eratos n'est pas constructible";}
 static void setMaximum(int m) {extendmax(m);}
 static int nthprime(int n) {return getnthprime(n);}
 static int nextPrime(int p) {return primeafter(p);}
 static int posPrimeAbove(int p) {return above(p);}
 static int posPrimeBelow(int p) {return below(p);}
 static int posLast() {return posPrimeBelow(id2);}
 static void clear() {extendmax(0, true);}

private:
 static vector<int> inp;
 static vector<int> cache;
 static int id2;
 static int id3;
 static int maxcomputed;
 static int dbcache;
 static int mxcache;
 static const int dg = numeric_limits<int>::digits;
 static const int nbits = dg + (numeric_limits<int>::is_signed?1:0);
 static const int smask = (nbits == 8)?3:(nbits == 16)?4:(nbits == 32)?5:(nbits == 64)?6:(nbits == 128)?7:-1;
 static const int mask = (int(1) << smask) - 1;
 static const int scache = 100;
 static bool isbitzero(int u) {return (inp[u >> smask] & (1 << (u & mask))) == 0;}
 static bool getbit(int u) {return (inp[u >> smask] & (1 << (u & mask))) != 0;}
 static void setbit(int u) {inp[u >> smask] |= (1 << (u & mask));}
 static void unsetbit(int u) {inp[u >> smask] &= ~(1 << (u & mask));}
 static void extendmax(int mx, bool forces = false) 
 {
  if (mx > id2 || forces)
  {
   if (mx < 1) mx = 1;
   id2 = 6*((mx+5)/6);
   id3 = int(sqrt(double(id2)));
   while (id3*id3 < id2) ++id3;
   maxcomputed = 5;
   inp.resize(((id2/3) >> smask) + 1, 0);
   cache.resize(scache);
   dbcache = 0;
   mxcache = -1;
   setbit(0);
   erasemultof(5, 20, 10);
   if (maxcomputed >= id3) maxcomputed = id2;
  }
 }
 static void erasemultof(int i, int a2, int a4)
 {
  if (i > id3) return;
  int j = i*i;
  while (j <= id2)
  {
   setbit(j/3);
   j += a4; 
   if (j > id2) break;
   setbit(j/3);
   j += a2;
  }
 }
 static int iteratenextprime(int d)
 {
  if (maxcomputed >= id3) maxcomputed = id2;
  if (d <= maxcomputed) return -1;
  int idx = maxcomputed / 3;
  if (maxcomputed % 6 == 1)
  {
   maxcomputed += 4; ++idx;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 4*maxcomputed, 2*maxcomputed);
    if (maxcomputed > d) return maxcomputed;
   }
  }
  while (maxcomputed <= id2)
  {
   maxcomputed += 2; ++idx;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 2*maxcomputed, 4*maxcomputed); 
    if (maxcomputed > d) return maxcomputed;
   }
   maxcomputed += 4; ++idx;
   if (maxcomputed > id2) break;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 4*maxcomputed, 2*maxcomputed);
    if (maxcomputed > d) return maxcomputed;
   }
  }
  return -1;
 }
 static int iteratefillcache(int wc)
 {
  int idx = maxcomputed / 3;
  if (maxcomputed % 6 == 1)
  {
   maxcomputed += 4; ++idx;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 4*maxcomputed, 2*maxcomputed);
    cache[wc] = maxcomputed;
    ++wc;
   }
  }
  if (wc < scache) while (maxcomputed <= id2)
  {
   maxcomputed += 2; ++idx;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 2*maxcomputed, 4*maxcomputed); 
    cache[wc] = maxcomputed;
    ++wc;
    if (wc >= scache) break;
   }
   maxcomputed += 4; ++idx;
   if (maxcomputed > id2) break;
   if (isbitzero(idx)) 
   {
    erasemultof(maxcomputed, 4*maxcomputed, 2*maxcomputed);
    cache[wc] = maxcomputed;
    ++wc;
    if (wc >= scache) break;
   }
  }
  if (maxcomputed >= id3) maxcomputed = id2;
  return wc;
 }
 static int fillcache(int wc, int db)
 {
  if (db < maxcomputed)
  {
   int idx = db/3;
   if (db % 6 == 1)
   {
    db += 4; ++idx;
    if (isbitzero(idx)) 
    {
     cache[wc] = db;
     ++wc;
    }
   }
   if (wc < scache) 
   {
    while (true)
    {
     db += 2; ++idx;
     if (db > maxcomputed) break;
     if (isbitzero(idx)) 
     {
      cache[wc] = db;
      ++wc;
      if (wc >= scache) break;
     }
     db += 4; ++idx;
     if (db > maxcomputed) break;
     if (isbitzero(idx)) 
     {
      cache[wc] = db;
      ++wc;
      if (wc >= scache) break;
     }
    }
   }
  }
  if (wc < scache && maxcomputed < id3) wc = iteratefillcache(wc);
  return wc;  
 }
 static void fillcachefromright(int fn)
 {
  int idx = fn/3;
  int wc = scache-1;
  if (fn % 6 == 5)
  {
   fn -= 4; --idx;
   if (isbitzero(idx)) 
   {
    cache[wc] = fn;
    --wc;
   }
  }
  if (wc >= 0) 
  {
   while (fn >= 7)
   {
    fn -= 2; --idx;
    if (isbitzero(idx)) 
    {
     cache[wc] = fn;
     --wc;
     if (wc < 0) break;
    }
    fn -= 4; --idx;
    if (fn < 7) break;
    if (isbitzero(idx)) 
    {
     cache[wc] = fn;
     --wc;
     if (wc < 0) break;
    }
   }
   if (wc >= 0) 
   {
    cache[wc] = 3; --wc;
    if (wc >= 0) cache[wc] = 2;
   }
  }
 }
 static void initcache()
 {
  dbcache = 0;
  cache[0] = 2; cache[1] = 3; cache[2] = 5;
  mxcache = fillcache(3, 5) - 1; 
 } 
 static void scacheright()
 {
  int i = cache[mxcache - dbcache];
  dbcache = mxcache + 1;
  mxcache = fillcache(0, i) + dbcache - 1;
 }
 static void scacheleft()
 {
  mxcache = dbcache - 1;
  dbcache -= scache;
  if (dbcache < 0) initcache();
  else fillcachefromright(cache[0]);
 }
 static void cachemoveto(int n)
 {
  if (n >= dbcache && n <= mxcache) return;
  if (mxcache == -1) {initcache(); if (n >= dbcache && n <= mxcache) return;}
  if (n >= dbcache) while (n > mxcache && mxcache - dbcache == scache - 1) scacheright();
  else if (dbcache < 2*n) while (dbcache > n) scacheleft();
  else
  {
   initcache();
   while (n > mxcache && mxcache - dbcache == scache - 1) scacheright();
  }
 }
 static int getnthprime(int n)
 {
  cachemoveto(n);
  if (n <= mxcache) return cache[n - dbcache]; else return -1;
 }
 static int primeafter(int n)
 {
  int r = iteratenextprime(n); 
  if (r > 0) return r;
  switch (n)
  {
   case 0: case 1: return 2; break;
   case 2: return 3; break;
   default:
    int i = n + 1;
    switch (i%6)
    {
     case 0: ++i; break;
     case 1: break;
     case 2: ++i;
     case 3: ++i; 
     case 4: ++i;  
     case 5: if (i <= maxcomputed) if (isbitzero(i/3)) return i;
      i += 2;
    }
    while (i <= maxcomputed)
    {
     if (isbitzero(i/3)) return i;
     i += 4;
     if (i > maxcomputed) break;
     if (isbitzero(i/3)) return i;
     i += 2;
    }
  }
  return -1;
 }
 static int above(int n)
 {
  if (n >= id2) return -1;
  if (mxcache == -1) initcache();
  if (n < cache[0] / 2) initcache();
  while (n > cache[mxcache - dbcache]) {if (mxcache - dbcache + 1 < scache) return -1; scacheright();}
  while (n < cache[0]) {if (dbcache == 0) break; scacheleft();}
  int a = -1;
  int b = mxcache - dbcache;
  while (a + 1 < b)
  {
   int m = (a + b + 1) >> 1;
   if (cache[m] < n) a = m; else b = m;
  }
  return dbcache + b;
 }
 static int below(int n)
 {
  if (n > id2) n = id2;
  int i = above(n);
  if (i >= 0) 
  {
   if (n == cache[i - dbcache]) return i;
   else return i-1;
  }
  else
  {
   if (mxcache < dbcache) scacheleft();
   return mxcache;
  }
 }
};
vector<int> eratos::inp;
vector<int> eratos::cache(eratos::scache);
int eratos::id2 = 0;
int eratos::id3 = 0;
int eratos::maxcomputed = 0;
int eratos::dbcache = 0;
int eratos::mxcache = -1;



class primes
{
public:
 primes(int n): mx(n) {eratos::setMaximum(mx-1);}
 class iterator
 {
  public:
   iterator(int n, int m): i(n), mx(m) {if (i != -1) p = eratos::nthprime(i); else p = -1; if (p >= mx) p = -1; if (p == -1) i = -1;}
   iterator(const iterator& a): i(a.i), p(a.p), mx(a.mx) {}
   iterator& operator=(const iterator& a) {i = a.i; p = a.p; mx = a.mx; return *this;}
   int operator* () const {return p;}
   iterator& operator++ () {++i; p = eratos::nthprime(i); if (p >= mx) p = -1; if (p == -1) i = -1; return *this;}
   iterator operator++ (int) {iterator t = *this; ++(*this); return t;}
   iterator& operator-- ()
   {
    if (i < 0) i = eratos::posPrimeBelow(mx); else --i; 
    if (i < 0) p = -1; else p = eratos::nthprime(i); 
    return *this;
   }
   iterator operator-- (int) {iterator t = *this; --(*this); return t;}
   bool operator== (const iterator& b) {return i == b.i;}
   bool operator!= (const iterator& b) {return i != b.i;} 
   int rank() {return i;}
  private:
   int i;
   int mx;
   int p;
 };
 iterator begin() const {return iterator(0, mx);}
 iterator end() const {return iterator(-1, mx);}
 iterator lower_bound(int p) const {return iterator(eratos::posPrimeAbove(p), mx);}
 iterator upper_bound(int p) const {iterator it = lower_bound(p); if (it != end()) if (*it == p) ++it; return it;}
 iterator find(int p) const {iterator it = lower_bound(p); if (*it != p) return end(); else return it;}

private:
 int mx;
};



class id1
{
public:
 id1(int m): mx(m)
 {
  for (auto p: primes(m)) pr.push_back(p);
 }

 int nthprime(int i) const {if (i < pr.size()) return pr[i]; else return -1;} 
 

 template<class T> vector<pair<T, int> > factor(T n) const
 {
  vector<pair<T, int> > res;
  for (int i = 0, m = pr.size(); i < m; ++i) 
  {
   T p = T(pr[i]);
   if (p*p > n) break;
   if (n%p == 0) 
   {
    int k = 0;
    while (n%p == 0) {++k; n /= p;}
    res.emplace_back(p, k);
   }
  }
  if (n > 1) res.emplace_back(n, 1);
  return res;
 }
 

 template<class T> T ndiv(T n) const
 {
  T res = 1;
  for (int i = 0, m = pr.size(); i < m; ++i) 
  {
   T p = T(pr[i]);
   if (p*p > n) break;
   if (n%p == 0) 
   {
    T k = 1;
    while (n%p == 0) {++k; n /= p;}
    res *= k;
   }
  }
  if (n > 1) res <<= 1;
  return res;
 }
 

 template<class T> bool isprime(T n) const
 {
  if (n < 0) n = -n;
  if (n == 2 || n == 3) return true;
  else if (n % 2 == 0 || n % 3 == 0) return false;
  else if (n <= mx) return isp(n/3);
  else
  {
   for (int i = 0, m = pr.size(); i < m; ++i) 
   {
    T p = T(pr[i]);
    if (p*p > n) break;
    if (n%p == 0) return false;
   }
   return true;
  }
 }
private:
 int mx;
 vector<int> pr;
};




unordered_map<ll, int> nv;

int nimval(ll s)
{
 if (s == 0) return 0;
 auto it = nv.find(s);
 if (it != nv.end()) return it->second;
 ll fd = 0; 
 ll msk = 1;
 for (int i = 1; msk <= s; ++i, msk <<= 1)
 {
  ll sp = (s & (msk-1)) | (s >> i);
  if (sp >= s) break;
  int nn = nimval(sp);
  if (nn <= 60) fd |= (1 << nn);
 }
 int k = 0;
 while ((fd&1) == 1) {++k; fd >>= 1;}
 nv[s] = k;
 return k; 
}

int main()
{
 int n;
 in(n);
 vector<int> a(n);
 ins(a);
 id1 pr(32000);
 unordered_map<int, ll> mpow;
 for (auto m: a) for (auto [p, v]: pr.factor(m)) 
 {
  auto it = mpow.find(p);
  if (it == mpow.end()) mpow[p] = ll(1) << (v-1);
  else it->second |= ll(1) << (v-1);
 }
 int nimadd = 0;
 for (auto [p, sv]: mpow) nimadd ^= nimval(sv);
 if (nimadd == 0) out("Arpa\n"); else out("Mojtaba\n");
 return 0;
}
