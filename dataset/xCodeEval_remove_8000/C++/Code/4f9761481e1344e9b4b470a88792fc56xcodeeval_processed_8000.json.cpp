



using namespace std;















using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void id3(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void id3(vector<int>&ord,Head&& head, Tail&&... tail){
  id3(ord, head);
  id3(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll id2(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};


int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int id5(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll id4(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
  }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};
using modint = ModInt< MOD9 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}


struct UnionFind {
  vector<ll> data;
  ll num;
  UnionFind(ll size) : data(size, -1) ,num(size){ }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
	  num--;
    }
    return x != y;
  }
  bool find(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(int x) {
    return -data[root(x)];
  }
  vector<vector<int>>groups(){
    vector<vector<int>>ret(data.size());
    for(int i=0;i<data.size();i++){
      ret[root(i)].push_back(i);
    }
    return ret;
  }
  void print(){
    auto tmp=groups();
    for(int i=0;i<data.size();i++){
      if(!tmp[i].empty()){
        for(auto z:tmp[i])cout<<z<<",";
        cout<<endl;
      }
    }
  }
};
template<typename T>
struct SCC{
  int n;
  const Graph<T>&G;
  vector<int>index;

  vector<int>start,visited,low,ord;
  int now_ord,group_num;
  SCC(const Graph<T> &g):G(g),n(g.size()){
    index.assign(n,-1);
    build();
  }
  void build(){
    low.assign(n,0);ord.assign(n,-1);index.assign(n,0);
    visited.reserve(n);
    now_ord=0,group_num=0;
    for(int i=0;i<n;i++){
      if(ord[i]==-1)dfs(i);
    }
    for(auto& x:index)x=group_num-1-x;
  }
  void dfs(int v){
    low[v]=ord[v]=now_ord++;
    visited.push_back(v);
    for(auto to:G[v]){
      if(ord[to]==-1){
        dfs(to);
        low[v]=min(low[v],low[to]);
      }
      else{
        low[v]=min(low[v],ord[to]);
      }
    }
    if(low[v]==ord[v]){
      while(1){
        int u=visited.back();
        visited.pop_back();
        ord[u]=n;
        index[u]=group_num;
        if(u==v)break;
      }
      group_num++;
    }

  }
  Graph<T>scc_graph;
  void build_edges(){
    scc_graph.resize(*max_element(index.begin(),index.end())+1);
    for(int i=0;i<n;i++){
      for(int j=0;j<G[i].size();j++){
        if(index[i]!=index[G[i][j]]){
          scc_graph[index[i]].emplace_back(index[G[i][j]], G[i][j].cost, G[i][j].id);
        }
      }
    }
  }
  vector<int>compsize(){
    vector<int>ret(*max_element(index.begin(),index.end())+1);
    for(int i=0;i<n;i++)ret[index[i]]++;
    return ret;
  }
  vector<int>output(){return index;};
};
template< typename Mint >
struct id1 {

  vector< Mint > dw, idw;
  int max_base;
  Mint root;

  id1() {
    const unsigned mod = Mint::get_mod();
    assert(mod >= 3 && mod % 2 == 1);
    auto tmp = mod - 1;
    max_base = 0;
    while(tmp % 2 == 0) tmp >>= 1, max_base++;
    root = 2;
    while(root.pow((mod - 1) >> 1) == 1) root += 1;
    assert(root.pow(mod - 1) == 1);
    dw.resize(max_base);
    idw.resize(max_base);
    for(int i = 0; i < max_base; i++) {
      dw[i] = -root.pow((mod - 1) >> (i + 2));
      idw[i] = Mint(1) / dw[i];
    }
  }

  void ntt(vector< Mint > &a) {
    const int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    assert(__builtin_ctz(n) <= max_base);
    for(int m = n; m >>= 1;) {
      Mint w = 1;
      for(int s = 0, k = 0; s < n; s += 2 * m) {
        for(int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j] * w;
          a[i] = x + y, a[j] = x - y;
        }
        w *= dw[__builtin_ctz(++k)];
      }
    }
  }

  void intt(vector< Mint > &a, bool f = true) {
    const int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    assert(__builtin_ctz(n) <= max_base);
    for(int m = 1; m < n; m *= 2) {
      Mint w = 1;
      for(int s = 0, k = 0; s < n; s += 2 * m) {
        for(int i = s, j = s + m; i < s + m; ++i, ++j) {
          auto x = a[i], y = a[j];
          a[i] = x + y, a[j] = (x - y) * w;
        }
        w *= idw[__builtin_ctz(++k)];
      }
    }
    if(f) {
      Mint inv_sz = Mint(1) / n;
      for(int i = 0; i < n; i++) a[i] *= inv_sz;
    }
  }

  vector< Mint > multiply(vector< Mint > a, vector< Mint > b) {
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    int sz = 1 << nbase;
    a.resize(sz, 0);
    b.resize(sz, 0);
    ntt(a);
    ntt(b);
    Mint inv_sz = Mint(1) / sz;
    for(int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
    intt(a, false);
    a.resize(need);
    return a;
  }
};
template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;

  using MULT = function< P(P, P) >;
  using FFT = function< void(P &) >;
  using SQRT = function< T(T) >;

  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }

  static void set_mult(MULT f) {
    get_mult() = f;
  }

  static FFT &get_fft() {
    static FFT fft = nullptr;
    return fft;
  }

  static FFT &get_ifft() {
    static FFT ifft = nullptr;
    return ifft;
  }

  static void set_fft(FFT f, FFT g) {
    get_fft() = f;
    get_ifft() = g;
  }

  static SQRT &get_sqrt() {
    static SQRT sqr = nullptr;
    return sqr;
  }

  static void set_sqrt(SQRT sqr) {
    get_sqrt() = sqr;
  }

  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  P operator+(const P &r) const { return P(*this) += r; }

  P operator+(const T &v) const { return P(*this) += v; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator-(const T &v) const { return P(*this) -= v; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P operator%(const P &r) const { return P(*this) %= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    

    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    

    return *this;
  }

  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
	 if(min(this->size(), r.size()) < 5 || get_mult() == nullptr){
      P ret(this->size() + r.size() - 1);
      for(int i = 0; i < this->size(); i++){
        for(int j = 0; j < r.size(); j++){
          ret[i + j] += (*this)[i] * r[j];
        }
      }
      return *this = ret;
    }
    return *this = get_mult()(*this, r);
  }

  P &operator%=(const P &r) { return *this -= *this / r * r; }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P dot(P r) const {
    P ret(min(this->size(), r.size()));
    for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  P pre(int sz) const { return P(begin(*this), begin(*this) + min((int) this->size(), sz)); }

  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }

  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
    return ret;
  }

  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
    return ret;
  }

  

  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if(get_fft() != nullptr) {
      P ret(*this);
      ret.resize(deg, T(0));
      return ret.inv_fast();
    }
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  

  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  P sqrt(int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2);
          if(ret.empty()) return {};
          ret = ret << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }

    P ret;
    if(get_sqrt() == nullptr) {
      assert((*this)[0] == T(1));
      ret = {T(1)};
    } else {
      auto sqr = get_sqrt()((*this)[0]);
      if(sqr * sqr != (*this)[0]) return {};
      ret = {T(sqr)};
    }

    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }

  

  P exp(int deg = -1) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if(get_fft() != nullptr) {
      P ret(*this);
      ret.resize(deg, T(0));
      return ret.exp_rec();
    }
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }


  P online_convolution_exp(const P &conv_coeff) const {
    const int n = (int) conv_coeff.size();
    assert((n & (n - 1)) == 0);
    vector< P > id0;
    auto& fft = get_fft();
    auto& ifft = get_ifft();
    for(int i = n; i >= 1; i >>= 1) {
      P g(conv_coeff.pre(i));
      fft(g);
      id0.emplace_back(g);
    }
    P conv_arg(n), conv_ret(n);
    auto rec = [&](auto rec, int l, int r, int d) -> void {
      if(r - l <= 16) {
        for(int i = l; i < r; i++) {
          T sum = 0;
          for(int j = l; j < i; j++) sum += conv_arg[j] * conv_coeff[i - j];
          conv_ret[i] += sum;
          conv_arg[i] = i == 0 ? T(1) : conv_ret[i] / i;
        }
      } else {
        int m = (l + r) / 2;
        rec(rec, l, m, d + 1);
        P pre(r - l);
        for(int i = 0; i < m - l; i++) pre[i] = conv_arg[l + i];
        fft(pre);
        for(int i = 0; i < r - l; i++) pre[i] *= id0[d][i];
        ifft(pre);
        for(int i = 0; i < r - m; i++) conv_ret[m + i] += pre[m + i - l];
        rec(rec, m, r, d + 1);
      }
    };
    rec(rec, 0, n, 0);
    return conv_arg;
  }

  P exp_rec() const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    int m = 1;
    while(m < n) m *= 2;
    P conv_coeff(m);
    for(int i = 1; i < n; i++) conv_coeff[i] = (*this)[i] * i;
    return online_convolution_exp(conv_coeff).pre(n);
  }


  P inv_fast() const {
    assert(((*this)[0]) != T(0));

    const int n = (int) this->size();
    P res{T(1) / (*this)[0]};

    for(int d = 1; d < n; d <<= 1) {
      P f(2 * d), g(2 * d);
      for(int j = 0; j < min(n, 2 * d); j++) f[j] = (*this)[j];
      for(int j = 0; j < d; j++) g[j] = res[j];
      get_fft()(f);
      get_fft()(g);
      for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
      get_ifft()(f);
      for(int j = 0; j < d; j++) {
        f[j] = 0;
        f[j + d] = -f[j + d];
      }
      get_fft()(f);
      for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
      get_ifft()(f);
      for(int j = 0; j < d; j++) f[j] = res[j];
      res = f;
    }
    return res.pre(n);
  }

  P pow(int64_t k, int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    for(int i = 0; i < n; i++) {
      if((*this)[i] != T(0)) {
        T rev = T(1) / (*this)[i];
        P ret = (((*this * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));
        if(i * k > deg) return P(deg, T(0));
        ret = (ret << (i * k)).pre(deg);
        if(ret.size() < deg) ret.resize(deg, T(0));
        return ret;
      }
    }
    return *this;
  }

  T eval(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }

  P pow_mod(int64_t n, P mod) const {
    P modinv = mod.rev().inv();
    auto get_div = [&](P base) {
      if(base.size() < mod.size()) {
        base.clear();
        return base;
      }
      int n = base.size() - mod.size() + 1;
      return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);
    };
    P x(*this), ret{1};
    while(n > 0) {
      if(n & 1) {
        ret *= x;
        ret -= get_div(ret) * mod;
      }
      x *= x;
      x -= get_div(x) * mod;
      n >>= 1;
    }
    return ret;
  }
    void mul(vector<pair<int, T>> g, bool extend = false){
    if(extend)this->resize(this->size() + g.back().first);
    int n = this->size();
    int d = g[0].first;
    T c = g[0].second;
    if(d == 0)g.erase(g.begin());
    else c = 0;
    for(int i = n - 1; i >= 0; i--){
      (*this)[i] *= c;
      for(auto z : g){
        if(z.first > i)continue;
        (*this)[i] += (*this)[i-z.first] * z.second;
      }
    }
  }
  void div(vector<pair<int, T>>g){

    int n = this->size();
    int d = g[0].first;
    T c = g[0].second;
    c = T(1) / c;
    g.erase(g.begin());
    for(int i = 0; i < n; i++){
      for(auto z : g){
        if(z.first > i)continue;
        (*this)[i] -= (*this)[i-z.first] * z.second;
      }
      (*this)[i] *= c;
    }
  }
};




