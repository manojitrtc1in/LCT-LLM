

using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}



template<typename T>
struct id0{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  id0(Conv conv):conv(conv){}

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,T k){
    for(auto &a:as) a*=k;
    return as;
  }

  

  Poly inv(Poly as,int deg){
    assert(as[0]!=T(0));
    Poly rs({T(1)/as[0]});
    int sz=1;
    while(sz<deg){
      sz<<=1;
      Poly ts(min(sz,(int)as.size()));
      for(int i=0;i<(int)ts.size();i++) ts[i]=as[i];
      rs=sub(add(rs,rs),mul(mul(rs,rs),ts));
      rs.resize(sz);
    }
    return rs;
  }

  

  Poly div(Poly as,Poly bs){
    while(as.back()==T(0)) as.pop_back();
    while(bs.back()==T(0)) bs.pop_back();
    if(bs.size()>as.size()) return Poly();
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    int need=as.size()-bs.size()+1;
    Poly ds=mul(as,inv(bs,need));
    ds.resize(need);
    reverse(ds.begin(),ds.end());
    return ds;
  }

  

  Poly sqrt(Poly as,int deg){
    assert(as[0]==T(1));

    int sz=1;
    T inv2=T(1)/T(2);
    Poly ss({T(1)});
    while(sz<deg){
      sz<<=1;
      Poly ts(min(sz,(int)as.size()));
      for(int i=0;i<(int)ts.size();i++) ts[i]=as[i];
      ss=add(ss,mul(ts,inv(ss,sz)));
      ss.resize(sz);
      for(T &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly res(n-1);
    for(int i=1;i<n;i++) res[i-1]=as[i]*T(i);
    return res;
  }

  Poly integral(Poly as){
    int n=as.size();
    Poly res(n+1);
    res[0]=T(0);
    for(int i=0;i<n;i++) res[i+1]=as[i]/T(i+1);
    return res;
  }

  Poly exp(Poly as,int deg){
    Poly f({T(1)}),g({T(1)});

    int sz=1;
    while(sz<deg){
      g=sub(mul(g,T(2)),mul(f,mul(g,g)));
      g.resize(sz+1);
      Poly q=diff(as);
      q.resize(sz);
      Poly w=add(q,mul(g,sub(diff(f),mul(f,q))));
      w.resize(2*sz);
      f=add(f,mul(f,sub(as,integral(w))));
      f.resize(2*sz+1);
      sz<<=1;
    }
    return f;
  }

  

  Poly log(Poly as,int deg){
    Poly rs=integral(mul(diff(as),inv(as,deg)));
    rs.resize(deg);
    return rs;
  }

  Poly partition(int n){
    Poly rs(n+1);
    rs[0]=T(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=T(k%2?-1LL:1LL);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=T(k%2?-1LL:1LL);
    }
    return inv(rs,n+1);
  }
};



template<typename T,T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}

constexpr int id1(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = id1(X);
  static constexpr int rt = brts(X);
  using M = Mint<int, md>;
  vector< vector<M> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      M w=M(rt).pow((md-1)/(i<<1));
      M rw=w.inv();
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=M(1);rrts[i][0]=M(1);
      for(int k=1;k<i;k++){
        rts[i][k]=rts[i][k-1]*w;
        rrts[i][k]=rrts[i][k-1]*rw;
      }
    }
  }

  void ntt(vector<M> &as,bool f,int n=-1){
    if(n==-1) n=as.size();
    assert((n&(n-1))==0);
    ensure_base(n);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(as[i],as[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
          as[i+j+k]=as[j+k]-z;
          as[j+k]+=z;
        }
      }
    }

    if(f){
      M tmp=M(n).inv();
      for(int i=0;i<n;i++) as[i]*=tmp;
    }
  }

  vector<M> multiply(vector<M> as,vector<M> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    as.resize(sz,M(0));
    bs.resize(sz,M(0));

    ntt(as,0);ntt(bs,0);
    for(int i=0;i<sz;i++) as[i]*=bs[i];
    ntt(as,1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    vector<M> am(as.size()),bm(bs.size());
    for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
    for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
    vector<M> cm=multiply(am,bm);
    vector<int> cs(cm.size());
    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
    return cs;
  }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;

struct ArbitraryModConvolution{
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a,int b,int md){
    int res=1;
    a=a%md;
    while(b){
      if(b&1) res=(ll)res*a%md;
      a=(ll)a*a%md;
      b>>=1;
    }
    return res;
  }

  static constexpr int inv(int x,int md){
    return pow(x,md-2,md);
  }

  inline void garner(int &c0,int c1,int c2,int m01,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    c1=(ll)(c1-c0)*r01%ntt1.md;
    if(c1<0) c1+=ntt1.md;

    c2=(ll)(c2-c0)*r02%ntt2.md;
    c2=(ll)(c2-c1)*r12%ntt2.md;
    if(c2<0) c2+=ntt2.md;

    c0+=(ll)c1*ntt0.md%MOD;
    if(c0>=MOD) c0-=MOD;
    c0+=(ll)c2*m01%MOD;
    if(c0>=MOD) c0-=MOD;
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    int sz=cs[0].size();
    for(int i=0;i<sz;i++) garner(cs[0][i],cs[1][i],cs[2][i],m01,MOD);
  }

  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(as,bs);
    cs[1]=ntt1.multiply(as,bs);
    cs[2]=ntt2.multiply(as,bs);
    size_t sz=as.size()+bs.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }

  template<typename T,T MOD>
  decltype(auto) multiply(vector< Mint<T, MOD> > am,
                          vector< Mint<T, MOD> > bm){
    using M = Mint<T, MOD>;
    vector<int> as(am.size()),bs(bm.size());
    for(int i=0;i<(int)as.size();i++) as[i]=am[i].v;
    for(int i=0;i<(int)bs.size();i++) bs[i]=bm[i].v;
    vector<int> cs=multiply(as,bs,MOD);
    vector<M> cm(cs.size());
    for(int i=0;i<(int)cm.size();i++) cm[i]=M(cs[i]);
    return cm;
  }
};
NTT<0> ArbitraryModConvolution::ntt0;
NTT<1> ArbitraryModConvolution::ntt1;
NTT<2> ArbitraryModConvolution::ntt2;




