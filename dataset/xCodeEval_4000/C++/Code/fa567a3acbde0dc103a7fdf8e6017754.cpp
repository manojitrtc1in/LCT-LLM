 

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

char a[3][15]={
"AAA.A.A....A",
".A..A.AAAAAA",
".A.AAAA....A"};
char b[15][15];
char ans[15][15];
int n,m;
int mx=-1,le;
void dfs(int x,int y,int now)
{
	if(x>=n-2)
	{
		if(now>mx)
		{
			mx=now;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					ans[i][j]=b[i][j];
				}
			}
		}
		return;
	}
	if(y>=m-2)
	{
		dfs(x+1,0,now);
		return;
	}
	if(le/5+now<=mx)
	return;
	le-=b[x][y]=='.';
	for(int k=0;k<12;k+=3)
	{
		bool check=true;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[i][k+j]=='A' and b[x+i][y+j]!='.')
				check=false;
			}
		}
		if(check)
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(a[i][k+j]=='A')
					b[x+i][y+j]='A'+now;
				}
			}
			le-=5;
			dfs(x,y+1,now+1);
			le+=5;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(a[i][k+j]=='A')
					b[x+i][y+j]='.';
				}
			}
		}
	}
	dfs(x,y+1,now);
	le+=b[x][y]=='.';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	n=read(),m=read();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			b[i][j]=ans[i][j]='.';
		}
	}
	le=n*m;
	dfs(0,0,0);
	cout<<mx<<endl;
	for(itn i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
