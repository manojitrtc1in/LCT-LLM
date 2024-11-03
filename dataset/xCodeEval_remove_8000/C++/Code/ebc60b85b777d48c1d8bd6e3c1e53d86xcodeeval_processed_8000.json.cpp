




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
const int N = 2e5 + 3;
const int mod=998244353;
int n,m,q;
int dem[maxn+3],id[maxn+3],chot[maxn+3],a[maxn + 3];
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

int u[N],v[N],w[N];
priority_queue<pair<ll,int>> pq;

bool relax(int u,int v,int w)
{
	if (dp[v] >= dp[u] + w)
	{
		dp[v] = dp[u] + w;
		return true;
	}
	return false;
}
vector<ll> ans;
set<int> in;
void dijks(int u)
{
	for (auto&x : in) 
	{
		kt[x] = false;
		dp[x] = 1e18;
	}
	dp[u] = 0;
	int save = u;
	while (!pq.empty()) pq.pop();
	pq.push({dp[u],u});
	while (!pq.empty())
	{
		 u = pq.top().second;pq.pop();
		if (kt[u]) continue;
		kt[u] = true;
		if (dp[u] > 0 && save< u) ans.push_back(dp[u]);
		for (auto&v : edge[u])
		{
			if (relax(u,v.first,v.second))
			{
				pq.push({-dp[v.first],v.first});
			}
		}
	}
}

int main()
{
	IOS;
	cin >> n >> m >> k;
	vector<pair<int,pair<int,int>>> _e;
	for (int i = 1;i <= m;++i)
	{
		cin >> u[i] >> v[i] >> w[i];
		_e.push_back({w[i],{u[i],v[i]}});
	}
	sort(all(_e));
	for (int i = 0 ;i < min(k,(int)_e.size());++i)
	 {
	 	int u = _e[i].second.first;
	 	int v = _e[i].second.second;
	 	int w = _e[i].first;
	 	in.insert(u),in.insert(v);
	 	edge[u].push_back({v,w});
	 	edge[v].push_back({u,w});
	 }
	for (auto&x:in) dijks(x);
	sort(all(ans));
	cout << ans[k-1];
}


