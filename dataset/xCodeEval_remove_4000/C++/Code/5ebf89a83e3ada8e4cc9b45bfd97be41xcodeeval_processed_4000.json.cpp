







































using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<ld> vld;

const ld pi = acosl(-1);

template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( a > b ) { a = b; return true; } return false; }

i64 mul(i64 a, i64 b, i64 m) {
  i64 d = ((long double)a * b / m), r = a * b - m * d;
  if( r < 0 ) r += m; else if( r >= m ) r -= m;
  return r;
}
i64 gcd(i64 a, i64 b) {
  while (b) {
    i64 t = a % b;
    a = b; b = t;
  } return a;
}
i64 id1 (i64 a, i64 b, i64 & x, i64 & y) {
  if (a == 0) { x = 0; y = 1; return b; }
  i64 x1, y1, d = id1(b%a, a, x1, y1);
  x = y1 - (b / a) * x1; y = x1;
  return d;
}
i64 powmod(i64 a,i64 n,i64 m) {
  i64 r=1; while(n){ if(n&1)r=mul(r,a,m); if(n/=2)a=mul(a,a,m); } return r;
}


i64 inv(i64 a, i64 mod) {
  i64 x,y,g = id1(a,mod,x,y);
  if( g != 1 ) return -1;
  x %= mod; if( x < 0 ) x += mod;
  return x;
}
vector<int> all_inv(int m) {
  vi r(m); r[1] = 1;
  for(int i=2; i<m; ++i) {
    r[i] = mul(m/i,r[m%i],m);
    r[i] = r[i] == m ? 0: m - r[i];
  } return r;
}
const int mod = 1e9 + 7;
int mul(int a, int b) { return ((i64)a*b) % mod; }
int sum(int a, int b) { if( (a+=b)>=mod ) a-=mod; return a; }
void add(int& a, int b) { if( (a+=b)>=mod) a-=mod; }
int diff(int a, int b) { if( (a-=b)<0 ) a+=mod; return a; }
void sub(int& a, int b) { if( (a-=b)<0 ) a+=mod; }
int powmod(int a, i64 n) {
  int r=1; while(n){ if(n&1)r=mul(r,a); if(n/=2)a=mul(a,a); } return r;
}
int inv(int x) { return powmod(x, mod-2); }
bool miller(i64 n, int a) {
  if( n % 2 == 0 ) return true;
  if( gcd((i64)a, n) != 1 ) return true;
  i64 k = n - 1, l = 0; while( k % 2 == 0 ) { k /= 2; ++l; }
  i64 x = powmod(a, k, n), x2; if( x == 1 || x == n - 1 ) return false;
  while(--l) {
    if( (x2=mul(x,x,n)) == 1 ) return true;
    if( (x=x2) == n - 1 ) return false;
  } return x != 1;
}
const int mxprime = 1e6;

vector<int> primes; bitset<mxprime/2> is_prime;
void id0(int n = mxprime) {
  is_prime.set(); is_prime.reset(0); primes.pb(2);
  int bi = sqrt(n), bj = (n-1)/2;

  for(int i=1,i21=3,sj=4,dsj=8;i21<bi;i+=1,i21+=2,sj+=dsj,dsj+=4)
    if( is_prime.test(i) ) for(int j=sj;j<bj;j+=i21)
        is_prime.reset(j);
  for(int i = 1; i < bj; ++i) if( is_prime.test(i) )
      primes.pb(i*2+1);
}
bool check_prime(int x) {
  if( primes.empty() ) id0();
  assert( x >= 0 && x < mxprime );
  return (x&1) ? is_prime[(x-1)/2] : (x==2);
}
bool isprime(i64 n, bool id2 = false) {
  if( n < 2 ) return false;
  if( n < mxprime ) return check_prime(n);
  if( id2 ) for(int x: primes) if( x <= 100 ) {
        if( n % x == 0 ) return false;
      } else break;
  for(int i: {2,3,5,7,11,13}) if( miller(n, i) ) return false;
  return true;
}
map<i64, int> factors(i64 n) {

  map<i64, int> r;
  if( primes.empty() ) id0();
  for(int x: primes) if( x < 100 ) {
      while( n % x == 0 ) { n /= x; r[x]++; }
    } else break;
  function<void(i64)> f = [&](i64 n) { if( n > 1 ) {
    if( isprime(n, false) ) r[n]++;
    else {
      i64 z; do{

        i64 x = 2 + rand() % 100, y = 1;
        int i = 0, stage = 2;
        while( (z = gcd(n, abs(x-y))) == 1 ) {
          if( i == stage ) { y = x; stage *= 2; }
          x = (mul(x,x,n) + 1) % n; ++i;
        }
      } while( z == n ); f(z); f(n / z);
    }
  } }; f(n);
  return r;
}
i64 get_phi(i64 n) {
  i64 r = 1; for(pair<i64,int> x: factors(n) ) {
    r *= x.fi - 1; while(--x.se) { r *= x.fi; }
  } return r;
}


