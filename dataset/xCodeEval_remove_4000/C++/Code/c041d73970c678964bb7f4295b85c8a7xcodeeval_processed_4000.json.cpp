





namespace atcoder {
    namespace internal {
        int id6(int n) {
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
        constexpr long long id25(long long x, long long n, int m) {
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
        constexpr bool id23(int n) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            long long d = n - 1;
            while (d % 2 == 0) d /= 2;
            int v[] = { 2,7,61 };
            for (long long a : v) {
                long long t = d;
                long long y = id25(a, t, n);
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
        template <int n> constexpr bool is_prime = id23(n);
        constexpr std::pair<long long, long long> id2(long long a, long long b) {
            a = safe_mod(a, b);
            if (a == 0) return { b, 0 };
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
            return { s, m0 };
        }
        constexpr int id12(int m) {
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
                    if (id25(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return g;
            }
        }
        template <int m> constexpr int primitive_root = id12(m);
    }
}




namespace atcoder {
    namespace internal {
        template <class T> struct simple_queue {
            std::vector<T> payload;
            int pos = 0;
            void reserve(int n) { payload.reserve(n); }
            int size() const { return int(payload.size()) - pos; }
            bool empty() const { return pos == int(payload.size()); }
            void push(const T& t) { payload.push_back(t); }
            T& front() { return payload[pos]; }
            void clear() {
                payload.clear();
                pos = 0;
            }
            void pop() { pos++; }
        };
    }
}






namespace atcoder {
    namespace internal {
        template <class E> struct csr {
            std::vector<int> start;
            std::vector<E> elist;
            csr(int n, const std::vector<std::pair<int, E>>& edges)
                : start(n + 1), elist(edges.size()) {
                for (auto e : edges) {
                    start[e.first + 1]++;
                }
                for (int i = 1; i <= n; i++) {
                    start[i] += start[i - 1];
                }
                auto counter = start;
                for (auto e : edges) {
                    elist[counter[e.first]++] = e.second;
                }
            }
        };
        struct id17 {
        public:
            id17(int n) : _n(n) {}
            int num_vertices() { return _n; }
            void add_edge(int from, int to) { edges.push_back({ from, {to} }); }
            std::pair<int, std::vector<int>> scc_ids() {
                auto g = csr<edge>(_n, edges);
                int now_ord = 0, group_num = 0;
                std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
                visited.reserve(_n);
                auto dfs = [&](auto self, int v) -> void {
                    low[v] = ord[v] = now_ord++;
                    visited.push_back(v);
                    for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                        auto to = g.elist[i].to;
                        if (ord[to] == -1) {
                            self(self, to);
                            low[v] = std::min(low[v], low[to]);
                        }
                        else {
                            low[v] = std::min(low[v], ord[to]);
                        }
                    }
                    if (low[v] == ord[v]) {
                        while (true) {
                            int u = visited.back();
                            visited.pop_back();
                            ord[u] = _n;
                            ids[u] = group_num;
                            if (u == v) break;
                        }
                        group_num++;
                    }
                };
                for (int i = 0; i < _n; i++) {
                    if (ord[i] == -1) dfs(dfs, i);
                }
                for (auto& x : ids) {
                    x = group_num - 1 - x;
                }
                return { group_num, ids };
            }
            std::vector<std::vector<int>> scc() {
                auto ids = scc_ids();
                int group_num = ids.first;
                std::vector<int> counts(group_num);
                for (auto x : ids.second) counts[x]++;
                std::vector<std::vector<int>> groups(ids.first);
                for (int i = 0; i < group_num; i++) {
                    groups[i].reserve(counts[i]);
                }
                for (int i = 0; i < _n; i++) {
                    groups[ids.second[i]].push_back(i);
                }
                return groups;
            }
        private:
            int _n;
            struct edge {
                int to;
            };
            std::vector<std::pair<int, edge>> edges;
        };
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
        using is_signed_int = typename std::conditional<(is_integral<T>::value&&
            std::is_signed<T>::value) ||
            is_signed_int128<T>::value,
            std::true_type,
            std::false_type>::type;
        template <class T>
        using is_unsigned_int =
            typename std::conditional<(is_integral<T>::value&&
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
            typename std::conditional<is_integral<T>::value&& std::is_signed<T>::value,
            std::true_type,
            std::false_type>::type;
        template <class T>
        using is_unsigned_int =
            typename std::conditional<is_integral<T>::value&&
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
        struct modint_base {};
        struct static_modint_base : modint_base {};
        template <class T> using is_modint = std::is_base_of<modint_base, T>;
        template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
    }
    template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct id20 : internal::static_modint_base {
        using mint = id20;
    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        id20() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id20(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id20(T v) {
            _v = (unsigned int)(v % umod());
        }
        id20(bool v) { _v = ((unsigned int)(v) % umod()); }
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
            ++* this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --* this;
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
            }
            else {
                auto eg = internal::id2(_v, m);
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
    template <int id> struct id19 : internal::modint_base {
        using mint = id19;
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
        id19() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id19(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id19(T v) {
            _v = (unsigned int)(v % mod());
        }
        id19(bool v) { _v = ((unsigned int)(v) % mod()); }
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
            ++* this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --* this;
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
            auto eg = internal::id2(_v, mod());
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
    template <int id> internal::barrett id19<id>::bt = 998244353;
    using modint998244353 = id20<998244353>;
    using modint1000000007 = id20<1000000007>;
    using modint = id19<-1>;
    namespace internal {
        template <class T>
        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
        template <class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
        template <class> struct is_dynamic_modint : public std::false_type {};
        template <int id>
        struct is_dynamic_modint<id19<id>> : public std::true_type {};
        template <class T>
        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
    }
}








namespace atcoder {
    namespace internal {
        template <class mint, internal::is_static_modint_t<mint>* = nullptr>
        void id4(std::vector<mint>& a) {
            static constexpr int g = internal::primitive_root<mint::mod()>;
            int n = int(a.size());
            int h = internal::id6(n);
            static bool first = true;
            static mint sum_e[30];
            if (first) {
                first = false;
                mint es[30], ies[30];
                int cnt2 = bsf(mint::mod() - 1);
                mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
                for (int i = cnt2; i >= 2; i--) {
                    

                    es[i - 2] = e;
                    ies[i - 2] = ie;
                    e *= e;
                    ie *= ie;
                }
                mint now = 1;
                for (int i = 0; i < cnt2 - 2; i++) {
                    sum_e[i] = es[i] * now;
                    now *= ies[i];
                }
            }
            for (int ph = 1; ph <= h; ph++) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                mint now = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p] * now;
                        a[i + offset] = l + r;
                        a[i + offset + p] = l - r;
                    }
                    now *= sum_e[bsf(~(unsigned int)(s))];
                }
            }
        }
        template <class mint, internal::is_static_modint_t<mint>* = nullptr>
        void id18(std::vector<mint>& a) {
            static constexpr int g = internal::primitive_root<mint::mod()>;
            int n = int(a.size());
            int h = internal::id6(n);
            static bool first = true;
            static mint sum_ie[30];
            if (first) {
                first = false;
                mint es[30], ies[30];
                int cnt2 = bsf(mint::mod() - 1);
                mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
                for (int i = cnt2; i >= 2; i--) {
                    

                    es[i - 2] = e;
                    ies[i - 2] = ie;
                    e *= e;
                    ie *= ie;
                }
                mint now = 1;
                for (int i = 0; i < cnt2 - 2; i++) {
                    sum_ie[i] = ies[i] * now;
                    now *= es[i];
                }
            }
            for (int ph = h; ph >= 1; ph--) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                mint inow = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        auto l = a[i + offset];
                        auto r = a[i + offset + p];
                        a[i + offset] = l + r;
                        a[i + offset + p] =
                            (unsigned long long)(mint::mod() + l.val() - r.val()) *
                            inow.val();
                    }
                    inow *= sum_ie[bsf(~(unsigned int)(s))];
                }
            }
        }
    }
    template <class mint, internal::is_static_modint_t<mint>* = nullptr>
    std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        if (std::min(n, m) <= 60) {
            if (n < m) {
                std::swap(n, m);
                std::swap(a, b);
            }
            std::vector<mint> ans(n + m - 1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i + j] += a[i] * b[j];
                }
            }
            return ans;
        }
        int z = 1 << internal::id6(n + m - 1);
        a.resize(z);
        internal::id4(a);
        b.resize(z);
        internal::id4(b);
        for (int i = 0; i < z; i++) {
            a[i] *= b[i];
        }
        internal::id18(a);
        a.resize(n + m - 1);
        mint iz = mint(z).inv();
        for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
        return a;
    }
    template <unsigned int mod = 998244353,
        class T,
        std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
        std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        using mint = id20<mod>;
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
    std::vector<long long> id10(const std::vector<long long>& a,
        const std::vector<long long>& b) {
        int n = int(a.size()), m = int(b.size());
        if (!n || !m) return {};
        static constexpr unsigned long long MOD1 = 754974721;
        static constexpr unsigned long long MOD2 = 167772161;
        static constexpr unsigned long long MOD3 = 469762049;
        static constexpr unsigned long long id1 = MOD2 * MOD3;
        static constexpr unsigned long long id15 = MOD1 * MOD3;
        static constexpr unsigned long long id0 = MOD1 * MOD2;
        static constexpr unsigned long long id14 = MOD1 * MOD2 * MOD3;
        static constexpr unsigned long long i1 =
            internal::id2(MOD2 * MOD3, MOD1).second;
        static constexpr unsigned long long i2 =
            internal::id2(MOD1 * MOD3, MOD2).second;
        static constexpr unsigned long long i3 =
            internal::id2(MOD1 * MOD2, MOD3).second;
        auto c1 = convolution<MOD1>(a, b);
        auto c2 = convolution<MOD2>(a, b);
        auto c3 = convolution<MOD3>(a, b);
        std::vector<long long> c(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            unsigned long long x = 0;
            x += (c1[i] * i1) % MOD1 * id1;
            x += (c2[i] * i2) % MOD2 * id15;
            x += (c3[i] * i3) % MOD3 * id0;
            long long diff =
                c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
            if (diff < 0) diff += MOD1;
            static constexpr unsigned long long offset[5] = {
                0, 0, id14, 2 * id14, 3 * id14 };
            x -= offset[diff % 5];
            c[i] = x;
        }
        return c;
    }
}






