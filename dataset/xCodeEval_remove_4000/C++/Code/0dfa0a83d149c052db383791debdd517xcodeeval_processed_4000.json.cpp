
using namespace std;



























int low(V<int> &a,int b){
  auto c=lower_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
int upp(V<int> &a,int b){
  auto c=upper_bound(a.begin(),a.end(),b);
  int d=c-a.bgn;
  return d;
}
template<class T>
 void cou(vector<vector<T>> a){
  int b=a.size();
  int c=a[0].size();
  fo(i,b){
    fo(j,c){
      cout<<a[i][j];
      if(j==c-1)
        cout<<endl;
      else
        cout<<' ';
    }
  }
}
int wari(int a,int b) {
  if(a%b==0)
    return a/b;
  else
    return a/b+1;
}
int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
int souwa(int a){
  return a*(a+1)/2;
}
int gcm(int a,int b){
  if(a%b==0)
    return b;
  return gcm(b,a%b);
}
bool prime(int a){
  if(a<2)
    return false;
  else if(a==2)
    return true;
  else if(a%2==0)
    return false;
  for(int i=3;i<=sqrt(a)+1;i+=2){
    if (a%i==0)
      return false;
  }
  return true;
}
struct Union{
  vector<int> par;
  Union(int a){
  par=vector<int>(a,-1);
  }
  int find(int a){
    if(par[a]<0)
      return a;
    else
      return par[a]=find(par[a]);
  }
  bool same(int a,int b){
    return find(a)==find(b);
  }
  int Size(int a){
    return -par[find(a)];
  }
  void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
      return;
    if(Size(b)>Size(a))
      swap<int>(a,b);
    par[a]+=par[b];
    par[b]=a;
  }
};
int ketas(int a){
  string b=to_string(a);
  int c=0;
  fo(i,keta(a)){
    c+=b[i]-'0';
  }
  return c;
}
bool fe(int a,int b){
  a%=10;
  b%=10;
  if(a==0)
    a=10;
  if(b==0)
    b=10;
  if(a>b)
    return true;
  else
    return false;
}
int INF=1000000007;
struct edge{int s,t,d; };
V<int> id4(string a){
  V<int> b(26,0);
  fo(i,a.sz){
    b[a[i]-'a']++;
  }
  return b;
}
int wa2(int a){
  if(a%2==1)
    return a/2;
  return a/2-1;
}

int nCr(int n,int r){
  int a=1;
  r=min(r,n-r);
  for(int i=n;i>n-r;i--){
    a*=i;
    a/=n-i+1;
  }
  return a;
}

