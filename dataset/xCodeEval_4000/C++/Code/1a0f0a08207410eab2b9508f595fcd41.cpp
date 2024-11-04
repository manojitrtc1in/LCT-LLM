






















#include <bits/stdc++.h>
#ifdef ONPC
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define popcnt(x) __builtin_popcount(x)
#define shuffle(a) shuffle(a.begin(), a.end(), rnd)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;



using ll = long long;

#ifndef ONPC
#define cerr cerr_maksim
struct Cerr : public ostream {
    template<typename T>
    Cerr& operator<<(T const&) {
        return *this;
    }
} cerr;
#endif

#ifdef ONPC
mt19937 rnd(223);
mt19937_64 rndll(231);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


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
#ifdef _WIN32
            uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
            uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
            asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
            );
            value = m;
#else
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
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

    constexpr int md = 998244353;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}


using Ment::Mint;


#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)











using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, maxw = (1 << 20) + 5, inf = 1e9 + 100, LG = 18;

int rig[4 * maxn], q[4 * maxn], up[4 * maxn], col[maxn];

void build(int v, int l, int r) {
    up[v] = rig[v] = q[v] = -1;
    if (l == r) {
        col[l] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
}

void push(int v, int l, int r) {
    if (up[v] != -1) {
        if (l != r) {
            up[2 * v] = up[v];
            up[2 * v + 1] = up[v];
        } else {
            col[l] = up[v];
        }
        if (up[v] == 0) {
            q[v] = -1;
        } else {
            q[v] = rig[v];
        }
        up[v] = -1;
    }
}

void fix(int v, int l, int r, int id, int w) {
    push(v, l, r);
    if (l == r) {
        rig[v] = (w == 1 ? l : -1);
        q[v] = (col[l] == 1 ? rig[v] : -1);
        return;
    }
    int m = (l + r) / 2;
    if (id <= m) {
        fix(2 * v, l, m, id, w);
        push(2 * v + 1, m + 1, r);
    } else {
        fix(2 * v + 1, m + 1, r, id, w);
        push(2 * v, l, m);
    }
    rig[v] = max(rig[2 * v], rig[2 * v + 1]);
    q[v] = max(q[2 * v], q[2 * v + 1]);
}

void update(int v, int tl, int tr, int l, int r, int w) {
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r) {
        up[v] = w;
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, l, min(r, m), w);
    update(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
    

    q[v] = max(q[2 * v], q[2 * v + 1]);
}



void solve() {
    int n;
    cin >> n;
    build(1, 0, n);
    string ul = "unlock", lk = "lock";
    vector<string> arr(n + 2);
    arr[0] = ul;
    arr.back() = lk;
    set<int> g;
    g.insert(0);
    g.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == ul || arr[i] == lk)
            g.insert(i);
        else
            fix(1, 0, n, i, 1);
    }
    for (auto i : g) {
        if (arr[i] == ul) {
            int j = *g.lower_bound(i + 1);
            update(1, 0, n, i, j - 1, 1);
        }
    }
    auto print = [&]() {
        int i = q[1];
        if (i == -1)
            cout << "blue\n";
        else
            cout << arr[i] << '\n';
    };
    print();
    int tss;
    cin >> tss;
    while (tss--) {
        int i;
        string s;
        cin >> i >> s;
        if (arr[i] == ul || arr[i] == lk) {
            auto it = g.lower_bound(i);
            int r = *next(it);
            int l = *prev(it);
            if (arr[i] == ul) {
                update(1, 0, n, i, r - 1, 0);
            }
            if (arr[l] == ul) {
                update(1, 0, n, i, r - 1, 1);
            }
            g.erase(it);
        } else {
            fix(1, 0, n, i, 0);
        }
        arr[i] = s;
        if (arr[i] == ul || arr[i] == lk) {
            g.insert(i);
            auto it = g.lower_bound(i);
            int r = *next(it);
            int l = *prev(it);
            if (arr[l] == ul) {
                update(1, 0, n, i, r - 1, 0);
            }
            if (arr[i] == ul) {
                update(1, 0, n, i, r - 1, 1);
            }
        } else {
            fix(1, 0, n, i, 1);
        }
        print();
    }
}




int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
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
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}