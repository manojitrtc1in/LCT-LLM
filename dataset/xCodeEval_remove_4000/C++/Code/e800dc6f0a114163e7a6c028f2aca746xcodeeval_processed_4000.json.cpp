
    
    







    

    


using ll = int64_t;
using ull = uint64_t;
using ld = long double;

using namespace std;

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
                         THOUSAND = HUNDRED * TEN, id5 = THOUSAND * TEN,
                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                         id0 = 12, SIXTEEN = 16;
    static constexpr IOPre io_pre = {};
    std::array<char, SZ> input_buffer, output_buffer;
    int id1, id8, id6;

    IO()
        : input_buffer{},
          output_buffer{},
          id1{},
          id8{},
          id6{} {}
    IO(const IO&) = delete;
    IO(IO&&) = delete;
    IO& operator=(const IO&) = delete;
    IO& operator=(IO&&) = delete;

    ~IO() {
        flush();
    }

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
        static constexpr bool value =
            std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
            std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
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
        static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                      is_string<T>::value ||
                                      std::is_integral_v<T>;
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
    static constexpr bool id7 = (is_iterable<T>::value ||
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
            id7<decltype(std::get<I>(std::declval<T>()))> ||
            any_needs_newline<T, std::index_sequence<Is...>>::value;
    };

    inline void load() {
        memmove(std::begin(input_buffer),
                std::begin(input_buffer) + id1,
                id8 - id1);
        id8 =
            id8 - id1 +
            static_cast<int>(fread_unlocked(
                std::begin(input_buffer) + id8 - id1, 1,
                SZ - id8 + id1, stdin));
        id1 = 0;
    }

    inline void read_char(char& c) {
        if (id1 + LEN > id8) load();
        c = input_buffer[id1++];
    }
    inline void read_string(std::string& x) {
        char c;
        while (read_char(c), c < '!') continue;
        x = c;
        while (read_char(c), c >= '!') x += c;
    }
    template <class T>
    inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
        if (id1 + LEN > id8) load();
        char c = 0;
        do c = input_buffer[id1++];
        while (c < '-');
        [[maybe_unused]] bool minus = false;
        if constexpr (std::is_signed<T>::value == true)
            if (c == '-') minus = true, c = input_buffer[id1++];
        x = 0;
        while (c >= '0')
            x = x * TEN + (c & MASK), c = input_buffer[id1++];
        if constexpr (std::is_signed<T>::value == true)
            if (minus) x = -x;
    }

    inline void skip_space() {
        if (id1 + LEN > id8) load();
        while (input_buffer[id1] <= ' ') id1++;
    }

    inline void flush() {
        fwrite_unlocked(std::begin(output_buffer), 1, id6, stdout);
        id6 = 0;
    }

    inline void write_char(char c) {
        if (id6 > SZ - LEN) flush();
        output_buffer[id6++] = c;
    }

    inline void write_bool(bool b) {
        if (id6 > SZ - LEN) flush();
        output_buffer[id6++] = b ? '1' : '0';
    }

    inline void write_string(const std::string& s) {
        for (auto x : s) write_char(x);
    }

    inline void write_string(const char* s) {
        while (*s) write_char(*s++);
    }

    inline void write_string(char* s) {
        while (*s) write_char(*s++);
    }

    template <typename T>
    inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
        if (id6 > SZ - LEN) flush();
        if (!x) {
            output_buffer[id6++] = '0';
            return;
        }
        if constexpr (std::is_signed<T>::value == true)
            if (x < 0) output_buffer[id6++] = '-', x = -x;
        int i = id0;
        std::array<char, SIXTEEN> buf{};
        while (x >= id5) {
            memcpy(std::begin(buf) + i,
                   std::begin(io_pre.num) + (x % id5) * 4, 4);
            x /= id5;
            i -= 4;
        }
        if (x < HUNDRED) {
            if (x < TEN) {
                output_buffer[id6++] = static_cast<char>('0' + x);
            } else {
                std::uint32_t q =
                    (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
                    MAGIC_SHIFT;
                std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
                output_buffer[id6] = static_cast<char>('0' + q);
                output_buffer[id6 + 1] =
                    static_cast<char>('0' + r);
                id6 += 2;
            }
        } else {
            if (x < THOUSAND) {
                memcpy(std::begin(output_buffer) + id6,
                       std::begin(io_pre.num) + (x << 2) + 1, 3),
                    id6 += 3;
            } else {
                memcpy(std::begin(output_buffer) + id6,
                       std::begin(io_pre.num) + (x << 2), 4),
                    id6 += 4;
            }
        }
        memcpy(std::begin(output_buffer) + id6,
               std::begin(buf) + i + 4, id0 - i);
        id6 += id0 - i;
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
            if constexpr (is_bool<T>::value) {
                write_bool(x);
            } else if constexpr (is_string<T>::value) {
                write_string(x);
            } else if constexpr (is_char<T>::value) {
                write_char(x);
            } else if constexpr (std::is_integral_v<T>) {
                write_int(x);
            }
        } else if constexpr (is_iterable<T>::value) {
            

            using E = decltype(*std::begin(x));
            constexpr char sep = id7<E> ? '\n' : ' ';
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
        static_assert(!is_bool<T>::value);
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

    IO* tie(std::nullptr_t) {
        return this;
    }
    void sync_with_stdio(bool) {}
};
IO io;



