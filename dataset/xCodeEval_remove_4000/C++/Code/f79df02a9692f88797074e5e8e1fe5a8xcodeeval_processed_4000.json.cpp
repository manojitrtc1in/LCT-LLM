














namespace suisen {


template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}



template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;



template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool id5 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} 


namespace suisen {
    class BitVector {
        using u8 = std::uint8_t;
    public:
        explicit BitVector(int n) : n(n), nl((n >> LOG_BLOCK_L) + 1), ns((n >> LOG_BLOCK_S) + 1), cum_l(nl, 0), cum_s(ns, 0), bits(ns, 0) {}
        BitVector() : BitVector(0) {}
        template <typename Gen, constraints_t<is_same_as_invoke_result<bool, Gen, int>> = nullptr>
        BitVector(int n, Gen gen) : BitVector(n) {
            build(gen);
        }
        BitVector& operator=(const BitVector& bv) {
            n = bv.n, nl = bv.nl, ns = bv.ns, cum_l = bv.cum_l, cum_s = bv.cum_s, bits = bv.bits;
            return *this;
        }
        BitVector& operator=(BitVector&& bv) {
            n = bv.n, nl = bv.nl, ns = bv.ns, cum_l = std::move(bv.cum_l), cum_s = std::move(bv.cum_s), bits = std::move(bv.bits);
            return *this;
        }
        template <typename Gen, constraints_t<is_same_as_invoke_result<bool, Gen, int>> = nullptr>
        void build(Gen gen) {
            int i = 0;
            for (int index_s = 1; index_s < ns; ++index_s) {
                int count = cum_s[index_s - 1];
                for (; i < index_s << LOG_BLOCK_S; ++i) {
                    bool b = gen(i);
                    bits[index_s - 1] |= b << (i & MASK_S);
                    count += b;
                }
                if (index_s & ((1 << (LOG_BLOCK_L - LOG_BLOCK_S)) - 1)) {
                    cum_s[index_s] = count;
                } else {
                    int index_l = i >> LOG_BLOCK_L;
                    cum_l[index_l] = cum_l[index_l - 1] + count;
                }
            }
            for (; i < n; ++i) bits[ns - 1] |= gen(i) << (i & MASK_S);
        }
        inline bool operator[](int i) const {
            return (bits[i >> LOG_BLOCK_S] >> (i & MASK_S)) & 1;
        }
        

        inline bool access(int i) const {
            return (*this)[i];
        }
        

        inline int rank(bool val, int i) const {
            int id11 = cum_l[i >> LOG_BLOCK_L] + cum_s[i >> LOG_BLOCK_S] + popcount8(bits[i >> LOG_BLOCK_S] & ((1 << (i & MASK_S)) - 1));
            return val ? id11 : i - id11;
        }
        

        inline int rank(bool val, int l, int r) const {
            return rank(val, r) - rank(val, l);
        }
        

        int select(bool val, int num, int default_value = -1) const {
            int l = -1, r = n + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                (rank(val, m) >= num ? r : l) = m;
            }
            return r == n + 1 ? default_value : r;
        }
    private:
        static constexpr int LOG_BLOCK_L = 8;
        static constexpr int LOG_BLOCK_S = 3;
        static constexpr int MASK_S = (1 << LOG_BLOCK_S) - 1;

        int n, nl, ns;
        std::vector<int> cum_l;
        std::vector<u8> cum_s, bits;

        static constexpr u8 popcount8(u8 x) {
            x = (x & 0b01010101) + ((x >> 1) & 0b01010101);
            x = (x & 0b00110011) + ((x >> 2) & 0b00110011);
            return (x & 0b00001111) + (x >> 4);
        }
    };
} 


namespace suisen {
    template <typename T, int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits>
    struct id2 {
        

        id2() noexcept : n(0) {}
        

        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        id2(int n, Gen generator) : n(n) {
            build(generator);
        }
        

