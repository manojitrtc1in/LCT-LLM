
















using namespace std;


typedef long long ll;
typedef long double lb;










const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;














































































































ll n, m, k, l, r, cnt, sum, flag, mid, ans, x, y;
ll arr[N], brr[N], crr[N], vis[N];
char s[N], ss[N];

void init() {
    mid = 0;
    rep(i, 2, 45000) {
        if (vis[i] == 0) {
            mid++;
            arr[mid] = i;
        }
        for (int j = 2 * i; j <= 45000; j += i)
            vis[j] = i;
    }
}

void solve() {
    cin >> n >> m >> k;
    ans = __gcd(n, m);
    if (k == 1) {
        if (ans == min(n, m) && n != m)
            put("YES") else put("NO") return;
    }
    if ((k / 2) > 32) {
        put("NO") return;
    }
    n = n / ans;
    m = m / ans;
    cnt = 0;
    x = 1;
    l = sqrt(ans);
    while (ans >= arr[x]) {
        if (ans % arr[x] == 0) {
            ans /= arr[x];
            cnt++;
        } else
            x++;
        if (x > mid)
            break;
    }
    if (ans != 1) {
        cnt++;
        ans = 1;
    }
    int cnt1 = 0, cnt2 = 0;
    l = sqrt(n);
    x = 1;
    while (n >= arr[x]) {
        if (n % arr[x] == 0) {
            n /= arr[x];
            cnt1++;
        } else
            x++;
        if (x > mid)
            break;
    }
    if (n != 1)
        cnt1++;
    l = sqrt(m);
    x = 1;
    while (m >= arr[x]) {
        if (m % arr[x] == 0) {
            m /= arr[x];
            cnt2++;
        } else
            x++;
        if (x > mid)
            break;
    }
    if (m != 1)
        cnt2++;
    sum = cnt * 2 + cnt1 + cnt2;
    if (k > sum)
        put("NO") else put("YES")
}

int main() {
    IOS
        

        

        int T = 1;
    init();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



































































































































