namespace atcoder {
    struct dsu {
    public:
        dsu() : _n(0) {}
        dsu(int n) : _n(n), parent_or_size(n, -1) {}
        int merge(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y) return x;
            if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }
        bool same(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }
        int leader(int a) {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0) return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }
        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }
        std::vector<std::vector<int>> groups() {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++) {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++) {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++) {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                std::remove_if(result.begin(), result.end(),
                    [&](const std::vector<int>& v) { return v.empty(); }),
                result.end());
            return result;
        }
    private:
        int _n;
        std::vector<int> parent_or_size;
    };
}





namespace atcoder {
    template <class T> struct id13 {
        using U = internal::to_unsigned_t<T>;
    public:
        id13() : _n(0) {}
        id13(int n) : _n(n), data(n) {}
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
        S(*op)(S, S),
        S(*e)(),
        class F,
        S(*mapping)(F, S),
        F(*composition)(F, F),
        F(*id)()>
        struct id24 {
        public:
            id24() : id24(0) {}
            id24(int n) : id24(std::vector<S>(n, e())) {}
            id24(const std::vector<S>& v) : _n(int(v.size())) {
                log = internal::id6(_n);
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
    long long pow_mod(long long x, long long n, int m) {
        assert(0 <= n && 1 <= m);
        if (m == 1) return 0;
        internal::barrett bt((unsigned int)(m));
        unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
        while (n) {
            if (n & 1) r = bt.mul(r, y);
            y = bt.mul(y, y);
            n >>= 1;
        }
        return r;
    }
    long long inv_mod(long long x, long long m) {
        assert(1 <= m);
        auto z = internal::id2(x, m);
        assert(z.first == 1);
        return z.second;
    }
    std::pair<long long, long long> crt(const std::vector<long long>& r,
        const std::vector<long long>& m) {
        assert(r.size() == m.size());
        int n = int(r.size());
        long long r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert(1 <= m[i]);
            long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
            if (m0 < m1) {
                std::swap(r0, r1);
                std::swap(m0, m1);
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return { 0, 0 };
                continue;
            }
            long long g, im;
            std::tie(g, im) = internal::id2(m0, m1);
            long long u1 = (m1 / g);
            if ((r1 - r0) % g) return { 0, 0 };
            long long x = (r1 - r0) / g % u1 * im % u1;
            r0 += x * m0;
            m0 *= u1;
            if (r0 < 0) r0 += m0;
        }
        return { r0, m0 };
    }
    long long floor_sum(long long n, long long m, long long a, long long b) {
        long long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
        if (y_max == 0) return ans;
        ans += (n - (x_max + a - 1) / a) * y_max;
        ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
        return ans;
    }
}








namespace atcoder {
    template <class Cap> struct mf_graph {
    public:
        mf_graph() : _n(0) {}
        mf_graph(int n) : _n(n), g(n) {}
        int add_edge(int from, int to, Cap cap) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            assert(0 <= cap);
            int m = int(pos.size());
            pos.push_back({ from, int(g[from].size()) });
            g[from].push_back(_edge{ to, int(g[to].size()), cap });
            g[to].push_back(_edge{ from, int(g[from].size()) - 1, 0 });
            return m;
        }
        struct edge {
            int from, to;
            Cap cap, flow;
        };
        edge get_edge(int i) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{ pos[i].first, _e.to, _e.cap + _re.cap, _re.cap };
        }
        std::vector<edge> edges() {
            int m = int(pos.size());
            std::vector<edge> result;
            for (int i = 0; i < m; i++) {
                result.push_back(get_edge(i));
            }
            return result;
        }
        void change_edge(int i, Cap new_cap, Cap new_flow) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            assert(0 <= new_flow && new_flow <= new_cap);
            auto& _e = g[pos[i].first][pos[i].second];
            auto& _re = g[_e.to][_e.rev];
            _e.cap = new_cap - new_flow;
            _re.cap = new_flow;
        }
        Cap flow(int s, int t) {
            return flow(s, t, std::numeric_limits<Cap>::max());
        }
        Cap flow(int s, int t, Cap flow_limit) {
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            std::vector<int> level(_n), iter(_n);
            internal::simple_queue<int> que;
            auto bfs = [&]() {
                std::fill(level.begin(), level.end(), -1);
                level[s] = 0;
                que.clear();
                que.push(s);
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();
                    for (auto e : g[v]) {
                        if (e.cap == 0 || level[e.to] >= 0) continue;
                        level[e.to] = level[v] + 1;
                        if (e.to == t) return;
                        que.push(e.to);
                    }
                }
            };
            auto dfs = [&](auto self, int v, Cap up) {
                if (v == s) return up;
                Cap res = 0;
                int level_v = level[v];
                for (int& i = iter[v]; i < int(g[v].size()); i++) {
                    _edge& e = g[v][i];
                    if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                    Cap d =
                        self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                    if (d <= 0) continue;
                    g[v][i].cap += d;
                    g[e.to][e.rev].cap -= d;
                    res += d;
                    if (res == up) break;
                }
                return res;
            };
            Cap flow = 0;
            while (flow < flow_limit) {
                bfs();
                if (level[t] == -1) break;
                std::fill(iter.begin(), iter.end(), 0);
                while (flow < flow_limit) {
                    Cap f = dfs(dfs, t, flow_limit - flow);
                    if (!f) break;
                    flow += f;
                }
            }
            return flow;
        }
        std::vector<bool> min_cut(int s) {
            std::vector<bool> visited(_n);
            internal::simple_queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int p = que.front();
                que.pop();
                visited[p] = true;
                for (auto e : g[p]) {
                    if (e.cap && !visited[e.to]) {
                        visited[e.to] = true;
                        que.push(e.to);
                    }
                }
            }
            return visited;
        }
    private:
        int _n;
        struct _edge {
            int to, rev;
            Cap cap;
        };
        std::vector<std::pair<int, int>> pos;
        std::vector<std::vector<_edge>> g;
    };
}








