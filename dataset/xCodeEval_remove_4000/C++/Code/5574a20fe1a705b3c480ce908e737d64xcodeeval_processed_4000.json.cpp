

using namespace std;



































template<typename _T>
using pair2=pair<_T,_T>;
template<typename _T>
using pair3=pair<pair<_T,_T>,_T>;
template<typename _T>
using pair4=pair<pair<_T,_T>,pair<_T,_T> >;


template<typename _T>
using priq=priority_queue<_T>;
template<typename _T>
using qrip=priority_queue<_T,vector<_T>,greater<_T> >;













typedef long long ll;
typedef long double lf;
typedef istringstream iss;
typedef stringstream sst;
const lf pi=acosl(-1);
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
unsigned Rand(){return rand()*32768+rand();}
int rand(int a,int b){return Rand()%(b-a+1)+a;}
template<typename _T>
inline _T chmin(_T &a,_T b){return a>b?(a=b):a;}
template<typename _T>
inline _T chmax(_T &a,_T b){return a<b?(a=b):a;}
template<typename _T,int len>
struct BIT{
	_T dt[len];
	inline void add(int a,_T x){while(a<len){dt[a]+=x;a+=a&-a;}}
	inline void add(int l,int r,_T x){add(l,x);add(r+1,-x);}
	inline _T get(int a){_T ans=0;while(a){ans+=dt[a];a-=a&-a;}return ans;}
	inline _T get(int l,int r){return get(r)-get(l-1);}
};
template<typename _T,int len>
struct segbit{
	_T dt[2][len];
	inline void add(int a,_T x){int b=a;while(a<len){dt[0][a]+=x;dt[1][a]+=x*b;a+=a&-a;}}
	inline void add(int l,int r,_T x){add(l,x);add(r+1,-x);}
	inline _T sum(int a){_T ans=0;int b=a;while(a){ans+=(b+1)*dt[0][a]-dt[1][a];a-=a&-a;}return ans;}
	inline _T sum(int l,int r){return sum(r)-sum(l-1);}
};
struct fastIO{
	inline fastIO operator>>(int& num){
		num=0;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;if(c=='-'){foo=1;c=getchar();}
		while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
		if(foo)num=-num;return *this;
	}
	inline fastIO operator>>(ll& num){
		num=0;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;if(c=='-'){foo=1;c=getchar();}
		while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
		if(foo)num=-num;return *this;
	}
	inline fastIO operator>>(float& num){scanf("%f",&num);return *this;}
	inline fastIO operator>>(double& num){scanf("%lf",&num);return *this;}
	inline fastIO operator>>(long double& num){scanf("%Lf",&num);return *this;}
	inline fastIO operator>>(char& num){num=getchar();while(num==' '||num=='\n')num=getchar();return *this;}
	inline fastIO operator>>(char* num){
		int cnt=0;char c=getchar();while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n'){num[cnt++]=c;c=getchar();}num[cnt]=0;return *this;
	}
	inline fastIO operator>>(string& num){cin>>num;return *this;}
	inline void printInt(const int& num){if(num<10){putchar(num+'0');return;}printInt(num/10);putchar((num%10)+'0');}
	inline void printll(const ll& num){if(num<10){putchar(num+'0');return;}printll(num/10);putchar((num%10)+'0');}
	inline fastIO operator<<(const int& num){if(num<0)putchar('-'),printInt(-num);else printInt(num);return *this;}
	inline fastIO operator<<(const ll& num){if(num<0)putchar('-'),printll(-num);else printll(num);return *this;}
	inline fastIO operator<<(const float& num){printf("%.10f",num);return *this;}
	inline fastIO operator<<(const double& num){printf("%.16lf",num);return *this;}
	inline fastIO operator<<(const long double& num){printf("%.20Lf",num);return *this;}
	inline fastIO operator<<(const char& num){putchar(num);return *this;}
	inline fastIO operator<<(const char* num){for(int i=0;num[i];i++)putchar(num[i]);return *this;}
	inline fastIO operator<<(const string& num){cout<<num;return *this;}
	template<typename _T> inline fastIO operator<<(const vector<_T> &vec){printf("{ ");foreach(i,vec)operator<<(*i)<<' ';printf("}");return *this;}
}fio;
const lf eps=1e-10;
struct point{
	lf x,y;
	lf ang;
	point(){}
	point(lf x,lf y):x(x),y(y){ang=atan2l(y,x);}
	inline point operator+(const point &pt)const{return point(x+pt.x,y+pt.y);}
	inline point operator-(const point &pt)const{return point(x-pt.x,y-pt.y);}
	inline point operator*(const lf &a)const{return point(x*a,y*a);}
	inline point operator/(const lf &a)const{return point(x/a,y/a);}
	inline lf operator*(const point &pt)const{return x*pt.x+y*pt.y;}

	inline lf operator%(const point &pt)const{return x*pt.y-y*pt.x;}

