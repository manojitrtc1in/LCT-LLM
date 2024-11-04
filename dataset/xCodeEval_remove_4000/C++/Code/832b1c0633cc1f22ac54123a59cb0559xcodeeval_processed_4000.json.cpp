
































using namespace std;







typedef long long ll;
typedef unsigned long long ull;
template<typename T>void __read(T &a) { cin >> a; }
template<typename T, typename ... Args> void __read(T &a, Args &... args) { cin >> a;__read(args...);}




typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
constexpr ll M7 = 1000000007;
constexpr ll M9 = 1000000009;
constexpr ll MFFT = 998244353;
template<class T> void outv(const T &a, string d = " ", bool nl = false) { for (auto &x : a) cout << x << d; if (nl) cout << '\n'; }
template<class T> void outv(const T &a, char d, bool nl = false) { for (auto &x : a) cout << x << d; if (nl) cout << '\n'; }
static mt19937_64 rnd(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count())); 

auto id1 = (ios_base::sync_with_stdio(false), cin.tie(nullptr)); 






enum fft_type {
    cmplx, mfft, mod
};

template<class T, fft_type type>
struct fourier {
    int32_t N;
    int32_t LOG;
    vector<T> w;
    vector<int32_t> inv;

    explicit fourier(int32_t lg) {
        assert(lg > 0);
        LOG = lg;
        N = 1 << lg;
        inv.resize(N);
        iota(inv.begin(), inv.end(), 0);
        for (int32_t i = 1; i < N; ++i) {
            if (inv[i] & 1) {
                inv[i] = inv[i - 1] | (1 << (LOG - 1));
            } else {
                inv[i] = inv[i >> 1] >> 1;
            }
        }
        w.resize(N);

        if constexpr (type == fft_type::cmplx) {
            for (int32_t i = 0; i < N; ++i) {
                double alpha = 2 * 3.14159265358979323846 * i / N;
                w[i] = T(cos(alpha), sin(alpha));
            }
        }
        if constexpr (type == fft_type::mfft) {
            w[0] = 1;
            w[1] = 15311432;
            for (int32_t i = lg; i < 23; ++i) {
                w[1] *= w[1];
            }
            for (int32_t i = 2; i < N; ++i) {
                w[i] = w[i - 1] * w[1];
            }
        }
        if constexpr (type == fft_type::mod) {
            w[0] = 1;
            for (w[1] = 2;; ++w[1]) {
                T r = w[1];
                for (int i = 1; i < LOG; ++i) {
                    r *= r;
                }
                if (r != 1 && r * r == 1) {
                    break;
                }
            }
        }
    }

    void transform(vector<T> &a) {
        int32_t n = a.size();
        assert((n & (n - 1)) == 0);
        int32_t log = 31 - __builtin_clz(n);
        for (int32_t i = 0; i < n; ++i) {
            int ii = inv[i] >> (LOG - log);
            if (ii < i) {
                swap(a[i], a[ii]);
            }
        }
        for (int32_t l = 0; l < log; l++) {
            int32_t len = 1 << l;
            for (int32_t i = 0; i < n; i += 2 * len) {
                for (int32_t j = 0; j < len; ++j) {
                    T v = a[i + j], u = a[i + j + len] * w[j << (LOG - l - 1)];
                    a[i + j] = v + u;
                    a[i + j + len] = v - u;
                }
            }
        }
    }

    void invTransform(vector<T> &a) {
        int32_t n = a.size();
        transform(a);
        reverse(a.begin() + 1, a.end());
        if constexpr (type == fft_type::cmplx) {
            for (auto &v : a) {
                v /= n;
            }
        } else {
            T invN = T(n).inverse();
            for (auto &v : a) {
                v *= invN;
            }
        }

    }

    template<class U>
    vector<U> convolution(const vector<U> &a, const vector<U> &b) {
        int32_t m = a.size() + b.size() - 1;
        int sz = 1;
        while (sz < m) {
            sz *= 2;
        }
        vector<T> f1(sz), f2(sz);
        for (int32_t i = 0; i < a.size(); ++i) {
            f1[i] = T(a[i]);
        }
        for (int32_t i = 0; i < b.size(); ++i) {
            f2[i] = T(b[i]);
        }
        transform(f1);
        transform(f2);
        for (int32_t i = 0; i < sz; ++i) {
            f1[i] *= f2[i];
        }
        invTransform(f1);
        if constexpr (is_same_v<T, U>) {
            f1.resize(m);
            return f1;
        }
        vector<U> res(m);
        if constexpr (type == fft_type::cmplx) {
            for (int32_t i = 0; i < m; ++i) {
                res[i] = round(f1[i].real());
            }
        } else {
            for (int32_t i = 0; i < m; ++i) {
                res[i] = f1[i]();
            }
        }
        return res;
    }

