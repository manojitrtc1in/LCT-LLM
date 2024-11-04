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
	template<typename T> inline void Min(T&a,T b){if (a > b) a = b;}
	template<typename T> inline void Max(T&a,T b){if (a < b) a = b;}
	template<typename T,typename... _T> inline void Min(T&a,T b,_T ...c){Min(a,b);Min(a,c...);}
	template<typename T,typename... _T> inline void Max(T&a,T b,_T ...c){Max(a,b);Max(a,c...);}
}
using namespace io;
const int maxn= 1e6 + 3;
const int N = 4e5 + 3;
const int mod= 1e9 + 7 ;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
int k,h;
ll t[N + 3];
string  s;
bool kt[N];
map<long long,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}
 
int main() {
	IOS;
	int n,q;
	cin >> n >> q;
	vector<vector<pair<int,int>>> edge(n + 1);
	for (int i = 1;i < n;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		edge[u].emplace_back(v,w);
		edge[v].emplace_back(u,w);
	}
	vector<vector<long long>> dp(2,vector<long long>(n + 1));
	function<void(int,int,int)> dfs = [&](int u,int p,int pos) {
		for (auto&x : edge[u]) {
			int v = x.first;
			if (v == p) continue;
			dp[pos][v] = dp[pos][u] + x.second;
			dfs(v,u,pos);
		}
	};
	dfs(1,0,0);
	dfs(n,0,1);
	long long can = 0;
	vector<pair<long long,int>> idx;
	for (int i = 1;i <= n;i++) idx.emplace_back(dp[0][i] - dp[1][i],i);
	sort(idx.begin(),idx.end());
	set<pair<long long,int>> m;
	vector<bool> kt(n + 1);
	for (auto&x : idx) {
		int u = x.second;
		for (auto&x : edge[u]) {
			int v = x.first;
			kt[v] = true;
		}
		for (auto&y : m) {
			if (!kt[y.second]) {
				can = max(can,-y.first + dp[1][u]);
				break;
			}
		}
		m.insert({-dp[0][u],u});
		for (auto&x : edge[u]) {
			int v = x.first;
			kt[v] = false;
		}
	}
	while (q--) {
		int x;
		cin >> x;
		cout << min(can + x,dp[0][n]) <<"\n";
	}
}
 

