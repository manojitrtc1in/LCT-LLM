




























                        

                        



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
static const char eof = '\xff';











struct Cg{I char OP()(){char c=(char)getchar();if(c == eof)valid=false;return c;};bool valid=true;};
struct Cp{I void OP()(int x){putchar(x);}};
struct Ce{I void OP()(int x){putc(x,stderr);}};
I bool IS(char x){return x==' '||x=='\r'||x=='\n'||x=='\t';}
template<class T>struct Fr{T P;ALL_INT(RD_INT)ALL_FLT(RD_FLT)I Fr&OP,(char&x){for(x=P();IS(x);)x=P();RT}
I Fr&OP,(char*s){for(*s=P();IS(*s)&&P.valid;)*s=P();for(;!IS(*s)&&P.valid;)*++s=P();*s=0;RT}
I Fr&OP,(string &s){s.clear();char c=P();for(;IS(c)&&P.valid;)c=P();for(;!IS(c)&&P.valid;)s.push_back(c),c=P();RT}
I OP bool() { return P.valid; }
};



template<class T>struct Fw{T P;char B[32];ALL_INT(WR_INT)ALL_FLT(WR_FLT)I Fw&OP,(char x){P(x);RT}typedef char_traits<char>CT;typedef basic_ostream<char,CT>&OS;typedef basic_istream<char,CT>&IS;I Fw&OP,(OS&(*func)(OS)){if(func==static_cast<OS&(*)(OS)>(endl<char,CT>))P('\n');RT}I Fw&OP,(IS&(*func)(IS)){if(func==static_cast<IS&(*)(IS)>(ws<char,CT>))P(' ');RT}
I Fw&OP,(const char*s){for(;*s;++s)P(*s);RT}
I Fw&OP,(const string&s){(*this),s.c_str();RT}
template<class C>I Fw&all(const C &v, char sep=' ', char nl='\n'){auto it=v.begin();for(int i=0;i<(int)v.size();++i,++it){if(i&&sep)P(sep);(*this),*it;}if(nl)P(nl);RT}
template<class U>I Fw&print(U x){(*this),x;P('\n');RT}
template<class U,class...Us>I Fw&print(U x,Us...args){(*this),x;P(' ');print(args...);RT}
};














}
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
    __int128_t p = __int128_t(a) * b;
    return (int64_t)(p % m);
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
Int id3(Int u, Int v, Int m) {
    Int r = u + v;
    if (r >= m) r -= m;
    return r;
}
template <typename Int>
Int id2(Int u, Int v, Int m) {
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












static const int maxn = 100005;
int n, m, seed, vmax;
int64_t a[maxn];
struct node_t {
    int len;
    int64_t v;
};
map<int, node_t> mp; 

int rnd() {
    int ret = seed;
    seed = (1LL * seed * 7 + 13) % 1000000007;
    return ret;
}
void add(int l, int r, int x) {
    auto it = mp.lower_bound(l);
    if (it == mp.end() || it->first > l) --it;
    assert(it->first <= l);
    int curx = it->first;
    while (curx <= r) {
        it = mp.lower_bound(curx);
        curx += it->second.len;
        if (it->first >= l && it->first + it->second.len - 1 <= r) {
            

            it->second.v += x;
            ++it;
        } else {
            int start = it->first;
            node_t cur = it->second;
            it = mp.erase(it);
            if (l > start) {
                

                mp[start] = node_t{l - start, cur.v};
            }
            if (r < start + cur.len - 1) {
                

                mp[r + 1] = node_t{start + cur.len - r - 1, cur.v};
            }
            int b = max(l, start), e = min(r, start + cur.len - 1);
            if (e >= b) mp[b] = node_t{e - b + 1, cur.v + x};
        }
    }
}
void assign(int l, int r, int x) {
    auto it = mp.lower_bound(l);
    if (it == mp.end() || it->first > l) --it;
    int curx = it->first;
    while (curx <= r) {
        it = mp.lower_bound(curx);
        curx += it->second.len;
        if (it->first >= l && it->first + it->second.len - 1 <= r) {
            

            it = mp.erase(it);
        } else {
            int start = it->first;
            node_t cur = it->second;
            it = mp.erase(it);
            if (l > start) {
                

                mp[start] = node_t{l - start, cur.v};
            }
            if (r < start + cur.len - 1) {
                

                mp[r + 1] = node_t{start + cur.len - r - 1, cur.v};
            }
        }
    }
    mp[l] = node_t{ r - l + 1, x };
}
int64_t kth(int l, int r, int x) {
    auto it = mp.lower_bound(l);
    if (it == mp.end() || it->first > l) --it;
    vector<pair<int64_t, int>> vec;
    while (it != mp.end() && it->first <= r) {
        if (it->first >= l && it->first + it->second.len - 1 <= r) {
            

            vec.push_back(make_pair(it->second.v, it->second.len));
            ++it;
        } else {
            int start = it->first;
            node_t cur = it->second;
            int b = max(l, start), e = min(r, start + cur.len - 1);
            vec.push_back(make_pair(cur.v, e - b + 1));
            ++it;
        }
    }
    int tot = 0;
    for (auto kv : vec) {
        tot += kv.second;
    }
    assert(tot == r - l + 1);
    sort(ALL(vec));
    for (auto kv : vec) {
        if (x < kv.second) return kv.first;
        x -= kv.second;
    }
    throw 0;
}
int64_t psum(int l, int r, int x, int y) {
    auto it = mp.lower_bound(l);
    if (it == mp.end() || it->first > l) --it;
    vector<pair<int64_t, int>> vec;
    while (it != mp.end() && it->first <= r) {
        if (it->first >= l && it->first + it->second.len - 1 <= r) {
            

            vec.push_back(make_pair(it->second.v, it->second.len));
            ++it;
        } else {
            int start = it->first;
            node_t cur = it->second;
            int b = max(l, start), e = min(r, start + cur.len - 1);
            vec.push_back(make_pair(cur.v, e - b + 1));
            ++it;
        }
    }
    int tot = 0;
    for (auto kv : vec) {
        tot += kv.second;
    }
    assert(tot == r - l + 1);
    int ans = 0;
    for (auto kv : vec) {
        ans += 1LL * pow_mod(int(kv.first % y), x, y) * kv.second % y;
        ans %= y;
    }
    return ans;
}
void check() {
    int cur = 1;
    auto it = mp.begin();
    while (it != mp.end()) {
        
        

        assert(it->first == cur);
        cur += it->second.len;
        assert(it->second.len > 0);
        ++it;
    }
    

    assert(cur == n + 1);
}
int main() {
    fin, n, m, seed, vmax;
    FOR(i, 1, n) {
        a[i] = (rnd() % vmax) + 1;
        mp[i] = node_t{1, 1LL * a[i]};
    }
    FOR(i, 1, m) {
        

        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        int x, y = 0;
        if (l > r)
             swap(l, r);
        if (op == 3)
            x = (rnd() % (r - l + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;
        if (op == 4)
            y = (rnd() % vmax) + 1;
        

        if (op == 1) {
            add(l, r, x);
            

        } else if (op == 2) {
            assign(l, r, x);
            

        } else if (op == 3) {
            int64_t  ans = kth(l, r, x - 1);
            fout, ans, endl;
            
        } else {
            assert(op == 4);
            int64_t ans = psum(l, r, x, y);
            fout, ans, endl;
            
        }
    }
    return 0;
}
