
#ifndef ONPC


#endif





























#include <bits/stdc++.h>

#ifdef ONPC
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define m_p make_pair
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define popcnt(x) __builtin_popcount(x)
#define shuffle(a) shuffle(a.begin(), a.end(), rnd)

#include <ext/pb_ds/assoc_container.hpp>




using namespace std;

template<typename T>
using inverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;



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
mt19937 rnd(224);
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

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

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

    constexpr int md = 998244353;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}


using namespace Ment;



































using ld = double;

using uint = unsigned int;
using ull = unsigned long long;

const ll llinf = 2e18 + 100;

const int maxn = 3e5 + 100, maxw = 5e6 + 10, inf = 1e9 + 100, LG = 20, SQ = 300;

void precalc() {}

struct Node {
    int s[2] = {0, 0};
    int t[2] = {-1, -1};
    int x1 = 0;

    void update(Node &A, Node &B) {
        x1 = B.x1;
        for (int i = 0; i < 2; i++) {
            int j = (A.x1 == B.t[i]);
            s[i] = B.s[i] + A.s[j];
            t[i] = A.t[j];
        }
    }
};

struct Str {
    vector<Node> q;

    int s;

    void update(int v) {
        q[v].update(q[2 * v], q[2 * v + 1]);
    }

    void upd(int v, Node const &w) {
        

        assert(v < s);
        v += s;
        q[v] = w;
        v /= 2;
        while (v) {
            update(v);
            v /= 2;
        }
        

    }

    void init(int n) {
        s = 1;
        while (s < n)
            s *= 2;
        q.resize(2 * s);
        for (int i = s - 1; i > 0; i--)
            update(i);
    }

    Node get() {
        return q[1];
    }
};

int n;

vector<int> e[maxn];

int p[maxn];

int sz[maxn];

void prec(int v, int par) {
    p[v] = par;
    sz[v] = 1;
    if (e[v].empty())
        return;
    for (int i : e[v])
        if (i != par) {
            prec(i, v);
            sz[v] += sz[i];
        }
    int id = 0;
    for (int i = 1; i < e[v].size(); i++)
        if (sz[e[v][id]] < sz[e[v][i]])
            id = i;
    swap(e[v][0], e[v][id]);
}

Str tree[maxn];

int hid[maxn], hpar[maxn], hsz[maxn];

int cnt[maxn][LG];

int mas[maxn][2];

int who[maxn];

int ans;

void upd(int v) {
    Node s;
    int x1 = -1, x2 = -1;
    for (int i = 0; ; i++)
        if (cnt[v][i] == 0) {
            if (x1 == -1) {
                x1 = i;
            } else {
                x2 = i;
                break;
            }
        }
    s.x1 = x1;
    

    s.t[0] = x1;
    s.s[0] = x1;
    

    s.t[1] = x2;
    s.s[1] = x2;
    ans -= tree[hpar[v]].get().s[0];
    tree[hpar[v]].upd(hid[v], s);
    ans += tree[hpar[v]].get().s[0];
}

void dfs(int v) {
    hid[v] = hsz[hpar[v]]++;
    

    if (e[v].empty()) {
        tree[hpar[v]].init(hsz[hpar[v]]);
        return;
    }
    hpar[e[v][0]] = hpar[v];
    dfs(e[v][0]);
    for (int i = 1; i < e[v].size(); i++) {
        hpar[e[v][i]] = e[v][i];
        dfs(e[v][i]);
    }
}

void solve() {
    cin >> n;
    n++;
    for (int i = 1; i < n; i++) {
        int pr;
        cin >> pr;
        pr--;
        e[pr].emplace_back(i);
    }
    prec(0, 0);
    dfs(0);
    upd(0);
    for (int it = 1; it < n; it++) {
        int v = it;
        while (1) {
            int u = hpar[v];
            int old = tree[u].get().t[0];
            upd(v);
            if (u == 0)
                break;
            int nw = tree[u].get().t[0];
            u = p[u];
            cnt[u][old]--;
            cnt[u][nw]++;
            v = u;
        }
        cout << ans << '\n';
    }
}



int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
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
        cerr << "\nts " << its << "/" << ts << '\n';


        solve();
        cerr << "\n\nConsumed " << TIME << '\n';
    }
    cerr << "\n\nConsumed " << TIME << '\n';
    return 0;
}
