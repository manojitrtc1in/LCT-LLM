#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back


#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define all(a)  (a).begin(),(a).end()
#define elif else if
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
V<int> mojisyu(string a){
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

int kaijou(int a){
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

V<P<int,int>> mawari8={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,-1}};
int inf=1000000000000000007;

V<P<int,int>> mawari4={{0,-1},{0,1},{1,0},{-1,0}};













V<int> onajibubun(string a){
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
bool nibu_hantei(int a,int b,V<V<int>> c){
  color[a]=b;
  fo(i,c[a].sz){
    if(b==color[c[a][i]])
      return false;
    if(color[c[a][i]]==0&&!nibu_hantei(c[a][i],-b,c))
      return false;
  }
  return true;
}






bool renketujanai_nibu_hantei(int a,V<V<int>> c){
  fo(i,a){
    if(color[i]==0){
      if(!nibu_hantei(i,1,c))
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


int kurikaesijijou(int a,int b,int c){
  a%=c;
  b%=c;
  if(b==0)
    return 1;
  if(b%2==0){
    int d=kurikaesijijou(a,b/2,c);
    d%=c;
    return d*d%c;
  }
  return a*kurikaesijijou(a,b-1,c)%c;
}
int waINF(int a){
  if(a>=0)
    return a%INF;
  return (a+INF*INF)%INF;
}



bool find_negative_roop(V<P<P<int,int>,int>> a,V<int> b){
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


void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex,V<V<int>> &G) {
    

    if (dist > maxDist) {
        maxDist = dist;
        maxVertex = current;
    }

    for (auto to : G[current]) {
        

        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex,G);
    }
}

int getTreeDiameter(V<V<int>> &G) {
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end,G);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end,G);
    return maxDist;
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
    if(c1*2+1>min(d1,getTreeDiameter(G))){
      cout<<"Alice"<<endl;
      continue;
    }
    int g=0;
    queue<int> f;
    f.push(c);
    V<int> m(b,inf);
    m[c]=0;
    while(!f.empty()){
      int h=f.front();
      f.pop();
      if(h==d){
        g=1;
        break;
      }
      fo(i,G[h].sz){
        if(m[G[h][i]]==inf){
          m[G[h][i]]=m[h]+1;
          if(m[G[h][i]]!=c1)
            f.push(G[h][i]);
          if(G[h][i]==d){
            g=1;
            break;
          }
        }
      }
      if(g)
        break;
    }
    if(g)
      cout<<"Alice"<<endl;
    else
      cout<<"Bob"<<endl;
  }
}