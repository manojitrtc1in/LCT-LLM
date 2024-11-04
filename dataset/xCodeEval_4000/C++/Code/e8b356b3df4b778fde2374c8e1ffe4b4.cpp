

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

namespace segtree1{
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return (__int128)a.first * b.second <= (__int128)a.second * b.first;
}

pair<ll, ll> intersect(pair<ll, ll> a, pair<ll, ll> b) {
    assert(a.first != b.first);
    

    pair<ll, ll> x = mp(b.second - a.second, a.first - b.first);
    if (x.second < 0) {
        x.first *= -1;
        x.second *= -1;
    }
    ll d = gcd(abs(x.first), x.second);
    x.first /= d;
    x.second /= d;
    return x;
}

struct item {
    vector<pair<pair<ll, ll>, pair<ll, ll>>> lines;
    ll ans = 4e18;

    template<typename T>
    void init(const T &t, int l, int r) {
        lines.eb(mp(0, 1), t);
    }

    void update(const item &first, const item &second, int l, int r) {
        int i1 = 0, i2 = 0;
        lines.clear();
        while (i1 < first.lines.size() || i2 < second.lines.size()) {
            bool choose1;
            if (i2 == second.lines.size()) choose1 = true;
            else if (i1 == first.lines.size()) choose1 = false;
            else if (first.lines[i1].second.first > second.lines[i2].second.first) choose1 = true;
            else if (first.lines[i1].second.first < second.lines[i2].second.first) choose1 = false;
            else if (first.lines[i1].second.second < second.lines[i2].second.second) choose1 = true;
            else choose1 = false;

            pair<ll, ll> line;
            if (choose1) {
                line = first.lines[i1].second;
                ++i1;
            } else {
                line = second.lines[i2].second;
                ++i2;
            }
            if (!lines.empty() && lines.back().second.first == line.first) continue;

            while (lines.size() >= 1 && comp(intersect(lines.back().second, line), lines.back().first))
                lines.pop_back();
            lines.eb((lines.empty() ? mp(0ll, 1ll) : intersect(lines.back().second, line)), line);
        }
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.ans = min(first.ans, second.ans);
        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, pair<ll, ll> p, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            item it;
            l = max(0, (int)(lower_bound(tree[i].lines.begin(), tree[i].lines.end(), p, [](const auto &a, const auto &b) {
                return comp(a.first, b);
            }) - tree[i].lines.begin()) - 1);
            it.ans = tree[i].lines[l].second.first * p.first + tree[i].lines[l].second.second * p.second;
            return it;
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, p, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, p, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, p, i * 2 + 1, vl, m), ask(m + 1, r, p, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r, pair<ll, ll> p) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, p, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};
}

namespace segtree2 {
struct item {
    ll mn = 4e18;
    template<typename T>
    void init(const T &t, int l, int r) {
        mn = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        mn = min(first.mn, second.mn);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  

        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};
}

void test_case(int test) {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    cin >> v;
    if (n <= 2) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 4e18;

    auto norm = [&]() {
        sort(v.begin(), v.end());
        ll minx = 1e18, miny = 1e18;
        for (auto [x, y] : v) {
            minx = min(minx, x);
            miny = min(miny, y);
        }
        for (int i = 0; i < v.size(); ++i) {
            v[i].first -= minx;
            v[i].second -= miny;
        }
        ll lastx = -1e18, lasty = -1e18;
        for (auto [x, y] : v) {
            lastx = max(lastx, x);
            lasty = max(lasty, y);
        }
        return mp(lastx, lasty);
    };

    auto solve1 = [&]() {
        auto [lastx, lasty] = norm();
        vector<ll> lowest(n);
        lowest.back() = v.back().second;
        for (int i = n - 2; i >= 0; --i)
            lowest[i] = min(v[i].second, lowest[i + 1]);

        segtree1::segtree tree(1);
        vector<ll> ys;
        vector<pair<ll, ll>> lines;
        {
            vector<ll> fy;
            sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });
            for (auto [x, y] : v) {
                if (ys.empty() || ys.back() != y) {
                    fy.pb(x);
                    ys.pb(y);
                }
            }
            for (int i = (int)fy.size() - 2; i >= 0; --i)
                fy[i] = min(fy[i], fy[i + 1]);
            for (int i = 0; i + 1 < fy.size(); ++i) {
                lines.eb(-fy[i + 1], ys[i]);
            }
            if (!lines.empty())
                tree.build(lines);
        }