int get_g(i64 n) {

  i64 phi = get_phi(n); 

  auto f = factors(phi);
  for(int g = 2; g < 200 && g < n; ++g) {
    if( gcd(g, n) == 1 && powmod(g,phi,n) == 1 ) {
      if( none_of(all(f), [&](pair<i64, int> x) {
        return powmod(g, phi / x.fi, n) == 1;
      } ) ) return g;
    }
  } return -1;
}

const int BS = 1e3, LBS = 3;
struct bint {

  vi d;
  bint() {}
  bint(const vi& v) :d(v) { del0(); }
  bint(i64 x) { do { d.pb(x%BS); x/= BS; } while(x); }
  bint(const string& s) {
    for(int i=s.length()-1;i>=0;i-=LBS) {
      int l=max(0,i-LBS+1);
      d.push_back(stoi(s.substr(l,i-l+1)));
    } del0();
  }
  void del0() { del0(d); }
  void del0(vi& d)const { while(sz(d)>1&&!d.back())d.pop_back(); }
  int size() const { return d.size(); }
  int& op[](int idx) { assert(idx >= 0 && idx < sz(d)); return d[idx]; }
  const int& op[](int idx) const { assert(idx >= 0 && idx < sz(d)); return d[idx]; }
  int sgn(int x) const { return (x>0)-(x<0); }
  int sgn(int x, int y) const { return (x>y)-(x<y); }
  bint op+(const bint& o) const {
    vi r(max(sz(d),sz(o))+1);
    forn(i, sz(r)-1) {
      if( i < sz(d) ) r[i] += d[i];
      if( i < sz(o) ) r[i] += o[i];
      if( r[i] >= BS ) r[i] -= BS, ++r[i+1];
    } return bint(r);
  }
  int cmp(const bint& o) const {
    if( sz(d) != sz(o) ) return sgn(sz(d), sz(o));
    ford(i, sz(d)) if( d[i]!=o[i] ) return sgn(d[i],o[i]);
    return 0;
  }
  bint op-(const bint& o) const {
    vi a(d); assert( cmp(o) >= 0 );
    forn(i, sz(a)) {
      if( i < sz(o) ) a[i] -= o[i];
      if( a[i] < 0 ) a[i] += BS, --a[i+1];
    } return bint(a);
  }
  bint op*(const bint& b) const {
    vi a(sz(d)+sz(b));
    const int BSZ = 2e6; assert( sz(a) <= BSZ );
    const u64 BMX = 16 * 1ULL * BS * 1ULL * BS;
    static u64 buf[BSZ];
    forn(i, sz(a)) buf[i] = 0;
    forn(i, sz(d)) if(d[i]) forn(j, sz(b)) if(b[j]) {
            buf[i+j] += d[i] * 1ULL * b[j];
            if( buf[i+j] >= BMX ) {
              buf[i+j] -= BMX;
              buf[i+j+1] += BMX/BS;
            }
          } forn(i, sz(a)) a[i] += buf[i] % BS, buf[i+1] += buf[i] / BS;
    return bint(a);
  }
  pair<bint,int> divmod(int b) const {
    vi r(d); i64 c = 0;
    ford(i, sz(r)) {
      c = c * BS + r[i];
      r[i] = c / b; c %= b;
    } return mp(r, c);
  }
  pair<bint,bint> divmod(const bint& b) const {
    vi a(d); if( sz(a) < sz(b) ) return mp(bint(0), a);
    vi c(sz(a)-sz(b)+1); bint bb;
    ford(i, sz(c)) if( i+sz(b)-1 >= sz(a) ) { c[i]=0; } else {
        int lv=0,rv=BS;
        while (lv+1<rv) {
          int v = (lv+rv)/2;
          bb = b*v;
          bool isOK = true;
          ford(j, sz(bb)) {
            if (i+j >= a.size()) { isOK = false; break; }
            if (a[i+j] != bb[j]) { isOK = a[i+j] > bb[j]; break; }
          }
          if (i + bb.size() < a.size()) isOK = true;
          if (!isOK) rv = v; else lv = v;
        } c[i] = lv; bb = b*lv;
        forn(j, sz(a)-i) {
          if (j < bb.size())
            a[i+j] -= bb[j];
          if (a[i+j] < 0) {
            a[i+j] += BS;
            a[i+j+1]--;
          }
        } del0(a);
      } del0(c); return mp(c,a);
  }
  bint sqrt() const {
    bint l(0), r(d);
    r = r + bint(1);
    while(1) {
      bint m = (l + r).divmod(2).fi;
      if( m.cmp(l) == 0 ) return l;
      if( cmp(m*m) >= 0 ) l = m;
      else r = m;
    }
  }
  string str() const {
    char*buf = new char[sz(d)*LBS];
    int j = sprintf(buf, "%d", d.back());
    ford(i, sz(d)-1) j += sprintf(buf+j,"%03d",d[i]);
    string r(buf, buf+j);
    delete[] buf; return r;
  }
  void swap(bint& o) { d.swap(o.d); }
  bool is0() const { assert(!d.empty()); return d.size() == 1 && d[0] == 0; }
  bint gcd(bint b) const {
    bint a(d), r(1);
    while( !a.is0() && !b.is0() ) {
      if( a[0]%2==0 && b[0]%2==0 ) {
        a=a.divmod(2).fi;
        b=b.divmod(2).fi;
        r=r+r;
      } else if( a[0]%2==0 ) {
        a=a.divmod(2).fi;
      } else if( b[0]%2==0 ) {
        b=b.divmod(2).fi;
      } else {
        if( a.cmp(b)<0 ) a.swap(b);
        a = a - b;
      }
    } return r*(a+b);
  }
};
struct base {
  typedef double T; T re, im;
  base() :re(0), im(0) {}
  base(T re) :re(re), im(0) {}
  base(T re, T im) :re(re), im(im) {}
  base op + (const base& o) const { return base(re + o.re, im + o.im); }
  base op - (const base& o) const { return base(re - o.re, im - o.im); }
  base op * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
  base op * (ld k) const { return base(re * k, im * k) ;}
  base conj() const { return base(re, -im); }
};
const int N = 20;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
void build_rev(int k) {
  static int rk = -1;
  if( k == rk )return ; rk = k;
  fore(i, 1, (1<<k) ) {
    int j = rev[i-1], t = k-1;
    while( t >= 0 && ((j>>t)&1) ) { j ^= 1 << t; --t; }
    if( t >= 0 ) { j ^= 1 << t; --t; }
    rev[i] = j;
  }
}
void fft(base *a, int k) {
  build_rev(k); int n = 1 << k;
  forn(i, n) if( rev[i] > i ) swap(a[i], a[rev[i]]);
  for(int l = 2, ll = 1; l <= n; l += l, ll += ll) {
    if( w[ll].re == 0 && w[ll].im == 0 ) {
      ld angle = pi / ll;
      base ww( cosl(angle), sinl(angle) );
      if( ll > 1 ) for(int j = 0; j < ll; ++j) {
          if( j & 1 ) w[ll + j] = w[(ll+j)/2] * ww;
          else w[ll + j] = w[(ll+j)/2];
        } else w[ll] = base(1, 0);
    }
    for(int i = 0; i < n; i += l) forn(j, ll) {
        base v = a[i + j], u = a[i + j + ll] * w[ll + j];
        a[i + j] = v + u; a[i + j + ll] = v - u;
      }
  }
}
vi mul(const vi& a, const vi& b) {
  int k = 1;
  while( (1<<k) < (a.size() + b.size()) ) ++k;
  int n = (1<<k);
  forn(i, n) f1[i] = base(0,0);
  forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
  forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
  fft(f1, k);
  forn(i, 1 + n/2) {
    base p = f1[i] + f1[(n-i)%n].conj();
    base _q = f1[(n-i)%n] - f1[i].conj();
    base q(_q.im, _q.re);
    f1[i] = (p * q) * 0.25;
    if( i > 0 ) f1[(n - i)] = f1[i].conj();
  }
  forn(i, n) f1[i] = f1[i].conj();
  fft(f1, k);
  vi r(sz(a) + sz(b));
  i64 c = 0;
  forn(i, sz(r) ) {
    c += (i64) (f1[i].re / n + 0.5); r[i] = c % BS; c /= BS;
  }
  while (r.size() > 1 && r.back() == 0) r.pop_back();
  return r;
}

