

using namespace __gnu_pbds;
using namespace std; 





































using ll=long long int;
using ld=long double;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;





void __print(int x) {cerr << x;} 
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;} 
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x){cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;} 
void __print(double x) {cerr << x;}
void __print(long double x){cerr << x;} 
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x){cerr<<'\"'<<x<<'\"';}
void __print(const string &x) {cerr<<'\"'<<x<<'\"';}
void __print(bool x){cerr<<(x?"true":"false");}
template<typename T, typename V>
void __print(const pair<T, V> &x){cerr<<'{'; __print(x.first);cerr<<','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) 
{ return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) 
{ return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } 
void debug_out() { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ordered_set=tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>; 










template<typename T> int SIZE(T (&t)){ return t.size(); }
template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; }
string to_string(char t){ return "'" + string({t}) + "'"; }
string to_string(bool t){ return t ? "true" : "false"; }
string to_string(const string &t, int x1=0, int x2=1e9){
    string ret = "";
    for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; }
    return '"' + ret + '"'; }
string to_string(const char* t){ string ret(t); return to_string(ret); }

template<size_t N>
string to_string(const bitset<N> &t, int x1=0, int x2=1e9){
    string ret = "";
    for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret+=t[i]+'0'; }
    return to_string(ret); }
template<typename T, typename... Coords>
string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C);
template<typename T, typename S>
string to_string(const pair<T, S> &t){
    return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; }
template<typename T, typename... Coords>
string to_string(const T (&t), int x1, int x2, Coords... C){
    string ret = "["; x1=min(x1, SIZE(t));
    auto e = begin(t);
    advance(e,x1);
    for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){
        ret += to_string(*e, C...) + (i != _i ? ", " : "");
        e = next(e);
    }
    return ret + "]";
}

template<int Index, typename... Ts>
struct print_tuple{
    string operator() (const tuple<Ts...>& t) {
        string ret = print_tuple<Index - 1, Ts...>{}(t);
        ret += (Index ? ", " : "");
        return ret + to_string(get<Index>(t));
    }
};

template<typename... Ts>
struct print_tuple<0, Ts...> {
    string operator() (const tuple<Ts...>& t) {
        return to_string(get<0>(t));
    }
};

template<typename... Ts>
string to_string(const tuple<Ts...>& t) {
    const auto Size = tuple_size<tuple<Ts...>>::value;
    return print_tuple<Size - 1, Ts...>{}(t);
}

void dbgr(){;}
template<typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T){
    cout << to_string(H) << " | ";
    dbgr(T...);
}

void dbgs(){;}
template<typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T){
    cout << H << " ";
    dbgs(T...);
}




