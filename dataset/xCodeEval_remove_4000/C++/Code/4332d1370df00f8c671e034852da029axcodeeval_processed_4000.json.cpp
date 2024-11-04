







using namespace stdext;








using namespace std;




typedef long long ll;





















char getChar() { return (char)tolower(getchar()); }
inline int kuaidu() { int k = 0; char f=1;char c=getChar();for(;!isdigit(c);c=getChar())if(c=='-')f=-1;for(;isdigit(c);c=getChar())k=k*10+c-'0';return k*f;}
inline ll id1() { ll k = 0; char f=1;char c=getChar();for(;!isdigit(c);c=getChar())if(c=='-')f=-1;for(;isdigit(c);c=getChar())k=k*10LL+c-'0';return k*f;}
char KX[100];


inline void id2(const int& x) { if (x == 0) {putchar('0');return;} int tmp = x > 0 ? x : -x; if (x < 0) putchar('-'); int cnt = 0; while (tmp > 0) { KX[cnt++] = (char)tolower(int(tmp % 10)) + '0'; tmp /= 10; } while (cnt > 0) putchar(KX[--cnt]);}
inline void id2(const ll& x) { if (x == 0) {putchar('0');return;} ll tmp = x > 0 ? x : -x; if (x < 0) putchar('-'); int cnt = 0; while (tmp > 0) { KX[cnt++] = (char)tolower(int(tmp % 10)) + '0'; tmp /= 10; } while (cnt > 0) putchar(KX[--cnt]);}
inline void print(const ll& x) {id2(x);putchar('\n');}
inline void print(const int& x) {id2(x);putchar('\n');}












typedef pair<int,int> PII; typedef vector<pair<int,int> > VPII; typedef pair<ll,ll> PLL; typedef vector<pair<ll,ll> > VPLL; typedef pair<int,ll> PIL; typedef pair<ll,int> PLI; typedef vector<int> VI; typedef vector<double> VD; typedef vector<VD> VVD; typedef vector<char> VC; typedef vector<VC> VVC; typedef vector<VI> VVI; typedef vector<ll> VL; typedef vector<VL> VVL; typedef set<int> SI; typedef set<ll> SL; typedef queue<int> QI; typedef unordered_set<int> USI; typedef unordered_set<ll> USL; typedef unordered_map<int,int> UMI;

void read(int& x){x=kuaidu();} void read(int& x,int& y){read(x);read(y);} void read(int& x,int& y,int& z){read(x,y);read(z);} void read(int& x,int& y,int& z,int& w){read(x,y);read(z,w);} void read(int& x,int& y,int& z,int& w, int& mu){read(x,y);read(z,w,mu);} void read(ll& x){x=id1();} void read(ll& x,ll& y){read(x);read(y);} void read(ll& x,ll& y,ll& z){read(x,y);read(z);} void read(ll& x,ll& y,ll& z,ll& w){read(x,y);read(z,w);} void read(ll& x,ll& y,ll& z,ll& w, ll& mu){read(x,y);read(z,w,mu);} void read(int* x, int n){REP(i,n)read(x[i]);} void read(ll* x, int n){REP(i,n)read(x[i]);} void read(VI& x, int n){x.resize(n);REP(i,n)read(x[i]);} void print(int* x, int n){REP(i,n){id2(x[i]);putchar(" \n"[i==n-1]);}} void print(int *x,int l,int r){FOR(i,l,r) {id2(x[i]);putchar(" \n"[i==r]);}} void print(const VI& x){REP(i,sz(x)) {id2(x[i]);putchar(" \n"[i==sz(x)-1]);}} void print(ll* x, int n){REP(i,n){id2(x[i]);putchar(" \n"[i==n-1]);}} void print(ll *x,int l,int r){FOR(i,l,r) {id2(x[i]);putchar(" \n"[i==r]);}} void print(const VL& x){REP(i,sz(x)) {id2(x[i]);putchar(" \n"[i==sz(x)-1]);}} void print(const PII& pr) {print(VI({pr.FI,pr.SE}));} void print(const unordered_map<int,int>& um){for(const auto& it : um){cout<<"Key:"<<it.FI<<endl;cout<<"Value:"<<it.SE<<endl;}} void print(const VPII& v){REP(i,sz(v))print(v[i]);} void print(const VPLL& v){REP(i,sz(v))print(v[i]);} void print(const int& i, const int& j){id2(i);putchar(' ');id2(j);putchar('\n');} void print(const int& i, const int& j, const int& k){id2(i);putchar(' ');id2(j);putchar(' ');id2(k);putchar('\n');} void print(const int& i, const int& j, const int& k, const int& l){id2(i);putchar(' ');id2(j);putchar(' ');id2(k);putchar(' ');id2(l);putchar('\n');} void print(const ll& i, const ll& j){id2(i);putchar(' ');id2(j);putchar('\n');} void print(const ll& i, const ll& j, const ll& k){id2(i);putchar(' ');id2(j);putchar(' ');id2(k);putchar('\n');} void print(const ll& i, const ll& j, const ll& k, const ll& l){id2(i);putchar(' ');id2(j);putchar(' ');id2(k);putchar(' ');id2(l);putchar('\n');}











