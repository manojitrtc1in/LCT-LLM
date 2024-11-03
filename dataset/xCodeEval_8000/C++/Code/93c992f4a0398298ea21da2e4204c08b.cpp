#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define f first
#define s second
#define  all(d) d.begin(),d.end()
std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
namespace io
{
	template<typename T> inline void read(T&a){
		int c = getchar(),sign = 0;
		a = 0;
		while(c < '0' || c >'9') sign += (c == '-'),c = getchar();
		while (c >='0' && c <='9') a = (a << 1) + (a << 3) + c-48,c = getchar();
		if (sign&1) a = -a;
	}
	template<typename T,typename... _T>
	inline void read(T&a,_T& ...argc)
	{
		read(a);read(argc...);
	}
	template<typename T>
	inline void Write(T a)
	{
		if (a > 9) Write(a/10);
		putchar(a % 10 + '0');
	}
	template<typename T>
	inline void write(T a,char ch = ' ')
	{
		if (a < 0) putchar('-'),a = -a;
		Write(a);
		putchar(ch);
	}
	template<typename T> inline void Min(T&a,T b){a = min(a,b);}
	template<typename T> inline void Max(T&a,T b){a = max(a,b);}
}
using namespace io;
const int maxn= 1e5 ;
const int N = 4e5 + 3;
const int mod=998244353;
int n,m,q;
int dem[N],id[N],chot[N],a[N];
int k,h;
ll t[maxn + 2],dp[N + 3];
string  s;
bool kt[N];
map<int,int> maps;
vector<pair<int,int>> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}


vector<vector<int>> to(52,vector<int>(52,0));
vector<vector<vector<vector<int>>>> f(52,vector<vector<vector<int>>>(52,vector<vector<int>>(52,vector<int>(52,1e8))));

int getsum(int x1,int y1,int x2,int y2)
{
	x1--;
	y1--;
	return to[x2][y2] - to[x1][y2] - to[x2][y1] + to[x1][y1];
}

int solve(int x1,int y1,int x2,int y2)
{
	int& res = f[x1][y1][x2][y2];
	if (res != 1e8) return res;
	res = max(x2 - x1,y2 - y1) + 1;
	for (int i = x1;i < x2;++i) Min(res,solve(x1,y1,i,y2) + solve(i + 1,y1,x2,y2));
	for (int j = y1;j < y2;++j) Min(res,solve(x1,y1,x2,j) + solve(x1,j + 1,x2,y2));
	return res;
}

int main()
{
	IOS;
	cin >> n;
	for (int i =1;i <= n;++i)
	{
		cin >> s;
		for (int j = 1;j <= n;++j) 
		{
			to[i][j] = to[i][j-1] + (s[j-1] == '#');
			f[i][j][i][j] = s[j-1] == '#';
		}
	}
	cout << solve(1,1,n,n);
}


