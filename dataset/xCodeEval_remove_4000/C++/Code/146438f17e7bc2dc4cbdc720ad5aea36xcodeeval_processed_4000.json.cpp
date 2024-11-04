



















using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }




template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;


struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using iter_value_t = typename iterator_traits<remove_cvref_t<T>>::value_type;


namespace cp_lib_type_meta {
    template <class T, class = void> constexpr bool id5 = false;
    template <class T> constexpr bool id5<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
template <class T> constexpr bool id1 = is_base_of_v<cp_lib_modint::ModIntTag, T>;


namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    constexpr array<array<char, 4>, 10'000> DIGITS = []{
        array<array<char, 4>, 10'000> digits{};
        for (int i = 3, d = 1; i >= 0; --i, d *= 10)
            rep(j, 10'000)
                digits[j][i] = char('0' + j / d % 10);
        return digits;
    }();
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> constexpr bool id6 = false;
    template <class T, size_t I> constexpr bool id6<array<T, I>> = true;

    void flush() {
        for (auto* p = begin(obuf); p != optr; p += write(STDOUT_FILENO, p, optr - p));
        optr = begin(obuf);
    }
    int id3 = []{ atexit(flush); return 0; }();

    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - 1 - iend);
        *iend = '\0';
    }

    template <class T, class T2 = remove_cvref_t<T>>
    void print(T&& val) {
        if (end(obuf) - optr < 64)
            flush();

        if constexpr (is_same_v<T2, char>)
            *optr++ = val;
        else if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
            return print(int(val));
        else if constexpr (is_integral_v<T2> && is_signed_v<T2>) {
            if (val < 0)
                *optr++ = '-';
            using U = make_unsigned_t<T2>;
            return print(U(val < 0 ? -U(val) : U(val)));
        } else if constexpr (is_integral_v<T2> && is_unsigned_v<T2>) {
            T2 val2 = val;
            array<char, 64> tmp;
            char* tptr = end(tmp);
            while (val2 >= 10'000)
                tptr -= 4, memcpy(tptr, &DIGITS[val2 % 10'000][0], 4), val2 /= T2(10'000);
            int d = (val2 >= 100 ? (val2 >= 1000 ? 4 : 3) : (val2 >= 10 ? 2 : 1));
            memcpy(optr, &DIGITS[val2][4 - d], d);
            memcpy(optr + d, tptr, end(tmp) - tptr);
            optr += d + int(end(tmp) - tptr);
        } else if constexpr (is_floating_point_v<T2>)
            optr += sprintf(optr, "%.30Lf", (long double)val);
        else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else {
                flush();
                for (auto *p = data(sv), *pe = p + sz(sv); p != pe; p += write(STDOUT_FILENO, p, pe - p));
            }
        } else if constexpr (id1<T2>)
            return print(typename T2::Int(val));
        else if constexpr (cp_lib_type_meta::id5<T2> && !id6<T2>)
            return apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
        else {
            trav(item, val)
                print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        auto skip_ws = [] {
            do {
                for (; iptr != iend && *iptr <= ' '; ++iptr);
                if (iend - iptr < 64)
                    refill();
            } while (*iptr <= ' ');
        };
        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            skip_ws(), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (id1<T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            skip_ws();
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            skip_ws(), val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            skip_ws();
            val.clear();
            do {
                auto* after = find_if(iptr, iend, [](char c) { return c <= ' '; });
                val.append(iptr, after);
                if ((iptr = after) != iend)
                    break;
                refill();
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::id5<T> && !id6<T>)
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val)
                read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args))
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        print('\n'), --cp_lib_io::optr;
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }





    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << 
        ::abort(); \
    } } while (0)





template <class I>
constexpr enable_if_t<is_signed_v<I>, array<I, 3>> id2(I a, I b) {
    I x(1), y(0), x1(0), y1(1);
    while (b) {
        I t = a / b;
        tie(x, x1) = pair(x1, x - t * x1);
        tie(y, y1) = pair(y1, y - t * y1);
        tie(a, b) = pair(b, a - t * b);
    }
    return {a, x, y};
}

