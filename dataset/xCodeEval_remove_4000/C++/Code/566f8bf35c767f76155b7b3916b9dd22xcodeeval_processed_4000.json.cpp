




typedef long long ll;
typedef long double ld;
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
}
using namespace io;
using namespace std;
const int maxn=3e5 ;
const int mod=998244353;
int n,d,m,q,a[maxn + 3],b[maxn+3];
int dem[maxn+3],id[maxn+3],chot[maxn+3];
int k,h;
int res = 2e9;
ll dp[maxn+5], t[maxn+3];
string  s;
bool kt[maxn + 3];
map<int,int> maps;
vector<int> edge[maxn+3];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}

struct Ans
{
	int u,v,w;
};
int p = 0;
Ans ans[5 * maxn + 102];
struct T
{
	int first,second,id;
	bool operator < (const T&other) const
	{
		return first != other.first ? first < other.first : second < other.second;
	}
};
T A[maxn + 3];

int main()
{
	IOS;
	read(n);
	for (int i=1 ; i <= n; ++i) read(A[i].first),A[i].second = i;
	for (int i=1 ; i <= n ;++i) read(b[i]);
	sort(A + 1,A + n + 1);
	sort(b+1,b +n  + 1);
	for (int i=1 ; i <= n;++i) A[i].first -= b[i];
	int last = n;
	ll tong = 0;
	stack<T> have;
	for (int i = 1 ; i <= n; ++i)
	{
		tong += 1ll * A[i].first;
		A[i].id = i;
	}
	if (tong != 0) answer("NO");
	for (int i=1 ; i <= n ;++i)
	{
		int tt = A[i].first;
		if (tt < 0) have.push(A[i]);
		while (tt > 0 && !have.empty())
		{
			T x = have.top();
			have.pop();
			int limit = min(tt,-x.first);
			tt -= limit;
			x.first += limit;
			int e = A[i].second,z = x.second;
			if (A[i].id > x.id) swap(e,z);
			ans[p++] = {e,z,limit};
			if (x.first != 0) have.push(x);		
		}
		if (tt > 0) answer("NO");
	}
	cout << "YES\n" << p <<"\n";
	for (int i=0 ; i < p ;++i) cout << ans[i].u <<' ' << ans[i].v <<' ' << ans[i].w << "\n";
}


