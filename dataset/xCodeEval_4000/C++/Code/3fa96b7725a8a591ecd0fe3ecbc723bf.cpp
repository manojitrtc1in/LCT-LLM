
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin() , x.end()
#define ff first
#define ss second
#define pii pair<int , int>
#define rall(x) x.rbegin() , x.rend()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << " = " << a << endl;
#define files freopen("input.in", "r", stdin);freopen("input.out", "w", stdout); 
#define fff cout << "--------------------------" << endl;


using namespace std;
const int MOD = 1e9 + 7;
const int LOG = 19;
const int INF = 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const int N = 1000 + 5;
 


 
int lcm(int a , int b) {
	return a * b * 1LL / __gcd(a , b);
}
 
int pref[N];
 
void precalc() {
	pref[0] = 1;
	for (int i = 1; i <= 500; i++) {
		pref[i] = lcm(pref[i - 1] , i);
	}
}
 
void solve() {
	int n;
	cin >> n;
	int ans = 0;
	int sum = 0 , prev_val = 0;
	for (int i = 2; i <= 500; i++) {
		if (pref[i - 1] > n) continue;
		if (pref[i] == pref[i - 1]) continue;
		int cnt = n / pref[i - 1];
		ans = (ans - cnt * prev_val * 1LL + 3LL * MOD) % MOD;
		ans = (ans + cnt * i * 1LL % MOD) % MOD;
		prev_val = i;
	}
	cout << ans << endl;
} 
 
signed main() { 
  

  fast
  precalc();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0; 
}
