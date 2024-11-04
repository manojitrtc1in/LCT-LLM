




























                        

                        



using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }








typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
namespace fio {











struct Cg{I char OP()(){return (char)getchar();}};
struct Cp{I void OP()(int x){putchar(x);}};
struct Ce{I void OP()(int x){putc(x,stderr);}};
I bool IS(char x){return x==' '||x=='\r'||x=='\n'||x=='\t';}
template<class T>struct Fr{T P;ALL_INT(RD_INT)ALL_FLT(RD_FLT)I Fr&OP,(char&x){for(x=P();IS(x);)x=P();RT}
I Fr&OP,(char*s){for(*s=P();IS(*s);)*s=P();for(;!IS(*s);)*++s=P();*s=0;RT}
I Fr&OP,(string &s){char c=P();for(;IS(c);)c=P();for(;!IS(c);)s.push_back(c),c=P();RT}
};



template<class T>struct Fw{T P;char B[32];ALL_INT(WR_INT)ALL_FLT(WR_FLT)I Fw&OP,(char x){P(x);RT}typedef char_traits<char>CT;typedef basic_ostream<char,CT>&OS;typedef basic_istream<char,CT>&IS;I Fw&OP,(OS&(*func)(OS)){if(func==static_cast<OS&(*)(OS)>(endl<char,CT>))P('\n');RT}I Fw&OP,(IS&(*func)(IS)){if(func==static_cast<IS&(*)(IS)>(ws<char,CT>))P(' ');RT}
I Fw&OP,(const char*s){for(;*s;++s)P(*s);RT}
I Fw&OP,(const string&s){(*this),s.c_str();RT}
template<class U>I Fw&all(const vector<U> &v, char sep=' ', char nl='\n'){for(int i=0;i<(int)v.size();++i){if(i&&sep)P(sep);(*this),v[i];}if(nl)P(nl);RT}
template<class U>I Fw&print(U x){(*this),x;P('\n');RT}
template<class U,class...Us>I Fw&print(U x,Us...args){(*this),x;P(' ');print(args...);RT}
};














};
fio::Fr<fio::Cg>fin;
fio::Fw<fio::Cp>fout;
fio::Fw<fio::Ce>ferr;





template <typename Int>
Int gcd(Int a, Int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}
template <typename Int, typename RInt = Int>
Int lcm(Int a, Int b) {
    return a / gcd(a, b) * static_cast<RInt>(b);
}
template <typename Int, typename XInt>
Int id1(Int a, Int b, XInt &x, XInt &y) {
    static_assert(std::numeric_limits<XInt>::is_signed,
            "x, y must be signed");
    

    

    

    

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    Int g = id1(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
template <typename Int>
Int mul_mod(Int a, Int b, Int m) {
    typedef int64_t TInt;
    static_assert(2 * std::numeric_limits<Int>::digits <= std::numeric_limits<TInt>::digits,
            "multiplication will overflow!");
    TInt p = a;
    p = (p * b) % m;
    return (Int)p;
}
template <>
int64_t mul_mod<int64_t>(int64_t a, int64_t b, int64_t m) {
    int64_t r = 0;
    for (int i = 63; i >= 0; --i) {
        r = (r + r) % m;
        if ((b >> i) & 1)
            r = (r + a) % m;
    }
    return r;
}
template <typename Int, typename PInt>
Int pow_mod(Int a, PInt p, Int m) {
    Int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}
template <typename Int,
          typename XInt = typename std::make_signed<Int>::type>
Int inv_mod(Int a, Int m) {
    

    XInt x, y;
    id1(a, m, x, y);
    if (x < 0)
        return x + m;
    return x;
}
template <typename Int>
Int id4(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id3(Int u, Int v, Int m) {
    Int r = u - v;
    if (r < 0) r += m;
    return r;
}
template <typename Int>
Int div_mod(Int u, Int v, Int m) {
    

    

    

    

    

    

    

    

    

    Int g = gcd(v, m);
    assert(u % g == 0);
    Int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}
template <typename Int>
Int id0(Int a, Int b, Int &r) {
    

    

    

    

    

    

    

    Int q = a / b;
    r = a % b;
    if (r < 0) {
        if (b < 0)
            q += 1, r -= b;
        else
            q -= 1, r += b;
    }
    return q;
}












template <typename T>
struct binary_plus {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 + t2; }
    T negate(const T &t) { return -t; }
};
template <typename T, T MOD>
struct modular_plus {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return (t1 + t2) % MOD; }
    T negate(const T &t) { return (MOD - t) % MOD; }
};
template <typename T, T MOD, typename TT = int64_t>
struct modular_times {
    T identity() const { return 1; }
    T operator()(const T &t1, const T &t2) const { return mul_mod(t1, t2, MOD); }
    T negate(const T &t) { return inv_mod(t, MOD); }
};
template <typename T>
struct binary_xor {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 ^ t2; }
    T negate(const T &t) { return t; }
};
template <typename T>
struct binary_max {
    T identity() const { return std::numeric_limits<T>::min(); }
    T operator()(const T &t1, const T &t2) const { return std::max(t1, t2); }
};
template <typename T>
struct binary_min {
    T identity() const { return std::numeric_limits<T>::max(); }
    T operator()(const T &t1, const T &t2) const { return std::min(t1, t2); }
};


