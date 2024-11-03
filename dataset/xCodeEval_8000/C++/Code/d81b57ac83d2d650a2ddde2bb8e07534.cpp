#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define fi first
#define se second
#define For(i,d,c) for (int i=d ; i <= c ;++i)
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
const int maxn = 2e5;
const int MOD = 1e9+7;
int n,m,k,f[maxn+3],y[3];
ll a[maxn+3],tong[maxn+3];
int dem = 0;
ll h,t = 0;
bool kt[1004][1004];
string l,r;
vector<int> chot;
struct T{
	char fi;
	int se,id ;
	bool operator<(const T&x) const
	{
		return fi > x.fi;
	}
};
T d[2][maxn+3];
map<pair<int,int>,int> ma;
template <typename T> void answer(T&X){cout <<X <<"\n";exit(0);}

int main()
{
	IOS;
	cin >> h >> n;
	ll c = 1e18;
	for (int i=1; i <= n ;++i) {
	cin >>a[i];
	t += a[i];
	c = min(c,t);
	if (h + t <= 0 ) answer(i);
	

	}
	if (t >= 0)  answer("-1");
	t = abs(t);
	ll ans = (h + c) / t;
	h -= t * ans;
	ans *= (ll)n;
	for (int j=1 ; j <= 310; ++j)
	for (int i=1 ; i <= n ;++i)
	{
		h += a[i];ans++;
		if (h <= 0 ) answer(ans);
	}
	answer("-1");
}



