









#include<bits/stdc++.h>
#define bint BigInteger
#define hh puts("");
#define yes puts("yes");
#define no puts("no");
#define YES puts("YES");
#define NO puts("NO");
#define open(x) freopen(x,"r",stdin);
#define write(x) freopen(x,"w",stdout);
#define file(x,y) freopen(x,"r",stdin);freopen(y,"w",stdout);
#define printa(a,n) for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
#define prints(a,n) for(int i=0;i<n;i++)printf("%c",a[i]);puts("");
using namespace std;
mt19937 rd(time(NULL)^clock());
typedef long long ll;typedef unsigned long long ull;
const int N = 101,dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
const double pi = 3.1415926,e = exp(1);
class BigInteger{static const int BASE=100000000;static const int WIDTH=8;public:vector<int>s;BigInteger&clean(){while(!s.back()&&s.size()>1)s.pop_back();return*this;}BigInteger(unsigned long long num=0){*this=num;}BigInteger(string s){*this=s;}BigInteger&operator=(long long num){s.clear();do{s.push_back(num%BASE);num/=BASE;}while(num>0);return*this;}BigInteger&operator=(const string&str){s.clear();int x,len=(str.length()-1)/WIDTH+1;for(int i=0;i<len;i++){int end=str.length()-i*WIDTH;int start=max(0,end-WIDTH);sscanf(str.substr(start,end-start).c_str(),"%d",&x);s.push_back(x);}return this->clean();}BigInteger operator+(const BigInteger&b)const{BigInteger c;c.s.clear();for(int i=0,g=0;;i++){if(g==0&&i>=s.size()&&i>=b.s.size())break;int x=g;if(i<s.size())x+=s[i];if(i<b.s.size())x+=b.s[i];c.s.push_back(x%BASE);g=x/BASE;}return c;}BigInteger operator-(const BigInteger&b)const{assert(b<=*this);BigInteger c;c.s.clear();for(int i=0,g=0;;i++){if(g==0&&i>=s.size()&&i>=b.s.size())break;int x=s[i]+g;if(i<b.s.size())x-=b.s[i];if(x<0){g=-1;x+=BASE;}else g=0;c.s.push_back(x);}return c.clean();}BigInteger operator*(const BigInteger&b)const{int i,j;unsigned long long g;vector<unsigned long long>v(s.size()+b.s.size(),0);BigInteger c;c.s.clear();for(i=0;i<s.size();i++)for(j=0;j<b.s.size();j++)v[i+j]+=ull(s[i])*b.s[j];for(i=0,g=0;;i++){if(g==0&&i>=v.size())break;unsigned long long x=v[i]+g;c.s.push_back(x%BASE);g=x/BASE;}return c.clean();}BigInteger operator/(const BigInteger&b)const{assert(b>0);BigInteger c=*this,m;for(int i=s.size()-1;i>-1;i--){m=m*BASE+s[i];c.s[i]=bsearch(b,m);m-=b*c.s[i];}return c.clean();}BigInteger operator%(const BigInteger&b)const{BigInteger c=*this;BigInteger m;for(int i=s.size()-1;i>-1;i--){m=m*BASE+s[i];c.s[i]=bsearch(b,m);m-=b*c.s[i];}return m;}int bsearch(const BigInteger&b,const BigInteger&m)const{int L=0,R=BASE-1,x;while(1){x=(L+R)>>1;if(b*x<=m){if(b*(x+1)>m)return x;else L=x;}else R=x;}}BigInteger&operator+=(const BigInteger&b){*this=*this+b;return*this;}BigInteger&operator-=(const BigInteger&b){*this=*this-b;return*this;}BigInteger&operator*=(const BigInteger&b){*this=*this*b;return*this;}BigInteger&operator/=(const BigInteger&b){*this=*this/b;return*this;}BigInteger&operator%=(const BigInteger&b){*this=*this%b;return*this;}bool operator<(const BigInteger&b)const{if(s.size()!=b.s.size())return s.size()<b.s.size();for(int i=s.size()-1;i;i--)if(s[i]!=b.s[i])return s[i]<b.s[i];return s[0]<b.s[0];}bool operator>(const BigInteger&b)const{return b<*this;}bool operator<=(const BigInteger&b)const{return!(b<*this);}bool operator>=(const BigInteger&b)const{return!(*this<b);}bool operator!=(const BigInteger&b)const{return b<*this||*this<b;}bool operator==(const BigInteger&b)const{return!(b<*this)&&!(b>*this);}};ostream&operator<<(ostream&out,const BigInteger&x){out<<x.s.back();for(int i=x.s.size()-2;i>-1;i--){char buf[20];sprintf(buf,"%08d",x.s[i]);for(int j=0;j<strlen(buf);j++)out<<buf[j];}return out;}istream&operator>>(istream&in,BigInteger&x){string s;if(!(in>>s))return in;x=s;return in;}
int ola_prime[N];
bool ola_isprime[N],sun_isprime[N/2];
ll fac[1000001];


