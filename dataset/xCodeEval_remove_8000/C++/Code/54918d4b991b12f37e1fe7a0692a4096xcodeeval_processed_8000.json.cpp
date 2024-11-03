
using namespace std;


















namespace atcoder {

    namespace internal {

    

    

    constexpr long long safe_mod(long long x, long long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    

    

    

    struct barrett {
        unsigned int _m;
        unsigned long long im;

        

        explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

        

        unsigned int umod() const { return _m; }

        

        

        

        unsigned int mul(unsigned int a, unsigned int b) const {
            

            


            

            

            

            

            

            

            

            unsigned long long z = a;
            z *= b;
    
            unsigned long long x;
            _umul128(z, im, &x);
    
            unsigned long long x =
                (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
    
            unsigned int v = (unsigned int)(z - x * _m);
            if (_m <= v) v += _m;
            return v;
        }
    };

    

    

    

    constexpr long long id26(long long x, long long n, int m) {
        if (m == 1) return 0;
        unsigned int _m = (unsigned int)(m);
        unsigned long long r = 1;
        unsigned long long y = safe_mod(x, m);
        while (n) {
            if (n & 1) r = (r * y) % _m;
            y = (y * y) % _m;
            n >>= 1;
        }
        return r;
    }

    

    

    

    

    constexpr bool id24(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 7 || n == 61) return true;
        if (n % 2 == 0) return false;
        long long d = n - 1;
        while (d % 2 == 0) d /= 2;
        constexpr long long bases[3] = {2, 7, 61};
        for (long long a : bases) {
            long long t = d;
            long long y = id26(a, t, n);
            while (t != n - 1 && y != 1 && y != n - 1) {
                y = y * y % n;
                t <<= 1;
            }
            if (y != n - 1 && t % 2 == 0) {
                return false;
            }
        }
        return true;
    }
    template <int n> constexpr bool is_prime = id24(n);

    

    

    constexpr std::pair<long long, long long> id5(long long a, long long b) {
        a = safe_mod(a, b);
        if (a == 0) return {b, 0};

        

        

        

        

        long long s = b, t = a;
        long long m0 = 0, m1 = 1;

        while (t) {
            long long u = s / t;
            s -= t * u;
            m0 -= m1 * u;  


            

            

            

            


            auto tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        

        

        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }

    

    

    

    constexpr int id16(int m) {
        if (m == 2) return 1;
        if (m == 167772161) return 3;
        if (m == 469762049) return 3;
        if (m == 754974721) return 11;
        if (m == 998244353) return 3;
        int divs[20] = {};
        divs[0] = 2;
        int cnt = 1;
        int x = (m - 1) / 2;
        while (x % 2 == 0) x /= 2;
        for (int i = 3; (long long)(i)*i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; g++) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (id26(g, (m - 1) / divs[i], m) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return g;
        }
    }
    template <int m> constexpr int primitive_root = id16(m);

    

    

    

    unsigned long long id2(unsigned long long n,
                                        unsigned long long m,
                                        unsigned long long a,
                                        unsigned long long b) {
        unsigned long long ans = 0;
        while (true) {
            if (a >= m) {
                ans += n * (n - 1) / 2 * (a / m);
                a %= m;
            }
            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            unsigned long long y_max = a * n + b;
            if (y_max < m) break;
            

            

            n = (unsigned long long)(y_max / m);
            b = (unsigned long long)(y_max % m);
            std::swap(m, a);
        }
        return ans;
    }

    }  


}  

namespace atcoder {

    namespace internal {

    
    template <class T>
    using is_signed_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value ||
                                    std::is_same<T, __int128>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using is_unsigned_int128 =
        typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                    std::is_same<T, unsigned __int128>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using make_unsigned_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value,
                                __uint128_t,
                                unsigned __int128>;

    template <class T>
    using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                    is_signed_int128<T>::value ||
                                                    is_unsigned_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

