

using namespace std;

















typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> pll;
const int MOD = (int)1e9 + 7;
const int MX = (int)2e5 + 5;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;

void solve(ll tc) {
	int n;cin >> n;
	map<char, int> mp;
	vector<string> a(2 * n+1);
	for (int i = 0; i < 2 *n+1; i++) {
		cin >> a[i];
		for (auto x : a[i]) {
			mp[x]++;
		}
	}
	for(auto [x,y]:mp){
	    if(y%2)cout<<x<<nl;
	}
}
int main() {
	fast;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << setprecision(10) << fixed;
	ll tc = 1;
	ll i = 1;
	cin >> tc;
	for (i = 1; i <= tc; i++)
		solve(i);
	return (0 - 0);
}
