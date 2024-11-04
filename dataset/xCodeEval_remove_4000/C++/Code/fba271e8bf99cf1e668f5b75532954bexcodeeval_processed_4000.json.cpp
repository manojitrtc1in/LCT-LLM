



















using namespace std;




static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;







	

	typedef long long lld;
	typedef unsigned long long u64;
	typedef double dou;
	typedef pair<int, int> pii;

	

	template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
	template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

	template<class T> inline void id9(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void id8(T &x, const T y){ if(x<y)x=y; }

	

	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

	

	inline int BINT(const int x){ return 1<<x; }
	inline lld BLLD(const int x){ return 1LL<<x; }
	inline int id4(const int s, const int x){ return (s&BINT(x))!=0; }
	inline int id11(const lld s, const int x){ return (s&BLLD(x))!=0LL; }
	
	template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }
	template<class T> inline int BITCOUNT(const T x){ return (!x)?x:(1+BITCOUNT(x&(x-1))); }

	

	const double PI=acos(-1.0);
	const double EPS=1e-5;

	

	template<class T> inline T SQR(const T x){ return x*x; }
	template<class T1, class T2> inline T1 POW(const T1 x, const T2 y){
		if(!y)return 1;else if((y&1)==0){
			return SQR(POW(x, y>>1));
		}else return POW(x, y^1)*x;
	}

	

	template<class T> inline T GCD(const T x, const T y){
		if(x<0)return GCD(-x, y);
		if(y<0)return GCD(x, -y);
		return (!y)?x:GCD(y, x%y);
	}
	template<class T> inline T LCM(const T x, const T y){
		if(x<0)return LCM(-x, y);
		if(y<0)return LCM(x, -y);
		return x*(y/GCD(x, y));
	}
	template<class T> inline T EEA(const T a, const T b, T &x, T &y){
		
		if(a<0){ T d=EEA(-a, b, x, y); x=-x; return d; }
		if(b<0){ T d=EEA(a, -b, x, y); y=-y; return d; }
		if(!b){
			x=1; y=0; return a;
		}else{
			T d=EEA(b, a%b, x, y);
			T t=x; x=y; y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T, int> > id0(T x){
		vector<pair<T, int> > ret;
		if(x<0)x=-x;
		for (T i=2;x>1;){
			if(x%i==0){
				int count=0;
				for(;x%i==0;x/=i)count++;
				ret.push_back(MP(i, count));
			}
			i++;if(i>x/i)i=x;
		}
		return ret;
	}
	template<class T> inline int id10(const T x){
		if(x<=1)return 0;
		for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T id3(T x){
		vector<pair<T, int> > f=id0(x);
		for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
			x=x/it->first*(it->first-1);
		}
		return x;
	}
	template<class T> inline T id6(const T a, const T b=MOD){
		T x, y;
		EEA(a, b, x, y);
		return x?x:1;
	}

	

	template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
	template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
	template<class T> inline T id7(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
	template<class T> inline void id7(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T1, class T2> inline T1 id5(const T1 x, const T2 y, const T1 m=MOD){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=id5(x, y>>1, m); return id7(z, z, m);
		}else return id7(id5(x, y^1, m), x, m);
	}
	inline lld id1(lld x, lld y, const lld m=MOD){
		if(x<y)swap(x, y);
		lld z=0LL;
		while(y>0){
			if(y&1){
				MOD_ADD(&z, x, m);
			}
			MOD_ADD(&x, x, m);
			y>>=1;
		}
		return z;
	}
	inline lld id2(const lld x, const lld y, const lld m=MOD){
		if(y==0LL)return 1LL%m;else if((y&1)==0LL){
			lld z=id2(x, y>>1, m); return id1(z, z, m);
		}else return id1(id2(x, y^1, m), x, m);
	}

	

	template<class T> class MATX{
		private:
			unsigned long hig, wid;
			T *data;
			
			void __init(){
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				memset(this->data, 0, sizeof(T)*this->hig*this->wid);
			}

		public:
			MATX(){ 
				this->hig=this->wid=1;
				__init();
			}
			MATX(const unsigned long _len){
				this->hig=this->wid=_len;
				__init();
			}
			MATX(const unsigned long _hig, const unsigned long _wid){
				this->hig=_hig;
				this->wid=_wid;
				__init();
			}
			MATX(const MATX &rhs){
				this->hig=rhs.hig;
				this->wid=rhs.wid;
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
			}
			~MATX(){
				free(this->data);
			}

			T & operator()(const unsigned long x, const unsigned long y){
				if(x>=this->hig || y>=this->wid)return (*(T*)NULL);
				return this->data[x*wid+y];
			}

			MATX & operator=(const MATX &rhs){
				if(this->hig!=rhs.hig || this->wid!=rhs.wid){
					free(this->data);
					this->hig=rhs.hig;
					this->wid=rhs.wid;
					this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				}
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
				return *this;
			}

			const MATX operator+(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]+=opn.at(x, y);
				return ret;
			}
			const MATX operator-(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]-=opn.at(x, y);
				return ret;
			}
			const MATX operator*(const MATX &opn) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.hig);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							ret.data[x*ret.wid+y]+=this->at(x, z)*opn.at(z, y);
				return ret;
			}

			const MATX mul(const MATX &opn) const{ return *this*opn; }
			template<class T2> const MATX mul(const MATX &opn, const T2 m) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.wid);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							MOD_ADD(&ret.data[x*ret.wid+y], id7(this->at(x, z), opn.at(z, y), m), m);
				return ret;
			}
			
			MATX & operator +=(const MATX &rhs){
				*this=*this+rhs;
				return *this;
			}	
			MATX & operator -=(const MATX &rhs){
				*this=*this-rhs;
				return *this;
			}	
			MATX & operator *=(const MATX &rhs){
				*this=*this*rhs;
				return *this;
			}

			const MATX pow(const unsigned long p) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret*=buff;
					buff*=buff;
					if(i>(p>>1))break;
				}
				return ret;
			}
			template<class T2> const MATX pow(const unsigned long p, const T2 m) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret=ret.mul(buff, m);
					buff=buff.mul(buff, m);
					if(i>(p>>1))break;
				}
				return ret;
			}


			const T at(const unsigned long x, const unsigned long y) const{
				if(x>=this->hig || y>=this->wid)return 0;
				return this->data[x*wid+y];
			}

			void show() const{
				for(unsigned long x=0; x<this->hig; x++){
					for(unsigned long y=0; y<this->wid; y++)
						cout<<this->at(x, y)<<" ";
					cout<<endl;
				}
			}

			void set_one(){
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=(x==y)?1:0;
			}

	};

	

	template<class T> class Complex{
		public:
		T r, i;

		Complex(T x=0.0, T y=0.0){ this->r=x; this->i=y; }
		Complex operator + (const Complex &opn) const { return Complex(this->r+opn.r, this->i+opn.i); }
		Complex operator - (const Complex &opn) const { return Complex(this->r-opn.r, this->i-opn.i); }
		Complex operator * (const Complex &opn) const { return Complex(this->r*opn.r-this->i*opn.i, this->r*opn.i+this->i*opn.r); }
	};

	

	class MILLERRABIN{
		private:
		static const int prime_table[12];
		int witness(lld a, lld d, lld s, lld n){
			lld r=id2(a, d, n);
			if(r==1 || r==n-1)return 0;
			for(int i=0; i<s-1; i++){
				r = id1(r, r, n);
				if(r==1)return 1;
				if(r==n-1)return 0;
			}
			return 1;
		}
		public:
		int test(const lld n){
			if(n<=2LL) return 0;
			lld p=n-1LL, s=0LL;
			while(!(p&1)){ p>>=1;s++; }
			for(int i=0; i<12 && this->prime_table[i]<n; i++){
				if(witness(this->prime_table[i], p, s, n))return 0;
			}
			return 1;
		}
	};
	const int MILLERRABIN::prime_table[12] = { 2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31, 37 };