    template <class T>
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                    std::is_signed<T>::value) ||
                                                        is_signed_int128<T>::value,
                                                    std::true_type,
                                                    std::false_type>::type;

    template <class T>
    using is_unsigned_int =
        typename std::conditional<(is_integral<T>::value &&
                                std::is_unsigned<T>::value) ||
                                    is_unsigned_int128<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using to_unsigned = typename std::conditional<
        is_signed_int128<T>::value,
        make_unsigned_int128<T>,
        typename std::conditional<std::is_signed<T>::value,
                                std::make_unsigned<T>,
                                std::common_type<T>>::type>::type;

    

    template <class T> using is_integral = typename std::is_integral<T>;

    template <class T>
    using is_signed_int =
        typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using is_unsigned_int =
        typename std::conditional<is_integral<T>::value &&
                                    std::is_unsigned<T>::value,
                                std::true_type,
                                std::false_type>::type;

    template <class T>
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                                std::make_unsigned<T>,
                                                std::common_type<T>>::type;

    

    template <class T>
    using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

    template <class T>
    using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

    template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

    }  


}  

namespace atcoder {

    namespace internal {

    

    

    int id8(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

    

    

    constexpr int id9(unsigned int n) {
        int x = 0;
        while (!(n & (1 << x))) x++;
        return x;
    }

    

    

    int bsf(unsigned int n) {
    
        unsigned long index;
        _BitScanForward(&index, n);
        return index;
    
        return __builtin_ctz(n);
    
    }

    }  


}  




namespace atcoder {

    namespace internal {

        struct modint_base {};
        struct static_modint_base : modint_base {};

        template <class T> using is_modint = std::is_base_of<modint_base, T>;
        template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

    }  


