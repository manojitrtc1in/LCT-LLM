































using namespace std;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;










int scan(){ return getchar(); }
void scan(int& a){ cin>>a; }
void scan(long long& a){ cin>>a; }
void scan(char &a){cin>>a;}
void scan(double &a){ cin>>a; }
void scan(long double& a){ cin>>a; }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void IN(){}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail){ scan(head); IN(tail...); }
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vi iota(int n){vi a(n);iota(all(a),0);return a;}
template<class T> void UNIQUE(vector<T> &x){sort(all(x));x.erase(unique(all(x)),x.end());}
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T> void print(set<T> &x){for(auto e:x)print(e),cout<<" ";cout<<endl;}
template<class T> void print(multiset<T> &x){for(auto e:x)print(e),cout<<" ";cout<<endl;}
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}



    
    
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }

    
    template<class... T> void err(const T&...){}


struct Setup_io{ Setup_io(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);}}setup_io;







template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

UnWeightedGraph make(int n,int m,int offset=1){
    UnWeightedGraph res(n);
    for(int i = 0;i<m;++i){
        int a,b; cin>>a>>b;
        a-=offset,b-=offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}

template< typename T >
WeightedGraph<T> make2(int n,int m,int offset=1){
    WeightedGraph<T> res(n);
    for(int i = 0;i<m;++i){
        int a,b;cin>>a>>b;
        T c;cin>>c;
        res[a].emplace_back(b,c);
        res[b].emplace_back(a,c);
    }
}




template< typename G >
struct id2 {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  id2(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};



vector<int> id0(const int N, const int Q=17, const int L=1<<15) {
  using u8 = unsigned char;
  static const int rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
  struct P { 
    P(int p) : p(p) {}
    int p; int pos[8];
  };
  auto id3 = [] (const int N) -> int {
    return N > 60184 ? N / (log(N) - 1.1)
                     : max(1., N / (log(N) - 1.11)) + 1;
  };

  const int v = sqrt(N), vv = sqrt(v);
  vector<bool> isp(v + 1, true);
  for (int i = 2; i <= vv; ++i) if (isp[i]) {
    for (int j = i * i; j <= v; j += i) isp[j] = false;
  }

  const int rsize = id3(N + 30);
  vector<int> primes = {2, 3, 5}; int psize = 3;
  primes.resize(rsize);

  vector<P> sprimes; size_t pbeg = 0;
  int prod = 1; 
  for (int p = 7; p <= v; ++p) {
    if (!isp[p]) continue;
    if (p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
    auto pp = P(p); 
    for (int t = 0; t < 8; ++t) {
      int j = (p <= Q) ? p : p * p;
      while (j % 30 != rs[t]) j += p << 1;
      pp.pos[t] = j / 30;
    }
    sprimes.push_back(pp);
  }

  vector<u8> pre(prod, 0xFF);
  for (size_t pi = 0; pi < pbeg; ++pi) {
    auto pp = sprimes[pi]; const int p = pp.p;
    for (int t = 0; t < 8; ++t) {
      const u8 m = ~(1 << t);
      for (int i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
    }
  }

  const int block_size = (L + prod - 1) / prod * prod;
  vector<u8> block(block_size); u8* pblock = block.data();
  const int M = (N + 29) / 30;

  for (int beg = 0; beg < M; beg += block_size, pblock -= block_size) {
    int end = min(M, beg + block_size);
    for (int i = beg; i < end; i += prod) {
      copy(pre.begin(), pre.end(), pblock + i);
    }
    if (beg == 0) pblock[0] &= 0xFE;
    for (size_t pi = pbeg; pi < sprimes.size(); ++pi) {
      auto& pp = sprimes[pi];
      const int p = pp.p;
      for (int t = 0; t < 8; ++t) {
        int i = pp.pos[t]; const u8 m = ~(1 << t);
        for (; i < end; i += p) pblock[i] &= m;
        pp.pos[t] = i;
      }
    }
    for (int i = beg; i < end; ++i) {
      for (int m = pblock[i]; m > 0; m &= m - 1) {
        primes[psize++] = i * 30 + rs[__builtin_ctz(m)];
      }
    }
  }
  assert(psize <= rsize);
  while (psize > 0 && primes[psize - 1] > N) --psize;
  primes.resize(psize);
  return primes;
}



class id1 {
  using u32 = unsigned int;
  using u64 = unsigned long long int;
  std::vector<u64> tbl[65];
  public:

  id1() {
    for(u32 t = 2; t < (1<<16); t++){
      u64 s = t * t;
      s = s * s;
      for(int k = 4; ; k++){
        tbl[k].push_back(s);
        if(__builtin_umulll_overflow(s, t, &s)) break;
      }
    }
  }



  u64 sqrt(u64 n){
    if(n == -1ULL) return -1U;
    u64 x = std::sqrt(n);
    return x * x > n ? x - 1 : x;
  }


  u64 cbrt(u64 n){
    return std::cbrt(n);
  }

  u64 operator()(u64 n, int k){
    if(k == 1 || n == 0) return n;
    if(k == 2) return sqrt(n);
    if(k == 3) return cbrt(n);
    int lb = -1;
    int ub = tbl[k].size();
    while(ub - lb > 1){
      int m = (lb + ub) / 2;
      if(tbl[k][m] > n) ub = m;
      else lb = m;
    }
    return lb + 2;
  }
  
};
signed main(){
    INT(Q);
    id1 kroot;
    vector<ll> v;
    constexpr ll INF = 1e18;
    vi used(1000001);
    rep2(i,1,1000){
        used[i*i] = true;
    }
    rep2(i,3,60){
        if(~i&1) continue;
        rep2(j,2,1000000){
            if(used[j]) continue;
            bool flag = true;
            ll tmp = 1;
            rep(k,i){
                if(tmp > INF/j) {flag = false;break;}
                tmp *= j;
                if(k == i-1) v.eb(tmp);
            }
            if(!flag) break;
        }
    }
    UNIQUE(v);
    function<ll(ll)> solve = [&](ll x)->ll{
        ll ans = 0;
        ans += ub(v,x);
        return ans + kroot(x,2);
    };
    while(Q--){
        LL(l,r);
        l--;
        cout << solve(r) - solve(l) << endl;
    }
        
}
                    
