



































using namespace std;

using ll = long long;
using ld = long double;
template<typename T>
using v = vector<T>;
template<typename ...T>
using tup = tuple<T...>;
template<typename T1, typename T2>
using pa = pair<T1, T2>;
const ld PI = 3.1415926535;
const ll MOD = 998244353;

mt19937 rng;

template<typename T>
inline pa<T, T> operator+(pa<T, T> a, pa<T, T> b) {
    return { a.first + b.first, a.second + b.second };
}

template<typename T>
inline pa<T, T> operator+=(pa<T, T>& a, pa<T, T> b) {
    return a = a + b;
}

template<typename T>
inline pa<T, T> operator-(pa<T, T> a, pa<T, T> b) {
    return { a.first - b.first, a.second - b.second };
}

template<typename T>
inline pa<T, T> operator-=(pa<T, T>& a, pa<T, T> b) {
    return a = a - b;
}

template<typename T>
inline pa<T, T> operator*(pa<T, T> a, T b) {
    return { a.first * b, a.second * b };
}

template<typename T>
inline pa<T, T> operator*=(pa<T, T>& a, T b) {
    return a = a * b;
}
template<typename T>
inline pa<T, T> operator/(pa<T, T> a, T b) {
    return { a.first / b, a.second / b };
}

template<typename T>
inline pa<T, T> operator/=(pa<T, T>& a, T b) {
    return a = a / b;
}

template<typename T>
inline T cross(pa<T, T> a, pa<T, T> b) {
    return a.first * b.second - a.second * b.first;
}

template<typename T>
inline T dot(pa<T, T> a, pa<T, T> b) {
    return a.first * b.first + a.second * b.second;
}

template<typename T>
inline T operator*(pa<T, T> a, pa<T, T> b) {
    return dot(a, b);
}

template<typename T>
inline T operator^(pa<T, T> a, pa<T, T> b) {
    return cross(a, b);
}

template<typename A, typename B>
inline std::istream& operator>>(std::istream& in, pa<A, B>& pa) {
    

    return in >> pa.first >> pa.second;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, pa<T, T>& pa) {
    

    return out << pa.first << ' ' << pa.second;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, v<T>& a) {
    for (ll i = 0; i < a.size(); ++i) {
        in >> a[i];
    }
    return in;
}
template<typename T>
inline std::ostream& operator<<(std::ostream& out, v<T>& a) {
    for (ll i = 0; i < a.size(); ++i) {
        out << a[i] << ' ';
    }
    return out;
}

template<typename T>
inline T id7(pa<T, T> pa) {
    return pa.first * pa.first + pa.second * pa.second;
}

template<typename T>
inline T length(pa<T, T> pa) {
    return sqrt(id7(pa));
}

template<typename T>
inline T id6(pa<T, T> pa) {
    return abs(pa.first) + abs(pa.second);
}

template<typename T>
inline T id11(pa<T, T> a, pa<T, T> b) {
    return id6(a - b);
}

template<typename T>
inline pa<T, T> normalize(pa<T, T> pa) {
    return pa / length(pa);
}

inline pa<ld, ld> toLd(pa<ll, ll> pa) {
    return { (ld)pa.first, (ld)pa.second };
}