    template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct id23 : internal::static_modint_base {
        using mint = id23;

    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        id23() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id23(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id23(T v) {
            _v = (unsigned int)(v % umod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v -= rhs._v;
            if (_v >= umod()) _v += umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int)(z % umod());
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            if (prime) {
                assert(_v);
                return pow(umod() - 2);
            } else {
                auto eg = internal::id5(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        friend constexpr ostream &operator<<(ostream& os,const mint &x) noexcept{
            return os<<(x._v);
        }
        friend constexpr istream &operator>>(istream& is,mint& x) noexcept{
            uint64_t t;
            is>>t,x=mint(t);
            return is;
        }

    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };


    template <int id> struct id22 : internal::modint_base {
        using mint = id22;

    public:
        static int mod() { return (int)(bt.umod()); }
        static void set_mod(int m) {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }

        id22() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id22(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id22(T v) {
            _v = (unsigned int)(v % mod());
        }

        unsigned int val() const { return _v; }

        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }

        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v += mod() - rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            auto eg = internal::id5(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }

        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        friend constexpr ostream &operator<<(ostream& os,const mint &x) noexcept{
            return os<<(x._v);
        }
        friend constexpr istream &operator>>(istream& is,mint& x) noexcept{
            uint64_t t;
            is>>t,x=mint(t);
            return is;
        }

    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id> internal::barrett id22<id>::bt(998244353);

    using modint = id22<-1>;

    namespace internal {

    template <class T>
    using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

    template <class T>
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

    template <class> struct is_dynamic_modint : public std::false_type {};
    template <int id>
    struct is_dynamic_modint<id22<id>> : public std::true_type {};

    template <class T>
    using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

    }  


}  




namespace atcoder {

    namespace internal {

    template <class mint,
            int g = internal::primitive_root<mint::mod()>,
            internal::is_static_modint_t<mint>* = nullptr>
    struct fft_info {
        static constexpr int rank2 = id9(mint::mod() - 1);
        std::array<mint, rank2 + 1> root;   

        std::array<mint, rank2 + 1> iroot;  


        std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
        std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

        std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
        std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

        fft_info() {
            root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
            iroot[rank2] = root[rank2].inv();
            for (int i = rank2 - 1; i >= 0; i--) {
                root[i] = root[i + 1] * root[i + 1];
                iroot[i] = iroot[i + 1] * iroot[i + 1];
            }

            {
                mint prod = 1, iprod = 1;
                for (int i = 0; i <= rank2 - 2; i++) {
                    rate2[i] = root[i + 2] * prod;
                    irate2[i] = iroot[i + 2] * iprod;
                    prod *= iroot[i + 2];
                    iprod *= root[i + 2];
                }
            }
            {
                mint prod = 1, iprod = 1;
                for (int i = 0; i <= rank2 - 3; i++) {
                    rate3[i] = root[i + 3] * prod;
                    irate3[i] = iroot[i + 3] * iprod;
                    prod *= iroot[i + 3];
                    iprod *= root[i + 3];
                }
            }
        }
    };

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    void id6(std::vector<mint>& a) {
        int n = int(a.size());
        int h = internal::id8(n);

        static const fft_info<mint> info;

        int len = 0;  

        while (len < h) {
            if (h - len == 1) {
                int p = 1 << (h - len - 1);
                mint rot = 1;
                for (int s = 0; s < (1 << len); s++) {
                    int offset = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p] * rot;
                        a[i + offset] = l + r;
                        a[i + offset + p] = l - r;
                    }
                    if (s + 1 != (1 << len))
                        rot *= info.rate2[bsf(~(unsigned int)(s))];
                }
                len++;
            } else {
                

                int p = 1 << (h - len - 2);
                mint rot = 1, imag = info.root[2];
                for (int s = 0; s < (1 << len); s++) {
                    mint rot2 = rot * rot;
                    mint rot3 = rot2 * rot;
                    int offset = s << (h - len);
                    for (int i = 0; i < p; i++) {
                        auto mod2 = 1ULL * mint::mod() * mint::mod();
                        auto a0 = 1ULL * a[i + offset].val();
                        auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                        auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                        auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                        auto id12 =
                            1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                        auto na2 = mod2 - a2;
                        a[i + offset] = a0 + a2 + a1 + a3;
                        a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                        a[i + offset + 2 * p] = a0 + na2 + id12;
                        a[i + offset + 3 * p] = a0 + na2 + (mod2 - id12);
                    }
                    if (s + 1 != (1 << len))
                        rot *= info.rate3[bsf(~(unsigned int)(s))];
                }
                len += 2;
            }
        }
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    void id20(std::vector<mint>& a) {
        int n = int(a.size());
        int h = internal::id8(n);

        static const fft_info<mint> info;

        int len = h;  

        while (len) {
            if (len == 1) {
                int p = 1 << (h - len);
                mint irot = 1;
                for (int s = 0; s < (1 << (len - 1)); s++) {
                    int offset = s << (h - len + 1);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p];
                        a[i + offset] = l + r;
                        a[i + offset + p] =
                            (unsigned long long)(mint::mod() + l.val() - r.val()) *
                            irot.val();
                        ;
                    }
                    if (s + 1 != (1 << (len - 1)))
                        irot *= info.irate2[bsf(~(unsigned int)(s))];
                }
                len--;
            } else {
                

                int p = 1 << (h - len);
                mint irot = 1, iimag = info.iroot[2];
                for (int s = 0; s < (1 << (len - 2)); s++) {
                    mint id15 = irot * irot;
                    mint id13 = id15 * irot;
                    int offset = s << (h - len + 2);
                    for (int i = 0; i < p; i++) {
                        auto a0 = 1ULL * a[i + offset + 0 * p].val();
                        auto a1 = 1ULL * a[i + offset + 1 * p].val();
                        auto a2 = 1ULL * a[i + offset + 2 * p].val();
                        auto a3 = 1ULL * a[i + offset + 3 * p].val();

                        auto id10 =
                            1ULL *
                            mint((mint::mod() + a2 - a3) * iimag.val()).val();

                        a[i + offset] = a0 + a1 + a2 + a3;
                        a[i + offset + 1 * p] =
                            (a0 + (mint::mod() - a1) + id10) * irot.val();
                        a[i + offset + 2 * p] =
                            (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                            id15.val();
                        a[i + offset + 3 * p] =
                            (a0 + (mint::mod() - a1) + (mint::mod() - id10)) *
                            id13.val();
                    }
                    if (s + 1 != (1 << (len - 2)))
                        irot *= info.irate3[bsf(~(unsigned int)(s))];
                }
                len -= 2;
            }
        }
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> id21(const std::vector<mint>& a,
                                        const std::vector<mint>& b) {
        int n = int(a.size()), m = int(b.size());
        std::vector<mint> ans(n + m - 1);
        if (n < m) {
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i + j] += a[i] * b[j];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i + j] += a[i] * b[j];
                }
            }
        }
        return ans;
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> id7(std::vector<mint> a, std::vector<mint> b) {
        int n = int(a.size()), m = int(b.size());
        int z = 1 << internal::id8(n + m - 1);
        a.resize(z);
        internal::id6(a);
        b.resize(z);
        internal::id6(b);
        for (int i = 0; i < z; i++) {
            a[i] *= b[i];
        }
        internal::id20(a);
        a.resize(n + m - 1);
        mint iz = mint(z).inv();
        for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
        return a;
    }

    }  


    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) return id21(a, b);
        return internal::id7(a, b);
    }

    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution(const std::vector<mint>& a,
                                const std::vector<mint>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) return id21(a, b);
        return internal::id7(a, b);
    }

