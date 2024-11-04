




















































using namespace __gnu_pbds;

using namespace std;

template<typename T>
using inverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


























using ll = long long;



struct Cerr : public ostream {
    template<typename T>
    Cerr& operator<<(T const&) {
        return *this;
    }
} cerr;



mt19937 rnd(223);
mt19937_64 rndll(231);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());



template<typename T>
void setmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void setmax(T &x, T y) {
    x = max(x, y);
}



namespace Ment {
    template<typename T>
    T inverse(T a, T m) {
        T u = 0, v = 1;
        while (a != 0) {
            T t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    template<typename T>
    class Modular {
    public:
        using Type = typename decay<decltype(T::value)>::type;

        constexpr Modular() : value() {}

        template<typename U>
        Modular(const U &x) {
            value = normalize(x);
        }

        template<typename U>
        static Type normalize(const U &x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }

        const Type &operator()() const { return value; }

        template<typename U>
        explicit operator U() const { return static_cast<U>(value); }

        constexpr static Type mod() { return T::value; }

        Modular &operator+=(const Modular &other) {
            value += other.value - mod();
            value += (value >> 31) & mod();
            return *this;
        }

        Modular &operator-=(const Modular &other) {
            value -= other.value;
            value += (value >> 31) & mod();
            return *this;
        }

        template<typename U>
        Modular &operator+=(const U &other) { return *this += Modular(other); }

        template<typename U>
        Modular &operator-=(const U &other) { return *this -= Modular(other); }

        Modular &operator++() { return *this += 1; }

        Modular &operator--() { return *this -= 1; }

        Modular operator++(int) {
            Modular result(*this);
            *this += 1;
            return result;
        }

        Modular operator--(int) {
            Modular result(*this);
            *this -= 1;
            return result;
        }

        Modular operator-() const { return Modular(-value); }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &
        operator*=(const Modular &rhs) {

            uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
            uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
            asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
            );
            value = m;

            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

            return *this;
        }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }

        template<typename U = T>
        typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            value = normalize(value * rhs.value);
            return *this;
        }

        Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

        template<typename U>
        friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

    private:
        Type value;
    };

    template<typename T>
    bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }

    template<typename T, typename U>
    bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }

    template<typename T, typename U>
    bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

    template<typename T>
    bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T>
    bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

    template<typename T>
    Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T>
    Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T>
    Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T>
    Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> pow(const Modular<T> &a, const U &b) {
        assert(b >= 0);
        Modular<T> x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }

    template<typename T>
    string to_string(const Modular<T> &number) {
        return to_string(number());
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
        return stream << number();
    }

    template<typename T>
    std::istream &operator>>(std::istream &stream, Modular<T> &number) {
        typename common_type<typename Modular<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Modular<T>::normalize(x);
        return stream;
    }

    constexpr int md = 1e9 + 7;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}


using namespace Ment;



































using ld = long double;

using uint = unsigned int;
using ull = unsigned long long;

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxm = 1e6 + 100, maxw = 1e7 + 10, inf = 1e9 + 100, LG = 18, SQ = 300;

void precalc() {}

struct item {
    ll w = 0, u = 0;
    template<typename T>
    void init(const T &t, int l, int r) {
        w = t;
        u = 0;
    }

    void update(const item &first, const item &second, int l, int r) {
        w = first.w + second.w;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  

        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        w += m * (ll)(r - l + 1);
        u += m;
    }

    void push(item &first, item &second, int l, int r) {
         int m = (l + r) / 2;
         first.modify(u, l, m);
         second.modify(u, m + 1, r);
         u = 0;
    }
};

struct id0 {
    vector<item> tree;
    int n = 1;

    id0(int n = 1) : n(n) {
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
    }

