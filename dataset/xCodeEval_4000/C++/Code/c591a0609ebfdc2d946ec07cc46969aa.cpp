


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





INT a[107][123456];
INT len[107];
INT n;
INT p[107],b[107];
INT V;

void mer9e(INT f1,INT f2,INT to){
	INT cur=0,cur1=0,cur2=0;
	while(cur1<len[f1]||cur2<len[f2]){
		if(a[f1][cur1]<a[f2][cur2]){
			a[to][cur]=a[f1][cur1];
			cur++;
			cur1++;
		}else{
			a[to][cur]=a[f2][cur2];
			cur++;
			cur2++;
		}
	}
	len[to]=cur;
	a[to][cur]=INF;
}

INT ksmii(INT a,INT b){
	if(!b){
		return 1;
	}
	INT fuck=ksmii(a,b/2);
	fuck*=fuck;
	if(b%2){
		fuck*=a;
	}
	return fuck;
}

INT fitch(INT start,INT djg){
	vector<INT> fch;
	fch.pb(b[djg]);
	INT cur=start;
	while(1){
		INT lst=fch[SZ(fch)-1];
		if(!lst){
			break;
		}else if(lst%2){
			fch.pb(lst/2);
		}else{
			fch.pb(lst-1);
		}
	}
	for(INT i=SZ(fch)-2;i>=0;i--){
		INT now=fch[i],nxt=fch[i+1];
		if(now==2*nxt+1){
			INT fus=ksmii(p[djg],nxt+1);
			for(INT i=0;i<len[cur];i++){
				a[cur+1][i]=a[cur][i]*fus;
			}
			len[cur+1]=len[cur];
			a[cur+1][len[cur+1]]=INF;
			mer9e(cur,cur+1,cur+2);
			cur+=2;
		}else{
			for(INT i=0;i<len[cur];i++){
				a[cur][i]*=p[djg];
			}
			mer9e(start,cur,cur+1);
			cur++;
		}
	}
	return cur;
}

INT ins[123456],cntin;
map<INT,pair<PII,PII> > geeloo;

void func(){
	INT c213=cntin-1;
	pair<PII,PII> ans;
	ans.first.first=INF;
	for(INT c1=0;c1<cntin;c1++){
		INT lst=V/ins[c1];
		while(lst/ins[c213]/ins[c213]==0){
			c213--;
		}
		for(INT c2=c213;c2>=c1;c2--){
			if(lst%ins[c2]){
				continue;
			}
			INT a1=ins[c1],a2=ins[c2];
			INT a3=V/a1/a2;
			ans=min(ans,mp(mp(2*(a1*(a2+a3)+a2*a3),a1),mp(a2,a3)));
			break;
		}
	}
	geeloo[V]=ans;
	fio<<ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
}

int main(){
	INT T;
	fio>>T;
	while(T--){
		fio>>n;
		V=1;
		a[0][0]=1;
		a[0][1]=INF;
		len[0]=1;
		for(INT i=0;i<n;i++){
			fio>>p[i]>>b[i];
			for(INT j=0;j<b[i];j++){
				V*=p[i];
			}
		}
		if(geeloo.count(V)){
			pair<PII,PII> ans=geeloo[V];
			fio<<ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
			continue;
		}
		INT xxx=0;
		for(INT i=0;i<n;i++){
			xxx=fitch(xxx,i);
		}
		for(INT i=0;i<len[xxx];i++){
			ins[i]=a[xxx][i];
		}
		cntin=len[xxx];
		func();
	}
	return 0;
}