int n, m, a[N];
char ans[M];

int main(){
	while(scanf("%d", &n)!=EOF){
		int odd=0;
		m=0;
		for(int i=0; i<n ;i++){
			scanf("%d", &a[i]);
			m+=a[i];
			if(a[i]&1)odd++;
		}
		if(n==1){
			printf("%d\n", a[0]);
			for(int j=0; j<a[0]; j++)ans[j]='a';
			ans[m]=0;
			printf("%s\n", ans);
		}else if(odd>1){
			printf("0\n");
			for(int i=0; i<n; i++){
				for(int j=0; j<a[i]; j++){
					putchar('a'+i);
				}
			}
			printf("\n");
		}else if(odd==1){
			int k=a[0], p=0;
			for(int i=1; i<n; i++)k=GCD(k, a[i]);
			printf("%d\n", k);
			int z;
			for(int i=0; i<n; i++){
				if(a[i]&1){
					z=i;
					a[i]-=k;
					break;
				}
			}
			do{
				for(int i=0; i<n; i++){
					for(int j=0; j<(a[i]/k)>>1; j++){
						ans[p++]='a'+i;
					}
				}
				ans[p++]='a'+z;
				for(int i=n-1; i>=0; i--){
					for(int j=0; j<(a[i]/k)>>1; j++){
						ans[p++]='a'+i;
					}
				}
			}while(p<m);
			ans[m]=0;
			printf("%s\n", ans);
		}else{
			int k=a[0], p=0;
			for(int i=1; i<n; i++)k=GCD(k, a[i]);
			printf("%d\n", k);
			do{
				for(int i=0; i<n; i++){
					for(int j=0; j<a[i]/k; j++){
						ans[p++]='a'+i;
					}
				}
				for(int i=n-1; i>=0; i--){
					for(int j=0; j<a[i]/k; j++){
						ans[p++]='a'+i;
					}
				}
			}while(p<m);
			ans[m]=0;
			printf("%s\n", ans);
		}
	}
	return 0;
}