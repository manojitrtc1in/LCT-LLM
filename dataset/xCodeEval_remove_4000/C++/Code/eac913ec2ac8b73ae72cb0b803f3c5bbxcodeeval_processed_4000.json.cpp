

using namespace std;
typedef long long LL;

const LL inv2=(modu+1)>>1;

void add(LL &a,LL b)    {   a=(a+b)%modu;   }
void sub(LL &a,LL b)    {   a=(a-b%modu+modu)%modu;  }
void mul(LL &a,LL b)    {   a=a*b%modu; }
LL sgn(LL a)    {   return (a&1)?modu-1:1;  }

LL pw(LL a,LL k=modu-2)   {
    LL ans=1;
    for (;k;k>>=1)  {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

namespace polynomial  {

    struct poly:vector<LL>  {
        using vector::vector;
        poly& normalize()   {
            while (size()&&!back())
                pop_back();
            return *this;
        }

        int deg() const  {   return size()-1;    }
        void init(int n) {
            resize(n);
            for (auto &x:*this)
                cin>>x;
            normalize();
        }

        poly operator - () const  {
            poly ans=*this;
            for (auto &x:ans)
                x=(modu-x)%modu;
            return ans;
        }

        LL operator () (const LL& x) const  {
            LL ans=0;
            for (int i=size()-1;i>=0;--i)
                ans=(ans*x+at(i))%modu;
            return ans;
        }
    };
    
    poly operator "" _x(unsigned long long a) { return poly{0, ((LL)a%modu+modu)%modu}; }
    
    ostream& operator << (ostream& os,poly a)   {
        os<<"("; 
        for (auto x:a) os<<x<<" "; 
        os<<")";
        return os;
    }
    istream& operator >> (istream& is,poly& a)  {
        int n;
        is>>n;
        a.resize(n);
        for (auto &x:a) is>>x;
        return is;
    }

    namespace FFT   {
        
        int N,rev[maxn];
        LL I,w[maxn];
        inline void init(int n) {
            for (N=1;N<n;N<<=1); I=pw(N);
            assert(N<maxn);

            rev[0]=0,rev[1]=N>>1;
            for (int i=2;i<N;++i)
                rev[i]=rev[i>>1]>>1|rev[i&1];
            
            w[0]=1,w[1]=pw(3,(modu-1)/N);
            for (int i=2;i<N;++i)
                w[i]=w[i-1]*w[1]%modu;
        }
        inline void DFT(LL *A)   {
            for (int i=0;i<N;++i)
                if (i<rev[i])
                    swap(A[i],A[rev[i]]);
            for (int len=2;len<=N;len<<=1)  {
                int m=len>>1;
                for (LL *p=A;p!=A+N;p+=len)
                    for (int i=0;i<m;++i)   {
                        LL u=p[i],v=p[i+m]*w[N/len*i]%modu;
                        p[i]=(u+v)%modu;
                        p[i+m]=(u-v+modu)%modu;
                    }
            }
        }
        inline void IDFT(LL *A)    {
            DFT(A);
            reverse(A+1,A+N);
            for (int i=0;i<N;++i)
                mul(A[i],I);
        }
    }

    inline poly operator + (const poly& a,const poly& b)   {
        poly ans(max(a.size(),b.size()));
        for (int i=0;i<ans.size();++i)  {
            if (i<a.size()) add(ans[i],a[i]);
            if (i<b.size()) add(ans[i],b[i]);
        }
        return ans;
    }
    inline poly operator - (const poly& a,const poly& b)   {
        poly ans(max(a.size(),b.size()));
        for (int i=0;i<ans.size();++i)  {
            if (i<a.size()) add(ans[i],a[i]);
            if (i<b.size()) sub(ans[i],b[i]);
        }
        return ans;
    }

    const int lim=300;
    inline poly operator * (poly a,poly b)   {
        if (a.size()<lim&&b.size()<lim) {
            poly ans(a.size()+b.size());
            for (int i=0;i<a.size();++i)
                for (int j=0;j<b.size();++j)
                    add(ans[i+j],a[i]*b[j]);
            return ans;
        } else  {
            FFT::init(a.size()+b.size());
            a.resize(FFT::N),FFT::DFT(&a[0]);
            b.resize(FFT::N),FFT::DFT(&b[0]);
            for (int i=0;i<FFT::N;++i)
                mul(a[i],b[i]);
            FFT::IDFT(&a[0]);
            return a;
        }
    }

    inline poly operator * (poly a,LL y)    {
        for (auto &x:a) mul(x,y);
        return a;
    }
    inline poly operator / (poly a,LL y)    {
        return a*pw(y);
    }
    inline poly operator % (poly a,int k)  {
        a.resize(k);
        return a;
    }

    inline poly operator ~ (poly a)    {

        poly ans={pw(a[0])};
        for (int len=2;len<2*a.size();len<<=1) {
            poly ta=a%len;
            ans=(poly{2}-ans*ta%len)*ans;
            ans.resize(len);
        }
        return ans%a.size();
    }
    
    inline poly operator / (poly a,poly b)  {
        assert(b.size());
        int len=a.size()-b.size()+1;
        if (len<=0) return poly{};
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        b.resize(len);
        poly ans=a*(~b)%len;
        reverse(ans.begin(),ans.end());
        return ans.normalize();
    }
    
    inline poly operator % (poly a,poly b)  {
        return (a-a/b*b).normalize();
    }
    
    inline pair<poly,poly> divmod(poly a,poly b)   {
        poly d=a/b;
        return make_pair(d,(a-d*b).normalize());
    }

    inline poly sqrt(poly a) {

        poly ans={1};
        for (int len=2;len<2*a.size();len<<=1)  {
            poly ta=a%len;
            ans.resize(len);
            ans=(ans/2+ta/2*~ans)%len;
        }
        return ans%a.size();
    }

    inline poly d(poly a)   {
        poly ans(a.size()-1);
        for (int i=1;i<a.size();++i)
            ans[i-1]=a[i]*i%modu;
        return ans;
    }
    inline poly I(poly a)   {
        poly ans(a.size()+1);
        for (int i=0;i<a.size();++i)
            ans[i+1]=a[i]*pw(i+1)%modu;
        return ans;
    }

    inline poly ln(poly a)  {

        return I(d(a)*~a)%a.size();
    }

    inline poly exp(poly a) {

        poly ans={1};
        for (int len=2;len<2*a.size();len<<=1)  {
            poly ta=a%len;
            ans.resize(len);
            ans=ans*(poly{1}-ln(ans)+ta)%len;
        }
        return ans%a.size();
    }

    inline poly operator ^ (poly a,LL k)   {

        return exp(ln(a/a[0])*k)*pw(a[0],k);
    }

    inline poly operator << (poly a,int k)  {
        poly ans(a.size()+k);
        for (int i=0;i<a.size();++i)
            ans[i+k]=a[i];
        return ans;
    } 
    inline poly operator >> (poly a,int k)  {
        if (a.size()<=k) return poly{};
        poly ans(a.size()-k);
        for (int i=k;i<a.size();++i)
            ans[i-k]=a[i];
        return ans;
    }

    inline vector<LL> evaluate(const poly& p,const vector<LL>& x)   {
        function<poly(int,int)> multi=[&](int l,int r)->poly   {
            if (l==r) return poly{modu-x[l],1};
            int mid=(l+r)>>1;
            return multi(l,mid)*multi(mid+1,r);
        };

        vector<LL> y(x.size());
        function<void(const poly&,int,int)> calc=[&](const poly& p,int l,int r)   {
            if (r-l+1<=lim)   
                for (int i=l;i<=r;++i)
                    y[i]=p(x[i]);
            else    {
                int mid=(l+r)>>1;
                poly L=multi(l,mid),R=multi(mid+1,r);
                calc(p%L,l,mid),calc(p%R,mid+1,r);
            }
        };
        calc(p,0,x.size()-1);
        return y;
    }
    
    inline poly interpolate(const vector<LL>& x,const vector<LL>& y)   {
        function<poly(int,int)> multi=[&](int l,int r)->poly   {
            if (l==r) return poly{-x[l],1};
            int mid=(l+r)>>1;
            return multi(l,mid)*multi(mid+1,r);
        };
        poly g=multi(0,x.size()-1);

        auto c=evaluate(d(g),x);
        for (int i=0;i<x.size();++i)
            c[i]=y[i]*pw(c[i])%modu;

        function<poly(int,int)> calc=[&](int l,int r)->poly   {
            if (r-l+1<=lim) {
                poly ans0{1},ans1;
                for (int i=l;i<=r;++i)  {
                    poly p=poly{modu-x[i],1};
                    ans1=ans1*p+ans0*c[i];
                    ans0=ans0*p;
                }
                return ans1;
            }   else    {
                int mid=(l+r)>>1;
                poly L=multi(l,mid),R=multi(mid+1,r);
                return calc(l,mid)*R+calc(mid+1,r)*L;
            }
        };
        return calc(0,x.size()-1);
    }

    


    struct polyMat  {
        poly a0,a1,b0,b1;
        
        polyMat(const poly& a0={},const poly& a1={},const poly& b0={},const poly& b1={}):
            a0(a0),a1(a1),b0(b0),b1(b1) {}
        bool operator == (const polyMat& M) const   {
            return a0==M.a0 && a1==M.a1 && b0==M.b0 && b1==M.b1;
        }
    };

    const polyMat swapMat=polyMat({},{1},{1},{});
    const polyMat identityMat=polyMat({1},{},{},{1});

    struct polyVec  {
        poly a,b;
        polyVec(const poly& a={},const poly& b={}):a(a),b(b)  {}
    };

    ostream& operator << (ostream& os,const polyVec& V)   {
        os<<"V[ "<<V.a<<", "<<V.b<<" ]";
        return os;
    }
    ostream& operator << (ostream& os,const polyMat& M)   {
        os<<"M[ "<<M.a0<<", "<<M.a1<<endl\
          <<"   "<<M.b0<<", "<<M.b1<<" ]";
        return os;
    }

    polyMat operator * (const polyMat& A,const polyMat& B)  {
        return polyMat( A.a0*B.a0+A.a1*B.b0,    A.a0*B.a1+A.a1*B.b1,
                        A.b0*B.a0+A.b1*B.b0,    A.b0*B.a1+A.b1*B.b1);
    }
    polyVec operator * (const polyMat& M,const polyVec& V)  {
        return polyVec( M.a0*V.a+M.a1*V.b,  M.b0*V.a+M.b1*V.b);
    }

    inline polyMat hgcd(const poly& a,const poly& b)   {
        assert(a.size()>b.size());
        int m=(a.deg()+1)>>1,n=b.deg();
        if (n<m) return identityMat;

        polyMat R=hgcd(a>>m,b>>m);
        polyVec V=R*polyVec(a,b);
        if (V.b.deg()<m) return R;
        
        auto q=divmod(V.a,V.b);
        polyMat Q({},{1},{1},-q.first);
        int k=(m<<1)-V.b.deg();
        return hgcd(V.b>>k,q.second>>k)*Q*R;
    }

    inline polyMat id1(const poly& a,const poly& b)  {
        if (!a.size()) return swapMat;
        if (!b.size()) return identityMat;

        if (a.size()<=b.size()) {
            auto q=divmod(b,a);
            polyMat Q({1},{},-q.first,{1});
            return id1(a,q.second)*Q;
        } else  {
            polyMat M=hgcd(a,b);
            polyVec V=M*polyVec(a,b);
            return id1(V.b,V.a)*swapMat*M;
        }
    };

    inline poly gcd(const poly& a,const poly& b)    {
        polyMat M=id1(a,b);
        polyVec V=M*polyVec(a,b);
        assert(V.b==poly{});
        return V.a;
    }    
    inline poly id0(const poly& a,const poly& b,poly& x,poly& y)    {
        polyMat M=id1(a,b);
        polyVec V=M*polyVec(a,b);
        assert(V.b==poly{});
        tie(x,y)=make_pair(M.a0,M.a1);
        return V.a;
    }

    

    

    

    
    
    inline LL resultant(const poly& a,const poly& b)    {
        if (!a.size()||!b.size()) return 0;
        if (a.size()==1||b.size()==1)   
            return pw(a.back(),b.deg())*pw(b.back(),a.deg())%modu;
        poly t=b/b.back();
        return sgn(a.deg()*b.deg())*resultant(t,a%t)%modu*pw(b.back(),a.deg())%modu;
    }
}

using namespace polynomial;

LL inv[maxn];

int n,m;

int main()  {
    inv[0]=inv[1]=1;
    for (int i=2;i<maxn;++i) inv[i]=modu-modu/i*inv[modu%i]%modu;

    cin>>n>>m;
    if (~n&1)   {
        poly even(n+1);
        for (LL i=1,C=1;2*i<=n;++i) {

            C=C*(m+i)%modu*(m-i+1)%modu*inv[2*i-1]%modu*inv[2*i]%modu;
            even[i*2]=sgn(i+1)*C%modu;
        }
        

        poly res=d(even)*inv2*1_x*~(poly{1}-even);
        assert(res.deg()>=n);
        cout<<res[n]<<endl;
    } else {
        

        

        int r=~m&1;
        m/=2;
        
        poly even(n+1);
        for (LL i=1,C=1;2*i<=n;++i) {

            C=C*(m+i)%modu*(m-i+1)%modu*inv[2*i-1]%modu*inv[2*i]%modu;
            even[i*2]=sgn(i+1)*C%modu;
        }

        poly odd(n+1);
        for (LL i=1,C=m+1;2*i-1<=n;++i) {

            odd[i*2-1]=sgn(i+1)*C%modu;
            C=C*(m+i+1)%modu*(m-i+1)%modu*inv[2*i]%modu*inv[2*i+1]%modu;
        }

        

        poly cut=odd*~(poly{1}-even);
        sub(cut[1],r);
        poly res=d(cut)*1_x*~(poly{1}-cut);
        assert(res.deg()>=n);
        cout<<res[n]<<endl;
    }
}