namespace atcoder {
    template <class Cap, class Cost> struct id5 {
    public:
        id5() {}
        id5(int n) : _n(n), g(n) {}
        int add_edge(int from, int to, Cap cap, Cost cost) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            int m = int(pos.size());
            pos.push_back({ from, int(g[from].size()) });
            g[from].push_back(_edge{ to, int(g[to].size()), cap, cost });
            g[to].push_back(_edge{ from, int(g[from].size()) - 1, 0, -cost });
            return m;
        }
        struct edge {
            int from, to;
            Cap cap, flow;
            Cost cost;
        };
        edge get_edge(int i) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
            };
        }
        std::vector<edge> edges() {
            int m = int(pos.size());
            std::vector<edge> result(m);
            for (int i = 0; i < m; i++) {
                result[i] = get_edge(i);
            }
            return result;
        }
        std::pair<Cap, Cost> flow(int s, int t) {
            return flow(s, t, std::numeric_limits<Cap>::max());
        }
        std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
            return slope(s, t, flow_limit).back();
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
            return slope(s, t, std::numeric_limits<Cap>::max());
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            assert(s != t);
            std::vector<Cost> dual(_n, 0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            std::vector<bool> vis(_n);
            auto dual_ref = [&]() {
                std::fill(dist.begin(), dist.end(),
                    std::numeric_limits<Cost>::max());
                std::fill(pv.begin(), pv.end(), -1);
                std::fill(pe.begin(), pe.end(), -1);
                std::fill(vis.begin(), vis.end(), false);
                struct Q {
                    Cost key;
                    int to;
                    bool operator<(Q r) const { return key > r.key; }
                };
                std::priority_queue<Q> que;
                dist[s] = 0;
                que.push(Q{ 0, s });
                while (!que.empty()) {
                    int v = que.top().to;
                    que.pop();
                    if (vis[v]) continue;
                    vis[v] = true;
                    if (v == t) break;
                    for (int i = 0; i < int(g[v].size()); i++) {
                        auto e = g[v][i];
                        if (vis[e.to] || !e.cap) continue;
                        Cost cost = e.cost - dual[e.to] + dual[v];
                        if (dist[e.to] - dist[v] > cost) {
                            dist[e.to] = dist[v] + cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                            que.push(Q{ dist[e.to], e.to });
                        }
                    }
                }
                if (!vis[t]) {
                    return false;
                }
                for (int v = 0; v < _n; v++) {
                    if (!vis[v]) continue;
                    dual[v] -= dist[t] - dist[v];
                }
                return true;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost = -1;
            std::vector<std::pair<Cap, Cost>> result;
            result.push_back({ flow, cost });
            while (flow < flow_limit) {
                if (!dual_ref()) break;
                Cap c = flow_limit - flow;
                for (int v = t; v != s; v = pv[v]) {
                    c = std::min(c, g[pv[v]][pe[v]].cap);
                }
                for (int v = t; v != s; v = pv[v]) {
                    auto& e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                Cost d = -dual[s];
                flow += c;
                cost += c * d;
                if (prev_cost == d) {
                    result.pop_back();
                }
                result.push_back({ flow, cost });
                prev_cost = cost;
            }
            return result;
        }
    private:
        int _n;
        struct _edge {
            int to, rev;
            Cap cap;
            Cost cost;
        };
        std::vector<std::pair<int, int>> pos;
        std::vector<std::vector<_edge>> g;
    };
}






