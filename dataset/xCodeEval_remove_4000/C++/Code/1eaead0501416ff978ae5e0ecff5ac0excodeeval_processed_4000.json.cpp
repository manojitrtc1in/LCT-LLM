

using namespace std;















typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;




namespace Poly {
	
	
	

	const int BASE = 20;
	const int MAXN = 1 << BASE;
	const int id0 = 128;


	const int mod = 1000000007;

	const int mod = 998244353;


	int pow_mod(int a, LL e) {
		int res = 1;
		for (; e; a = (LL)a * a % mod, e >>= 1) if (e & 1) res = (LL)res * a % mod;
		return res;
	}
	int pow_mod(int a, LL e, int mod) {
		int res = 1;
		for (; e; a = (LL)a * a % mod, e >>= 1) if (e & 1) res = (LL)res * a % mod;
		return res;
	}
	int modsqr(int a, int n) {
	    int b, k, i, x;
	    if (n == 2) return a % n;
	    if (pow_mod(a, (n - 1) / 2, n) == 1) {
	    	if (n % 4 == 3)  x = pow_mod(a, (n + 1) / 4, n);
          	else {
            	for (b = 1; pow_mod(b, (n - 1) / 2, n) == 1; b++);
            	i = (n - 1) / 2;
              	k = 0;
              	do {
                	i /= 2;
                  	k /= 2;
                  	if ((pow_mod(a, i, n) * (LL)pow_mod(b, k, n) + 1) % n == 0)  k += (n - 1) / 2;
              	} while (i % 2 == 0);
              	x = (pow_mod(a, (i + 1) / 2, n) * (LL)pow_mod(b, k / 2,n )) % n;
          	}
        	if (x * 2 > n) x = n - x;
         	return x;
	    }
	    return -1;
	}
	
	


	const double PI = acos(-1.0);
	struct complex {
	    double r, i;
	    complex(double _r = 0.0, double _i = 0.0) {r = _r; i =_i;}
	    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
	    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
	    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
	    complex conj() {return complex(r, -i);}
	};
	complex W[2][MAXN*2];
	void init() {
		for (int h = 2; h <= MAXN; h <<= 1)
			for (int d = 0; d < h / 2; d++) {
				W[0][h + d] = complex(cos(2 * d * PI / h), sin(2 * d * PI / h));
				W[1][h + d] = complex(cos(-2 * d * PI / h), sin(-2 * d * PI / h));
			}
	}
	void change(complex y[], int len) {
	    int i, j, k;
	    for(i = 1, j = len / 2; i < len - 1; i++) {
	        if (i < j) swap(y[i], y[j]);
	        k = len / 2;
	        while (j >= k) {
	            j -= k;
	            k /= 2;
	        }
	        if (j < k) j += k;
	    }
	}
	void fft(complex y[],int len,int type)
	{
	    change(y,len);
	    for(int h=2;h<=len;h<<=1)
	        for(int j=0;j<len;j+=h)
	            for(int k=j,d=0;k<j+h/2;k++,d++)
	            {
					complex w;
					if (type==1) w=W[0][h+d];
					else w=W[1][h+d];
	                complex u=y[k],t=w*y[k+h/2];
	                y[k]=u+t;
	                y[k+h/2]=u-t;               
	            }
	    if(type==-1) for(int i=0;i<len;i++) y[i].r/=len;
	}



