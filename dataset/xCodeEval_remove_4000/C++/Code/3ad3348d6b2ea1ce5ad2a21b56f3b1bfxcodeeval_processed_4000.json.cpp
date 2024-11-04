
    
    







    

    


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
                         THOUSAND = HUNDRED * TEN, id2 = THOUSAND * TEN,
                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                         id0 = 12, SIXTEEN = 16;
    static constexpr IOPre io_pre = {};
    std::array<char, SZ> input_buffer, output_buffer;
    int id1, id6, id3;

    IO()
        : input_buffer{},
          output_buffer{},
          id1{},
          id6{},
          id3{} {}
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
        static constexpr bool value =
            std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
            std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
        ;
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
    static constexpr bool id4 = (is_iterable<T>::value ||
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
            id4<decltype(std::get<I>(std::declval<T>()))> ||
            any_needs_newline<T, std::index_sequence<Is...>>::value;
    };

    inline void load() {
        memmove(std::begin(input_buffer),
                std::begin(input_buffer) + id1,
                id6 - id1);
        id6 =
            id6 - id1 +
            static_cast<int>(fread_unlocked(
                std::begin(input_buffer) + id6 - id1, 1,
                SZ - id6 + id1, stdin));
        id1 = 0;
    }

    inline void read_char(char& c) {
        if (id1 + LEN > id6) load();
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
        if (id1 + LEN > id6) load();
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
        if (id1 + LEN > id6) load();
        while (input_buffer[id1] <= ' ') id1++;
    }

    inline void flush() {
        fwrite_unlocked(std::begin(output_buffer), 1, id3, stdout);
        id3 = 0;
    }

    inline void write_char(char c) {
        if (id3 > SZ - LEN) flush();
        output_buffer[id3++] = c;
    }

    inline void write_bool(bool b) {
        if (id3 > SZ - LEN) flush();
        output_buffer[id3++] = b ? '1' : '0';
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
        if (id3 > SZ - LEN) flush();
        if (!x) {
            output_buffer[id3++] = '0';
            return;
        }
        if constexpr (std::is_signed<T>::value == true)
            if (x < 0) output_buffer[id3++] = '-', x = -x;
        int i = id0;
        std::array<char, SIXTEEN> buf{};
        while (x >= id2) {
            memcpy(std::begin(buf) + i,
                   std::begin(io_pre.num) + (x % id2) * 4, 4);
            x /= id2;
            i -= 4;
        }
        if (x < HUNDRED) {
            if (x < TEN) {
                output_buffer[id3++] = static_cast<char>('0' + x);
            } else {
                std::uint32_t q =
                    (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
                    MAGIC_SHIFT;
                std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
                output_buffer[id3] = static_cast<char>('0' + q);
                output_buffer[id3 + 1] =
                    static_cast<char>('0' + r);
                id3 += 2;
            }
        } else {
            if (x < THOUSAND) {
                memcpy(std::begin(output_buffer) + id3,
                       std::begin(io_pre.num) + (x << 2) + 1, 3),
                    id3 += 3;
            } else {
                memcpy(std::begin(output_buffer) + id3,
                       std::begin(io_pre.num) + (x << 2), 4),
                    id3 += 4;
            }
        }
        memcpy(std::begin(output_buffer) + id3,
               std::begin(buf) + i + 4, id0 - i);
        id3 += id0 - i;
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
            constexpr char sep = id4<E> ? '\n' : ' ';
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

    IO* tie(std::nullptr_t) { return this; }
    void sync_with_stdio(bool) {}
};
IO io;



struct Random : std::mt19937 {
    using std::mt19937::mt19937;
    using std::mt19937::operator();
    static int64_t gen_seed() {
        return std::chrono::steady_clock::now().time_since_epoch().count();
    }
    Random() : std::mt19937(gen_seed()) {}
    template <class Int>
    auto operator()(Int a, Int b)
        -> std::enable_if_t<std::is_integral_v<Int>, Int> {
        return std::uniform_int_distribution<Int>(a, b)(*this);
    }
    template <class Int>
    auto operator()(Int a) -> std::enable_if_t<std::is_integral_v<Int>, Int> {
        return std::uniform_int_distribution<Int>(0, a - 1)(*this);
    }
    template <class Real>
    auto operator()(Real a, Real b)
        -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
        return std::uniform_real_distribution<Real>(a, b)(*this);
    }
};

