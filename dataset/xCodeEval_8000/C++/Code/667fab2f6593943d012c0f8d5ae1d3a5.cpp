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
const int maxn= 3e6 + 3;
const int N = 1e6 + 3;
const int mod=1e9 + 7 ;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
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

template<typename T,typename U>
T operator % (T a,U b)
{
	return a - a / b * b;
}

int main()
{
	IOS;
	cin >> n;
	long long t = 0;
	for (int i = 1;i <= n;++i) cin >> a[i],t += a[i];
	ll now = 2;
	ll ans = 1e18;
	auto solve = [&](long long x)
	{
		ll sum = 0;
		ll res = 0;
		for (int i = 1;i <= n;++i) {
			sum = (sum + a[i]) % x;
			res += min(sum,x - sum);
		}	
		ans = min(ans,res);
	};
	while (now * now <= t) {
		if (t % now == 0) {
			while (t % now == 0) t /= now;
			solve(now);
		}
		++now;
	}
	if (t > 1) solve(t);
	if (ans == 1e18) ans = -1;
	cout << ans;
}
 