namespace atcoder {
    struct id17 {
    public:
        id17() : internal(0) {}
        id17(int n) : internal(n) {}
        void add_edge(int from, int to) {
            int n = internal.num_vertices();
            assert(0 <= from && from < n);
            assert(0 <= to && to < n);
            internal.add_edge(from, to);
        }
        std::vector<std::vector<int>> scc() { return internal.scc(); }
    private:
        internal::id17 internal;
    };
}






namespace atcoder {
    template <class S, S(*op)(S, S), S(*e)()> struct id21 {
    public:
        id21() : id21(0) {}
        id21(int n) : id21(std::vector<S>(n, e())) {}
        id21(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::id6(_n);
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








namespace atcoder {
    namespace internal {
        std::vector<int> id22(const std::vector<int>& s) {
            int n = int(s.size());
            std::vector<int> sa(n);
            std::iota(sa.begin(), sa.end(), 0);
            std::sort(sa.begin(), sa.end(), [&](int l, int r) {
                if (l == r) return false;
                while (l < n && r < n) {
                    if (s[l] != s[r]) return s[l] < s[r];
                    l++;
                    r++;
                }
                return l == n;
            });
            return sa;
        }
        std::vector<int> id16(const std::vector<int>& s) {
            int n = int(s.size());
            std::vector<int> sa(n), rnk = s, tmp(n);
            std::iota(sa.begin(), sa.end(), 0);
            for (int k = 1; k < n; k *= 2) {
                auto cmp = [&](int x, int y) {
                    if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
                    int rx = x + k < n ? rnk[x + k] : -1;
                    int ry = y + k < n ? rnk[y + k] : -1;
                    return rx < ry;
                };
                std::sort(sa.begin(), sa.end(), cmp);
                tmp[sa[0]] = 0;
                for (int i = 1; i < n; i++) {
                    tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
                }
                std::swap(tmp, rnk);
            }
            return sa;
        }
        template <int id3 = 10, int id8 = 40>
        std::vector<int> sa_is(const std::vector<int>& s, int upper) {
            int n = int(s.size());
            if (n == 0) return {};
            if (n == 1) return { 0 };
            if (n == 2) {
                if (s[0] < s[1]) {
                    return { 0, 1 };
                }
                else {
                    return { 1, 0 };
                }
            }
            if (n < id3) {
                return id22(s);
            }
            if (n < id8) {
                return id16(s);
            }
            std::vector<int> sa(n);
            std::vector<bool> ls(n);
            for (int i = n - 2; i >= 0; i--) {
                ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
            }
            std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
            for (int i = 0; i < n; i++) {
                if (!ls[i]) {
                    sum_s[s[i]]++;
                }
                else {
                    sum_l[s[i] + 1]++;
                }
            }
            for (int i = 0; i <= upper; i++) {
                sum_s[i] += sum_l[i];
                if (i < upper) sum_l[i + 1] += sum_s[i];
            }
            auto induce = [&](const std::vector<int>& lms) {
                std::fill(sa.begin(), sa.end(), -1);
                std::vector<int> buf(upper + 1);
                std::copy(sum_s.begin(), sum_s.end(), buf.begin());
                for (auto d : lms) {
                    if (d == n) continue;
                    sa[buf[s[d]]++] = d;
                }
                std::copy(sum_l.begin(), sum_l.end(), buf.begin());
                sa[buf[s[n - 1]]++] = n - 1;
                for (int i = 0; i < n; i++) {
                    int v = sa[i];
                    if (v >= 1 && !ls[v - 1]) {
                        sa[buf[s[v - 1]]++] = v - 1;
                    }
                }
                std::copy(sum_l.begin(), sum_l.end(), buf.begin());
                for (int i = n - 1; i >= 0; i--) {
                    int v = sa[i];
                    if (v >= 1 && ls[v - 1]) {
                        sa[--buf[s[v - 1] + 1]] = v - 1;
                    }
                }
            };
            std::vector<int> id11(n + 1, -1);
            int m = 0;
            for (int i = 1; i < n; i++) {
                if (!ls[i - 1] && ls[i]) {
                    id11[i] = m++;
                }
            }
            std::vector<int> lms;
            lms.reserve(m);
            for (int i = 1; i < n; i++) {
                if (!ls[i - 1] && ls[i]) {
                    lms.push_back(i);
                }
            }
            induce(lms);
            if (m) {
                std::vector<int> id7;
                id7.reserve(m);
                for (int v : sa) {
                    if (id11[v] != -1) id7.push_back(v);
                }
                std::vector<int> rec_s(m);
                int rec_upper = 0;
                rec_s[id11[id7[0]]] = 0;
                for (int i = 1; i < m; i++) {
                    int l = id7[i - 1], r = id7[i];
                    int end_l = (id11[l] + 1 < m) ? lms[id11[l] + 1] : n;
                    int end_r = (id11[r] + 1 < m) ? lms[id11[r] + 1] : n;
                    bool same = true;
                    if (end_l - l != end_r - r) {
                        same = false;
                    }
                    else {
                        while (l < end_l) {
                            if (s[l] != s[r]) {
                                break;
                            }
                            l++;
                            r++;
                        }
                        if (l == n || s[l] != s[r]) same = false;
                    }
                    if (!same) rec_upper++;
                    rec_s[id11[id7[i]]] = rec_upper;
                }
                auto rec_sa =
                    sa_is<id3, id8>(rec_s, rec_upper);
                for (int i = 0; i < m; i++) {
                    id7[i] = lms[rec_sa[i]];
                }
                induce(id7);
            }
            return sa;
        }
    }
    std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
        assert(0 <= upper);
        for (int d : s) {
            assert(0 <= d && d <= upper);
        }
        auto sa = internal::sa_is(s, upper);
        return sa;
    }
    template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
        int n = int(s.size());
        std::vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
        std::vector<int> s2(n);
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (i && s[idx[i - 1]] != s[idx[i]]) now++;
            s2[idx[i]] = now;
        }
        return internal::sa_is(s2, now);
    }
    std::vector<int> suffix_array(const std::string& s) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return internal::sa_is(s2, 255);
    }
    template <class T>
    std::vector<int> id9(const std::vector<T>& s,
        const std::vector<int>& sa) {
        int n = int(s.size());
        assert(n >= 1);
        std::vector<int> rnk(n);
        for (int i = 0; i < n; i++) {
            rnk[sa[i]] = i;
        }
        std::vector<int> lcp(n - 1);
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (h > 0) h--;
            if (rnk[i] == 0) continue;
            int j = sa[rnk[i] - 1];
            for (; j + h < n && i + h < n; h++) {
                if (s[j + h] != s[i + h]) break;
            }
            lcp[rnk[i] - 1] = h;
        }
        return lcp;
    }
    std::vector<int> id9(const std::string& s, const std::vector<int>& sa) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return id9(s2, sa);
    }
    template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
        int n = int(s.size());
        if (n == 0) return {};
        std::vector<int> z(n);
        z[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            int& k = z[i];
            k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
            while (i + k < n && s[k] == s[i + k]) k++;
            if (j + z[j] < i + z[i]) j = i;
        }
        z[0] = n;
        return z;
    }
    std::vector<int> z_algorithm(const std::string& s) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return z_algorithm(s2);
    }
}





