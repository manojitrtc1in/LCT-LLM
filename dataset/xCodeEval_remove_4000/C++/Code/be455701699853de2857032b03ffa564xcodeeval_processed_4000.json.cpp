  
 

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
 
const ll linf = id0;
const int iinf = INT_MAX;
const ll mod = 1000000007;
const ll mod2 = 998244353;



void solve()
{
	int n; cin >> n;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	ll pref = 0;
	ll ans = 0;
	for(int i = 1; i < n; ++i) {
		ans += pref-a[i]*i;
		pref += a[i];
	}
	cout << ans + a[n-1] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
		solve();
	}
	return 0;
}
