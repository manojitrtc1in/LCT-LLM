















using namespace std;



 

namespace Fread{
const int SIZE= 1 << 16;
	char buf[SIZE],*S,*T;
	inline char getchar(){if(S==T){T=(S=buf)+
	fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}
} 

namespace Fwrite {
const int SIZE= 1 << 16;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct NTR{~NTR(){flush();}}ztr;
} 


	
	

namespace Fastio{
struct Reader{
	template<typename T>Reader&operator>>(T&x){
		char c=getchar();short f=1;
		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
		x=0;while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}x*=f;return *this;
	}
	Reader&operator>>(double&x){
		char c=getchar();short f=1,s=0;x=0;double t=0;
		while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(long double&x){
		char c=getchar();short f=1,s=0;x=0;long double t=0;
		while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(__float128&x){
		char c=getchar();short f=1,s=0;x=0;__float128 t=0;
		while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}
		while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();
		if(c=='.')c=getchar();else return x*=f,*this;
		while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();
		while(s--)t/=10.0;x=(x+t)*f;return*this;
	}
	Reader&operator>>(char&c){
		c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();
		return *this;
	}
	Reader&operator>>(char*str){
		int len=0;char c=getchar();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();
		str[len]='\0';return*this;
	}
	Reader&operator>>(string&str){
		char c=getchar();str.clear();
		while(c=='\n'||c==' '||c=='\r')c=getchar();
		while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();
		return*this;
	}
	template<class _Tp>Reader&operator>>(vector<_Tp>&vec){for(unsigned i=0;i<vec.size();i++)cin>>vec[i];return*this;}
	template<class _Tp,class _tp>Reader&operator>>(pair<_Tp,_tp>&a){cin>>a.first>>a.second;return*this;}
	Reader(){}
}cin;
const char endl='\n';
struct Writer{
const int Setprecision=6;
typedef int mxdouble;
	template<typename T>Writer&operator<<(T x){
		if(x==0)return putchar('0'),*this;
		if(x<0)putchar('-'),x=-x;
		static int sta[45];int top=0;
		while(x)sta[++top]=x%10,x/=10;
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(long double x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(__float128 x){
		if(x<0)putchar('-'),x=-x;
		mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;
		while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;putchar('.');
		for(int i=0;i<Setprecision;i++)x*=10;
		_=x;while(_)sta[++top]=_%10,_/=10;
		for(int i=0;i<Setprecision-top;i++)putchar('0');
		while(top)putchar(sta[top]+'0'),--top;
		return*this;
	}
	Writer&operator<<(char c){putchar(c);return*this;}
	Writer& operator<<(char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return *this;
	}
	Writer&operator<<(const char*str){
		int cur=0;while(str[cur])putchar(str[cur++]);
		return*this;
	}
	Writer&operator<<(string str){
		int st=0,ed=str.size();
		while(st<ed)putchar(str[st++]);
		return*this;
	}
	template<class _Tp>Writer&operator<<(vector<_Tp>vec){for(unsigned i=0;i<vec.size()-1;i++)cout<<vec[i]<<" ";cout<<vec[vec.size()-1];return*this;}
	template<class _Tp,class _tp>Writer&operator<<(pair<_Tp,_tp>a){cout<<a.first<<" "<<a.second;return*this;}
	Writer(){}
}cout;
} 




 









typedef long long i64;
const int p=998244353;
const int G=3;
const int I=911660635;








template<class _Tp,class _tp>void add(_Tp&x,const _tp& y){((x+=y)>=p)&&(x-=p);}template<class _Tp,class _tp>_Tp Add(_Tp x,const _tp y){add(x,y);return x;}
template<class _Tp,class _tp>void sub(_Tp&x,const _tp&y){((x-=y)<0)&&(x+=p);}template<class _Tp,class _tp>_Tp Sub(_Tp x,const _tp y){sub(x,y);return x;}
template<class _Tp,class _tp>void mul(_Tp&x,const _tp&y){x=1ll*x*y%p;}template<class _Tp,class _tp>_Tp Mul(const _Tp x,const _tp y){return 1ll*x*y%p;}
template<class _Tp,class _tp>_Tp ksm(_Tp a,_tp b){_Tp ans(1);for(;b;b>>=1,mul(a,a))if(b&1)mul(ans,a);return ans;} 
template<class _Tp>_Tp div2(_Tp a){if(a&1)a+=p;return a>>1;}
int inv[maxn],jc[maxn],jcinv[maxn];void init(int n){for(rg int i=0;i<2;i++)inv[i]=jc[i]=jcinv[i]=1;
	for(rg int i=2;i<=n;i++)inv[i]=Mul(p-p/i,inv[p%i]),jc[i]=Mul(jc[i-1],i),jcinv[i]=Mul(jcinv[i-1],inv[i]);
}

typedef vector<int> poly;


void Read(poly&a,int n){a.resize(n);for(rg int i=0;i<n;i++)cin>>a[i];}int extend(int x){int len=1;while(len<x)len<<=1;return len;}
void Print(poly a,char ending='\n'){for(rg unsigned i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<ending;}
int rev[maxn],lstlen;void id0(const int&n){if(n==lstlen)return;lstlen=n;for(rg int i=1;i<n;i++)rev[i]=(rev[i>>1]>>1),(i&1)&&(rev[i]|=n>>1);}
void id2(int *f,const int&n,int tag){

	id0(n);for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);for(rg int h=2,wn;(h<=n)&&(wn=ksm(G,(p-1)/h));h<<=1)
	for(rg int i=0;i<n;i+=h)for(int j=i,_w=1,v1,v2;j<i+h/2;j++,mul(_w,wn))v1=f[j],v2=Mul(f[j+h/2],_w),f[j]=Add(v1,v2),f[j+h/2]=Sub(v1,v2);	
	if(tag==-1){reverse(f+1,f+n);int invn=ksm(n,p-2);for(rg int i=0;i<n;i++)mul(f[i],invn);}
}poly Qd(poly a){for(rg unsigned i=0;i<a.size()-1;i++)a[i]=Mul(i+1,(unsigned)a[i+1]);return a.pop_back(),a;}

poly Jf(poly a){assert(inv[1]);a.resize(a.size()+1);for(rg int i=a.size()-1;i;i--)a[i]=Mul(a[i-1],inv[i]);return a[0]=0,a;}


poly operator+=(poly &a,const poly&b){if(a.size()<b.size())a.resize(b.size());for(rg unsigned i=0;i<b.size();i++)add(a[i],b[i]);return a;}
poly operator+(const poly&a,const poly&b){poly c(a);c+=b;return c;}
poly operator-=(poly &a,const poly&b){if(a.size()<b.size())a.resize(b.size());for(rg unsigned i=0;i<b.size();i++)sub(a[i],b[i]);return a;}
poly operator-(const poly&a,const poly&b){poly c(a);c-=b;return c;}
poly operator-(const poly&a){poly d(a);for(unsigned i=0;i<a.size();i++)if(a[i])d[i]=p-d[i];return d;}
poly operator<<(const poly&a,const int&b){poly ans;ans.resize(a.size()+b);for(unsigned i=0;i<a.size();i++)ans[i+b]=a[i];return ans;}
poly operator<<=(poly&a,const int&b){return a=a<<b;}
poly operator>>(const poly&a,const int&b){poly ans;ans.resize(a.size()-b);for(unsigned i=0;i<ans.size();i++)ans[i]=a[i+b];return ans;}
poly operator>>=(poly&a,const int&b){return a=a>>b;}
poly operator*(const poly&a,int b){poly ans(a.size());for(unsigned i=0;i<a.size();i++)ans[i]=Mul(a[i],b);return ans;}
poly operator*=(poly&a,int b){return a=a*b;}
poly operator*(const poly&a,const poly&b){

	int len=a.size()+b.size()-1,n=extend(len);static int _x[maxn],_y[maxn],_z[maxn];poly c(len);
	for(rg int i=0;i<n;i++)_x[i]=(unsigned)i<a.size()?a[i]:0,_y[i]=(unsigned)i<b.size()?b[i]:0;id2(_x,n,1),id2(_y,n,1);
	for(rg int i=0;i<n;i++)_z[i]=Mul(_x[i],_y[i]);id2(_z,n,-1);for(int i=0;i<len;i++)c[i]=_z[i];return c;
}int _c[maxn],_d[maxn],_e[maxn];void id1(int n,const int h[],int f[]){

	fill(f+1,f+n*2,0);f[0]=ksm(h[0],p-2);for(int t=2;t<=n;t<<=1){
		const int t2=t<<1;copy(h,h+t,_c);fill(_c+t,_c+t2,0);id0(t2);id2(f,t2,1),id2(_c,t2,1);
		for(int i=0;i<t2;i++)f[i]=Mul(f[i],Sub(2,Mul(f[i],_c[i])));id2(f,t2,-1),fill(f+t,f+t2,0);
	}
}poly Inv(poly a){

	static int _x[maxn],_y[maxn];int len=extend(a.size());for(rg int i=0;i<len;i++)_x[i]=(unsigned)i<a.size()?a[i]:0;
	id1(len,_x,_y);poly ans(a.size());for(rg unsigned i=0;i<a.size();i++)ans[i]=_y[i];return ans;
}int _w;
pair<poly,poly>operator/(poly p,poly q){
  poly pr=p,qr=q;reverse(pr.begin(),pr.end());reverse(qr.begin(),qr.end());qr.resize(p.size()-q.size()+1);
  poly ans=pr*Inv(qr);ans.resize(qr.size());reverse(ans.begin(),ans.end());poly R=p-ans*q;R.resize(q.size()-1);return make_pair(ans,R);
}
struct Cp{int x,y;Cp(int X=0,int Y=0):x(X),y(Y){}Cp operator*(Cp u){return Cp(Add(Mul(u.x,x),Mul(Mul(u.y,y),_w)),Add(Mul(u.x,y),Mul(u.y,x)));}};
int Ksm(Cp a,int b){Cp ans(1,0);for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;return ans.x;}
int _Solve(int n){

	n%=p;if(!n)assert(0);if(ksm(n,(p-1)>>1)==p-1)assert(0);

	int a;while(1){a=rand()%p;_w=Sub(Mul(a,a),n);if(ksm(_w,(p-1)>>1)==p-1)break;}Cp x(a,1);int o=Ksm(x,(p+1)/2);return min(o,p-o);
}void id6(int n,int h[],int f[]){

	fill(f+1,f+n*2,0);f[0]=_Solve(h[0]);for(int t=2;t<=n;t<<=1){const int t2=t<<1;copy(h,h+t,_e),fill(_e+t,_e+t2,0);
	id1(t,f,_d);id0(t2);id2(f,t2,1),id2(_d,t2,1),id2(_e,t2,1);
	for(int i=0;i<t2;i++)f[i]=div2(Add(Mul(_d[i],_e[i]),f[i]));id2(f,t2,-1);fill(f+t,f+t2,0); }memset(_d,0,sizeof _d);
}
poly Sqrt(poly a){

	static int _a[maxn],_b[maxn];int len=extend(a.size());for(rg int i=0;i<len;i++)_a[i]=(unsigned)i<a.size()?a[i]:0;
	id6(len,_a,_b);poly ans(a.size());for(rg unsigned i=0;i<a.size();i++)ans[i]=_b[i];return ans;
}
poly Ln(poly a){poly ans(Jf(Qd(a)*Inv(a)));return ans.resize(a.size()),ans;}
poly id5(const poly&a){
	int len=a.size();
	if(len==1)return{1};
	poly b(id5({a.begin(),a.begin()+len/2}));b.resize(len);
	poly ans(a-Ln(b));	
	add(ans[0],1),b.resize(len/2);ans=ans*b,ans.resize(len);
	return ans;
}poly Exp(poly a){int len=a.size();a.resize(extend(len));poly ans(id5(a));ans.resize(len);return ans;}
poly Ksm(poly a,int b){assert(a[0]==1); return Exp(Ln(a)*b);}

poly Sin(poly a){poly x(a*I);return (Exp(x)-Exp(-x))*ksm(Mul(2,I),p-2);}
poly Cos(poly a){poly x(a*I);return (Exp(x)+Exp(-x))*ksm(2,p-2);}
poly Asin(poly a){int len=a.size();poly g=-a*a;g.resize(len-1);add(g[0],1);a=Qd(a)*Inv(Sqrt(g));a.resize(len-1);return Jf(a);}
poly Acos(poly a){return -Asin(a);}
poly Atan(poly a){int len=a.size();poly f=a*a;f.resize(len-1);add(f[0],1);a=Qd(a)*Inv(f);a.resize(len-1);return Jf(a);}





const double PI=3.141592653589793238462643383279502;
struct _Cp{double a,b;
	   _Cp operator~()const{return _Cp(a,-b);}
	   _Cp(double aa=0,double bb=0):a(aa),b(bb){}_Cp operator*(_Cp x)const{return _Cp(a*x.a-b*x.b,a*x.b+b*x.a);}
	   _Cp operator+(_Cp x)const{return _Cp(a+x.a,b+x.b);}_Cp operator-(_Cp x)const{return _Cp(a-x.a,b-x.b);}};
void fft(_Cp*f,const int&n){
id0(n);for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);for(int h=2;h<=n;h<<=1){_Cp wn(cos(PI*2/h),sin(PI*2/h)),w,v1,v2;
for(int i=0;w=_Cp(1,0),i<n;i+=h)for(int j=i;v1=f[j],v2=f[j+h/2]*w,j<i+h/2;f[j]=v1+v2,f[j+h/2]=v1-v2,j++,w=w*wn);}}
struct id4{int p;_Cp a[maxn],b[maxn],c[maxn],d[maxn];long long Z(double a){return (long long)(0.5+a)%p;}id4(int md):p(md){} 
	poly operator()(const poly&x,const poly&y){
		int len=x.size()+y.size()-1;int n=extend(len);memset(a,0,sizeof(_Cp)*n);memset(b,0,sizeof(_Cp)*n);
		for(unsigned i=0;i<x.size();i++)a[i]=_Cp(x[i]&32767,x[i]>>15);for(unsigned i=0;i<y.size();i++)b[i]=_Cp(y[i]&32767,y[i]>>15);
		fft(a,n),fft(b,n);for(int i=0;i<n;i++){int j=(n-i)&(n-1);c[i]=(~a[i]+a[j])*b[j]*_Cp(0.5,0);d[i]=(~a[i]-a[j])*b[j]*_Cp(0,0.5);}
		fft(c,n),fft(d,n);poly ans(len);for(int i=0;i<len;i++)ans[i]=(Z(c[i].a/n)+(Z(c[i].b/n)+Z(d[i].a/n))%p*32768+Z(d[i].b/n)%p*32768%p*32768)%p;
		return ans;
	}
}mtt(p);
poly id3(poly f){
  int n=f.size();
  int _n=extend(n),Len;
  poly g(1),h;
  f.resize(_n),g[0]=ksm(f[0],p-2);
  for(int i=2;i<=_n;i<<=1){
    h.resize(i);for(int j=0;j<i;j++)h[j]=f[j];
    h=mtt(g,mtt(g,h)),g.resize(i);
    for(int j=0;j<i;j++)g[j]=Sub(Mul(g[j],2),h[j]);
  }
  return g.resize(n),g;
}


signed main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<int> >g(k);
  vector<int>fa(k),in(k),out(k);
  iota(all(fa),0);
  map<pair<int,int>,int>M;
  function<int(int)>get=[&](int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
  };
  auto Add=[&](int x,int y){
    if(M[{x,y}])return;
    M[{x,y}]=1;
    g[x].push_back(y);
    fa[get(x)]=get(y);
    in[y]++,out[x]++;
  };
  while(n--){
    int c,lst;
    cin>>c>>lst;
    while(--c){
      int u;cin>>u;
      Add(lst-1,u-1);lst=u;
    }
  }
  vector<vector<int> >faset(k);
  vector<bool>vis(k);
  vector<int>QAQ(k);
  rep(i,0,k-1)faset[get(i)].push_back(i);
  vector<int>S;
  for(auto j:faset)if(j.size()){
    for(int i:j)QAQ[get(i)]+=in[i];
    bool gg=QAQ[get(j[0])]!=j.size()-1;
    for(int i:j)gg|=in[i]>1||out[i]>1;
    if(gg)continue;
    S.push_back(j.size());
  }
  poly a(m+1);
  for(int i:S)if(i<=m)a[i]++;
  a=-a;
  add(a[0],1);
  cout<<Inv(a)[m]<<endl;
}