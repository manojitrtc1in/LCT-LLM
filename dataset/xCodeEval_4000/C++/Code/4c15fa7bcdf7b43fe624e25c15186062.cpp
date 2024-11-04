#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload5(a,b,c,d,e,name,...) name
#define overload4(a,b,c,d,name,...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each1(i,a) for(auto&&i:a)
#define each2(x,y,a) for(auto&&[x,y]:a)
#define each3(x,y,z,a) for(auto&&[x,y,z]:a)
#define each4(w,x,y,z,a) for(auto&&[w,x,y,z]:a)
#define each(...) overload5(__VA_ARGS__,each4,each3,each2,each1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),0_M)
#define elif else if
#define unless(a) if(!(a))
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T, class U> auto count(const T& a, const U& b){ return count(all(a), b); }
template<class T, class U> auto count_if(const T& a, U b){ return count_if(all(a), b); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> auto run_press(const T& a){ vector<pair<remove_const_t<remove_reference_t<decltype(a[0])>>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do a = getchar(); while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class... T> void in(T&... a){ (void)initializer_list<int>{ (scan(a), 0)... }; }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const complex<T>& a){ if(a.real() >= 0) print('+'); print(a.real()); if(a.imag() >= 0) print('+'); print(a.imag()); print('i'); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
int first(bool i = true){ return out(i?"first":"second"); }
int First(bool i = true){ return out(i?"First":"Second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }








enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};
template<typename Flow, typename Cost,
         Objective objective = Objective::MINIMIZE>
struct MinCostFlow{
  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}

  struct Edge{
    int src,dst;
    Flow flow,cap;
    Cost cost;
    int rev;
    Edge(int src,int dst,Flow cap,Cost cost,int rev):
      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}
    Flow residual_cap()const{return cap-flow;}
  };

  struct EdgePtr{
    int v,e;
    EdgePtr(int v,int e):v(v),e(e){}
  };

  int n;
  vector<vector<Edge>> G;
  vector<Flow> b;
  vector<Cost> p;

  MinCostFlow(int n):n(n),G(n),b(n,0){}

  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    assert(lower<=upper);
    G[src].emplace_back(src,dst,+upper,+cost*objective,r);
    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);
    return EdgePtr(src,e);
  }

  const Edge &get_edge(EdgePtr ep)const{return G[ep.v][ep.e];}

  void push(Edge &e,Flow amount){
    e.flow+=amount;
    G[e.dst][e.rev].flow-=amount;
  }

  void add_supply(int v,Flow amount){b[v]+=amount;}
  void add_demand(int v,Flow amount){b[v]-=amount;}

  Cost residual_cost(const Edge &e){
    return e.cost+p[e.src]-p[e.dst];
  }

  vector<int> excess_vs,deficit_vs;
  void saturate_negative(const Flow delta){
    for(auto &es:G){
      for(auto &e:es){
        Flow cap=e.residual_cap();
        cap-=cap%delta;
        if(cap<0 or residual_cost(e)<0){
          push(e,cap);
          b[e.src]-=cap;
          b[e.dst]+=cap;
        }
      }
    }

    excess_vs.clear();
    deficit_vs.clear();
    for(int v=0;v<n;v++){
      if(b[v]>0) excess_vs.emplace_back(v);
      if(b[v]<0) deficit_vs.emplace_back(v);
    }
  }

  const Cost unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  vector<Cost> dist;
  vector<Edge*> parent;

  struct P{
    Cost first;
    int second;
    P(Cost first,int second):first(first),second(second){}
    bool operator<(const P o)const{return first>o.first;}
  };

  priority_queue<P> pq;

  template<typename Predicate>
  void eliminate(vector<int> &vs,Predicate predicate){
    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));
  }

  bool dual(const Flow delta){
    eliminate(excess_vs, [&](int v){return b[v]<+delta;});
    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});

    dist.assign(n,unreachable);
    for(int v:excess_vs) pq.emplace(dist[v]=0,v);

    parent.assign(n,nullptr);
    auto emplace=[&](Edge& e){
      if(e.residual_cap()<delta) return;
      Cost nxt=dist[e.src]+residual_cost(e);
      if(nxt>=dist[e.dst]) return;
      pq.emplace(dist[e.dst]=nxt,e.dst);
      parent[e.dst]=&e;
    };

    farthest=0;
    int deficit_count=0;
    while(!pq.empty()){
      Cost d=pq.top().first;
      int v=pq.top().second;
      pq.pop();
      if(dist[v]<d) continue;
      farthest=d;

      if(b[v]<=-delta) deficit_count++;
      if(deficit_count>=(int)deficit_vs.size()) break;

      for(auto &e:G[v]) emplace(e);
    }
    pq=decltype(pq)();

    for(int v=0;v<n;v++)
      p[v]+=min(dist[v],farthest);

    return deficit_count>0;
  }

  void primal(const Flow delta){
    for(int t:deficit_vs){
      if(dist[t]>farthest) continue;
      Flow f=-b[t];
      int v;
      for(v=t;parent[v];v=parent[v]->src)
        chmin(f,parent[v]->residual_cap());
      chmin(f,b[v]);

      f-=f%delta;
      if(f<=0) continue;

      for(v=t;parent[v];){
        auto &e=*parent[v];
        push(e,f);
        int u=parent[v]->src;
        if(e.residual_cap()<=0) parent[v]=nullptr;
        v=u;
      }
      b[t]+=f;
      b[v]-=f;
    }
  }

  template<Flow SCALING_FACTOR=2>
  bool build(){
    p.resize(n);
    Flow max_flow=1;
    for(auto t:b) max_flow=max({max_flow,t,-t});
    for(auto &es:G)
      for(auto &e:es)
        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});

    Flow delta=1;
    while(delta<max_flow) delta*=SCALING_FACTOR;
    for(;delta;delta/=SCALING_FACTOR){
      saturate_negative(delta);
      while(dual(delta)) primal(delta);
    }

    return excess_vs.empty() and deficit_vs.empty();
  }

  template<typename T=Cost>
  T get_cost(){
    T res=0;
    for(auto &es:G)
      for(auto &e:es)
        res+=T(e.flow)*T(e.cost)/T(objective);
    return res/T(2);
  }
  template<typename T=Cost> T get_gain(){return get_cost();}

  vector<Cost> get_potential(){
    fill(p.begin(),p.end(),0);
    for(int i=0;i<n;i++)
      for(auto &es:G)
        for(auto &e:es)
          if(e.residual_cap()>0)
            chmin(p[e.dst],p[e.src]+e.cost);
    return p;
  }
};

template<typename Flow, typename Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;

int main(){
    LL(n,m);
    VEC(ll,a,n);
    MinCostFlow<ll,ll>g(n+1);
    rep(n)g.add_edge(n,i,-1,1,0);
    rep(m){
        LL(u,v);
        u--; v--;
        swap(u,v);
        g.add_edge(u,v,0,INF,a[u]-a[v]);
    }
    g.build();
    auto ans=g.get_potential();
    rep(n)ans[i]-=ans[n];
    ans.pop_back();
    rep(n)ans[i]+=a[i];
    out(ans);
}