namespace FastIO {
struct Reader {
private: FILE* file; std::vector<char> buffer; int pos; bool was;
void read(){ if(!buffer.empty()) {buffer.resize(fread(&buffer[0],1,(int)buffer.size(),file));pos=0;}}
public:
Reader(FILE* file_=stdin,const int size_=1<<16):file(file_),buffer(size_,'\0'),pos(size_),was(true){ }
operator bool() const {return was;}
char getChar(){ if(pos==(int)buffer.size()) { read();}
if(pos==(int)buffer.size()) { was=false; return EOF; } 
else{ was=true; return buffer[pos++]; } }
string getStr() {char c=' '; while(std::isspace(c)){ c=getChar(); }
string answ; while(c!=EOF&&!std::isspace(c)){answ.push_back(c); c= getChar();}
was=!answ.empty(); return answ; }
string getLine() { char c='\n'; string answ; 
while(c=='\n'){c=getChar();} 
while(c!='\n'&& c!=EOF){ answ.push_back(c);c=getChar(); }
was=!answ.empty(); return answ; }
template<typename T> T getInt(){char c='?'; 
while(!(c=='-'||('0'<=c&&c<='9')||c==EOF)){c=getChar();} bool positive=true; 
if(c=='-'){ positive=false; c=getChar(); } T answ(0); bool flag=false;
while('0'<=c && c<='9'){ flag=true;(answ*=10)+=(c-'0'); c= getChar(); }
was=flag; return positive?answ:-answ;}
template<typename T> T getReal(){ bool flag=false; char c='?';
while(!(c=='-'||('0'<=c&&c<='9')||c==EOF)){ c=getChar(); }
bool positive=(c!='-'); if(c=='-'){ c=getChar(); } ll first=0;
while('0'<=c&&c<='9'){ flag=true; (first*=10)+=(c-'0'); c= getChar(); }
was=flag; if(c!='.'){ return T(positive?first:-first); }
c=getChar(); ll second=0,pow=1;
while('0'<=c&&c<='9') { (second*=10)+=(c-'0'); c=getChar(); pow*=10; }
T answ=first+(T)second/(T)pow; return positive?answ:-answ; }    
};
Reader& operator>>(Reader& reader, char& c) { return c = reader.getChar(), reader; }
Reader& operator>>(Reader& reader, std::string& s) { return s = reader.getStr(), reader; }
template<class T> typename std::enable_if<std::is_floating_point<T>::value, Reader&>::type
operator>>(Reader& reader, T& t) { return t = reader.getReal<T>(), reader; }
template<class T> typename std::enable_if<std::is_integral<T>::value, Reader&>::type
operator>>(Reader& reader, T& t) { return t = reader.getInt<T>(), reader; }
template<class T> Reader& operator>>(Reader& reader, std::vector<T>& vec) {
for (auto &it : vec) { reader >> it; } return reader; }
struct Writer {
private: FILE* file; std::vector<char> buffer; int pos,defaultPrecision,defaultWidth; char defaultFill;
public: Writer(FILE* file_ = stdout, const int size_ = 1 << 16) 
: file(file_), buffer(size_, '\0'), pos(0), defaultPrecision(6), defaultWidth(0), defaultFill(' ') { }
~Writer() { flush(); }
void flush() { putChar(EOF); }
void setprecision(int precision) { defaultPrecision = precision; }
void setw(int width) { defaultWidth = width; }
void setfill(char fill) { defaultFill = fill; }
int getPrecision() const { return defaultPrecision; }
int getWidth() const { return defaultWidth; }
char getFill() const { return defaultFill; }
void putChar(char c) { if(pos==(int)buffer.size()||c==EOF){fwrite(&buffer[0],1,pos,file);pos=0;}
if(c!=EOF){ buffer[pos++]=c; } } void putStr(const std::string& s) { for (auto it : s) putChar(it); }
template<typename T> void putInt(T value, int width = 0, char fill = ' ') {
bool positive=!(value<0); if(value<0) { value=-value; } char buf[24]; int p=0;
do {buf[p++]=char(value % 10 + '0'); value /= 10; } while(value>0);
if(!positive){buf[p++]='-';} while(p<width) buf[p++]=fill; 
while(p>0)putChar(buf[--p]); }
template<typename T> void putReal(T value,int precision=6,int width=0,char fill=' ') {
putInt((long long)value,width-precision-1,fill); value=std::abs(value-(long long)value);
if (precision==0){ return; } putChar('.');

PRINT_PART(6,1000000) PRINT_PART(3,1000) PRINT_PART(1,10) 

} };
Writer& operator<<(Writer& writer, const char c) { return writer.putChar(c), writer; }
Writer& operator<<(Writer& writer, const std::string& s) { return writer.putStr(s), writer; }
template<class T> typename std::enable_if<std::is_floating_point<T>::value, Writer&>::type
operator<<(Writer& writer, const T& t){writer.putReal(t,writer.getPrecision(),writer.getWidth(),writer.getFill());
return writer; }
template<class T> typename std::enable_if<std::is_integral<T>::value, Writer&>::type
operator<<(Writer& writer, const T& t){writer.putInt(t,writer.getWidth(),writer.getFill());
return writer; } }
template<typename V>
inline void rd(V &x) { char c; while(c=_getchar_nolock(),c<=' '); bool sign(c=='-');
if(sign){ c=_getchar_nolock(); } x=(c-'0');
while(c=_getchar_nolock(),!((c<'0')|(c>'9'))) {x=10*x+c-'0';} if(sign) x=-x; }
template<typename H,typename... T>
void rd(H& h, T&... t) { rd(h); rd(t...); }
static const int buf_len=(1<<14); static const int buf_max=(1<<04);
static char buf_out[buf_len]; static char buf_num[buf_max];
static int buf_pos = 0;
template <typename T>
inline void writeChar(T x){ if(buf_pos==buf_len)fwrite(buf_out,1,buf_len,stdout),buf_pos=0;
buf_out[buf_pos++]=x; }
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pll> vpll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<bool, ll> pbl;
typedef vector<pbl> vpbl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<pdd> vpdd;
typedef vector<string> vs;
typedef pair<ul, int> pui;
typedef vector<pui> vpui;
typedef vector<ul> vu;
mt19937 rng(2391);
mt19937 gnr(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        fin >> *it;
    return fin;
}
template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
    fin >> p.X >> p.Y;
    return fin;
}
template<typename A, typename B>
pair<A, B> operator+(const pair<A, B>& a, const pair<A, B>& b)
{
    return mp(a.X + b.X, a.Y + b.Y);
}
template<typename A, typename B>
pair<A, B> operator+=(pair<A, B>& a, const pair<A, B>& b)
{
    a.X += b.X;
    a.Y += b.Y;
    return a;
}
template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a, const pair<A, B>& b)
{
    return mp(a.X - b.X, a.Y - b.Y);
}
template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a)
{
    return mp(-a.X, -a.Y);
}
template<typename A, typename B>
pair<A, B>& operator++(pair<A, B>& a)
{
    ++a.X;
    ++a.Y;
    return a;
}
template<typename A, typename B>
pair<A, B>& operator--(pair<A, B>& a)
{
    --a.X;
    --a.Y;
    return a;
}
template<typename A>
vector<A>& operator++(vector<A>& a)
{
    for (auto it = a.begin(); it != a.end(); ++it)
        ++* it;
    return a;
}
template<typename A>
vector<A>& operator--(vector<A>& a)
{
    for (auto it = a.begin(); it != a.end(); ++it)
        --* it;
    return a;
}
template<typename A, typename B>
pair<A, B> operator++(pair<A, B>& a, int)
{
    pair<A, B> b = a;
    ++a;
    return b;
}
template<typename A, typename B>
pair<A, B> operator--(pair<A, B>& a, int)
{
    pair<A, B> b = a;
    --a;
    return b;
}
template<typename A>
vector<A>& operator++(vector<A>& a, int)
{
    vector<A> b = a;
    ++a;
    return b;
}
template<typename A>
vector<A>& operator--(vector<A>& a, int)
{
    vector<A> b = a;
    --a;
    return b;
}
vvi id43(const vpii& e, const int& n)
{
    vvi g(n);
    for (auto it = e.begin(); it != e.end(); ++it)
    {
        g[it->X].pb(it->Y);
        g[it->Y].pb(it->X);
    }
    return g;
}
template<typename A, typename B>
pair<A, B> operator-=(pair<A, B>& a, const pair<A, B>& b)
{
    a.X -= b.X;
    a.Y -= b.Y;
    return a;
}
template<typename A>
A operator*(const pair<A, A>& p, const pair<A, A>& q)
{
    return p.X * q.X + p.Y * q.Y;
}
template<typename A>
pair<A, A> operator*(const pair<A, A>& p, const A& q)
{
    return mp(p.X * q, p.Y * q);
}
template<typename A>
A operator%(const pair<A, A>& p, const pair<A, A>& q)
{
    return p.X * q.Y - p.Y * q.X;
}
template<typename A>
A sq_len(const pair<A, A>& p)
{
    return p * p;
}
template<typename A>
A sq_dist(const pair<A, A>& p, const pair<A, A>& q)
{
    return sq_len(p - q);
}
template<typename A>
double len(const pair<A, A>& p)
{
    return sqrt(sq_len(p));
}
template<typename A>
double dist(const pair<A, A>& p, const pair<A, A>& q)
{
    return len(p - q);
}
template<typename A>
bool id28(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    A x = sq_dist(a, b);
    A y = sq_dist(b, c);
    A z = sq_dist(c, d);
    A t = sq_dist(d, a);
    return ((x == y) && (y == z) && (z == t));
}
template<typename A>
bool is_rectangle(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    pair<A, A> x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    return ((x * y == 0) && (y * z == 0) && (z * t == 0) && (t * x == 0));
}
template<typename A>
bool are_parallel(const pair<A, A>& a, const pair<A, A>& b)
{
    return (a % b == 0);
}
template<typename A>
bool id29(const pair<A, A>& a, const pair<A, A>& b)
{
    return (a * b == 0);
}
template<typename A>
bool id44(const pair<A, A>& a, const pair<A, A>& b)
{
    return (are_parallel(a, b) && (a * b >= 0));
}
template<typename A>
bool id51(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    return ((a - b) == (d - c));
}
template<typename A>
bool id39(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    pair<A, A> x = a - b, z = d - c;
    return id44(x, z);
}
template<typename A>
bool id33(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    pair<A, A> x = a - b,
        y = b - c,
        z = c - d,
        t = d - a;
    A p = x % y, q = y % z, r = z % t, s = t % x;
    return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
        ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}


