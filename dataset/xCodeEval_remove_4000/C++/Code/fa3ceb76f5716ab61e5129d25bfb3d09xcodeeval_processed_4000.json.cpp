  
 

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



void solve()
{
	ll n; cin >> n;
	vector<ll> a(2*n);
	for(auto &i : a) cin >> i;
	sort(a.begin(),a.end());
	if(n < 2 and a[0] != a[1]) {
		cout << "NO\n";
		return;
	}
	bool sets = false, sama = false;
	for(int i = 0; i < 2*n; i+=2) {
		if(i != 0 and a[i] == a[i-1]) {
			sama = true;
			break;
		}
		if(a[i] != a[i+1]) {
			sets = true;
			break;
		}
	}
	if(sets or sama) {
		cout << "NO\n";
		return;
	}
	ll pre = 0;
	ll cnt = 0;
	for(int i = n*2-1; i >= 0; i-=2) {
		if((a[i]-2*pre) % ((ll)2*(n-cnt)) != (ll)0) {
			cout << "NO\n";
			return;
		}
		ll cur = (a[i]-2*pre)/(2*(n-cnt));
		if(cur <= 0) {
			cout << "NO\n";
			return;
		}
		pre += cur;
		++cnt;
	}
	cout << "YES\n";
}

int main()
{
	int t; cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
