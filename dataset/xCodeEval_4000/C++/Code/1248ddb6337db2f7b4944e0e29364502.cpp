



















































































































#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
typedef long long ll;
typedef long double lb;
#define IOS ios::sync_with_stdio(false);
#define rep(i, a, n) for(ll i=a;i<=n;i++)

#define X first
#define Y second
#define ms(a, k) memset(a,k,sizeof(a))
#define put(x) cout<< x << "\n";
#define hh " "
#define putt(x, y) cout<< x << " " << y << "\n";
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;





































































ll n, m, k, l, r, cnt, sum, flag, mid, ans;
ll arr[N], brr[N], vis[N], vis1[N];
string s;

void cf() {
    cin >> n >> m >> k;
    rep(i, 1, k) {
        cin >> arr[i];
        vis[arr[i]] = 0;
    }
    rep(i, 1, k) {
        cin >> brr[i];
        vis1[brr[i]] = 0;
    }
    sum = 0;
    rep(i, 1, k) {
        if (!vis[arr[i]]) {
            vis[arr[i]]++;
        } else {
            sum += vis[arr[i]];
            vis[arr[i]]++;
        }
        if (!vis1[brr[i]]) {
            vis1[brr[i]]++;
        } else {
            sum += vis1[brr[i]];
            vis1[brr[i]]++;
        }
    }
    ans = k * (k - 1) / 2;
    put(ans-sum)
}


int main() {
    IOS




    int T = 1;
    cin >> T;
    while (T--) {
        cf();
    }
    return 0;
}
		  	 					 	 	   			   	  	  	