mt19937_64 mrand(random_device{}()); ll myrand(ll x) { return (mrand() % x + x) % x; } ll myrand(ll x, ll y) { return x + myrand(y - x + 1);}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; } ll gcd (ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }



VPII dirs={{-1,0},{1,0},{0,-1},{0,1}};









  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {

~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};



void id3(int n, int l, int r) {REP(i,n){if(i)printf(" ");printf("%lld",myrand(l,r));}printf("\n");}






ll MOD = 1E9+7;
struct UnionFind { vector<int> C;int cnt; UnionFind(int n) : C(n, -1),cnt(n) {} int find(int x) { return (C[x] < 0) ? x : C[x] = find(C[x]); } void merge(int x, int y) { int px = find(x), py = find(y); if (px != py) { --cnt; int rx = -C[px], ry = -C[py]; if (rx == ry) {--C[py]; ++ry;} if (rx < ry) C[px] = py; else C[py] = px; } } int numgroup() {return cnt;}};





struct BIT { int N; vector<ll> tree; BIT(int N_) : N(N_), tree(N_ + 1, 0) {}
   void add(int x, ll v) { assert(x >= 0 && x <= N); ++x; while(x <= N) { tree[x] += v; x += (x & -x); } }
   ll get(ll x) { if (x < 0) return 0; assert(x <= N); ++x; ll res = 0; while(x) { res += tree[x]; x -= (x & -x); } return res; } };

ll ksm(ll x, ll k) { ll ret = 1; while(k) { if(k & 1) { ret *= x; ret %= MOD; } k >>= 1; x *= x; x %= MOD; } return ret; }
VVL matmul(VVL& A, VVL& B) { int n = sz(A), m = sz(A[0]), k = sz(B[0]); VVL C(n, VL(k, 0)); for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) for(int l = 0; l < m; l++) C[i][j] += A[i][l] * B[l][j]; return C; }
VVL matpower(VVL& A, ll k) { int n = sz(A); VVL ret(n, VL(n)), B = A; for(int i = 0; i < n; i++) ret[i][i]=1; while(k) { if(k & 1) ret = matmul(ret, B); k >>= 1; B = matmul(B, B); } return ret; }
ll mod_inverse(ll x) { return ksm(x, MOD - 2); }
ll mod_div(ll x, ll y) {return ((x%MOD)*mod_inverse(y))%MOD;}


vector<int> id4(int n) { vector<bool> a(n+10); a[0]=a[1]=true; vector<int> v; FOR(i,2,n) { if (!a[i]) v.push_back(i); for(int j = 0; j < sz(v) && v[j]*i <= n;j++) { a[i*v[j]] = 1; if (i % v[j] == 0) break; } } return v; }




void randtree(int N) { for (int i = 2; i <= N; ++i) { print(myrand(1, i - 1)); } }
















int to(int a, int b, int c, int d, int e) { return a * BASE1 * BASE2 * BASE3 * BASE4 + b * BASE2 * BASE3 * BASE4 + c * BASE3 * BASE4 + d * BASE4 + e; }
void from(int x, int& a, int& b, int& c, int& d, int& e) { a = x / (BASE1 * BASE2 * BASE3 * BASE4); x %= (BASE1 * BASE2 * BASE3 * BASE4); b = x / (BASE2 * BASE3 * BASE4); x %= (BASE2 * BASE3 * BASE4); c = x / (BASE3 * BASE4); x %= (BASE3 * BASE4); d = x / (BASE4); x %= BASE4; e = x; }