template<typename A>
bool id18(const pair<A, A>& a, const pair<A, A>& c)
{
    return ((a % c) >= 0);
}
template<typename A>
bool id18(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
    return id18(a - b, a - c);
}


template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& c)
{
    return ((a % c) <= 0);
}
template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
    return npocs(a - b, a - c);
}


template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& c)
{
    return ((a % c) > 0);
}
template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
    return prcs(a - b, a - c);
}


template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& c)
{
    return ((a % c) < 0);
}
template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
    return pocs(a - b, a - c);
}
template<typename A>
bool id53(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    pair<A, A> x = b - a;
    A p = x % (c - b), q = x % (d - b);
    return (((p >= 0) && (q <= 0)) ||
        ((p <= 0) && (q >= 0)));
}
template<typename A>
bool id23(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
    pair<A, A> x = b - a;
    A p = x % (c - b), q = x % (d - b);
    return (((p > 0) && (q < 0)) ||
        ((p < 0) && (q > 0)));
}
template<typename A>
pair<A, A> id45(const pair<A, A>& p)
{
    return mp(-p.Y, p.X);
}
template<typename A>
pair<A, A> id45(const pair<A, A>& p, const pair<A, A>& c)
{
    return c + id45(p - c);
}
template<typename A>
bool id9(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
    return id53(a, b, c, d) && id53(c, d, a, b);
}
template<typename A>
bool id40(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) 

{
    return id23(a, b, c, d) && id23(c, d, a, b);
}
template <typename A>
pair<pair<A, A>, A> id2(const pair<A, A>& normal, const pair<A, A>& point)
{
    return mp(normal, -(normal * point));
}
template <typename A>
pair<pair<A, A>, A> serper(const pair<A, A>& a, const pair<A, A>& b)
{
    

    

    

    

    pair<A, A> p = b - a;
    return mp(p + p, -(p * (a + b)));
}
pdd ints(const pdd& p, const double& a,
    const pdd& q, const double& b)
{
    double D = p % q;
    double E = pdd(-a, p.Y) % pdd(-b, q.Y);
    double F = pdd(p.X, -a) % pdd(q.X, -b);
    return pdd(E / D, F / D);
}
pdd id46(const pdd& x, const pdd& y, const pdd& z)
{
    auto p1 = serper(x, y),
        p2 = serper(x, z);
    return ints(p1.X, p1.Y, p2.X, p2.Y);
}
template<typename A>
pair<pair<A, A>, A> id8(const pair<A, A>& p, const pair<A, A>& q)
{
    return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}