template <bool> class Hasher;

namespace cp_lib_modint {
    template <class Self, class Int_, bool Lazy>
    struct Base : ModIntTag {
        using Int = Int_;
        static_assert(is_same_v<Int, uint32_t> || is_same_v<Int, uint64_t>);
        template <bool> friend class ::Hasher;

        friend constexpr Self operator+(Self l, Self r) { return l += r; }
        friend constexpr Self operator-(Self l, Self r) { return l -= r; }
        friend constexpr Self operator*(Self l, Self r) { return l *= r; }
        friend constexpr Self operator/(Self l, Self r) { return l * r.inv(); }
        friend constexpr Self& operator/=(Self& l, Self r) { return l *= r.inv(); }
        friend constexpr Self operator+(Self x) { return x; }
        friend constexpr Self operator-(Self x) { return Self(0) - x; }
        friend constexpr Self& operator++(Self& x) { return x += Self(1); }
        friend constexpr Self& operator--(Self& x) { return x -= Self(1); }
        friend constexpr Self operator++(Self& x, int) { auto y = x; ++x; return y; }
        friend constexpr Self operator--(Self& x, int) { auto y = x; --x; return y; }
        friend constexpr bool operator==(Self l, Self r) { return normed(l.i) == normed(r.i); }
        friend constexpr bool operator!=(Self l, Self r) { return normed(l.i) != normed(r.i); }
        friend constexpr bool operator<(Self l, Self r) { return normed(l.i) < normed(r.i); }


        template <class T, enable_if_t<is_integral_v<T>, int> = 0> \
        friend constexpr auto operator op(T l, Self r) { return Self(l) op r; }
        CP_LIB_DEF(==) CP_LIB_DEF(!=) CP_LIB_DEF(<) CP_LIB_DEF(+) CP_LIB_DEF(-) CP_LIB_DEF(*) CP_LIB_DEF(/)


        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Self> pow(T e) const {
            Self r(1), b(*(Self*)(this));
            for (; e; b *= b, e >>= 1)
                if (e & 1) r *= b;
            return r;
        }

        constexpr optional<Self> try_inv() const {
            if (Self::is_prime())
                return *(Self*)this == Self() ? nullopt : optional(pow(Self::mod() - 2));
            auto [g, x, _] = id2(ll(*(Self*)this), ll(Self::mod()));
            return (g == 1 || g == -1 ? optional(Self(x)) : nullopt);
        }
        constexpr Self inv() const {
            if (Self::is_prime())
                return pow(Self::mod() - 2);
            auto [g, x, _] = id2(ll(*(Self*)this), ll(Self::mod()));
            cp_lib_assert(g == 1 || g == -1);
            return x;
        }

        friend ostream& operator<<(ostream& out, Self m) { return out << uint64_t(m); }
        friend istream& operator>>(istream& in, Self& m) { ll x; in >> x; m = x; return in; }

     protected:
        constexpr static Int_ normed(Int_ x) { return Lazy && x >= Self::mod() ? x - Self::mod() : x; }

        Int i = 0;
    };

    template <class Int> using Wide = conditional_t<is_same_v<uint64_t, Int>, unsigned __int128, uint64_t>;
}

namespace cp_lib_modint {
    template <class Int, Int Mod, bool IsPrime>
    class id0 : public Base<id0<Int, Mod, IsPrime>, Int, true> {
        static_assert(Mod % 2 && Mod < (1ull << (sizeof(Int) * 8 - 2)));
        static constexpr Int INV = []{
            Int inv = Mod;
            rep(_, __builtin_ctz(sizeof(Int) * 8) - 1)
                inv *= 2 - Mod * inv;
            return inv;
        }();
        static constexpr Int R2 = Int(-Wide<Int>(Mod) % Mod);
        static constexpr Int reduce(Wide<Int> x) {
            return Int((x - Int(x) * INV * Wide<Int>(Mod)) >> (sizeof(Int) * 8)) + Mod;
        }

     public:
        static constexpr Int mod() { return Mod; }
        static constexpr bool is_prime() { return IsPrime; }

