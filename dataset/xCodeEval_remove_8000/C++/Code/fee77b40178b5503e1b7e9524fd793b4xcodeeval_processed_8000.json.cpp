



using namespace std;

int n, k;
struct Interval {
    int l, r, i;
} a[300000];

void solve() {
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i++) {
        scanf("%d %d", &a[i].l, &a[i].r);
        a[i].i = i;
    }
    sort(a, a + n, [](const Interval &i1, const Interval &i2) {if(i1.l != i2.l) return i1.l < i2.l;return i1.r < i2.r;});
    auto cmp = [](const Interval &i1, const Interval &i2) {if(i1.r == i2.r)return i1.i < i2.i;return i1.r < i2.r;};
    set<Interval, decltype(cmp)> s(cmp);
    for(int i = 0;i < k - 1;i++)
        s.insert(a[i]);
    long long ans = -1;
    int ansi = -1;
    for(int i = k - 1;i < n;i++) {
        long long lb = a[i].l;
        long long rb = (s.empty() ? a[i].r : min(a[i].r, s.begin()->r));
        if(lb <= rb && rb - lb + 1 > ans) {
            ans = rb - lb + 1;
            ansi = i;
        }
        s.insert(a[i]);
        s.erase(s.begin());
    }
    if(ans == -1) {ans = 0;ansi = n - 1;}
    s.clear();
    for(int i = 0;i < k - 1;i++)
        s.insert(a[i]);
    for(int i = k - 1;i <= ansi;i++) {
        s.insert(a[i]);
        if(i < ansi) s.erase(s.begin());
    }
    printf("%I64d\n", ans);
    for(const Interval &e : s)
        printf("%d ", e.i + 1);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
