#include <bits/stdc++.h>



#ifdef __linux
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif





#define loopx(var, l, r) for(typename std::remove_reference_t<decltype(r)> var = (l), _oilib_loop_r = (r); var != _oilib_loop_r; ++var)


#define loop(var, l, r) for(typename std::remove_reference_t<decltype(r)> var = (l), _oilib_loop_r = (r); var <= _oilib_loop_r; ++var)
#define repeat(n) loopx(_oilib_repeat, 0, n)
#define fill0(arr) memset(arr, 0, sizeof(arr))
#define fill1(arr) memset(arr, 255, sizeof(arr))




#define input(type, vars...) type vars; read(vars)


#define lambda(var, expr) ([&](auto& var){ return expr; })
#define lambda2(a, b, expr) ([&](auto& a, auto& b){ return expr; })

namespace _oilib_classes {
    

    using i32 = int;
    using i64 = long long;
    using u32 = unsigned;
    using u64 = unsigned long long;
    using f32 = float;
    using f64 = double;

    const i32 I32_MAX = INT32_MAX;
    const i32 I32_MIN = INT32_MIN;
    const i64 I64_MAX = INT64_MAX;
    const i64 I64_MIN = INT64_MIN;
    const u32 U32_MAX = UINT32_MAX;
    const u64 U64_MAX = UINT64_MAX;

    template <class T1, class T2 = T1>
    struct vec2 {
        T1 x;
        T2 y;

        vec2() {}
        vec2(const T1 a, const T2 b) : x(a), y(b) {}
        vec2(const std::pair<T1, T2>& p) : x(p.first), y(p.second) {}

        template <typename std::enable_if_t<std::is_same_v<T1, T2>, u32> = 0>
        T1 operator[](u32 i) {
            if(i == 0)
                return x;
            else
                return y;
        }

        operator std::pair<T1, T2>() const {
            return make_pair(x, y);
        }

        template <class T>
        vec2 operator+(const T& rhs) const {
            return vec2(x + rhs, y + rhs);
        }

        vec2 operator+(const vec2& rhs) const {
            return vec2(x + rhs.x, y + rhs.y);
        }

        

        template <class T>
        vec2& operator+=(const T& rhs) {
            x += rhs;
            y += rhs;
            return *this;
        }

