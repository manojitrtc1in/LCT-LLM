






#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"



using namespace __gnu_pbds;


using namespace std;

using ll = long long;



#define unordered_map gp_hash_table
#define cauto const auto

template <typename T>
void ignore_unused(const T &) {}
#ifdef DEBUG
#define debug(args...)                               \
    {                                                \
        std::string _s = #args;                      \
        replace(_s.begin(), _s.end(), ',', ' ');     \
        std::stringstream _ss(_s);                   \
        std::istream_iterator<std::string> _it(_ss); \
        err(_it, args);                              \
    }
#define print_container(v)          \
    {                               \
        bool first = true;          \
        os << "[";                  \
        for (auto x : v) {          \
            if (!first) os << ", "; \
            os << x;                \
            first = false;          \
        }                           \
        return os << "]";           \
    }
void err(std::istream_iterator<std::string> it) { ignore_unused(it); }
template <typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cerr << *it << " = " << a << std::endl;
    err(++it, args...);
}




template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::vector<T>& v) { print_container(v); }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::set<T>& v) { print_container(v); }
template <typename T1, typename T2> inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v) { print_container(v); }
template <typename T1, typename T2, class C> inline std::ostream &operator << (std::ostream & os, const unordered_map<T1, T2, C>& v) { print_container(v); }
template <typename T, class C> inline std::ostream &operator << (std::ostream & os, const unordered_set<T, C>& v) { print_container(v); }
template <typename T1, typename T2> inline std::ostream &operator << (std::ostream & os, const std::multimap<T1, T2>& v) { print_container(v); }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::multiset<T>& v) { print_container(v); }
#else
#define debug(args...) 0
#endif

template <typename X, typename Y> X &remin(X &x, const Y &y) { return x = (y < x) ? y : x; }
template <typename X, typename Y> X &remax(X &x, const Y &y) { return x = (x < y) ? y : x; }
template <typename X, typename Y> [[nodiscard]] bool ckmin(X &x, const Y &y) { return (y < x) ? (x = y, 1) : 0; }
template <typename X, typename Y> [[nodiscard]] bool ckmax(X &x, const Y &y) { return (x < y) ? (x = y, 1) : 0; }
template <typename T> inline T sq(T a) { return a * a; }
template <typename T> inline T sq_dist(pair<T, T> &a, pair<T, T> &b) { return sq(a.first - b.first) + sq(a.second - b.second); }
template <typename T> inline long double dist(pair<T, T> &a, pair<T, T> &b) { return sqrtl(sq_dist(a, b)); }
inline long long isqrt(long long n) {
    long long sq = (long long)sqrtl((long double)n) - 2;
    sq = max(sq, 0LL);
    while (sq * sq < n) sq++;
    if ((sq * sq) == n) return sq;
    return sq - 1;
}
inline bool is_sq(int n) { int w = (int)isqrt(n); return w * w == n; }

struct custom_hash {
    

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int, int> p) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(p.first * 31 + p.second + FIXED_RANDOM);
    }
};

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    if (name.size() == 0) return;
    FILE *fin = freopen((name + ".in").c_str(), "r", stdin);
    FILE *fout = freopen((name + ".out").c_str(), "w", stdout);
    ignore_unused(fin);
    ignore_unused(fout);
}






constexpr int mod = 1e9 + 7;
constexpr int64_t linf = 3e18;
constexpr long double pi = acosl(-1.0);

