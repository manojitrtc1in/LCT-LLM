
































































using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }

    static Type inverse(Type a, Type mod) {
        Type b = mod, x = 0, y = 1;
        while (a != 0) {
            Type t = b / a;
            b -= a * t;
            x -= t * y;
            swap(a, b);
            swap(x, y);
        }
        if (x < 0)
            x += mod;
        return x;
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

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
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

    template <typename U>
    friend const Modular<U>& abs(const Modular<U>& v) { return v; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
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

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

const int md = 1e9 + 7;

using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

ll sqr(ll x) {
    return x * x;
}

int mysqrt(ll x) {
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m * (ll) m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}


mt19937 rnd(513);
mt19937_64 rndll(231);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());


template<typename T>
T gcd(T a, T b) {
    return a ? gcd(b % a, a) : b;
}

int id0(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = id0(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

void setmin(int &x, int y) {
    x = min(x, y);
}

void setmax(int &x, int y) {
    x = max(x, y);
}

void setmin(ll &x, ll y) {
    x = min(x, y);
}

void setmax(ll &x, ll y) {
    x = max(x, y);
}

const ll llinf = 4e18 + 100;

const double eps = 1e-12, PI = atan2(0, -1);

const int maxn = 5e5 + 100, maxw = 1e6 + 1111, inf = 1e9 + 100, sq = 450, LG = 18, mod = 1e9 + 933, mod1 = 1e9 + 993;



using namespace __gnu_pbds;

int main() {

    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    

    



    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> d(n);
        vector<vector<int>> e(n);

        unordered_set<ll> table;

        for (int i = 0; i < m; i++) {
            int v, u;
            cin >> v >> u;
            v--;
            u--;
            d[v]++;
            d[u]++;
            e[v].push_back(u);
            e[u].push_back(v);
            if (v > u)
                swap(v, u);
            table.insert(v * (ll)n + u);
        }

        if (k == 1) {
            cout << "2 1\n";
            continue;
        }
        set<pair<int, int>> g;
        for (int i = 0; i < n; i++) {
            g.insert({d[i], i});
            sort(e[i].begin(), e[i].end());
        }
        bool ez = 0;
        while (!g.empty()) {
            int it = g.begin()->sc;
            if (d[it] >= k)
                break;
            if (d[it] == k - 1) {
                vector<int> q;
                for (int i : e[it])
                    if (d[i] != 0)
                        q.push_back(i);
                q.push_back(it);
                ez = 1;
                for (int i : q) {
                    for (int j : q)
                        if (j > i && table.find(i * (ll) n + j) == table.end()) {
                            ez = 0;
                            break;
                        }
                    if (!ez)
                        break;
                }
                if (ez) {
                    cout << 2 << '\n';
                    for (int i : q)
                        cout << i + 1 << ' ';
                    cout << '\n';
                    break;
                }
            }
            g.erase(g.begin());
            d[it] = 0;
            for (int i : e[it])
                if (d[i] > 0) {
                    g.erase({d[i], i});
                    d[i]--;
                    g.insert({d[i], i});
                }
        }
        if (ez)
            continue;
        if (g.empty())
            cout << -1 << '\n';
        else if (g.size() == k) {
            cout << 2 << '\n';
            for (auto it : g)
                cout << it.sc + 1 << ' ';
            cout << '\n';
        } else {
            assert(g.size() > k);
            cout << 1 << ' ' << g.size() << '\n';
            for (auto it : g)
                cout << it.sc + 1 << ' ';
            cout << '\n';
        }
    }
}