namespace atcoder {
    struct two_sat {
    public:
        two_sat() : _n(0), scc(0) {}
        two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}
        void add_clause(int i, bool f, int j, bool g) {
            assert(0 <= i && i < _n);
            assert(0 <= j && j < _n);
            scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
            scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
        }
        bool satisfiable() {
            auto id = scc.scc_ids().second;
            for (int i = 0; i < _n; i++) {
                if (id[2 * i] == id[2 * i + 1]) return false;
                _answer[i] = id[2 * i] < id[2 * i + 1];
            }
            return true;
        }
        std::vector<bool> answer() { return _answer; }
    private:
        int _n;
        std::vector<bool> _answer;
        internal::id17 scc;
    };
}



















using namespace std;
using namespace atcoder;





typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e17;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
    if (a > b) { return a; }
    return b;
}

ll min(ll a, ll b) {
    if (a > b) { return b; }
    return a;
}

ll gcd(ll a, ll b) {
    if (b == 0) { return a; }
    if (a < b) { return gcd(b, a); }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


struct edge {
    ll id;
    ll fr;
    ll to;
    ll d;
};

using mint = modint;

typedef vector<ll> vll;
typedef vector <vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

vmint f, finv, inv;

void cominit(ll N) {
    ll MOD = 1000000007;


    f.assign(N + 1, 1);
    finv.assign(N + 1, 1);
    inv.assign(N + 1, 1);
    inv[1] = 1;

    repn(i, N) {
        f[i] = f[i - 1] * i;
        if (i > 1)inv[i] = -inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

mint com(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) { return 0; }
    return f[a] * finv[b] * finv[a - b];
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, K;
    cin >> N >> K;

    vvll ans(N, vll(N, 0));
    ll mx = 0;
    rep(i, N)rep(j, N) {
        if (i >= j)continue;

        ll x = i, y = j;
        ll cnt = 0;
        while (1) {
            if (x % K < y % K)break;
            x /= K;
            y /= K;
            cnt++;
        }
        ans[i][j] = cnt;
        mx = max(mx, cnt);
    }

    cout << mx + 1 << endl;
    rep(i, N)rep(j, N) {
        if (i >= j)continue;
        cout << ans[i][j] + 1 << " ";
    }
    cout << endl;
}