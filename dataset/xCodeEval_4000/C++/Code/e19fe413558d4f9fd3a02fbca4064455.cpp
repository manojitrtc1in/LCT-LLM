  
 
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
	int bef = 0;
	vi a;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if(bef == x) continue;
		bef = x;
		a.pb(x);
	}
	vi dp(a.size(), iinf);
	int ans = 0;
	unordered_map<int, int> pos;
	for(int i = a.size()-1; i >= 0; --i) {
		if(pos[a[i]] == 0) pos[a[i]] = i;
		else {
			dp[i] = pos[a[i]]-i;
			pos[a[i]] = i;
		}
	}
	int at = iinf; int befat = 0;
	int ba = iinf; int befba = 0;
	for(int i = 0; i < (int)a.size(); ++i) {
		if(at != iinf) --at;
		if(ba != iinf) --ba;
		if(a[i] == befat) {
			at = dp[i];
			continue;
		}
		if(a[i] == befba) {
			ba = dp[i];
			continue;
		}
		if(at >= ba) {
			++ans;
			befat = a[i];
			at = dp[i];
		}
		else {
			++ans;
			befba = a[i];
			ba = dp[i];
		}
	}
	cout << ans << "\n";
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1;
    while(t--) {
		solve();
	}
}
