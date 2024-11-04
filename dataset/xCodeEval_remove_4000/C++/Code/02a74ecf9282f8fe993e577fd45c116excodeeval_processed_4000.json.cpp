







using namespace std;
















        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);












typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ll128;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;




template <typename TT, typename T>
void id12(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void id8(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void id4(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void id13(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void id9(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    id8(v, count);
}

template <typename T>
void sort(V<T> &v)
{
    sort(v.begin(), v.end());
}

template <typename T>
void sort_reverse(V<T> &v)
{
    sort(v.begin(), v.end(), greater<T>());
}

t2 id6(ll a, ll b, ll g)
{
    if (!b) return t2(1, 0);
    ll q = a / b;
    ll r = a % b;
    t2 sol = id6(b, r, g);
    ll sx = get<0>(sol);
    ll sy = get<1>(sol);
    ll x = sy;
    ll y = sx - q * sy;
    return t2(x, y);
}

t2 id3(ll a, ll b)
{
    return id6(a, b, gcd(a, b));
}



ll mod_inv(ll x, ll mod)
{
    t2 result = id3(x, mod);
    ll ret = get<0>(result);
    while (ret < 0) ret += mod;
    ret %= mod;
    return ret;
}

ll msec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ll ret = 0;
    ret += tv.tv_sec * 1000LL;
    ret += tv.tv_usec / 1000LL;
    return ret;
}


template <typename T>
void _debug_print(T x)
{
    cout << x << " ";
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "(" << x1 << ", " << x2 << ") ";
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ") ";
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << ") ";
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
    cout << endl;
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) _debug_print(x);
    cout << endl;
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) _debug_print(x);
    cout << endl;
}

template <typename TT, typename T>
void _debug_print(const map<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "K=";
        _debug_print(k);
        cout << " V=";
        _debug_print(v);
        cout << endl;
    }
}







template <typename T>
struct SegmentTree {
    T *nodes;
    t2 *ranges;  

    ll nodecount;
    ll itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(ll itemcount, T unit, T op(T, T)) {
        ll id11 = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < id11) this->itemcount *= 2LL;
        nodecount = this->itemcount * 2 - 1;
        nodes = new T[nodecount];
        ranges = new t2[nodecount];
        this->unit = unit;
        this->op = op;

        ll start = 0LL;
        ll end = this->itemcount;
        ll len = this->itemcount;

        rep (i, nodecount) {
            nodes[i] = unit;
            ranges[i] = t2(start, end);
            if (end >= this->itemcount) {
                len /= 2LL;
                start = 0LL;
                end = len;
            }
            else {
                start = end;
                end = start + len;
            }
        }
    }

    virtual ~SegmentTree() {
        delete [] nodes;
        delete [] ranges;
    }

    virtual void initialize(const T arr[], ll cnt) {
        memcpy(nodes + nodecount / 2LL, arr, sizeof(T) * cnt);
        rrep (i, nodecount / 2LL) {
            nodes[i] = op(nodes[i * 2LL + 1LL], nodes[i * 2LL + 2LL]);
        }
    }

    virtual void initialize(const T val) {
        T *vals = new T[sizeof(T) * itemcount];
        rep (i, itemcount) vals[i] = val;
        initialize(vals, itemcount);
        delete [] vals;
    }

    void update(ll k, T v) {
        ll idx = k + itemcount - 1LL;
        nodes[idx] = v;
        idx = (idx - 1LL) / 2LL;

        for ( ; idx >= 0; idx = (idx - 1LL) / 2LL) {
            nodes[idx] = op(nodes[idx * 2LL + 1LL],
                            nodes[idx * 2LL + 2LL]);
            if (!idx) break;
        }
    }

    

    virtual T query(ll start, ll end) const {
        return _query(start, end, 0LL);
    }

    virtual T _query(ll start, ll end, ll idx) const {
        ll rstart = get<0>(ranges[idx]);
        ll rend = get<1>(ranges[idx]);

        if (start <= rstart && rend <= end) {
            return nodes[idx];
        }
        if (rend <= start || end <= rstart) {
            return unit;
        }
        T left = _query(start, end, idx * 2LL + 1LL);
        T right = _query(start, end, idx * 2LL + 2LL);
        return op(left, right);
    }

    T query_fast(ll start, ll end) const {
        start += nodecount / 2LL;
        end += nodecount / 2LL;
        T lval = unit;
        T rval = unit;
        for ( ; start < end; start >>= 1LL, end >>= 1LL) {
            if (!(start & 1LL)) lval = op(lval, nodes[start]);
            if (!(end & 1LL)) rval = op(rval, nodes[end-1]);
            end--;
        }
        return op(lval, rval);
    }

    virtual T all() {
        return nodes[0];
    }
};




