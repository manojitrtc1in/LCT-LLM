






































using namespace __gnu_pbds;

using namespace std;



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
            if ((value += other.value) >= mod()) value -= mod();
            return *this;
        }

        Modular &operator-=(const Modular &other) {
            if ((value -= other.value) < 0) value += mod();
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
    Modular<T> power(const Modular<T> &a, const U &b) {
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
using Ment::Mint;














using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, maxw = (1 << 20) + 5, inf = 1e9 + 100;
struct Val {
    ll v;
    Val() : v(0) {}
    Val(ll x) : v(x) {}

    friend Val operator+(Val a, Val b);

    Val& operator+=(Val a) {
        return *this = *this + a;
    }
};

Val operator+(Val a, Val b) {
    return Val(a.v + b.v);
}

bool operator==(Val a, Val b) {
    return a.v == b.v;
}

bool operator!=(Val a, Val b) {
    return !(a == b);
}

struct Segtree {

    static Val calc(Val a, Val b) {
        return min(a.v, b.v);
    }

    Val q[4 * maxn], up[4 * maxn];
    int n;

    void build(int v, int l, int r, vector<ll> &who) {
        up[v] = 0;
        if (l == r) {
            q[v] = who[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, who);
        build(2 * v + 1, m + 1, r, who);
        q[v] = calc(q[2 * v], q[2 * v + 1]);
    }
    void build(int n_, vector<ll> &who) {
        n = n_;
        build(1, 0, n - 1, who);
    }

    void push(int v, int l, int r) {
        if (up[v] != Val(0)) {
            q[v] += up[v];
            if (l != r) {
                up[2 * v] += up[v];
                up[2 * v + 1] += up[v];
            }
            up[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, Val w) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (tl == l && tr == r) {
            up[v] += w;
            push(v, tl, tr);
            return;
        }
        int m = (tl + tr) / 2;
        update(2 * v, tl, m, l, min(r, m), w);
        update(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
        q[v] = calc(q[2 * v], q[2 * v + 1]);
    }

    void update(int l, int r, ll w) {
        update(1, 0, n - 1, l, r, w);
    }

    Val get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r)
            return llinf;
        if (tl == l && tr == r)
            return q[v];
        int m = (tl + tr) / 2;
        return calc(get(2 * v, tl, m, l, min(r, m)),
                    get(2 * v + 1, m + 1, tr, max(l, m + 1), r));
    }

    Val get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }

};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<ll> dp(n + 1);

    vector<int> nxt(n), prev(n);
    {
        map<int, int> go;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            if (!go.count(x))
                nxt[i] = n;
            else
                nxt[i] = go[x];
            go[x] = i;
        }
        go.clear();
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (!go.count(x))
                prev[i] = -1;
            else
                prev[i] = go[x];
            go[x] = i;
        }
    }
    for (int iter = 0; iter < k; iter++) {
        Segtree q;
        q.build(n + 1, dp);
        

        vector<ll> pd(n + 1);
        for (int i = 0; i <= n; i++) {
            pd[i] = q.get(0, i - 1).v;
            if (i < n) {
                if (prev[i] != -1) {
                    q.update(0, prev[i], (i - prev[i]));
                }
                if (nxt[i] != n) {
                    q.update(0, i, -(nxt[i] - i));
                }
            }
        }
        swap(dp, pd);
        

        

        

    }
    ll tot = 0;
    map<int, int> q;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (q.find(x) != q.end()) {
            tot += i - q[x];
        }
        q[x] = i;
    }
    cout << tot + dp.back() << '\n';
}




int main() {

    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(20);
    

    if (false) {
        int te = 0;
        while (1) {
            cerr << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
    

    for (int its = 1; its <= ts; its++) {
        

        

        solve();
    }

    cerr << "\n\nConsumed " << TIME << '\n';

}