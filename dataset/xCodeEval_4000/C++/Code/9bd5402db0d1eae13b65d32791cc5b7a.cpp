

#include <bits/stdc++.h>
using namespace std;
#define lll bigint
#define watch_shid Stopwatch WATCH;WATCH.start()
#define mayn main
#define x first
#define max_el(vec) *max_element(vec.begin(), vec.end())
#define min_el(vec) *min_element(vec.begin(), vec.end())
#define THE int
#define y second
#define ll long long
#define sz(x) x.size()
#define range(a,b,iter) for(int iter = a ; iter <= b ; iter++)
#define iter(x,it) for(auto it = x.begin() ; it!=x.end() ; ++it)
#define endl '\n'
#define n_l '\n'
#define THICC INT_MAX
#define SMOL INT_MIN
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;




const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a;
    int sign;
    
    int size(){
        if(a.empty())return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca)
            ans++,ca/=10;
        return ans;
    }
    bigint operator ^(const bigint &v){
        bigint ans=1,a=*this,b=v;
        while(!b.isZero()){
            if(b%2)
                ans*=a;
            a*=a,b/=2;
        }
        return ans;
    }
    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof(){
        string s = to_string();
        int ans = 0;
        for(auto c : s)  ans += c - '0';
        return ans;
    }
    bigint() :
            sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    void operator*=(long long v) {
        if (v < 0)
            sign = -sign, v = -v;
        if(v > base){
            *this = *this * (v / base) * base + *this * (v % base);
            return ;
        }
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(long long v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};




template <typename T, size_t N>
 int SIZE(const T (&t)[N]){
     return N;
 }

 template<typename T>
 int SIZE(const T &t){
     return t.size();
 }

 string to_string(const string s, int x1=0, int x2=1e9){
     return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"';
 }

 string to_string(const char* s) {
     return to_string((string) s);
 }

 string to_string(const bool b) {
     return (b ? "true" : "false");
 }

 string to_string(const char c){
     return string({c});
 }

 template<size_t N>
 string to_string(const bitset<N> &b, int x1=0, int x2=1e9){
     string t = "";
     for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){
       t += b[__iii__] + '0';
     }
     return '"' + t + '"';
 }

 template <typename A, typename... C>
 string to_string(const A (&v), int x1=0, int x2=1e9, C... coords);

 int l_v_l_v_l = 0, t_a_b_s = 0;

 template <typename A, typename B>
 string to_string(const pair<A, B> &p) {
     l_v_l_v_l++;
     string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
     l_v_l_v_l--;
     return res;
 }

 template <typename A, typename... C>
 string to_string(const A (&v), int x1, int x2, C... coords) {

     int rnk = rank<A>::value;
     string tab(t_a_b_s, ' ');

     string res = "";
     bool first = true;

     if(l_v_l_v_l == 0) res += n_l;
     res += tab + "[";

     x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
     auto l = begin(v);
     advance(l, x1);
     auto r = l;
     advance(r, (x2-x1) + (x2 < SIZE(v)));

     for (auto e = l; e != r; e = next(e)) {
         if (!first) {
             res += ", ";
         }
         first = false;

         l_v_l_v_l++;
         if(e != l){
             if(rnk > 1) {
                 res += n_l;
                 t_a_b_s = l_v_l_v_l;
             };
         }
         else{
             t_a_b_s = 0;
         }

         res += to_string(*e, coords...);
         l_v_l_v_l--;
     }
     res += "]";
     if(l_v_l_v_l == 0) res += n_l;
     return res;
 }

 void dbgm(){;}
 template<typename Heads, typename... Tails>
 void dbgm(Heads H, Tails... T){
     cerr << to_string(H) << " | ";
     dbgm(T...);
}
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl;






template <class T> struct is_iterator {
    template <class U, typename enable_if<!is_convertible<U, const char*>::value, int>::type = 0>
    constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) { return true; }
    template <class> constexpr static bool has_indirection(long) { return false; }
    constexpr static bool value = has_indirection<T>(0);
};
using uint = unsigned int;


const uint BUFFER_SIZE = 1 << 12;




