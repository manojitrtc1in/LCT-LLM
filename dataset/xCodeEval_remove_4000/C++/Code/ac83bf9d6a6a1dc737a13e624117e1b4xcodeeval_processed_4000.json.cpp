



























using namespace std;
using namespace __gnu_pbds;



typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oSet;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> veci;
typedef deque<int> deqi;
typedef long long lint;
typedef set<int> seti;
typedef long long ll;


















const int E4 = 1e4+2;
const int E5 = 1e5+2;
const int E6 = 1e6+2;
const int MOD = 1e9+7;
const int INF = 1e9+8;
const double eps = 1e-12;
const double pi = 3.14159265359;
const lint INFL = 1ll*INF*INF;






double getTime(double sub = 0.0) { cout << "Time : " << fixed << clock()*1.0/CLOCKS_PER_SEC - sub << '\n';}
double getClock() { return clock()*1.0/CLOCKS_PER_SEC;}

int    pw(int a, int n, int K=1e9+7){return(n?(pw((a*a)%K,n/2ll,K)*((n&1ll)?a:1ll))%K:1ll);}
lint   pw(lint a,lint n,lint K=INFL){return(n?(pw((a*a)%K,n/2ll,K)*((n&1ll)?a:1ll))%K:1ll);}
int    gcd(int a,int b){return (b==0?a:gcd(b,a%b));}
lint   gcd(lint a,lint b){return b==0?a:gcd(b,a%b);}
int    lcm(int a,int b){return a*(b/gcd(a,b));}
lint   lcm(lint a,lint b){return (b/gcd(a,b))*a;}
int    fact(int n) { return n>0?n*fact(n-1):1;}
lint   fact(lint n) { return n>0?n*fact(n-1):1;}
int    choose(int k,int n){  if(k>n)return 0;k=max(n-k,k);if(k ==0)return 1;int R=n;for(int i=2;i<=k;i++){R=R*(n-i+1)/i;}return R;}
lint   choose(lint k,lint n){if(k>n)return 0;k=max(n-k,k);if(k ==0)return 1;int R=n;for(int i=2;i<=k;i++){R=R*(n-i+1)/i;}return R;}

int    lowbit(int m){return m&(-m);}
int    hibit(int m){for (int i=30;i>=0;i--) if ((1<<i)&m) return i;}
lint   hibit(lint m){for (int i=62;i>=0;i--) if ((1ll<<i)&m) return i;}
int    getbit(int x, int b){return (x >> b) & 1;}
lint   getbit(lint x, int b){return (x >> b) & 1;}
int    setbit(int x, int b){return x | (1 << b);}
void   _setbit(int &x, int b){x = setbit(x, b);}
lint   setbit(lint x, int b){ return x | (1ll << b);}
void   _setbit(lint &x, int b){x = setbit(x, b);}
int    unsetbit(int x, int b){return x & ((~0)- (1 << b));}
void   id0(int &x, int b){x = unsetbit(x, b);}
int    bitcnt(int x){x = x - ((x >> 1) & 0x55555555);x = (x & 0x33333333) + ((x >> 2) & 0x33333333);return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;}
lint   bitcnt(lint x){int p1 = (x >> 32) & ((1ll << 32)-1);int p2 = x & ((1ll << 32)-1);return bitcnt(p1) + bitcnt(p2);}
string bin(int x, int len = -1){if (len == -1) {len = hibit(x)+1;}string res="";for(int i = len-1; i >= 0; i--) res.pb(getbit(x, i)+'0');return res;}
string bin(lint x, int len = -1){if (len == -1) {len = hibit(x)+1;}string res="";for(int i = len-1; i >= 0; i--) res.pb(getbit(x, i)+'0');return res;}
int    id1(int x){return hibit(x)-bitcnt(x)+1;}
int    id1(lint x){return hibit(x)-bitcnt(x)+1;}

struct IO {
  IO operator>>(int &n)const{n=0;bool sign=0;int a=getchar();while(a<'0'||a>'9'){ if(a=='-'){sign=1;a=getchar();break;}a=getchar();}while(a>='0' && a<='9'){n=(n<<1)+(n<<3)+a-'0';a=getchar();}if (sign) n = ~(n-1);return *this;}
  IO operator>>(long long &n){n = 0;bool sign = 0;char c = getchar();while( c < '0' || c > '9'){if(c == '-') sign = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(sign) n = ~(n-1);return *this;}
  IO operator>>(double &x) const { scanf("%lf", &x); return *this; }
  IO operator>>(char &x) const { do { x = getchar(); } while (x == ' ' || x == '\n'); return *this; }
  IO operator>>(string &s) const { cin >> s; return *this;}
  IO operator<<(const int x) const { printf("%d", x); return *this; }
  IO operator<<(const double x) const { printf("%lf", x); return *this; }
  IO operator<<(const char x) const { putchar(x); return *this; }
  IO operator<<(const long long x) const { cout << x; return *this;}
  IO operator<<(string x) { printf("%s", (x.c_str())); return *this;}
}in,out;

namespace Input{
  template <template <typename, typename...> class Container,typename T>
  void cinv(Container <T> &a,int n) {
    for (int i = 0; i < n; i++) {
      T t;
      cin >> t;
      a.push_back(t);
    }
  }

