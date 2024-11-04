
using namespace std;

typedef long long int64;

template<typename mint_type,typename mint_type2,mint_type mint_mod>
struct modint{
  
  using type=mint_type;
  using type2=mint_type2;
  
  static const type mod=mint_mod;
  
  using mint=modint<type,type2,mod>;
  
  type v;
  
  modint():v(){}
  modint(const type &_v):v(_v){}
  
  bool operator ! ()const{return !v;}
  friend bool operator == (const mint &a,const mint &b){return a.v==b.v;}
  friend bool operator != (const mint &a,const mint &b){return a.v!=b.v;}
  
  mint &operator += (const mint &p){v=v+p.v>=mod?v+p.v-mod:v+p.v;return *this;}
  mint &operator -= (const mint &p){v=v<p.v?v+mod-p.v:v-p.v;return *this;}
  mint &operator *= (const mint &p){v=type2(v)*p.v%mod;return *this;}
  mint &operator ++ (){v+1<mod?++v:v=0;return *this;}
  mint operator ++ (int){mint res=*this;v+1<mod?++v:v=0;return res;}
  mint &operator -- (){v?--v:v=mod-1;return *this;}
  mint operator -- (int){mint res=*this;v?--v:v=mod-1;return res;}
  mint operator + ()const{return *this;}
  mint operator - ()const{return mint()-=*this;}
  friend mint operator + (const mint &a,const mint &b){return mint(a)+=b;}
  friend mint operator - (const mint &a,const mint &b){return mint(a)-=b;}
  friend mint operator * (const mint &a,const mint &b){return mint(a)*=b;}
  
  friend istream &operator >> (istream &in,mint &p){return in>>p.v;}
  friend ostream &operator << (ostream &out,const mint &p){return out<<p.v;}
  
  template<typename pow_type>
  mint pow(pow_type k)const{
    mint a=*this,res=1;
    for (;k;k/=2,a*=a)
      if (k&1) res*=a;
    return res;
  }
  
  mint inv()const{
    mint x=1,y=0;
    type a=v,b=mod;
    for (;b;){
      type t=a/b;
      swap(a-=t*b,b);
      swap(x-=t*y,y);
    }
    return x;
  }
  
};

typedef modint<int,int64,1000000007> mint;

struct matrix{
  
  mint a[2][2];
  
  matrix(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
  
  matrix(int a00,int a01,int a10,int a11){
    a[0][0]=a00;
    a[0][1]=a01;
    a[1][0]=a10;
    a[1][1]=a11;
  }
  
  mint *operator [] (size_t p){return a[p];}
  const mint *operator [] (size_t p)const{return a[p];}
  
  matrix &operator += (const matrix &p){
    a[0][0]+=p[0][0];
    a[0][1]+=p[0][1];
    a[1][0]+=p[1][0];
    a[1][1]+=p[1][1];
    return *this;
  }
  
  friend matrix operator + (const matrix &a,const matrix &b){return matrix(a)+=b;}
  
  matrix &operator -= (const matrix &p){
    a[0][0]-=p[0][0];
    a[0][1]-=p[0][1];
    a[1][0]-=p[1][0];
    a[1][1]-=p[1][1];
    return *this;
  }
  
  friend matrix operator - (const matrix &a,const matrix &b){return matrix(a)-=b;}
  
  matrix &operator *= (const mint &p){
    a[0][0]*=p;
    a[0][1]*=p;
    a[1][0]*=p;
    a[1][1]*=p;
    return *this;
  }
  
  friend matrix operator * (const matrix &a,const mint &b){return matrix(a)*=b;}
  friend matrix operator * (const mint &a,const matrix &b){return matrix(b)*=a;}
  
  matrix &operator *= (const matrix &p){
    matrix t=*this;
    a[0][0]=t[0][0]*p[0][0]+t[0][1]*p[1][0];
    a[0][1]=t[0][0]*p[0][1]+t[0][1]*p[1][1];
    a[1][0]=t[1][0]*p[0][0]+t[1][1]*p[1][0];
    a[1][1]=t[1][0]*p[0][1]+t[1][1]*p[1][1];
    return *this;
  }
  
  friend matrix operator * (const matrix &a,const matrix &b){return matrix(a)*=b;}
  
  mint val()const{return a[0][1];}
  
};

const int N=50000,M=1000000;
const int64 INF=(1LL<<60)-1;

int n,cq;
int64 a[2][N+9];

void In(){
  scanf("%d%d",&n,&cq);
  for (int i=0;i<2;++i)
    for (int j=1;j<=n;++j)
      scanf("%lld",&a[i][j]);
}

matrix fib[2][2][M+9];

void id0(){
  for (int i=0;i<2;++i){
    fib[i][0][0]=fib[i][1][0]=matrix(1,0,0,1);
    fib[i][0][1]=i?matrix(mint::mod-1,1,1,0):matrix(0,1,1,1);
    for (int j=1;j<=M;++j)
      fib[i][0][j]=fib[i][0][j-1]*fib[i][0][1];
    fib[i][1][1]=fib[i][0][M];
    for (int j=1;j<=M;++j)
      fib[i][1][j]=fib[i][1][j-1]*fib[i][1][1];
  }
}

matrix Fib(int64 k){
  if (!k) return matrix(1,0,0,1);
  int i=k>0?0:(k=-k,1);
  return fib[i][0][k%M]*fib[i][1][k/M];
}

struct tree{
  
