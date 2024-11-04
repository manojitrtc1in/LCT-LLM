














































using namespace std;




















template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}



typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

constexpr int MOD = 998244353;

constexpr int id0(int x){
  if(x==0) return 1012924417;
  if(x==1) return 924844033;
  if(x==2) return 998244353;
  if(x==3) return 897581057;
  if(x==4) return 645922817;
}
constexpr int brts(int x){
  if(x==0) return 5;
  if(x==1) return 5;
  if(x==2) return 3;
  if(x==3) return 3;
  if(x==4) return 3;
}
 
template<int X>
struct NTT{
  static constexpr int md = id0(X);
  static constexpr int rt = brts(X);
 
  inline int add(int a,int b){
    a+=b;
    if(a>=md) a-=md;
    return a;
  }
  
  inline int mul(int a,int b){
    return 1LL*a*b%md;
  }
  
  inline int pow(int a,int b){
    int res=1;
    while(b){
      if(b&1) res=mul(res,a);
      a=mul(a,a);
      b>>=1;
    }
    return res;
  }
 
  inline int inv(int x){
    return pow(x,md-2);
  }
  
  vector<vector<int> > rts,rrts;
  
  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      int w=pow(rt,(md-1)/(i<<1));
      int rw=inv(w);
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=1;rrts[i][0]=1;
      for(int k=1;k<i;k++){
      rts[i][k]=mul(rts[i][k-1],w);
      rrts[i][k]=mul(rrts[i][k-1],rw);
      }
    }
  }
 
  void ntt(vector<int> &a,bool f,int n=-1){
    if(n==-1) n=a.size();
    assert((n&(n-1))==0);
    
    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(a[i],a[j]);
    }
 
    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
    for(int k=0;k<i;k++){
    int z=mul(a[i+j+k],f?rrts[i][k]:rts[i][k]);
    a[i+j+k]=add(a[j+k],md-z);
    a[j+k]=add(a[j+k],z);
    }
      }
    }
    
    if(f){
      int tmp=inv(n);
      for(int i=0;i<n;i++) a[i]=mul(a[i],tmp);
    }
  }
 
  vector<int> multiply(vector<int> &a,vector<int> &b){
    int need=a.size()+b.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    ensure_base(sz);
    
    vector<int> f(sz),g(sz);
    for(int i=0;i<(int)a.size();i++) f[i]=a[i];
    for(int i=0;i<(int)b.size();i++) g[i]=b[i];
    ntt(f,0);ntt(g,0);
    for(int i=0;i<sz;i++) f[i]=mul(f[i],g[i]);
    ntt(f,1);
 
    f.resize(need);
    return f;
  }
  
};

void add(int &a, int b){
  a = ((a+b) % MOD + MOD) % MOD;
}

inline int mul(int a, int b) {
    add(a,0); add(b,0);
    
      return (int) ((long long) a * b % MOD);
    
      unsigned long long x = (long long) a * b;
      unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (MOD)
      );
      return m;
}

inline int modpow(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
      }
      a = mul(a, a);
      b >>= 1;
  }
  return res;
}

inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

int cmb(int N, int K){
  int res = 1;
  REP(i,K){
    res = mul(res,N-i);
    res = mul(res,inv(i+1));
  }
  return res;
}



void solve(){
  int N;
  cin >> N;

  vector<int> fact(201010,1);
  REP(i,201000) fact[i+1] = mul(fact[i],i+1); 

  vector<int> a = {1};
  REP(i,N){
    int x,y;
    cin >> x >> y;
    int c = mul(fact[x+y],inv(mul(fact[(x+y)/2],fact[x+y-(x+y)/2])));
    int K = (x+y+1)/2;
    NTT<2> ntt;
    vector<int> b(min(x+y+1,(i+1)*10 + (x+y+1)%2));
    int l = (b.size()-1)/2, r = b.size()/2;
    while(l>=0){
      b[l] = b[r] = c;
      l--; r++;
      c = mul(c,(x+y)-K);
      c = mul(c,inv(K+1));
      K++;
    }
    vec res = ntt.multiply(a,b);

    int len = a.size() + x - y;
    vec tmp; int v = (res.size() - len) / 2;
    FOR(i,v,res.size()-v) tmp.emplace_back(res[i]);
    a = tmp;
  }

  int ans = 0;
  for(int v:a) add(ans,v);

  cout << ans << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  


  while(T--) solve();

  return 0;
}