#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define f first
#define s second
#define  all(d) d.begin(),d.end()
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
int n,d,m,q, a[maxn + 3];
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

int main()
{
	IOS;
	cin >> n >> q;
	for (int i=1 ; i <= n ;++i) cin >> a[i];
	vector<int> get_last_bit(20,n+1);
	vector<vector<int>> next_reach(n+2,get_last_bit);
	for (int i = n -1 ; i >= 1; i--)
	{
		for (int j=1 ; j <= 19;++j)
		{
			if (a[i] >> (j-1) & 1)
			{
				for (int k = 1 ; k <= 19 ;++k) 
				{
					next_reach[i][k] = min(next_reach[i][k],next_reach[get_last_bit[j]][k]);
				}
				next_reach[i][j] = i;
				get_last_bit[j] = i;
			}
		}
	}
	while (q--)
	{
		int u,v;
		cin >> u >> v;
		bool flag = false;
		for (int i=1 ; i <= 19;++i)
		{
			if (a[v] >> (i-1) & 1 && next_reach[u][i] <= v) 
			{
				flag = true;
				break;
			}
		}
		if (flag) cout << "Shi\n";
		else cout << "Fou\n";
	}
}


