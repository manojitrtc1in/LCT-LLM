








































using namespace std;
using std::bitset;


const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;







inline long long pw(long long x,long long p) {
	long long res=1;
	for(; p; p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}


inline int getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
namespace getinv {
	int *inv;

	

	void init_inv(int n) {
		inv=new int[n+1];
		inv[0]=1;
		inv[1]=1;
		for(register int i=2; i<=n; i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
}
using namespace getinv;
namespace Poly {
	int *w[30];



	void id1(int MAXN) {
		for(int i=2,t=0; i<2*MAXN; i<<=1,t++) {
			w[t]=new int[i>>1];
			ll wn=pw(3,(MOD-1)/i);
			w[t][0]=1;
			for(int j=1; j<(i>>1); j++) w[t][j]=w[t][j-1]*wn%MOD;
		}
	}
	struct poly {
		vector<int>a;

		

		
		poly() {
		}
		poly(int sz) {
			a.resize(sz+1);
		}

		poly(initializer_list<int>x) {
			a=x;
		}

		poly(vector<int>vec) {
			a=vec;
		}
		template<class T>
		poly(T s,T t) {
			

			a=vector<int>(s,t);
		}
		poly(const poly &x) {
			a=x.a;
		}
		
		inline int size() {
			return a.size()-1;
		}
		inline void resize(int x) {
			a.resize(x+1);
		}
		inline int& operator[](int pos) {
			return a[pos];
		}
		inline poly subpoly(int l,int r) {
			

			return poly(&a[l],&a[r]);
		}
		
		

		inline void NTT() {
			int N=a.size(),len=1;

			while(len<N)len<<=1;
			if(N<len) {
				resize(len-1);
			}
			unsigned ll A[len];
			F(i,0,len-1)A[i]=a[i];
			register int j=len>>1;
			for(register int i=1; i<len-1; i++) {
				if (i<j) swap(A[i],A[j]);
				int k=len>>1;
				while (j>=k) {
					j-=k;
					k>>=1;
				}
				j+=k;
			}
			for(register int i=2,t=0; i<=len; i<<=1,t++) {
				if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
				for(register int j=0; j<len; j+=i)
					for(register int k=j; k<j+(i>>1); k++) {
						unsigned ll u=A[k];
						unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
						A[k]=u+v;
						A[k+(i>>1)]=u-v+mod;
					}
			}
			F(i,0,len-1)a[i]=(A[i]%mod)%mod;
		}
		

		inline void UNTT() {
			int N=a.size(),len=1;

			while(len<N)len<<=1;
			if(N<len) {
				resize(len-1);
			}
			unsigned ll A[len];
			F(i,0,len-1)A[i]=a[i];
			register int j=len>>1;
			for(register int i=1; i<len-1; i++) {
				if (i<j) swap(A[i],A[j]);
				int k=len>>1;
				while (j>=k) {
					j-=k;
					k>>=1;
				}
				j+=k;
			}
			for(register int i=2,t=0; i<=len; i<<=1,t++) {
				if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
				for(register int j=0; j<len; j+=i)
					for(register int k=j; k<j+(i>>1); k++) {
						unsigned ll u=A[k];
						unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
						A[k]=u+v;
						A[k+(i>>1)]=u-v+mod;
					}
			}
			reverse(A+1,A+len);
			ll nev=pw(len,MOD-2);
			for(int i=0; i<len; i++) a[i]=(A[i]%MOD)*nev%MOD;
		}
		
		

		inline poly operator+(poly b) {
			register int n=size(),bn=b.size();
			if(n>=bn) {
				poly rt(a);
				for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
				return rt;
			}
			poly rt(b);
			for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
			return rt;
		}
		

		inline poly operator-(poly b) {
			register int n=size(),bn=b.size();
			if(n>=bn) {
				poly rt(a);
				for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
				return rt;
			}
			poly rt(bn);
			for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
			for(register int i=n+1; i<=bn; ++i)rt.a[i]=(mod-b.a[i])%mod;
			return rt;
		}
		

		inline poly operator-() {
			register int n=size();
			poly rt(n);
			for(register int i=0; i<=n; ++i)rt.a[i]=(mod-a[i])%mod;
			return rt;
		}
		

		inline poly operator*(poly b) {
			int n=size(),bn=b.size();
			int len=n+bn;
			if(1ll*n*bn<=10000) {
				poly rt(len);
				for(register int i=0; i<=n; ++i) {
					for(register int j=0; j<=bn; ++j) {
						rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
					}
				}
				return rt;
			}
			poly A(a),B(b.a);
			A.resize(len);
			B.resize(len);
			A.NTT();
			B.NTT();
			poly rt(A.size());
			for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
			rt.UNTT();
			rt.resize(len);
			return rt;
		}
		

		inline poly operator&(poly b) {
			int n=size(),bn=b.size();
			int len=n+bn;
			if(1ll*n*bn<=10000) {
				poly rt(n);
				for(register int i=0; i<=n; ++i) {
					for(register int j=0; j<=min(bn,n-i); ++j) {
						rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
					}
				}
				return rt;
			}
			poly A(a),B(b.a);
			A.resize(len);
			B.resize(len);
			A.NTT();
			B.NTT();
			poly rt(A.size());
			for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
			rt.UNTT();
			rt.resize(n);
			return rt;
		}
		

		inline poly operator^(poly b) {
			poly temp=b.rev();
			temp=(*this)*temp;
			temp.a.erase(temp.a.begin(),temp.a.begin()+b.size());
			return temp;
		}
		

		inline poly inv() {
			if(size()==0) {
				return poly(vector<int>(1,getm(1,a[0])));
			}
			poly sub(size()>>1),temp;
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.inv();
			temp=(*this)&(sub*sub);
 
			F(i,0,ss)sub[i]=(sub[i]<<1)%mod;
			return sub-temp;
		}
		

		inline poly sqrt() {
			if(size()==0) {
				return poly(vector<int>(1,1));
			}
			poly sub(size()>>1);
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.sqrt();
			sub.resize(size());
			sub=((*this)&sub.inv())+sub;
			ss=size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=1ll*sub.a[i]*inv2%mod;
			return sub;
		}
		

		inline poly rev() {
			poly rt(a);
			reverse(rt.a.begin(),rt.a.end());
			return rt;
		}
		

		inline poly operator/(poly b) {
			if(b.size()>size())return poly();
			poly temp=b.rev();
			temp.resize(size());
			poly rt=rev()&temp.inv();
			rt.resize(size()-b.size());
			return rt.rev();
		}
		

		inline poly operator%(poly b) {
			if(b.size()>size())return *this;
			poly rt=(*this)-(*this)/b*b;
			rt.resize(b.size()-1);
			return rt;
		}
		

		inline poly dev() {
			int n=size();
			poly rt(n-1);
			for(register int i=1; i<=n; ++i)rt.a[i-1]=1ll*i*a[i]%mod;
			return rt;
		}
		

		inline poly inter() {
			int n=size();
			poly rt(n+1);
			for(register int i=0; i<=n; ++i)rt.a[i+1]=1ll*a[i]*getinv::inv[i+1]%P;
			return rt;
		}
		

		inline poly inter2() {
			int n=size();
			poly rt(n);
			for(register int i=0; i<n; ++i)rt.a[i+1]=1ll*a[i]*getinv::inv[i+1]%P;
			return rt;
		}
		

		inline poly ln() {
			return (inv()&dev()).inter2();
		}
		

		inline void exp_solve(int l,int r,vector<int> &op,int rr) {
			if(l==r)return;
			int mid=(l+r)>>1;
			exp_solve(l,mid,op,rr);
			if(mid>=rr)return;
			poly sub(a.begin(),a.begin()+r-l+1),temp(op.begin()+l,op.begin()+mid+1);
			sub=sub&temp;
			for(int i=mid-l+1,iend=min(r,rr)-l; i<=iend; ++i)op[i+l]=(op[i+l]+1ll*getinv::inv[i+l]*sub[i])%mod;
			exp_solve(mid+1,r,op,rr);
		}
		


		inline poly exp() {

		inline poly exp2() {

			unsigned int k=1;
			int temp=a.size();
			while(k<a.size())k<<=1;
			a.resize(k);
			for(int i=1; i<temp; ++i)a[i]=1ll*a[i]*i%mod;
			vector<int>res(a.size(),0);
			res[0]=1;
			exp_solve(0,size(),res,temp-1);
			for(int i=1; i<temp; ++i)a[i]=1ll*a[i]*getinv::inv[i]%mod;
			a.resize(temp);
			res.resize(temp);
			return poly(res);
		}
		


		inline poly exp() {

		inline poly exp2() {

			if(size()==0) {
				return poly(vector<int>(1,1));
			}
			poly sub(size()>>1),temp;
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.exp();
			temp=sub;
			temp.resize(size());
			temp=*this-temp.ln();
			temp.a[0]=(temp.a[0]+1)%mod;
			return temp&sub;
		}
		
		

		inline poly power(ll x) {
			vector<int>temp=a;
			int t1=0,t2=0,n=size();
			for(register int i=0; i<=n; ++i) {
				if(a[i]) {
					t1=i,t2=a[i];
					for(register int j=i; j<=n; ++j)a[j]=getm(a[j],t2);
					a.erase(a.begin(),a.begin()+i);
					break;
				}
			}
			if((x>=mod&&t1)||!t2) {
				a=temp;
				return poly(n);
			}
			ll xx=x%(mod-1);
			x%=mod;
			if(t1*x>n) {
				a=temp;
				return poly(n);
			}
			t2=pw(t2,xx);
			*this=ln();
			for(register int i=0; i<=n; ++i)a[i]=a[i]*x%mod;
			*this=exp();
			for(register int i=0; i<=n; ++i)a[i]=1ll*a[i]*t2%mod;
			a.insert(a.begin(),t1*x,0);
			swap(a,temp);
			return temp;
		}
		

		inline poly power(ll x,ll xx,bool exc=false) {
			vector<int>temp=a;
			int t1=0,t2=0,n=size();
			for(register int i=0; i<=n; ++i) {
				if(a[i]) {
					t1=i,t2=a[i];
					for(register int j=i; j<=n; ++j)a[j]=getm(a[j],t2);
					a.erase(a.begin(),a.begin()+i);
					break;
				}
			}
			if((exc&&t1)||t1*x>n||!t2) {
				a=temp;
				return poly(n);
			}
			t2=pw(t2,xx);
			*this=ln();
			for(register int i=0; i<=n; ++i)a[i]=a[i]*x%mod;
			*this=exp();
			for(register int i=0; i<=n; ++i)a[i]=1ll*a[i]*t2%mod;
			a.insert(a.begin(),t1*x,0);
			swap(a,temp);
			return temp;
		}
		

		inline void id2(int *bg,int *ed,int p,poly *op) {
			if(bg+1==ed) {
				op[p]=poly(1);
				op[p][1]=1;
				op[p][0]=mod-*bg;
				return;
			}
			id2(bg,bg+((ed-bg)>>1),p<<1,op);
			id2(bg+((ed-bg)>>1),ed,p<<1|1,op);
			op[p]=op[p<<1]*op[p<<1|1];
		}
		

		inline void id3(int *bg,int *ed,poly *mul,int p,int *op) {
			if(bg+1==ed) {
				*op=a[0];
				return;
			}
			poly t1=(*this)%mul[p<<1],t2=(*this)%mul[p<<1|1];
			t1.id3(bg,bg+((ed-bg)>>1),mul,p<<1,op);
			t2.id3(bg+((ed-bg)>>1),ed,mul,p<<1|1,op+((ed-bg)>>1));
		}
		

		inline void id0(int *bg,int *ed,int *op) {
			vector<poly>temp((ed-bg+1)<<2);
			id2(bg,ed,1,&temp[0]);
			id3(bg,ed,&temp[0],1,op);
		}
	} A;


	template<class T>
	inline poly multi(T bg,T ed) {
		

		if(bg+1==ed)return *bg;
		return multi(bg,bg+((ed-bg)>>1))*multi(bg+((ed-bg)>>1),ed);
	}
}
using namespace Poly;
int nxt[300002],lst[300002];
int vis[300002];
int dp[300002];
bool ok[300002];
inline void dfs(int c){
	if(vis[c]==2||!ok[c]){
		ok[c]=0;
		dp[c]=-1;
		return;
	}
	if(!nxt[c]){
		dp[c]=1;
		vis[c]=1;
	}else{
		vis[c]=2;
		if(vis[nxt[c]]!=1)dfs(nxt[c]);
		dp[c]=dp[nxt[c]]+1;
		if(dp[c]<=0){
			ok[c]=0;
			dp[c]=-1;
			return;
		}
		vis[c]=1;
	}
}
int n,m,k;
int main() {
	init_inv(1050000);
	id1(1050000);
	cin>>n>>m>>k;
	F(i,1,k)ok[i]=1;
	F(i,1,n){
		int len=read();
		int now=read();
		F(i,1,len-1){
			int nx=read();
			if(nxt[now]>0&&nxt[now]!=nx){
				ok[now]=0;
			}
			nxt[now]=nx;
			if(lst[nx]>0&&lst[nx]!=now){
				ok[nx]=0;
			}
			lst[nx]=now;
			now=nx;
		}
	}
	F(i,1,k)if(!vis[i])dfs(i);
	

	A.resize(max(k,m));
	A[0]=1;
	F(i,1,k)if(lst[i]==0&&dp[i]>0&&ok[i])A[dp[i]]=(A[dp[i]]+mod-1)%mod;
	A=A.inv();
	cout<<A[m];
	return 0;
}