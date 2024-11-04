  
 
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
	string s; cin >> s;
	int cnt0 = 0;
	for(int i = 0; i < n; ++i) if(s[i] == '0') ++cnt0;
	if(n == 2) {
		cout << "BOB\n";
		return;
	}
	if(cnt0 == 0) cout << "DRAW\n";
	else if(cnt0%2 == 0 or n == 1 or cnt0 == 1) cout << "BOB\n";
	else cout << "ALICE\n";
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
		solve();
	}
}
