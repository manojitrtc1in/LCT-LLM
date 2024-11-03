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
const int N = 1e5 + 3;
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

int GCD[N];
int main()
{
	IOS;
	cin >> n;
	int now = 0;
	vector<pair<int,int>> in(n);
	for (int i = 0;i < n;++i)cin >> in[i].first,in[i].second = i + 1,now= __gcd(now,in[i].first);
	if (now != 1) answer("NO");
	clock_t Start = clock(),End;
	while (true)
	{
		random_shuffle(in.begin(),in.end());
		GCD[0] = 0;
		for (int i = 0;i < n;++i)
		{
			GCD[i] = __gcd(GCD[i-1],in[i].first);
		}
		int now = 0;
		for (int i = 0;i < n;++i)
		{
			if (GCD[i] == GCD[i-1])
			{
				now = __gcd(now,in[i].first);
				dem[in[i].second] = 2;
			}
			else dem[in[i].second ] = 1;
		}
		if (now == 1)
		{
			cout <<"YES\n";
			for (int i = 1;i <= n;++i) cout << dem[i] <<' ';
			return 0;
		}
		End = clock() - Start;
		if (1.0 * End / CLOCKS_PER_SEC > 0.45) break;
	}
	answer("NO");
}


