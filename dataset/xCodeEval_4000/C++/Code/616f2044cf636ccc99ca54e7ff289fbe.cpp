#include <bits/stdc++.h>

static struct FASTIO {

  char READ_CHARACTER; bool REMAINING_CHARACTER = false;

  inline void ignore(); inline void flush();

  template <typename T> inline bool READ_INT(T &x); template <typename T> inline bool READ_STRING(T &x);
  
  template<size_t N> inline bool READ_CHAR_ARRAY(char (&x)[N]); template<size_t N> inline bool READ_VAR(char (&x)[N]);
  
  template <typename T> inline bool READ_CHAR(T &x); inline bool READ_CHAR_ARRAY(char*& x); inline bool READ_GETLINE(std::string &x);
  
  template <typename T> inline bool READ_FLOAT(T &x); template <typename T> inline bool READ_DOUBLE(T &x);
  
  template<std::size_t N> inline bool READ_BITSET(std::bitset<N> &bit); template<std::size_t N> inline bool READ_VAR(std::bitset<N> &bit);
  inline bool READ_VAR(bool &x); inline bool READ_VAR(short int &x); inline bool READ_VAR(int &x); 
  inline bool READ_VAR(long int &x); inline bool READ_VAR(long long int &x); inline bool READ_VAR(unsigned short int &x);
  inline bool READ_VAR(unsigned int &x); inline bool READ_VAR(unsigned long &x); inline bool READ_VAR(unsigned long long &x);
  inline bool READ_VAR(std::string &x); inline bool READ_VAR(char &x); inline bool READ_VAR(char*& x); inline bool READ_VAR(float &x);
  inline bool READ_VAR(double &x); inline bool READ_VAR(long double &x); template <typename T> inline void WRITE_INT(T x);
  inline void WRITE_STRING(std::string &x); inline void WRITE_CHAR(char x); inline void WRITE_CHAR_ARRAY(const char *x);
  inline void WRITE_FLOAT(float x); template <typename T> inline void WRITE_DOUBLE(T x); inline void WRITE_VAR(bool x);
  inline void WRITE_VAR(short int x); inline void WRITE_VAR(int x); inline void WRITE_VAR(long int x); inline void WRITE_VAR(long long int x);
  inline void WRITE_VAR(unsigned short int x); inline void WRITE_VAR(unsigned int x); inline void WRITE_VAR(unsigned long x);
  inline void WRITE_VAR(unsigned long long x); inline void WRITE_VAR(char x); inline void WRITE_VAR(const char *x); 
  inline void WRITE_VAR(std::string &x); inline void WRITE_VAR(float x); inline void WRITE_VAR(double x); inline void WRITE_VAR(long double x);
  template<std::size_t N> inline void WRITE_VAR(std::bitset<N> &bit); template<std::size_t N> inline void WRITE_BITSET(std::bitset<N> &bit);

} __FIO__;

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio 0;0;0;
#define pb push_back
#define mp make_pair
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define rep(i,j,k) for(int i=j;i<k;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000  
#define M   1000000007  
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1LL;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
vector<pii> adj[100100];
vector<pii> mst[100100];
int n,m,k,q;
vector<int> p(100100);
vector<int> sz(100100);
struct node{
    int cost, u, origin;
    bool operator<(const node& y) const{
        return cost < y.cost;
    }
};
struct edge{
    int u,v,c;
    bool operator<(const edge& w){
        return c < w.c;
    }
};
int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}
void make_set(int v) {
    p[v] = v;
    sz[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

namespace LCA{
    int anc[18][100010];
    int mw[18][100010];
    int pai[100010],tin[100010],tout[100010];
    int tempo = 0;
    void dfs(int u,int p){
        pai[u] = p;
        anc[0][u] = p;
        tin[u] = tempo++;
        for(pii v : mst[u])
            if(v.ff != p){
                mw[0][v.ff] = v.ss;
                dfs(v.ff,u);
            }
        tout[u] = tempo++;
    }
    void precompute(){
        dfs(1,-1);
        for(int i=1;i<18;i++){
            for(int j=1;j<=n;j++){
                mw[i][j] = (anc[i-1][j] == -1 ? 0 : max(mw[i-1][anc[i-1][j]],mw[i-1][j]));
                anc[i][j] = (anc[i-1][j] == -1 ? -1 : anc[i-1][anc[i-1][j]]);       
            }
        }
    }
    bool is_anc(int x,int y){  
        return (tin[x] <= tin[y] && tout[x] >= tout[y]);    
    }
    int lca(int x,int y){
        if(is_anc(x,y)) return x;
        if(is_anc(y,x)) return y;

        int cur = x;
        for(int i=17;i>=0;i--){
            int k = anc[i][cur];
             
            if(k==-1) continue;
            if(!is_anc(k,y)){
                cur = k;
            }
        }
        return pai[cur];
    }
    int do_rmq(int x,int y){  
        int maximum_weight = -1;
        int cur = y;
        for(int i=17;i>=0;i--){
            int k = anc[i][cur];
            if(k==-1){
                continue;
            }
            if(!is_anc(k,x)){
                maximum_weight= max(maximum_weight,mw[i][cur]);
                cur = k;
            }
        }
        if(cur!=x) maximum_weight = max(maximum_weight,mw[0][cur]);
        return maximum_weight;
    }
    int rmq(int x,int y){
        if(x==y){
            return 0;
        }
        int z = lca(x,y);
        return max(do_rmq(z,x), do_rmq(z,y)); 
    }
}
main(){
    fastio;
    __FIO__.READ_VAR(n), __FIO__.READ_VAR(m), __FIO__.READ_VAR(k), __FIO__.READ_VAR(q);
    rep(i,0,n+1) make_set(i);
    vector<edge> edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        __FIO__.READ_VAR(a), __FIO__.READ_VAR(b), __FIO__.READ_VAR(c);
        edges.pb({a,b,c});
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    vector<int> dist(100100,(1LL<<62));
    priority_queue<pii,vector<pii>, greater<pii> > pq;
    rep(i,1,k+1){
        pq.push({0,i});
        dist[i] = 0;
    }
    while(!pq.empty()){
        pii w = pq.top();
        pq.pop();
        if(w.ff != dist[w.ss]) continue;
        for(pii &v : adj[w.ss])
            if(w.ff + v.ss < dist[v.ff]){
                dist[v.ff] = w.ff + v.ss;
                pq.push({dist[v.ff], v.ff});
            }
    }
    for(auto &x : edges)
        x.c += dist[x.u] + dist[x.v];
    
    sort(td(edges));
   
    for(auto &x : edges){
        if(find_set(x.u) != find_set(x.v)){
            mst[x.u].pb({x.v,x.c});
            mst[x.v].pb({x.u,x.c});
             
            union_sets(x.u,x.v);
            
        }
        
    }
    LCA::precompute();
    while(q--){
        int x,y;
        __FIO__.READ_VAR(x), __FIO__.READ_VAR(y);
        __FIO__.WRITE_VAR(LCA::rmq(x,y)), putchar('\n');
    }
    
}   

#undef ms
#undef frr
#undef rep
#undef td
#undef int
#undef double
#undef endl
#undef fastio
#undef pb
#undef mp
#undef ms
#undef pii
#undef ff
#undef ss
#undef frr
#undef rep
#undef td
#undef inf
#undef M

inline void FASTIO::ignore() {
  if(REMAINING_CHARACTER == true) REMAINING_CHARACTER = false; else READ_CHARACTER = getchar();
}

inline void FASTIO::flush() {
  fflush(stdout);
}




template <typename T>
inline bool FASTIO::READ_INT(T &x) {
  x = 0; T sig = 1;
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while (!isdigit(READ_CHARACTER) && READ_CHARACTER != EOF) sig = (READ_CHARACTER == '-' ? -sig : sig), READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while (isdigit(READ_CHARACTER)) x = x * 10 + READ_CHARACTER - '0', READ_CHARACTER = getchar();
  x *= sig; REMAINING_CHARACTER = true;
  return true;
}

template <typename T>
inline bool FASTIO::READ_STRING(T &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_GETLINE(std::string &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = false;
  return true;
}

template <typename T>
inline bool FASTIO::READ_CHAR(T &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  x = READ_CHARACTER; REMAINING_CHARACTER = false;
  return true;
}


template<size_t N>
inline bool FASTIO::READ_CHAR_ARRAY(char (&x)[N]) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  char *ptr = &x[0];
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) *ptr++ = READ_CHARACTER, READ_CHARACTER = getchar();
  *ptr = '\0', REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_CHAR_ARRAY(char*& x) {
  std::string y;
  if(READ_STRING(y) == false)
    return false;
  x = new char[(int)y.size() + 1];
  strcpy(x, y.c_str());
  return true;
}

template <typename T>
inline bool FASTIO::READ_FLOAT(T &x) {
  return (scanf("%f", &x) != EOF);
}

template <typename T>
inline bool FASTIO::READ_DOUBLE(T &x) {
  double y;
  if(scanf("%lf", &y) == EOF) return false;
  x = y;
  return true;
}

template<std::size_t N>
inline bool FASTIO::READ_BITSET(std::bitset<N> &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  int i = 0; REMAINING_CHARACTER = true;
  while (READ_CHARACTER == '0' || READ_CHARACTER == '1') x[i++] = READ_CHARACTER - '0', READ_CHARACTER = getchar();
  return true;
}

inline bool FASTIO::READ_VAR(short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(std::string &x) {
  return READ_STRING(x);    
}

inline bool FASTIO::READ_VAR(char &x) {
  return READ_CHAR(x);
}

template<size_t N>
inline bool FASTIO::READ_VAR(char (&x)[N]) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(char*& x) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(float &x) {
  return READ_FLOAT(x);
}

inline bool FASTIO::READ_VAR(double &x) {
  return READ_DOUBLE(x);
}

inline bool FASTIO::READ_VAR(long double &x) {
  return READ_DOUBLE(x);
}

template<std::size_t N>
inline bool FASTIO::READ_VAR(std::bitset<N> &x) {
  return READ_BITSET(x);
}




template <typename T>
inline void FASTIO::WRITE_INT(T x) {
  if (x < 0) {putchar('-'); x = -x; }
  char writeBuffer[20], *writePtr = writeBuffer;
  do {
    *writePtr++ = '0' + x % 10;
    x /= 10;
  }
  while (x);
  do  { putchar(*--writePtr); }
  while (writePtr > writeBuffer);
}

inline void FASTIO::WRITE_CHAR(char x) {
  putchar(x);
}

inline void FASTIO::WRITE_CHAR_ARRAY(const char *x) {
  while(*x != '\0')
    putchar(*x++);
}

inline void FASTIO::WRITE_STRING(std::string &x) {
  for(char c: x) 
    putchar(c);
}

inline void FASTIO::WRITE_FLOAT(float x) {
  printf("%f", x);
}

template <typename T>
inline void FASTIO::WRITE_DOUBLE(T x) {
  printf("%lf", (double)x);
}

template<std::size_t N>
inline void FASTIO::WRITE_BITSET(std::bitset<N> &x) {
  for(int i = (int)x.size() - 1; i >= 0; i--)
    putchar(x[i] + 48);
}

inline void FASTIO::WRITE_VAR(bool x) {
  WRITE_INT(x);
}

inline void FASTIO::WRITE_VAR(short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(std::string &x) {
  WRITE_STRING(x);    
}

inline void FASTIO::WRITE_VAR(char x) {
  WRITE_CHAR(x);
}

inline void FASTIO::WRITE_VAR(const char *x) {
  WRITE_CHAR_ARRAY(x);
}

inline void FASTIO::WRITE_VAR(float x) {
  WRITE_FLOAT(x);
}

inline void FASTIO::WRITE_VAR(double x) {
  WRITE_DOUBLE(x);
}

inline void FASTIO::WRITE_VAR(long double x) {
  WRITE_DOUBLE(x);
}

template<std::size_t N>
inline void FASTIO::WRITE_VAR(std::bitset<N> &x) {
  WRITE_BITSET(x);
}  


