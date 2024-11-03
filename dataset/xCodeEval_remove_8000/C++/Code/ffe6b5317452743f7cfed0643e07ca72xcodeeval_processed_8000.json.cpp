




using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);












typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}







































































ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    

            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}


vii vec;
ll dp[201000];
ll fact[201000];
ll invfact[201000];

ll choose(ll n, ll r)
{
	ll res = 0;
	res = ((fact[n] * invfact[r])%MOD * invfact[n - r])%MOD;
	if(res < 0) res += MOD;
	return res;
}

bool comp(ii a, ii b)
{
	if(a.fi + a.se != b.fi + b.se) return a.fi + a.se < b.fi + b.se;
	else return a.fi < b.fi;
}

int main()
{
	

	

	fact[0] = 1;
	for (ll i = 1; i < 200010; ++i) 
	{
		fact[i] = (fact[i - 1] * i)%MOD;
		if(fact[i] < 0) fact[i] += MOD;
	}
	invfact[200009] = power(fact[200009], MOD - 2);
	for (ll i = 200008; i >= 0; --i) 
	{
		invfact[i] = (invfact[i + 1] * (i + 1))%MOD;
		if(invfact[i] < 0) invfact[i] += MOD;
	}
	int h, w, n;
	

	scanf("%d %d %d", &h, &w, &n);
	int x, y;
	vec.pb(ii(0, 0));
	vec.pb(ii(h-1, w-1));
	for(int i = 0; i < n; i++)
	{
		

		scanf("%d %d", &x, &y);
		x--; y--;
		vec.pb(ii(x, y));
	}
	sort(vec.begin(), vec.end(), comp);
	dp[0] = 1;
	ll c, d;
	for(int i = 1; i < vec.size(); i++)
	{
		dp[i] = 0;
		c = vec[i].fi - vec[0].fi;
		d = vec[i].se - vec[0].se;
		if(c >= 0 && d >= 0)
		{
			dp[i] = choose(c + d, c);
		}
		for(int j = 1; j < i; j++)
		{
			c = vec[i].fi - vec[j].fi;
			d = vec[i].se - vec[j].se;
			if(c >= 0 && d >= 0)
			{
				dp[i] -= dp[j] * choose(c + d, c);
			}
			dp[i] %= MOD;
		}
		dp[i] %= MOD;
	}
	if(dp[vec.size() - 1] < 0) dp[vec.size() - 1] += MOD;
	

	printf("%I64d", dp[vec.size() - 1]);
	return 0;
}




