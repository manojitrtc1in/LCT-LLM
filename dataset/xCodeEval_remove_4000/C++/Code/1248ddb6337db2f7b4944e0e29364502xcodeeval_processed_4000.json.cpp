





















































































































using namespace std;


typedef long long ll;
typedef long double lb;









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
		  	 					 	 	   			   	  	  	