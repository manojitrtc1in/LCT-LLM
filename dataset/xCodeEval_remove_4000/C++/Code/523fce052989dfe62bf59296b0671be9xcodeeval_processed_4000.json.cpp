


















using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
struct point{
	pointtype x,y;
	inline point(){
	}
	inline point(pointtype x,pointtype y=0):x(x),y(y){
	}
	inline point operator+(const point &a)const{
		return point(x+a.x,y+a.y);
	}
	inline point operator+=(const point &a){
		return *this=*this+a;
	}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
	}
	inline point operator-=(const point &a){
		return *this=*this-a;
	}
	inline bool operator<(const point &b)const{
		if(x==b.x)
			return y<b.y;
		return x<b.x;
	}
	inline bool operator==(const point &b)const{
		return x==b.x&&y==b.y;
	}
	
		inline point operator*(const point &a)const{
			return point(1ll*x*a.x-1ll*y*a.y,1ll*x*a.y+1ll*y*a.x);
		}
		inline friend LL cross(const point &a,const point &b){
			return 1ll*a.x*b.y-1ll*a.y*b.x;
		}
		inline friend LL dot(const point &a,const point &b){
			return 1ll*a.x*b.x+1ll*a.y*b.y;
		}
	
		inline point operator*(const point &a)const{
			return point(x*a.x-y*a.y,x*a.y+y*a.x);
		}
		inline friend pointtype cross(const point &a,const point &b){
			return a.x*b.y-a.y*b.x;
		}
		inline friend pointtype dot(const point &a,const point &b){
			return a.x*b.x+a.y*b.y;
		}
	
};
template<class T,class T2>
struct hashnode{
	T val;
	T2 v;
	hashnode *next;
};
template<class T,class T2>
inline int& addhash(int u,const T &val,T2 *&ecnt,T2 **adj){
	T2 *p=++ecnt;
	p->val=val;
	p->v=0;
	p->next=adj[u];
	adj[u]=p;
	return p->v;
}
template<class T,class T2,int MOD,int ss>
class hash_table{
	hashnode<T,T2>*adj[MOD],edge[ss+10],*ecnt;
	int sz;
	public:
	inline int Get_val(int x){
		return x%MOD;
	}
	
		inline int Get_val(point x){
			return (x.x*998244353ll+x.y)%MOD;
		}
	