template <typename T1, typename T2>
struct id10 : public SegmentTree<T1> {
    T2 *lzvals;
    bool *lzvalids;
    T2 id0;
    void (*id2)(T1&, T2);
    T2 (*id5)(T2);
    T2 (*id1)(T2, ll);
    void (*id7)(T2&, T2);

    id10(ll itemcount, T1 id15, T2 id0,
                    T1 id14(T1, T1), void id2(T1&, T2),
                    T2 id5(T2), T2 id1(T2, ll),
                    void id7(T2&, T2))
        : SegmentTree<T1>(itemcount, id15, id14) {
        this->lzvals = new T2[this->nodecount];
        this->lzvalids = new bool[this->nodecount];
        this->id0 = id0;
        this->id2 = id2;
        this->id5 = id5;
        this->id1 = id1;
        this->id7 = id7;
        rep (i, this->nodecount) this->lzvals[i] = id0;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
    }

    virtual ~id10() {
        delete [] lzvals;
        delete [] lzvalids;
    }

    virtual void initialize(const T1 arr[], ll cnt) {
        rep (i, this->nodecount) this->lzvals[i] = this->id0;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
        SegmentTree<T1>::initialize(arr, cnt);
    }

    

    void eval(ll nodeidx) {
        if (!lzvalids[nodeidx]) return;

        id2(this->nodes[nodeidx], lzvals[nodeidx]);

        if (nodeidx * 2LL + 2LL < this->nodecount) {
            T2 downval = id5(lzvals[nodeidx]);
            id7(lzvals[nodeidx * 2LL + 1LL], downval);
            id7(lzvals[nodeidx * 2LL + 2LL], downval);
            lzvalids[nodeidx * 2LL + 1LL] = lzvalids[nodeidx * 2LL + 2LL] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->id0;
    }

    void update(ll start, ll end, T2 val) {
        _update(start, end, val, 0LL);
    }

    void _update(ll start, ll end, T2 val, ll nodeidx) {
        eval(nodeidx);

        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);
        if (end <= rstart || rend <= start) return;

        if (start <= rstart && rend <= end) {
            id7(lzvals[nodeidx], id1(val, rend - rstart));
            lzvalids[nodeidx] = true;
            eval(nodeidx);
        }
        else {
            _update(start, end, val, nodeidx * 2LL + 1LL);
            _update(start, end, val, nodeidx * 2LL + 2LL);
            this->nodes[nodeidx] = this->op(this->nodes[nodeidx * 2LL + 1LL],
                                            this->nodes[nodeidx * 2LL + 2LL]);
        }
    }

    

    virtual T1 query(ll start, ll end) {
        return _query(start, end, 0LL);
    }

    virtual T1 _query(ll start, ll end, ll nodeidx) {
        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);

        eval(nodeidx);

        if (start <= rstart && rend <= end) {
            return this->nodes[nodeidx];
        }
        if (rend <= start || end <= rstart) {
            return this->unit;
        }
        T1 left = _query(start, end, nodeidx * 2LL + 1LL);
        T1 right = _query(start, end, nodeidx * 2LL + 2LL);
        return this->op(left, right);
    }

    virtual T1 all() {
        eval(0);
        return SegmentTree<T1>::all();
    }
};









ll id14(ll x, ll y)
{
    return max(x, y);
}
void id2(ll &x, ll y)
{
    x += y;
}
ll id5(ll x)
{
    return x;
}
ll id1(ll x, ll y)
{
    return x;
}
void id7(ll& x, ll y)
{
    x += y;
}

id10<ll, ll> tree(itemcount a---- a, -1e18, 0,
                             id14, id2,
                             id5, id1, id7);
tree.initialize(0);




