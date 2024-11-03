






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
const int N = 3e5 + 3;
const int mod=1e9 + 7 ;
int n,m,q;
int dem[N],id[N],chot[N],a[N],b[N];
int k,h;
ll t[N + 3];
string  s;
bool kt[N];
map<int,int> maps;
vector<int> edge[N];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

int main()
{
	IOS;
	cin >> n >> m;
	vector<vector<int>> a(n+1,vector<int>(m+1,0)),fix = a;
	for (int i = 1;i <= n;++i) {
		cin >> s;
		for (int j = 1;j <= m;++j) {
			fix[i][j] = (s[j-1] == 'X');
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + (s[j-1] == 'X');
		}
	}
	auto id0 = [&](int x1,int y1,int x2,int y2) {
		--x1;--y1;
		int val = a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1];
		return (val == (x2 - x1) * (y2 - y1));
	};
	vector<pair<int,int>> res;
	vector<vector<int>> sum(n + 2,vector<int>(m + 2));
	auto check = [&](int limit,int can)
	{
		for (int i = 0;i <= n+1;++i) {
			for (int j = 0;j <= m+1;++j) sum[i][j] = 0;
		}
		for (int i = limit + 1;i <= n - limit;++i) {
			for (int j = limit + 1;j <= m - limit;++j) {
				int now = 1;
				now &= id0(i-limit,j-limit,i,j) ;
				now &= id0(i-limit,j,i,j+limit);
				now &= id0(i,j-limit,i+limit,j);
				now &= id0(i,j,i+limit,j+limit);
				if (now) {
					if (can) res.emplace_back(i,j);
					sum[i-limit][j-limit]++;
					sum[i-limit][j + limit + 1]--;
					sum[i + limit + 1][j-limit]--;
					sum[i+limit+1][j+limit+1]++;
				}
			}
		}
		for (int i = 0;i <= n;++i) {
			for (int j = 0;j <= m;++j) {
				if (i)sum[i][j] += sum[i-1][j];
			}
		}
		int cnt = 0;
		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= m;++j) {
				

				sum[i][j] += sum[i][j-1];
				if ((sum[i][j] > 0) == fix[i][j]) ++cnt;
			}
		}	
		return cnt == n * m;
	};
	int l = 1,r = min(m,n);
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid,0)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r <<"\n";
	assert(check(r,1));
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) sum[i][j] = 0;
	}
	for (auto&x : res) sum[x.first][x.second] = 1;
	for (int i =1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			if (sum[i][j] ) cout << "X";else cout << ".";
		}
		cout <<"\n";
	}
}
 