        id0() = default;
        template <class T, enable_if_t<is_unsigned_v<T>, int> = 0>
        constexpr id0(T x) { this->i = reduce(Wide<Int>(uint64_t(x) % Mod) * R2); }
        template <class T, enable_if_t<is_signed_v<T>, int> = 0>
        constexpr id0(T x) { this->i = reduce(Wide<Int>(ll(x) % ll(Mod) + ll(Mod)) * R2); }

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        constexpr explicit operator T() const { return T(this->normed(reduce(this->i))); }

        constexpr id0& operator+=(id0 r) {
            if ((this->i += r.i) >= 2 * Mod)
                this->i -= 2 * Mod;
            return *this;
        }
        constexpr id0& operator-=(id0 r) {
            if (make_signed_t<Int>(this->i -= r.i) < 0)
                this->i += 2 * Mod;
            return *this;
        }
        constexpr id0& operator*=(id0 r) {
            this->i = reduce(Wide<Int>(this->i) * r.i);
            return *this;
        }
    };
}

template <uint32_t Mod, bool IsPrime> using StaticMontgomeryInt = cp_lib_modint::id0<uint32_t, Mod, IsPrime>;
template <uint64_t Mod, bool IsPrime> using StaticMontgomeryInt64 = cp_lib_modint::id0<uint64_t, Mod, IsPrime>;


[[maybe_unused]] static mt19937 rng(uint32_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

constexpr int N = int(3e6);
constexpr int K = 32;  

constexpr auto F = []{
    array<int, K> f{};
    f[0] = f[1] = 1;
    rep(i, 2, K)
        f[i] = f[i - 1] + f[i - 2];
    return f;
}();

using Hash = StaticMontgomeryInt64<(1ull << 62) - 10565, true>;
static Hash A = []{
    Hash a = 0;
    while (uint64_t(a) < (1ull << 61))
        a = ((uint64_t(rng()) << 29) ^ rng()) | (1ull << 61);
    return a;
}();

bitset<N> bs, keep;
int m = 0;

template <class Callback>
void id4(Callback&& f) {
    array<Hash, K> h{}, apow{};
    apow.fill(1);
    auto a_inv = A.inv();

    rep(i, m) {
        rep(j, 32) {
            if (i >= F[j])
                h[j] = (h[j] - int(bs[i - F[j]])) * a_inv;
            h[j] += apow[j] * int(bs[i]);
            if (i + 1 < F[j])
                apow[j] *= A;
        }

        f(i, h);
    }
}

int main() {
    int n; read(n);
    vector l(n, 0);
    rep(i, n) {
        string s; read(s);
        trav(c, s)
            bs[m++] = c == '1';
        l[i] = m;
    }

    array<Hash, K> f_hash{};
    f_hash[1] = 1;
    rep(i, 2, K)
        f_hash[i] = f_hash[i - 1] + f_hash[i - 2] * A.pow(F[i - 1]);

    constexpr int HIST = 100;
    constexpr int NUM_LOW = []{
        int c = 0;
        trav(fi, F)
            c += fi < HIST;
        return c;
    }();

    id4([&](int i, const auto& h) {
        rep(j, NUM_LOW, K)
            if (i >= F[j])
                keep[i - F[j]] = keep[i - F[j]] || h[j] == f_hash[j];
    });

    using MI = StaticMontgomeryInt<998'244'353, true>;
    int done = 0;
    deque dp_hist(HIST, MI(0));
    MI dp_sum = dp_hist[0] = 1;
    map<int, MI> kept;
    kept[-1] = dp_hist[0];
    id4([&](int i, const auto& h) {
        dp_hist.pop_back();
        MI& new_dp = dp_hist.emplace_front(dp_sum);
        rep(j, K) {
            if (i + 1 < F[j] || h[j] != f_hash[j])
                continue;
            new_dp -= j < NUM_LOW ? dp_hist[F[j]] : kept[i - F[j]];
        }

        dp_sum += new_dp;
        if (keep[i])
            kept[i] = new_dp;

        if (i + 1 == l[done])
            println(new_dp), ++done;
    });
}