  int len;
  
  struct info{
    
    int64 mx[2],mn[2];
    int cx,cn;
    int64 tag[3];
    
    void assign(int v){
      mx[0]=mn[0]=v;
      mx[1]=-INF;mn[1]=INF;
      cx=cn=1;
    }
    
    friend info operator + (const info &a,const info &b){
      info c;
      c.tag[0]=c.tag[1]=c.tag[2]=0;
      a.mx[0]==b.mx[0]?(
        c.mx[0]=a.mx[0],
        c.mx[1]=max(a.mx[1],b.mx[1]),
        c.cx=a.cx+b.cx
      ):a.mx[0]>b.mx[0]?(
        c.mx[0]=a.mx[0],
        c.mx[1]=max(a.mx[1],b.mx[0]),
        c.cx=a.cx
      ):(
        c.mx[0]=b.mx[0],
        c.mx[1]=max(a.mx[0],b.mx[1]),
        c.cx=b.cx
      );
      a.mn[0]==b.mn[0]?(
        c.mn[0]=a.mn[0],
        c.mn[1]=min(a.mn[1],b.mn[1]),
        c.cn=a.cn+b.cn
      ):a.mn[0]<b.mn[0]?(
        c.mn[0]=a.mn[0],
        c.mn[1]=min(a.mn[1],b.mn[0]),
        c.cn=a.cn
      ):(
        c.mn[0]=b.mn[0],
        c.mn[1]=min(a.mn[0],b.mn[1]),
        c.cn=b.cn
      );
      return c;
    }
    
    void upd0(int64 v){
      mn[1]==mx[0]&&(mn[1]+=v);
      mx[0]+=v;
      tag[0]+=v;
    }
    
    void upd1(int64 v){
      mx[1]==mn[0]&&(mx[1]+=v);
      mn[0]+=v;
      tag[1]+=v;
    }
    
    void upd2(int64 v){
      mx[1]!=mn[0]&&(mx[1]+=v);
      mn[1]!=mx[0]&&(mn[1]+=v);
      tag[2]+=v;
    }
    
    void upd3(int64 v){
      mx[0]+=v;
      mn[0]+=v;
      tag[0]+=v;
    }
    
    bool opt()const{return mx[0]==mn[0];}
    
  }val[2];
  
