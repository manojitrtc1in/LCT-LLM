






using namespace std;



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














void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}



















































































int main()
{
	ios_base::sync_with_stdio(false);
	

	ll n, k;
	cin >> n >> k;
	ll m = n/2;
	if(!(k == 0 && n == 1) && (k < m || n == 1) )
	{
		cout << -1;
		return 0;
	}
	else if(n != 1)
	{
		for(int i = 0; i < m - 1; i++)
		{
			cout << 200000050 + 2*i << " " << 200000050 + 2*i + 1 << " ";
		}
		cout << k - m + 1 << " " << 2*(k - m + 1) << " ";
	}
	if(n % 2) cout << 999999999;
	return 0;
}



