	inline lf length()const{return x*x+y*y;}
	inline lf operator^(const point &pt)const{return acosl(*this*pt)/length()/pt.length();}
	inline lf getangle(){return ang=atan2l(y,x);}
	inline bool operator<(const point &p)const{return ang<p.ang;}
};
inline bool id1(const point &x,const point &y){return fabs(x.x-y.x)<1e-10?x.y<y.y:x.x<y.x;}
inline bool ysmaller(const point &x,const point &y){return fabs(x.y-y.y)<1e-10?x.x<y.x:x.y<y.y;}
struct line{
	point a,b;
	line(){}
	line(point a,point b):a(a),b(b){}
};
point intersect(line x,line y){
	point p1=x.a,v1=x.b-x.a;
	point p2=y.a,v2=y.b-y.a;
	return p1+v1*(((p2-p1)%v2)/(v1%v2));
}
const int jt=998244353;
inline int id0(int a,int b=jt-2){
	if(b<0){return id0(id0(a),-b);}
	if(!b){return 1;}
	int x=id0(a,b>>1);x=1ll*x*x%jt;
	if(b&1)x=1ll*x*a%jt;return x;
}
template<int len>
struct bitmod{
	int dt[len];
	inline void add(int a,int x){while(a<len){dt[a]=(dt[a]+x)%jt;a+=a&-a;}}
	inline void add(int l,int r,int x){add(l,x%jt);add(r+1,jt-x%jt);}
	inline int get(int a){int ans=0;while(a){ans=(ans+dt[a])%jt;a-=a&-a;}return ans;}
	inline int get(int l,int r){return (get(r)-get(l-1)+jt)%jt;}
};
template<int len>
struct DSU{
	int fa[len],sz[len];
	DSU(){loop(i,len)fa[i]=i,sz[i]=1;}
	void init(){loop(i,len)fa[i]=i,sz[i]=1;}
	int root(int x){return fa[x]==x?x:(fa[x]=root(fa[x]));}
	bool conn(int a,int b){a=root(a);b=root(b);if(a==b)return 0;fa[a]=b;sz[b]+=sz[a];return 1;}
};
template<typename _T>
inline _T qp(_T a,int b){
	if(!b){return 1;}
	_T x=qp(a,b>>1);x=x*x;
	if(b&1){x=x*a;}return x;
}
template<int R,int C=R>
struct matrix{
	int mat[R][C];
	int* operator[](int x){
		return mat[x];
	}
	matrix(){loop(i,R)loop(j,C)mat[i][j]=0;}
	matrix(int x){loop(i,R)loop(j,C)mat[i][j]=(i==j?x:0);}
	matrix<R,C> operator+(const matrix<R,C> m){
		matrix<R,C> ans;
		loop(i,R)loop(j,C)ans.mat[i][j]=(mat[i][j]+m.mat[i][j])%jt;
		return ans;
	}
	template<int D>
	matrix<R,D> operator*(const matrix<C,D> m){
		matrix<R,D> ans;
		loop(i,R)loop(j,C)loop(k,D)ans.mat[i][k]=(ans.mat[i][k]+((ll)mat[i][j])*m.mat[j][k])%jt;
		return ans;
	}
	void debug(){
		loop(i,R){loop(j,C)cerr<<mat[i][j]<<' ';cerr<<endl;}cerr<<endl;
	}
};


int fa[600005],sz[600005];
int n,k;
char s[300005];
int f[300005][2];
int ans=0;

int root(int x){
	return fa[x]==x?x:(fa[x]=root(fa[x]));
}

void conn(int a,int b){
	sz[a]+=sz[b];
	fa[b]=a;
}

void add(int x,int y,bool sm){
	x=root(x);y=root(y);
	if(x>=delta){
		x-=delta;
		sm=!sm;
	}
	if(y>=delta){
		y-=delta;
		sm=!sm;
	}
	if(x==y){
		return;
	}
	ans-=min(sz[x],sz[x+delta])+min(sz[y],sz[y+delta]);
	if(sm){
		conn(x,y);
		conn(x+delta,y+delta);
	}else{
		conn(x,y+delta);
		conn(x+delta,y);
	}
	ans+=min(sz[x],sz[x+delta]);
}

int main(){
	fio>>n>>k>>(s+1);
	cont(i,k){
		int x;
		fio>>x;
		cont(j,x){
			int a;
			fio>>a;
			if(f[a][0]){
				f[a][1]=i;
			}else{
				f[a][0]=i;
			}
		}
	}
	sz[0]=delta;
	cont(i,k){
		sz[i]=1;
		sz[i+delta]=0;
	}
	loop(i,600005){
		fa[i]=i;
	}
	cont(i,n){
		if(f[i][0]){
			add(f[i][0],f[i][1],s[i]=='1');
		}
		fio<<ans<<ln;
	}
	return 0;
}