	const int g=3;
	int W[2][MAXN*2];
	void init()
	{
		for (int h=2;h<=MAXN;h<<=1)
		{
			LL x=pow_mod(g,(mod-1)/h);
			LL y=pow_mod(x,mod-2);
			W[0][h]=W[1][h]=1;
			for (int d=1;d<h/2;d++)
				W[0][h+d]=(LL)x*W[0][h+d-1]%mod,W[1][h+d]=(LL)y*W[1][h+d-1]%mod;
		}
	}
	void change(int y[],int len)
	{
	    int i,j,k;
	    for(i=1,j=len/2;i<len-1;i++)
	    {
	        if (i<j) swap(y[i],y[j]);
	        k=len/2;
	        while(j>=k)
	        {
	            j-=k;
	            k/=2;
	        }
	        if(j<k) j+=k;
	    }
	}
	void fft(int y[],int len,int type)
	{
	    change(y,len);
	    for(int h=2;h<=len;h<<=1)
	        for(int j=0;j<len;j+=h)
	            for(int k=j,d=0;k<j+h/2;k++,d++)
	            {
					int w;
					if (type==1) w=W[0][h+d];
					else w=W[1][h+d];
	                int u=y[k],t=(LL)w*y[k+h/2]%mod;
	                y[k]=(u+t)%mod;
	                y[k+h/2]=(u-t+mod)%mod;               
	            }
	    if(type==-1) for(int i=0,x=pow_mod(len,mod-2);i<len;i++) y[i]=(LL)y[i]*x%mod;
	}



	int set_size[MAXN];
	void init()
	{
		for (int i=0;i<MAXN;i++)
			set_size[i]=__builtin_popcount(i);
	}
	void id4(int *a,int length,int type)
	{
		int len=-1;
		for (int x=length;x;++len,x>>=1);
		for (int i=1;i<=len;++i)
			for (int j=0;j<length;j+=1<<i)
				for (int k=j,szk=1<<i-1;k<j+szk;++k)
				{
					int s=a[k],t=a[k+szk];
					a[k]=s+t>=mod?s+t-mod:s+t;
					a[k+szk]=s-t<0?s-t+mod:s-t;
				}
		if (type==1) return;
		int inv=pow_mod(length,mod-2);
		for (int i=0;i<length;++i)
			a[i]=1LL*a[i]*inv%mod;
	}
	
	void id5(int *a,int length,int type)
	{
		int len=-1;
		for (int x=length;x;++len,x>>=1);
		for (int i=1;i<=len;++i)
			for (int j=0;j<length;j+=1<<i)
				for (int k=j,szk=1<<i-1;k<j+szk;++k)
					a[k]=(a[k]+1LL*type*a[k+szk]+mod)%mod;
	}
	
	void id1(int *a,int length,int type)
	{
		int len=-1;
		for (int x=length;x;++len,x>>=1);
		for (int i=1;i<=len;++i)
			for (int j=0;j<length;j+=1<<i)
				for (int k=j,szk=1<<i-1;k<j+szk;++k)
					a[k+szk]=(a[k+szk]+1LL*type*a[k]+mod)%mod;
	}


	template<class T>
	struct poly
	{
		T *a;
		int length,size;
		void clear()
		{
			delete [] a;
			a=nullptr;
			size=length=0;
		}
		void apply(int size)
		{
			if (!size) return;
			a=new T [size]();
			this->size=size;
		}
		void resize(int size)
		{
			if (!size) return;
			T *aux=a;
			a=new T [size]();
			memcpy(a,aux,sizeof(T)*(length+1));
			if (this->size) delete [] aux;
			this->size=size;
		}
		void initpoly(const poly &p,int length)
		{
			clear();
			apply(length+1);
			memcpy(a,p.a,sizeof(T)*(std::min(length,p.length)+1));
			this->length=length;
		}
		void print()
		{
			for (int i=0;i<=length;i++)
			{
				printf("%d",a[i]);
				if (i!=length) printf(" ");
				else printf("\n");
			}
		}
		void setlength(int length)
		{
			if (length>=size) resize(length+1);
			if (length>=this->length) { this->length=length; return;}
			memset(a+length+1,0,sizeof(T)*(this->length - length));
			this->length=length;
		}
		void reverse()
		{
			std::reverse(a,a+length+1);
		}
		poly():a(nullptr),length(-1),size(0) {}
		poly(int length):a(nullptr),length(length) {apply(length+1);}
		poly(const poly&p):a(nullptr) {initpoly(p,p.length);}
		poly(const poly&p,int length):a(nullptr) {initpoly(p,length);}
		poly(T p[],int n) {
			apply(n+2<<1);
			length=n;
			memcpy(a,p,sizeof(T)*(n+1));
		}
		~poly() {clear();}
		
		