    template<class U>
    vector<U> id0(const vector<U> &a) {
        int32_t m = a.size() * 2 - 1;
        int sz = 1;
        while (sz < m) {
            sz *= 2;
        }
        vector<T> f1(sz);
        for (int32_t i = 0; i < a.size(); ++i) {
            f1[i] = T(a[i]);
        }
        transform(f1);
        for (int32_t i = 0; i < sz; ++i) {
            f1[i] *= f1[i];
        }
        invTransform(f1);
        if constexpr (is_same_v<T, U>) {
            f1.resize(m);
            return f1;
        }
        vector<U> res(m);
        if constexpr (type == fft_type::cmplx) {
            for (int32_t i = 0; i < m; ++i) {
                res[i] = round(f1[i].real());
            }
        } else {
            for (int32_t i = 0; i < m; ++i) {
                res[i] = f1[i]();
            }
        }
        return res;
    }

};
typedef complex<double> base;



template<int32_t MOD>
struct modular {

    template<class U>
    static modular fpow(const modular &a, const U &b) {
        assert(b >= 0);
        modular x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) {
                res *= x;
            }
            x *= x;
            p >>= 1;
        }
        return res;
    }

    int32_t value;

    constexpr modular() : value() {}

    template<typename U>
    modular(const U &x) {
        value = normalize(x);
    }

    template<typename U>
    static int32_t normalize(const U &x) {
        int32_t v;
        if (-MOD <= x && x < MOD) v = static_cast<int32_t>(x);
        else v = static_cast<int32_t>(x % MOD);
        if (v < 0) v += MOD;
        return v;
    }

    const int32_t &operator()() const {
        return value;
    }

    template<typename U>
    explicit operator U() const {
        return static_cast<U>(value);
    }

    constexpr static int32_t mod() {
        return MOD;
    }

    modular &operator+=(const modular &other) {
        value += other.value;
        if (value >= MOD) {
            value -= MOD;
        }
        return *this;
    }

    modular &operator-=(const modular &other) {
        value -= other.value;
        if (value < 0) {
            value += MOD;
        }
        return *this;
    }

    modular &operator++() {
        return *this += 1;
    }

    modular &operator--() {
        return *this -= 1;
    }

    const modular operator++(int32_t) {
        modular result(*this);
        *this += 1;
        return result;
    }

    const modular operator--(int32_t) {
        modular result(*this);
        *this -= 1;
        return result;
    }

    modular operator-() const {
        return modular(-value);
    }

    modular &operator*=(const modular &other) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(other));
        return *this;
    }

    modular inverse() const {
        return fpow(*this, MOD - 2);
    }

    modular &operator/=(const modular &other) {
        return *this *= modular(other.inverse());
    }

    static vector<modular<MOD>> inverse(int32_t n){
        vector<modular<MOD>> inv(n);
        inv[1] = 1;
        for(int32_t i = 2; i < n; ++i){
            inv[i] = - MOD / i * inv[MOD % i];
        }
        return inv;
    }

    static vector<modular<MOD>> factorial(int32_t n){
        vector<modular<MOD>> fact(n);
        fact[0] = 1;
        for(int32_t i = 1; i < n; ++i){
            fact[i] = fact[i - 1] * i;
        }
        return fact;
    }

    static vector<modular<MOD>> invFactorial(int32_t n){
        modular<MOD> f = 1;
        for(int32_t i = 2; i < n; ++i){
            f *= i;
        }
        vector<modular<MOD>> invFact(n);
        invFact[n - 1] = f.inverse();
        for(int32_t i = n - 2; i > 0; --i){
            invFact[i] = invFact[i + 1] * (i + 1);
        }
        return invFact;
    }

    template<int32_t MODU>
    friend bool operator==(const modular<MODU> &l, const modular<MODU> &r);

    template<int32_t MODU>
    friend bool operator<(const modular<MODU> &l, const modular<MODU> &r);

    template<int32_t MODU>
    friend std::istream &operator>>(std::istream &stream, modular<MODU> &number);
};

