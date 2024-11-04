  
 
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
	vi a(n);
	bool ada = false;
	int maks = -iinf;
	for(auto &i : a) {
		cin >> i;
		maks = max(maks, i);
		if(i < 0) {
			ada = true;
		}
	}
	if(ada) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << maks+1 << "\n";
	for(int i = 0; i <= maks; ++i) {
		cout << i << " ";
	}
	cout << "\n";
	
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