template<typename T>
inline T sign(T n) {
    if (n > 0) {
        return 1;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

bool id4(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> x) {
    return x.first >= min(a.first, b.first) && x.first <= max(a.first, b.first) && x.second >= min(a.second, b.second) && x.second <= max(a.second, b.second);
}

bool id9(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> x) {
    if (((b - a) ^ (x - a)) == 0) {
        return id4(a, b, x);
    }
    else {
        return false;
    }
}

bool id5(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> c, pa<ll, ll> p) {
    ll s = abs((b - a) ^ (c - a));
    ll s1 = abs((p - a) ^ (c - a));
    ll s2 = abs((b - a) ^ (p - a));
    ll s3 = abs((b - p) ^ (c - p));
    return s == s1 + s2 + s3;
}

ld id1(pa<ld, ld> a, pa<ld, ld> b, pa<ld, ld> c) {
    ld id3 = abs(cross(b - a, c - a)) / (length(b - a));
    

    bool ray = dot(c - a, b - a) >= 0;
    
    bool segm = ray && (dot(c - b, a - b) >= 0);
    if (segm) {
        return id3;
    }
    else {
        return min(length(c - a), length(c - b));
    }
}

struct id8 {
    using tree_el = ll;

    ll n = 4e5 + 1;

    v<tree_el> st;
    v<ll> addition;
    v<pa<ll, bool>> modification;

    static constexpr tree_el neutral = -1e18;

    id8() = default;

    id8(const v<ll>& x) {
        n = x.size();
        st = v<ll>(4 * n);
        addition = v<ll>(4 * n);
        modification = v<pa<ll, bool>>(4 * n, { -1, false });
        build(x);
    }

    inline tree_el combine(tree_el a, tree_el b) {
        return max(a, b);
    }

    void add_node(ll i, ll x) {
        if (modification[i].second) {
            modification[i].first += x;
        }
        else {
            addition[i] += x;
        }
    }

    void set_node(ll i, ll x) {
        addition[i] = 0;
        modification[i].second = true;
        modification[i].first = x;
    }

    inline void propagate(ll i, ll size) {
        if (modification[i].second) {
            st[i] = (modification[i]).first;
            if (2 * i + 1 < st.size()) {
                set_node(2 * i + 1, modification[i].first);
                

                if (2 * i + 2 < st.size()) {
                    set_node(2 * i + 2, modification[i].first);
                }
            }
            modification[i].second = false;
        }
        else {
            st[i] += (addition[i]);
            if (2 * i + 1 < st.size()) {
                add_node(2 * i + 1, addition[i]);
                

                if (2 * i + 2 < st.size()) {
                    add_node(2 * i + 2, addition[i]);
                }
            }
            addition[i] = 0;
        }
    }

    tree_el build(const v<ll>& x, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else if (R - L == 1) {
            return st[i] = x[L];
        }
        else {
            ll M = (L + R) >> 1;
            return st[i] = combine(build(x, 2 * i + 1, L, M), build(x, 2 * i + 2, M, R));
        }
    }

    tree_el update(ll p, tree_el x, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else {
            propagate(i, R - L);
            if (L > p || R <= p) {
                return st[i];
            }
            else if (R - L == 1) {
                return st[i] = x;
            }
            else {
                ll M = (L + R) >> 1;
                return st[i] = combine(update(p, x, 2 * i + 1, L, M), update(p, x, 2 * i + 2, M, R));
            }
        }
    }

    tree_el get_range(ll inL, ll inR, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else {
            propagate(i, R - L);
            if (L >= inR || R <= inL) {
                return neutral;
            }
            else if (L >= inL && R <= inR) {
                tree_el x = st[i];
                return x;
            }
            else {
                ll M = (L + R) >> 1;
                tree_el x = combine(get_range(inL, inR, 2 * i + 1, L, M), get_range(inL, inR, 2 * i + 2, M, R));
                return x;
            }
        }
    }

    void add_range(ll inL, ll inR, ll inX, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return;
        }
        else {
            propagate(i, R - L);
            if (L >= inR || R <= inL) {
                return;
            }
            else if (L >= inL && R <= inR) {
                add_node(i, inX);
                

                propagate(i, R - L);
            }
            else {
                ll M = (L + R) >> 1;
                add_range(inL, inR, inX, 2 * i + 1, L, M);
                add_range(inL, inR, inX, 2 * i + 2, M, R);
                propagate(2 * i + 1, M - L);
                propagate(2 * i + 2, R - M);
                st[i] = combine(st[2 * i + 1], st[2 * i + 2]);
            }
        }
    }

    void set_range(ll inL, ll inR, ll inX, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return;
        }
        else {
            propagate(i, R - L);
            if (L >= inR || R <= inL) {
                return;
            }
            else if (L >= inL && R <= inR) {
                

                set_node(i, inX);
                propagate(i, R - L);
            }
            else {
                ll M = (L + R) >> 1;
                set_range(inL, inR, inX, 2 * i + 1, L, M);
                set_range(inL, inR, inX, 2 * i + 2, M, R);
                propagate(2 * i + 1, M - L);
                propagate(2 * i + 2, R - M);
                st[i] = combine(st[2 * i + 1], st[2 * i + 2]);
            }
        }
    }
};

struct best_ans_finder {
    ll best_ans = -1e18;
    ll best_in = -1e18;
    ll best_out = -1e18;
};

struct id2 {
    using tree_el = best_ans_finder;

    ll n = 4e5 + 1;

    v<tree_el> st;
    

    tree_el neutral;

    id2() = default;

