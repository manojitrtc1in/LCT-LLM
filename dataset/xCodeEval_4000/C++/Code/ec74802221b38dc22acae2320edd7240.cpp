
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=2e5+5;
const LL mod=1e9;
struct mat{
	LL v[2][2];
	int x,y;
	mat(){
		memset(v,0,sizeof(v));
	}
	mat(int x){
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++){
				if (i!=j)v[i][j]=0;
				else v[i][j]=x;
			}
		}
	}
};
mat Gt2(LL d,LL len);
mat mul(mat &a,mat &b){
	mat c;
	c.x=a.x;c.y=b.y;
	for (int i=0;i<a.x;i++){
		for (int j=0;j<b.y;j++){
			for (int k=0;k<a.y;k++){
				c.v[i][j]+=a.v[i][k]*b.v[k][j];
			}
			c.v[i][j]%=mod;
		}
	}
	return c;
}
mat prv[Maxn];
int val[Maxn];
int n,m;
mat tree[Maxn*4];
LL tag[Maxn*4];
mat coef;
LL fib[Maxn],sum[Maxn];

mat Gt(int va){
	mat ret;
	ret.x=2;ret.y=1;
	ret.v[0][0]=va;
	ret.v[1][0]=va;
	return ret;
}
mat add(mat a,mat b){
	for (int i=0;i<a.x;i++){
		for (int j=0;j<a.y;j++){
			a.v[i][j]+=b.v[i][j];
			if (a.v[i][j]>=mod) a.v[i][j]-=mod;
		}
	}
	return a;
}
inline mat Merge(mat &lf,mat &rg,int siz){
	return add(lf,mul(prv[siz],rg));
}
void build(int p,int l,int r){
	if (l==r){
		tree[p]=Gt(val[l]);
		return;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p]=Merge(tree[p*2],tree[p*2+1],mid-l+1);
}
void Push(int p,int l,int r){
	tag[p*2]+=tag[p];
	tag[p*2+1]+=tag[p];
	int mid=l+r>>1;
	tree[p*2]=add(tree[p*2],Gt2(tag[p],mid-l+1));
	tree[p*2+1]=add(tree[p*2+1],Gt2(tag[p],r-mid));
	tag[p]=0;
}
void modify(int p,int l,int r,int pos,int val){
	if (l==r){
		tree[p]=Gt(val);
		return;
	}
	int mid=l+r>>1;
	Push(p,l,r);
	if (pos<=mid){
		modify(p*2,l,mid,pos,val);
	} 
	else{
		modify(p*2+1,mid+1,r,pos,val);
	}
	tree[p]=Merge(tree[p*2],tree[p*2+1],mid-l+1);
}
mat Gt2(LL d,LL len){
	mat ret;
	ret.x=2;ret.y=1;
	ret.v[0][0]=sum[len-1]*d%mod;
	ret.v[1][0]=(sum[len]-1)*d%mod;
	return ret;
}
void Modify(int p,int l,int r,int lo,int hi,int d){
	if (lo<=l && r<=hi){
		tag[p]+=d;
		tree[p]=add(tree[p],Gt2(d,r-l+1));
		return;
	}
	int mid=l+r>>1;
	Push(p,l,r);
	if (lo<=mid){
		Modify(p*2,l,mid,lo,min(hi,mid),d);
	}
	if (hi>mid){
		Modify(p*2+1,mid+1,r,max(lo,mid+1),hi,d);
	}
	tree[p]=Merge(tree[p*2],tree[p*2+1],mid-l+1);
}
mat query(int p,int l,int r,int lo,int hi,int off){
	if (lo<=l && r<=hi){
		

		

		return mul(prv[off],tree[p]);
	} 
	int mid=l+r>>1;
	Push(p,l,r);
	if (lo<=mid && hi>mid){
		return add(query(p*2,l,mid,lo,min(hi,mid),off),query(p*2+1,mid+1,r,max(lo,mid+1),hi,off+mid-lo+1));
	}
	else if (lo<=mid){
		return query(p*2,l,mid,lo,min(hi,mid),off);
	}
	else{
		return query(p*2+1,mid+1,r,max(lo,mid+1),hi,off);
	}
}
int main(){
	fib[0]=fib[1]=1;
	for (int i=2;i<Maxn;i++){
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=mod; 
	}
	sum[0]=fib[0];
	prv[0]=mat(1);
	prv[0].x=prv[0].y=2;
	coef.x=2;coef.y=2;
	coef.v[0][0]=0;coef.v[0][1]=1;
	coef.v[1][0]=1;coef.v[1][1]=1;
	for (int i=1;i<Maxn;i++){
		prv[i]=mul(prv[i-1],coef);
	}
	for (int i=1;i<Maxn;i++){
		sum[i]=(sum[i-1]+fib[i])%mod;
	}

	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		val[i]=read();
	}
	build(1,1,n);
	for (int i=0;i<m;i++){
		int tp;
		tp=read();
		if (tp==1){
			int pos,va;
			pos=read();va=read();
			modify(1,1,n,pos,va);
		}
		else if (tp==3){
			int l,r,d;
			l=read();r=read();d=read();
			Modify(1,1,n,l,r,d);
		}
		else{
			int l,r;
			l=read();r=read();
			mat ans=query(1,1,n,l,r,0);
			printf("%I64d\n",ans.v[0][0]);
		}
	}
}