template<int32_t MOD>
bool operator==(const modular<MOD> &l, const modular<MOD> &r) {
    return l.value == r.value;
}

template<int32_t MOD, typename U>
bool operator==(const modular<MOD> &l, U r) {
    return l == modular<MOD>(r);
}

template<int32_t MOD, typename U>
bool operator==(U l, const modular<MOD> &r) {
    return modular<MOD>(l) == r;
}

template<int32_t MOD>
bool operator!=(const modular<MOD> &l, const modular<MOD> &r) {
    return l.value != r.value;
}

template<int32_t MOD, typename U>
bool operator!=(const modular<MOD> &l, U r) {
    return !(l == r);
}

template<int32_t MOD, typename U>
bool operator!=(U l, const modular<MOD> &r) {
    return !(l == r);
}

template<int32_t MOD>
bool operator<(const modular<MOD> &l, const modular<MOD> &r) {
    return l.value < r.value;
}

template<int32_t MOD>
modular<MOD> operator+(const modular<MOD> &l, const modular<MOD> &r) {
    return modular<MOD>(l) += r;
}

template<int32_t MOD, typename U>
modular<MOD> operator+(const modular<MOD> &l, U &r) {
    return modular<MOD>(l) += r;
}

template<int32_t MOD, typename U>
modular<MOD> operator+(U l, const modular<MOD> &r) {
    return modular<MOD>(l) += r;
}

template<int32_t MOD>
modular<MOD> operator-(const modular<MOD> &l, const modular<MOD> &r) {
    return modular<MOD>(l) -= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator-(const modular<MOD> &l, U r) {
    return modular<MOD>(l) -= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator-(U l, const modular<MOD> &r) {
    return modular<MOD>(l) -= r;
}

template<int32_t MOD>
modular<MOD> operator*(const modular<MOD> &l, const modular<MOD> &r) {
    return modular<MOD>(l) *= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator*(const modular<MOD> &l, U r) {
    return modular<MOD>(l) *= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator*(U l, const modular<MOD> &r) {
    return modular<MOD>(l) *= r;
}

template<int32_t MOD>
modular<MOD> operator/(const modular<MOD> &l, const modular<MOD> &r) {
    return modular<MOD>(l) /= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator/(const modular<MOD> &l, U r) {
    return modular<MOD>(l) /= r;
}

template<int32_t MOD, typename U>
modular<MOD> operator/(U l, const modular<MOD> &r) {
    return modular<MOD>(l) /= r;
}

template<int32_t MOD>
std::ostream &operator<<(std::ostream &stream, const modular<MOD> &number) {
    return stream << number();
}

template<int32_t MOD>
std::istream &operator>>(std::istream &stream, modular<MOD> &number) {
    int64_t x;
    stream >> x;
    number.value = modular<MOD>::normalize(x);
    return stream;
}

using mint = modular<MFFT>;



int32_t main() {
    fourier<mint, fft_type::mfft> fft(20);
    make(int, ttt);
    while (ttt--) {
        make(int, n);
        make(string, s);
        int N = 1;
        while (N < 2 * n) {
            N *= 2;
        }
        vector<mint> av(N), bv(N), ak(N), bk(N);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'V') {
                av[i] = 1;
                bv[n - i - 1] = 1;
            }
            if (s[i] == 'K') {
                ak[i] = 1;
                bk[n - i - 1] = 1;
            }
        }
        fft.transform(av);
        fft.transform(bv);
        fft.transform(ak);
        fft.transform(bk);
        for (int i = 0; i < N; ++i) {
            av[i] = (av[i] * bk[i] + ak[i] * bv[i]);
        }
        fft.invTransform(av);
        VI res(n + 1);
        for(int i = 0; i < n; ++i){
            res[n - i - 1] = av[i]();
        }
        VI ans;
        for(int i = 1; i + 1 <= n; ++i){
            for(int j = i; j <= n; j += i){
                res[i] += res[j];
            }
            if (res[i] == 0){
                ans.push_back(i);
            }
        }
        ans.push_back(n);
        cout << ans.size() << '\n';
        for(auto& i : ans){
            cout << i << ' ';
        }
        cout << '\n';

    }

    return 0;
}