template<typename T, typename Op = binary_plus<T>>
struct bitree {
    Op op;
    

    std::vector<T> vec;
    bitree(int size) : vec(size) { }
    T query_include(int e) {
        T ans = op.identity();
        if (e == -1) return ans;
        while (e != 0)
            ans = op(vec[e], ans), e -= e & -e;
        ans = op(vec[0], ans);
        return ans;
    }
    T query_range(int e) {
        return query_include(e - 1);
    }
    T query_element(int p) {
        return op(query_include(p), op.negate(query_range(p)));
    }
    void increase_element(int p, const T &n) {
        if (p == 0)
            vec[0] = op(vec[0], n);
        else {
            while (p < vec.size()) {
                vec[p] = op(vec[p], n);
                p += p & -p;
            }
        }
    }
};















































int64_t ans;
struct Q{
    bool is_q;
    int x, p, f; 
    int sign;
    

    

};
vector<Q> qs;
bitree<int64_t, binary_plus<int64_t>> bit(20000);
bool cmp_x(Q q1, Q q2) {
    return make_tuple(q1.x, -q1.p, q1.f, q1.is_q) < make_tuple(q2.x, -q2.p, q2.f, q2.is_q);
}
bool cmp_q(Q q1, Q q2) {
    return make_tuple(-q1.p, q1.f, q1.is_q) < make_tuple(-q2.p, q2.f, q2.is_q);
}
void id2(vector<Q> &v, int b, int e) {
    if (e - b <= 1) return;
    int m = (b + e) / 2;
    id2(v, b, m);
    id2(v, m, e);
    FOR(i, b, m - 1) if (!v[i].is_q) {
        bit.increase_element(v[i].f, 1);
    }
    FOR(i, m, e - 1) if (v[i].is_q) {
        ans += bit.query_include(v[i].f) * v[i].sign;
    }
    FOR(i, b, m - 1) if (!v[i].is_q) {
        bit.increase_element(v[i].f, -1);
    }
}
void CDQ(int b, int e) {
    if (e - b <= 1) return;
    int m = (b + e) / 2;
    CDQ(b, m);
    CDQ(m, e);
    

    vector<Q> ps;
    FOR(i, b, m - 1) if (!qs[i].is_q) ps.push_back(qs[i]);
    FOR(i, m, e - 1) if (qs[i].is_q) ps.push_back(qs[i]);
    sort(ALL(ps), cmp_q);
    id2(ps, 0, (int)ps.size());
}
int n, k;
int main() {
    fin, n, k;
    FOR0(i, n) {
        int x, r, f; fin, x, r, f;
        qs.push_back({false, x, x + r, f});
        qs.push_back({true, x, x, f + k, 1});
        qs.push_back({true, x - r - 1, x, f + k, -1});
        qs.push_back({true, x, x, max(0, f - k - 1), -1});
        qs.push_back({true, x - r - 1, x, max(0, f - k - 1), 1});
    }
    sort(ALL(qs), cmp_x);
    CDQ(0, (int)qs.size());
    fout, ans - n, endl;
    return 0;
}