        template <typename U, constraints_t<std::is_constructible<T, U>> = nullptr>
        id2(const std::vector<U>& a) : id2(a.size(), [&a](int i) { return T(a[i]); }) {}

        

        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        void build(Gen generator) {
            std::vector<T> a(n), l(n), r(n);
            for (int i = 0; i < n; ++i) a[i] = generator(i);
            for (int log = bit_num - 1; log >= 0; --log) {
                bv[log] = BitVector(n, [&a, log](int i) -> bool { return (a[i] >> log) & 1; });
                int li = 0, ri = 0;
                for (int i = 0; i < n; ++i) {
                    ((a[i] >> log) & 1 ? r[ri++] : l[li++]) = a[i];
                }
                a.swap(l);
                std::copy(r.begin(), r.begin() + ri, a.begin() + li);
                mid[log] = li;
            }
        }
        

        T operator[](int i) const {
            T res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                bool b = bv[log][i];
                res |= T(b) << log;
                i = b * mid[log] + bv[log].rank(b, i);
            }
            return res;
        }
        

        inline T access(int i) const {
            return (*this)[i];
        }
        

        int rank(T val, int i) const {
            check_value_bounds(val);
            int l = 0, r = i;
            for (int log = bit_num - 1; log >= 0; --log) succ(l, r, (val >> log) & 1, log);
            return r - l;
        }
        

        T range_kth_smallest(int l, int r, int k, T default_value = T(-1)) const {
            if (k < 0 or k >= r - l) return default_value;
            T res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                int id3 = bv[log].rank(false, l, r);
                bool bit = k >= id3;
                succ(l, r, bit, log);
                res |= T(bit) << log;
                k -= bit * id3;
            }
            return res;
        }
        

        inline T range_kth_largest(int l, int r, int k, T default_value = T(-1)) const {
            return range_kth_smallest(l, r, r - l - 1 - k, default_value);
        }
        

        inline T range_min(int l, int r) const {
            assert(l < r);
            return range_kth_smallest(l, r, 0);
        }
        

        inline T range_max(int l, int r) const {
            assert(l < r);
            return range_kth_largest(l, r, 0);
        }
        

        int range_freq(int l, int r, T upper) const {
            if (r <= l) return 0;
            check_value_bounds(upper);
            int res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                bool b = (upper >> log) & 1;
                if (b) res += bv[log].rank(false, l, r);
                succ(l, r, b, log);
            }
            return res;
        }
        

        inline int range_freq(int l, int r, T lower, T upper) const {
            if (lower >= upper) return 0;
            return range_freq(l, r, upper) - range_freq(l, r, lower);
        }
        

        inline T range_min_geq(int l, int r, T lower, T default_value = T(-1)) const {
            int cnt = range_freq(l, r, lower);
            return cnt >= r - l ? default_value : range_kth_smallest(l, r, cnt);
        }
        

        inline T range_min_gt(int l, int r, T lower, T default_value = T(-1)) const {
            return lower == MAX ? default_value : range_min_geq(l, r, lower + 1);
        }
        

        inline T range_max_lt(int l, int r, T upper, T default_value = T(-1)) const {
            int cnt = range_freq(l, r, upper);
            return cnt == 0 ? default_value : range_kth_smallest(l, r, cnt - 1);
        }
        

        inline T range_max_leq(int l, int r, T upper, T default_value = T(-1)) const {
            if (r >= l) return default_value;
            return upper == MAX ? range_max(l, r) : range_max_lt(l, r, upper + 1);
        }
    protected:
        id2(int n) noexcept : n(n) {}
    private:
        static_assert(bit_num > 0);
        static constexpr T MAX = bit_num == std::numeric_limits<T>::digits ? std::numeric_limits<T>::max() : (T(1) << bit_num) - 1;

        int n;
        std::array<BitVector, bit_num> bv;
        std::array<int, bit_num> mid;

        inline void succ(int& l, int& r, const bool b, const int log) const {
            l = b * mid[log] + bv[log].rank(b, l);
            r = b * mid[log] + bv[log].rank(b, r);
        }

        static constexpr void check_value_bounds(T val) {
            assert((val >> bit_num) == 0);
        }
    };
} 


using suisen::id2;




namespace suisen {
    template <int id1, typename mint>
    struct id0 {
        id0() {}
        id0(int n) { ensure(n); }
        const mint& operator[](int i) const {
            ensure(i);
            return pows[i];
        }
        static void ensure(int n) {
            int sz = pows.size();
            if (sz > n) return;
            pows.resize(n + 1);
            for (int i = sz; i <= n; ++i) pows[i] = base * pows[i - 1];
        }
    private:
        static inline std::vector<mint> pows { 1 };
        static inline mint base = id1;
        static constexpr int mod = mint::mod();
    };

