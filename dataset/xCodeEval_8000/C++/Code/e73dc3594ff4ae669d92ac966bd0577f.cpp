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
const int maxn=2e5;
const int mod=1e9+7;
int n,q,d,m,a[maxn+3],b[maxn+3];
int dem[maxn+3],id[maxn+3];
int k,h;
int res = 2e9;
ll dp[maxn+5],t[maxn+3];
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
	read(n);
	for (int i=1; i <= n ;++i) read(h),a[h]++;
	b[0 ] = 0;
	for (int i=1; i <= maxn + 2;++i) b[i] += b[i-1] + a[i];
	int chot = 1,ans = 0,l,r;
	for (int i=1 ; i <= maxn ;++i)
	{
		if (a[i] == 0)continue;
		chot = max(chot,i+1);
		while (chot <= maxn && a[chot] >= 2) chot ++;
		if (ans <= b[chot] - b[i-1]) 
		{
			ans = b[chot] - b[i-1];
			l = i;r = chot;
		}
	}
	cout << ans << "\n" ;
	for (int i=l ; i <= r ;++i)
	{
		if (a[i] > 0) cout << i <<' ',a[i]--;
	}
	for (int i=r ; i >= l ;--i)
	{
		while (a[i]-->0) cout << i <<" " ;
	}
}