    template <unsigned int mod = 998244353,
            class T,
            std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
    std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};

        using mint = id23<mod>;
        std::vector<mint> a2(n), b2(m);
        for (int i = 0; i < n; i++) {
            a2[i] = mint(a[i]);
        }
        for (int i = 0; i < m; i++) {
            b2[i] = mint(b[i]);
        }
        auto c2 = convolution(move(a2), move(b2));
        std::vector<T> c(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            c[i] = c2[i].val();
        }
        return c;
    }

    std::vector<long long> id11(const std::vector<long long>& a,
                                        const std::vector<long long>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};

        static constexpr unsigned long long MOD1 = 754974721;  

        static constexpr unsigned long long MOD2 = 167772161;  

        static constexpr unsigned long long MOD3 = 469762049;  

        static constexpr unsigned long long id1 = MOD2 * MOD3;
        static constexpr unsigned long long id19 = MOD1 * MOD3;
        static constexpr unsigned long long id0 = MOD1 * MOD2;
        static constexpr unsigned long long id17 = MOD1 * MOD2 * MOD3;

        static constexpr unsigned long long i1 =
            internal::id5(MOD2 * MOD3, MOD1).second;
        static constexpr unsigned long long i2 =
            internal::id5(MOD1 * MOD3, MOD2).second;
        static constexpr unsigned long long i3 =
            internal::id5(MOD1 * MOD2, MOD3).second;

        auto c1 = convolution<MOD1>(a, b);
        auto c2 = convolution<MOD2>(a, b);
        auto c3 = convolution<MOD3>(a, b);

        std::vector<long long> c(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            unsigned long long x = 0;
            x += (c1[i] * i1) % MOD1 * id1;
            x += (c2[i] * i2) % MOD2 * id19;
            x += (c3[i] * i3) % MOD3 * id0;
            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            long long diff =
                c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
            if (diff < 0) diff += MOD1;
            static constexpr unsigned long long offset[5] = {
                0, 0, id17, 2 * id17, 3 * id17};
            x -= offset[diff % 5];
            c[i] = x;
        }

        return c;
    }

}  












template <typename T>
void out(vector<T> &v){
    for(T x:v) cout << x << " ";
    cout << "\n"; return;
}


struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};


