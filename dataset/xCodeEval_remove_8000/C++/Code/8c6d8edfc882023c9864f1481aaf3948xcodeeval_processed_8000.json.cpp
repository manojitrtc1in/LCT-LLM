
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }





const int mod=998244353,MAX=300005,INF=1<<30;













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
        
        constexpr long long safe_mod(long long x, long long m) {
            x %= m;
            if (x < 0) x += m;
            return x;
        }
        
        struct barrett {
            unsigned int _m;
            unsigned long long im;
            
            barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
            
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
        
        constexpr long long id9(long long x, long long n, int m) {
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
        
        constexpr bool id7(int n) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            long long d = n - 1;
            while (d % 2 == 0) d /= 2;
            for (long long a : {2, 7, 61}) {
                long long t = d;
                long long y = id9(a, t, n);
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
        template <int n> constexpr bool is_prime = id7(n);
        
        constexpr std::pair<long long, long long> id0(long long a, long long b) {
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
        
        constexpr int id2(int m) {
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
                    if (id9(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return g;
            }
        }
        template <int m> constexpr int primitive_root = id2(m);
        
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
    struct id5 : internal::static_modint_base {
        using mint = id5;
        
    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        
        id5() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id5(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id5(T v) {
            _v = (unsigned int)(v % umod());
        }
        id5(bool v) { _v = ((unsigned int)(v) % umod()); }
        
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
                auto eg = internal::id0(_v, m);
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
        
    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };
    
    template <int id> struct id4 : internal::modint_base {
        using mint = id4;
        
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
        
        id4() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id4(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id4(T v) {
            _v = (unsigned int)(v % mod());
        }
        id4(bool v) { _v = ((unsigned int)(v) % mod()); }
        
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
            auto eg = internal::id0(_v, mod());
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
        
    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id> internal::barrett id4<id>::bt = 998244353;
    
    using modint998244353 = id5<998244353>;
    using modint1000000007 = id5<1000000007>;
    using modint = id4<-1>;
    
    namespace internal {
        
        template <class T>
        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
        
        template <class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
        
        template <class> struct is_dynamic_modint : public std::false_type {};
        template <int id>
        struct is_dynamic_modint<id4<id>> : public std::true_type {};
        
        template <class T>
        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
        
    }  

    
}  


using mint=atcoder::modint998244353;














namespace atcoder {
    namespace internal {
        int id1(int n) {
            int x = 0;
            while ((1U << x) < (unsigned int)(n)) x++;
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
    
    template <class T> struct id3 {
        using U = internal::to_unsigned_t<T>;
        
    public:
        id3() : _n(0) {}
        id3(int n) : _n(n), data(n) {}
        
        void add(int p, T x) {
            assert(0 <= p && p < _n);
            p++;
            while (p <= _n) {
                data[p - 1] += U(x);
                p += p & -p;
            }
        }
        
        T sum(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            return sum(r) - sum(l);
        }
        
    private:
        int _n;
        std::vector<U> data;
        
        U sum(int r) {
            U s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }
    };
    
}  







namespace atcoder {
    
    template <class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*composition)(F, F),
    F (*id)()>
    struct id8 {
    public:
        id8() : id8(0) {}
        id8(int n) : id8(std::vector<S>(n, e())) {}
        id8(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::id1(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            lz = std::vector<F>(size, id());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }
        
        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        
        S get(int p) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }
        
        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return e();
            
            l += size;
            r += size;
            
            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push(r >> i);
            }
            
            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            
            return op(sml, smr);
        }
        
        S all_prod() { return d[1]; }
        
        void apply(int p, F f) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        void apply(int l, int r, F f) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return;
            
            l += size;
            r += size;
            
            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }
            
            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }
            
            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }
        
        template <bool (*g)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return g(x); });
        }
        template <class G> int max_right(int l, G g) {
            assert(0 <= l && l <= _n);
            assert(g(e()));
            if (l == _n) return _n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = (2 * l);
                        if (g(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        
        template <bool (*g)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return g(x); });
        }
        template <class G> int min_left(int r, G g) {
            assert(0 <= r && r <= _n);
            assert(g(e()));
            if (r == 0) return 0;
            r += size;
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(op(d[r], sm))) {
                    while (r < size) {
                        push(r);
                        r = (2 * r + 1);
                        if (g(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }
        
    private:
        int _n, size, log;
        std::vector<S> d;
        std::vector<F> lz;
        
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
        void all_apply(int k, F f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }
        void push(int k) {
            all_apply(2 * k, lz[k]);
            all_apply(2 * k + 1, lz[k]);
            lz[k] = id();
        }
    };
    
}  






namespace atcoder {
    
    template <class S, S (*op)(S, S), S (*e)()> struct id6 {
    public:
        id6() : id6(0) {}
        id6(int n) : id6(std::vector<S>(n, e())) {}
        id6(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::id1(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }
        
        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        
        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }
        
        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;
            
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        
        S all_prod() { return d[1]; }
        
        template <bool (*f)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return f(x); });
        }
        template <class F> int max_right(int l, F f) {
            assert(0 <= l && l <= _n);
            assert(f(e()));
            if (l == _n) return _n;
            l += size;
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!f(op(sm, d[l]))) {
                    while (l < size) {
                        l = (2 * l);
                        if (f(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        
        template <bool (*f)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return f(x); });
        }
        template <class F> int min_left(int r, F f) {
            assert(0 <= r && r <= _n);
            assert(f(e()));
            if (r == 0) return 0;
            r += size;
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!f(op(d[r], sm))) {
                    while (r < size) {
                        r = (2 * r + 1);
                        if (f(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }
        
    private:
        int _n, size, log;
        std::vector<S> d;
        
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    };
    
}  


typedef array<array<mint,2>,2> mat;
typedef array<array<mint,1>,2> vec;

mat mul(mat &A, mat&B){
    mat C;
    for(int i=0;i<A.size();i++){
        for(int k=0;k<B.size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

vec mul(mat &A, vec&B){
    vec C;
    for(int i=0;i<A.size();i++){
        for(int k=0;k<B.size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

vec wa(vec &A, vec&B){
    vec C;
    for(int i=0;i<si(A);i++){
        for(int j=0;j<si(A[0]);j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return C;
}

mat tanni;
vec bi;

using T=vec;
using E=mat;

T f(T a,T b){
    return wa(a,b);
}

T g(E a,T b){
    return mul(a,b);
}

E h(E a,E b){
    return mul(a,b);
}

T ti(){
    return bi;
}

E ei(){
    return tanni;
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    tanni[0][0]=tanni[1][1]=1;
    tanni[0][1]=tanni[1][0]=0;
    
    bi[0][0]=0;
    bi[0][1]=1;
    
    mat A;
    mat B;
    A[0][0]=2;
    A[0][1]=2;
    A[1][0]=1;
    A[1][1]=1;
    
    B[0][0]=2;
    B[0][1]=0;
    B[1][0]=1;
    B[1][1]=3;
    
    
    int N;cin>>N;
    vector<int> L(N),R(N);
    for(int i=0;i<N;i++) cin>>L[i]>>R[i];
    
    vector<vec> def(300001,bi);
    
    for(int i=L[0];i<=R[0];i++) swap(def[i][0][0],def[i][1][0]);
    
    atcoder::id8<T,f,ti,E,g,h,ei> seg(def);
    
    for(int i=1;i<N;i++){
        int l,r;
        l=L[i];
        r=R[i];
        seg.apply(0,l,B);
        seg.apply(l,r+1,A);
        seg.apply(r+1,300001,B);
        
    }
    
    

    
    cout<<seg.all_prod()[0][0].val()<<endl;
    
    return 0;
    
    mint ans=0;
    
    
    for(int i=0;i<=300000;i++){
        ans+=seg.get(i)[0][0];
        

        

    }
    
    cout<<ans.val()<<endl;
}
