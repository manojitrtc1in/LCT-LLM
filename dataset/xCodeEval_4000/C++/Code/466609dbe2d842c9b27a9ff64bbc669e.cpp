


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





struct BinCharGay{
	int fa[100007];
	void init(){
		for(int i=0;i<100007;i++){
			fa[i]=i;
		}
	}
	int root(int x){
		return fa[x]==x?x:(fa[x]=root(fa[x]));
	}
	void conn(int x,int y){
		fa[root(x)]=root(y);
	}
}dsu;

int lgl[100007];
vector<pii> nei[100007];

void dfs(int now,int sig){
	lgl[now]=sig;
	for(pii i:nei[now]){
		if(!lgl[i.first]){
			dfs(i.first,sig);
		}
	}
}

int n,m;
int k;
pair<int,pii> egs[200007];
vector<pii> nei2[100007];
INT cnteg=0;
int fa[25][100007];
int ceng[100007];
int mxval[25][100007];

void dfs2(int now=1,int lst=0,int val=0){
	fa[0][now]=lst;
	ceng[now]=ceng[lst]+1;
	mxval[0][now]=val;
	for(pii i:nei2[now]){
		if(i.first!=lst){
			dfs2(i.first,now,i.second);
		}
	}
}

int LCAmax(int a,int b){
	if(ceng[b]>ceng[a]){
		swap(a,b);
	}
	int maxv=0,tomove=ceng[a]-ceng[b];
	for(int i=0;i<=20;i++){
		if(BIT(tomove,i)){
			maxv=max(maxv,mxval[i][a]);
			a=fa[i][a];
		}
	}
	if(a==b){
		return maxv;
	}
	for(int i=20;i>=0;i--){
		if(fa[i][a]!=fa[i][b]){
			maxv=max(maxv,mxval[i][a]);
			maxv=max(maxv,mxval[i][b]);
			a=fa[i][a];
			b=fa[i][b];
		}
	}
	maxv=max(maxv,mxval[0][a]);
	maxv=max(maxv,mxval[0][b]);
	return maxv;
}

int main(){
	fio>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		fio>>a>>b>>c;
		nei[a].pb(mp(b,c));
		nei[b].pb(mp(a,c));
		egs[i]=mp(c,mp(a,b));
	}
	sort(egs,egs+m);
	int CntLianTongKuai=0;
	for(int i=1;i<=n;i++){
		if(!lgl[i]){
			dfs(i,++CntLianTongKuai);
		}
	}
	if(CntLianTongKuai>2){
		fio>>k;
		while(k--){
			int junk,rubbish;
			fio>>junk>>rubbish;
			fio<<"-1\n";
		}
		return 0;
	}
	dsu.init();
	for(int i=0;i<m;i++){
		if(dsu.root(egs[i].second.first)!=dsu.root(egs[i].second.second)){
			nei2[egs[i].second.first].pb(mp(egs[i].second.second,egs[i].first));
			nei2[egs[i].second.second].pb(mp(egs[i].second.first,egs[i].first));
			dsu.conn(egs[i].second.first,egs[i].second.second);
			cnteg+=egs[i].first;
		}
	}
	if(CntLianTongKuai==2){
		fio>>k;
		while(k--){
			int a,b;
			fio>>a>>b;
			if(lgl[a]==lgl[b]){
				fio<<"-1\n";
			}else{
				fio<<cnteg<<endl;
			}
		}
		return 0;
	}else{
		fio>>k;
		dfs2();
		for(int i=1;i<=20;i++){
			for(int j=1;j<=n;j++){
				fa[i][j]=fa[i-1][fa[i-1][j]];
				mxval[i][j]=max(mxval[i-1][j],mxval[i-1][fa[i-1][j]]);
			}
		}
		while(k--){
			int a,b;
			fio>>a>>b;
			fio<<cnteg-LCAmax(a,b)<<endl;
		}
	}
	return 0;
}