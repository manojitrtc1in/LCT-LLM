




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
	cin >> n >> s;
	for (int i=1 ; i <= 9 ;++i) cin >> dem[i],dem[i] = (dem[i] < i ? -1 : dem[i]);
	for (int i= 0 ;i  < n ;++i)
	{
		int j = i;
		bool flag = false;
		if (dem[s[i] - '0'] == -1) continue;
		while (j < n && dem[s[j] -'0'] != -1) {
			if (!flag) flag = (dem[s[j] -'0'] +'0' > s[j]);
			s[j] = dem[ s[j] -'0']+'0';
			j++;
		}
		if (flag) break;
		i = j-1;
	}
	cout << s;
}


