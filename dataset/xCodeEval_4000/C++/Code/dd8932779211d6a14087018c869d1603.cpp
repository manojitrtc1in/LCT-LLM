 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define mp make_pair
#define pb push_back
#define itn int
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
typedef pair<pii,pii >piiii;
const int INF=1e9+7;
const int hash1=20041123;
const int hash2=20050208;
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}

int n,m;
ll phi;
int cant[200005];
vector<int> v[200005];
ll gcd(ll x,ll y)
{
	return (y==0?x:gcd(y,x%y));
}
ll power(ll x,ll y)
{
	ll res=1;
	while(y!=0)
	{
		if(y%2==1)
		res=res*x%m;
		x=x*x%m;
		y/=2;
	}
	return res;
}
ll get(ll x,ll y)
{
	int g=gcd(x,y);
	x/=g,y/=g;
	return y*power(x,phi-1)%m;
}
bool used[200005];
int dp[200005];
int pa[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	phi=m;
	int tn=m;
	for(int i=2;i<=m;i++)
	{
		if(tn%i==0)
		{
			phi=phi/i*(i-1);
			while(tn%i==0)
			tn/=i;
		}
	}
	for(itn i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		used[x]=true;
	}
	for(int i=0;i<m;i++)
	{
		if(used[i])
		continue;
		v[gcd(m,i)].push_back(i); 
	}
	for(int i=1;i<=m;i++)
	{
		if(m%i)
		continue;
		dp[i]+=v[i].size() ;
		for(int j=i+i;j<=m;j+=i)
		{
			if(m%j)
			continue;
			if(dp[j]<=dp[i])
			{
				dp[j]=dp[i];
				pa[j]=i;
			}
		}
	}
	int a=m;
	int cnt=0;
	int ans[200005];
	while(true)
	{
		for(int i=0;i<v[a].size() ;i++)
		{
			ans[cnt++]=v[a][i];
		}
		if(a==1)
		break;
		a=pa[a];
	}
	cout<<cnt<<endl<<ans[cnt-1]<<' ';
	for(itn i=cnt-1;i>0;i--)
	cout<<get(ans[i],ans[i-1])<<' ';
	return 0;
}
