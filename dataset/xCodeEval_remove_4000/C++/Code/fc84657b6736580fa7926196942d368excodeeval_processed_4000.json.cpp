
















using namespace std;


typedef long long ll;
typedef long double lb;










const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;














































































































ll n, m, k, l, r, cnt, sum, flag, mid, ans, x, y;
ll arr[N];
priority_queue<ll, vector<ll>, greater<ll>> q;

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n) {
    	if(q.empty()){
    		if(arr[i]>=0){
    			q.push(arr[i]);
    			ans+=arr[i];
    		}
    		continue;
    	}
        if (arr[i] >= 0) {
            q.push(arr[i]);
            ans += arr[i];
        } else {
            if (ans + arr[i] >= 0) {
                ans += arr[i];
                q.push(arr[i]);
            } else {
                if (q.top() < arr[i]) {
                    ans -= q.top();
                    ans += arr[i];
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
    }
    put(q.size())
}

int main() {
    

    

    IOS int T = 1;
    

    while (T--) {
        solve();
    }
    return 0;
}



































































































































