		inline T add(const T &a,const T &b) const {return a+b;}
		inline T sub(const T &a,const T &b) const {return a-b;}
		inline T mul(const T &a,const T &b) const {return a*b;}
		inline T mod_inv(const T &a) const { return 1.0/a;}

		inline T add(const T &a,const T &b) const {return (a+b)%mod;}
		inline T sub(const T &a,const T &b) const {return (a-b+mod)%mod;}
		inline T mul(const T &a,const T &b) const {return (LL)a*b%mod;}
		inline T mod_inv(const T &a) const {return pow_mod(a,mod-2);}

		T value(T x)
		{
			T res=0,now=1;
			for (int i=0;i<=length;i++)
			{
				res=add(res,mul(a[i],now));
				now=mul(now,x);
			}
			return res;
		}
		T &operator [](int pos) {return a[pos];}
		poly &operator = (const poly &p)
		{
			if (&p!=this) initpoly(p,p.length);
			return *this;
		}
		
		poly operator << (const int &dis) const {
			poly res(length+dis);
			memcpy(res.a+dis,a,sizeof(T)*(length+1));
			return res;
		}
		poly operator >> (const int &dis) const {
			if (dis>length) return poly(-1);
			poly res(length-dis);
			memcpy(res.a,a+dis,sizeof(T)*(res.length+1));
			return res;
		}
		poly operator + (const poly &p) const {
			if (length==-1) return p;
			if (p.length==-1) return *this;
			poly res(*this,std::max(length,p.length));
			for (int i=0;i<=p.length;i++)
				res.a[i]=add(res.a[i],p.a[i]);
			return res;
		}
		poly operator - (const poly &p) const {
			if (length==-1) return p;
			if (p.length==-1) return *this;
			poly res(*this,std::max(length,p.length));
			for (int i=0;i<=p.length;i++)
				res.a[i]=sub(res.a[i],p.a[i]);
			return res;
		}
		poly operator - () const {
			poly res(length);
			for (int i=0;i<=length;i++)
				res[i]=sub(0,a[i]);
			return res;
		}
		poly operator * (const T &p) const {
			poly res(length);
			for (int i=0;i<=length;i++)
				res[i]=mul(a[i],p);
			return res;
		}
		poly operator + (const T &p) const {
			poly res(length);
			for (int i=0;i<=length;i++)
				res[i]=add(a[i],p);
			return res;
		}
		poly operator - (const T &p) const {
			poly res(length);
			for (int i=0;i<=length;i++)
				res[i]=sub(a[i],p);
			return res;
		}
		

		void mul(T *a,T *b,T *c,int lengtha,int lengthb,int lengthret,int n) const {
			for (int i=0;i<=n;i++)
				c[i]=0;
			for (int i=0;i<=lengtha;i++)
				for (int j=0;j<=std::min(lengthb,n-i);j++)
					c[i+j]=add(c[i+j],mul(a[i],b[j]));
		}

		


		void conv(T *a,T *b,T *c,int lengtha,int lengthb,int lengthret,int n) const
		{
			if (n<id0)
			{
				mul(a,b,c,lengtha,lengthb,lengthret,n);
				return;
			}
			complex *a1=new complex [lengthret];
			complex *a2=new complex [lengthret];
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=i>lengtha?0:a[i];
				a2[i]=i>lengthb?0:b[i];
			}
			fft(a1,lengthret,1);
			fft(a2,lengthret,1);
			for (int i=0;i<lengthret;i++)
				a1[i]=a1[i]*a2[i];
			fft(a1,lengthret,-1);
			for (int i=0;i<=n;i++)
				c[i]=(a1[i].r+0.5);
			delete [] a1;
			delete [] a2;
		}
		poly operator * (const poly &p) const {
			if (length==-1||p.length==-1) return poly(-1);
			int n=length+p.length;
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			poly res(n);
			conv(a,p.a,res.a,length,p.length,lengthret,n);
			return res;
		}



