#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
string bits_to_string(ll mask, ll n) { string s; rep(i, n) s += '0' + !!(mask & (1ll << i)); return s; }
#define ldout fixed << setprecision(40) 


static const long long mo = 1e9+7;
class Mod {
    public:
        int num;
        Mod() : Mod(0) {}
        Mod(long long int n) : num(n) { }
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mo; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
ostream &operator<<(ostream &o, const Mod &x) { o << x.num; return o; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mo); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mo + a.num - b.num) % mo); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mo); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod factorial(const long long n) {
    if (n < 0) return 0;
    Mod ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod modpowsum(const Mod a, const long long b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}



class MD5
{
    public:
        typedef unsigned int size_type; 


        MD5();
        MD5(const string& text);
        MD5(const void* data, size_t data_size);
        void update(const unsigned char *buf, size_type length);
        void update(const char *buf, size_type length);
        MD5& finalize();
        string hexdigest() const;
        pair<size_t, size_t> integer() const;
        void* getMD5() const;
        friend ostream& operator<<(ostream&, MD5 md5);

    private:
        void init();
        typedef unsigned char uint1; 

        typedef unsigned int uint4;  

        enum {blocksize = 64}; 


        void transform(const uint1 block[blocksize]);
        static void decode(uint4 output[], const uint1 input[], size_type len);
        static void encode(uint1 output[], const uint4 input[], size_type len);

        bool finalized;
        uint1 buffer[blocksize]; 

        uint4 count[2];   

        uint4 state[4];   

        uint1 digest[16]; 


        

        static inline uint4 F(uint4 x, uint4 y, uint4 z);
        static inline uint4 G(uint4 x, uint4 y, uint4 z);
        static inline uint4 H(uint4 x, uint4 y, uint4 z);
        static inline uint4 I(uint4 x, uint4 y, uint4 z);
        static inline uint4 rotate_left(uint4 x, int n);
        static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
        static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};
string md5(const string str);

const int S11=7, S12=12, S13=17, S14=22, S21=5, S22=9, S23=14, S24=20, S31=4, S32=11, S33=16, S34=23, S41=6, S42=10, S43=15, S44=21;

inline MD5::uint4 MD5::F(uint4 x, uint4 y, uint4 z) { return (x&y) | ((~x)&z); }
inline MD5::uint4 MD5::G(uint4 x, uint4 y, uint4 z) { return (x&z) | (y&(~z)); }
inline MD5::uint4 MD5::H(uint4 x, uint4 y, uint4 z) { return x^y^z; }
inline MD5::uint4 MD5::I(uint4 x, uint4 y, uint4 z) { return y ^ (x | ~z); }
inline MD5::uint4 MD5::rotate_left(uint4 x, int n) { return (x << n) | (x >> (32-n)); }
inline void MD5::FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) { a = rotate_left(a+ F(b,c,d) + x + ac, s) + b; }
inline void MD5::GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) { a = rotate_left(a + G(b,c,d) + x + ac, s) + b; }
inline void MD5::HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) { a = rotate_left(a + H(b,c,d) + x + ac, s) + b; }
inline void MD5::II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) { a = rotate_left(a + I(b,c,d) + x + ac, s) + b; }
MD5::MD5() { init(); }

MD5::MD5(const string &text) {
    init();
    update(text.c_str(), text.length());
    finalize();
}
MD5::MD5(const void* data, size_t data_size) {
    init();
    update((const unsigned char*)data, (size_type)data_size);
    finalize();
}


void MD5::init() {
    finalized=false;
    count[0] = count[1] = 0;
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
}

void MD5::decode(uint4 output[], const uint1 input[], size_type len)
{
    for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
        output[i] = ((uint4)input[j]) | (((uint4)input[j+1]) << 8) |
            (((uint4)input[j+2]) << 16) | (((uint4)input[j+3]) << 24);
}

