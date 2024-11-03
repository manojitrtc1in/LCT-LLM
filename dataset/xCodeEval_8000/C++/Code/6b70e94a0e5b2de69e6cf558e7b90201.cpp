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
const int maxn= 1 << 21 ;
const int N = 2e5 + 3;
const int mod=1e9 + 7;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
int k,h;
ll t[N + 3];
ll dp[N];
string  s;
bool kt[N];
map<pair<int,int>,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

int main()
{
	IOS;
	cin >> n >> m >> k;
	if (1ll * m * n == k + 1) return cout << "Yes",0;
	vector<vector<int>> col(m + 1,{0}),row(n + 1,{0});
	for (int i = 1;i <= k;++i) {
		int u,v;
		cin >> u >> v;
		col[v].emplace_back(u);
		row[u].emplace_back(v);
	}
	clock_t be = clock(),ed;
	for (int i = 1;i <= m;++i) sort(all(col[i])),col[i].emplace_back(n+1);
	for (int i = 1;i <= n;++i) sort(all(row[i])),row[i].emplace_back(m+1);
	int x = 1,y = 1;
	long long ans = 1;
	int id = 1;
	vector<int> oo = {m+1,n+1,0,1};
	while (1) {
		pair<int,int> pre = {x,y};
		if (id == 1) {
			int last = *upper_bound(all(row[x]),y) - 1;
			y = min(last,oo[0]-1);
			oo[0] = y;
			id = 2;
		}else if (id == 2) {
			int last = *upper_bound(all(col[y]),x) - 1; 
			x = min(last,oo[1]-1);
			oo[1] = x;
			id = 3;
		}else if (id == 3) {
			int last = *(--upper_bound(all(row[x]),y)) + 1;
			y = max(last,oo[2]+1);
			oo[2] = y;
			id = 4;
		}else {
			int last = *(--upper_bound(all(col[y]),x)) + 1;
			x = max(last,oo[3]+1);
			oo[3] = x;
			id = 1;
		}
		if (make_pair(x,y) == pre && make_pair(x,y) != make_pair(1,1)) break;
		ans += abs(pre.first - x) + abs(pre.second  - y);
	}
	if (ans >= 1ll * n * m - k) cout << "Yes";else cout << "No";
}


