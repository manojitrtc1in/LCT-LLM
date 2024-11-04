  
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
 
const ll linf = LLONG_MAX;
const int iinf = INT_MAX;
const ll mod = 1000000007;
#define pb push_back
#define ar array

 
 
void solve()
{
	int n; cin >> n;
	vi a(n+2);
	a[n+1] = 0; a[0] = 0;
	int maks = 0;
	ll ans = 0;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		int s = min(a[i], max(a[i-1], a[i+1]));
		ans += a[i]-s+abs(a[i-1]-s);
		a[i] = s;
		maks = max(a[i], maks);
	}
	cout << ans+a[n] << "\n";
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	
}