void id3(int n, bint& r) {
  if (n <= 20) {
    r = bint(1);
    forn(i, n) r = r * 3;
  } else if (n % 2 == 0) {
    id3(n / 2, r);
    

    vi a = r.d; a = mul(a, a); r.d = a;
  } else {
    id3(n - 1, r);
    r = r * 3;
  }
}

void solve_d() {
  

  string s; cin >> s;
  if (s == "1") {
    cout << "1\n";
    return ;
  }
  bint n(s);
  long double lgn = 0, lgmul = 1, lgdiff = 0;
  int i = n.d.size() - 1;
  lgdiff = i * log(BS);
  forn(t, 10) {
    if (i < 0) break;
    lgn += n.d[i] * lgmul; --i;
    lgmul /= BS;
  }
  lgn = logl(lgn) + lgdiff;
  

  

  

  

  

  

  int p2 = 0, p3 = 0;
  while (lgn > logl(6.01)) {
    lgn -= logl(3); p3 += 1;
  }
  bint zn; id3(p3, zn);
  bint czn(zn);
  int z = 1;
  while (czn.cmp(n) < 0) {
    czn = czn + zn; ++z;
  }
  int ans = 0;
  switch (z) {
    case 1: ans += 0; break;
    case 2: ans += 2; break;
    case 3: ans += 3; break;
    case 4: ans += 4; break;
    case 5: ans += 5; break;
    case 6: ans += 5; break;
    default: ans += 6; break;
  }
  cout << ans + 3 * p3 << endl;
}

bool go(i64 n, const vector<i64>& f) {
  for (i64 x: f) n -= x;
  if (n < 0) return false;
  if (n == 0) return true;
  if (f.size() == 1) return n % f[0] == 0;
  if (n >= f[0] * f[1]) return true;
  

  return false;
}

void solve_f() {
  int T;
  cin >> T;
  i64 n, k;
  map<i64, vector<i64>> M;
  forn(t, T) {
    cin >> n >> k;
    if (M.find(k) == M.end()) {
      for (auto e: factors(k)) M[k].pb(e.fi);
      sort(all(M[k]));
    }
    cout << (go(n, M[k]) ? "YES" : "NO") << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);

  freopen("input.txt", "r", stdin);
  


  solve_d();


  cerr << "time is " << int(clock() * 1000.0 / CLOCKS_PER_SEC + .5) << " ms." << endl;

  return 0;
}
