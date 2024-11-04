
    
    





    

template <typename... T>
void debug(T&&...) {}


using ll = int64_t;
using ld = long double;

struct IOPre {
    static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
    std::array<char, 4 * SZ> num;
    constexpr IOPre() : num{} {
        for (int i = 0; i < SZ; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i * 4 + j] = static_cast<char>(n % TEN + '0');
                n /= TEN;
            }
        }
    }
};
struct IO {

    


    

    static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                         THOUSAND = HUNDRED * TEN, id7 = THOUSAND * TEN,
                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                         id1 = 12, SIXTEEN = 16;
    static constexpr IOPre io_pre = {};
    std::array<char, SZ> input_buffer, output_buffer;
    int id2, id10, id8;

    IO()
        : input_buffer{},
          output_buffer{},
          id2{},
          id10{},
          id8{} {}
    IO(const IO&) = delete;
    IO(IO&&) = delete;
    IO& operator=(const IO&) = delete;
    IO& operator=(IO&&) = delete;

    ~IO() { flush(); }

    template <class T>
    struct is_char {
        static constexpr bool value = std::is_same_v<T, char>;
    };

    template <class T>
    struct is_bool {
        static constexpr bool value = std::is_same_v<T, bool>;
    };

    template <class T>
    struct is_string {
        static constexpr bool value = std::is_same_v<T, std::string> ||
                                      std::is_same_v<T, const char*> ||
                                      std::is_same_v<T, char*>;
    };

    template <class T, class D = void>
    struct is_custom {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_custom<T, std::void_t<typename T::internal_value_type>> {
        static constexpr bool value = true;
    };

    template <class T>
    struct is_default {
        static constexpr bool value =
            is_char<T>::value || is_string<T>::value || std::is_integral_v<T>;
    };

    template <class T, class D = void>
    struct is_iterable {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_iterable<
        T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
        static constexpr bool value = true;
    };

    template <class T, class D = void, class E = void>
    struct is_applyable {
        static constexpr bool value = false;
    };

    template <class T>
    struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                        std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
        static constexpr bool value = true;
    };

    template <class T>
    static constexpr bool id9 = (is_iterable<T>::value ||
                                           is_applyable<T>::value) &&
                                          (!is_default<T>::value);

    template <typename T, typename U>
    struct any_needs_newline {
        static constexpr bool value = false;
    };
    template <typename T>
    struct any_needs_newline<T, std::index_sequence<>> {
        static constexpr bool value = false;
    };
    template <typename T, std::size_t I, std::size_t... Is>
    struct any_needs_newline<T, std::index_sequence<I, Is...>> {
        static constexpr bool value =
            id9<decltype(std::get<I>(std::declval<T>()))> ||
            any_needs_newline<T, std::index_sequence<Is...>>::value;
    };

    inline void load() {
        memmove(std::begin(input_buffer),
                std::begin(input_buffer) + id2,
                id10 - id2);
        id10 =
            id10 - id2 +
            static_cast<int>(fread_unlocked(
                std::begin(input_buffer) + id10 - id2, 1,
                SZ - id10 + id2, stdin));
        id2 = 0;
    }

