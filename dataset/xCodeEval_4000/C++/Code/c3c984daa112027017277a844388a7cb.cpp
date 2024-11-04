


#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(...) return printf(__VA_ARGS__),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang
#define endl '\n'
#define left leftxiaomiexudurenrenyouze
#define hash hashxushibingduyouweilifushiyiqiedewuti




using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
struct fastIO
{
	inline fastIO operator>>(int& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(INT& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(float& num)
	{
		scanf("%f",&num);
		return *this;
	}
	inline fastIO operator>>(double& num)
	{
		scanf("%lf",&num);
		return *this;
	}
	inline fastIO operator>>(long double& num)
	{
		scanf("%Lf",&num);
		return *this;
	}
	inline fastIO operator>>(char& num)
	{
		num=getchar();
		while(num==' '||num=='\n')num=getchar();
		return *this;
	}
	inline fastIO operator>>(char* num)
	{
		int cnt=0;
		char c=getchar();
		while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n')
		{
			num[cnt++]=c;
			c=getchar();
		}
		num[cnt]=0;
		return *this;
	}
	inline fastIO operator>>(string& num)
	{
		cin>>num;
		return *this;
	}
	inline void printInt(const int& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printInt(num/10);
		putchar((num%10)+'0');
	}
	inline void printINT(const INT& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printINT(num/10);
		putchar((num%10)+'0');
	}
	inline fastIO operator<<(const int& num)
	{
		if(num<0)putchar('-'),printInt(-num);
		else printInt(num);
		return *this;
	}
	inline fastIO operator<<(const INT& num)
	{
		if(num<0)putchar('-'),printINT(-num);
		else printINT(num);
		return *this;
	}
	inline fastIO operator<<(const float& num)
	{
		printf("%.10f",num);
		return *this;
	}
	inline fastIO operator<<(const double& num)
	{
		printf("%.16lf",num);
		return *this;
	}
	inline fastIO operator<<(const long double& num)
	{
		printf("%.20Lf",num);
		return *this;
	}
	inline fastIO operator<<(const char& num)
	{
		putchar(num);
		return *this;
	}
	inline fastIO operator<<(const char* num)
	{
		for(int i=0;num[i];i++)
			putchar(num[i]);
		return *this;
	}
	inline fastIO operator<<(const string& num)
	{
		cout<<num;
		return *this;
	}
}fio;





struct Edge{
	int to,cap,rev;
	Edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};

vector<Edge> egs[5005];

void NewEdge(int u,int v,int cap){
	egs[u].pb(Edge(v,cap,SZ(egs[v])));
	egs[v].pb(Edge(u,0,SZ(egs[u])-1));
}

bool lgl[5005];

int dfs(int frm,int to,int cap){
	if(frm==to){
		return cap;
	}
	lgl[frm]=1;
	for(int i=0;i<SZ(egs[frm]);i++){
		if(egs[frm][i].cap&&!lgl[egs[frm][i].to]){
			int ff=dfs(egs[frm][i].to,to,min(cap,egs[frm][i].cap));
			if(ff){
				egs[frm][i].cap-=ff;
				egs[egs[frm][i].to][egs[frm][i].rev].cap+=ff;
				return ff;
			}
		}
	}
	return 0;
}

int Cnt=1;
vector<pair<pii,int> > vtx[5005];
int n,m;
int a[105];

int main(){
	fio>>n>>m;
	for(int i=1;i<=n;i++){
		fio>>a[i];
		int ai=a[i];
		for(int j=2;j*j<=ai;j++){
			if(ai%j==0){
				int cnt=0;
				while(ai%j==0){
					ai/=j;
					cnt++;
				}
				vtx[i].pb(mp(mp(j,cnt),Cnt));
				NewEdge(0,Cnt,cnt);
				NewEdge(Cnt+1,5004,cnt);
				Cnt+=2;
			}
		}
		if(ai!=1){
			vtx[i].pb(mp(mp(ai,1),Cnt));
			NewEdge(0,Cnt,1);
			NewEdge(Cnt+1,5004,1);
			Cnt+=2;
		}
	}
	for(int i=0;i<m;i++){
		int x,y;
		fio>>x>>y;
		for(int j=0;j<SZ(vtx[x]);j++){
			for(int k=0;k<SZ(vtx[y]);k++){
				if(vtx[x][j].first.first==vtx[y][k].first.first){
					NewEdge(vtx[x][j].second,vtx[y][k].second+1,min(vtx[x][j].first.second,vtx[y][k].first.second));
					NewEdge(vtx[y][k].second,vtx[x][j].second+1,min(vtx[x][j].first.second,vtx[y][k].first.second));
				}
			}
		}
	}
	int ans=0;
	while(1){
		FILL0(lgl);
		int ff=dfs(0,5004,Inf);
		if(!ff){
			break;
		}
		ans+=ff;
	}
	fio<<ans/2<<endl;
	return 0;
}