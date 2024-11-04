




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
















































int main()
{
	ios_base::sync_with_stdio(false);
	

	ll a;
	cin >> a;
	ll n = ll(1e17);
	n *= 18;
	

	n %= a;
	ll k = n;
	

	for(int i = 0; i < 44; i++)
	{
		n = (n + k)%a;
	}
	

	if(n < 0)
	{
		n += a;
	}
	ll c = a - n; ll d = c + ll(1e18) - 1LL;
	cout << c << " " << d;
	return 0;
}









