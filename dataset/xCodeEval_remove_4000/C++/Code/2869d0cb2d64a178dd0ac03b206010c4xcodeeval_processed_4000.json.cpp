







using namespace std;
















        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);












typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ll128;
typedef tuple<int, int> t2;
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

    int nodecount;
    int itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(int itemcount, T unit, T op(T, T)) {
        int id11 = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < id11) this->itemcount *= 2LL;
        nodecount = this->itemcount * 2 - 1;
        nodes = new T[nodecount];
        ranges = new t2[nodecount];
        this->unit = unit;
        this->op = op;

        int start = 0LL;
        int end = this->itemcount;
        int len = this->itemcount;

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

    void initialize(const T arr[], int cnt) {
        memcpy(nodes + nodecount / 2LL, arr, sizeof(T) * cnt);
        rrep (i, nodecount / 2LL) {
            nodes[i] = op(nodes[i * 2LL + 1LL], nodes[i * 2LL + 2LL]);
        }
    }

    void initialize(const T val) {
        T *vals = new T[sizeof(T) * itemcount];
        rep (i, itemcount) vals[i] = val;
        initialize(vals, itemcount);
        delete [] vals;
    }

    void update(int k, T v) {
        int idx = k + itemcount - 1LL;
        nodes[idx] = v;
        idx = (idx - 1LL) / 2LL;

        for ( ; idx >= 0; idx = (idx - 1LL) / 2LL) {
            nodes[idx] = op(nodes[idx * 2LL + 1LL],
                            nodes[idx * 2LL + 2LL]);
            if (!idx) break;
        }
    }

    

    virtual T query(int start, int end) const {
        return _query(start, end, 0LL);
    }

    virtual T _query(int start, int end, int idx) const {
        int rstart = get<0>(ranges[idx]);
        int rend = get<1>(ranges[idx]);

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

    T query_fast(int start, int end) const {
        start += nodecount / 2LL;
        end += nodecount / 2LL;
        T lval = unit;
        T rval = unit;
        for ( ; start < end; start >>= 1LL, end >>= 1LL) {
            if (!(start & 1LL)) lval = min(lval, nodes[start]);
            if (!(end & 1LL)) rval = min(rval, nodes[end-1]);
            end--;
        }
        return min(lval, rval);
    }

};




template <typename T1, typename T2>
struct id10 : public SegmentTree<T1> {
    T2 *lzvals;
    bool *lzvalids;
    T2 id0;
    void (*id2)(T1&, T2);
    T2 (*id5)(T2);
    T2 (*id1)(T2, int);
    void (*id7)(T2&, T2);

