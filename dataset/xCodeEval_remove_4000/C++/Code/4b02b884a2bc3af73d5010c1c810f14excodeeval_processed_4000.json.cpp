





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
const int N = 3e5 + 3;
const int mod=998244353;
int n,m,q;
int dem[N],id[N],chot[N],a[N];
int k,h,r;
ll t[N + 3];
int dp[N];
string  s;
bool kt[N];
map<pair<int,int>,int> maps;
vector<pair<int,int>> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

pair<int,int> in[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	t[0] = 1;
	for (int i = 1;i <= n;++i) t[i] = t[i-1] * i % mod;
	for (int i = 1;i <= n;++i) cin >> in[i].first >> in[i].second;
	sort(in + 1,in + n + 1);
	ll ans = 1;
	for (int i = 1;i <= n;++i)
	{
		int j = i + 1;
		while  (j <= n && in[i].first == in[j].first) ++j;
		ans = (ans * t[j - i]) % mod;
		i = j-1;
	}
	sort(in + 1,in + n + 1,[](pair<int,int> a,pair<int,int> b)
	{
		return a.second != b.second ? a.second < b.second : a.first < b.first;
	});
	ll ans1 = 1;
	for (int i = 1;i <= n;++i)
	{
		int j = i + 1;
		while  (j <= n && in[i].second == in[j].second) ++j;
		ans1 = (ans1 * t[j - i]) % mod;
		i = j-1;
	}
	sort(in + 1,in + n + 1);
	ll ans2 = 1;
	for (int i = 1;i < n;++i)
	{
		if (in[i].first <= in[i + 1].first && in[i].second <= in[i + 1].second) ;
		else ans2 =0;
	}
	for (int i = 1;i <= n;++i) maps[in[i]]++;
	for (auto&x : maps) ans2 = (ans2 * t[x.second]) % mod;
	ans = (ans + ans1 - ans2 + 1ll  * mod * mod) % mod;
	cout << (t[n] - ans + mod) % mod;
}


