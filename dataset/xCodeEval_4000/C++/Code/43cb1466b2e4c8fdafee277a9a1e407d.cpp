#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0)
#define mst(a,n) memset(a,n,sizeof(a))
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define il inline
#define ll long long 
#define ull unsigned long long 
#define int ll
#define md 1000000007
#define pi 3.14159265358979323
#define INF 0x7fffffffffffffff
#define inf 0x7fffffff
#define MAXN 100005
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll pow_mod(ll x, ll n, ll mod) { ll res = 1; while (n) { if (n & 1)res = res * x % mod; x = x * x % mod; n >>= 1; }return res; }
ll fact_pow(ll n, ll p) { ll res = 0; while (n) { n /= p; res += n; }return res; }
ll mult(ll a, ll b, ll p) { a %= p; b %= p; ll r = 0, v = a; while (b) { if (b & 1) { r += v; if (r > p)r -= p; }v <<= 1; if (v > p)v -= p; b >>= 1; }return r; }
ll quick_pow(ll a, ll b, ll p) { ll r = 1, v = a % p; while (b) { if (b & 1)r = mult(r, v, p); v = mult(v, v, p); b >>= 1; }return r; }
bool CH(ll a, ll n, ll x, ll t) { ll r = quick_pow(a, x, n); ll z = r; for (ll i = 1; i <= t; i++) { r = mult(r, r, n); if (r == 1 && z != 1 && z != n - 1)return true; z = r; }return r != 1; }
bool Miller_Rabin(ll n) { if (n < 2)return false; if (n == 2)return true; if (!(n & 1))return false; ll x = n - 1, t = 0; while (!(x & 1)) { x >>= 1; t++; }srand(time(NULL)); ll o = 8; for (ll i = 0; i < o; i++) { ll a = rand() % (n - 1) + 1; if (CH(a, n, x, t))return false; }return true; }
struct Tree { ll l, r, sum, lazy, maxn, minn; }tree[4 * MAXN];
il void push_up(ll rt) { tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum; tree[rt].maxn = max(tree[rt << 1].maxn, tree[rt << 1 | 1].maxn); tree[rt].minn = min(tree[rt << 1].minn, tree[rt << 1 | 1].minn); }
il void push_down(ll rt, ll length) { if (tree[rt].lazy) { tree[rt << 1].lazy += tree[rt].lazy; tree[rt << 1 | 1].lazy += tree[rt].lazy; tree[rt << 1].sum += (length - (length >> 1)) * tree[rt].lazy; tree[rt << 1 | 1].sum += (length >> 1) * tree[rt].lazy; tree[rt << 1].minn += tree[rt].lazy; tree[rt << 1 | 1].minn += tree[rt].lazy; tree[rt << 1].maxn += tree[rt].lazy; tree[rt << 1 | 1].maxn += tree[rt].lazy; tree[rt].lazy = 0; } }
il void build(ll l, ll r, ll rt, ll* aa) { tree[rt].lazy = 0; tree[rt].l = l; tree[rt].r = r; if (l == r) { tree[rt].sum = aa[l]; tree[rt].minn = tree[rt].sum; tree[rt].maxn = tree[rt].sum; return; }ll mid = (l + r) >> 1; build(l, mid, rt << 1, aa); build(mid + 1, r, rt << 1 | 1, aa); push_up(rt); }
il void update_range(ll L, ll R, ll key, ll rt) { if (tree[rt].r<L || tree[rt].l>R)return; if (L <= tree[rt].l && R >= tree[rt].r) { tree[rt].sum += (tree[rt].r - tree[rt].l + 1) * key; tree[rt].minn += key; tree[rt].maxn += key; tree[rt].lazy += key; return; }push_down(rt, tree[rt].r - tree[rt].l + 1); ll mid = (tree[rt].r + tree[rt].l) >> 1; if (L <= mid)update_range(L, R, key, rt << 1); if (R > mid)update_range(L, R, key, rt << 1 | 1); push_up(rt); }
il ll query_range(ll L, ll R, ll rt) { if (L <= tree[rt].l && R >= tree[rt].r) { return tree[rt].sum; }push_down(rt, tree[rt].r - tree[rt].l + 1); ll mid = (tree[rt].r + tree[rt].l) >> 1; ll ans = 0; if (L <= mid)ans += query_range(L, R, rt << 1); if (R > mid)ans += query_range(L, R, rt << 1 | 1); return ans; }
il ll query_min(ll L, ll R, ll rt) { if (L <= tree[rt].l && R >= tree[rt].r) { return tree[rt].minn; }push_down(rt, tree[rt].r - tree[rt].l + 1); ll mid = (tree[rt].r + tree[rt].l) >> 1; ll ans = (0x3f3f3f3f3f3f3f3fll); if (L <= mid)ans = min(ans, query_min(L, R, rt << 1)); if (R > mid)ans = min(ans, query_min(L, R, rt << 1 | 1)); return ans; }
il ll query_max(ll L, ll R, ll rt) { if (L <= tree[rt].l && R >= tree[rt].r) { return tree[rt].maxn; }push_down(rt, tree[rt].r - tree[rt].l + 1); ll mid = (tree[rt].r + tree[rt].l) >> 1; ll ans = -(0x3f3f3f3f3f3f3f3fll); if (L <= mid)ans = max(ans, query_max(L, R, rt << 1)); if (R > mid)ans = max(ans, query_max(L, R, rt << 1 | 1)); return ans; }







struct vec
{
    double x, y; vec(double X = 0, double Y = 0) :x(X), y(Y) {}vec operator+(const vec& a)const { return vec(x + a.x, y + a.y); }
    vec operator-(const vec& a)const { return vec(x - a.x, y - a.y); }void operator+=(const vec& a) { this->x += a.x, this->y += a.y; }
    void operator-=(const vec& a) { this->x -= a.x, this->y -= a.y; }vec operator*(const double& a)const { return vec(x * a, y * a); }
    vec operator/(const double& a)const { return vec(x / a, y / a); }void operator*=(const double& a) { this->x *= a, this->y *= a; }
    void operator/=(const double& a) { this->x /= a, this->y /= a; }
};






int a[2500];
int b[2500];
int c[2500];
signed main()
{
    ios;
    int tt;
    cin >> tt;
    while (tt--)
    {
        
        mst(b, 0);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;
        }
        
        int k = 1;
        int ans = 0;
        for (int i = 0; i < 1024; i++)
        {
            mst(c, 0);
            int ok = 1;
            for (int j = 0; j < n; j++)
            {
                int t = a[j] ^ k;
                if (!b[t])
                {
                    ok = 0;
                    break;
                }
                else
                {
                    if (c[t] == 1) {
                        ok = 0; break;
                    }
                    else c[t] = 1;
                }

            }
            if (ok) { ans = 1; break; }
            k++;
        }
        if (ans)cout << k << endl;
        else cout << -1 << endl;
    }
}

