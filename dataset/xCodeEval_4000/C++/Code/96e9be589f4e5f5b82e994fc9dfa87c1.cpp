














#include <bits/stdc++.h>

using namespace std;




typedef long long ll;
typedef long double lb;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, n) for (ll i = a; i <= n; i++)
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
ll arr[N], brr[N], crr[N], vis[N];

void solve() {
	flag = 0;
    cin >> n;
    if(n%2 == 0){
    	cnt = 0;
    	while(n%2 == 0){
    		n/=2;
    		cnt++;
    	}
    	if((n == 1 && cnt % 2 == 1)) put("Bob")
    	else put("Alice")
    } else put("Bob")
}

int main() {
    IOS
        

        

        int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


































































































































