        sort(v.begin(), v.end());
        ll highesty = 0;
        for (int i = 0; i < n - 1; ++i) {
            highesty = max(highesty, v[i].second);
            ll x = v[i].first;
            ll h = lasty - lowest[i + 1];

            int il = lowb(ys, lowest[i + 1]);
            int ir = (int)lowb(ys, highesty) - 1;

            ans = min(ans, tree.ask(il, ir, {h, x}).ans + lastx * h);
        }
    };

    auto solve2 = [&]() {
        auto [lastx, lasty] = norm();
        vector<ll> sufmin(n);
        vector<ll> sufmax(n);
        for (int i = 0; i < n; ++i)
            sufmax[i] = sufmin[i] = v[i].second;
        for (int i = n - 2; i >= 0; --i) {
            sufmin[i] = min(sufmin[i], sufmin[i + 1]);
            sufmax[i] = max(sufmax[i], sufmax[i + 1]);
        }
        ll miny = 1e18;
        ll maxy = -1e18;
        for (int i = 0; i < n - 1; ++i) {
            miny = min(miny, v[i].second);
            maxy = max(maxy, v[i].second);
            ans = min(ans, (maxy - miny) * v[i].first + (lastx - v[i + 1].first) * (sufmax[i + 1] - sufmin[i + 1]));
        }
    };

    auto solve3 = [&]() {
        auto [lastx, lasty] = norm();
        vector<ll> minys(n);
        vector<ll> maxys(n);
        vector<ll> prefmax(n);
        vector<ll> prefmin(n);
        for (int i = 0; i < n; ++i) {
            minys[i] = maxys[i] = prefmax[i] = prefmin[i] = v[i].second;
        }
        for (int i = n - 2; i >= 0; --i) {
            minys[i] = min(minys[i], minys[i + 1]);
            maxys[i] = max(maxys[i], maxys[i + 1]);
        }
        for (int i = 1; i < n; ++i) {
            prefmax[i] = max(prefmax[i], prefmax[i - 1]);
            prefmin[i] = min(prefmin[i], prefmin[i - 1]);
        }

        segtree2::segtree tree2(n - 1);
        {
            vector<ll> tmp(n - 1);
            for (int j = 0; j + 1 < n; ++j) {
                tmp[j] = -(v.back().first - v[0].first) * prefmin[j] - v[j + 1].first * lasty;
            }

            tree2.build(tmp);
        }

        for (int i = 0; i < n - 1; ++i) {
            ll miny = minys[i + 1];
            ll maxy = maxys[i + 1];
            int l = min(i, (int)(lower_bound(prefmax.begin(), prefmax.end(), maxy + 1) - prefmax.begin()));
            int ind = min(l, (int)(lower_bound(prefmin.begin(), prefmin.end(), miny - 1, greater<ll>()) - prefmin.begin()));
            ans = min(ans, (v.back().first - v[0].first) * (maxy - miny) + v[i].first * lasty - v[ind].first * lasty);
            ans = min(ans, (v.back().first - v[0].first) * maxy + v[i].first * lasty + tree2.ask(ind, l - 1).mn);
        }
    };

    for (int i = 0; i < 2; ++i) {
        solve1();
        for (int i = 0; i < n; ++i)
            v[i].second *= -1;
    }
    for (int i = 0; i < 2; ++i) {
        solve2();
        for (int i = 0; i < n; ++i)
            swap(v[i].first, v[i].second);
    }
    for (int i = 0; i < 2; ++i) {
        solve3();
        for (int i = 0; i < n; ++i)
            v[i].first *= -1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}