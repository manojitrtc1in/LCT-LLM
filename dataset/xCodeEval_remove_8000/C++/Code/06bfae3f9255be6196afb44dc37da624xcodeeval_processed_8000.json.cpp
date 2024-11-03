




typedef long long ll;
typedef long double ld;
namespace io
{
	template<typename T> inline void read(T&a){
		int c = getchar();
		a = 0;
		while(c < '0' || c >'9') c = getchar();
		while (c >='0' && c <='9') a = (a << 1) + (a << 3) + c-48,c = getchar();
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
const int MOD=1e9+7;
int n,q,d,m,a[maxn+3],chot[maxn+3],l[maxn+3],r[maxn+3];
int dem[maxn+3];
int k,h;
ll res = 1e18;
ll dp[maxn+5];
int kt[maxn + 3],id;
map<int,int> maps;
map<int,vector<pair<int,int>>> m1;
vector<int> edge[maxn+3];
map<int,int> ::iterator it;
template<typename T>
void answer(T x) {cout << x;exit(0);}
void putstring(string x,char ch = ' ') {for (char c:x) putchar(c);putchar(ch);}
char str[maxn+3];
void combine(int w)
{
	l[r[w]] = l[w];
	r[l[w]] = r[w];
	str[w] = id + '0';
	kt[a[w]] = 1;
}

int main()
{
	IOS;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		chot[a[i]] = i;
		l[i] = i - 1;
		r[i] = i + 1;
	}
	int mx = n; id = 1;
	while (mx > 0) {
		int p = chot[mx], now = p;
		for (int i = 1; i <= k; i++) {
			now = l[now];
			if (now == 0) break;
			combine(now);
		}
		now = p;
		for (int i = 1; i <= k; i++) {
			now = r[now];
			if (now > n) break;
			combine(now);
		}
		combine(p);
		id = id == 1 ? 2 : 1;
		while (kt[mx]) --mx;
	}
	puts(str + 1);
	return 0;
}




