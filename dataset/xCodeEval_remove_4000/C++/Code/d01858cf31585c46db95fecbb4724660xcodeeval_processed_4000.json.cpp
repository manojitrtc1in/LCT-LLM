
using namespace std;

typedef long long int64;

namespace hezlik{
  
  template<class T,class T2,T mod>
  class modint{
    
  public:
    using type=T;
    using type2=T2;
    
    static type umod(){return mod;}
    
  private:
    using mint=modint;
    
  protected:
    type v;
    
  public:
    modint():v(){};
    modint(const type &other):v(other){}
    modint(type &&other):v(other){}
    
    modint &operator = (const type &other){v=other;return *this;}
    modint &operator = (type &&other){v=other;return *this;}
    
    template<class input_type>
    static mint standard(const input_type &v){return mint(v<0?v%mod+mod:v%mod);}
    
    type &data(){return v;}
    const type &data()const{return v;}
    explicit operator type ()const{return v;}
    
    void swap(mint &other){std::swap(v,other.v);}
    
    friend std::istream &operator >> (std::istream &in,mint &a){return in>>a.v;}
    friend std::ostream &operator << (std::ostream &out,const mint &a){return out<<a.v;}
    
    explicit operator bool ()const{return v;}
    bool operator ! ()const{return !v;}
    friend bool operator == (const mint &a,const mint &b){return a.v==b.v;}
    friend bool operator != (const mint &a,const mint &b){return a.v!=b.v;}
    
    mint &operator += (const mint &b){v=v>=mod-b.v?v-(mod-b.v):v+b.v;return *this;}
    mint &operator -= (const mint &b){v=v<b.v?v+(mod-b.v):v-b.v;return *this;}
    mint &operator *= (const mint &b){v=type2(v)*b.v%mod;return *this;}
    mint operator + ()const{return *this;}
    mint operator - ()const{return mint(0)-=*this;}
    mint &operator ++ (){v+1<mod?++v:v=0;return *this;}
    mint operator ++ (int){mint res=*this;v+1<mod?++v:v=0;return res;}
    mint &operator -- (){v?--v:v=mod-1;return *this;}
    mint operator -- (int){mint res=*this;v?--v:v=mod-1;return res;}
    friend mint operator + (const mint &a,const mint &b){return mint(a)+=b;}
    friend mint operator - (const mint &a,const mint &b){return mint(a)-=b;}
    friend mint operator * (const mint &a,const mint &b){return mint(a)*=b;}
    
    mint inv()const{
      mint x=1,y=0;
      type a=v,b=mod;
      for (;b;){
        type t=a/b;
        std::swap(a-=t*b,b);
        std::swap(x-=t*y,y);
      }
      return x;
    }
    
    mint &operator /= (const mint &b){*this*=b.inv();return *this;}
    friend mint operator / (const mint &a,const mint &b){return mint(a)/=b;}
    
    template<class index_type>
    mint pow(index_type k)const{
      mint a=*this,res=1;
      for (;k;k/=2,a*=a)
        if (k&1) res*=a;
      return res;
    }
    
  };
  
}

namespace std{
  
  template<class type,class type2,type mod>
  void swap(hezlik::modint<type,type2,mod> &a,
            hezlik::modint<type,type2,mod> &b){a.swap(b);}
  
}

namespace hezlik{
  