    id2(const v<best_ans_finder>& x) {
        neutral.best_ans = neutral.best_in = neutral.best_out = -1e18;
        n = x.size();
        st = v<tree_el>(4 * n, neutral);
        
        build(x);
    }

    inline tree_el combine(tree_el a, tree_el b) {
        tree_el res;
        res.best_in = max(a.best_in, b.best_in);
        res.best_out = max(a.best_out, b.best_out);
        res.best_ans = max({ a.best_ans, b.best_ans, a.best_in + b.best_out });
        return res;
    }

    

    inline void propagate(ll i, ll size) {

    }

    tree_el build(const v<best_ans_finder>& x, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else if (R - L == 1) {
            return st[i] = x[L];
        }
        else {
            ll M = (L + R) >> 1;
            return st[i] = combine(build(x, 2 * i + 1, L, M), build(x, 2 * i + 2, M, R));
        }
    }

    tree_el update(ll p, tree_el x, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else {
            propagate(i, R - L);
            if (L > p || R <= p) {
                return st[i];
            }
            else if (R - L == 1) {
                return st[i] = x;
            }
            else {
                ll M = (L + R) >> 1;
                return st[i] = combine(update(p, x, 2 * i + 1, L, M), update(p, x, 2 * i + 2, M, R));
            }
        }
    }

    tree_el get_range(ll inL, ll inR, ll i = 0, ll L = 0, ll R = -1) {
        if (R == -1) {
            R = n;
        }
        if (R - L == 0) {
            return neutral;
        }
        else {
            propagate(i, R - L);
            if (L >= inR || R <= inL) {
                return neutral;
            }
            else if (L >= inL && R <= inR) {
                tree_el x = st[i];
                return x;
            }
            else {
                ll M = (L + R) >> 1;
                tree_el x = combine(get_range(inL, inR, 2 * i + 1, L, M), get_range(inL, inR, 2 * i + 2, M, R));
                return x;
            }
        }
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

};

void solve() {
    ll n, q;
    cin >> n >> q;
    v<v<ll>> a(n, v<ll>(3));
    for (ll i = 0; i < 3; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> a[j][i];
        }
    }
    v<pa<pa<ll, ll>, ll>> s(q);
    cin >> s;
    v<v<ll>> id10(n);
    for (ll i = 0; i < q; ++i) {
        auto& [lr, k] = s[i];
        auto& [l, r] = lr;
        --l;
        --r;
        id10[r].push_back(i);
    }
    v<v<ll>> pref(n + 1, v<ll>(3));
    for (ll j = 0; j < 3; ++j) {
        for (ll i = 0; i < n; ++i) {
            pref[i + 1][j] = pref[i][j] + a[i][j];
        }
    }
    v<ll> prest(n);
    for (ll i = 0; i < n; ++i) {
        prest[i] = pref[i + 1][0] - pref[i][1];
    }
    id8 st(prest);
    id8 dpv((v<ll>(n)));
    for (ll i = 0; i < n; ++i) {
        ll mares = -1e18;
        for (ll j : id10[i]) {
            auto [lr, k] = s[j];
            auto [l, r] = lr;
            mares = max({ mares, st.get_range(l, r + 1) - k, dpv.get_range(max(l - 1, 0ll), r) - k });
        }
        dpv.update(i, mares);
    }
    v<best_ans_finder> prestm(n);
    v<best_ans_finder> prests(n);
    for (ll i = 0; i < n; ++i) {
        ll c_in = dpv.get_range(i, i + 1);
        ll c_out = pref[i + 1][1] + pref[n][2] - pref[i][2];
        prestm[i].best_in = c_in;
        prestm[i].best_out = c_out;
        prestm[i].best_ans = c_in + c_out;
        ll id0 = pref[i + 1][0] - pref[i][1];
        prests[i].best_in = id0;
        prests[i].best_out = c_out;
        prests[i].best_ans = id0 + c_out;
    }
    id2 stm(prestm);
    id2 sts(prests);
    ll mares = -1e18;
    for (auto [lr, k] : s) {
        auto [l, r] = lr;
        ll aa = stm.get_range(max(0ll, l - 1), r + 1).best_ans - k;
        ll bb = sts.get_range(l, r + 1).best_ans - k;
        mares = max({ mares, aa, bb });
    }
    cout << mares;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    

    for (ll i = 0; i < t; ++i) {
        solve();
    }
}