  int64 &mx(int i){return val[i].mx[0];}
  int64 &mn(int i){return val[i].mn[0];}
  int64 &smx(int i){return val[i].mx[1];}
  int64 &smn(int i){return val[i].mn[1];}
  int &cx(int i){return val[i].cx;}
  int &cn(int i){return val[i].cn;}
  int64 *tag(int i){return val[i].tag;}
  const int64 &mx(int i)const{return val[i].mx[0];}
  const int64 &mn(int i)const{return val[i].mn[0];}
  const int64 &smx(int i)const{return val[i].mx[1];}
  const int64 &smn(int i)const{return val[i].mn[1];}
  const int &cx(int i)const{return val[i].cx;}
  const int &cn(int i)const{return val[i].cn;}
  const int64 *tag(int i)const{return val[i].tag;}
  
  bool opt(int i)const{return val[i].opt();}
  
  matrix s[3][3];
  
  friend tree operator + (const tree &a,const tree &b){
    tree c;
    for (int i=0;i<2;++i)
      c.val[i]=a.val[i]+b.val[i];
    {
      int p[2][3];
      for (int i=0;i<2;++i){
        p[i][0]=a.mx(i)==c.mx(i)?0:a.mx(i)==c.mn(i)?1:2;
        p[i][1]=a.mn(i)==c.mn(i)?1:a.mn(i)==c.mx(i)?0:2;
        p[i][2]=2;
      }
      for (int i=0;i<(a.mx(0)==a.mn(0)?1:3);++i)
        for (int j=0;j<(a.mx(1)==a.mn(1)?1:3);++j)
          c.s[p[0][i]][p[1][j]]+=a.s[i][j];
    }
    {
      int p[2][3];
      for (int i=0;i<2;++i){
        p[i][0]=b.mx(i)==c.mx(i)?0:b.mx(i)==c.mn(i)?1:2;
        p[i][1]=b.mn(i)==c.mn(i)?1:b.mn(i)==c.mx(i)?0:2;
        p[i][2]=2;
      }
      for (int i=0;i<(b.mx(0)==b.mn(0)?1:3);++i)
        for (int j=0;j<(b.mx(1)==b.mn(1)?1:3);++j)
          c.s[p[0][i]][p[1][j]]+=b.s[i][j];
    }
    return c;
  }
  
  void assign(int64 x,int64 y){
    val[0].assign(x);
    val[1].assign(y);
    s[0][0]=Fib(x+y);
  }
  
  void upd0(int i,int64 v){
    if (!v) return;
    matrix t=Fib(v);
    for (int j=0;j<(mx(i^1)==mn(i^1)?1:3);++j)
      (i?s[j][0]:s[0][j])*=t;
    val[i].upd0(v);
  }
  
  void upd1(int i,int64 v){
    if (!v) return;
    matrix t=Fib(v);
    for (int j=0;j<(mx(i^1)==mn(i^1)?1:3);++j)
      (i?s[j][1]:s[1][j])*=t;
    val[i].upd1(v);
  }
  
  void upd2(int i,int64 v){
    if (!v) return;
    matrix t=Fib(v);
    for (int j=0;j<(mx(i^1)==mn(i^1)?1:3);++j)
      (i?s[j][2]:s[2][j])*=t;
    val[i].upd2(v);
  }
  
  void upd3(int i,int64 v){
    if (!v) return;
    matrix t=Fib(v);
    for (int j=0;j<(mx(i^1)==mn(i^1)?1:3);++j)
      (i?s[j][0]:s[0][j])*=t;
    val[i].upd3(v);
  }
  