  template <typename T>
  void cinv(T *ptr,int len) {
    for (int i = 0; i < len; i++) {
      in >> *(ptr + i);
    }
  }

  template <typename T>
  void cinv(T A, int n, int m) {
    for (int i = 0; i < n; i++) {
      cinv(A[i],m);
    }
  }
}

namespace Output{
  void split(char A) {
    if (A != '0') {
      putchar(A);
    }
  }
  template <typename T>
  void Print(T A,char sp = '0') {
    out << A;
    split(sp);
  }
  template <typename T1,typename T2>
  void Print(pair<T1,T2> A,char sp = '0') {
    cout << '(' << A.first << ',' << A.second << ')';
    split(sp);
  }
  template <typename T>
  void Print(T A[],int len,char sp = ' ') {
    for (int i = 0; i < len; i++) {
      out << A[i];
      split(sp);
    }
  }
  template <typename T>
  void Print(T *A,int n,int m,char nsp = ' ',char sp = '\n') {
    for (int i = 0; i < n; i++) {
      Print(A[i],m,nsp);
      split(sp);
    }
  }
  template <template <typename, typename...> class Container,typename T>
  void Print(Container<T> C,char sp = ' ') {
    for (auto i : C) {
      Print(i);
      split(sp);
    }
  }
  template <typename T>
  void Print(stack<T> A,char sp = ' ') {
    while(A.size()) {
      Print(A.top());
      split(sp);
      A.pop();
    }
  }
  void Print(oSet C,char sp = ' ') {
    for (auto i : C) {
      Print(i);
      split(sp);
    }
  }
  template <template <typename, typename...> class Container,typename T1,typename T2>
  void Print(Container<T1,T2> C,char sp = ' ') {
    for (auto i : C) {
      Print(i);
      split(sp);
    }
  }
  template <typename T>
  void Printl(T A) {
    Print(A,'\n');
  }
}
using namespace Output;
using namespace Input;

const int N = 301005;
int n,q;
int a[N],Tree[2 * N];

typedef long long ll;

struct fenwick{
  ll T[N];
  ll c(ll x) {
    ll sum = 0;
    for (;x;x-=x&(-x)) {
      sum += T[x];
    }
    sum += T[0];
    return sum;
  }
  ll getSum(ll l,ll r) {
    return (l > r) ? 0 : c(r) - (l > 0 ? c(l - 1) : 0);
  }
  void update(ll x,ll val) {
    if (x == 0) {
      T[0] += val;
      return;
    }
    for (;x<N;x+=x&(-x)) {
      T[x] += val;
    }
  }
  void print(int l, int r) {
    for (int i = l; i <= r; i++) {
      cout << getSum(i,i) << " \n"[i == r];
    }
  }
  void reset() {
    memset(T,0,sizeof T);
  }
};

struct fenrick {
  static const int max_len = N;
  size_t array_size;
  fenwick T1 , T2;
  fenrick(int n = max_len) {
    array_size = n;
  }
  void updateRange(ll l, ll r, ll val) {
    T1.update(l , val);
    T1.update(r + 1, -val);
    T2.update(l, val * (l - 1));
    T2.update(r + 1, -val * r);
  }
  ll c(ll ind) {
    return T1.c(ind) * ind - T2.c(ind);
  }
  ll getSum(ll l, ll r) {
    return (l > r) ? 0 : c(r) - (l > 0 ? c(l - 1) : 0);
  }
  void reset() {
    T1.reset();
    T2.reset();
  }
  void print(int l, int r) {
    for (int i = l; i <= r; i++) {
      cout << getSum(i,i) << " \n"[i == r];
    }
  }
  size_t size() {
    return array_size;
  }
  friend istream& operator >> (istream& InputStream, fenrick &F) {
    for (int i = 0; i < F.size(); i++) {
      int foo;
      cin >> foo;
      F.updateRange(i,i,foo);
    }
  };
}F;

int id2() {
  int hi = n;
  int lo = 1;
  int cnt = 0;
  if (F.getSum(n - 1,n - 1) == 0) {
    return 0;
  }
  if (F.getSum(0, n - 1) == n) {
    return n;
  }
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    if (F.getSum(n - mid, n - 1) == mid) {
      lo = mid;
    } else {
      hi = mid;
    }
    cnt++;
    if (cnt > 1000) {
      break;
    }
  }
  return lo;
}

int main() {
  cin >> n;
  cout << "1" << " ";
  for (int i = 0; i < n; i++) {
    int foo;
    in >> foo;
    F.updateRange(foo - 1,foo - 1, 1);
    int sub = id2();
    

    

    if (sub == n) {
      cout << 1;
      break;
    }
    out << F.getSum(0, n - 1 - sub) + 1 << ' ';
  }
}