        vec2& operator+=(const vec2& rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        template <class T>
        vec2 operator-(const T& rhs) const {
            return vec2(x - rhs, y - rhs);
        }

        vec2 operator-(const vec2& rhs) const {
            return vec2(x - rhs.x, y - rhs.y);
        }

        template <class T>
        vec2& operator-=(const T& rhs) {
            x -= rhs;
            y -= rhs;
            return *this;
        }

        vec2& operator-=(const vec2& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        template <class T>
        vec2 operator*(const T& rhs) const {
            return vec2(x * rhs, y * rhs);
        }

        template <class T>
        vec2& operator*=(const T& rhs) const {
            x *= rhs;
            y *= rhs;
            return *this;
        }

        template <class T>
        vec2 operator/(const T& rhs) const {
            return vec2(x / rhs, y / rhs);
        }

        template <class T>
        vec2& operator/=(const T& rhs) const {
            x /= rhs;
            y /= rhs;
            return *this;
        }

        bool operator==(const vec2& rhs) const {
            return x == rhs.x && y == rhs.y;
        }

        bool operator!=(const vec2& rhs) const {
            return x != rhs.x || y != rhs.y;
        }

        bool operator<(const vec2& rhs) const {
            return (x != rhs.x) ? (x < rhs.x) : (y < rhs.y);
        }

        bool operator<=(const vec2& rhs) const {
            return x < rhs.x || (x == rhs.x && y <= rhs.y);
        }

        bool operator>(const vec2& rhs) const {
            return (x != rhs.x) ? (x > rhs.x) : (y > rhs.y);
        }

        bool operator>=(const vec2& rhs) const {
            return x > rhs.x || (x == rhs.x && y >= rhs.y);
        }
    };

    template <class T1, class T2 = T1, class T3 = T2>
    struct vec3 {
        T1 x;
        T2 y;
        T3 z;

        vec3() {}
        vec3(const T1 a, const T2 b, const T3 c) : x(a), y(b), z(c) {}

        template <typename std::enable_if_t<std::is_same_v<T1, T2> && std::is_same_v<T1, T3>, u32> = 0>
        T1 operator[](u32 i) {
            if(i == 0)
                return x;
            else if(i == 1)
                return y;
            else
                return z;
        }

        template <class T>
        vec3 operator+(const T& rhs) const {
            return {x + rhs, y + rhs, z + rhs};
        }

        vec3 operator+(const vec3& rhs) const {
            return {x + rhs.x, y + rhs.y, z + rhs.z};
        }

        

        template <class T>
        vec3& operator+=(const T& rhs) {
            x += rhs;
            y += rhs;
            z += rhs;
            return *this;
        }

        vec3& operator+=(const vec3& rhs) {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            return *this;
        }

        template <class T>
        vec3 operator-(const T& rhs) const {
            return vec3(x - rhs, y - rhs, z - rhs);
        }

        vec3 operator-(const vec3& rhs) const {
            return vec3(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        template <class T>
        vec3& operator-=(const T& rhs) {
            x -= rhs;
            y -= rhs;
            z -= rhs;
            return *this;
        }

        vec3& operator-=(const vec3& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        template <class T>
        vec3 operator*(const T& rhs) const {
            return vec3(x * rhs, y * rhs, z * rhs);
        }

        template <class T>
        vec3& operator*=(const T& rhs) const {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            return *this;
        }

        template <class T>
        vec3 operator/(const T& rhs) const {
            return vec3(x / rhs, y / rhs, z / rhs);
        }

        template <class T>
        vec3& operator/=(const T& rhs) const {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            return *this;
        }

        bool operator==(const vec3& rhs) const {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        bool operator!=(const vec3& rhs) const {
            return x != rhs.x || y != rhs.y || z != rhs.z;
        }

        bool operator<(const vec3& rhs) const {
            return (x != rhs.x) ? (x < rhs.x) : ((y != rhs.y) ? (y < rhs.y) : (z < rhs.z));
        }

        bool operator<=(const vec3& rhs) const {
            return x < rhs.x || (x == rhs.x && (y < rhs.y || (y == rhs.y && z <= rhs.z)));
        }

        bool operator>(const vec3& rhs) const {
            return (x != rhs.x) ? (x > rhs.x) : ((y != rhs.y) ? (y > rhs.y) : (z > rhs.z));
        }

        bool operator>=(const vec3& rhs) const {
            return x > rhs.x || (x == rhs.x && (y > rhs.y || (y == rhs.y && z >= rhs.z)));
        }
    };
};

using namespace _oilib_classes;

namespace _oilib_input {
    void input_file(const char* const filename) {
        freopen(filename, "r", stdin);
    }

    template <class T, typename std::enable_if_t<!std::is_arithmetic_v<T>, u32> = 0>
    void read(T& x) {
        std::cin >> x;
    }

    bool _isdigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    

    

    template <class T, typename std::enable_if_t<std::is_signed_v<T> && !std::is_floating_point_v<T>, u32> = 0>
    void read(T& num) {
        using unsigned_T = typename std::make_unsigned_t<T>;
        char ch;
        bool negative = false;
        while(!_isdigit(ch = getchar()))
            if(ch == '-')
                negative = true;
        unsigned_T num2 = ch & 15;
        while(_isdigit(ch = getchar()))
            num2 = num2 * 10 + (ch & 15);
        num = negative ? -num2 : num2;
    }

    template <class T, typename std::enable_if_t<std::is_unsigned_v<T>, u32> = 0>
    void read(T& num) {
        char ch;
        while(!_isdigit(ch = getchar()))
            continue;
        num = ch & 15;
        while(_isdigit(ch = getchar()))
            num = num * 10 + (ch & 15);
    }

    bool _iscontrol(char ch) {
        return ch <= 32 || ch == 127;
    }

    void read(char& ch) {
        while(_iscontrol(ch = getchar()))
            continue;
    }

    void read(f32& f) {
        scanf("%f", &f);
    }

    void read(f64& f) {
        scanf("%lf", &f);
    }

    void read(char* str) {
        while(_iscontrol(*str = getchar()))
            continue;
        while(!_iscontrol(*(++str) = getchar()))
            continue;
        *str = '\0';
    }

    void read(std::string& str) {
        str.clear();
        char ch;
        while(_iscontrol(ch = getchar()))
            continue;
        str.push_back(ch);
        while(!_iscontrol(ch = getchar()))
            str.push_back(ch);
    }

    template <class T>
    T read() {
        T x;
        read(x);
        return x;
    }

    

    template <> char* read() {
        std::string s;
        read(s);
        char* str = new char[s.size() + 1];
        memcpy(str, s.c_str(), s.size());
        return str;
    }

    i64 read() {
        return read<i64>();
    }

    u64 readu() {
        return read<u64>();
    }

    template <class T1, class T2>
    void read(std::pair<T1, T2>& p) {
        read(p.first);
        read(p.second);
    }

    template <class T1, class T2>
    void read(vec2<T1, T2>& v) {
        read(v.x);
        read(v.y);
    }

    template <class T1, class T2, class T3>
    void read(vec3<T1, T2, T3>& v) {
        read(v.x);
        read(v.y);
        read(v.z);
    }

    template <class T1, class T2>
    void read(T1& a, T2& b) {
        read(a);
        read(b);
    }

    template <class T1, class T2, class... Rest>
    void read(T1& a, T2& b, Rest&... rest) {
        read(a, b);
        read(rest...);
    }

    template <class Iterator>
    void read_arr(Iterator iter, const size_t n) {
        for(size_t cnt = 0; cnt < n; ++cnt, ++iter)
            read(*iter);
    }

    template <class T>
    std::vector<T> read_arr(const size_t n) {
        std::vector<T> arr(n);
        read_arr(arr.begin(), n);
        return arr;
    }
};

using _oilib_input::input_file;
using _oilib_input::read;
using _oilib_input::readu;
using _oilib_input::read_arr;

namespace _oilib_output {
    void output_file(const char* const filename) {
        freopen(filename, "w", stdout);
    }

    char _f32_format[6] = "%f";
    char _f64_format[7] = "%lf";

    

    void output_prec(const u32 prec) {
        sprintf(_f32_format, "%%.%uf", prec);
        sprintf(_f64_format, "%%.%ulf", prec);
    }

    template <class T, typename std::enable_if_t<!std::is_arithmetic_v<T>, u32> = 0>
    void print(const T& x) {
        std::cout << x;
    }

    char _buf[20];
    char* _p = _buf;

    template <class T, typename std::enable_if_t<std::is_unsigned_v<T>, u32> = 0>
    void print(const T num) {
        T n = num;
        do {
            *(_p++) = (n % 10) | 48;
            n /= 10;
        } while(n != 0);
        while(_p != _buf)
            putchar(*(--_p));
    }

    template <class T, typename std::enable_if_t<std::is_signed_v<T> && !std::is_floating_point_v<T>, u32> = 0>
    void print(const T num) {
        using unsigned_T = typename std::make_unsigned_t<T>;
        if(num < 0) {
            putchar('-');
            print(unsigned_T(-num));
        } else
            print(unsigned_T(num));
    }

    void print(const char ch) {
        putchar(ch);
    }

    void print(const f32 num) {
        printf(_f32_format, num);
    }

    void print(const f64 num) {
        printf(_f64_format, num);
    }

    void print(const char* str) {
        fputs(str, stdout);
    }

    void print(const std::string& str) {
        fputs(str.c_str(), stdout);
    }

    template <class T1, class T2>
    void print(const std::pair<T1, T2>& p) {
        print(p.first);
        putchar(' ');
        print(p.second);
    }

    template <class T1, class T2>
    void print(const vec2<T1, T2>& v) {
        print(v.x);
        putchar(' ');
        print(v.y);
    }

    template <class T1, class T2, class T3>
    void print(const vec3<T1, T2, T3>& v) {
        print(v.x);
        putchar(' ');
        print(v.y);
        putchar(' ');
        print(v.z);
    }

    template <class T1, class T2>
    void print(const T1& a, const T2& b) {
        print(a);
        putchar(' ');
        print(b);
    }

    template <class T1, class T2, class... Rest>
    void print(const T1& a, const T2& b, const Rest&... rest) {
        print(a, b);
        putchar(' ');
        print(rest...);
    }

    template <class Iterator>
    void print_arr(Iterator begin, const Iterator end) {
        print(*(begin++));
        while(begin != end) {
            putchar(' ');
            print(*(begin++));
        }
    }

    template <class Iterator>
    void print_arr(Iterator iter, const size_t n) {
        print_arr(iter, iter + n);
    }

    template <class Container>
    void print_arr(const Container& c) {
        print_arr(c.begin(), c.end());
    }

    template <class... T>
    void println(const T&... args) {
        print(args...);
        putchar('\n');
    }

    template <class Iterator>
    void println_arr(const Iterator iter, const size_t n) {
        print_arr(iter, n);
        putchar('\n');
    }

    template <class Container>
    void println_arr(const Container& c) {
        print_arr(c);
        putchar('\n');
    }
};

using _oilib_output::output_file;
using _oilib_output::output_prec;
using _oilib_output::print;
using _oilib_output::print_arr;
using _oilib_output::println;
using _oilib_output::println_arr;

namespace _oilib_rand {
    class Rng {
        private:
        u64 _s0, _s1;

        

        u64 _next() {
            u64 result = _s0 + _s1;
            _s1 ^= _s0;
            _s0 = ((_s0 << 24) | (_s0 >> 40)) ^ _s1 ^ (_s1 << 16);
            _s1 = (_s1 << 37) | (_s1 >> 27);
            return result;
        }

        

        f64 _nextf() {
            u64 t = 0x3ff0000000000000 | (_next() >> 12);
            return *(f64*)&t - 1.0;
        }

        public:
        void seed(u64 s) {
            std::seed_seq gen = {u32(s >> 32), u32(s)};
            u32 val[4];
            gen.generate(val, val + 4);
            _s0 = (u64(val[0]) << 32) | val[1];
            _s1 = (u64(val[2]) << 32) | val[3];
        }

        

        Rng() {
            std::random_device entropy;
            _s0 = (u64(entropy()) << 32) | entropy();
            _s1 = (u64(entropy()) << 32) | entropy();
        }

        Rng(const u64 s) {
            seed(s);
        }

        u64 operator()() {
            return _next();
        }

        template <class T, typename std::enable_if_t<std::is_integral_v<T>, u32> = 0>
        T operator()(T l, T r) {
            return _next() % (r - l + 1) + l;
        }

        

        template <class T, typename std::enable_if_t<std::is_integral_v<T>, u32> = 0>
        T operator()(T max) {
            return _next() % max;
        }

        

        template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, u32> = 0>
        T operator()(T l, T r) {
            return _nextf() * (r - l) + l;
        }

        

        template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, u32> = 0>
        T operator()(T max) {
            return _nextf() * max;
        }
    } rnd;
};

using namespace _oilib_rand;

namespace _oilib_util {
    void io_prefix(const char* const prefix) {
        size_t len = strlen(prefix);
        char* buf = new char[len + 5];
        sprintf(buf, "%s.in", prefix);
        freopen(buf, "r", stdin);
        sprintf(buf, "%s.out", prefix);
        freopen(buf, "w", stdout);
        delete[] buf;
    }

    template <class T, class T2>
    void to_min(T& a, const T2& b) {
        if(T(b) < a)
            a = b;
    }

    template <class T, class T2>
    void to_max(T& a, const T2& b) {
        if(T(b) > a)
            a = b;
    }

    template <class Iterator, class Function>
    void apply(const Iterator begin, const Iterator end, Function f) {
        std::transform(begin, end, begin, f);
    }
};

using namespace _oilib_util;

namespace _oilib_numtheory {
    u32 _mul(u32 a, u32 b, u32 mod) {
        return u64(a) * b % mod;
    }

    u64 mul64(u64 a, u64 b, u64 mod) {
        a %= mod;
        b %= mod;
        return a * b - u64((long double) a / mod * b) * mod;
    }

    u32 qpow(u64 a, u64 b, u32 mod) {
        u32 a2 = a % mod;
        u32 res = 1;
        for(; b != 0; a2 = _mul(a2, a2, mod), b >>= 1)
            if(b & 1)
                res = _mul(res, a2, mod);
        return res;
    }

    u64 qpow(u64 a, u64 b) {
        u64 res = 1;
        for(; b != 0; a *= a, b >>= 1)
            if(b & 1)
                res *= a;
        return res;
    }

    template <u32 n>
    class FactorProcessor {
        private:
        u32 _factor[n + 1], _prime[n + 1], _pi[n + 1];

        public:
        FactorProcessor() {
            fill0(_factor);
            _pi[1] = 0;
            loop(i, 2, n) {
                _pi[i] = _pi[i - 1];
                if(_factor[i] == 0) {
                    _factor[i] = i;
                    _prime[_pi[i]++] = i;
                }
                loopx(j, 0, _pi[std::min(_factor[i], n / i)])
                    _factor[i * _prime[j]] = _prime[j];
            }
        }

        u32 operator()(u32 x) {
            return _factor[x];
        }

        bool is_prime(u32 x) {
            return _factor[x] == x;
        }

        u32 nth_prime(u32 k) {
            return _prime[k - 1];
        }

        u32 pi(u32 x) {
            return _pi[x];
        }

        u32 min_factor(u32 x) {
            return _factor[x];
        }

        std::vector<vec2<u32>> factorize(u32 x) {
            std::vector<vec2<u32>> res;
            while(x != 1) {
                u32 f = _factor[x];
                u32 cnt = 0;
                do {
                    x /= f;
                    ++cnt;
                } while(x % f == 0);
                res.push_back({f, cnt});
            }
            return res;
        }
    };

    u64 _gcd(u64 a, u64 b) {
        if(a == 0)
            return b;
        return _gcd(b, a % b);
    }

    u64 gcd(u64 a, u64 b) {
        return (a < b) ? _gcd(a, b) : _gcd(b, a);
    }
};

namespace algorithms {
    using _oilib_numtheory::mul64;
    using _oilib_numtheory::qpow;
    using _oilib_numtheory::FactorProcessor;
    using _oilib_numtheory::gcd;
};

using namespace std;
using namespace algorithms;

const u32 mod = 1e9 + 7;

int main() {
    input(u32, n);
    static u32 seq[100000];
    read_arr(seq, n);
    u64 sum = accumulate(seq, seq + n, 0ull);
    if(sum % n != 0) {
        println(0);
        return 0;
    }
    u32 mean = sum / n;
    u32 nsrc = count_if(seq, seq + n, lambda(x, x < mean));
    u32 ndst = count_if(seq, seq + n, lambda(x, x > mean));
    map<u32, u32> vcnt;
    loopx(i, 0, n)
        ++vcnt[seq[i]];
    static u32 fact[100001];
    fact[0] = fact[1] = 1;
    loop(i, 2, n)
        fact[i] = u64(fact[i - 1]) * i % mod;
    if(nsrc <= 1 || ndst <= 1) {
        u64 res = fact[n];
        for(pair<u32, u32> p : vcnt)
            res = res * qpow(fact[p.second], mod - 2, mod) % mod;
        println(res);
    } else {
        u64 res = 2;
        res = res * fact[nsrc] % mod;
        res = res * fact[ndst] % mod;
        for(pair<u32, u32> p : vcnt)
            if(p.first != mean)
                res = res * qpow(fact[p.second], mod - 2, mod) % mod;
        res = res * fact[n] % mod;
        res = res * qpow(fact[nsrc + ndst], mod - 2, mod) % mod;
        res = res * qpow(fact[n - nsrc - ndst], mod - 2, mod) % mod;
        println(res);
    }
}
