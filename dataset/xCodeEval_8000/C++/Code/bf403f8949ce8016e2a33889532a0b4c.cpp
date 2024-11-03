#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define fi first
#define se second
#define  all(d) d.begin(),d.end()
#define allr(d) d.rbegin(),d.rend()
#define For(i,d,c) for(int i = d;i <= c;++i)
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
	template<typename T,typename... _T> inline void Min(T&a,T b,_T ...c){Min(a,b);Min(a,c...);}
	template<typename T,typename... _T> inline void Max(T&a,T b,_T ...c){Max(a,b);Max(a,c...);}
}
using namespace io;
const int maxn= 1 << 21;
const int N = 2e3 + 3;
const int mod=1e9 + 7;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
int k,h;
ll t[N + 3];
int dp[2][N][N];
string  s;
bool kt[N];
map<int,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

int add(int&a,int b) 
{
	a += b;
	if (a >= mod ) a-= mod;
}

int sub(int a,int b)
{
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int main()
{
	IOS;
	cin >> n >> m;
	if (n + m == 2) return cout <<"1",0;
	vector<vector<int>> lab(n + 2,vector<int>(m+2));
	for (int i = 1;i <= n;++i) {
		cin >> s;
		for (int j = 1;j <= m;++j) lab[i][j] = s[j-1] == 'R';
	}
	vector<vector<vector<int>>> last(2,vector<vector<int>>(n+2,vector<int>(m+2)));
	last[0] = last[1] = lab;
	for (int i = n;i ;--i) {
		for (int j = m;j;--j) {
			if (i < n) last[0][i][j] += last[0][i+1][j];
			if (j < m) last[1][i][j] += last[1][i][j+1];
		}
	}
	vector<int> cid(m+1,1),rid(n+1,1);
	dp[0][1][1] = dp[1][1][1] = 1;
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			if (i + j == 2) continue;
			while (last[0][cid[j]+1][j] > n - i) ++cid[j];
			while (last[1][i][rid[i]+1] > m - j) ++rid[i];
			dp[0][i][j] = sub(dp[1][i][j-1],dp[1][i][rid[i]-1]);
			add(dp[0][i][j],dp[0][i-1][j]);
			dp[1][i][j] = sub(dp[0][i-1][j],dp[0][cid[j]-1][j]);
			add(dp[1][i][j],dp[1][i][j-1]);
			

		}
		

	}
	cout << (sub(dp[0][n][m],dp[0][n-1][m]) + sub(dp[1][n][m],dp[1][n][m-1])) % mod;
}
 

