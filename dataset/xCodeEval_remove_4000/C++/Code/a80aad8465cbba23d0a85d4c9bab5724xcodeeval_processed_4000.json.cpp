

























using namespace std;
typedef long long ll;



const long double Pi = acos(-1.0);
const ll dx[] = {0,0,1,-1};
const ll dy[] = {1,-1,0,0};
const ll N = (ll) 1e6 + 17;
const ll M = (ll) 5e3 + 69;
const ll inf = (ll) 1e14 + 3;
const ll mod = (ll) 1e9 + 7;
ll sq(ll x) { return x * x; }

ll zxc = 1, a[N];

ll sum(ll x) {
    return x * (x + 1) / 2;
}

struct node {
    ll seg, pref, suf, ans, fst, lst;
} t[4 * N];

const node zero = { 0, 0, 0, 0, inf, inf };

node combine(node a, node b) {
    node c;
    c.seg = a.seg + b.seg;
    c.pref = a.pref, c.suf = b.suf;
    c.fst = a.fst, c.lst = b.lst;
    c.ans = a.ans + b.ans;
    if(a.lst <= b.fst) {
        c.ans += sum(a.suf + b.pref);
        c.ans -= sum(a.suf) + sum(b.pref);
        c.suf += (b.suf == b.seg) * a.suf;
        c.pref += (a.pref == a.seg) * b.pref;
    }
    return c;
}

void recalc(ll v) {
    t[v] = combine(t[left(v)], t[right(v)]);
}

node one(ll x) {
    return { 1, 1, 1, 1, x, x };
}

void build(ll v, ll tl, ll tr) {
    if(!(tr - tl)) { t[v] = one(a[tl]); return; }
    ll tm = (tl + tr) / 2;
    build(left(v), tl, tm);
    build(right(v), tm + 1, tr);
    recalc(v);
}

node get(ll v, ll tl, ll tr, ll l, ll r) {
    if(l <= tl && tr <= r) return t[v];
    if(tr < l || r < tl) return zero;
    ll tm = (tl + tr) / 2;
    return combine(get(left(v), tl, tm, l, r), get(right(v), tm + 1, tr, l, r));
}

void upd(ll v, ll tl, ll tr, ll i, ll x) {
    if(!(tl - tr)) { t[v] = one(x); return; }
    ll tm = (tl + tr) / 2;
    if(i <= tm) upd(left(v), tl, tm, i, x);
    else upd(right(v), tm + 1, tr, i, x);
    recalc(v);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--) {
        ll tp, l, r;
        cin >> tp >> l >> r;
        if(tp == 1) upd(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r).ans << "\n";
    }
}

int main() {
ios_base::sync_with_stdio(0);
    cin.tie(0);



    while(zxc--) {
        solve();
    }
  	return 0;
}