[[nodiscard]] int64_t pwr_mod(int64_t a, int64_t n, int mod = ::mod) {
    int64_t ans = 1;
    while (n) {
        if (n & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}



template <typename T>
T pwr(T a, int64_t n) {
    T ans(1);
    while (n) {
        if (n & 1) ans *= a;
        if (n > 1) a *= a;
        n >>= 1;
    }
    return ans;
}

void precompute() {}



template <int32_t MOD = 998'244'353>
struct Modular {
    int32_t value;
    static const int32_t MOD_value = MOD;

    Modular(long long v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Modular &operator-=(Modular const &b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Modular &operator*=(Modular const &b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular &operator/=(Modular const &b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Modular const &a) {
        return os << a.value;
    }
    friend bool operator==(Modular const &a, Modular const &b) {
        return a.value == b.value;
    }
    friend bool operator!=(Modular const &a, Modular const &b) {
        return a.value != b.value;
    }
};

namespace IO {
const int BUFFER_SIZE = 1 << 15;

char input_buffer[BUFFER_SIZE];
size_t input_pos = 0, input_len = 0;

char output_buffer[BUFFER_SIZE];
int output_pos = 0;

char number_buffer[100];
uint8_t lookup[100];

void _update_input_buffer() {
    input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
    input_pos = 0;

    if (input_len == 0) input_buffer[0] = EOF;
}

inline char next_char(bool advance = true) {
    if (input_pos >= input_len) _update_input_buffer();

    return input_buffer[advance ? input_pos++ : input_pos];
}

inline bool isspace(char c) {
    return (unsigned char)(c - '\t') < 5 || c == ' ';
}

inline void read_char(char &c) {
    while (isspace(next_char(false))) next_char();

    c = next_char();
}

template <typename T>
inline void read_int(T &number) {
    bool negative = false;
    number = 0;

    while (!isdigit(next_char(false)))
        if (next_char() == '-') negative = true;

    do {
        number = 10 * number + (next_char() - '0');
    } while (isdigit(next_char(false)));

    if (negative) number = -number;
}

template <typename T, typename... Args>
inline void read_int(T &number, Args &... args) {
    read_int(number);
    read_int(args...);
}

inline void read_str(string &str) {
    while (isspace(next_char(false))) next_char();

    str.clear();

    do {
        str += next_char();
    } while (!isspace(next_char(false)));
}

void _flush_output() {
    fwrite(output_buffer, sizeof(char), output_pos, stdout);
    output_pos = 0;
}

inline void write_char(char c) {
    if (output_pos == BUFFER_SIZE) _flush_output();

    output_buffer[output_pos++] = c;
}

template <typename T>
inline void write_int(T number, char after = '\0') {
    if (number < 0) {
        write_char('-');
        number = -number;
    }

    int length = 0;

    while (number >= 10) {
        uint8_t lookup_value = lookup[number % 100];
        number /= 100;
        number_buffer[length++] = char((lookup_value & 15) + '0');
        number_buffer[length++] = char((lookup_value >> 4) + '0');
    }

    if (number != 0 || length == 0) write_char(char(number + '0'));

    for (int i = length - 1; i >= 0; i--) write_char(number_buffer[i]);

    if (after) write_char(after);
}

inline void write_str(const string &str, char after = '\0') {
    for (char c : str) write_char(c);

    if (after) write_char(after);
}

void IOinit() {
    

    bool exit_success = atexit(_flush_output) == 0;
    assert(exit_success);

    for (int i = 0; i < 100; i++) lookup[i] = uint8_t((i / 10 << 4) + i % 10);
}
}  


using namespace IO;

using mint = Modular<mod>;

void solve(int) {
    int n;
    read_int(n);
    vector<vector<int>> g(n);

    for (int i = 1; i < n; ++i) {
        int u, v;
        read_int(u, v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int N = 46;
    vector<int> fib(N);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < N; ++i) fib[i] = fib[i - 1] + fib[i - 2];

    function<void(int, int, vector<int> &, vector<int> &,
                  vector<vector<int>> &)>
        get_size = [&](int v, int p, vector<int> &siz, vector<int> &par,
                       vector<vector<int>> &g) {
            siz[v] = 1;
            par[v] = p;
            for (auto u : g[v]) {
                if (u != p) {
                    get_size(u, v, siz, par, g);
                    siz[v] += siz[u];
                }
            }
        };

    function<void(int, int, vector<int> &, vector<vector<int>> &, int)> dfs =
        [&](int v, int p, vector<int> &in_larger, vector<vector<int>> &g,
            int start_idx) {
            in_larger[v] = start_idx;
            for (auto u : g[v]) {
                if (u != p) {
                    dfs(u, v, in_larger, g, start_idx);
                }
            }
        };

    

    function<bool(vector<vector<int>> &, int)> works =
        [&](vector<vector<int>> &g, int f) {
            if (f <= 3) return true;
            int n = g.size();
            vector<int> siz(n), par(n, -1);
            get_size(0, -1, siz, par, g);
            for (int i = 0; i < n; ++i) {
                if (siz[i] == fib[f - 1] || siz[i] == fib[f - 2]) {
                    const int subtree_larger = siz[i] == fib[f - 1];
                    const int start_idx = subtree_larger;
                    const int increment = 2 * subtree_larger - 1;
                    vector<int> in_larger(n, -increment);
                    vector<vector<int>> gr(fib[f - 2]);
                    dfs(i, par[i], in_larger, g, start_idx);
                    int cur_idx = start_idx;
                    for (int i = 0; i < n; ++i) {
                        if (in_larger[i] == start_idx) {
                            in_larger[i] = cur_idx;
                            cur_idx += increment;
                        }
                    }
                    if (increment == 1) {
                        int smaller_idx = 0;
                        for (int i = 0; i < n; ++i) {
                            if (in_larger[i] == -1) {
                                in_larger[i] = -smaller_idx;
                                smaller_idx++;
                            }
                        }
                    } else {
                        int larger_idx = 1;
                        for (int i = 0; i < n; ++i) {
                            if (in_larger[i] == 1) {
                                in_larger[i] = larger_idx++;
                            }
                        }
                    }
                    for (int i = 0; i < n; ++i) {
                        if (in_larger[i] <= 0) {
                            auto &adj_i = gr[-in_larger[i]];
                            for (auto u : g[i]) {
                                if (in_larger[u] <= 0) {
                                    adj_i.push_back(-in_larger[u]);
                                }
                            }
                        }
                    }
                    auto g_end =
                        remove_if(begin(g), end(g), [&](const vector<int> &v) {
                            return in_larger[&v - &*begin(g)] <= 0;
                        });
                    g.erase(g_end, end(g));
                    for (auto &v : g) {
                        for (auto &x : v) x = in_larger[x] - 1;
                        auto v_end =
                            remove_if(begin(v), end(v),
                                      [&](const int &a) { return a < 0; });
                        v.erase(v_end, end(v));
                    }
                    vector<int>().swap(in_larger);
                    vector<int>().swap(siz);
                    vector<int>().swap(par);
                    return works(g, f - 1) && works(gr, f - 2);
                }
            }
            return false;
        };

    if (n == 1) {
        write_str("YES\n");
        return;
    }

    for (int i = 2; i < N; ++i) {
        if (fib[i] == n) {
            if (works(g, i)) {
                write_str("YES\n");
                return;
            } else {
                write_str("NO\n");
                return;
            }
        }
    }
    write_str("NO\n");
}

void brute(int) {}

signed main() {
    

    IOinit();
    precompute();
    int t = 1;
    

    for (int _t = 1; _t <= t; _t++) {
        

        solve(_t);
        

    }
    return 0;
}


