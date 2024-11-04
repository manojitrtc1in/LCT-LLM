




using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int n;
ll a[50000], s = 0, ans = 0;

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%I64d", &a[i]);
        s += a[i];
    }
    s /= n;
    for(int i = 0;i < n - 1;i++) {
        if(a[i] > s) {
            a[i + 1] += (a[i] - s);
            ans += (a[i] - s);
            a[i] = s;
        } else {
            ll need = s - a[i];
            ans += need;
            a[i + 1] -= need;
        }
    }
    printf("%I64d", ans);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
