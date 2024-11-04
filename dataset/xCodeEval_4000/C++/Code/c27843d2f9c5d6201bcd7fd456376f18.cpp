  
 
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
	vi a(n); for(auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	int mini = iinf; pi af;
	for(int i = 0; i < n-1; ++i) {
		if(mini > a[i+1]-a[i]) {
			mini = a[i+1]-a[i];
			af = {i, i+1};
		}
	}
	cout << a[af.first] << " "; for(int i = af.second+1; i < n; ++i) cout << a[i] << " ";
	for(int i = 0; i < af.first; ++i) cout << a[i] << " "; 
	cout << a[af.second];
	cout << "\n";
	
	
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();
	return 0;
}
