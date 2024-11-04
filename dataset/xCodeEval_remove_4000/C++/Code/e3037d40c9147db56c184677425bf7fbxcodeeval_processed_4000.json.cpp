






































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

    constexpr int md = 998244353;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}


using Ment::Mint;














using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, maxw = (1 << 20) + 5, inf = 1e9 + 100, LG = 18;



int shag[maxn];

int n;

void fix(int id, bool w) {
    id = n + 1 - id;
    if (w)
        shag[id >> 5] |= (1u << (id & 31));
    else
        shag[id >> 5] &= ~(1u << (id & 31));
    return;
}

int flag[maxn];

void update(int l, int r, bool w) {
    cerr << "ok " << l << ' ' << r << ' ' << w << '\n';
    if (l > r)
        return;
    l = n + 1 - l;
    r = n + 1 - r;
    swap(l, r);
    while (l <= r && (l & 31) != 0) {
        if (w)
            flag[l >> 5] |= (1u << (l & 31));
        else
            flag[l >> 5] &= ~(1u << (l & 31));
        l++;
    }
    while (l <= r && (r & 31) != 31) {
        if (w)
            flag[r >> 5] |= (1u << (r & 31));
        else
            flag[r >> 5] &= ~(1u << (r & 31));
        r--;
    }
    if (w)
        w = -1;
    if (l > r)
        return;
    l >>= 5;
    r >>= 5;
    while (l <= r && (l & 7) != 0) {
        flag[l] = w;
        l++;
    }
    while (l <= r && (r & 7) != 7) {
        flag[r] = w;
        r--;
    }
    if (l > r)
        return;

    __m256i ones = _mm256_set1_epi32(w);
    for (int i = l; i < r; i += 8) {
        _mm256_store_si256((__m256i*) &flag[i], ones);
    }
}

bitset<maxn> res;



void solve() {
    n = 1e5;
    cin >> n;
    string ul = "unlock", lk = "lock";
    vector<string> arr(n + 2);
    arr[0] = ul;
    arr.back() = lk;
    set<int> g;
    g.insert(0);
    g.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = lk;
        cin >> arr[i];
        if (arr[i] == ul || arr[i] == lk)
            g.insert(i);
        else
            fix(i, 1);
    }
    for (auto i : g) {
        if (arr[i] == ul) {
            int j = *g.lower_bound(i + 1);
            update(i, j - 1, 1);
        }
    }
    auto print = [&]() {
        int i = -1;
        {
            for (int i = 0; i <= n + 1; i++)
                cerr << (shag[i >> 5] & (1u << (i & 31))) << ' ';
            cerr << '\n';
            for (int i = 0; i <= n + 1; i++)
                cerr << (flag[i >> 5] & (1u << (i & 31))) << ' ';
            cerr << "\n\n";
            

            __m256i res, z, x, y, zeros = _mm256_setzero_si256();
            for (int j = 0; j * 32 <= n + 1; j += 8) {
                x = _mm256_load_si256((__m256i*) &shag[j]);
                y = _mm256_load_si256((__m256i*) &flag[j]);
                z = _mm256_and_si256(x, y);
                res = _mm256_cmpeq_epi16(z, zeros);
                if (_mm256_movemask_epi8(res) != -1) {
                    i = j;
                    break;
                }
            }
        }
        if (i != -1) {
            for (int j = i; j < i + 8; j++)
                if ((shag[j] & flag[j]) != 0) {
                    i = j;
                    break;
                }
            int ld = __builtin_ctz(shag[i] & flag[i]);
            assert(ld != 32);
            i = i * 32 + ld;
        }
        cerr << i << '\n';
        if (i != -1)
            i = n + 1 - i;
        if (i == -1)
            cout << "blue\n";
        else
            cout << arr[i] << '\n';
    };
    print();
    int tss;
    tss = n;
    cin >> tss;
    while (tss--) {
        int i;
        string s;
        i = n;
        s = lk;
        cin >> i >> s;
        if (arr[i] == ul || arr[i] == lk) {
            auto it = g.lower_bound(i);
            int r = *next(it);
            int l = *prev(it);
            if (arr[i] == ul) {
                update(i, r - 1, 0);
            }
            if (arr[l] == ul) {
                update(i, r - 1, 1);
            }
            g.erase(it);
        } else {
            fix(i, 0);
        }
        arr[i] = s;
        if (arr[i] == ul || arr[i] == lk) {
            g.insert(i);
            auto it = g.lower_bound(i);
            int r = *next(it);
            int l = *prev(it);
            if (arr[l] == ul) {
                update(i, r - 1, 0);
            }
            if (arr[i] == ul) {
                update(i, r - 1, 1);
            }
        } else {
            fix(i, 1);
        }
        print();
    }
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