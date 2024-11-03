#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define f first
#define s second
#define  all(d) d.begin(),d.end()
typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=1003;
const int MOD=998244353;
ll n,q,d,m,a[maxn+3];
ld dem[maxn+3];
int k,res =0,l[1030],r[103];
int b[maxn+3],ans[maxn+3];

ll dp[103][103][103],bd = 0;
string  s,t;
bool kt[maxn + 3];
map<int,int> ma;
vector<int> edge[maxn+3],chot;
template<typename T>
void answer(T x) {cout << x;exit(0);}

ll solve(int l,int r,int k)
{
	ll& ans = dp[l][r][k];
	if (l >= r ) return 0;
	if (ans != 0) return ans;
	ans = a[k] + solve(l+1,r,1);
	for (int i= l +1 ; i < r; i++)
	{
	
		if (s[i] == s[l]) ans= max(ans , solve(l+1,i,1) + solve(i,r,k+1));
	}
	return ans;
}

int main()
{
	IOS;
	cin >> n >> s;
	for (int i=1 ; i <= n;++i) cin >> a[i];
	cout << solve(0,n,1);
}