    template<typename T>
    id0(const vector<T>& v) {
        build(v);
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
        tree.assign(1 << (__lg(max(1, n - 1)) + 2), item());
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
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
            if (l != r) {
                tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
            }
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

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        if (l == vl && r == vr) {
            tree[i].modify(modifier, vl, vr);
            return;
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            modify(l, r, modifier, i * 2 + 1, vl, m);
        } else if (m < l) {
            modify(l, r, modifier, i * 2 + 2, m + 1, vr);
        } else {
            modify(l, m, modifier, i * 2 + 1, vl, m);
            modify(m + 1, r, modifier, i * 2 + 2, m + 1, vr);
        }
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
    }

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }
};

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct SparseTable {
    vector<vector<T>> table;
    vector<int> p2;
    F combine;

    SparseTable(int n, F combine) : combine(combine) {
        while ((1 << table.size()) <= n || table.empty())
            table.emplace_back(n);
    }
    template<typename U>
    SparseTable(const vector<U>& v, F combine) : SparseTable<T>(v.size(), combine) {
        table[0].assign(v.begin(), v.end());
        build();
    }

    void build() {
        p2.resize(table[0].size() + 1);
        for (int i = 2; i < p2.size(); ++i)
            p2[i] = p2[i / 2] + 1;
        for (int i = 1; i < table.size(); ++i) {
            for (int j = 0; j + (1 << i) <= table[i].size(); ++j) {
                table[i][j] = combine(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T ask(int l, int r) {
        int ln = p2[r - l + 1];
        if (r - l + 1 == ln) return table[ln][l];
        return combine(table[ln][l], table[ln][r - (1 << ln) + 1]);
    }
};

int a[maxn], pa[maxn];


int mxx(int const &x, int const &y) {
    return max(x, y);
}

vector<pair<int, int>> ques[maxn];

void solve() {
    int n, zaps;
    n = 2e5;
    zaps = 1e6;
        cin >> n >> zaps;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        cin >> a[i];
        pa[a[i]] = i;
    }
    for (int i = 0; i < zaps; i++) {
        int l, r;
        l = rnd() % n + 1;
        r = rnd() % n + 1;
        if (l > r)
            swap(l, r);
        cin >> l >> r;
        l--;
        r--;
        ques[r].emplace_back(l, i);
    }
    SparseTable<int> t(vector<int>(a, a + n), mxx);










    vector<int> les(n, -1);
    for (int x = 1; x <= n; x++)
        for (int y = x + 1; y * (ll)x <= n; y++) {
            int l = pa[x], r = pa[y];
            if (l > r)
                swap(l, r);
            int m = pa[x * y];
            if (m > r)
                setmax(les[m], l);
        }
    vector<ll> ans(zaps);
    id0 A(n), D(n);
    int ind = 0;
    auto upd = [&](int l, int r, int w) {


        if (l > r)
            return;
        A.modify(l, r, w);
        D.modify(l, r, -w * (ll)ind);
    };
    vector<int> hist(n);
    auto get = [&](int l, int r) {








        return A.ask(l, r).w * ind + D.ask(l, r).w;
    };
    vector<int> to(n, -1);
    vector<int> pos;
    vector<int> opos(n, -1);
    

    pos.emplace_back(-1);
    

    for (int i = 0; i < n; i++) {
        while (pos.size() > 1) {
            int id = pos.back();
            if (a[id] > a[i])
                break;
            opos[id] = -1;
            pos.pop_back();
            upd(pos.back() + 1, to[id], -1);
        }
        opos[i] = pos.size();
        to[i] = pos.back();
        pos.emplace_back(i);
        {
            if (les[i] > to[i]) {
                upd(to[i] + 1, les[i], 1);
                to[i] = les[i];
            }
        }
        int x = a[i];
        for (int y = 1; x * y <= n; y++) {
            if (pa[y] < i) {
                int m = pa[x * y];
                if (opos[m] == -1)
                    continue;
                int r = min(pa[y], m);
                int l = to[m] + 1;
                if (r >= l) {
                    to[m] = r;
                    upd(l, r, 1);
                }
            }
        }
        ind++;




        for (auto [l, id] : ques[i]) {
            ans[id] = get(l, i);
        }


    }
    for (auto i : ans)
        cout << i << '\n';
}



int main() {

    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    precalc();
    if (0) {
        int te = 0;
        while (1) {
            cerr << "ts " << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;


    for (int its = 1; its <= ts; its++) {




        solve();


    }
    cerr << "\n\nConsumed " << TIME << '\n';
    return 0;
}