		void merge_fft(complex *a,complex *b,int lengthret,int type) const
		{
			for (int i=0;i<lengthret;i++)
				a[i]=a[i]+complex(0,1.0)*b[i];
			fft(a,lengthret,type);
			b[0]=a[0].conj();
			for (int i=1;i<lengthret;i++)
				b[i]=a[lengthret-i].conj();
			for (int i=0;i<lengthret;i++)
			{
				complex cur_c=a[i],cur_d=b[i];
				a[i]=(cur_c+cur_d)*complex(0.5,0);
				b[i]=(cur_c-cur_d)*complex(0,-0.5);
			}
		}
		void conv(T *a,T *b,T *c,int lengtha,int lengthb,int lengthret,int n) const
		{
			if (n<id0)
			{
				mul(a,b,c,lengtha,lengthb,lengthret,n);
				return;
			}
			complex *ka=new complex [lengthret];
			complex *kb=new complex [lengthret];
			complex *ra=new complex [lengthret];
			complex *rb=new complex [lengthret];
			const int s=1<<15;
			for (int i=0;i<lengthret;i++)
			{
				ka[i]=i>lengtha?0:a[i]/s;
				ra[i]=i>lengtha?0:a[i]%s;
				kb[i]=i>lengthb?0:b[i]/s;
				rb[i]=i>lengthb?0:b[i]%s;
			}
			merge_fft(ka,ra,lengthret,1);
			merge_fft(kb,rb,lengthret,1);
			

			for (int i=0;i<lengthret;i++)
			{
				complex id3=ka[i],id2=kb[i];
				complex cur_ra=ra[i],cur_rb=rb[i];
				ka[i]=id3*id2;
				kb[i]=id3*cur_rb+cur_ra*id2;
				ra[i]=cur_ra*cur_rb;
			}
			fft(ka,lengthret,-1);
			fft(kb,lengthret,-1);
			fft(ra,lengthret,-1);
			for (int i=0;i<=n;i++)
				c[i]=((LL)(ka[i].r+0.5)%mod*(LL)s*s+(LL)(kb[i].r+0.5)%mod*(LL)s+(LL)(ra[i].r+0.5))%mod;
			delete [] ka;
			delete [] ra;
			delete [] kb;
			delete [] rb;
		}
		poly operator * (const poly &p) const {
			if (length==-1||p.length==-1) return poly(-1);
			int n=length+p.length;
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			poly res(n);
			conv(a,p.a,res.a,length,p.length,lengthret,n);
			return res;
		}



