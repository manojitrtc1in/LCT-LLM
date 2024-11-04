



















using namespace std;




static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;
static const double eps=1e-8;







	

	typedef long long lld;
	typedef unsigned long long u64;
	typedef pair<int, int> pii;

	

	template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
	template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

	template<class T> inline void id1(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void id0(T &x, const T y){ if(x<y)x=y; }

	

	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

	

	inline int BINT(const int x){ return 1<<x; }
	inline lld BLLD(const int x){ return 1LL<<x; }
	inline int id7(const int s, const int x){ return (s&BINT(x))!=0; }
	inline int id5(const lld s, const int x){ return (s&BLLD(x))!=0LL; }
	
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
	template<class T> inline vector<pair<T, int> > id2(T x){
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
	template<class T> inline int id11(const T x){
		if(x<=1)return 0;
		for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T id6(T x){
		vector<pair<T, int> > f=id2(x);
		for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
			x=x/it->first*(it->first-1);
		}
		return x;
	}
	template<class T> inline T id10(const T a, const T b=MOD){
		T x, y;
		EEA(a, b, x, y);
		return x?x:1;
	}

	

	template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
	template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
	template<class T> inline T id4(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
	template<class T> inline void id4(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T1, class T2> inline T1 id8(const T1 x, const T2 y, const T1 m=MOD){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=id8(x, y>>1, m); return id4(z, z, m);
		}else return id4(id8(x, y^1, m), x, m);
	}
	inline lld id9(lld x, lld y, const lld m=MOD){
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
	inline lld id3(const lld x, const lld y, const lld m=MOD){
		if(y==0LL)return 1LL%m;else if((y&1)==0LL){
			lld z=id3(x, y>>1, m); return id9(z, z, m);
		}else return id9(id3(x, y^1, m), x, m);
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
							MOD_ADD(&ret.data[x*ret.wid+y], id4(this->at(x, z), opn.at(z, y), m), m);
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
			lld r=id3(a, d, n);
			if(r==1 || r==n-1)return 0;
			for(int i=0; i<s-1; i++){
				r = id9(r, r, n);
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

	

	
	template<class T> inline int fsign(const T x){
		if(x>-eps && x<eps)return 0;
		return (x<0.0)?-1:1;
	}

	template<class T> class point_t{
		public:
		T x, y;
		point_t (){
			this->x=0.0;
			this->y=0.0;
		}
		point_t (const T _x, const T _y){
			this->x=_x;
			this->y=_y;
		}
		point_t operator - (const point_t &rhs) const{
			return point_t(this->x-rhs.x, this->y-rhs.y);
		}
		T operator ^ (const point_t &rhs) const{
			return this->x*rhs.y - this->y*rhs.x;
		}
		T operator * (const point_t &rhs) const{
			return this->x*rhs.x + this->y*rhs.y;
		}
		T cross(const point_t &p, const point_t &q) const{
			return (p-*this)^(q-*this);
		}
		void rotate(double radian){
			T x0=x, y0=y;
			T sinr=sin(radian);
			T cosr=cos(radian);
			x=x0*cosr-y0*sinr;
			y=x0*sinr+y0*cosr;
		}
		T dist2(const point_t &lhs, const point_t &rhs) const{
			return (lhs-rhs)*(lhs-rhs);
		}
		T dist2(const point_t &rhs) const{
			return (*this-rhs)*(*this-rhs);
		}
		T dist(const point_t &lhs, const point_t &rhs) const{
			return sqrt((lhs-rhs)*(lhs-rhs));
		}
		T dist(const point_t &rhs) const{
			return sqrt((*this-rhs)*(*this-rhs));
		}
	};

	template<class T> class segment_t{
		public:
		point_t<T> p, q;
		segment_t (){
			this->p.x=this->p.y=0.0;
			this->q.x=this->q.y=0.0;
		}
		template<class T2> segment_t (const point_t<T2> &_p, const point_t<T2> &_q){
			this->p.x=_p.x;
			this->p.y=_p.y;
			this->q.x=_q.x;
			this->q.y=_q.y;
		}
		segment_t (const T px, const T py, const T qx, const T qy){
			this->p.x=px;
			this->p.y=py;
			this->q.x=qx;
			this->q.y=qy;
		}
		T length() const{
			return this->p.dist(this->q);
		}
		T length2() const{
			return this->p.dist2(this->q);
		}
		int contain(const point_t<T> &pnt, const int ignore_endpoint=0) const{
			if(ignore_endpoint){
				return fsign((this->p-pnt)^(this->q-pnt))==0
					&& fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <0
					&& fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <0;
			}else{
				return fsign((this->p-pnt)^(this->q-pnt))==0
					&& fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <=0
					&& fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <=0;
			}
		}
		int intersection(const segment_t &sa, const segment_t &sb, const int ignore_endpoint=0) const{
			if(!ignore_endpoint){
				if(sa.contain(sb.p) || sa.contain(sb.q) || sb.contain(sa.p) || sb.contain(sa.q))
					return 1;
			}
			return fsign(sa.p.cross(sa.q, sb.p))*fsign(sa.p.cross(sa.q, sb.q))<0
				&& fsign(sb.p.cross(sb.q, sa.p))*fsign(sb.p.cross(sb.q, sa.q))<0;
		}
		int intersection(const segment_t &rhs, const int ignore_endpoint=0) const{
			return this->intersection(*this, rhs, ignore_endpoint);
		}
	};






int n, x, y, a[N];
lld ans, f[N][3];

void core_entry(const int key){
	memset(f, 0x3f, sizeof(f));
	f[0][0]=0LL;
	for(int i=0; i<n; i++){
		id1(f[i+1][1], f[i][0]+x*1LL);
		id1(f[i+1][1], f[i][1]+x*1LL);
		if((a[i]%key)==0){
			id1(f[i+1][0], f[i][0]);
			id1(f[i+1][2], f[i][1]);
			id1(f[i+1][2], f[i][2]);
		}else if((a[i]-1)%key==0 || (a[i]+1)%key==0){
			id1(f[i+1][0], f[i][0]+y*1LL);
			id1(f[i+1][2], f[i][1]+y*1LL);
			id1(f[i+1][2], f[i][2]+y*1LL);
		}
	}
	id1(ans, f[n][0]);
	id1(ans, f[n][1]);
	id1(ans, f[n][2]);
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>x>>y){
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		vector<pii> maj[6] = { id2(a[0]), id2(a[n-1]) ,id2(a[0]-1), id2(a[n-1]-1), id2(a[0]+1), id2(a[n-1]+1) };
		set<int> mat;
		mat.clear();
		for(int i=0; i<6; i++){
			for(vector<pii>::const_iterator it=maj[i].begin(); it!=maj[i].end(); it++){
				mat.insert(it->first);
			}
		}
		ans=n*1LL*x;
		for(set<int>::const_iterator it=mat.begin(); it!=mat.end(); it++){
			

			core_entry(*it);
		}
		cout<<ans<<endl;
	}
}
