#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define fi first
#define se second
#define  all(d) d.begin(),d.end()
#define allr(d) d.rbegin(),d.rend()
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
const int maxn= 2e5 + 3 ;
const int N = 2e5 + 3;
const int mod=998244353;
int n,m,q;
int dem[N],id[N],chot[N],a[N];
int k,h,r;
ll t[maxn + 3];
int dp[103][103][103];
string  s;
bool kt[N];
map<int,int> maps;
vector<pair<int,int>> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}
 
int main()
{
	IOS;
	cin >> n >> r;
	clock_t be = clock();
	vector<pair<int,int>> add,sub;
	for (int i = 1;i <= n;++i)
	{
		int x,y;
		cin >> x >> y;
		if (y >= 0) add.emplace_back(make_pair(x,y));
		else sub.emplace_back(make_pair(x,y));
	}
	sort(all(add));
	int ans = 0;
	for (auto&x : add)
	{
		if (r >= x.first) r += x.second,ans++;else answer("NO");
	}
	n = sub.size();
	sort(all(sub),[](pair<int,int> a,pair<int,int> b)
	{
		return a.first + a.second > b.first + b.second;
	});
	for (auto & x : sub)
	{
		if (r < x.first || r + x.second < 0) answer("NO");
		r += x.second;
	}
	cout << "YES\n";
}
 

