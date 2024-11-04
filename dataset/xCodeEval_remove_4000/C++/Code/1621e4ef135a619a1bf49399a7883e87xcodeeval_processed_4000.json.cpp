




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
























































map<ll, ll> ma;
ll ans[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	

	ll n;
	cin >> n;
	ll x;
	

	for(ll i = 0; i < ll(n)*ll(n); i++)
	{
		cin >> x;
		ma[-1*x]++;
		

	}
	map<ll, ll>::iterator it;
	for(int i = n - 1; i >= 0; i--)
	{
		for(it = ma.begin(); it != ma.end(); ++it)
		{
			x = it->first;
			if(it->second > 0) break;
		}
		

		ma[x]--;
		ans[i] = -1*x;
		for(int j = n - 1; j > i; j--)
		{
			ma[-1*gcd(ans[j], ans[i])] -= 2;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}