void MD5::encode(uint1 output[], const uint4 input[], size_type len)
{
    for (size_type i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = input[i] & 0xff;
        output[j+1] = (input[i] >> 8) & 0xff;
        output[j+2] = (input[i] >> 16) & 0xff;
        output[j+3] = (input[i] >> 24) & 0xff;
    }
}

void MD5::transform(const uint1 block[blocksize])
{
    uint4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    decode (x, block, blocksize);

    
    FF (a, b, c, d, x[ 0], S11, 0xd76aa478); 
    FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); 
    FF (c, d, a, b, x[ 2], S13, 0x242070db); 
    FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); 
    FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); 
    FF (d, a, b, c, x[ 5], S12, 0x4787c62a); 
    FF (c, d, a, b, x[ 6], S13, 0xa8304613); 
    FF (b, c, d, a, x[ 7], S14, 0xfd469501); 
    FF (a, b, c, d, x[ 8], S11, 0x698098d8); 
    FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); 
    FF (c, d, a, b, x[10], S13, 0xffff5bb1); 
    FF (b, c, d, a, x[11], S14, 0x895cd7be); 
    FF (a, b, c, d, x[12], S11, 0x6b901122); 
    FF (d, a, b, c, x[13], S12, 0xfd987193); 
    FF (c, d, a, b, x[14], S13, 0xa679438e); 
    FF (b, c, d, a, x[15], S14, 0x49b40821); 

    
    GG (a, b, c, d, x[ 1], S21, 0xf61e2562); 
    GG (d, a, b, c, x[ 6], S22, 0xc040b340); 
    GG (c, d, a, b, x[11], S23, 0x265e5a51); 
    GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); 
    GG (a, b, c, d, x[ 5], S21, 0xd62f105d); 
    GG (d, a, b, c, x[10], S22,  0x2441453); 
    GG (c, d, a, b, x[15], S23, 0xd8a1e681); 
    GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); 
    GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); 
    GG (d, a, b, c, x[14], S22, 0xc33707d6); 
    GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); 
    GG (b, c, d, a, x[ 8], S24, 0x455a14ed); 
    GG (a, b, c, d, x[13], S21, 0xa9e3e905); 
    GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); 
    GG (c, d, a, b, x[ 7], S23, 0x676f02d9); 
    GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); 

    
    HH (a, b, c, d, x[ 5], S31, 0xfffa3942); 
    HH (d, a, b, c, x[ 8], S32, 0x8771f681); 
    HH (c, d, a, b, x[11], S33, 0x6d9d6122); 
    HH (b, c, d, a, x[14], S34, 0xfde5380c); 
    HH (a, b, c, d, x[ 1], S31, 0xa4beea44); 
    HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); 
    HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); 
    HH (b, c, d, a, x[10], S34, 0xbebfbc70); 
    HH (a, b, c, d, x[13], S31, 0x289b7ec6); 
    HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); 
    HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); 
    HH (b, c, d, a, x[ 6], S34,  0x4881d05); 
    HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); 
    HH (d, a, b, c, x[12], S32, 0xe6db99e5); 
    HH (c, d, a, b, x[15], S33, 0x1fa27cf8); 
    HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); 

    
    II (a, b, c, d, x[ 0], S41, 0xf4292244); 
    II (d, a, b, c, x[ 7], S42, 0x432aff97); 
    II (c, d, a, b, x[14], S43, 0xab9423a7); 
    II (b, c, d, a, x[ 5], S44, 0xfc93a039); 
    II (a, b, c, d, x[12], S41, 0x655b59c3); 
    II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); 
    II (c, d, a, b, x[10], S43, 0xffeff47d); 
    II (b, c, d, a, x[ 1], S44, 0x85845dd1); 
    II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); 
    II (d, a, b, c, x[15], S42, 0xfe2ce6e0); 
    II (c, d, a, b, x[ 6], S43, 0xa3014314); 
    II (b, c, d, a, x[13], S44, 0x4e0811a1); 
    II (a, b, c, d, x[ 4], S41, 0xf7537e82); 
    II (d, a, b, c, x[11], S42, 0xbd3af235); 
    II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); 
    II (b, c, d, a, x[ 9], S44, 0xeb86d391); 

    state[0] += a; state[1] += b; state[2] += c; state[3] += d;

    memset(x, 0, sizeof x);
}

