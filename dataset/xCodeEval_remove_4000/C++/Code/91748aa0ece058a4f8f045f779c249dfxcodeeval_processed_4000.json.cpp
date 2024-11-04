







using namespace std;

















        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);












typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;




template <typename TT, typename T>
T get_m(M<TT, T> &m, TT k, T default_value)
{
    if (m.find(k) == m.end()) return m[k] = default_value;
    return m[k];
}

template <typename TT, typename T>
void id9(M<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

template <typename TT, typename T>
void id9(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void id4(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void id1(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void id10(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void id6(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    id4(v, count);
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

template <typename T>
void _debug_print(T x)
{
    cout << x << endl;
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "-- " << x1 << " -- " << x2 << endl;
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "-- " << x1 << " -- " << x2 << " -- " << x3 << endl;
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "-- " << x1 << " -- " << x2
         << " -- " << x3 << " -- " << x4 << endl;
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename TT, typename T>
void _debug_print(const M<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

template <typename TT, typename T>
void _debug_print(const map<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

void id3(const char *prefix)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    struct tm *tm = localtime(&tv.tv_sec);

    debug_printf("-- %s %02d:%02d:%02d.%06ld\n",
                 prefix, tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec);
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
        ll id8 = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < id8) this->itemcount *= 2LL;
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

    void build(const T arr[]) {
        memcpy(nodes + nodecount / 2LL, arr, sizeof(T) * itemcount);
        rrep (i, nodecount / 2LL) {
            nodes[i] = op(nodes[i * 2LL + 1LL], nodes[i * 2LL + 2LL]);
        }
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

};































template <typename T>
struct id7 : public SegmentTree<T> {
    T *lzvals;
    bool *lzvalids;
    ll id0;
    void (*id12)(T&, T);
    T (*op_div)(T);
    T (*id2)(T, T);

    id7(ll itemcount, T unit, T id0,
                    T op(T, T), void id12(T&, T), T op_div(T), T id2(T, T))
        : SegmentTree<T>(itemcount, unit, op) {
        this->lzvals = new T[this->nodecount];
        this->lzvalids = new bool[this->nodecount];
        this->id0 = id0;
        this->id12 = id12;
        this->op_div = op_div;
        this->id2 = id2;
        rep (i, this->nodecount) this->lzvals[i] = id0;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
    }

    

    void eval(ll nodeidx) {
        if (!lzvalids[nodeidx]) return;

        id12(this->nodes[nodeidx], lzvals[nodeidx]);

        if (nodeidx * 2LL + 2LL < this->nodecount) {
            ll downval = op_div(lzvals[nodeidx]);
            id12(lzvals[nodeidx * 2LL + 1LL], downval);
            id12(lzvals[nodeidx * 2LL + 2LL], downval);
            lzvalids[nodeidx * 2LL + 1LL] = lzvalids[nodeidx * 2LL + 2LL] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->id0;
    }

    void update(ll start, ll end, ll val) {
        _update(start, end, val, 0LL);
    }

    void _update(ll start, ll end, ll val, ll nodeidx) {
        eval(nodeidx);

        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);
        if (end <= rstart || rend <= start) return;

        if (start <= rstart && rend <= end) {
            id12(lzvals[nodeidx], id2(val, rend - rstart));
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

    

    virtual T query(ll start, ll end) {
        return _query(start, end, 0LL);
    }

    virtual T _query(ll start, ll end, ll nodeidx) {
        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);

        eval(nodeidx);

        if (start <= rstart && rend <= end) {
            return this->nodes[nodeidx];
        }
        if (rend <= start || end <= rstart) {
            return this->unit;
        }
        ll border = (rstart+rend)/2LL;
        if (start < border) return _query(start, end, nodeidx * 2LL + 1LL);
        else return _query(start, end, nodeidx * 2LL + 2LL);

        T left = _query(start, end, nodeidx * 2LL + 1LL);
        T right = _query(start, end, nodeidx * 2LL + 2LL);
        return this->op(left, right);

    }
};







void _main();
int main()
{
    cout << setprecision(12);

    ios::sync_with_stdio(false);
    cin.tie(0);


    _main();
    return 0;
}



ll op(ll x, ll y){
    return x + y;
}
void id12(ll &x, ll y) {
    x += y;
}
ll op_div(ll x) {
    return x / 2LL;
}
ll id2(ll x, ll y) {
    return x * y;
}

void _main()
{
    ll n; llin(n);
    ll qcnt; llin(qcnt);
    V<ll> alist; llina(alist, n);
    V<t2> qlist; id1(qlist, qcnt);

    rep (i, n) alist[i]--;

    V<t3> id5;
    rep (i, qcnt) {
        ll leftcnt = get<0>(qlist[i]);
        ll rightcnt = get<1>(qlist[i]);
        id5.pb(t3(n - rightcnt - 1LL, leftcnt, i));
    }
    sort(id5);

    debug_printf("---- id5\n");
    debug_print(id5);

    V<ll> sublist;
    rep (i, n) sublist.pb(i-alist[i]);

    debug_printf("---- sublist\n");
    debug_print(sublist);

    id7<ll> permitted(300005, 0, 0, op, id12, op_div, id2);
    

    ll qidx = 0;
    S ll anslist[300005] = {};

    rep (i, n) {
        ll sub = sublist[i];
        if (sub < 0) {
            while (qidx < qcnt) {
                auto q = id5[qidx];
                ll lastidx = get<0>(q);
                ll beginidx = get<1>(q);
                ll qi = get<2>(q);
                if (lastidx > i) break;
                anslist[qi] = permitted.query(beginidx, beginidx+1LL);
                qidx++;
            }
            continue;
        }

        ll left = 0;
        ll right = i;
        ll now = (left+right) / 2LL;
        ll id11 = -1;
        for ( ; left <= right; now = (left+right) / 2LL) {
            ll p = permitted.query(now, now+1);
            if (sub <= p) {
                left = now + 1LL;
                id11 = max(id11, now);
            }
            else {
                right = now - 1LL;
            }
        }

        debug_printf("i=%lld id11=%lld\n", i, id11);

        if (id11 >= 0) {
            

            permitted.update(0, id11+1LL, 1LL);
        }

        while (qidx < qcnt) {
            auto q = id5[qidx];
            ll lastidx = get<0>(q);
            ll beginidx = get<1>(q);
            ll qi = get<2>(q);
            if (lastidx > i) break;
            anslist[qi] = permitted.query(beginidx, beginidx+1LL);
            qidx++;
        }
    }

    debug_printf("---- ans\n");
    rep (i, qcnt) cout << anslist[i] << endl;
}


