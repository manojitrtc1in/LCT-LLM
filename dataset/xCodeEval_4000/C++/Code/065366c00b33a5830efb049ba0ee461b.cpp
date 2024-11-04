



















































































































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
    cin >> n >> m;




    ans = n - m;
    rep(i, 1, 2 * m - 1 - n) cout << i << " ";
    cout << m << " ";
    rep(i,1,ans) cout<<m - i <<" ";
    cout<<endl;
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
			  	  						  	 			  				  	