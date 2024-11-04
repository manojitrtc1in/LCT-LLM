#include "bits/stdc++.h"

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)

const int N=1e6+6;
bool sieve[N];
void buildSieve(){
	memset(sieve, true, sizeof(sieve));
	sieve[1] = false;
    for (int p = 2; p * p <= N; p++){
        if (sieve[p] == true){
            for (int i = p * p; i <= N; i += p)
                sieve[i] = false;
        }
    }
}

void solve(){
	int t;
	buildSieve();
	cin >> t;
	while(t--){
		int n, e;
		cin >> n >> e;
		vi arr(n);
		For(i, n)
			cin >> arr[i];
		if(e >= n){
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		For(i, n){
			ll l=0, r = 0;
			if(sieve[arr[i]]){
				int j=i+e;
				while(j < n && arr[j] == 1){
					j += e;
					r++;
				}
				j = i-e;
				while(j >= 0 && arr[j] == 1){
					j -= e;
					l++;
				}
				ans += (l+r + l*r);
			}
		}
		cout << ans << endl;
	}
}

int main(){
	fastio;
	

	solve();
	return 0;
}
