 

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

pair<ll,ll> a[100005];

pair<ll,ll> b[100005];

priority_queue<pair<ll,ll> > pq;
ll n,m;
ll dfs(ll x,ll y,ll res)

{
	

	if(a[x].second >=y)
	{
		a[x].second-=y;
		return (res+y*a[x].first );
	}
	res+=a[x].second *a[x].first ;
	y-=a[x].second ;
	a[x].second =0;
	while(!pq.empty() )
	{
		if(a[-pq.top() .second].second ==0)
		pq.pop() ;
		if(a[-pq.top() .second].second>0)
		{
			return dfs(-pq.top() .second ,y,res);
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		ll x;
		x=read();
		a[i].second=x;
		b[i].second=i;
	}
	for(int i=1;i<=n;i++)
	{
		ll x;
		x=read();
		a[i].first =x;
		b[i].first =x;
	}
	for(int i=1;i<=n;i++)
	{
		pq.push(mp(-b[i].first ,-b[i].second ));
	}
	

	for(int i=1;i<=m;i++)
	{
		ll x,y;
		x=read(),y=read();
		cout<<dfs(x,y,0)<<endl;
	}
	return 0;
}
