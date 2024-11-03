#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define f first
#define s second
#define  all(d) d.begin(),d.end()
typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=2e5;
const int MOD=1e9+7;
int n,q,m,a[maxn+3];
ld dem[maxn+3];
ll h,d[maxn+3];
int k,res =0;
int b[maxn+3];

ll dp[maxn+5][3],f[maxn+3],bd = 0;
string  s1;
bool kt[maxn + 3];
map<int,int> ma;
vector<pair<int,int>> edge[maxn+3],chot;
template<typename T>
void answer(T x) {cout << x;exit(0);}

int main()
{
	IOS;
	cin >> h >> n;
	for (int i=1 ; i <= n ;++i) {
		cin >> d[i];
		f[i] = f[i-1] + d[i];
		if (h + f[i] <= 0 ) answer(i);
	}
	if (f[n] >=0 ) answer("-1");
	ll chot = *min_element(f+1,f+n+1);
	f[n] = abs(f[n]);
	ll ans = (h + chot + f[n] - 1) / f[n];
	h -= ans*f[n];
	ans *= (ll)n;
	for (int j=1 ; j <= 100; ++j)
	for (int i=1 ; i <= n ;++i)
	{
		h += d[i];ans ++;
		if (h <= 0) answer(ans);
	}
	answer("-1");
}

