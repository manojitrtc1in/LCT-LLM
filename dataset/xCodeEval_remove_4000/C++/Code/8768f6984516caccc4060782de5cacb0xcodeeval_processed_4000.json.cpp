


using namespace std;



































inline void read(int &x){int v=0,f=1;char c=getchar();while (!isdigit(c)&&c!='-') c=getchar();if (c=='-') f=-1; else v=v*10+c-'0';while (isdigit(c=getchar())) v=v*10+c-'0';x=v*f;}
inline void read(ll &x){ll v=0ll,f=1ll;char c=getchar();while (!isdigit(c)&&c!='-') c=getchar();if (c=='-') f=-1; else v=v*10+c-'0';while (isdigit(c=getchar())) v=v*10+c-'0';x=v*f;}
inline void readc(char &x){char c;while ((c=getchar())==' ');x=c;}
inline void writes(string s){puts(s.c_str());}
inline void writeln(){writes("");}
inline void writei(int x){if (x<0){putchar('-');x=abs(x);}if (!x) putchar('0');char a[25];int top=0;while (x){a[++top]=(x%10)+'0';x/=10;}while (top){putchar(a[top]);top--;}}
inline void id0(ll x){if (x<0){putchar('-');x=abs(x);}if (!x) putchar('0');char a[25];int top=0;while (x){a[++top]=(x%10)+'0';x/=10;}while (top){putchar(a[top]);top--;}}

inline long long inc(int &x){return ++x;}
inline long long inc(long long &x){return ++x;}
inline long long inc(int &x,long long y){return x+=y;}
inline long long inc(long long &x,long long y){return x+=y;}
inline long double inc(long double &x,long double y){return x+=y;}
inline long long dec(int &x){return --x;}
inline long long dec(long long &x){return --x;}
inline long long dec(int &x,long long y){return x-=y;}
inline long long dec(long long &x,long long y){return x-=y;}
inline long double dec(long double &x,long double y){return x-=y;}
inline long long mul(int &x){return x=((long long)x)*x;}
inline long long mul(long long &x){return x=x*x;}






inline long long divi(const int &x)
{
	long long ans,l,r,mid;
	ans=0;l=0;r=0x3fffffff;
	while (l<r)
	{
		mid=(l+r)/2;
		if (mid*mid<=x)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	return ans;
}
inline long long divi(const long long &x)
{
	long long ans,l,r,mid;
	ans=0;l=0;r=0x3fffffff;
	while (l<r)
	{
		mid=(l+r)/2;
		if (mid*mid<=x)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	return ans;
}
inline long long divi(int &x,long long y){return x/=y;}
inline long long divi(long long &x,long long y){return x/=y;}
inline long double divi(long double &x,long double y){return x/=y;}
inline long long mod(int &x,long long y){return x%=y;}
inline long long mod(long long &x,long long y){return x%=y;}








































int n,m,k,i,j,csc=1009,x,rev[400005];
long double pi=3.141592653589793;
struct cpx
{
	long double x,y;
	cpx operator + (const cpx &z) const
	{
		return (cpx){x+z.x,y+z.y};
	}
	cpx operator - (const cpx &z) const
	{
		return (cpx){x-z.x,y-z.y};
	}
	cpx operator * (const cpx &z) const
	{
		return (cpx){x*z.x-y*z.y,x*z.y+y*z.x};
	}
	cpx operator / (const long double &z) const
	{
		return (cpx){x/z,y/z};
	}
}b[400005],c[400005];
vector<int> a[400005];
set<pair<int,int> > s;
void ntt(cpx *a,int len,int op)
{
	int i,j,k;
	forup(i,0,len-1)
	{
		if (rev[i]<i) swap(a[i],a[rev[i]]);
	}
	for (i=1;i<len;i*=2)
	{
		cpx t=(cpx){cos(pi/i),sin(-op*pi/i)};
		for (j=0;j<len;j+=i+i)
		{
			cpx s=(cpx){1,0};
			for (k=0;k<i;k++)
			{
				cpx x=a[j+k],y=a[i+j+k]*s;
				a[j+k]=x+y;
				a[i+j+k]=x-y;
				s=s*t;
			}
		}
	}
	if (op==-1)
	{
		for (i=0;i<len;i++) a[i]=a[i]/len;
	}
}
int init(int x)
{
	int len=1,lg=0;
	while (len<x)
	{
		len*=2;
		lg++;
	}
	int i;
	forup(i,0,len-1)
	{
		rev[i]=rev[i/2]/2+(((1<<(lg-1)))*(i&1));
	}
	return len;
}
void mul(int x,int y)
{
	

	int len=init(a[x].size()+a[y].size()+1);
	forup(i,0,len-1)
	{
		b[i]=c[i]=(cpx){0,0};
		if (i<a[x].size()) b[i]=(cpx){a[x][i],0};
		if (i<a[y].size()) c[i]=(cpx){a[y][i],0};
	}
	ntt(b,len,1);
	ntt(c,len,1);
	forup(i,0,len-1)
	{
		b[i]=b[i]*c[i];
	}
	ntt(b,len,-1);
	a[x].clear();a[y].clear();
	forup(i,0,len-1)
	{
		a[x].push_back(((long long)(b[i].x+0.3))%csc);
	}
	while (a[x].back()==0) a[x].pop_back();
}
int main()
{
	read(n);read(m);read(k);
	rep(i,m) a[i].push_back(1);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x].push_back(1);
	}
	rep(i,m)
	{
		s.insert(make_pair(a[i].size(),i));
	}
	while (s.size()>1)
	{
		int x=s.begin()->se;s.erase(s.begin());
		int y=s.begin()->se;s.erase(s.begin());
		mul(x,y);
		s.insert(make_pair(a[x].size(),x));
	}
	if (a[s.begin()->se].size()>k) cout<<a[s.begin()->se][k]<<endl; else cout<<"fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffcscffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
	return 0;
}