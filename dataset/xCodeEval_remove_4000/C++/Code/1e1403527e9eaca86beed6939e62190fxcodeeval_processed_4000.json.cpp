

























using namespace std;









typedef long long int64;

typedef unsigned long long uint64;









const double pi=acos(-1.0);

const double eps=1e-11;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}

template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

template<class T> inline T sqr(T x){return x*x;}

typedef pair<int,int> ipair;

template<class T> inline T lowbit(T n){return (n^(n-1))&n;}

template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}



template<class T> inline T gcd(T a,T b)

  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)

  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T id9(T a,T b,T &x,T &y)

  {if(a<0){T d=id9(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=id9(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=id9(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)

  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool id10(T n)

  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T id1(T n)

  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}


const int id6=40;

template<class T> inline void showMatrix(int n,T A[id6][id6])

  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}

template<class T> inline void identityMatrix(int n,T A[id6][id6])

  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T> inline void addMatrix(int n,T C[id6][id6],T A[id6][id6],T B[id6][id6])

  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];}
template<class T> inline void subMatrix(int n,T C[id6][id6],T A[id6][id6],T B[id6][id6])

  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];}
template<class T> inline void mulMatrix(int n,T C[id6][id6],T _A[id6][id6],T _B[id6][id6])

  { T A[id6][id6],B[id6][id6];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void id3(int n,T m,T C[id6][id6],T A[id6][id6],T B[id6][id6])

  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]+B[i][j],m);}
template<class T> inline void id2(int n,T m,T C[id6][id6],T A[id6][id6],T B[id6][id6])

  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]-B[i][j],m);}
template<class T> inline T multiplyMod(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}

template<class T> inline void id5(int n,T m,T C[id6][id6],T _A[id6][id6],T _B[id6][id6])

  { T A[id6][id6],B[id6][id6];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;}
template<class T> inline T powerMod(T p,int e,T m)

  {if(e==0)return 1%m;else if(e%2==0){T t=powerMod(p,e/2,m);return multiplyMod(t,t,m);}else return multiplyMod(powerMod(p,e-1,m),p,m);}


double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}

double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}

template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}

int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)

  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=eps) return 0;return (t<0)?-1:1;}
bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)

  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}
bool isMiddle(double s,double m,double t){return fabs(s-m)<=eps || fabs(t-m)<=eps || (s<m)!=(t<m);}



bool id8(char c){return c>='A' && c<='Z';}

bool id11(char c){return c>='a' && c<='z';}

bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}

bool isDigit(char c){return c>='0' && c<='9';}

char id4(char c){return (id8(c))?(c+32):c;}

char id7(char c){return (id11(c))?(c-32):c;}

template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

int64 id0(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}

double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}

template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}

template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}

template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}

template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}

template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}

template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}



template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};

  template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
  template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
  template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
  template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}



const int maxsize=100+5;
const int maxs=30*1440+5;

int n,m,k,s;
int ID[30][1440],E1[maxs],E2[maxs];
map<string,int> MS;
int time_used[maxsize];
int p[maxsize],d[maxsize],g[maxsize],id[maxsize];
int f[maxsize][maxs];

void out_time(int s)
{
	printf("%d %02d:%02d",E1[s],E2[s]/60,E2[s]%60);
}
void out(int n,int s,int d=0)
{
	while (1)
	{
		if (s-1>=0 && f[n][s]==f[n][s-1]) s--;
		else if (n-1>=0 && f[n][s]==f[n-1][s]) n--;
		else break;
	}
	if (n==0 || s==0 || f[n][s]==0)
	{
		printf("%d\n",d);
		return;
	}
	out(n-1,s-g[n-1],d+1);
	printf("%d ",id[n-1]);
	out_time(s-g[n-1]+1);
	printf(" ");
	out_time(s);
	printf("\n");
}
int main()
{

	freopen("input.txt","r",stdin);

	scanf("%d%d%d",&m,&n,&k);
	MS.clear();
	for (int i=0;i<m;i++)
	{
		char s[1024];
		scanf("%s",s);
		MS[s]=i;
	}
	for (int i=0;i<m;i++)
		scanf("%d",&time_used[i]);
	memset(ID,255,sizeof(ID));
	for (int i=0;i<4;i++)
	{
		char s[1024];
		scanf("%s",s);
		for (int k=0;s[k];k++) if (s[k]=='-' || s[k]==':') s[k]=' ';
		istringstream sin(s);
		int a1,b1,a2,b2;
		sin>>a1>>b1>>a2>>b2;
		a1=a1*60+b1;
		a2=a2*60+b2;
		ID[0][a1]=-2;
		ID[0][a2]=-2;
		for (;a1!=a2;a1=(a1+1)%1440) ID[0][a1]=-2;
	}
	s=0;
	for (int a=0;a<1440;a++)
		if (ID[0][a]==-1)
			ID[0][a]=(++s);
	for (int d=1;d<k;d++)
		for (int a=0;a<1440;a++)
			if (ID[0][a]>0)
				ID[d][a]=(++s);
	for (int ps=0,d=0;d<k;d++) for (int a=0;a<1440;a++) 
		if (ID[d][a]>0)
		{
			ps=ID[d][a];
			E1[ps]=d+1;
			E2[ps]=a;
		}
		else
			ID[d][a]=ps;
	int count=0;
	for (int i=0;i<n;i++)
	{
		int day,price;
		char s1[1024],s2[1024];
		scanf("%s%d%s%d",s1,&day,s2,&price);
		day--;
		if (MS.find(s1)==MS.end()) 
			continue;
		for (int k=0;s2[k];k++) if (s2[k]==':') s2[k]=' ';
		istringstream sin(s2);
		int a,b;
		sin>>a>>b;
		a=a*60+b;
		if ((--a)<0) a=1440-1,day--;
		if (day<0) continue;
		if (ID[day][a]<=0)
			continue;
		id[count]=i+1;
		d[count]=ID[day][a];
		g[count]=time_used[MS[s1]];
		p[count++]=price;
	}
	n=count;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (d[j]<d[i])
			{
				swap(d[i],d[j]);
				swap(g[i],g[j]);
				swap(p[i],p[j]);
				swap(id[i],id[j]);
			}
	memset(f,0,sizeof(f));
	for (int step=0;step<n;step++)
	{
		int g0=g[step],p0=p[step],d0=d[step];
		int *current=f[step+1];
		int *prev=f[step];
		for (int i=0;i<=s;i++)
		{
			int key=prev[i];
			if (i-1>=0)
			{
				int t=current[i-1];
				if (t>key) key=t;
			}
			if (i<=d0 && i>=g0)
			{
				int t=prev[i-g0]+p0;
				if (t>key) key=t;
			}
			current[i]=key;
		}
	}
	printf("%d\n",f[n][s]);
	out(n,s);
	return 0;
}