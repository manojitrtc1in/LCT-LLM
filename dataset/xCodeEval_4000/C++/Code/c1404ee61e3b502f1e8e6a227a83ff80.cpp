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
const int maxn=3e5;
const int mod=1e9+7;
int n,q,d,m,a[maxn+3],b[maxn+3];
int dem[maxn+3],id[maxn+3];
int k,h;
ll res = 1e18;
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
	cin >> n >> s;
	set<int> v[2];
	int move = n-11;
	int m1 = move/2,m2 = m1;
	for (int i=0 ; i < n;++i)
	{
		if (s[i] == '8') 
		{
			if (m1) m1 --,s[i] = 'O';
		}else
		{
			if (m2) m2--,s[i] = 'O'; 
		}
	}
	for (int i= 0 ; i < n;++i)
	{
		if (s[i] == 'O') continue;
		if (s[i] == '8') answer("YES");else answer("NO");
	}
	int id = 1;
	while (move--)
	{
		if (v[id].empty()) 
		{
			if (id == 1) cout << "NO";else cout <<"YES";
			return 0;
		}
		v[id].erase(v[id].begin());
		id^=1;
	}
	if (v[1].empty()) cout << "NO";else if (v[0].empty()) cout <<"YES";else
	if (*v[1].begin() > *v[0].begin()) cout << "NO";else cout << "YES";
}