    template <typename mint>
    struct id10 {
        id10() {}
        id10(mint base, int n) : base(base) { ensure(n); }
        const mint& operator[](int i) const {
            ensure(i);
            return pows[i];
        }
        void ensure(int n) const {
            int sz = pows.size();
            if (sz > n) return;
            pows.resize(n + 1);
            for (int i = sz; i <= n; ++i) pows[i] = base * pows[i - 1];
        }
    private:
        mutable std::vector<mint> pows { 1 };
        mint base;
        static constexpr int mod = mint::mod();
    };
}

namespace suisen {
    namespace internal::rolling_hash {
        

        struct id9 {
            using self = id9;

            id9() {}
            id9(uint64_t v) : v(fast_mod(v)) {}

            static constexpr uint64_t mod() {
                return _mod;
            }

            static constexpr uint64_t fast_mod(uint64_t v) {
                constexpr uint32_t mid = 61;
                constexpr uint64_t mask = (uint64_t(1) << mid) - 1;
                uint64_t u = v >> mid;
                uint64_t d = v & mask;
                uint64_t res = u + d;
                if (res >= _mod) res -= _mod;
                return res;
            }

            uint64_t val() const {
                return v;
            }

            self& operator+=(const self &rhs) {
                v += rhs.v;
                if (v >= _mod) v -= _mod;
                return *this;
            }
            self& operator-=(const self &rhs) {
                if (v < rhs.v) v += _mod;
                v -= rhs.v;
                return *this;
            }
            self& operator*=(const self &rhs) {
                static constexpr uint32_t mid31 = 31;
                static constexpr uint64_t mask31 = (uint64_t(1) << mid31) - 1;

                uint64_t au = v >> mid31;     

                uint64_t ad = v & mask31;     

                uint64_t bu = rhs.v >> mid31; 

                uint64_t bd = rhs.v & mask31; 

                
                

                

                

                

                

                

                

                

                


                static constexpr uint32_t mid30 = 30;
                static constexpr uint64_t mask30 = (uint64_t(1) << mid30) - 1;

                uint64_t m = au * bd + ad * bu;
                uint64_t mu = m >> mid30;
                uint64_t md = m & mask30;

                v = fast_mod((au * bu << 1) + mu + (md << 31) + ad * bd);
                return *this;
            }

            friend self operator+(const self &l, const self &r) { return self(l) += r; }
            friend self operator-(const self &l, const self &r) { return self(l) -= r; }
            friend self operator*(const self &l, const self &r) { return self(l) *= r; }
            friend bool operator==(const self &l, const self &r) { return l.v == r.v; }
        private:
            static constexpr uint64_t _mod = (uint64_t(1) << 61) - 1; 

            uint64_t v;
        };

        template <int base_num, typename mint>
        std::array<mint, base_num> id8() {
            static std::mt19937_64 rng(std::random_device{}());
            std::array<mint, base_num> res;
            for (int i = 0; i < base_num; ++i) {
                res[i] = rng();
                while (res[i].val() < 128) res[i] = rng();
            }
            return res;
        }
        template <int base_num, typename mint>
        std::array<id10<mint>, base_num> id12(const std::array<mint, base_num>& bases) {
            std::array<id10<mint>, base_num> res;
            for (int i = 0; i < base_num; ++i) {
                res[i] = id10<mint>(bases[i], 0);
            }
            return res;
        }
    }

    template <int base_num = 1, typename mint = internal::rolling_hash::id9>
    struct RollingHash {
    private:
        using default_mint = internal::rolling_hash::id9;
    public:
        using modint_type = mint;
        using hash_type = decltype(mint::mod());

        RollingHash() {}
        RollingHash(const std::vector<int> &a) : n(a.size()) {
            for (int base_id = 0; base_id < base_num; ++base_id) {
                hash[base_id].resize(n + 1);
                hash[base_id][0] = 0;
                for (int i = 0; i < n; ++i) hash[base_id][i + 1] = hash[base_id][i] * bases[base_id] + a[i];
            }
        }

        auto operator()(int l, int r) {
            std::array<mint, base_num> res;
            for (int base_id = 0; base_id < base_num; ++base_id) res[base_id] = hash[base_id][r] - hash[base_id][l] * pows[base_id][r - l];
            return res;
        }