  template<class T,
           class container_T=std::vector<T>>
  class id0
  :public container_T{
    
  public:
    using type=T;
    using container_type=container_T;
    
    using size_type=std::size_t;
    using difference_type=std::ptrdiff_t;
    
  private:
    using poly=id0;
    using _init_list=std::initializer_list<type>;
    
  public:
    using container_type::container_type;
    using container_type::size,container_type::empty;
    using container_type::resize;
    using container_type::front,container_type::back;
    using container_type::begin,container_type::end;
    using container_type::rbegin,container_type::rend;
    using container_type::push_back,container_type::pop_back;
    using container_type::insert,container_type::erase;
    
    id0(const container_type &other):container_type(other){}
    id0(container_type &&other):container_type(other){}
    
    poly &operator = (const container_type &other){return *this=poly(other);}
    poly &operator = (container_type &&other){return *this=poly(other);}
    
    poly &operator = (const _init_list init){return *this=poly(init);}
    
    poly &operator = (const type &other){return *this=poly({other});}
    poly &operator = (type &&other){return *this=poly({other});}
    
    void resize(){for (;!empty()&&!back();pop_back());}
    
    id0(size_type n,const poly &other):container_type(other){resize(n);}
    id0(size_type n,poly &&other):container_type(other){resize(n);}
    
    id0(size_type n,const container_type &other):container_type(other){resize(n);}
    id0(size_type n,container_type &&other):container_type(other){resize(n);}
    
    id0(size_type n,const _init_list init):container_type(init){resize(n);}
    
    explicit operator container_type ()const{return *this;}
    container_type &container(){return *this;}
    const container_type &container()const{return *this;}
    
    void swap(poly &other){container_type::swap(other);}
    
    type operator () (const type &x)const{
      type res=0;
      for (iterator it=rbegin();it!=rend();++it)
        res=res*x+*it;
      return res;
    }
    
    friend bool operator == (const poly &a,const poly &b){
      for (size_type i=0;i<a.size()&&i<b.size();++i)
        if (a[i]!=b[i]) return 0;
      for (size_type i=a.size();i<b.size();++i)
        if (b[i]) return 0;
      for (size_type i=b.size();i<a.size();++i)
        if (a[i]) return 0;
      return 1;
    }
    
    friend bool operator == (const poly &a,const type &b){return a==poly({b});}
    friend bool operator == (const type &a,const poly &b){return poly({a})==b;}
    friend bool operator != (const poly &a,const poly &b){return !(a==b);}
    friend bool operator != (const poly &a,const type &b){return a!=poly({b});}
    friend bool operator != (const type &a,const poly &b){return poly({a})!=b;}
    
    explicit operator bool ()const{return *this!=poly();}
    bool operator ! ()const{return *this==poly();}
    
    poly operator + ()const{return *this;}
    
    poly &operator += (const poly &b){
      poly &a=*this;
      if (a.size()<b.size()) a.resize(b.size());
      for (size_type i=0;i<b.size();++i) a[i]+=b[i];
      return a;
    }
    
    poly &operator += (const type &b){
      poly &a=*this;
      if (a.empty()) a.resize(1);
      a[0]+=b;
      return a;
    }
    
    poly &operator ++ (){return *this+=1;}
    poly operator ++ (int){poly res=*this;*this+=1;return res;}
    friend poly operator + (const poly &a,const poly &b){return poly(a)+=b;}
    friend poly operator + (const poly &a,const type &b){return poly(a)+=b;}
    friend poly operator + (const type &a,const poly &b){return poly(b)+=a;}
    
    poly operator - ()const{
      poly res=*this;
      for (type &x:res) x=-x;
      return res;
    }
    
    poly &operator -= (const poly &b){
      poly &a=*this;
      if (a.size()<b.size()) a.resize(b.size());
      for (size_type i=0;i<b.size();++i) a[i]-=b[i];
      return a;
    }
    
    poly &operator -= (const type &b){
      poly &a=*this;
      if (a.empty()) a.resize(1);
      a[0]-=b;
      return a;
    }
    
    poly &operator -- (){return *this-=1;}
    poly operator -- (int){poly res=*this;*this-=1;return res;}
    friend poly operator - (const poly &a,const poly &b){return poly(a)-=b;}
    friend poly operator - (const poly &a,const type &b){return poly(a)-=b;}
    friend poly operator - (const type &a,const poly &b){return poly({a})-=b;}
    
    poly &operator *= (const type &b){
      for (type &x:*this) x*=b;
      return *this;
    }
    
    friend poly operator * (const poly &a,const type &b){return poly(a)*=b;}
    friend poly operator * (const type &a,const poly &b){return poly(b)*=a;}
    
    poly &operator /= (const type &b){
      type t=b.inv();
      for (type &x:*this) x*=t;
      return *this;
    }
    
    friend poly operator / (const poly &a,const type &b){return poly(a)/=b;}
    
    poly &operator >>= (size_type n){erase(begin(),begin()+n);return *this;}
    poly &operator <<= (size_type n){insert(begin(),n,0);return *this;}
    poly operator >> (size_type n)const{return poly(*this)>>=n;}
    poly operator << (size_type n)const{return poly(*this)<<=n;}
    
  protected:
    static size_type _lg(size_type n){
      size_type res=0;
      for (;n;n>>=1) ++res;
      return res-1;
    }
    
    using _type=typename type::type;
    using _type2=typename type::type2;
    using _utype2=typename std::make_unsigned<_type2>::type;
    
    class pretreatment{
      
    public:
      type g;
      std::vector<size_type> rev;
      std::vector<type> wn,inv;
      
      pretreatment()=default;
      
      void resize_ntt(size_type n){
        if (!g){
          _type phi=type::umod()-1,t=phi;
          std::vector<_type> d;
          for (_type i=2;i*i<=phi;++i){
            if (t%i) continue;
            for (;t%i==0;t/=i);
            d.push_back(i);
          }
          if (t>1) d.push_back(t);
          for (g=2;;++g){
            if (g.pow(phi)!=1) continue;
            bool flag=1;
            for (_type x:d)
              if (g.pow(phi/x)==1) {flag=0;break;}
            if (flag) break;
          }
        }
        if (wn.size()<n){
          wn.resize(n+1);
          type w=g.pow((type::umod()-1)/n);
          wn[0]=1;
          for (size_type i=1;i<=n;++i) wn[i]=wn[i-1]*w;
        }
        if (rev.size()==n) return;
        rev.resize(n);
        size_type m=_lg(n);
        rev[0]=0;
        for (size_type i=1;i<n;++i)
          rev[i]=rev[i>>1]>>1|(i&1)<<m-1;
      }
      
      void resize_inv(size_type n){
        if (n<=inv.size()) return;
        size_type m=inv.size()+inv.empty();
        inv.resize(n);
        for (size_type i=m;i<n;++i)
          inv[i]=i==1?1:(type::umod()-type::umod()/i)*inv[type::umod()%i];
      }
      
    };
    static pretreatment pre;
    
  public:
    static void reset_ntt(){pre=pretreatment();}
    static void set_proot(const type &g){pre.g=g;}
    static size_type ntt_size(size_type n){return n==1?1:(size_type)(1)<<_lg(n-1)+1;}
    
    void ntt(size_type n,bool o){
      poly &a=*this;
      a.resize(n);
      pre.resize_ntt(n);
      std::vector<_utype2> t(n);
      std::vector<_type> pw(n);
      size_type lim=std::numeric_limits<_utype2>::max()
                /(_utype2(type::umod())*type::umod());
      for (size_type i=0;i<n;++i) t[i]=a[pre.rev[i]].data();
      for (size_type i=1,c=1;i<n;i<<=1){
        const size_type wn_size=pre.wn.size()-1;
        size_type d=wn_size/(i<<1);
        for (size_type j=0;j<i;++j)
          pw[j]=(o?pre.wn[wn_size-j*d]:pre.wn[j*d]).data();
        for (size_type j=0;j<n;j+=i<<1)
          for (size_type k=0;k<i;++k){
            _type2 y=pw[k]*t[i+j+k]%type::umod();
            t[i+j+k]=t[j+k]+type::umod()-y;
            t[j+k]+=y;
          }
        if (++c>=lim){
          for (size_type j=0;j<n;++j) t[j]%=type::umod();
          c=1;
        }
      }
      for (size_type i=0;i<n;++i) a[i]=t[i]%type::umod();
      if (!o) return;
      pre.resize_inv(n+1);
      for (size_type i=0;i<n;++i) a[i]*=pre.inv[n];
    }
    
    static poly mul(poly a,poly b,size_type n){
      if (!n) return poly();
      if (a.empty()||b.empty()) return poly(a.size()+b.size());
      n=min(n,a.size()+b.size()-1);
      if (a.size()>n) a.resize(n);
      if (b.size()>n) b.resize(n);
      
      size_type len=ntt_size(n);
      a.ntt(len,0);
      b.ntt(len,0);
      for (size_type i=0;i<len;++i) a[i]*=b[i];
      a.ntt(len,1);
      return poly(n,a);
    }
    
    friend poly operator * (const poly &a,const poly &b){
      return mul(a,b,std::numeric_limits<size_type>::max());
    }
    
    poly &smul(const poly &b,size_type n){return *this=mul(*this,b,n);}
    poly &operator *= (const poly &b){return *this=*this*b;}
    
    poly inv()const{
      if (empty()) return {};
      if (size()==1) return {front().inv()};
      size_type n=size();
      poly a=*this;
      poly res=poly(a.begin(),a.end()-(n>>1)).inv();
      size_type len=ntt_size(2*n-1);
      a.ntt(len,0);
      res.ntt(len,0);
      for (size_type i=0;i<len;++i)
        res[i]=res[i]*(2-res[i]*a[i]);
      res.ntt(len,1);
      return poly(n,res);
    }
    
    poly inv(size_type n)const{return poly(n,*this).inv();}
    
    static std::pair<poly,poly> div(const poly &a,poly b){
      b.resize();
      size_type n=a.size(),m=b.size();
      if (n<m) return make_pair(poly(),poly(m-1,a));
      poly x=a,y=b;
      std::reverse(x.begin(),x.end());
      std::reverse(y.begin(),y.end());
      poly res=poly(n-m+1,poly(n-m+1,x)*poly(n-m+1,y).inv());
      std::reverse(res.begin(),res.end());
      return std::make_pair(res,poly(m-1,a-b*res));
    }
    
    friend poly operator / (const poly &a,const poly &b){return div(a,b).first;}
    poly &operator /= (const poly &b){return *this=div(*this,b).first;}
    friend poly operator % (const poly &a,const poly &b){return div(a,b).second;}
    poly &operator %= (const poly &b){return *this=div(*this,b).second;}
    
    poly de(size_type n)const{
      const poly &a=*this;
      poly res(n);
      for (size_type i=0;i<n;++i)
        res[i]=i+1<size()?a[i+1]*(i+1):0;
      return res;
    }
    
    poly de()const{return empty()?poly():de(size()-1);}
    
    poly in(size_type n)const{
      const poly &a=*this;
      poly res(n);
      pre.resize_inv(std::min(n,size()+1));
      for (size_type i=1;i<n;++i)
        res[i]=i<=size()?a[i-1]*pre.inv[i]:0;
      return res;
    }
    
    poly in()const{return in(size()+1);}
    
    poly ln()const{
      if (empty()) return {};
      if (size()==1) return {0};
      return poly(size(),(inv()*de()).in());
    }
    
    poly ln(size_type n)const{return poly(n,*this).ln();}
    
    type slope(const type &x)const{return de()(x);}
    
    type area(const type &l,const type &r)const{
      poly t=in();
      return t(r)-t(l);
    }
    
    poly exp()const{
      if (empty()) return {};
      if (size()==1) return {1};
      size_type n=size();
      const poly &a=*this;
      poly res=poly(a.begin(),a.end()-(n>>1)).exp();
      return poly(n,(1-res.ln(n)+a)*res);
    }
    
    poly exp(size_type n)const{poly(n,*this).exp();}
    
    template<class index_type>
    poly _pow(const index_type &_k,size_type n)const{
      type k=type(_k%type::umod());
      return (k*ln()).exp();
    }
    
    template<class index_type>
    poly pow(const index_type &k,size_type n)const{
      if (!n) return poly();
      if (k==0) return poly(n,{1});
      if (k==1) return poly(n,*this);
      const poly &a=*this;
      size_type m=0;
      for (;m<a.size()&&m<n&&!a[m];++m);
      if (m>=a.size()||m>=n||m&&k>=n/m) return poly(n);
      return ((a>>m)*a[0].inv())._pow(k,n-m*k)*a[0].pow(k)<<m*k;
    }
    
    template<class index_type>
    poly pow(index_type k)const{return pow(k,size());}
    
  };
  template<class type,class container>
  typename id0<type,container>::pretreatment
  id0<type,container>::pre;
  
}

