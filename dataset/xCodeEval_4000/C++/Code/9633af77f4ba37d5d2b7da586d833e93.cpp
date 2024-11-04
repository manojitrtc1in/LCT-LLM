





























#include <bits/stdc++.h>

using namespace std;




typedef long long ll;
typedef long double lb;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define per(i, n, a) for (ll i = n; i >= a; i--)
#define dbg(x) cout << #x << "=" << x << endl;

#define X first
#define Y second
#define ms(a, k) memset(a, k, sizeof(a))
#define put(x) cout << x << endl;
#define hh " "
#define putt(x, y) cout << x << " " << y << endl;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;














































































































ll n, m, k, l, r, cnt, sum, flag, mid, ans, x, y;
ll arr[N], brr[N], crr[N], vis[N], dp[1200][1200];
string s[N];
char a;

void solve() {
    cin >> n >> m;
    rep(i,1,m) arr[i] = 0;
    rep(i,1,n) {
    	rep(j,1,m) {
    		cin >> a;
    		arr[j] += ( a - 'a' );
    	} 
    }
    rep(i,1,n-1){
    	rep(j,1,m) {
    		cin >> a;
    		arr[j] -= ( a - 'a' );
    	}
    }
    rep(i,1,m){
    	a = 'a' + arr[i];
    	cout<<a;
    }
    cout<<endl;
}

int main() {
    

    

    IOS int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



































































































































