template <int n>
struct st_wrapper {
    template <class Node, class Update, class CombineNodes, class ApplyUpdate>
    struct id4 {
        static constexpr int log = [] {
            int x = 0;
            while ((1 << x) < n) ++x;
            return x;
        }();
        static constexpr int size = 1 << log;

       public:
        template <typename... T>
        explicit id4(const Node& _id_node,
                              const CombineNodes& _combine,
                              const Update& _id_update,
                              const ApplyUpdate& _apply_update)
            : combine{_combine},
              id_node{_id_node},
              apply_update{_apply_update},
              id_update{_id_update},
              d{} {}

        void set(int p, Node x) {
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; ++i) update(p >> i);
        }

        Node get(int p) {
            p += size;
            return d[p];
        }

        Node query(int l, int r) {
            if (l == r) return id_node;
            l += size, r += size;
            Node sml = id_node, smr = id_node;
            while (l < r) {
                if (l & 1) sml = combine(sml, d[l++]);
                if (r & 1) smr = combine(d[--r], smr);
                l >>= 1, r >>= 1;
            }
            return combine(sml, smr);
        }

        Node all_query() const { return d[1]; }

        void update(int p, Update f) {
            p += size;
            d[p] = apply_update(f, d[p]);
            for (int i = 1; i <= log; ++i) update(p >> i);
        }

        void update(int l, int r, Update f) {
            if (l == r) return;
            l += size, r += size;
            const int id2 = __builtin_ctz(l);
            const int id3 = __builtin_ctz(r);
            {
                const int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1, r >>= 1;
                }
                l = l2, r = r2;
            }
            for (int i = id2 + 1; i <= log; ++i) update(l >> i);
            for (int i = id3 + 1; i <= log; ++i) update((r - 1) >> i);
        }

        template <class G>
        int max_right(int l, G g) {
            if (l == n) return n;
            l += size;
            Node sm = id_node;
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(combine(sm, d[l]))) {
                    while (l < size) {
                        l = (2 * l);
                        if (g(combine(sm, d[l]))) {
                            sm = combine(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = combine(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return n;
        }

        template <class G>
        int min_left(int r, G g) {
            if (r == 0) return 0;
            r += size;
            Node sm = id_node;
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(combine(d[r], sm))) {
                    while (r < size) {
                        r = (2 * r + 1);
                        if (g(combine(d[r], sm))) {
                            sm = combine(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = combine(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }

       private:
        CombineNodes combine;
        Node id_node;
        ApplyUpdate apply_update;
        Update id_update;
        std::array<Node, 2 * size> d;

        void update(int k) { d[k] = combine(d[2 * k], d[2 * k + 1]); }
        void all_apply(int k, Update f) { d[k] = apply_update(f, d[k]); }
    };
};

using Base = char;
struct Node {
    int l{}, r{};
    ll m{};
};
constexpr Node id_node{};
constexpr auto combine = [](const Node& l, const Node& r) -> Node {
    return Node{l.l + r.l, l.r + r.r, l.m + r.m + ll(l.r) * r.l};
};
struct Update {
    int dl{}, dr{};
};
constexpr Update id_update{};
constexpr auto apply_update = [](const Update& u, Node n) -> Node {
    n.l += u.dl;
    n.r += u.dr;
    n.m = n.l && n.r;
    return n;
};
constexpr int N = 400'000;

constexpr auto G = [](int x) {
    return ll(x) * (x - 1) / 2;
};

st_wrapper<2 * N>::id4 st{id_node, combine, id_update, apply_update};
char x[N];

int main() {
    int q, d;
    cin >> q >> d;
    if (d == 1) {
        while (q--) cout << "0\n";
    } else {
        ll ans = 0;
        while (q--) {
            int i;
            cin >> i;
            --i;
            int factor = x[i] ? -1 : 1;
            x[i] ^= 1;
            long long delta = G(st.query(max(0, i - d), i).r) +
                              G(st.query(i + 1, i + d + 1).r);
            delta += st.query(i + 1, i + d).m;
            ans += delta * factor;
            st.update(i, {0, factor});
            st.update(i + d, {factor, 0});
            cout << ans << '\n';
        }
    }
}