void MD5::update(const unsigned char input[], size_type length)
{
    size_type index = count[0] / 8 % blocksize;
    if ((count[0] += (length << 3)) < (length << 3))
        count[1]++;
    count[1] += (length >> 29);
    size_type firstpart = 64 - index;
    size_type i;
    if (length >= firstpart) {
        memcpy(&buffer[index], input, firstpart);
        transform(buffer);
        for (i = firstpart; i + blocksize <= length; i += blocksize) transform(&input[i]);
        index = 0;
    } else
        i = 0;
    memcpy(&buffer[index], &input[i], length-i);
}
void MD5::update(const char input[], size_type length) { update((const unsigned char*)input, length); }
MD5& MD5::finalize() {
    static unsigned char padding[64] = {
        0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    if (!finalized) {
        unsigned char bits[8];
        encode(bits, count, 8);
        size_type index = count[0] / 8 % 64;
        size_type padLen = (index < 56) ? (56 - index) : (120 - index);
        update(padding, padLen);
        update(bits, 8);
        encode(digest, state, 16);
        memset(buffer, 0, sizeof buffer);
        memset(count, 0, sizeof count);
        finalized=true;
    }
    return *this;
}


string MD5::hexdigest() const {
    if (!finalized) return "";
    char buf[33];
    size_t long_long = 0;
    for (int i=0; i<16; i++) {
        sprintf(buf+i*2, "%02x", digest[i]);
        long_long |= ((size_t)digest[i] << (i * 4));
    }
    buf[32]=0;
    return string(buf);
}
pair<size_t, size_t> MD5::integer() const {
    if (!finalized) return mp(0, 0);
    size_t ret_u = 0;
    for (int i=0; i<8; i++) 
        ret_u |= ((size_t)digest[i] << (i * 4));
    size_t ret_l = 0;
    for (int i=0; i<8; i++) 
        ret_l |= ((size_t)digest[i+8] << (i * 4));
    return pair<size_t, size_t>(ret_u, ret_l);
}
void* MD5::getMD5() const {
    if (!finalized) return NULL;
    return (void*)digest;
}



string md5String(const string &str) {
    MD5 md5 = MD5(str);
    return md5.hexdigest();
}





pair<size_t, size_t> md5Raw(const void* input, size_t input_size) {
    MD5 md5 = MD5(input, input_size);
    return md5.integer();
}





template<typename T> 
pair<size_t, size_t> md5Vector(vector<T> &input) {
    if (input.size() == 0) return mp(0, 0); 

    MD5 md5 = MD5(input.data(), sizeof(T) * input.size());
    return md5.integer();
}



int main() {
    int n, m;
    cin >> n >> m;

    vector<map<int, int>> mp(n);
    for (int i = 0; i < n; i++) {
        int g;
        scanf("%d", &g);
        for (int j = 0; j < g; j++) {
            int k;
            scanf("%d", &k);
            k--;
            mp[i][k]++;
        }
    }

    vector<vector<P>> rev(m);
    rep(i, n) for (auto kv : mp[i]) {
        rev[kv.first].pb(P(i, kv.second));
    }
    sort(all(rev));
    rep(i, m) {
        sort(all(rev[i]));
    }

    map<pair<size_t, size_t>, int> cnt;
    rep(i, m) 
        cnt[md5Vector(rev[i])]++;



    vector<Mod> fact(1010101);
    fact[0] = 1;
    repi(i, 1, fact.size()) 
        fact[i] = fact[i - 1] * i;

    vll tmp; 
    Mod ans = 1;
    for (auto kv : cnt) {
        ans *= fact[kv.second];
        tmp.pb(kv.second);
    }
    sort(all(tmp));



    cout << ans << endl;
}