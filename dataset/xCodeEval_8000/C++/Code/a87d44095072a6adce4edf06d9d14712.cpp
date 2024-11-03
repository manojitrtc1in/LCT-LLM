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
const int maxn= 1e6 + 3;
const int N = 3e5 + 3;
const int mod= 998244353;
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

void add(int&a,int b)
{
	a += b;
	if (a >= mod) a -= mod;
}

int mul(int a,int b)
{
	return 1ll * a * b % mod;
}

int inverse(int a)
{
	int b = mod,u = 0,v = 1;
	while (a) {
		int t = b / a;
		b -= a * t;swap(a,b);
		u -= v * t;swap(u,v);
	}
	assert(b == 1);
	if (u < 0) u += mod;
	return u;
}

int pow(int a,int b)
{
	if (!b) return 1;
	int tong = pow(a,b>>1);
	tong = mul(tong,tong);
	if (b&1) return mul(tong,a);
	return tong;
}

int main()
{
	IOS;
	vector<int> f(2e5+1),rev(2e5+1);
	f[0] = 1;
	for (int i = 1;i <= (int)2e5;++i) f[i] = mul(f[i-1],i);
	rev[(int)2e5] = inverse(f[(int)2e5]);
	for (int i = (int)2e5 - 1;i >= 0;--i) rev[i] = mul(rev[i+1],i+1);
	cin >> n >> k;
	for (int i = 1;i <= n;++i) cin >> a[i];
	int cnt =0 ;
	for (int i = 1;i <= n;++i) cnt += a[i] == a[i % n + 1];
	int ans = 0;
	int remain = n - cnt;
	auto C = [&](int k,int n) {return mul(f[n],mul(rev[k],rev[n-k]));};
	for (int i =1;i <= remain;++i) {
		int now = 0;
		for (int j = 0;j * 2 <= remain - i;++j) {
			int dem = remain - i - 2 * j;
			

			add(ans,mul(pow(k-2,dem),mul(C(j,remain),C(i+j,remain-j))));
		}
	}
	ans = mul(ans,pow(k,cnt));
	cout << ans;
}
 