int gcd(int a,int b);int lcm(int a,int b);int daoxu(int n);bool hw(int n);ll ksm(ll a,ll b,int c);int char_to_digit(char c);char digit_to_char(int x);void kprintl(int n,char s[],int m);void ktol(int n,char s[],int m);void strupper(char s[]);void strlower(char s[]);int qh(int n);void makejc(int n,ll p);ll C(ll n,ll m,ll p);ll jc(ll n,ll p);



#define endl '\n'







signed main()
{
	int a[200001],b[200001];
	int n,f,i,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
			cin>>b[i];
		f = 1;
		int x = 0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<b[i])
			{
				f = 0;
				break;
			}
			x = max(x,a[i]-b[i]);
		}
		if(!f)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(max(a[i]-x,0)!=b[i])
			{
				f = 0;
				break;
			}
		}
		if(f)
			puts("YES");
		else
			puts("NO");
	}
    return 0;
}























































int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

bool hw(int n)
{
	int a,b;
	a = n;
	b = 0;
	while(a)
	{
		b = b*10+a%10;
		a /= 10;
	}
	return n==b;
}
int daoxu(int n)
{
	
	int b=0;
	while(n)
	{
		b = b*10+n%10;
		n /= 10;
	}
	return b;
}
ll ksm(ll a,ll b,int c)
{
	a %= c;
	ll s = 1;
	while(b)
	{
		if(b&1)
			s = s*a%c;
		b >>= 1;
		a = a*a%c;
	}
	return s%c;
}
int char_to_digit(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else
		return c-'a'+10;
}
char digit_to_char(int x)
{
	if(x<=9)
		return x+'0';
	else
		return (x-10)+'a';
}
void kprintl(int n,char s[],int m)
{
	
	int cnt = 0,v = 0,l = strlen(s),i;
	char c[100001];
	for(i=0;i<l;i++)
		v = v*n+char_to_digit(s[i]);
	while(v!=0)
		c[cnt] = digit_to_char(v%m),v /= m,cnt++;
	for(i=cnt-1;i>=0;i--)
		putchar(c[i]);
	puts("");
		
}
void ktol(int n,char s[],int m)
{
	int cnt = 0,v = 0,l = strlen(s),i;
	char c[100001];
	for(i=0;i<l;i++)
		v = v*n+char_to_digit(s[i]);
	while(v!=0)
		c[cnt] = digit_to_char(v%m),v /= m,cnt++;
	s[cnt] = '\0';
	for(i=cnt;i>=0;i--)
		s[cnt-i-1] = c[i];
}
void strupper(char s[])
{
	int i,l;
	l = strlen(s); 
	for(i=0;i<l;i++)
		if(islower(s[i]))
			s[i] -= 32;
}
void strlower(char s[])
{
	int i,l;
	l = strlen(s);
	for(i=0;i<l;i++)
		if(isupper(s[i]))
			s[i] += 32; 
}
int qh(int n)
{
	int s = 0,a;
	while(n)
	{
		a = n%10;
		n /= 10;
		s += a;
	}
	return s;
}
void makejc(int n,ll p)
{
	int i;
	fac[0] = 1;
	for(i=1;i<=n;i++)
		fac[i] = (fac[i-1]*i)%p;
	return;
}
ll C(ll n,ll m,ll p)
{
	if(m>n)
		return 0;
	return ((fac[n]*ksm(fac[m],p-2,p))%p*ksm(fac[n-m],p-2,p));
}
ll jc(int n,ll p)
{
	makejc(n,p);
	return fac[n];
}