template<typename A>
vector<pdd> id38(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
{
    pair<A, A> c = b.X - a.X;
    A rr1 = a.Y * a.Y, rr2 = b.Y * b.Y, cc = c * c,
        rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
        D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
    if (D >= 0)
    {
        double E = (((double)(rr1 - rr2)) / cc + 1) / 2;
        pdd baza = pdd(a.X.X, a.X.Y) + pdd(c.X, c.Y) * E;
        if (D)
        {
            double lll = sqrt((double)(D)) / (2 * cc);
            pair<A, A> cr = id45(c);
            pdd pmm = pdd(cr.X, cr.Y) * lll;
            return{ baza + pmm, baza - pmm };
        }
        else
            return vector<pdd>(1, baza);
    }
    else
        return vector<pdd>();
}
template<typename A, typename B>
pair<A, B> sopr(const pair<A, B>& p)
{
    return mp(p.X, -p.Y);
}
template<typename A>
bool on_segment(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
    return id44(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
    return id2(id45(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
    pair<pdd, double> temp = perpendicular(line.X, point);
    return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
    return projection(id8(a, c), b);
}
pdd unitvector(const pdd& a)
{
    return a * (1 / len(a));
}
template<typename T>
vi z_function(const vector<T>& s)
{
    int n = sz(s);
    vi z(n);
    int l = 0, r = 1;
    for (int i = 1; i < n; ++i)
    {
        z[i] = max(0, min(r - i, z[i - l]));
        while (i + z[i] < n && (s[i + z[i]] == s[z[i]]))
            ++z[i];
        if (r < i + z[i])
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
pii euc(const int& m, const int& n)
{
    if (n == 0)
        return pii((m >= 0) ? 1 : -1, 0);
    int t = m / n;
    pii ans1 = euc(n, m - t * n);
    return pii(ans1.Y, ans1.X - ans1.Y * t);
}
int prod(const int& a, const int& b, const int& M)
{
    return ((ll)(a)) * b % M;
}
int sum(const int& a, const int& b, const int& M)
{
    int c = a + b;
    return c >= M ? c - M : c;
}
int raz(const int& a, const int& b, const int& M)
{
    int c = a - b;
    return c < 0 ? c + M : c;
}
const int id20 = 400;
struct id19
{
    int N;
    vi pr;
    vi md;
    vi pw;
    vi without_md;
    id19(const int& n) : N(n), md(n), pw(n), without_md(n, 1)
    {
        for (int i = 2; i < N; ++i)
            md[i] = i;
        for (int i = 2; i < N; ++i)
        {
            if (md[i] == i)
                pr.pb(i);
            bool worth = true;
            for (int j = 0; worth && (j < sz(pr)) && (pr[j] <= md[i]); ++j)
            {
                ll temp = ((ll)(pr[j])) * i;
                if (temp < N)
                    md[((int)temp)] = pr[j];
                else
                    worth = false;
            }
        }
        for (int i = 2; i < N; ++i)
        {
            int t = md[i], s = i / t;
            if (md[s] == t)
            {
                pw[i] = 1 + pw[s];
                without_md[i] = without_md[s];
            }
            else
            {
                pw[i] = 1;
                without_md[i] = s;
            }
        }
    }
    void known_factorization(int n, vpui& v)
    {
        while (n > 1)
        {
            v.eb(md[n], pw[n]);
            n = without_md[n];
        }
    }
    vpui pollardRho(const ul& n);
    vpui factor(ul n);
    template<typename T>
    vector<pair<T, int>> merge(const vector<pair<T, int>>& p1, const vector<pair<T, int>>& p2)
    {
        vector<pair<T, int>> ans;
        int m = sz(p1);
        int n = sz(p2);
        int i = 0; int j = 0;
        while ((i < m) || (j < n))
        {
            if (i < m)
            {
                if (j < n)
                {
                    if (p1[i].X < p2[j].X)
                        ans.pb(p1[i++]);
                    else if (p1[i].X > p2[j].X)
                        ans.pb(p2[j++]);
                    else
                    {
                        ans.eb(p1[i].X, p1[i].Y + p2[j].Y);
                        ++i; ++j;
                    }
                }
                else
                    ans.pb(p1[i++]);
            }
            else
                ans.pb(p2[j++]);
        }
        return ans;
    }
};

id19 fac(2000000);

id19 fac(id20);

ul id52(const ul& a, const ul& b, const ul& M, const int& helper)
{
    if (M == 0)
        return 0;
    ul q = ((ld)a) * b / M;
    ul a1 = a * b - q * M;
    ul a2 = a1;
    int rm = M % helper;
    int ra = a % helper;
    int rb = b % helper;
    int rq = q % helper;
    int r1 = raz(prod(ra, rb, helper), prod(rq, rm, helper), helper);
    int r2 = r1;
    while (true)
    {
        if (a1 % helper == r1 && a1 < M)
            return a1;
        a1 -= M;
        r1 = raz(r1, rm, helper);

        a2 += M;
        r2 = sum(r2, rm, helper);
        if (a2 % helper == r2 && a2 < M)
            return a2;
    }
}
inline int find_helper(const ul& M)
{
    int i = 30;
    while (M % fac.pr[i] == 0)
        ++i;
    return fac.pr[i];
}
ul prodll(const ul& a, const ul& b, const ul& M)
{
    if (M == 0)
        return 0;
    ul helper = find_helper(M);
    return id52(a, b, M, helper);
}
ul sumll(const ul& a, const ul& b, const ul& M)
{
    if (a < M - b)
        return a + b;
    else
        return a + b - M;
}
ul razll(const ul& a, const ul& b, const ul& M)
{
    if (a >= b)
        return a - b;
    else
        return a + M - b;
}
template<typename T>
T diff(const T& a, const T& b) {
    return (a > b) ? (a - b) : (b - a);
}


template<typename A>
bool id35(const pair<A, A>& a, const pair<A, A>& b)
{
    A p;
    if (p = a % b)
        return (p > 0);
    else
        return sq_len(a) < sq_len(b);
}
template<typename T>
int id34(const vector<T>& v)
{
    int ans = 0, n = sz(v);
    for (int i = 1; i < n; ++i)
        if (v[i] < v[ans])
            ans = i;
    return ans;
}


template<typename T>
vi id48(vector<pair<T, T>>& a)
{
    int n = sz(a);
    if (n)
    {
        int mt = id34(a);
        pair<T, T> d = a[mt];
        for (int i = 0; i < n; ++i)
            a[i] -= d;

        vi idx(n);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return id35(a[l], a[r]); });

        vi h(1, idx.front());
        for (auto it = idx.begin() + 1; it != idx.end(); ++it)
        {
            auto temp = a.begin() + *it;
            if (sz(h) >= 2)
            {
                if (are_parallel(a[h.back()], *temp))
                    h.pop_back();
                while ((sz(h) >= 3) && npocs(a[h[sz(h) - 2]], a[h.back()], *temp))
                    h.pop_back();
            }
            h.push_back(*it);
        }

        for (int i = 0; i < n; ++i)
            a[i] += d;
        return h;
    }
    else
        return vi();
}
pii id31(const int& a, const int& b)
{
    if (b)
    {
        int c = a / b;
        pii ans1 = id31(b, a - b * c);
        return pll(ans1.Y, ans1.X - ans1.Y * c);
    }
    else
        return pii(1, 0);
}
pll id14(const ll& a, const ll& b)
{
    if (b)
    {
        ll c = a / b;
        pll ans1 = id14(b, a - b * c);
        return pll(ans1.Y, ans1.X - ans1.Y * c);
    }
    else
        return pll(1ll, 0ll);
}
template<typename T>
T gcd(T a, T b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}


ll pr_p(const ll& a, const ll& b, const ll& p)
{
    if (b < 1000000)
        return (a * b) % p;
    ll temp = pr_p(a, b >> 1ll, p);
    temp = sumll(temp, temp, p);
    if (b & 1ll)
        return sumll(temp, a, p);
    else
        return temp;
}
ll po_p(const ll& a, const ll& b, const ll& p)
{
    if (b < 2)
    {
        if (b == 0)
            return 1;
        else
            return a;
    }
    ll temp = po_p(a, b >> 1ll, p);
    temp = pr_p(temp, temp, p);
    if (b & 1ll)
        return pr_p(temp, a, p);
    else
        return temp;
}
int pow_mod(const int& a, const int& b, const int& p)
{
    if (b < 2)
    {
        if (b == 0)
            return 1;
        else
            return a;
    }
    int temp = pow_mod(a, b >> 1, p);
    temp = prod(temp, temp, p);
    if (b & 1)
        return prod(temp, a, p);
    else
        return temp;
}
ll id5(const ll& a, const ll& b, const ll& p)
{
    if (b < 2)
    {
        if (b == 0)
            return 1;
        else
            return a;
    }
    ll temp = id5(a, b >> 1ll, p);
    temp = prodll(temp, temp, p);
    if (b & 1ll)
        return prodll(temp, a, p);
    else
        return temp;
}
int inverse(int a, int n)
{
    int c = id31(a, n).X;
    if (c < 0)
        c += n;
    return c;
}
ll id10(ll a, ll n)
{
    ll c = id14(a, n).X;
    if (c < 0)
        c += n;
    return c;
}
template<typename A>
pii equal_elements(const vector<A>& u, const vector<A>& v)
{
    pii ans(INT_MAX, INT_MAX);
    int m = sz(u), n = sz(v);
    vi id_u(m);
    for (int i = 1; i < m; ++i)
        id_u[i] = i;
    vi id_v(n);
    for (int i = 1; i < n; ++i)
        id_v[i] = i;
    sort(id_u.begin(), id_u.end(), [&](const int& x, const int& y) {return u[x] < u[y]; });
    sort(id_v.begin(), id_v.end(), [&](const int& x, const int& y) {return v[x] < v[y]; });
    int i = 0; int j = 0;
    while ((i < m) && (j < n))
    {
        if (u[id_u[i]] < v[id_v[j]])
            ++i;
        else if (v[id_v[j]] < u[id_u[i]])
            ++j;
        else
        {
            ans = min(ans, pii(id_v[j], id_u[i]));
            ++j;
        }
    }
    if (ans.X == INT_MAX)
        return pii(-1, -1);
    else
        return pii(ans.Y, ans.X);
}
ll id30(ll a, ll b, ll n)
{
    int k = ((int)(sqrt((long double)n)));
    ll a1 = id10(a, n);
    int l = k + 20;
    ll a2 = po_p(a1, k, n);
    vl seq1(k), seq2(l);
    seq1.front() = 1;
    for (int i = 1; i < k; ++i)
        seq1[i] = pr_p(seq1[i - 1], a, n);
    seq2.front() = b;
    for (int i = 1; i < l; ++i)
        seq2[i] = pr_p(seq2[i - 1], a2, n);
    pll e = equal_elements(seq1, seq2);
    if (e.X == -1)
        return -1;
    else
        return e.X + e.Y * k;
}
ll id55(ll a, ll b, ll n)
{
    const int C = 70;
    a %= n;
    b %= n;
    if (gcd(n, a) != 1)
    {
        for (int i = 0; i < C; ++i)
        {
            if (po_p(a, i, n) == b)
            {
                return i;
            }
        }
        ll multp = po_p(a, C, n);
        ll g = gcd(multp, n);
        if (b % g)
        {
            return -1;
        }
        else
        {
            b /= g;
            n /= g;
            multp /= g;
            ll ob = id10(multp, n);
            b = pr_p(b, ob, n);
            ll ans = id30(a, b, n);
            if (ans == -1)
                return -1;
            else
                return ans + C;
        }
    }
    else
        return id30(a, b, n);
}
const ul minimum_composites[] =
{
    1ull,
    2046ull,
    1373652ull,
    25326000ull,
    3215031750ull,
    2152302898746ull,
    3474749660382ull,
    341550071728320ull,
    341550071728320ull,
    3825123056546413050ull,
    3825123056546413050ull,
    18446744073709551615ull
};
const int little_primes[] =
{
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37
};
bool id22(const ul& n, const ul& prime, const ul& odd, const ul& pot, const ul& nmo)
{
    long long x = id5(prime, odd, n);
    if ((x == nmo) || (x == 1))
        return true;
    for (int i = 1; i < pot; ++i)
    {
        x = prodll(x, x, n);
        if (x == nmo)
            return true;
        if (x == 1)
            return false;
    }
    return false;
}
bool is_prime(const ul& n)
{
    if (n <= 2)
        return (n == 2);
    ul odd, pot, nmo;
    nmo = n - 1;
    odd = nmo;
    pot = 0;
    while ((odd & 1ll) == 0)
    {
        odd >>= 1ll;
        ++pot;
    }
    int i = 0;
    while (n > minimum_composites[i])
    {
        if (id22(n, little_primes[i], odd, pot, nmo) == false)
            return false;
        ++i;
    }
    return true;
}

vpui id19::pollardRho(const ul& n)
{
    if (is_prime(n))
        return vpui(1, pui(n, 1));
    int step = 1;
    while (true)
    {
        step <<= 1;
        ul a = rng();
        ul b = a;
        ul d = 1;
        for (int j = 0; j < step; ++j)
        {
            a = sumll(1, prodll(a, a, n), n);
            b = sumll(1, prodll(b, b, n), n);
            b = sumll(1, prodll(b, b, n), n);
            d = gcd(diff(a, b), n);
            if (d > 1) {
                break;
            }
        }
        if (1 < d && d < n)
            return merge(pollardRho(d), pollardRho(n / d));
    }
    return vpui();
}
vpui id19::factor(ul n)
{
    vpui ans;
    for (int i = 0; n >= N && i < sz(pr) && pr[i] < id20; ++i)
        while (n % pr[i] == 0)
        {
            if (sz(ans) && ans.back().X == pr[i])
                ++ans.back().Y;
            else
                ans.eb(pr[i], 1);
            n /= pr[i];
        }
    if (n < N)
    {
        known_factorization(n, ans);
        return ans;
    }
    else
        return merge(ans, pollardRho(n));
}
template<typename T>
T phi(const vector<pair<T, int>>& v)
{
    T ans = 1;
    for (int i = 0; i < sz(v); ++i)
    {
        ans *= v[i].X - 1;
        for (int j = 1; j < v[i].Y; ++j)
            ans *= v[i].X;
    }
    return ans;
}
ul phi(const ul& n)
{
    return phi(fac.factor(n));
}
bool id0(const int& ph, const vi& to_check, const int& r, const int& n)
{
    for (int i = 0; i < sz(to_check); ++i)
        if (pow_mod(r, to_check[i], n) == 1)
            return false;
    return (pow_mod(r, ph, n) == 1);
}
int primitive_root(const int& n)
{
    if (n < 3)
        return n - 1;
    int p = phi(n);
    vpui f = fac.factor(p);
    vi to_check(sz(f));
    for (int i = 0; i < sz(f); ++i)
        to_check[i] = p / f[i].X;
    for (int i = 2; i < n; ++i)
        if (id0(p, to_check, i, n))
            return i;
    return -1;
}
int id49(const int& a, const int& p, const int& b, const int& q)
{
    pii c = id31(p, q);
    int pr = p * q;
    int ans = ((a * c.Y * q + b * c.X * p) % pr + pr) % pr;
    return ans;
}
ll id1(const ll& a, const ll& p, const ll& b, const ll& q)
{
    pll c = id14(p, q);
    ll pr = p * q;
    ll ans = ((a * c.Y * q + b * c.X * p) % pr + pr) % pr;
    return ans;
}
pii power_v(int n, const int& p)
{
    int ans = 0;
    while (n % p == 0)
    {
        n /= p;
        ++ans;
    }
    return pii(ans, n);
}
int id16(int c, int n, const int& pr, const int& k)
{
    c %= n;
    if (c)
    {
        pii kek = power_v(c, pr);
        int l = kek.X;
        if (l & 1)
            return -1;
        if (l > 0)
        {
            int pwl = 1;
            for (int i = 0; i < l; ++i)
                pwl *= pr;
            n /= pwl;
            c /= pwl;
            int ans1 = id16(c, n, pr, k - l);
            if (ans1 == -1)
                return -1;
            for (int i = 0; i < (l >> 1); ++i)
                ans1 *= pr;
            return ans1;
        }
        else
        {
            int primitive;
            if (n & 1)
                primitive = primitive_root(n);
            else
                primitive = 5;
            int u = ((int)id30(primitive, c, n));
            if (u == -1)
                return -1;
            if (u & 1)
                return -1;
            return pow_mod(primitive, u >> 1, n);
        }
    }
    else
        return 0;
}
int id11(const int& c, const int& n)
{
    vpui f = fac.factor(n);
    int a = 0, p = 1;
    for (int i = 0; i < sz(f); ++i)
    {
        int q = 1;
        for (int j = 0; j < f[i].Y; ++j)
            q *= f[i].X;
        int b = id16(c, q, f[i].X, f[i].Y);
        if (b == -1)
            return -1;
        a = id49(a, p, b, q);
        p *= q;
    }
    return a;
}

namespace BGF
{
    inline int cntd(unsigned x)
    {
        int ans = 0;
        while (x)
        {
            if (x & 1)
                ++ans;
            x >>= 1;
        }
        return ans;
    }
    inline ll cntdll(ul x)
    {
        ll ans = 0;
        while (x)
        {
            if (x & 1)
                ++ans;
            x >>= 1;
        }
        return ans;
    }
    inline int clzd(unsigned x)
    {
        int ans = 32;
        while (x)
        {
            --ans;
            x >>= 1;
        }
        return ans;
    }
    inline ll id12(ul x)
    {
        ll ans = 64;
        while (x)
        {
            --ans;
            x >>= 1;
        }
        return ans;
    }
    inline int ctzd(unsigned x)
    {
        if (x == 0)
            return 32;
        int ans = 0;
        while ((x & 1) == 0)
        {
            ++ans;
            x >>= 1;
        }
        return ans;
    }
    inline ll id26(ul x)
    {
        if (x == 0)
            return 64;
        ll ans = 0;
        while ((x & 1) == 0)
        {
            ++ans;
            x >>= 1;
        }
        return ans;
    }
}


namespace BGF 

{
    const unsigned BHC = 65535u;
    const ul BHCL = 65535ull;
    const unsigned BHN = 65536u;
    const unsigned BHL = 16u;
    const unsigned LH = 4294901760u;
    const unsigned RH = 65535u;
    const ul id7 = 16ull;
    const ul id56 = 32ull;
    const ul id27 = 48ull;
    const ul LHL = 18446744069414584320ull;
    const ul RHL = 4294967295ull;
    int CNT[BHN];
    int CLZ[BHN];
    int CTZ[BHN];
    inline void initialize()
    {
        CNT[0] = 0;
        CLZ[0] = BHL + BHL;
        CTZ[0] = BHL;
        for (unsigned i = 1; i < BHN; ++i)
        {
            CNT[i] = cntd(i);
            CLZ[i] = clzd(i);
            CTZ[i] = ctzd(i);
        }
    }
    inline int cntc(const unsigned& x)
    {
        return CNT[x & BHC] + CNT[(x >> BHL) & BHC];
    }
    inline ll id36(const ul& x)
    {
        return CNT[x & BHCL] + CNT[(x >> id7) & BHCL] + CNT[(x >> id56) & BHCL] + CNT[(x >> id27) & BHCL];
    }
    inline int clzc(const unsigned& x)
    {
        if (x & LH)
            return CLZ[x >> BHL] - BHL;
        else
            return CLZ[x];
    }
    inline ll id54(const ul& x)
    {
        if (x & LHL)
            return clzc(x >> id56);
        else
            return clzc(x) + id56;
    }
    inline int ctzc(const unsigned& x)
    {
        if (x & RH)
            return CTZ[x & RH];
        else
            return CTZ[x >> BHL] + BHL;
    }
    inline ll id37(const ul& x)
    {
        if (x & RHL)
            return ctzc(x);
        else
            return ctzc(x >> id56) + id56;
    }
}




















const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";
int sum(const int a, const int b)
{
    return min(1 + (int)1e9, a + b);
}
struct st
{
    int n;
    vi mn;
    vi mx;
    vi s;
    vi p;
    st(const vi& a) : n(sz(a))
    {
        p.resize(n * 4);
        mn.resize(n * 4);
        mx.resize(n * 4);
        s.resize(n * 4);
        construct(0, 0, n, a);
    }
    void construct(const int v, const int vx, const int vy, const vi& a)
    {
        if (vy - vx == 1)
        {
            mn[v] = a[vx];
            mx[v] = a[vx];
            s[v] = a[vx];
        }
        else
        {
            int vz = (vx + vy) / 2;
            construct(v * 2 + 1, vx, vz, a);
            construct(v * 2 + 2, vz, vy, a);
            s[v] = sum(s[2 * v + 1], s[2 * v + 2]);
            mn[v] = mn[2 * v + 2];
            mx[v] = mx[2 * v + 1];
        }
    }
    pii eat(const int v, const int vx, const int vy, const int x, int y)
    {
        push(v, vx, vy);
        if (x >= vy || y < mn[v])
            return pii(0, 0);
        if (x <= vx && y >= s[v])
            return pii(s[v], vy - vx);
        int vz = (vx + vy) / 2;
        pii e = eat(2 * v + 1, vx, vz, x, y);
        y -= e.X;
        e += eat(2 * v + 2, vz, vy, x, y);
        return e;
    }
    int eat(const int x, const int y)
    {
        return eat(0, 0, n, x, y).Y;
    }
    void push(const int v, const int vx, const int vy)
    {
        if (p[v])
        {
            mn[v] = p[v];
            mx[v] = p[v];
            s[v] = min(1 + (ll)1e9, (ll)p[v] * (vy - vx));
            if (2 * v + 2 < sz(p))
            {
                p[2 * v + 1] = p[v];
                p[2 * v + 2] = p[v];
            }
            p[v] = 0;
        }
    }
    void up(const int v, const int vx, const int vy, const int x, const int y)
    {
        push(v, vx, vy);
        if (x <= vx || mn[v] >= y)
            return;
        if (x >= vy && mx[v] <= y)
        {
            p[v] = y;
            return;
        }
        int vz = (vx + vy) / 2;
        up(2 * v + 1, vx, vz, x, y);
        up(2 * v + 2, vz, vy, x, y);
        push(2 * v + 1, vx, vz);
        push(2 * v + 2, vz, vy);
        s[v] = sum(s[2 * v + 1], s[2 * v + 2]);
        mn[v] = mn[2 * v + 2];
        mx[v] = mx[2 * v + 1];
    }
    void up(const int x, const int y)
    {
        up(0, 0, n, x, y);
    }
};


constexpr ll inf=2223372036854775807;
constexpr int mod1=(1e9+7);
constexpr int mod2=(998244353);
constexpr int MAX=(1e5+3);
constexpr int MOD=1e9+7; 
struct mint
{
  public:
    int v;
    mint(int _v=0):v(_v){}
    explicit operator int() const {return v;}
    mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
    mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
    mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}
    friend mint operator + (mint a, const mint& b) {return a+=b;}
    friend mint operator - (mint a, const mint& b) {return a-=b;}
    friend mint operator * (mint a, const mint& b) {return a*=b;}
    friend mint pow(mint b, ll p)
    { mint f(1); for(;p;p>>=1, b*=b) if(p&1) f*=b; return f; }
};
template<typename T, typename... Args>
void addV(vector<T>& v, Args&&... args)
{
    (v.eb(forward<Args>(args)), ...);
}
template <typename L>
inline void print(L x, char end=0){  if(abs(x)>1000000000000000){ cout<<x; return; }  if(x<0) writeChar('-'), x=-x; int n=0;
do buf_num[n++]=x%10+'0'; while(x/=10); while (n--) writeChar(buf_num[n]); if(end) writeChar(end);}
struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out,1,buf_pos,stdout),buf_pos=0;}}flusher;
template<typename H,typename... T> void print(H h, T... t) { print(h); F1; print(t...); }
template<typename T> void print(vector<T>v){ for(auto i:v){ print(i); F1; } }
template<typename T> void print(set<T>v){ for(auto i:v){ print(i); F1; } }
template<typename R> void input(vector<R>&a,int n){ rep(i,0,n-1) rd(a[i]); }
template<typename T,typename V> T ce(T a,V b){ if(a<0) return a/b; T res;if(a%b==0)res=a/b; else res=a/b+1; return res; }
template<typename W,typename F> W fl(W a,F b){ if(abs(a)%abs(b)==0) return a/b; if(a<0) return a/b-1; return a/b; }
ll id24(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod2; b>>=1;a=(a*2)%mod2; } return res; }
ll id25(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod1; b>>=1;a=(a*2)%mod1; } return res; }
ll multiply(ll a,ll b){ ll res=0; while(b) { if(b&1) res+=a; b>>=1;a=(a<<1); } return res; }
ll id4(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod2; a=(a*a)%mod2; b>>=1; } return res; }
ll id15(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod1; a=(a*a)%mod1; b>>=1; } return res; }
ll power(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a); a=(a*a); b>>=1; } return res; }
ll fact[MAX+7];
void facto(){ fact[0]=1; fact[1]=1; rep(i,2,MAX-1) fact[i]=(fact[i-1]*i)%mod1; }
ll modInv(int n){ return id15(n,mod1-2); }
ll ncr(int n,int r){ if (r==0) return 1; return (fact[n]*modInv(fact[r])%mod1*modInv(fact[n-r])%mod1)%mod1; }
template<typename T,typename V>
int id32(T n,V a){ T res=1; int p=-1; while(n%res==0){ p++; res*=a; } return p; }
template<typename T,typename V> T id13(T n,V p){ T x=0; while(n){ n/=p; x+=n; } return x; }
template<typename L>void factorise(L a,vector<L>&f){ int limit=sqrt(a); rep(i,1,limit) { if(a%i==0) { f.push_back(i); if(i!=a/i) f.push_back(a/i); } } }
vector<int>prime; 
void sieve(int limit){prime.eb(2);prime.eb(3);bool sieve[limit];for(int i=0;i<limit;i++)sieve[i]=false; 
for(int x=1; x*x<limit;x++) 
{ 
    for(int y=1;y*y<limit;y++){int n=(4*x*x)+(y*y);
    if(n<=limit&&(n%12==1||n%12==5)){sieve[n]^=true;}n=(3*x*x)+(y*y);if(n<=limit&&n%12==7){ sieve[n]^=true; }
    n=(3*x*x)-(y*y);if(x>y&&n<=limit&&n%12==11){sieve[n]^=true;} } } 
    for(int r=5;r*r<limit;r++){ if(sieve[r]) { for(int i=r*r;i<limit;i+=r*r) sieve[i]=false; } } 
    for(int a=5;a<limit;a++) { if(sieve[a]) prime.eb(a); }
} 
void dfs(int s,vector<vector<int>>v,vector<int>f)
{
    stack<int>q; q.push(s); while(!q.empty()){ int m=q.top(); q.pop(); f[m]=1; 
    for(auto i=v[m].begin();i!=v[m].end();++i){ if(!f[*i]) { q.push(*i); f[*i]=1; } } }
}
void bfs(int s,vector<vector<int>>v,vector<int>f)
{
    queue<int>q; q.push(s); f[s]=1; while(!q.empty()) { int m=q.front(); q.pop();
    for(auto i=v[m].begin();i!=v[m].end();++i){ if(!f[*i]) { f[*i]=1; q.push(*i); } } }
}
template<typename G>void primeFactors(G n,vector<G>&pf){if(n%2==0) pf.eb(2); while(n%2==0)n=n/2;
int limit=sqrt(n);for(int i=3;i<=limit;i=i+2){ if(n%i==0) pf.eb(i); while(n%i==0) n=n/i;}if(n>2) pf.eb(n);}  
template<typename T> int id21(T n){repr(i,60,0) { if(bit(n,i)) return i; } }
vector<int> divisor[MAX+7];void sieve(){ rep(i,1,MAX){ for(int j=i;j<=MAX;j+=i) divisor[j].eb(i); } }
template <typename T> bool id42 (T x) { return x&&(!(x&(x-1))); }
template <typename T> bool isPrime(T n){ if(n<=1) return false; if(n<=3) return true; 
if(n%2==0||n%3==0) {return false;} for(int i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) {return false;} return true; }
void id6(string str,vector<int>&Z)
{
    int n=str.length(),L,R,k; L=R=0;
    for(int i=1;i<n;++i){ if(i>R){ L=R=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;}
    else{ k=i-L; if(Z[k]<R-i+1) Z[i]=Z[k]; else{L=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;} } }
}
void zfunc(string text,string pattern,vector<int>&index)
{
    string concat=pattern+"$"+text; int l=concat.length(); vector<int>Z(l); id6(concat,Z);
    rep(i,0,l-1){ if(Z[i]==(int)pattern.length()) index.eb(i-pattern.length()-1); }
}
template<typename A,typename B> B id50(A n,B a){ A res=1; B p=-1; while(n>res){ res*=a; p++; } return p; } 
template<typename A,typename B> B id41(A n,B a){ A res=1; B p=-1; while(n>=res){ res*=a; p++; } return p; } 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id17=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+id17);
    }
};
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
struct vectorHash {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
int spf[MAX];
void spf_compute(){
    for (int i = 2; i < MAX; i += 2) spf[i]=2;
    for (ll i = 3;i<MAX;i+=2){
        if (!spf[i]){
            spf[i]=i;
            for(ll j=i;(j*i)<MAX;j+=2){ spf[j*i] = i; }
        }
    }
}
vector<int>getPF(int k)
{ 
    vector<int>ans; um<int,int,custom_hash>g; 
    while(k>1)
    {   
        if(!g[spf[k]])
        ans.eb(spf[k]); g[spf[k]]=1; 
        k/=spf[k];
    }
    return ans;
} 
template<typename T>ll sumy(vector<T>&v){ ll s=0; for(auto i:v)s+=i; return s; }
template<typename T>T max_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=max(m,v[i]); } return m; }
template<typename T>T min_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=min(m,v[i]); } return m; }
template<typename T>int id3(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(m<v[i]){ m=v[i]; ind=i;} } } return ind; }
template<typename T>int id47(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(v[i]<m){ m=v[i]; ind=i; }} } return ind; }
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
void solve()
{
   int n,k; rd(n,k); 
   string s; cin>>s; 
   if(n%k!=0){  print(-1); F2; return; }
   vector<vector<int>>cnt(27,vector<int>(n+1,0)); 
   for(int i=1;i<=26;i++)
   {
    for(int j=0;j<=n-1;j++)
    {
        int c=s[j]-96; 
        if(j)
        cnt[i][j]=cnt[i][j-1];
        if(c==i) cnt[i][j]++;   
    }
   }
   int flag=1; 
   for(int i=1;i<=26;i++)
   {
    if(cnt[i][n-1]%k!=0)
    {
        flag=0; break; 
    }
   }
   if(flag)
   {
    cout<<s<<"\n"; return; 
   }
   string ans=""; 
   string t=s; t.pop_back();  
   for(int i=n-1;i>=0;i--)
   {
     char c=s[i]+1; int rem=(n-i-1); 
     for(char c1=c;c1<='z';c1++)
     {
         

        vector<int>req(27,0); 
        for(int j=1;j<=26;j++)
        {
            int occ=cnt[j][i]; char d=j+96; 
            if(d==c1) occ++; 
            else if(d==s[i]) occ--; 
            req[j]=(k-occ%k)%k; 
        }
        int sum=accumulate(all(req),0); 
        if(sum>rem) continue; 
        t=(i>0)?s.substr(0,i):""; t+=c1;
        assert((rem-sum)%k==0);  
        req[1]+=rem-sum; 
        sum=rem; 
        for(int j=1;j<=26;j++)
        {
            for(int z=1;z<=req[j];z++){ char d=j+96; t+=d; } 
        }
        cout<<t<<"\n"; return; 
     }
   }
    cout<<ans<<"\n"; return; 
}
int main() 
{
  FastIO::Reader cin; FastIO::Writer cout; cout.setprecision(9);
  
  clock_t start=clock();
  
    
    if(fopen("input.txt","r"))
    {
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       cerr<<("///////////////////////////////////////////Error Stream//////////////////////////////////////////")<<"\n"; 
    }
  
  int t=1,c=1; rd(t); 
  while(t--)
  { 
    
    pc('T');pc('e');pc('s');pc('t');pc('c');pc('a'); pc('s'); pc('e'); pc(' ');
    pc('
    
    solve(); c++; 
  }
  
  clock_t end=clock();
  double time_taken=double(end-start)/double(CLOCKS_PER_SEC); 
  cout<<"Time taken: "<<time_taken; 
  cout<<" sec \n"; 
  
  return 0;
}     
