



using namespace std;

int n, m, d, a[100000];

int f(const int &x) {
    int r = 0;
    for(int i = 0;i < n * m;i++)
        r += abs(a[i] - x) / d;
    return r;
}

void solve() {
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0;i < n * m;i++)
        scanf("%d", &a[i]);
    for(int i = 1;i < n * m;i++)
        if(abs(a[i] - a[0]) % d != 0) {
            printf("-1");
            return;
        }
    int l = 1, r = 10000, m1, m2;
    for(int _ = 0;_ < 100;_++) {
        m1 = l + (r - l) /3;
        m2 = r - (r - l) / 3;
        if(f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }
    printf("%d", min({f(l), f(l + d)}));
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
