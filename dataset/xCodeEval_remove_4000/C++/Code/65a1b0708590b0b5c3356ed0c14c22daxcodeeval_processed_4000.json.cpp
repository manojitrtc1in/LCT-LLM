

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
	vll a(n);
	for (auto& x : a)cin >> x;
	int m;cin >> m;
	ll sum = 0;
	while (m--) {
		int x;cin >> x;
		sum += x;
	}
	cout << a[sum % n] << nl;

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