		void conv(T *a,T *b,T *c,int lengtha,int lengthb,int lengthret,int n) const
		{
			if (n<id0)
			{
				mul(a,b,c,lengtha,lengthb,lengthret,n);
				return;
			}
			int *a1=new int [lengthret];
			int *a2=new int [lengthret];
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=i>lengtha?0:a[i];
				a2[i]=i>lengthb?0:b[i];
			}
			fft(a1,lengthret,1);
			fft(a2,lengthret,1);
			for (int i=0;i<lengthret;i++)
				a1[i]=(LL)a1[i]*a2[i]%mod;
			fft(a1,lengthret,-1);
			for (int i=0;i<=n;i++)
				c[i]=a1[i];
			delete [] a1;
			delete [] a2;
		}
		poly operator * (const poly &p) const {
			if (length==-1||p.length==-1) return poly(-1);
			int n=length+p.length;
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			poly res(n);
			conv(a,p.a,res.a,length,p.length,lengthret,n);
			return res;
		}



	
		

		poly czt(T c,int m)
		{
			int n=m+length;
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			T *a1 = new T [lengthret];
			T *a2 = new T [lengthret];
			T *a3 = new T [lengthret];
			T *w[3];
			w[0] = new T [lengthret];
			w[1] = new T [lengthret];
			w[2] = new T [lengthret];
			w[0][0]=1,w[0][1]=c,w[1][0]=w[1][1]=w[2][0]=w[2][1]=1;
			for (int i=2;i<lengthret;i++)
			{
				w[0][i]=mul(w[0][i-1],c);
				w[1][i]=mul(w[0][i-1],w[1][i-1]);
				w[2][i]=mod_inv(w[1][i]);
			}
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=w[1][i];
				a2[i]=i>length?0:mul(w[2][i],a[i]);
			}
			delete [] w[0];
			delete [] w[1];
			reverse(a1,a1+lengthret);
			poly res(m);
			conv(a1,a2,a3,lengthret-1,lengthret-1,lengthret,lengthret-1);
			for (int i=0;i<=m;i++)
				res[i]=mul(a3[lengthret-1-i],w[2][i]);
			delete [] a1;
			delete [] a2;
			delete [] a3;
			delete [] w[2];
			return res;
		}



		poly operator ^ (const poly &p) const {
			int n=std::max(length,p.length);
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			int *a1=new int [lengthret];
			int *a2=new int [lengthret];
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=i>length?0:a[i];
				a2[i]=i>p.length?0:p.a[i];
			}
			id4(a1,lengthret,1);
			id4(a2,lengthret,1);
			for (int i=0;i<lengthret;i++)
				a1[i]=(LL)a1[i]*a2[i]%mod;
			id4(a1,lengthret,-1);
			poly res(n);
			for (int i=0;i<=n;i++)
				res[i]=a1[i];
			delete [] a1;
			delete [] a2;
			return res;
		}
		poly operator | (const poly &p) const {
			int n=std::max(length,p.length);
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			int *a1=new int [lengthret];
			int *a2=new int [lengthret];
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=i>length?0:a[i];
				a2[i]=i>p.length?0:p.a[i];
			}
			id1(a1,lengthret,1);
			id1(a2,lengthret,1);
			for (int i=0;i<lengthret;i++)
				a1[i]=(LL)a1[i]*a2[i]%mod;
			id1(a1,lengthret,-1);
			poly res(n);
			for (int i=0;i<=n;i++)
				res[i]=a1[i];
			delete [] a1;
			delete [] a2;
			return res;
		}
		poly operator & (const poly &p) const {
			int n=std::max(length,p.length);
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			int *a1=new int [lengthret];
			int *a2=new int [lengthret];
			for (int i=0;i<lengthret;i++)
			{
				a1[i]=i>length?0:a[i];
				a2[i]=i>p.length?0:p.a[i];
			}
			id5(a1,lengthret,1);
			id5(a2,lengthret,1);
			for (int i=0;i<lengthret;i++)
				a1[i]=(LL)a1[i]*a2[i]%mod;
			id5(a1,lengthret,-1);
			poly res(n);
			for (int i=0;i<=n;i++)
				res[i]=a1[i];
			delete [] a1;
			delete [] a2;
			return res;
		}
		poly operator * (const poly &p) const {
			int n=std::max(length,p.length);
			int lengthret=1;
			for (;lengthret<=n;lengthret<<=1);
			int *a1[BASE],*a2[BASE],*a3[BASE];
			for (int i=0;i<BASE;i++)
			{
				a1[i]=new int [lengthret];
				a2[i]=new int [lengthret];
				a3[i]=new int [lengthret];
				for (int j=0;j<lengthret;j++)
				{
					a1[i][j]=(j>length||set_size[j]!=i)?0:a[j];
					a2[i][j]=(j>p.length||set_size[j]!=i)?0:p.a[j];
					a3[i][j]=0;
				}
				id1(a1[i],lengthret,1);
				id1(a2[i],lengthret,1);
			}
			for (int i=0;i<BASE;i++)
				for (int j=0;j<BASE-i;j++)
					for (int k=0;k<lengthret;k++)
						a3[i+j][k]=(a3[i+j][k]+(LL)a1[i][k]*a2[j][k])%mod;
			for (int i=0;i<BASE;i++)
				id1(a3[i],lengthret,-1);
			poly res(n);
			for (int i=0;i<=n;i++)
				res[i]=a3[set_size[i]][i];
			for (int i=0;i<BASE;i++)
			{
				delete [] a1[i];
				delete [] a2[i];
				delete [] a3[i];
			}
			return res;
		}

		friend poly operator - (const T &q,const poly &p) {return p-q;} 
		friend poly operator + (const T &q,const poly &p) {return p+q;}
		friend poly operator * (const T &q,const poly &p) {return p*q;}
		poly &operator += (const poly &p){*this=*this+p; return *this;}
		poly &operator -= (const poly &p){*this=*this-p; return *this;}
		poly &operator *= (const poly &p){*this=*this*p; return *this;}
		poly &operator *= (const T &p){*this=*this*p; return *this;}
		poly der() const
		{
			if (length==-1) return poly(-1);
			poly res(length-1);
			for (int i=0;i<length;i++)
				res[i]=mul(a[i+1],i+1);
			return res;
		}
		poly integral() const
		{
			int *a1 = new int [length+3];
			a1[0]=0,a1[1]=1;
			for (int i=2;i<=length+1;i++)
				a1[i]=sub(0,mul(mod/i,a1[mod%i]));
			poly res(length+1);
			for (int i=length+1;i;i--)
				res[i]=mul(a[i-1],a1[i]);
			delete [] a1;
			return res;
		}
		poly inv(int n) const
		{
			poly res(1);
			res[0]=pow_mod(a[0],mod-2);
			int len=1;
			while (len<n) len*=2;
			for (int degree=0;degree<len;)
			{
				degree=degree<<1|1;
				poly a1(*this,degree),a2(res);
				res*=res,res.setlength(degree);
				a1*=res,a1.setlength(degree);
				res=2*a2-a1;
			}
			res.setlength(n-1);
			return res;
		}
		poly operator / (const poly &p) const
		{
			if (p.length>length) return poly(-1);
			poly a(*this),b(p);
			a.reverse(),a.setlength(length-p.length+1);
			b.reverse(),b.setlength(length-p.length+1);
			poly res(b.inv(length-p.length+1));
			res*=a;
			res.setlength(length-p.length);
			res.reverse();
			return res;
		}
		poly operator % (const poly &p) const
		{
			poly res=(*this)-(*this)/p*p;
			res.setlength(p.length-1);
			return res;
		}
		poly &operator /= (const poly &p) {*this=*this/p; return *this;}
		poly &operator %= (const poly &p) {*this=*this%p; return *this;}
		

		poly ln(int n) const
		{
			poly res=(*this).der()*(*this).inv(n);
			res.setlength(n);
			res=res.integral();
			res.setlength(n-1);
			return res;
		}
		poly sqrt(int n) const 
		{
			poly res(1);
			res[0]=modsqr(a[0],mod);
			for (int degree=0;degree<n;)
			{
				degree=degree<<1|1;
				poly a1(*this,degree),a2(res);
				res=res*res+a1,res.setlength(degree);
				a2=(a2*2).inv(degree+1);
				res=res*a2;
				res.setlength(degree);
			}
			res.setlength(n-1);
			return res;
		}
		

		poly exp(int n) const 
		{
			poly res(1);
			res[0]=1;
			poly unit(res);
			for (int degree=0;degree<n;)
			{
				degree=degree<<1|1;
				poly a1(*this,degree),a2(res);
				a1=unit-a2.ln(degree+1)+a1;
				a1.setlength(degree);
				res=a1*a2;
				res.setlength(degree);
			}
			res.setlength(n-1);
			return res;
		}
		

		poly pow(int n,T k1,T k2=-1, T k3=-1) const
		{
			if (k2==-1) k2=k1;
			if (k3==-1) k3=k1;
			int pos=-1;
			for (int i=0;i<=length;i++)
				if (a[i]!=0)
				{
					pos=i;
					break;
				}
			

			if (pos==-1) return (*this);
			poly res=(*this)>>pos;
			T coef=res[0],inverse=mod_inv(res[0]);
			res=res*inverse;
			res=res.ln(n);
			res=res*k1;
			res=res.exp(n);
			pos=min((LL)pos*(LL)k3,(LL)n);
			res=(res*pow_mod(coef,k2))<<pos;
			res.setlength(n-1);
			return res;
		}
		poly sin(int n) const
		{
			static T i=modsqr(mod-1,mod);
			poly a1=((*this)*i).exp(n);
			poly a2=((*this)*sub(0,i)).exp(n);
			poly res=a1-a2;
			res=res*mod_inv(mul(2,i));
			return res;
		}
		poly cos(int n) const
		{
			static T i=modsqr(mod-1,mod);
			poly a1=((*this)*i).exp(n);
			poly a2=((*this)*sub(0,i)).exp(n);
			poly res=a1+a2;
			res=res*mod_inv(2);
			return res;
		}
		

		poly arcsin(int n) const
		{
			poly res(1);
			res[0]=1;
			poly unit(res);
			poly a1=(*this).der();
			poly a2=(*this)*(*this);
			a2.setlength(n-1);
			a2=unit-a2;
			a2=a2.sqrt(n);
			a1=a1*a2.inv(n);
			a1.setlength(n-1);
			res=a1.integral();
			res.setlength(n-1);
			return res;
		}
		

		poly arccos(int n) const
		{
			poly res(1);
			res[0]=1;
			poly unit(res);
			poly a1=(*this).der();
			poly a2=(*this)*(*this);
			a2.setlength(n-1);
			a2=unit-a2;
			a2=a2.sqrt(n);
			a1=-a1*a2.inv(n);
			a1.setlength(n-1);
			res=a1.integral();
			res.setlength(n-1);
			return res;
		}	
		

		poly arctan(int n) const
		{
			poly res(1);
			res[0]=1;
			poly unit(res);
			poly a1=(*this).der();
			poly a2=(*this)*(*this);
			a2.setlength(n-1);
			a2=unit+a2;
			a1=a1*a2.inv(n);
			a1.setlength(n-1);
			res=a1.integral();
			res.setlength(n-1);
			return res;
		}
		void multi_eval(T b[],int m)
		{
			int M=4*m;
			poly *moder = new poly [M];
			poly *rem = new poly [M];
			int *l = new int [M];
			int *r = new int [M];
			memset(l,0,sizeof(int)*(M));
			memset(r,0,sizeof(int)*(M));
			l[1]=1,r[1]=m;
			for (int i=1;i<M;i++)
			{
				if (l[i]==r[i]) continue;
				int mid=(l[i]+r[i])/2;
				l[i<<1]=l[i],r[i<<1]=mid;
				l[i<<1|1]=mid+1,r[i<<1|1]=r[i];
			}
			for (int i=M-1;i;i--)
			{
				if (l[i]==r[i])
				{
					if (l[i])
					{
						moder[i]=poly(1),moder[i][0]=sub(0,b[l[i]]),moder[i][1]=1;
					}
					continue;
				}
				moder[i]=moder[i<<1]*moder[i<<1|1];
				moder[i].setlength(r[i]-l[i]+1);
			}
			rem[1]=(*this)%moder[1];
			for (int i=1;i<M;i++)
			{
				if (l[i]==r[i]) continue;
				rem[i<<1]=rem[i]%moder[i<<1];
				rem[i<<1|1]=rem[i]%moder[i<<1|1];
			}
			for (int i=1;i<M;i++)
				if (l[i]&&l[i]==r[i]) b[l[i]]=rem[i][0];
			delete [] l;
			delete [] r;
			delete [] rem;
			delete [] moder;
			
		}
		void fast_lagrange(T x[],T y[],int m)
		{
			int M=4*m;
			poly *moder = new poly [M];
			poly *res = new poly [M];
			int *l = new int [M];
			int *r = new int [M];
			T *val = new T [M];
			memset(l,0,sizeof(int)*(M));
			memset(r,0,sizeof(int)*(M));
			l[1]=1,r[1]=m;
			for (int i=1;i<M;i++)
			{
				if (l[i]==r[i]) continue;
				int mid=(l[i]+r[i])/2;
				l[i<<1]=l[i],r[i<<1]=mid;
				l[i<<1|1]=mid+1,r[i<<1|1]=r[i];
			}
			for (int i=M-1;i;i--)
			{
				if (l[i]==r[i])
				{
					if (l[i])
					{
						moder[i]=poly(1),moder[i][0]=sub(0,x[l[i]]),moder[i][1]=1;
					}
					continue;
				}
				moder[i]=moder[i<<1]*moder[i<<1|1];
				moder[i].setlength(r[i]-l[i]+1);
			}
			for (int i=1;i<=m;i++)
				val[i]=x[i];
			poly g=moder[1].der();
			g.multi_eval(val,m);
			for (int i=M-1;i;i--)
			{
				if (l[i]==r[i])
				{
					if (l[i])
					{
						res[i]=poly(0),res[i][0]=mul(y[l[i]],mod_inv(val[l[i]]));
					}
					continue;
				}
				res[i]=res[i<<1]*moder[i<<1|1]+res[i<<1|1]*moder[i<<1];
				res[i].setlength(r[i]-l[i]);
			}
			(*this)=res[1];
			delete [] l;
			delete [] r;
			delete [] moder;
			delete [] res;
		}
	};
}