    id10(int itemcount, T1 id15, T2 id0,
                    T1 id14(T1, T1), void id2(T1&, T2),
                    T2 id5(T2), T2 id1(T2, int),
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

    

    void eval(int nodeidx) {
        this->nodes[nodeidx] += lzvals[nodeidx];

        int idx1 = (nodeidx<<1) + 1;
        int idx2 = (nodeidx<<1) + 2;

        if (idx2 < this->nodecount) {
            T2 downval = lzvals[nodeidx];
            lzvals[idx1] += downval;
            lzvals[idx2] += downval;
            lzvalids[idx1] = lzvalids[idx2] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->id0;
    }

    void update(int start, int end, T2 val) {
        _update(start, end, val, 0LL);
    }

    void _update(int start, int end, T2 val, int nodeidx) {
        if (lzvalids[nodeidx]) eval(nodeidx);

        int rstart = get<0>(this->ranges[nodeidx]);
        int rend = get<1>(this->ranges[nodeidx]);
        if (end <= rstart || rend <= start) return;

        if (start <= rstart && rend <= end) {
            lzvals[nodeidx] += val;
            lzvalids[nodeidx] = true;
            eval(nodeidx);
        }
        else {
            int idx1 = (nodeidx<<1) + 1;
            int idx2 = (nodeidx<<1) + 2;
            _update(start, end, val, idx1);
            _update(start, end, val, idx2);
            this->nodes[nodeidx] = min(this->nodes[idx1], this->nodes[idx2]);
        }
    }

    void updatex(int start, int end, T2 val) {
        deque<int> q;
        deque<int> qq;
        q.push_front(0);

        while (q.size()) {
            ll nodeidx = q.front(); q.pop_front();
            if (lzvalids[nodeidx]) eval(nodeidx);

            int rstart = get<0>(this->ranges[nodeidx]);
            int rend = get<1>(this->ranges[nodeidx]);
            if (end <= rstart || rend <= start) continue;

            if (start <= rstart && rend <= end) {
                lzvals[nodeidx] += val;
                lzvalids[nodeidx] = true;
                eval(nodeidx);
            }
            else {
                q.push_front((nodeidx<<1) + 2);
                q.push_front((nodeidx<<1) + 1);
                qq.push_front(nodeidx);
            }
        }

        while (qq.size()) {
            ll nodeidx = qq.front(); qq.pop_front();
            this->nodes[nodeidx] = min(this->nodes[(nodeidx<<1) + 1], this->nodes[(nodeidx<<1) + 2]);
        }
    }

    

    virtual T1 query(int start, int end) {
        return _query(start, end, 0LL);
    }

    virtual T1 _query(int start, int end, int nodeidx) {
        int rstart = get<0>(this->ranges[nodeidx]);
        int rend = get<1>(this->ranges[nodeidx]);

        if (lzvalids[nodeidx]) eval(nodeidx);

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

    virtual T1 queryx(int start, int end) {
        queue<ll> qn;
        qn.push(0);

        while (qn.size()) {
            ll nodeidx = qn.front(); qn.pop();
            int rstart = get<0>(this->ranges[nodeidx]);
            int rend = get<1>(this->ranges[nodeidx]);
            if (!lzvalids[nodeidx]) continue;
            eval(nodeidx);
            if (start <= rstart && rend <= end) continue;
            if (rend <= start || end <= rstart) continue;
            qn.push((nodeidx<<1) + 1);
            qn.push((nodeidx<<1) + 2);
        }

        return this->query_fast(start, end);
    }

    virtual T1 all() {
        if (lzvalids[0]) eval(0);
        return this->nodes[0];
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



















int id14(int x, int y)
{
    return min(x, y);
}
void id2(int &x, int y)
{
    x += y;
}
int id5(int x)
{
    return x;
}
int id1(int x, int y)
{
    return x;
}
void id7(int& x, int y)
{
    x += y;
}


void _main()
{
    ll n; llin(n);
    ll k; llin(k);
    V<ll> alist; llina(alist, n);

    id10<int, int> *trees[SZK];
    srep (i, 1, SZK) {
        trees[i] = new id10<int, int>(SZN, 1225000000, 0,
                                                 id14, id2,
                                                 id5, id1, id7);
        

    }
    

    trees[1]->_update(0, 1, -1225000000, 0);

    S V<int> idxs[SZN];
    rep (i, n) idxs[alist[i]].pb(i);

    rep (i, n) {
        debug_printf("--------------- i=%lld\n", i);
        int a = alist[i];

        auto iter_idx = lower_bound(ALL(idxs[a]), i);
        if (iter_idx != idxs[a].begin()) {
            iter_idx--;
            int end = *iter_idx + 1;
            debug_printf("---- end=%d incr=%lld\n", end, i - *iter_idx);
            srep (j, 1, k+1) trees[j]->_update(0, end, i - *iter_idx, 0);
        }

        srep (j, 1, k) {
            

            int val = trees[j]->all();
            

            trees[j+1]->_update(i+1, i+2, val - 1225000000, 0);
        }


        srep (x, 1, 4) {
            debug_printf("---- tree %lld\n", x);
            rep (j, n+1) debug_printf("%lld ", trees[x]->query(j, j+1));
            debug_printf("\n");
        }

    }

    cout << trees[k]->query(0, n+1) << endl;
}