const uint MAX_LENGTH = 1 << 7;
namespace Detail {
    struct Width { uint value; };
    struct Fill { char value; };
    struct Base { uint value; };
    struct Precision { uint value; };
    struct Delimiter { const char* value; };
}  

Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return {value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return {value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return {value}; }

class InputDevice {
protected:
    const char* head;
    const char* tail;

    InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}

    virtual void fillInput() = 0;

    inline char nextChar() {
        if (__builtin_expect(head >= tail, false)) fillInput();
        return *head++;
    }

    template <class I> int readUnsignedIntGeneral(I& arg, char c) {
        I value = 0;
        int length = 0;
        for (;; ++length, c = nextChar()) {
            if (isDigit(c)) c -= '0';
            else if (isUpper(c)) c -= 'A' - 10;
            else if (isLower(c)) c -= 'a' - 10;
            else c = base;
            if (c >= base) break;
            value = base * value + c;
        }
        arg = value;
        return --head, length;
    }

    template <class I> inline int readUnsignedInt(I& arg, char c) {
        if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
        I value = 0;
        int length = 0;
        for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
            value = base * value + c - '0';
        arg = value;
        return --head, length;
    }

    template <class I> inline bool readSignedInt(I& arg, char c) {
        bool negative = c == '-';
        if (negative) c = nextChar();
        typename make_unsigned<I>::type unsignedArg;
        if (readUnsignedInt(unsignedArg, c) == 0) return false;
        arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
        return true;
    }

    template <class F> bool readFloatingPoint(F& arg, char c) {
        bool negative = c == '-';
        if (negative) c = nextChar();
        unsigned long long integerPart;
        if (readUnsignedInt(integerPart, c) == 0) return false;
        arg = static_cast<F>(integerPart);
        if (nextChar() == '.') {
            unsigned long long fractionalPart = 0;
            int fractionalLength = readUnsignedInt(fractionalPart, nextChar());
            if (fractionalLength > 0) {
                unsigned long long basePower = 1;
                for (; fractionalLength; --fractionalLength) basePower *= base;
                arg += static_cast<F>(fractionalPart) / basePower;
            }
        } else --head;
        if (negative) arg = -arg;
        return true;
    }

public:
    uint base;

    InputDevice(InputDevice const&) = delete;
    InputDevice& operator = (InputDevice const&) = delete;

    static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
    static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
    static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
    static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
    static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }

    void putBack() { --head; }  


    inline bool readChar(char& arg) {
        if (__builtin_expect(head >= tail, false)) {
            fillInput();
            if (__builtin_expect(head >= tail, false)) return arg = '\0', false;
        }
        return arg = *head++, true;
    }

    template <class UnaryPredicate>
    inline char skipCharacters(UnaryPredicate isSkipped) {
        char c;
        do { c = nextChar(); } while (isSkipped(c));
        return c;
    }
    inline char skipCharacters() { return skipCharacters(isSpace); }

    template <class UnaryPredicate>
    inline int readString(char* arg, int limit, UnaryPredicate isTerminator) {
        skipCharacters(isTerminator);
        

        int charsRead = 0;
        for (--head, --limit; head < tail; fillInput()) {
            ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;
            arg = copy_n(head, chunkSize, arg);
            head += chunkSize;
            charsRead += chunkSize;
            if (chunkSize == 0 || head < tail) break;
        }
        return *arg = '\0', charsRead;
    }

    inline int readString(char* arg, int limit, const char* terminators) {
        if (!*terminators) return readString(arg, limit, InputDevice::isSpace);
        return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
    }

    

    inline bool read(Detail::Base newBase) { base = newBase.value; return true; }
    

    inline bool read() { return true; }
    inline bool read(char& arg) { return readChar(arg); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
            bool>::type read(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
    template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
            bool>::type read(I& arg) { return readSignedInt(arg, skipCharacters()); }
    template <class F> inline typename enable_if<is_floating_point<F>::value,
            bool>::type read(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
    

    inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
    inline bool read(const char* arg) {
        if (*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
        else skipCharacters();
        return putBack(), true;
    }
    inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }
    

    template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
            bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args) {
        readString(arg, static_cast<int>(limit), terminator);
        return read(forward<Ts>(args)...);
    }
    template <class I> inline typename enable_if<is_integral<I>::value,
            bool>::type read(char* arg, I limit) { return read(arg, limit, ""); }
    template <class... Ts>
    inline bool read(char* first, char* last, Ts&&... args) {
        return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
    }
    template <int N, class... Ts>
    inline bool read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
    template <class Terminator, class... Ts>
    inline bool read(string& arg, Terminator terminator, Ts&&... args) {
        for (int length = 16, last = 0;; last += length, length <<= 1) {
            arg.resize(last + length);
            int charsRead = readString(&arg[last], length + 1, terminator);
            if (charsRead < length) {
                arg.resize(last + charsRead);
                return read(forward<Ts>(args)...);
            }
        }
    }
    inline bool read(string& arg) { return read(arg, ""); }

    inline bool read(bigint& arg) {
        cin>>arg;
        return 1;
    }
    

    

    template <class T1, class T2>
    inline bool read(pair<T1, T2>& arg) { return read(arg.first, arg.second); }
    template <class T>
    inline bool read(complex<T>& arg) {
        T real, imag;
        if (!read(real, imag)) return false;
        arg.real(real), arg.imag(imag);
        return true;
    }
    template <class T>
    inline bool read(vector<T>& arg) {
        uint n;
        if (!read(n)) return false;
        arg.resize(n);
        return read(arg.begin(), arg.end());
    }
    template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
            bool>::type read(Iterator first, Iterator last, Ts&&... args) {
        for (; first != last; ++first) if (!read(*first)) return false;
        return read(forward<Ts>(args)...);
    }
    template <class Iterator, class I, class... Ts>
    inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
            bool>::type read(Iterator first, I count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
    

    template <class T>
    inline auto read(T& arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
    template <class T0, class T1, class... Ts>
    inline typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char*>::value,
            bool>::type read(T0&& arg0, T1&& arg1, Ts&&... args) {
        return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
    }
};
class InputFile : public InputDevice {
    FILE* file;
    bool lineBuffered;
    bool owner;
    char buffer[BUFFER_SIZE];

    void fillInput() override {
        head = buffer;
        *buffer = '\0';
        if (__builtin_expect(!lineBuffered, true)) {
            tail = head + fread(buffer, 1, BUFFER_SIZE, file);
        } else {
            tail = head;
            if (fgets(buffer, BUFFER_SIZE, file)) while (*tail) ++tail;
        }
    }

public:
    InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
            : InputDevice(buffer, buffer) , file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
    InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
    ~InputFile() { if (owner) fclose(file); }
};


class InputString : public InputDevice {
    void fillInput() override { while (*tail) ++tail; }

public:
    InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
    InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};

class OutputDevice {
protected:
    char buffer[BUFFER_SIZE + MAX_LENGTH];
    char* output;
    char* end;
    bool separate;

    OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false)
            , width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value)
            , delimiter(setDelimiter().value) { computeBasePower(); }

    virtual void writeToDevice(uint count) = 0;

    inline void flushMaybe() {
        if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
            writeToDevice(BUFFER_SIZE);
            output = copy(buffer + BUFFER_SIZE, output, buffer);
        }
    }

    void computeBasePower() {
        basePower = 1;
        for (uint i = 0; i < precision; ++i) basePower *= base;
    }

    template <class I> inline char* writeUnsignedInt(I arg, char* last) {
        if (__builtin_expect(arg == 0, false)) *--last = '0';
        if (__builtin_expect(base == 10, true)) {
            for (; arg; arg /= 10) *--last = '0' + arg % 10;
        } else for (; arg; arg /= base) {
                I digit = arg % base;
                *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
            }
        return last;
    }

    template <class I> inline char* writeSignedInt(I arg, char* last) {
        auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
        if (arg < 0) {
            last = writeUnsignedInt(~unsignedArg + 1, last);
            *--last = '-';
            return last;
        }
        return writeUnsignedInt(unsignedArg, last);
    }

    template <class F> char* writeFloatingPoint(F arg, char* last) {
        bool negative = signbit(arg);
        if (negative) arg = -arg;
        if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
        else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
        else {
            auto integerPart = static_cast<unsigned long long>(arg);
            auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
            if (fractionalPart >= basePower) ++integerPart, fractionalPart = 0;
            char* point = last - precision;
            if (precision > 0) {
                ::fill(point, writeUnsignedInt(fractionalPart, last), '0');
                *--point = '.';
            }
            last = writeUnsignedInt(integerPart, point);
        }
        if (negative) *--last = '-';
        return last;
    }

    inline int writeT(char* first) {
        int delimiterLenght = separate ? writeDelimiter() : 0;
        separate = true;
        uint charsWritten = static_cast<uint>(end - first);
        if (__builtin_expect(charsWritten < width, false))
            charsWritten += writeFill(width - charsWritten);
        output = copy(first, end, output);
        flushMaybe();
        return delimiterLenght + static_cast<int>(charsWritten);
    }

    inline int writeFill(uint count) {
        int charsWritten = static_cast<int>(count);
        if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
            if (count == 1) *output++ = fill;
            else output = fill_n(output, count, fill);
        } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
                if (chunkSize > count) chunkSize = count;
                output = fill_n(output, chunkSize, fill);
                flushMaybe();
                if ((count -= chunkSize) == 0) break;
            }
        return charsWritten;
    }