int n, m, k, a[N], sum[N], psum[N];
polyn f1, f2;
LL b[N], ans;
int num[N];
int main()
{
	Poly::init();
	IO;
	cin >> n >> m >> k;
	f1.setlength(k - 1), f2.setlength(k - 1);
	repn(i, 1, n) {
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % k;
		f1[sum[i]] += 1;
	}
	repn(i, 0, m - 2) {
		int rem = (LL)i * (LL)sum[n] % k;
		f2[rem] = (f2[rem] + m - (i + 2) + 1) % mod;
	}
	f1 = f1 * f2;
	repn(i, 0, f1.length) {
		b[i % k] = (b[i % k] + f1[i]) % mod;
	}
	int all = (LL)m * (LL)sum[n] % k;
	psum[n + 1] = 0;
	pern(i, 1, n) {
		psum[i] = (psum[i + 1] + a[i]) % k;
	}
	

	repn(i, 1, n) {
		

		ans = (ans + b[(k - psum[i]) % k]) % mod;
		

		ans = (ans + b[(all - psum[i] + k) % k]) % mod;
	}
	if (m > 1) {
		ans = (ans - 1 + mod) % mod;
	}
	

	repn(i, 1, n) {
		num[sum[i - 1]]++;
		

		ans = (ans + (LL)m * num[sum[i]]) % mod;
	}
	memset(num, 0, sizeof(num));
	repn(i, 1, n) num[psum[i]]++;
	repn(i, 2, m) {
		int rem = (LL)(i - 1) * sum[n] % k;
		ans = (ans - num[(all + k - rem) % k] + mod) % mod;
	}
	memset(num, 0, sizeof(num));
	repn(i, 1, n) num[sum[i]]++;
	repn(i, 2, m) {
		int rem = (LL)(i - 1) * sum[n] % k;
		ans = (ans - num[(all + k - rem) % k] + mod) % mod;
	}
	if (m > 1) ans = (ans + 2 + mod) % mod;
	memset(num, 0, sizeof(num));
	if (n > 1 || m > 1) {
		repn(i, 2, n) {
			num[sum[i - 1]]++;
			

			int delta = m;
			if (i == n) delta--;
			ans = (ans + (LL)delta * num[(sum[i] - all + k) % k]) % mod;
		}
		if (m > 1) {
			repn(i, 1, n) {
				LL delta = m - 1;
				if (i == n) delta--;
				if (sum[i] == all) ans = (ans + delta) % mod;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}