signed id3(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,q;
  cin>>n>>m>>q;
  vector<int> ls(q),rs(q);
  for(int i=0;i<q;i++) cin>>ls[i]>>rs[i],ls[i]--;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  if(as==vector<int>(n,0)){
    for(int i=0;i<m;i++){
      if(i) cout<<" ";
      cout<<0;
    }
    cout<<endl;
    return 0;
  }

  vector<int> cs(n-m+1,0);
  for(int l:ls) cs[l]++;

  NTT<0> ntt;
  using M = NTT<0>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  id0<M> FPS(conv);

  vector<M> ps(as.size()),qs(cs.size());
  for(int i=0;i<(int)ps.size();i++) ps[i]=M(as[i]);
  for(int i=0;i<(int)qs.size();i++) qs[i]=M(cs[i]);

  auto bs=FPS.div(ps,qs);
  for(int i=0;i<m;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}


signed id4(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> cs(n);
  for(int i=0;i<n;i++) cin>>cs[i];

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  id0<M> FPS(conv);

  const int deg=1<<18;
  vector<M> as(deg,0);
  as[0]=M(1);
  for(int c:cs) as[c]-=M(4);

  auto bs=FPS.sqrt(as,deg);
  bs[0]+=M(1);

  vector<M> vs({2});

  auto ans=FPS.mul(vs,FPS.inv(bs,deg));
  for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
  cout<<flush;

  return 0;
}


signed id5(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k,n;
  cin>>k>>n;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  using M = Mint<int>;
  ArbitraryModConvolution arb;
  auto conv=[&](auto as,auto bs){return arb.multiply(as,bs);};
  id0<M> FPS(conv);

  const int sz=1<<17;
  vector<M> bs(sz,M(0));
  bs[0]=1;
  for(int x:xs) bs[x]-=M(1);
  cout<<FPS.inv(bs,k+1)[k]<<endl;
  return 0;
}


const int md = 998244353;
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

inline int sqrt(int a){
  if(a==0) return 0;
  if(pow(a,(md-1)/2)!=1) return -1;
  int q=md-1,m=0;
  while(~q&1) q>>=1,m++;
  mt19937 mt;
  int z=mt()%md;
  while(pow(z,(md-1)/2)!=md-1) z=mt()%md;
  int c=pow(z,q),t=pow(a,q),r=pow(a,(q+1)/2);
  while(m>1){
    if(pow(t,1<<(m-2))!=1)
      r=mul(r,c),t=mul(t,mul(c,c));
    c=mul(c,c);
    m--;
  }
  return min(r,md-r);
}

signed id2(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  id0<M> FPS(conv);

  int n,k;
  cin>>n>>k;

  vector<M> F(n+1);
  for(int i=0;i<=n;i++) cin>>F[i].v;

  const int deg = 1<<17;
  auto as=FPS.log(FPS.mul(F,F[0].inv()),deg);
  auto bs=FPS.exp(FPS.mul(as,M((md-1)/2)),deg);
  M s(sqrt(F[0].v));
  auto cs=FPS.integral(FPS.mul(bs,s.inv()));
  auto ds=FPS.exp(cs,deg);
  auto es=FPS.sub(F,ds);
  es[0]+=M(2);
  es[0]-=F[0];
  auto fs=FPS.log(es,deg);
  fs[0]+=M(1);
  auto gs=FPS.log(fs,deg);
  auto hs=FPS.mul(gs,M(k));
  auto is=FPS.exp(hs,deg);
  auto G=FPS.diff(is);

  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}


signed main(){
  

  id4();
  

  

  return 0;
}

