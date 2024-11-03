






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
const int maxn= 1e6 + 3;
const int N = 2e5 + 3;
const int mod=1e9 + 7;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
int k,h;
ll t[N + 3];
int dp[N];
string  s;
bool kt[N];
map<pair<int,int>,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}
 
int base = 777;
 
int main()
{
	IOS;
	cin >> n >> k;
	for (int i = 1;i <= k;++i) {
		int r,c;
		cin >> r >> c;
		edge[n-c+1].emplace_back(n-r+1);
	}
	vector<vector<int>> f(2,vector<int>(base+1));
	f[1][0] = 0;
	

	int counter = 0;
	for (int i = 1;i <= n;++i) {
		sort(all(edge[i]));
		int fix = 0;
		counter += (int)edge[i].size();
		dp[i] = dp[i-1] + 3 * (int)edge[i].size();
		

		for (int j = 1;j <= min(base,i);++j) {
			while (fix < (int)edge[i].size() && edge[i][fix] <= j) fix++;
			

			f[0][j] = min(dp[i-1],f[1][j-1]) + ((int)edge[i].size() - fix) * 3;
			

			dp[i] = min(dp[i],j * (j+1) / 2 + 2 + f[0][j]);
			
		}
		f[0][0] = dp[i];
		
		swap(f[0],f[1]);
	}
	cout << dp[n];
}
 