class rational { public: ll u, d; private: ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); } ll lcm(ll a, ll b) { return a / gcd(a, b) * b; } void reduce(ll& u_, ll& d_) { ll g = gcd(abs(u_), abs(d_)); u_ /= g, d_ /= g; } public: rational(ll a, ll b) : u(a), d(b) { reduce(u, d); } rational operator+(const rational& t) { ll m = lcm(d, t.d); return rational(u * (m / d) + t.u * (m / t.d), m); } rational operator-(const rational& t) { return *this + rational(-t.u, t.d); } rational operator*(const rational& t) { return rational(u * t.u, d * t.d); } rational operator/(const rational& t) { if (t.u == 0) return rational(1, 0); if (t.u < 0) return *this * rational(-t.d, -t.u); return *this * rational(t.d, t.u); } friend ostream& operator<<(ostream& os, const rational& r);  }; ostream& operator<<(ostream& os, const rational& r) { os<<r.u<<"/"<<r.d; return os; }

struct mod_int { ll val; mod_int(ll v = 0) {if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; } static ll mod_inv(ll a, ll m = MOD) { ll g = m, r = a, x = 0, y = 1; while (r != 0) { ll q = g / r; g %= r; swap(g, r); x -= q * y; swap(x, y); } return x < 0 ? x + m : x; } explicit operator ll() const {return val; } mod_int& operator+=(const mod_int &other) {val += other.val; if (val >= MOD) val -= MOD; return *this; } mod_int& operator-=(const mod_int &other) {val -= other.val; if (val < 0) val += MOD; return *this; } mod_int& operator*=(const mod_int &other) {val = fast_mod((uint64_t) val * other.val); return *this; } mod_int& operator/=(const mod_int &other) {return *this *= other.inv(); } friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; } friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; } friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; } friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; } mod_int& operator++() {val = val == MOD - 1 ? 0 : val + 1; return *this; } mod_int& operator--() {val = val == 0 ? MOD - 1 : val - 1; return *this; } mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; } mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; } mod_int operator-() const {return val == 0 ? 0 : MOD - val; } bool operator==(const mod_int &other) const { return val == other.val; } bool operator!=(const mod_int &other) const { return val != other.val; } mod_int inv() const {return mod_inv(val); } friend ostream& operator<<(ostream &stream, const mod_int &m) {return stream << m.val; } friend istream& operator>>(istream &stream, mod_int &m) {return stream >> m.val; } mod_int pow(long long p) const { assert(p >= 0); mod_int a = *this, result = 1; while (p > 0) { if (p & 1) result *= a; a *= a; p >>= 1; } return result; } static ll fast_mod(ll x, ll m = MOD) { return x % m;} }; void print(mod_int x){ return print(x.val); }
class id0 {
  public:
    ll u, d; id0(ll u_, ll d_) { u = u_%MOD; d=d_%MOD; } id0 operator+(const id0& t) { return id0(((u * t.d)%MOD + (d*t.u)%MOD)%MOD, (d*t.d)%MOD); } id0& operator+=(const id0& t) { id0 ans = *this + t; u = ans.u; d = ans.d; return *this; } id0 operator-(const id0& t) { return *this + id0(MOD-t.u,t.d); } id0& operator-=(const id0& t) {id0 ans=*this - t;u=ans.u;d=ans.d;return *this;} id0 operator*(const id0& t) { return id0((u*t.u)%MOD,(d*t.d)%MOD); } id0& operator*=(const id0&t){id0 ans=*this * t;u=ans.u;d=ans.d;return *this;} id0 operator/(const id0& t) { if (t.u == 0) return id0(1, 0); return *this * id0(t.d, t.u); } id0& operator/=(const id0&t){id0 ans=*this / t;u=ans.u;d=ans.d;return *this;}
    ll asll() { return mod_div(u, d); } friend ostream& operator<<(ostream& os,const id0& r);
}; ostream& operator<<(ostream& os, const id0& r) { os << r.u << "/" << r.d; return os; }
void read_tree(VI nbrs[MAXN], int N){ REP(i,N)CLR(nbrs[i]); REP(i,N-1){int uuu, vvv;read(uuu,vvv);--uuu;--vvv;nbrs[uuu].PB(vvv);nbrs[vvv].PB(uuu);} }

int N;
int d[MAXN];

ll doit() {
  sort(d+1,d+N);
  ll ans = d[N-1];
  ll pref = 0;
  FOR(i,2,N){
    ans+=pref-ll(d[i-1])*(i-1);
    pref+=d[i-1];
  }
  return ans;
}

int main() {
  FET(tt){
    read(N);read(d,N);
    print(doit());
  }
  return 0;
}