    inline void read_char(char& c) {
        if (id2 + LEN > id10) load();
        c = input_buffer[id2++];
    }
    template <class T>
    inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
        if (id2 + LEN > id10) load();
        char c = 0;
        do c = input_buffer[id2++];
        while (c < '-');
        [[maybe_unused]] bool minus = false;
        if constexpr (std::is_signed<T>::value == true)
            if (c == '-') minus = true, c = input_buffer[id2++];
        x = 0;
        while (c >= '0')
            x = x * TEN + (c & MASK), c = input_buffer[id2++];
        if constexpr (std::is_signed<T>::value == true)
            if (minus) x = -x;
    }

    inline void skip_space() {
        if (id2 + LEN > id10) load();
        while (input_buffer[id2] <= ' ') id2++;
    }

    inline void flush() {
        fwrite_unlocked(std::begin(output_buffer), 1, id8, stdout);
        id8 = 0;
    }

    inline void write_char(char c) {
        if (id8 > SZ - LEN) flush();
        output_buffer[id8++] = c;
    }

    inline void write_bool(bool b) {
        if (id8 > SZ - LEN) flush();
        output_buffer[id8++] = b ? '1' : '0';
    }

    template <typename T>
    inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
        if (id8 > SZ - LEN) flush();
        if (!x) {
            output_buffer[id8++] = '0';
            return;
        }
        if constexpr (std::is_signed<T>::value == true)
            if (x < 0) output_buffer[id8++] = '-', x = -x;
        int i = id1;
        std::array<char, SIXTEEN> buf{};
        while (x >= id7) {
            memcpy(std::begin(buf) + i,
                   std::begin(io_pre.num) + (x % id7) * 4, 4);
            x /= id7;
            i -= 4;
        }
        if (x < HUNDRED) {
            if (x < TEN) {
                output_buffer[id8++] = static_cast<char>('0' + x);
            } else {
                std::uint32_t q =
                    (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
                    MAGIC_SHIFT;
                std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
                output_buffer[id8] = static_cast<char>('0' + q);
                output_buffer[id8 + 1] =
                    static_cast<char>('0' + r);
                id8 += 2;
            }
        } else {
            if (x < THOUSAND) {
                memcpy(std::begin(output_buffer) + id8,
                       std::begin(io_pre.num) + (x << 2) + 1, 3),
                    id8 += 3;
            } else {
                memcpy(std::begin(output_buffer) + id8,
                       std::begin(io_pre.num) + (x << 2), 4),
                    id8 += 4;
            }
        }
        memcpy(std::begin(output_buffer) + id8,
               std::begin(buf) + i + 4, id1 - i);
        id8 += id1 - i;
    }
    template <typename T_>
    IO& operator<<(T_&& x) {
        using T = typename std::remove_cv<
            typename std::remove_reference<T_>::type>::type;
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        if constexpr (is_custom<T>::value) {
            write_int(x.get());
        } else if constexpr (is_default<T>::value) {
            if constexpr (is_string<T>::value) {
                write_string(x);
            } else if constexpr (is_char<T>::value) {
                write_char(x);
            } else if constexpr (std::is_integral_v<T>) {
                write_int(x);
            }
        } else if constexpr (is_iterable<T>::value) {
            

            using E = decltype(*std::begin(x));
            constexpr char sep = id9<E> ? '\n' : ' ';
            int i = 0;
            for (const auto& y : x) {
                if (i++) write_char(sep);
                operator<<(y);
            }
        } else if constexpr (is_applyable<T>::value) {
            

            constexpr char sep =
                (any_needs_newline<
                    T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
                    ? '\n'
                    : ' ';
            int i = 0;
            std::apply(
                [this, &sep, &i](auto const&... y) {
                    (((i++ ? write_char(sep) : void()), this->operator<<(y)),
                     ...);
                },
                x);
        }
        return *this;
    }
    template <typename T>
    IO& operator>>(T& x) {
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        if constexpr (is_custom<T>::value) {
            typename T::internal_value_type y;
            read_int(y);
            x = y;
        } else if constexpr (is_default<T>::value) {
            if constexpr (is_string<T>::value) {
                read_string(x);
            } else if constexpr (is_char<T>::value) {
                read_char(x);
            } else if constexpr (std::is_integral_v<T>) {
                read_int(x);
            }
        } else if constexpr (is_iterable<T>::value) {
            for (auto& y : x) operator>>(y);
        } else if constexpr (is_applyable<T>::value) {
            std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
        }
        return *this;
    }

    IO* tie(std::nullptr_t) { return this; }
    void sync_with_stdio(bool) {}
};
IO io;



constexpr int mod = int(1e9) + 7;
constexpr int id6 = 998'244'353;

template <std::uint32_t P>
struct id4 {
   public:
    using i32 = std::int32_t;
    using u32 = std::uint32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    using m32 = id4;
    using internal_value_type = u32;

   private:
    u32 v;
    static constexpr u32 get_r() {
        u32 iv = P;
        for (u32 i = 0; i != 4; ++i) iv *= 2U - P * iv;
        return -iv;
    }
    static constexpr u32 r = get_r(), r2 = -u64(P) % P;
    static_assert((P & 1) == 1);
    static_assert(-r * P == 1);
    static_assert(P < (1 << 30));
    static constexpr u32 pow_mod(u32 x, u64 y) {
        u32 res = 1;
        for (; y != 0; y >>= 1, x = u64(x) * x % P)
            if (y & 1) res = u64(res) * x % P;
        return res;
    }
    static constexpr u32 reduce(u64 x) {
        return (x + u64(u32(x) * r) * P) >> 32;
    }
    static constexpr u32 norm(u32 x) { return x - (P & -(x >= P)); }