namespace std{
  
  template<class type,class container>
  void swap(hezlik::id0<type,container> &a,
            hezlik::id0<type,container> &b){a.swap(b);}
  
}

typedef hezlik::modint<int,int64,998244353> mint;
typedef hezlik::id0<mint> poly;

const int N=200000;

int n;

void In(){
  scanf("%d",&n);
}

mint inv[N+9],fac[N+9],ifac[N+9];

void Get_inv(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=n;++i){
    inv[i]=-mint(mint::umod()/i)*inv[mint::umod()%i];
    fac[i]=fac[i-1]*i;
    ifac[i]=ifac[i-1]*inv[i];
  }
}

poly ans;

void Get_ans(){
  poly f(n);
  for (int i=1;i<=n-1>>1;++i) f[i]=fac[i-1]*ifac[i];
  f=f.exp();
  mint t=f[n-1]*fac[n-1];
  for (int i=1;i<n;++i) f[i]*=i+1==n?1:fac[n-i-2];
  for (int i=0;i<n;++i)
    if (n-1-i>n-1>>1) f[i]=0;
  ans=poly(n);
  for (int i=0;i<n;++i) ans[i]=ifac[i];
  ans=poly(n,ans*f);
  for (int i=0;i<n;++i) ans[i]*=fac[i];
  for (int i=0;i<n;++i) ans[i]*=i+1==n?1:n-1-i;
  ans[n-1]=t;
}

void Out(){
  for (int i=n-1;i>=0;--i)
    printf("%d ",ans[i].data());
  puts("");
}

void work(){
  In();
  Get_inv();
  Get_ans();
  Out();
}

int main(){
  int T=1;
  

  for (;T--;) work();
  return 0;
}