  matrix sum()const{
    matrix res;
    for (int i=0;i<(mx(0)==mn(0)?1:3);++i)
      for (int j=0;j<(mx(1)==mn(1)?1:3);++j)
        res+=s[i][j];
    return res;
  }
  
}tr[N*4+9];

void Pushup(int k){tr[k]=tr[k<<1]+tr[k<<1|1];}

void Pushdown(int k){
  for (int i=0;i<2;++i){
    auto t=tr[k].tag(i);
    if (!t[0]&&!t[1]&&!t[2]) continue;
    int x=k<<1,y=k<<1|1;
    int bxx=tr[x].mx(i)>=tr[y].mx(i);
    int bxn=tr[x].mn(i)<=tr[y].mn(i);
    int byx=tr[y].mx(i)>=tr[x].mx(i);
    int byn=tr[y].mn(i)<=tr[x].mn(i);
    tr[x].opt(i)?
      tr[x].upd3(i,t[bxx?0:bxn?1:2])
    :(
      tr[x].upd0(i,t[bxx?0:2]),
      tr[x].upd1(i,t[bxn?1:2]),
      tr[x].upd2(i,t[2])
    );
    tr[y].opt(i)?
      tr[y].upd3(i,t[byx?0:byn?1:2])
    :(
      tr[y].upd0(i,t[byx?0:2]),
      tr[y].upd1(i,t[byn?1:2]),
      tr[y].upd2(i,t[2])
    );
    t[0]=t[1]=t[2]=0;
  }
}

void Build(int l,int r,int k){
  tr[k].len=r-l+1;
  if (l==r){
    tr[k].assign(a[0][l],a[1][l]);
    return;
  }
  int mid=l+r>>1;
  Build(l,mid,k<<1);
  Build(mid+1,r,k<<1|1);
  Pushup(k);
}

void Change_max(int i,int ql,int qr,int64 v,int l,int r,int k){
  if (tr[k].mn(i)>=v) return;
  if (ql<=l&&qr>=r&&tr[k].smn(i)>v){
    int64 t=v-tr[k].mn(i);
    tr[k].opt(i)?tr[k].upd3(i,t):tr[k].upd1(i,t);
    return;
  }
  int mid=l+r>>1;
  Pushdown(k);
  if (ql<=mid) Change_max(i,ql,qr,v,l,mid,k<<1);
  if (qr>mid) Change_max(i,ql,qr,v,mid+1,r,k<<1|1);
  Pushup(k);
}

void Change_min(int i,int ql,int qr,int64 v,int l,int r,int k){
  if (tr[k].mx(i)<=v) return;
  if (ql<=l&&qr>=r&&tr[k].smx(i)<v){
    int64 t=v-tr[k].mx(i);
    tr[k].opt(i)?tr[k].upd3(i,t):tr[k].upd0(i,t);
    return;
  }
  int mid=l+r>>1;
  Pushdown(k);
  if (ql<=mid) Change_min(i,ql,qr,v,l,mid,k<<1);
  if (qr>mid) Change_min(i,ql,qr,v,mid+1,r,k<<1|1);
  Pushup(k);
}

void Change_add(int i,int ql,int qr,int64 v,int l,int r,int k){
  if (ql<=l&&qr>=r){
    tr[k].opt(i)?
      tr[k].upd3(i,v)
    :(
      tr[k].upd0(i,v),
      tr[k].upd1(i,v),
      tr[k].upd2(i,v)
    );
    return;
  }
  int mid=l+r>>1;
  Pushdown(k);
  if (ql<=mid) Change_add(i,ql,qr,v,l,mid,k<<1);
  if (qr>mid) Change_add(i,ql,qr,v,mid+1,r,k<<1|1);
  Pushup(k);
}

matrix Query(int ql,int qr,int l,int r,int k){
  if (ql<=l&&qr>=r) return tr[k].sum();
  int mid=l+r>>1;
  matrix res;
  Pushdown(k);
  if (ql<=mid) res+=Query(ql,qr,l,mid,k<<1);
  if (qr>mid) res+=Query(ql,qr,mid+1,r,k<<1|1);
  return res;
}

void Inter(){
  for (;cq--;){
    int opt,o,l,r;
    int64 x;
    scanf("%d",&opt);
    opt==4&&scanf("%d%d",&l,&r);
    opt<=3&&scanf("%d%d%d%lld",&o,&l,&r,&x),--o;
    switch (opt){
      case 1:Change_min(o,l,r,x,1,n,1);break;
      case 2:Change_max(o,l,r,x,1,n,1);break;
      case 3:Change_add(o,l,r,x,1,n,1);break;
      case 4:printf("%lld\n",Query(l,r,1,n,1).val());break;
    }
  }
}

void work(){
  In();
  id0();
  Build(1,n,1);
  Inter();
}

int main(){
  int T=1;
  

  for (;T--;) work();
  return 0;
}