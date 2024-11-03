#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define fi first
#define se second
#define  all(d) d.begin(),d.end()
#define allr(d) d.rbegin(),d.rend()
#define For(i,d,c) for(int i = d;i <= c;++i)
std::mt19937 rgn(std::chrono::steady_clock::now().time_since_epoch().count());
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
const int maxn= 1e6 + 3;
const int N = 4e5 + 3;
const int mod= 1e9 + 7 ;
int n,m,q;
int dem[N],id[N],chot[N],a[N][10],b[N];
int k,h;
ll t[N + 3];
int dp[N];
string  s;
bool kt[N];
map<int,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}
 
void add(int &a,int b)
{
	a += b;
	if (a >= mod) a-= mod;
}
 
int mul(int a,int b)
{
	return 1ll * a * b % mod;
}
 
int main()
{
	IOS;
	cin >> n >> m;
	for (int i = 1;i <= n;++i) {
		for (int j = 0;j < m;++j) cin >> a[i][j];
	}
	int ans = -1;
	pair<int,int> res = {0,0};
	for (int mask = 1;mask < 1 << m;++mask) {
		int pos = 0;
		int value = 0;
		for (int i = 1;i <= n;++i) {
			int val = 1e9;
			for (int j = 0;j < m;++j) {
				if (mask >> j & 1) continue;
				val = min(val,a[i][j]);
			}
			if (!pos || value < val) pos = i,value = val;
		}
		for (int i = 1;i <= n;++i) {
			int val = 1e9;
			for (int j = 0;j < m;++j) {
				val = min(val,max(a[i][j],a[pos][j]));
			}
			if (ans < val) ans = val,res = {pos,i};
		}
	}
	cout << res.first <<" " << res.second ;
}
 
