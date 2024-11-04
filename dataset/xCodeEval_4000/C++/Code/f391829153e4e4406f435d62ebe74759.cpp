


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





vector<pii> nei[10005],nei2[10005],nei3[10005];
int ceng[10005];
int col[10005];
int n,m;
int lgl[10005],lgl2[10005];
vector<int> ans;
bool isintree[10005];
int dfnfn;
int fa[25][10005];
vector<int> fuck,shit;
int dy[10005];

void choolycol(int now,int colr,int cng,int lst=-1){
	if(lgl2[now]){
		return;
	}
	

	lgl2[now]=1;
	ceng[now]=cng;
	col[now]=colr;
	

	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i].first!=lst){
			if(!lgl2[nei[now][i].first]){
				

				dy[nei[now][i].first]=nei[now][i].second;
				fa[0][nei[now][i].first]=now;
				choolycol(nei[now][i].first,1-colr,cng+1,now);
			}else{
				if(now<nei[now][i].first){
					fuck.pb(nei[now][i].second);
					if(col[now]==col[nei[now][i].first]){
						shit.pb(nei[now][i].second);
					}
				}
			}
		}
	}
	

	return;
}

int dp1[10005],dp2[10005],dp3[10005];

int lca(int a,int b){
	if(ceng[a]>ceng[b]){
		swap(a,b);
	}
	int toup=ceng[b]-ceng[a];
	for(int i=0;i<=20;i++){
		if(BIT(toup,i)){
			b=fa[i][b];
		}
	}
	if(a==b){
		return a;
	}
	for(int i=20;i>=0;i--){
		if(fa[i][a]!=fa[i][b]){
			a=fa[i][a];
			b=fa[i][b];
		}
	}
	return fa[0][a];
}

void dfsdp(int now,int lst){
	lgl[now]=1;
	

	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i].first!=lst){
			if(!lgl[nei[now][i].first]){
				dfsdp(nei[now][i].first,now);
				dp2[now]+=dp2[nei[now][i].first];
				dp3[now]+=dp3[nei[now][i].first];
			}else{
				int to=lca(now,nei[now][i].first);
				if(col[now]==col[nei[now][i].first]){
					

					dp2[to]--;
					dp2[now]++;
				}else{
					dp3[to]--;
					dp3[now]++;
				}
			}
		}
	}
}

int main(){
	fio>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		fio>>a>>b;
		nei[a].pb(mp(b,i));
		nei[b].pb(mp(a,i));
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!lgl2[i]){
			choolycol(i,1,1);
			

			nei2[0].pb(mp(i,0));
			fa[0][i]=0;
		}
	}
	

	if(!SZ(shit)){
		for(int i=0;i<SZ(fuck);i++){
			ans.pb(fuck[i]);
		}
	}else if(SZ(shit)==1){
		ans.pb(shit[0]);
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
		}
	}
	sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<SZ(nei[i]);j++){
			if(col[i]==col[nei[i][j].first]){
				

				sum++;
			}
		}
	}
	sum/=2;
	FILL0(lgl);
	for(int i=1;i<=n;i++){
		if(!lgl[i]){
			dfsdp(i,-1);
		}
	}
	for(int i=1;i<=n;i++){
			

		if(dy[i]&&dp2[i]==sum){
			

			if(!(dp2[i]&&dp3[i])){
				ans.pb(dy[i]);
			}
		}
	}
	sort(ALL(ans));
	ans.resize(unique(ALL(ans))-ans.begin());
	fio<<SZ(ans)<<endl;
	for(int i=0;i<SZ(ans);i++){
		fio<<ans[i]<<' ';
	}
	fio<<endl;
	return 0;
}

