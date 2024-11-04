 

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
vector<pair<int,char> > v[105];
bool dp[105][105][26];
bool used[105][105][26];
bool dfs(int x,int y,char c)
{
	if(used[x][y][c-'a'])
	return dp[x][y][c-'a'];
	bool check=false;
	for(int i=0;i<v[x].size() ;i++)
	{
		if(v[x][i].second <c)
		continue;
		if(!dfs(y,v[x][i].first,v[x][i].second ))
		{
			check=true;
			break;
		}
	}
	dp[x][y][c-'a']=check;
	used[x][y][c-'a']=true;
	return check;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char z;
		cin>>x>>y>>z;
		v[x].push_back(mp(y,z)); 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool ans=dfs(i,j,'a');
			cout<<(ans?"A":"B");
		}
		cout<<endl;
	}
	return 0;
}