        static auto mod() {
            return mint::mod();
        }

        static void set_bases(const std::array<mint, base_num> &id7) {
            bases = id7;
            pows = internal::rolling_hash::id12<base_num, mint>(bases);
        }

        template <typename Iterable, typename ToIntFunction>
        static RollingHash from(const Iterable &s, ToIntFunction f) {
            std::vector<int> a;
            for (auto &&e : s) a.push_back(f(e));
            return RollingHash(a);
        }
        static RollingHash from_lowercase_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return e - 'a' + 1; });
        }
        static RollingHash from_uppercase_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return e - 'A' + 1; });
        }
        static RollingHash from_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return std::islower(e) ? e - 'a' + 27 : e - 'A' + 1; });
        }
        static RollingHash from_digit(const std::string &s) {
            return from(s, [](const auto &e) { return e - '0' + 1; });
        }

    private:
        static inline std::array<mint, base_num> bases = internal::rolling_hash::id8<base_num, mint>();
        static inline std::array<id10<mint>, base_num> pows = internal::rolling_hash::id12<base_num, mint>(bases);

        int n;
        std::array<std::vector<mint>, base_num> hash;
    };
} 


using suisen::RollingHash;

long long solve(std::vector<std::string> s) {
    const int n = s.size();
    const int m = s[0].size();

    std::sort(s.begin(), s.end());

    std::vector<RollingHash<2>> hash(n);
    for (int i = 0; i < n; ++i) {
        hash[i] = RollingHash<2>::from_lowercase_alphabet(s[i]);
    }

    std::vector<int> p(n), q(n);
    std::iota(p.begin(), p.end(), 0);
    {
        std::vector<std::string> t;
        for (const auto& e : s) {
            auto ti = e;
            std::reverse(ti.begin(), ti.end());
            t.push_back(std::move(ti));
        }
        std::sort(p.begin(), p.end(), [&](int i, int j) { return t[i] < t[j]; });
    }
    for (int i = 0; i < n; ++i) {
        q[p[i]] = i;
    }

    id2<int, 18> wm(q);

    auto id6 = [&](int i, int x) {
        int il, ir;
        {
            auto h = hash[i](0, x);
            int l = -1, r = i;
            while (r - l > 1) {
                int p = (l + r) >> 1;
                (hash[p](0, x) != h ? l : r) = p;
            }
            il = r;
        }
        {
            auto h = hash[i](0, x);
            int l = i, r = n;
            while (r - l > 1) {
                int p = (l + r) >> 1;
                (hash[p](0, x) == h ? l : r) = p;
            }
            ir = r;
        }
        return std::make_pair(il, ir);
    };

    auto id4 = [&](int i, int x) {
        int vl, vr;
        {
            auto h = hash[i](x, m);
            int l = -1, r = q[i];
            while (r - l > 1) {
                int j = (l + r) >> 1;
                (hash[p[j]](x, m) != h ? l : r) = j;
            }
            vl = r;
        }
        {
            auto h = hash[i](x, m);
            int l = q[i], r = n;
            while (r - l > 1) {
                int j = (l + r) >> 1;
                (hash[p[j]](x, m) == h ? l : r) = j;
            }
            vr = r;
        }
        return std::make_pair(vl, vr);
    };

    auto count = [&](int i, int x, int y) -> int {
        auto [il, ir] = id6(i, x);
        auto [vl, vr] = id4(i, y);
        return wm.range_freq(il, ir, vl, vr);
    };

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l < m;) {
            int r = l + 1;
            while (r < m and s[i][r - 1] <= s[i][r]) ++r;

            int add = count(i, l, r);
            res += add - 1;
            l = r;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::array<int, 26>, std::vector<std::string>> mp;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        std::array<int, 26> cnt{};
        for (char c : s) ++cnt[c - 'a'];
        mp[cnt].push_back(s);
    }

    long long ans = 0;
    long long sub = 0;
    for (const auto& [c, s] : mp) {
        long long m = s.size();
        ans += (n - m) * m * 1337;
        ans += 2 * m * (m - 1);
        sub += solve(s);
    }

    std::cout << ans / 2 - sub << std::endl;
    return 0;
}

