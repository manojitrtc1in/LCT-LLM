





















































































































using namespace std;


typedef long long ll;
typedef long double lb;









const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;





































































ll n, m, k, l, r, cnt, sum, flag, mid, ans;
ll arr[N], brr[N], vis[N], dp[N];
string s;

void cf() {
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i];
        dp[i] = 0;
    }
    dp[0] = 0;
    ans = 0;
    rep(i, 1, n) {
        dp[i] = max(dp[i], arr[i]);
        ans = max(ans, dp[i]);
        if (i + arr[i] <= n) dp[i + arr[i]] = max(dp[i + arr[i]], dp[i] + arr[i + arr[i]]);
    }
    put(ans)
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
 					  	       		 	 			  	   	