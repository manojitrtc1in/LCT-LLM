









































using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;



int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }


template <uint MD> struct ModInt {
    using M = ModInt;
    static constexpr uint get_mod() { return MD; }
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};





struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; 

        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};















struct Random {
  private:
    

    

    static uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    std::array<uint64_t, 4> s;

    uint64_t next() {
        const uint64_t id0 = rotl(s[1] * 5, 7) * 9;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);

        return id0;
    }

    

    uint64_t next(uint64_t upper) {
        if (!(upper & (upper + 1))) {
            

            return next() & upper;
        }
        int lg = 63 - __builtin_clzll(upper);
        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg + 1)) - 1;
        while (true) {
            uint64_t r = next() & mask;
            if (r <= upper)
                return r;
        }
    }

  public:
    Random(uint64_t seed = 0) {
        

        

        for (int i = 0; i < 4; i++) {
            uint64_t z = (seed += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            s[i] = z ^ (z >> 31);
        }
    }

    

    template <class T>
    T uniform(T lower, T upper) {
        assert(lower <= upper);
        return T(lower + next(uint64_t(upper - lower)));
    }

    bool uniform_bool() { return uniform(0, 1) == 1; }

    double uniform01() {
        uint64_t v = next(1ULL << 63);
        return double(v) / (1ULL << 63);
    }

    

    std::string lower_string(size_t n) {
        std::string res = "";
        for (size_t i = 0; i < n; i++) {
            res += uniform('a', 'z');
        }
        return res;
    }

    

    template <class Iter>
    void shuffle(Iter first, Iter last) {
        if (first == last) return;
        

        

        

        int len = 1;
        for (auto it = first + 1; it != last; it++) {
            len++;
            int j = uniform(0, len - 1);
            if (j != len - 1)
                iter_swap(it, first + j);
        }
    }

    

    template <class T>
    std::vector<T> perm(size_t n) {
        std::vector<T> idx(n);
        std::iota(idx.begin(), idx.end(), T(0));
        shuffle(idx.begin(), idx.end());
        return idx;
    }

    template <class T>
    std::vector<T> choice(size_t n, T lower, T upper) {
        assert(n <= upper - lower + 1);
        std::set<T> res;
        while (res.size() < n) res.insert(uniform(lower, upper));
        return {res.begin(), res.end()};
    }
} global_gen;

Random id1() {
    return Random(chrono::steady_clock::now().time_since_epoch().count());
}

using Mint = ModInt<998244353>;

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

V<Mint> solve(int m, V<ull> v) {
    int n = int(v.size());
    V<Mint> ans(m + 1);
    if (n <= 29) {
        ull w = 0;
        int c = n - 1;
        for (auto x: v) w ^= x;
        for (uint f = 0; f < (1<<n); f++) {
            c++;
            for (int i = 0; i < n; i++) {
                w ^= v[i];
                if (f & (1 << i)) break;
                c--;
            }
            ans[c + popcnt(w)] += Mint(1);
        }
    } else {
        int k = m - n;


        
        

        VV<Mint> dp_buf(n + 1);
        for (int neg = 0; neg <= n; neg++) {
            V<Mint> dp(n + 1);
            dp[0] = Mint(1);
            for (int ph = 0; ph < neg; ph++) {
                for (int i = n - 1; i >= 0; i--) {
                    dp[i + 1] -= dp[i];
                }
            }
            for (int ph = neg; ph < n; ph++) {
                for (int i = n - 1; i >= 0; i--) {
                    dp[i + 1] += dp[i];
                }
            }
            dp_buf[neg] = dp;
        }

        VV<Mint> pool(n + 1, V<Mint>(k + 1));
        for (uint f = 0; f < (1<<k); f++) {
            int neg = 0;
            for (auto x: v) {
                if (popcnt(x & f) % 2) neg++;
            }
            pool[neg][popcnt(f)] += Mint(1);
        }

        for (int pf = 0; pf <= k; pf++) {
            ull base = (1ULL << pf) - 1;
            V<Mint> cnt(k + 1);
            for (uint g = 0; g < (1 << k); g++) {
                if (popcnt(base & g) % 2) cnt[popcnt(g)] -= Mint(1);
                else cnt[popcnt(g)] += Mint(1);
            }
            for (int neg = 0; neg <= n; neg++) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= k; j++) {
                        Mint x = dp_buf[neg][i] * pool[neg][pf] * cnt[j];
                        ans[i + j] += x;
                    }
                }
            }
        }


        for (int i = 0; i <= m; i++) {
            ans[i] *= Mint(2).pow(k).inv();
        }
    }
    return ans;
}

void solve_main() {
    int n, m;
    sc.read(n, m);
    V<ull> d(m);
    for (int ph = 0; ph < n; ph++) {
        ull a;
        sc.read(a);
        for (int i = m - 1; i >= 0; i--) {
            if (!(a & (1ULL << i))) continue;
            if (d[i] == 0) {
                d[i] = a;
                break;
            } else {
                a ^= d[i];
            }
        }
    }
    for (int ph = 0; ph < 100; ph++) {
        for (int i = 1; i < m; i++) {
            if (d[i] == 0 && d[i - 1]) {
                

                swap(d[i], d[i - 1]);
                for (auto& a: d) {
                    bool f1 = (a >> i) & 1;
                    bool f0 = (a >> (i - 1)) & 1;
                    if (f1) a ^= 3ULL << (i - 1);
                    if (f0) a ^= 3ULL << (i - 1);
                }
            }
        }
    }
    int rnk = 0;
    while (rnk < m && !d[rnk]) rnk++;
    V<ull> base;
    for (int i = rnk; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (d[j] & (1ULL << i)) d[j] ^= d[i];
        }
        base.push_back(d[i] - (d[i] >> rnk << rnk));
    }
    Mint off = Mint(2).pow(n - (m - rnk));
    V<Mint> ans = solve(m, base);
    for (auto x: ans) {
        pr.write((x * off).v);
        pr.write(' ');
    }
    pr.writeln();
}

void check(int m, int n) {
    V<ull> v(n);
    auto gen = Random(114514);
    for (int i = 0; i < n; i++) {
        v[i] = gen.uniform(0ULL, (1ULL << (m - n)) - 1);
    }
    auto u = solve(m, v);
          ;
}

int main() {
    solve_main();


}
