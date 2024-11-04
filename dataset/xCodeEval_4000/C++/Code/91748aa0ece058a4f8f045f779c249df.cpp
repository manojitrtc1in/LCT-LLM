


#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

using namespace std;




#define DEBUG 0

#define pb push_back
#define V vector
#define M unordered_map
#define S static

#define rep(i,n) for(ll i=0LL; i<n; ++i)
#define srep(i,s,n) for(ll i=s; i<n; ++i)
#define rrep(i,n) for(ll i=n-1LL; i>=0LL; --i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CIN(x) do { \
        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);
#if DEBUG
#define debug_print(...) _debug_print(__VA_ARGS__)
#define debug_printf(...) printf(__VA_ARGS__)
#define debug_print_time _debug_print_time
#else 

#define debug_print(...)
#define debug_printf(...)
#define debug_print_time
#endif 


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
void incr_m(M<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

template <typename TT, typename T>
void incr_m(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void llinl1(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void llinl2(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void llinl3(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void llinl4(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    llinl1(v, count);
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

void _debug_print_time(const char *prefix)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
#if DEBUG
    struct tm *tm = localtime(&tv.tv_sec);
#endif
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
        ll orig_itemcount = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < orig_itemcount) this->itemcount *= 2LL;
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
struct SegmentTreeLazy : public SegmentTree<T> {
    T *lzvals;
    bool *lzvalids;
    ll unit_upd;
    void (*op_upd)(T&, T);
    T (*op_div)(T);
    T (*op_mlt)(T, T);

    SegmentTreeLazy(ll itemcount, T unit, T unit_upd,
                    T op(T, T), void op_upd(T&, T), T op_div(T), T op_mlt(T, T))
        : SegmentTree<T>(itemcount, unit, op) {
        this->lzvals = new T[this->nodecount];
        this->lzvalids = new bool[this->nodecount];
        this->unit_upd = unit_upd;
        this->op_upd = op_upd;
        this->op_div = op_div;
        this->op_mlt = op_mlt;
        rep (i, this->nodecount) this->lzvals[i] = unit_upd;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
    }

    

    void eval(ll nodeidx) {
        if (!lzvalids[nodeidx]) return;

        op_upd(this->nodes[nodeidx], lzvals[nodeidx]);

        if (nodeidx * 2LL + 2LL < this->nodecount) {
            ll downval = op_div(lzvals[nodeidx]);
            op_upd(lzvals[nodeidx * 2LL + 1LL], downval);
            op_upd(lzvals[nodeidx * 2LL + 2LL], downval);
            lzvalids[nodeidx * 2LL + 1LL] = lzvalids[nodeidx * 2LL + 2LL] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->unit_upd;
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
            op_upd(lzvals[nodeidx], op_mlt(val, rend - rstart));
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
#if 0
        T left = _query(start, end, nodeidx * 2LL + 1LL);
        T right = _query(start, end, nodeidx * 2LL + 2LL);
        return this->op(left, right);
#endif
    }
};







void _main();
int main()
{
    cout << setprecision(12);
#if !DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif

    _main();
    return 0;
}



ll op(ll x, ll y){
    return x + y;
}
void op_upd(ll &x, ll y) {
    x += y;
}
ll op_div(ll x) {
    return x / 2LL;
}
ll op_mlt(ll x, ll y) {
    return x * y;
}

void _main()
{
    ll n; llin(n);
    ll qcnt; llin(qcnt);
    V<ll> alist; llina(alist, n);
    V<t2> qlist; llinl2(qlist, qcnt);

    rep (i, n) alist[i]--;

    V<t3> qtuples;
    rep (i, qcnt) {
        ll leftcnt = get<0>(qlist[i]);
        ll rightcnt = get<1>(qlist[i]);
        qtuples.pb(t3(n - rightcnt - 1LL, leftcnt, i));
    }
    sort(qtuples);

    debug_printf("---- qtuples\n");
    debug_print(qtuples);

    V<ll> sublist;
    rep (i, n) sublist.pb(i-alist[i]);

    debug_printf("---- sublist\n");
    debug_print(sublist);

    SegmentTreeLazy<ll> permitted(300005, 0, 0, op, op_upd, op_div, op_mlt);
    

    ll qidx = 0;
    S ll anslist[300005] = {};

    rep (i, n) {
        ll sub = sublist[i];
        if (sub < 0) {
            while (qidx < qcnt) {
                auto q = qtuples[qidx];
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
        ll incrlast = -1;
        for ( ; left <= right; now = (left+right) / 2LL) {
            ll p = permitted.query(now, now+1);
            if (sub <= p) {
                left = now + 1LL;
                incrlast = max(incrlast, now);
            }
            else {
                right = now - 1LL;
            }
        }

        debug_printf("i=%lld incrlast=%lld\n", i, incrlast);

        if (incrlast >= 0) {
            

            permitted.update(0, incrlast+1LL, 1LL);
        }

        while (qidx < qcnt) {
            auto q = qtuples[qidx];
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



