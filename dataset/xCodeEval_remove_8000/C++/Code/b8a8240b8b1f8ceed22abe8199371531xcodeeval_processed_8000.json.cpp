




using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int mx() {return INT_MIN;}
template<typename... Args> int mx(int parameter, Args... args) {return max(parameter, mx(args...));}

ll n, m, dx, dy;

void slv(const ll &a, ll &x, const ll &b, ll &y) {
    if(a == 1 && b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    slv(b, x1, a % b, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

void inv(const ll &a, ll &x, const ll &b) {
    ll y;
    slv(a, x, n, y);
    x = (x * b) % n;
}

void solve() {
    scanf("%I64d %I64d %I64d %I64d", &n, &m, &dx, &dy);
    map<ll, int> cnt;
    map<ll, ii> eg;
    for(int i = 0;i < m;i++) {
        int x, y;
        ll k, z;
        scanf("%d %d", &x, &y);
        if(y == 0)
            z = x;
        else {
            inv(dy, k, y);
            z = ((x - dx * k) % n + n) % n;
        }
        cnt[z]++;
        eg[z] = {x, y};
    }
    ll ans = -1;
    for(const pair<ll, int> &x : cnt) {
        if(ans == -1 || x.Y > cnt[ans])
            ans = x.X;
    }
    printf("%d %d", eg[ans].X, eg[ans].Y);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
