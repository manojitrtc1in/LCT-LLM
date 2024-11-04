  
 
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
const int mxn = 1e6+1;
int fpri[mxn];
vi prime;
void solve()
{
	int n; cin >> n;
	map<int, int> cnt;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		int con = 1;
		while(x > 1) {
			int ps = fpri[x];
			int cnts = 0;
			while(x % ps == 0) {
				++cnts;
				x/= ps;
			}
			cnts%=2;
			if(cnts) con*= ps;
		}
		cnt[con]++;
	}
	int ans0 = 0;
	for(auto i : cnt) {
		ans0 = max(ans0, i.second);
	}
	map<int, int> temp;
	for(auto i : cnt) {
		if(i.second%2) temp[i.first] = i.second;
		else temp[1] += i.second;
	}
	cnt.swap(temp);
	int ans1 = 0;
	for(auto i : cnt) ans1 = max(ans1, i.second);
	int q; cin >> q;
	while(q--) {
		ll x; cin >> x;
		if(x == 0) cout << ans0 << "\n";
		else cout << ans1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	

	fpri[1] = 1;
	for(int i = 2; i < mxn; ++i) {
		if(fpri[i] == 0) {
			fpri[i] = i;
			prime.pb(i);
		}
		for(auto j : prime) {
			if( j > fpri[i] || i*j >= mxn) break;
			fpri[i*j] = j;
		}
	}
	
	
	int t; cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
