




















    
    using namespace __gnu_pbds;



using namespace std;
























template<class T> T peek(queue<T>& q) { T top_el = q.front(); q.pop(); return top_el; }


















typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<int>> graph;




template<typename T> inline int bit(T n, T i){return ((n >> i) & T(1));}
inline int bitcount(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + ((v >> 4) & 0xF0F0F0F)) * 0x1010101) >> 24; }
inline int bitcount(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bitcount(t) + bitcount(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool id0(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << bit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << bit(n, i); } cout << "\n"; }


template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T id2(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=id2(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}
template<typename T> inline bool between(T x, T l, T r) { return l <= x && x <= r; }


template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}



void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r) cin >> arr[i]; }



template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const std::set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r) {cout << arr[i] << " ";}; cout << "\n"; }



template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }



template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }



template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::tensor(args...); }


typedef __int128 bigInt;
istream& operator >>(istream& in, bigInt& n){
    in >> ws; n = 0;
    for(char ch = getchar(); isdigit(ch); ch = getchar()){
        n = n*bigInt(10) + bigInt(ch-'0');
    }
    return in;
}
ostream& operator <<(ostream& out, bigInt n){
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int representation[36];
    int pos = 0;
    while(n){
        representation[pos++] = digits[n % 10];
        n /= 10;
    }
    for(int i = pos-1; i >= 0; i--){
        out << representation[i];
    }
    return out;
}



















template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }


const int id3 = 2048;
static char inbuf[id3 + 16];
static char *inp = inbuf;
static char *linp = inbuf + id3;
int read_int()
{
    if (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, id3);
        cin.read(inbuf, id3);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    bool minus = false;
    if (*inp == '-') minus = true, ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, id3);
        cin.read(inbuf, id3);
        inp = inbuf;
    }
    int res = *inp++ - '0';
    if (inp == linp)
    {
        memset(inbuf, 0, id3);
        cin.read(inbuf, id3);
        inp = inbuf;
    }
    while (*inp >= '0' && *inp <= '9')
    {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp)
        {
            memset(inbuf, 0, id3);
            cin.read(inbuf, id3);
            inp = inbuf;
        }
    }
    return minus ? -res : res;
}
static char outbuf[id3 + 16];
static char *outp = outbuf;
static char *loutp = outbuf + id3;
void write_int(int x, bool last = false)
{
    char *begp = outp;
    do
    {
        int t = x / 10;
        char c = x - 10 * t + '0';
        *outp++ = c;
        x = t;
    } while (x);
    char *endp = outp - 1;
    while (begp < endp)
    {
        swap(*begp, *endp);
        ++begp;
        --endp;
    }
    *outp++ = '\n';
    if (last || outp > loutp)
    {
        cout.write(outbuf, outp - outbuf);
       outp = outbuf;
    }
}



template <class T>
    struct custom_vector : vector<T> {
    custom_vector() : vector<T>() { }
    custom_vector( int n ) : vector<T>(n) { }
    custom_vector( int n, T x ) : vector<T>(n, x) { }
    T &operator [] ( size_t i ) {
        return vector<T>::at(i);
    }
    const T &operator [] ( size_t i ) const {
        return vector<T>::at(i);
    }
};




bool id1(const deque<char>& lhs, const deque<char>& rhs) {
    int n = lhs.size(), m = rhs.size();




    for (int i = 0; i < min(n, m); i++) {
        if (lhs[i] < rhs[i]) {  return 1; }
        if (lhs[i] > rhs[i]) {  return 0; }
    }


    return n <= m;
}

int main(){
    fastIO();




    int n; cin >> n;
    vector<ll> c(n); cin >> c >> ws;
    vector<deque<char>> s(n), rs(n);
    for (int i = 0; i < n; i++) {
        for (char ch; (ch=cin.get()) != '\n';) {
            s[i].push_back(ch);
            rs[i].push_front(ch);
        }
    }
    vector<vector<ll>> d(n, vector<ll>(2, LINF));
    d[0][0] = 0; d[0][1] = c[0];
    for (int i = 1; i < n; i++) {
        if (d[i-1][0] != LINF) {
            if (id1(s[i-1], s[i])) {
                d[i][0] = min(d[i][0], d[i-1][0]);
            }
            if (id1(s[i-1], rs[i])) {
                d[i][1] = min(d[i][1], d[i-1][0]+c[i]);
            }
        }
        if (d[i-1][1] != LINF) {
            if (id1(rs[i-1], s[i])) {
                d[i][0] = min(d[i][0], d[i-1][1]);
            }
            if (id1(rs[i-1], rs[i])) {
                d[i][1] = min(d[i][1], d[i-1][1]+c[i]);
            }
        }
        if (d[i][0] == LINF && d[i][1] == LINF) {
            cout << "-1" << endl;
            return 0;
        }
    }


    cout << min(d[n-1][0], d[n-1][1]) << endl;
    return 0;
}


const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete ( void * ) { }