	inline hash_table():ecnt(edge),sz(0){
		for(int i=0;i<MOD;i++)
			adj[i]=0;
	}
	inline int size(){
		return sz;
	}
	inline hashnode<T,T2>* hash(const T &x){
		int t=Get_val(x);
		for(hashnode<T,T2> *p=adj[t];p;p=p->next)
			if(p->val==x)
				return p;
		return 0;
	}
	inline int &operator[](const T &x){
		hashnode<T,T2> *p=hash(x);
		if(p)
			return p->v;
		return ++sz,addhash(Get_val(x)%MOD,x,ecnt,adj);
	}
	inline bool count(const T &x){
		return hash(x);
	}
	inline void clear(){
		ecnt=edge;
		int t=MOD>>2<<2,i;
		for(i=0;i<t;i+=4){
			adj[i]=0;
			adj[i+1]=0;
			adj[i+2]=0;
			adj[i+3]=0;
		}
		for(;i<MOD;i++)
			adj[i]=0;
		sz=0;
	}
};
template<int sz,int MOD>
struct Matrix{
	int a[sz][sz];
	inline Matrix(){
		memset(a,0,sizeof a);
	}
	inline Matrix(int){
		memset(a,0,sizeof a);
		for(int i=0;i<sz;i++)
			a[i][i]=1;
	}
	inline void clear(){
		memset(a,0,sizeof a);
	}
	inline Matrix operator *(const Matrix &b)const{
		static Matrix c;
		c.clear();
		int i,j,k;
		for(i=0;i<sz;i++)
			for(j=0;j<sz;j++)
				if(a[i][j])
					for(k=0;k<sz;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%MOD;
		return c;
	}
	inline Matrix &operator *=(const Matrix &b){
		return *this=*this*b;
	}
	friend Matrix quick_pow(Matrix a,int b){
		Matrix ret(1);
		while(b){
			if(b&1)
				ret*=a;
			a*=a;
			b>>=1;
		}
		return ret;
	}
};
struct cpx{
	double r,i;
	inline cpx(){
	}
	inline cpx(double r,double i=0):r(r),i(i){
	}
	inline cpx operator+(const cpx &a)const{
		return cpx(r+a.r,i+a.i);
	}
	inline cpx operator-(const cpx &a)const{
		return cpx(r-a.r,i-a.i);
	}
	inline cpx operator*(const cpx &a)const{
		return cpx(r*a.r-i*a.i,r*a.i+i*a.r);
	}
	inline cpx operator/(const double &a)const{
		return cpx(r/a,i/a);
	}
	inline cpx operator/(const cpx&a)const{
		return *this*cpx(a.r,-a.i)/(a.r*a.r+a.i*a.i);
	}
	inline cpx operator+=(const cpx &a){
		return *this=*this+a;
	}
	inline cpx operator-=(const cpx &a){
		return *this=*this-a;
	}
	inline cpx operator*=(const cpx &a){
		return *this=*this*a;
	}
	inline cpx operator/=(const cpx &a){
		return *this=*this/a;
	}
	inline cpx conj(){
		return cpx(r,-i);
	}
};
template<class T,int len>
struct polynomial{
	T a[len];
	inline void clear(){
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			a[i]=0;
			a[i+1]=0;
			a[i+2]=0;
			a[i+3]=0;
		}
		for(;i<len;i++)
			a[i]=0;
	}
	inline polynomial operator+(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]+b.a[i];
			c.a[i+1]=a[i+1]+b.a[i+1];
			c.a[i+2]=a[i+2]+b.a[i+2];
			c.a[i+3]=a[i+3]+b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]+b.a[i];
		return c;
	}
	inline polynomial operator+=(const polynomial &b){
		return *this=*this+b;
	}
	inline polynomial operator-(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]-b.a[i];
			c.a[i+1]=a[i+1]-b.a[i+1];
			c.a[i+2]=a[i+2]-b.a[i+2];
			c.a[i+3]=a[i+3]-b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]-b.a[i];
		return c;
	}
	inline polynomial operator-=(const polynomial &b){
		return *this=*this-b;
	}
	inline polynomial operator*(const polynomial &b){
		static polynomial ret;
		ret.clear();
		for(int i=0;i<len;i++)
			for(int j=0;j<=i;j++)
				ret.a[i]+=a[j]*b.a[i-j];
		return ret;
	}
	inline void Antiderivative(int c){
		int i;
		for(i=len-1;i;i--)
			a[i]=a[i-1]/i;
		a[0]=c;
	}
	inline T Get_val(T c){
		T ret(a[0]);
		for(int i=1;i<len;i++){
			ret+=c*a[i];
			c*=c;
		}
		return ret;
	}
};
void fft(cpx *a,int N,int f){
	int i,j=0,k,t;
	for(i=1;i<N-1;i++){
		for(t=N;j^=t>>=1,~j&t;);
		if(i<j)
			swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		cpx wn(cos(pi/i),f*sin(pi/i));
		t=i<<1;
		for(j=0;j<N;j+=t){
			cpx w(1,0);
			for(k=0;k<i;k++,w*=wn){
				cpx x(a[j+k]),y(w*a[j+k+i]);
				a[j+k]=x+y,a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)
		for(i=0;i<N;i++)
			a[i].r/=N;
}
void mul(cpx *a,cpx *b,cpx *c,cpx *t,int N){
	int i,j;
	for(i=0;i<N;i++)
		t[i]=cpx(a[i].r,b[i].r);
	fft(t,N,1);
	for(i=0;i<N;i++){
		j=(N-i)&(N-1);
		c[i]=(t[i]*t[i]-(t[j]*t[j]).conj())*cpx(0,-0.25);
	}
	fft(c,N,-1);
	

	

	

	

}
namespace mypq{
	template<class T,class Container=std::vector<T>,class cmp=std::less<typename Container::value_type> >
	struct priority_queue{
		std::priority_queue<T,Container,cmp>ins,del;
		inline void push(T a){
			ins.push(a);
		}
		inline void erase(T a){
			del.push(a);
		}
		inline void pop(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			ins.pop();
		}
		inline T top(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			return ins.top();
		}
		inline T second_top(){
			T tmp=top(),ret;
			pop();
			ret=top();
			push(tmp);
			return ret;
		}
		inline void clear(){
			while(!ins.empty())
				ins.pop();
			while(!del.empty())
				del.pop();
		}
		inline int size(){
			return ins.size()-del.size();
		}
		inline bool empty(){
			return !size();
		}
	};
}
void id0(long long a,long long b,long long &d,long long &x,long long &y){
    if(!b){
        d=a;
        x=1;
        y=0;
        return;
    }
    id0(b,a%b,d,y,x);
    y-=a/b*x;
}


struct hp{
    int a[30+10];
    hp(){
        memset(a,0,sizeof a);
        a[0]=1;
    }
    hp(int n){
        memset(a,0,sizeof a);
        a[0]=0;
        while(n){
            a[++a[0]]=(n&32767);
            n>>=15;
        }
        if(!a[0])
            a[0]=1;
    }
    hp operator*(const hp &b)const{
        hp c;
        int i,j,len=a[0]+b.a[0];
        for(i=1;i<=a[0];i++)
            for(j=1;j<=b.a[0];j++)
                c.a[i+j-1]+=a[i]*b.a[j];
        for(i=1;i<len;i++){
            c.a[i+1]+=(c.a[i]>>15);
            c.a[i]&=32767;
        }
        while(len>1&&!c.a[len])
            len--;
        c.a[0]=len;
        return c;
    }
    hp operator+(const hp &b)const{
        hp c;
        int len=max(a[0],b.a[0]),i;
        for(i=1;i<=len;i++){
            c.a[i]+=a[i]+b.a[i];
            c.a[i+1]=(c.a[i]>>15);
            c.a[i]&=32767;
        }
        len++;
        while(len>1&&!c.a[len])
            len--;
        c.a[0]=len;
        return c;
    }
    hp operator-(const hp &b)const{
        hp c;
        int i,len=a[0];
        for(i=1;i<=len;i++){
            c.a[i]+=a[i]-b.a[i];
            if(c.a[i]<0)
                c.a[i]+=32768,c.a[i+1]--;
        }
        while(len>1&&!c.a[len])
            len--;
        c.a[0]=len;
        return c;
    }
    void operator*=(const hp &x){
        *this=*this*x;
    }
    void operator/=(const int &x){
        *this=*this/x;
    }
    void operator+=(const hp &x){
        *this=*this+x;
    }
    void operator-=(const hp &x){
        *this=*this-x;
    }
    void print(){
        for(int i=a[0];i;i--)
            printf("%d",a[i]);
    }
    bool operator>(const hp&b)const{
        if(a[0]>b.a[0])
            return 1;
        if(a[0]<b.a[0])
            return 0;
        for(int i=a[0];i;i--)
            if(a[i]>b.a[i])
                return 1;
            else if(a[i]<b.a[i])
                return 0;
        return 0;
    }
    bool operator<(const hp&b)const{
        if(a[0]<b.a[0])
            return 1;
        if(a[0]>b.a[0])
            return 0;
        for(int i=a[0];i;i--)
            if(a[i]<b.a[i])
                return 1;
            else if(a[i]>b.a[i])
                return 0;
        return 0;
    }
    bool operator<=(const hp&b)const{
        return !(*this>b);
    }
    hp operator/(const hp&b)const{
        hp l(0),r(*this),mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(mid*b<=*this)
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
    void operator/=(const hp&b){
        *this=*this/b;
    }
};
int cases,n,C,T;
double c,t;
hp f[110][1100],p10[110];
bool g[110][1100];
pii a[110];
int main()
{




	Read(cases);
	while(cases--){
		Read(n);
		int i,j,k;
		scanf("%lf%lf",&c,&t);
		C=c*1000+0.2,T=t*1000+0.2;
		f[0][0]=0;
		*p10=1;
		for(i=1;i<=n;i++){
			Read(a[i].first),Read(a[i].second);
			
			p10[i]=p10[i-1]*10;
		}
		sort(a+1,a+n+1,greater<pii>());
		memset(g,0,sizeof g);
		g[0][0]=1;
		hp now;
		for(k=1;k<=n;k++){
			now=1;
			for(i=n;i>=1;i--){
				now=p10[i];
				for(j=0;j<=n*10;j++)
					if(g[i-1][j]){
						if(g[i][j+a[k].second]){
							f[i][j+a[k].second]=min(f[i-1][j]*9+now*a[k].first,f[i][j+a[k].second]);
						}
						else
							g[i][j+a[k].second]=1,f[i][j+a[k].second]=f[i-1][j]*9+now*a[k].first;
					}
				}
		}
		now=1;
		int ans=0;
		for(i=1;i<=n;i++){
			now*=9;
			for(j=ans+1;j<=n*10;j++)
				if(g[i][j]){
					if(f[i][j]*C<=now*1000){
						if(f[i][j]*1000+now*(1000*10*i)<=now*T)
							ans=j;
					}
					else{
						if(T>=1000*10*i&&f[i][j]*C*4*1000000000<=(hp(C)*T-hp(C)*1000*10*i+1000000)*(hp(C)*T-hp(C)*1000*10*i+1000000)*now)
							ans=j;
					}
				}
		}
		printf("%d\n",ans);
	}
}