template <typename T>
void add(map<T,ll> &cnt,T a,ll n = 1){
    if(cnt.count(a)) cnt[a] += n;
    else cnt[a] = n;
}  

const ll mod = 998244353;

vector<Pr> ans(2e5+1);


vector<ll> dist(2e5+1,2e18);
vector<ll> id25(graph &g,vector<ll> starts){
    ll N = g.G.size();
    queue<int> go;
    ll x,y,a,t,l; ll inf = 2e18;
    for(ll s:starts){
        go.push(s); dist[s] = 0;
    }
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(auto q:g.G[s]){
            ll x = get<0>(q); ll label = get<2>(q);
            if(dist[x]<=dist[s]+1) continue;
            dist[x] = dist[s] + 1; ans[x] = ans[s];
            g.par_v[x] = s;
            g.par_e[x] = label;
            go.push(x);
        }
    }
    return dist;
}

ll calc(ll lmn,ll lmx,ll rmn,ll rmx,ll pv,ll nx,ll N){
    ll res = 0;
    res += (N+1-lmx)*(lmn)*(rmn-N)*(2*N+1-rmx);
    ll id14 = lmn,id18 = lmx,id4 = rmn,id3 = rmx;
    if(pv<=N){
        chmax(id18,pv); chmin(id14,pv);
    }
    else{
        chmax(id3,pv); chmin(id4,pv);
    }
    res -= (N+1-id18)*(id14)*(id4-N)*(2*N+1-id3);
    if(nx<=N){
        chmax(lmx,nx); chmin(lmn,nx);
    }
    else{
        chmax(rmx,nx); chmin(rmn,nx);
    }
    res -= (N+1-lmx)*(lmn)*(rmn-N)*(2*N+1-rmx);
    if(nx<=N){
        chmax(id18,nx); chmin(id14,nx);
    }
    else{
        chmax(id3,nx); chmin(id4,nx);
    }
    res += (N+1-id18)*(id14)*(id4-N)*(2*N+1-id3);
    return res;
}

int main(){
	riano_; ll ans = 0;
    ll N; cin >> N;
    graph G(2*N+1);
    
    rep(i,2*N){
        ll a,b; cin >> a >> b;
        G.unite(a,b);
    }
    vector<bool> vis(N+1,false);
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        vector<ll> p; ll pre = -1,st = i,n = i;
        while(1){
            p.emplace_back(n);
            

            if(n<=N) vis[n] = true;
            for(auto[x,c,l]:G.G[n]){
                

                if(pre==x) continue;
                pre = n;
                n = x;
                break;
            }
            if(n==i) break;
            

        }
        

        

        

        ll L = p.size();
        rep(j,L){
            ll lmn = 2e9,lmx = -1,rmn = 2e9,rmx = -1;
            if(p[j]<=N){
                chmax(lmx,p[j]); chmin(lmn,p[j]);
            }
            else{
                chmax(rmx,p[j]); chmin(rmn,p[j]);
            }
            ll pv = p[(j+L-1)%L];
            rep(k,L-2){
                ll tg = p[(j+1+k)%L];
                ll nx = p[(j+2+k)%L];
                if(tg<=N){
                    chmax(lmx,tg); chmin(lmn,tg);
                }
                else{
                    chmax(rmx,tg); chmin(rmn,tg);
                }
                ans += calc(lmn,lmx,rmn,rmx,pv,nx,N)*((ll)(k+2)/2LL);
                

                

                

            }
        }
        ll lmn = 2e9,lmx = -1,rmn = 2e9,rmx = -1;
        rep(j,L){
            if(p[j]<=N){
                chmax(lmx,p[j]); chmin(lmn,p[j]);
            }
            else{
                chmax(rmx,p[j]); chmin(rmn,p[j]);
            }
            
            

            

        }
        ans += (L/2LL)*(N+1-lmx)*(lmn)*(rmn-N)*(2*N+1-rmx);
    }
    
    cout << ans << endl;
}