template <bool ToShuffle = false>
struct id5 {
   public:
    id5(int _n_left, int _n_right)
        : n_left(_n_left),
          n_right(_n_right),
          g(_n_left),
          match_from_left(_n_left, -1),
          match_from_right(_n_right, -1),
          dist(_n_left) {}

    void add(int u, int v) { g[u].push_back(v); }

    int get_max_matching() {
        if (!computed) compute_max_matching();
        return flow;
    }

    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_cover() {
        if (!computed) compute_max_matching();
        std::vector<int> L, R;
        for (int u = 0; u < n_left; ++u) {
            if (!~dist[u])
                L.push_back(u);
            else if (~match_from_left[u])
                R.push_back(match_from_left[u]);
        }
        return {L, R};
    }

    std::vector<std::pair<int, int>> get_edges() {
        if (!computed) compute_max_matching();
        std::vector<std::pair<int, int>> ans;
        for (int u = 0; u < n_left; ++u)
            if (match_from_left[u] != -1)
                ans.emplace_back(u, match_from_left[u]);
        return ans;
    }

   private:
    template <class T>
    struct simple_queue {
        std::vector<T> payload;
        int pos = 0;
        void reserve(int n) { payload.reserve(n); }
        int size() const { return int(payload.size()) - pos; }
        bool empty() const { return pos == int(payload.size()); }
        void push(const T& t) { payload.push_back(t); }
        T& front() { return payload[pos]; }
        void clear() { payload.clear(), pos = 0; }
        void pop() { pos++; }
    };

    int n_left, n_right, flow = 0;
    bool computed = false;
    std::vector<std::basic_string<int>> g;
    std::vector<int> match_from_left, match_from_right;
    std::vector<int> dist;

    void bfs() {
        std::queue<int> q;
        for (int u = 0; u < n_left; ++u) {
            if (!~match_from_left[u])
                q.push(u), dist[u] = 0;
            else
                dist[u] = -1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
                if (~match_from_right[v] && !~dist[match_from_right[v]]) {
                    dist[match_from_right[v]] = dist[u] + 1;
                    q.push(match_from_right[v]);
                }
        }
    }

    bool dfs(int u) {
        for (auto v : g[u])
            if (!~match_from_right[v]) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        for (auto v : g[u])
            if (dist[match_from_right[v]] == dist[u] + 1 &&
                dfs(match_from_right[v])) {
                match_from_left[u] = v, match_from_right[v] = u;
                return true;
            }
        return false;
    }

    void compute_max_matching() {
        if constexpr (ToShuffle) {
            Random rng;
            for (int i = 0; i < n_left; ++i)
                std::random_shuffle(std::begin(g[i]), std::end(g[i]), rng);
        }
        while (true) {
            bfs();
            int augment = 0;
            for (int u = 0; u < n_left; ++u)
                if (!~match_from_left[u]) augment += dfs(u);
            if (!augment) break;
            flow += augment;
        }
        computed = true;
    }
};

constexpr int N = 50005;
std::array<std::basic_string<int>, N> d;
std::array<int, N> id, a;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    


    id.fill(-1);
    for (int i = 1; i < N; ++i)
        for (int j = 2 * i; j < N; j += i) d[j].push_back(i);

    int _tests;
    cin >> _tests;

    for (int _test = 1; _test <= _tests; ++_test) {
        

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            id[a[i]] = i;
        }
        id5<true> b(2 * n, 2 * n);
        for (int i = 0; i < n; ++i) {
            for (auto m : d[a[i]]) {
                if (id[m] != -1) {
                    int j = id[m];
                    b.add(j, i);
                    b.add(n + j, n + i);
                }
            }
            b.add(i, n + i);
        }
        cout << b.get_max_matching() - n << '\n';
        for (int i = 0; i < n; ++i) id[a[i]] = -1;
    }
}