public:
    uint width;
    char fill;
    uint base;
    uint precision;
    unsigned long long basePower;
    string delimiter;

    OutputDevice(OutputDevice const&) = delete;
    OutputDevice& operator = (OutputDevice const&) = delete;
    virtual ~OutputDevice() {};

    inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }

    inline int writeString(const char* arg, size_t length, bool checkWidth = true) {
        separate = false;
        uint count = static_cast<uint>(length);
        int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
        if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
            if (count == 1) *output++ = *arg;
            else output = copy_n(arg, count, output);
        } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
                if (chunkSize > count) chunkSize = count;
                output = copy_n(arg, chunkSize, output);
                flushMaybe();
                if ((count -= chunkSize) == 0) break;
                arg += chunkSize;
            }
        return charsWritten;
    }

    inline int writeDelimiter() { return writeString(delimiter.c_str(), delimiter.size(), false); }

    inline void flush() {
        writeToDevice(static_cast<uint>(output - buffer));
        output = buffer;
    }

    

    inline int write(Detail::Width newWidth) { width = newWidth.value; return 0; }
    inline int write(Detail::Fill newFill) { fill = newFill.value; return 0; }
    inline int write(Detail::Base newBase) { base = newBase.value; computeBasePower(); return 0; }
    inline int write(Detail::Precision newPrecision) {
        precision = newPrecision.value; computeBasePower(); return 0;
    }
    inline int write(Detail::Delimiter newDelimiter) { delimiter = newDelimiter.value; return 0; }
    

    inline int write() { return 0; }
    inline int write(char arg) { return writeChar(arg); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
            int>::type write(I arg) { return writeT(writeUnsignedInt(arg, end)); }
    template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
            int>::type write(I arg) { return writeT(writeSignedInt(arg, end)); }
    template <class F> inline typename enable_if<is_floating_point<F>::value,
            int>::type write(F arg) { return writeT(writeFloatingPoint(arg, end)); }
    

    inline int write(const char* arg) { return writeString(arg, strlen(arg)); }
    template <int N>
    inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
    inline int write(const string& arg) { return writeString(arg.c_str(), arg.size()); }
    

    template <class T1, class T2>
    inline int write(const pair<T1, T2>& arg) {
        int charsWritten = write(arg.first);
        charsWritten += writeDelimiter();
        return charsWritten + write(arg.second);
    }
    inline int write(const bigint& arg) {
        cerr<<arg;
        return 1;
    }
    template <class T>
    inline int write(const complex<T>& arg) { return write(real(arg), imag(arg)); }
    

    template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
            int>::type write(Iterator first, Iterator last, Ts&&... args) {
        int charsWritten = 0;
        for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
        return charsWritten + write(forward<Ts>(args)...);
    }
    template <class Iterator, class I, class... Ts>
    inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
            int>::type write(Iterator first, I count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
    

    template <class T>
    inline auto write(const T& arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
    template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value,
            int>::type write(T0&& arg0, T1&& arg1, Ts&&... args) {
        int charsWritten = write(forward<T0>(arg0));
        return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
    }
};
class OutputFile : public OutputDevice {
    FILE* file;
    bool owner;

    void writeToDevice(uint count) override {
        fwrite(buffer, 1, count, file);
        fflush(file);
    }

public:
    OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
    OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
    ~OutputFile() override { flush(); if (owner) fclose(file); }
};
class OutputString : public OutputDevice {
    string& str;

    void writeToDevice(uint count) override { str.append(buffer, count); }

public:
    OutputString(string& str) : OutputDevice(), str(str) {}
    ~OutputString() override { flush(); }
};
unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;
template <class... Ts> inline bool read(Ts&&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts&&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }

 



namespace stopwatch{

class Stopwatch{
public:
   enum TimeFormat{ NANOSECONDS, MICROSECONDS, MILLISECONDS, SECONDS };

   Stopwatch(): start_time(), laps({}) {
      start();
   }

   void start(){
      start_time = std::chrono::high_resolution_clock::now();
      laps = {start_time};
   }

   template<TimeFormat fmt = TimeFormat::MILLISECONDS>
   std::uint64_t lap(){
      const auto t = std::chrono::high_resolution_clock::now();
      const auto last_r = laps.back();
      laps.push_back( t );
      return ticks<fmt>(last_r, t);
   }

   template<TimeFormat fmt = TimeFormat::MILLISECONDS>
   std::uint64_t elapsed(){
      const auto end_time = std::chrono::high_resolution_clock::now();
      return ticks<fmt>(start_time, end_time);
   }

   template<TimeFormat fmt_total = TimeFormat::MILLISECONDS, TimeFormat fmt_lap = fmt_total>
   std::pair<std::uint64_t, std::vector<std::uint64_t>> elapsed_laps(){
      std::vector<std::uint64_t> lap_times;
      lap_times.reserve(laps.size()-1);

      for( std::size_t idx = 0; idx <= laps.size()-2; idx++){
         const auto lap_end = laps[idx+1];
         const auto lap_start = laps[idx];
         lap_times.push_back( ticks<fmt_lap>(lap_start, lap_end) );
      }

      return { ticks<fmt_total>(start_time, laps.back()), lap_times };
   }

private:
   typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_pt;
   time_pt start_time;
   std::vector<time_pt> laps;

   template<TimeFormat fmt = TimeFormat::MILLISECONDS>
   static std::uint64_t ticks( const time_pt& start_time, const time_pt& end_time){
      const auto duration = end_time - start_time;
      const std::uint64_t ns_count = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

      switch(fmt){
      case TimeFormat::NANOSECONDS:
      {
         return ns_count;
      }
      case TimeFormat::MICROSECONDS:
      {
         std::uint64_t up = ((ns_count/100)%10 >= 5) ? 1 : 0;
         const auto mus_count = (ns_count /1000) + up;
         return mus_count;
      }
      case TimeFormat::MILLISECONDS:
      {
         std::uint64_t up = ((ns_count/100000)%10 >= 5) ? 1 : 0;
         const auto ms_count = (ns_count /1000000) + up;
         return ms_count;
      }
      case TimeFormat::SECONDS:
      {
         std::uint64_t up = ((ns_count/100000000)%10 >= 5) ? 1 : 0;
         const auto s_count = (ns_count /1000000000) + up;
         return s_count;
      }
      }
    }
};


constexpr Stopwatch::TimeFormat ns = Stopwatch::TimeFormat::NANOSECONDS;
constexpr Stopwatch::TimeFormat mus = Stopwatch::TimeFormat::MICROSECONDS;
constexpr Stopwatch::TimeFormat ms = Stopwatch::TimeFormat::MILLISECONDS;
constexpr Stopwatch::TimeFormat s = Stopwatch::TimeFormat::SECONDS;

constexpr Stopwatch::TimeFormat nanoseconds = Stopwatch::TimeFormat::NANOSECONDS;
constexpr Stopwatch::TimeFormat microseconds = Stopwatch::TimeFormat::MICROSECONDS;
constexpr Stopwatch::TimeFormat milliseconds = Stopwatch::TimeFormat::MILLISECONDS;
constexpr Stopwatch::TimeFormat seconds = Stopwatch::TimeFormat::SECONDS;


std::string show_times( const std::vector<std::uint64_t>& times ){
    std::string result("{");
    for( const auto& t : times ){
        result += std::to_string(t) + ",";
    }
    result.back() = static_cast<char>('}');
    return result;
}

} 

using namespace stopwatch;
void print_time(Stopwatch WATCH , bool Do){
  if(Do)cerr<<"\nELAPSED: "<<WATCH.elapsed()<<endl;
}




 










ll gcd( ll a, ll b ){
		if(b==0)return a;
		else return gcd( b, a%b );
	}
ll lcm (ll a, ll b){
	return (a*b)/gcd(a,b);
}












map<int,int>freq;






vector<vector<int>>dp(3501,vector<int>(3501));
int fenq(int l , int r,int k ,int m , vector<int>&arr){
  if (m == 1){
		return max(arr[l],arr[r]);
	}
	if (dp[l][r]){
		return dp[l][r];
	}
	int A = fenq(l+1,r,max(0,k-1),m-1,arr);
  int B = fenq(l,r-1,max(0,k-1),m-1,arr);
	if(k)return dp[l][r] = max(A,B);
	return dp[l][r] = min(A,B);
}


void slov(){
  int t; cin>>t;
  while(t--){
    int n,m,k; read(n,m,k);
    range(0,n,i)range(0,n,j)dp[i][j]=0;
    vector<int>arr;
    range(1,n,i){int a; read(a); arr.push_back(a);}
    writeln(fenq(0,n-1,k,m,arr));
  }
}


THE mayn(){
    input.reset(new InputFile());
    output.reset(new OutputFile());
    watch_shid;
    slov();
    print_time(WATCH , 0); 

}