int id1(int a){
  int b=1;
  fo(i,a)
    b*=i+1;
  return b;
}
int nPr(int a,int b){
  if(a<b)
    return 0;
  if(b==0)
    return 1;
  int c=1;
  for(int i=a;i>a-b;i--){
    c*=i;
    c%=INF;
  }
  return c;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 


long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
 
int lcm(int a,int b){
  int c=modinv(gcm(a,b),INF);
  return ((a*c)%INF)*(b%INF)%INF;
}
int MOD=INF;
int fac[1000010], finv[1000010], inv[1000010]; 






void COMinit() {
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<1000010;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}


int COM(int n,int k){
  if(n<k)
    return 0;
  if(n<0||k<0)
    return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
bool naka(int a,int b,V<V<char>> c){
  return (a>=0&&b>=0&&a<c.sz&&b<c[0].sz);
}
 
V<P<int,int>> id2={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,-1}};
int inf=1000000000000000007;
 
V<P<int,int>> id6={{0,-1},{0,1},{1,0},{-1,0}};













V<int> id0(string a){
  V<int> b(a.sz);
  for(int i=1,j=0;i<a.sz;i++){
    if(i+b[i-j]<j+b[j])
      b[i]=b[i-j];
    else{
      int c=max<int>(0,j+b[j]-i);
      while(i+c<a.sz&&a[c]==a[i+c])
        c++;
      b[i]=c;
      j=i;
    }
  }
  b[0]=a.sz;
  return b;
}






V<int> color(200005);
bool id7(int a,int b,V<V<int>> c){
  color[a]=b;
  fo(i,c[a].sz){
    if(b==color[c[a][i]])
      return false;
    if(color[c[a][i]]==0&&!id7(c[a][i],-b,c))
      return false;
  }
  return true;
}






bool id9(int a,V<V<int>> c){
  fo(i,a){
    if(color[i]==0){
      if(!id7(i,1,c))
        return false;
    }
  }
  return true;
}
struct segmin{
  vector<int> seg;
  int b;
  segmin(V<int> a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<int>(2*b-1,inf);
    fo(i,a.sz){
      seg[i+b-1]=a[i];
    }
    for(int i=b-2;i>=0;i--){
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
  }
  void update(int i,int a){
    i+=b-1;
    seg[i]=a;
    while(i){
      i=(i-1)/2;
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
  }
  

  

  int getmin(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return INF;
    if(x<=l&&r<=y)
      return seg[a];
    int a1=getmin(x,y,2*a+1,l,(l+r)/2);
    int a2=getmin(x,y,2*a+2,(l+r)/2,r);
    return min(a1,a2);
  }
};
struct segadd{
  vector<int> seg;
  int b;
  segadd(V<int> a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<int>(2*b-1,0);
    fo(i,a.sz){
      seg[i+b-1]=a[i];
    }
    for(int i=b-2;i>=0;i--){
      seg[i]=seg[2*i+1]+seg[2*i+2];
    }
  }
  void update(int i,int a){
    i+=b-1;
    seg[i]=a;
    while(i){
      i=(i-1)/2;
      seg[i]=seg[2*i+1]+seg[2*i+2];
    }
  }
  

  

  int getadd(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return 0;
    if(x<=l&&r<=y)
      return seg[a];
    int a1=getadd(x,y,2*a+1,l,(l+r)/2);
    int a2=getadd(x,y,2*a+2,(l+r)/2,r);
    return a1+a2;
  }
};
struct sege{
  vector<P<int,V<int>>> seg;
  int b;
  sege(string a){
    b=1;
    while(b<a.sz)
      b*=2;
    seg=vector<P<int,V<int>>>(2*b-1);
    fo(i,a.sz){
      seg[i+b-1].fi=1;
      seg[i+b-1].se.pb(a[i]-'a');
    }
    for(int i=b-2;i>=0;i--){
      V<int> d=seg[2*i+1].se;
      fo(j,seg[2*i+2].se.sz){
        d.pb(seg[2*i+2].se[j]);
      }
      Sort(d);
      uni(d);
      seg[i].se=d;
      seg[i].fi=d.sz;
    }
  }
  V<int> mu;
  void update(int i,char a){
    i+=b-1;
    seg[i].se=mu;
    seg[i].se.pb(a-'a');
    seg[i].fi=1;
    while(i){
      i=(i-1)/2;
      V<int> d=seg[2*i+1].se;
      fo(j,seg[2*i+2].se.sz){
        d.pb(seg[2*i+2].se[j]);
      }
      Sort(d);
      uni(d);
      seg[i].se=d;
      seg[i].fi=d.sz;
    }
  }
  void unko(){
    fo(i,2*b-1)
    cout<<seg[i].fi<<' ';
  }
  

  

  P<int,V<int>> gete(int x,int y,int a,int l,int r){
    if(r==INF)
      r=b;
    if(r<=x||y<=l)
      return {0,mu};
    if(x<=l&&r<=y)
      return seg[a];
    P<int,V<int>> a1=gete(x,y,2*a+1,l,(l+r)/2);
    P<int,V<int>> a2=gete(x,y,2*a+2,(l+r)/2,r);
    fo(i,a2.se.sz)
    a1.se.pb(a2.se[i]);
    Sort(a1.se);
    uni(a1.se);
    return {a1.se.sz,a1.se};
  }
};


int id10(int a,int b,int c){
  a%=c;
  b%=c;
  if(b==0)
    return 1;
  if(b%2==0){
    int d=id10(a,b/2,c);
    d%=c;
    return d*d%c;
  }
  return a*id10(a,b-1,c)%c;
}
int waINF(int a){
  if(a>=0)
    return a%INF;
  return (a+INF*INF)%INF;
}



bool id5(V<P<P<int,int>,int>> a,V<int> b){
  V<int> d(b.sz,1),e;
  fo(i,3*b.sz){
    fo(j,a.sz){
      P<P<int,int>,int> c=a[j];
      if(b[c.ff]!=inf&&b[c.fs]>b[c.ff]+c.se){
        b[c.fs]=b[c.ff]+c.se;
        if(i>=b.sz-1&&d[c.ff]){
          d[c.ff]=0;
          e.pb(c.ff);
        }
        if(i>=b.sz-1&&d[c.fs]){
          d[c.fs]=0;
          e.pb(c.fs);
        }
      }
    }
  }
  if(e.sz==0)
  return 0;
  Union f(b.sz);
  fo(i,e.sz-1){
    f.unite(e[i],e[i+1]);
  }
  fo(j,b.sz){
  fo(i,a.sz){
    if(f.same(a[i].ff,e[0])){
      f.unite(e[0],a[i].fs);
    }
  }
  }
  if(f.same(e[0],b.sz-1))
    return 1;
  return 0;
}


void id11(int a,int b,int c,int &d,int &e,V<V<int>> &f){
  if(c>d){
    d=c;
    e=b;
  }
  fo(i,f[b].sz){
    if(f[b][i]==a)
      continue;
    id11(b,f[b][i],c+1,d,e,f);
  }
}


int id8(V<V<int>> &a){
  int b=0,c=0,d=0;
  id11(-1,b,0,d,c,a);
  b=c,c=0,d=0;
  id11(-1,b,0,d,c,a);
  return d;
  

}


int id3(int a,int b,V<V<int>> &c){
  if(a==b)
    return 0;
  Q<int> e;
  e.push(a);
  V<int> d(c.sz,inf);
  d[a]=0;
  while(!d.empty()){
    int f=e.front();
    e.pop();
    fo(i,c[f].sz){
      if(d[c[f][i]]==inf){
        d[c[f][i]]=d[f]+1;
        if(c[f][i]==b)
          return d[c[f][i]];
        e.push(c[f][i]);
      }
    }
  }
}
signed main(){
  int a;
  cin>>a;
  fo(z,a){
    int b,c,d,c1,d1;
    cin>>b>>c>>d>>c1>>d1;
    c--;
    d--;
    V<V<int>> G(b);
    P<int,int> y;
    fo(i,b-1){
      cin>>y.fi>>y.se;
      y.fi--;
      y.se--;
      G[y.fi].pb(y.se);
      G[y.se].pb(y.fi);
    }
    if(c1*2+1>min(id8(G),d1)){
      cout<<"Alice"<<endl;
      continue;
    }
    if(id3(c,d,G)<=c1)
      cout<<"Alice"<<endl;
    else
      cout<<"Bob"<<endl;
  }
}