int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  using FPS=FormalPowerSeries<modint>;
  id1<modint> ntt;
  auto mult=[&](const FPS &x,const FPS &y){
    auto ret = ntt.multiply(x,y);
    return FPS(ret.begin(),ret.end());
  };
  FPS::set_mult(mult);
  FPS::set_fft([&](FPS &a){return ntt.ntt(a);},[&](FPS &b){return ntt.intt(b);});

  ll n,m,k;cin>>n>>m>>k;
  UnionFind uf(k);
  Graph<int>g(k);
  vector<set<int>>gs(k);
  rep(i,0,n){
    ll sz;cin>>sz;
    vector<ll>v(sz);
    rep(j,0,sz)cin>>v[j],v[j]--;
    rep(j,0,sz-1){
      uf.unite(v[j],v[j+1]);
      if(!gs[v[j]].count(v[j+1])){
        g[v[j]].EB(v[j+1]);
        gs[v[j]].insert(v[j+1]);
      }
    }
  }
  vector<bool>t(k,true);
  SCC scc(g);
  auto s=scc.compsize();
  auto rg=revgraph(g);
  rep(i,0,k){
    

    if(g[i].size()>=2)t[uf.root(i)]=false;
    if(rg[i].size()>=2)t[uf.root(i)]=false;
    if(s[scc.index[i]]>=2)t[uf.root(i)]=false;
  }
  rep(i,0,k){
    for(auto to:g[i]){
      

      if(i==to)t[uf.root(i)]=false;
    }
  }
  FPS f(max(k,m)+1);
  rep(i,0,k)if(i==uf.root(i)&&t[i])f[uf.size(i)]+=1;
  f=(FPS{1}-f).inv();
  cout<<f[m]<<endl;
  return 0;
}