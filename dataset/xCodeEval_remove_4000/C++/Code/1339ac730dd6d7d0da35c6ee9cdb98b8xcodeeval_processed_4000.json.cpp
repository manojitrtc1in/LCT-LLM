
 










using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 2e5 + 5;

int n, m, _, k;
int h[N], ne[N], a[N], c[N];
bool v[N];

void add(int x, int k) {
    for (; x <= n; x += -x & x) umin(c[x], k);
}

int ask(int x) {
    int ans = n;
    for (; x; x -= -x & x) umin(ans, c[x]);
    return ans;
}

int main() {
    IOS; cin >> n;
    rep (i, 1, n) cin >> a[i], ne[i] = h[a[i]], h[a[i]] = i, c[i] = n;
    rep (i, 1, n) add(i, h[i]);
    rep (i, 2, n + 1) if (ask(i - 1) > h[i]) v[i] = 1;
    per (i, n, 1) {
        add(a[i], ne[i]);
        if (a[i] - 1 && ask(a[i] - 1) > ne[i]) v[a[i]] = 1;
        if (a[i] - 1) v[1] = 1;
    }
    int ans = 0; while (v[++ans]); cout << ans;
    return 0;
}