




using namespace std;
namespace io
{
	string read(string& x,char ch = ' ')
	{
		int c = getchar();
		while (c != ch) x += c,c = getchar();
		return x;
	}
	template<typename T> 
	T read(T&a)
	{
		int c = getchar(),sign = 1;
		a = 0;
		while (!(c == '-' ||( c >= '0' && c <= '9'))) c = getchar();
		if (c =='-') sign = -sign,c = getchar();
		while (c >= '0' && c <='9') a = (a << 1) + (a << 3) + c - 48,c = getchar();
		if (sign == -1) a = -a;
		return a;
	}
}
using namespace io;
typedef long long ll;
const int maxn = 5008;
const int MOD = 1e9+7;
int n,k,dp[maxn][maxn];
int a[maxn+3],tong[maxn+3];
int dem = 0;
ll h,t = 0;
bool kt[1004][1004];
string l,r;
vector<int> chot;
map<pair<int,int>,int> m;
template <typename T> void answer(T&X){cout <<X <<"\n";exit(0);}
map<int,map<int,int>> ms;
 
int main()
{
	IOS;
	read(n) ; read(k);
	for (int i=0 ; i < n ;++i) read(a[i]);
	sort(a,a+n);
	a[n] = 2e9;
	for (int i=1 ; i <= k + 1; i ++)
	{
		int r = 0;
		for (int j=0 ; j < n ;++j)
		{
			while (a[j] + 5 >= a[r]) r++;
			if (j != 0) dp[j][i-1] = max(dp[j][i-1],dp[j-1][i-1]);
			dp[r][i] = max(dp[r][i],dp[j][i-1] + r-j);
		}
		dp[n][i-1] = max(dp[n][i-1],dp[n-1][i-1]);
	}
	cout << dp[n][k];
}
 

 
 
