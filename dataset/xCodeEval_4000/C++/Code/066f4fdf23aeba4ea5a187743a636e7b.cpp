


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
inline int read()
{
	int num=0;
	char c=getchar();
	if(c=='-')return -read();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}
inline INT READ()
{
	INT num=0;
	char c=getchar();
	if(c=='-')return -READ();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}





struct event13
{
	int id;
	int y;
	int x1,x2;
	int tp;

	event13(int tp,int id,int y,int x1,int x2):id(id),y(y),x1(x1),x2(x2),tp(tp){}
	event13(){}
	bool operator<(const event13& evvvv)const
	{
		if(y!=evvvv.y)return y<evvvv.y;
		if(tp!=evvvv.tp)return !tp;
		if(!tp)return id>evvvv.id;
		else return id<evvvv.id;
	}
};

struct n0de
{
	set<int> ids;
	int unbig,sml;
	n0de():unbig(-1),sml(-1){}
};

int n,m;

vector<int> lissan;
map<int,int> fls;
bool sig[200007];

struct segtree
{
	n0de dt[800007];
	void calc(int now,int l,int r)
	{


		if(l!=r)
		{
			int m=(l+r)>>1;


			if(dt[now<<1].unbig!=-1&&sig[dt[now<<1].unbig])
				calc(now<<1,l,m);


			if(dt[now<<1|1].unbig!=-1&&sig[dt[now<<1|1].unbig])
				calc(now<<1|1,m+1,r);


			dt[now].unbig=max(dt[now<<1].unbig,dt[now<<1|1].unbig);
			dt[now].sml=min(dt[now<<1].sml,dt[now<<1|1].sml);
		}
		else
			dt[now].unbig=dt[now].sml=-1;
		if(SZ(dt[now].ids))
		{
			int t0p=*dt[now].ids.rbegin();

			dt[now].sml=max(dt[now].sml,t0p);
			if(dt[now].unbig<t0p)
			{
				dt[now].unbig=-1;
				if(!sig[t0p]&&dt[now].sml==t0p)
					dt[now].unbig=t0p;
			}
		}
	}
	void update(int now,int nl,int nr,int l,int r,int tp,int id)
	{
		if(lissan[nr+1]<=l||lissan[nl]>=r)return;
		if(lissan[nl]>=l&&lissan[nr+1]<=r)
		{
			if(!tp)dt[now].ids.insert(id);
			else dt[now].ids.erase(id);
			calc(now,nl,nr);
			return;
		}
		int m=(nl+nr)>>1;
		update(now<<1,nl,m,l,r,tp,id);
		update(now<<1|1,m+1,nr,l,r,tp,id);
		calc(now,nl,nr);
	}
	void upd(int tp,int frm,int to,int id)
	{
		update(1,0,m-2,frm,to,tp,id);
		while(calc(1,0,m-2),dt[1].unbig!=-1)
			sig[dt[1].unbig]=1;
	}
}seg;

int have_a_count()
{
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=(sig[i]==1);
	return cnt;
}

vector<event13> evs;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		evs.pb(event13(0,i,b,a,c));
		evs.pb(event13(1,i,d,a,c));
		lissan.pb(a);
		lissan.pb(c);
	}
	sort(ALL(evs));
	sort(ALL(lissan));
	lissan.erase(unique(lissan.begin(),lissan.end()),lissan.end());
	m=SZ(lissan);
	for(int i=0;i<2*n;i++)
		seg.upd(evs[i].tp,evs[i].x1,evs[i].x2,evs[i].id);
	printf("%d\n",have_a_count()+1);
	return 0;
}