   public:
    static constexpr u32 get_pr() {
        u32 tmp[32] = {}, cnt = 0;
        const u64 phi = P - 1;
        u64 m = phi;
        for (u64 i = 2; i * i <= m; ++i)
            if (m % i == 0) {
                tmp[cnt++] = i;
                while (m % i == 0) m /= i;
            }
        if (m != 1) tmp[cnt++] = m;
        for (u64 res = 2; res != P; ++res) {
            bool flag = true;
            for (u32 i = 0; i != cnt && flag; ++i)
                flag &= pow_mod(res, phi / tmp[i]) != 1;
            if (flag) return res;
        }
        return 0;
    }
    constexpr id4() : v(0){};
    ~id4() = default;
    constexpr id4(u32 _v) : v(reduce(u64(_v) * r2)) {}
    constexpr id4(i32 _v) : v(reduce(u64(_v % P + P) * r2)) {}
    constexpr id4(u64 _v) : v(reduce((_v % P) * r2)) {}
    constexpr id4(i64 _v) : v(reduce(u64(_v % P + P) * r2)) {}
    constexpr id4(const m32& rhs) : v(rhs.v) {}
    constexpr u32 get() const { return norm(reduce(v)); }
    explicit constexpr operator u32() const { return get(); }
    explicit constexpr operator i32() const { return i32(get()); }
    constexpr m32& operator=(const m32& rhs) { return v = rhs.v, *this; }
    constexpr m32 operator-() const {
        m32 res;
        return res.v = (P << 1 & -(v != 0)) - v, res;
    }
    constexpr m32 inv() const { return pow(P - 2); }
    constexpr m32& operator+=(const m32& rhs) {
        return v += rhs.v - (P << 1), v += P << 1 & -(v >> 31), *this;
    }
    constexpr m32& operator-=(const m32& rhs) {
        return v -= rhs.v, v += P << 1 & -(v >> 31), *this;
    }
    constexpr m32& operator*=(const m32& rhs) {
        return v = reduce(u64(v) * rhs.v), *this;
    }
    constexpr m32& operator/=(const m32& rhs) {
        return this->operator*=(rhs.inv());
    }
    friend m32 operator+(const m32& lhs, const m32& rhs) {
        return m32(lhs) += rhs;
    }
    friend m32 operator-(const m32& lhs, const m32& rhs) {
        return m32(lhs) -= rhs;
    }
    friend m32 operator*(const m32& lhs, const m32& rhs) {
        return m32(lhs) *= rhs;
    }
    friend m32 operator/(const m32& lhs, const m32& rhs) {
        return m32(lhs) /= rhs;
    }
    friend bool operator==(const m32& lhs, const m32& rhs) {
        return norm(lhs.v) == norm(rhs.v);
    }
    friend bool operator!=(const m32& lhs, const m32& rhs) {
        return norm(lhs.v) != norm(rhs.v);
    }
    friend std::istream& operator>>(std::istream& is, m32& rhs) {
        return is >> rhs.v, rhs.v = reduce(u64(rhs.v) * r2), is;
    }
    friend std::ostream& operator<<(std::ostream& os, const m32& rhs) {
        return os << rhs.get();
    }
    constexpr m32 pow(i64 y) const {
        

        i64 rem = y % (P - 1);
        if (y > 0 && rem == 0)
            y = P - 1;
        else
            y = rem;
        m32 res(1), x(*this);
        for (; y != 0; y >>= 1, x *= x)
            if (y & 1) res *= x;
        return res;
    }
};

using mint = id4<mod>;

using namespace std;

using ll = int64_t;
using ld = long double;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    

    int _tests = 1;
    

    for (ll _test = 1; _test <= _tests; ++_test) {
        

        int n;
        cin >> n;
        vector<int> a(1 << n);
        vector p(n, vector<mint>(n));
        {
            vector<mint> s(n);
            cin >> s;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) p[i][j] = s[i] / (s[i] + s[j]);
        }
        vector<mint> id3(1 << n, 1);
        vector id0(1 << n, vector<mint>(n, 1));
        for (int i = 0; i < n; ++i) {
            for (int mask = 1; mask < (1 << n); ++mask) {
                int j = __lg(mask);
                id0[mask][i] =
                    id0[mask ^ (1 << j)][i] * p[i][j];
            }
        }
        mint ans = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i)
                if (mask >> i & 1)
                    for (int j = 0; j < n; ++j)
                        if (!(mask >> j & 1)) id3[mask] *= p[i][j];
            int unmask = mask ^ ((1 << n) - 1);
            const auto& id5 = id0[unmask];
            for (int submask = (mask - 1) & mask; submask;
                 (--submask) &= mask) {
                mint winprob = id3[submask];
                for (int i = 0; i < n; ++i)
                    if ((mask >> i & 1) && !(submask >> i & 1))
                        winprob *= id5[i];
                id3[mask] -= winprob;
            }
            ans += id3[mask] * __builtin_popcount(mask);
        }
        cout << ans << '\n';
    }
}