t2 id14(t2 x, t2 y)
{
    ll val1 = get<0>(x);
    ll len1 = get<1>(x);
    ll val2 = get<0>(y);
    ll len2 = get<1>(y);
    return t2(val1 + val2, len1 + len2);
}
void id2(t2& x, ll y)
{
    ll val = get<0>(x);
    ll len = get<1>(x);
    val += y * len;
    x = t2(val, len);
}
ll id5(ll x)
{
    return x;
}
ll id1(ll x, ll cnt)
{
    return x;
}
void id7(ll& x, ll y)
{
    x += y;
}

id10<t2, ll> tree(itemcount a---- a, t2(0, 0), 0,
                             id14, id2,
                             id5, id1, id7);
tree.initialize(t2(0, 1));





ll id14(ll x, ll y)
{
    return x + y;
}
void id2(ll &x, ll y)
{
    x += y;
}
ll id5(ll x)
{
    return x / 2LL;
}
ll id1(ll x, ll y)
{
    return x * y;
}
void id7(ll& x, ll y)
{
    x += y;
}

id10<ll, ll> tree(itemcount a---- a, 0, 0,
                             id14, id2,
                             id5, id1, id7);




t2 id14(t2 x, t2 y)
{
    ll val1 = get<0>(x);
    ll len1 = get<1>(x);
    ll val2 = get<0>(y);
    ll len2 = get<1>(y);
    return t2(val1 + val2, len1 + len2);
}
void id2(t2& x, ll y)
{
    if (y == -1e18) return;
    ll len = get<1>(x);
    x = t2(y * len, len);
}
ll id5(ll x)
{
    return x;
}
ll id1(ll x, ll cnt)
{
    return x;
}
void id7(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}

id10<t2, ll> tree(itemcount a---- a, t2(0, 0), -1e18,
                             id14, id2,
                             id5, id1, id7);
tree.initialize(t2(0, 1));




ll id14(ll x, ll y)
{
    return x + y;
}
void id2(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}
ll id5(ll x)
{
    return x / 2LL;
}
ll id1(ll x, ll cnt)
{
    return x * cnt;
}
void id7(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}

id10<ll, ll> tree(itemcount a---- a, 0, -1e18,
                             id14, id2,
                             id5, id1, id7);













void _main();
int main()
{
    cout << setprecision(12);

    ios::sync_with_stdio(false);
    cin.tie(0);


    _main();
    return 0;
}



















ll sumll(ll x, ll y)
{
    return x + y;
}

void f1(ll sum1[SZ], const V<ll> &alist, ll n)
{
    V<t2> vidxs;
    rep (i, n) vidxs.pb(t2(alist[i], i));
    sort(vidxs);

    SegmentTree<ll> tree(SZ, 0, sumll);
    priority_queue_incr<t3> q1;

    for (auto vidx : vidxs) {
        ll v, i; tie(v, i) = vidx;
        sum1[i] = v * i;

        V<t3> later;
        while (q1.size()) {
            ll vv, ov, ii; tie(vv, ov, ii) = q1.top();
            if (vv > v) break;
            q1.pop();

            assert(v > ov);
            ll diff = v - ov;
            diff /= ov;
            diff *= ov;
            ll vv0 = ov + diff;

            tree.update(ii, vv0);
            later.pb(t3(vv0 + ov, ov, ii));
        }

        for (auto item : later) q1.push(item);

        sum1[i] -= tree.query(0, i);

        tree.update(i, v);
        q1.push(t3(v+v, v, i));
    }

    debug_printf("---- sum1\n");
    debug_print(sum1, n);
}

void f2(ll sum2[SZ], const V<ll> &alist, ll n)
{
    ll sum = 0;
    sum2[0] = sum;
    rep (i, n) {
        sum += alist[i];
        sum2[i+1] = sum;
    }

    SegmentTree<ll> treecnt(VEND, 0, sumll);

    rep (i, n) {
        ll a = alist[i];
        rep (j, VEND) {
            if (j*a >= VEND) break;
            sum2[i] -= treecnt.query_fast(j*a, min((j+1)*a, VEND)) * a * j;
        }

        treecnt.update(a, 1);
    }

    debug_printf("---- sum2\n");
    debug_print(sum2, n);
}

void _main()
{
    ll n; llin(n);
    V<ll> alist; llina(alist, n);

    S ll sum1[SZ];
    f1(sum1, alist, n);

    S ll sum2[SZ];
    f2(sum2, alist, n);

    ll now = 0;
    rep (i, n) {
        now += sum1[i];
        now += sum2[i];
        cout << now << " ";
    }
    cout << endl;
}



