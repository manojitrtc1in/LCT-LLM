





using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n, a[1000000];
long long ans = 0;
ordered_set sl, sr;

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        sr.insert(a[i]);
    }
    for(int i = 0;i < n;i++) {
        sr.erase(a[i]);
        ans += 1LL * sr.order_of_key(a[i]) * (sl.size() - sl.order_of_key(a[i]));
        sl.insert(a[i]);
    }
    printf("%I64d", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
