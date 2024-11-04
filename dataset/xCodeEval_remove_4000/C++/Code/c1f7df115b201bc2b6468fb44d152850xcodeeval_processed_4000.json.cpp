
using namespace std;












using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}





template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;template<class...Ts>using pq=priority_queue<Ts...>;
template<class T>using minpq=pq<T,vector<T>,greater<T>>;template<class T>using maxpq=pq<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id3(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id3(long){return false;}constexpr static bool value=id3<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id1=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[id1],_tempOutputBuf[id1],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id5=0,_cnt;ull _precisionBase=1000000;














void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}























void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
template<class T1,class T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>void write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(forward<Ts>(xs)...);}
template<class T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>id4=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

class id6: public runtime_error {
public:
    id6(): runtime_error("No such element exists"){}
    id6(string message): runtime_error(message){}
};

template <class Value, class Comparator = less<Value>>
struct id7 {
    Comparator cmp; int n, id0; vector<vector<Value>> a; vector<int> prefixSZ;
    pair<int, int> ceiling_ind(const Value val) const {
        int lo = 0, hi = (int) a.size(), mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(a[mid].back(), val)) lo = mid + 1;
            else hi = mid;
        }
        if (lo == (int) a.size()) return {(int) a.size(), 0};
        int i = lo; lo = 0, hi = (int) a[i].size();
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(a[i][mid], val)) lo = mid + 1;
            else hi = mid;
        }
        return {i, lo};
    }
    pair<int, int> floor_ind(const Value val) const {
        int lo = 0, hi = ((int) a.size()) - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(val, a[mid].front())) hi = mid - 1;
            else lo = mid + 1;
        }
        if (hi == -1) return {-1, 0};
        int i = hi; lo = 0, hi = ((int) a[i].size()) - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(val, a[i][mid])) hi = mid - 1;
            else lo = mid + 1;
        }
        return {i, hi};
    }

    pair<int, int> above_ind(const Value val) const {
        int lo = 0, hi = (int) a.size(), mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(val, a[mid].back())) hi = mid;
            else lo = mid + 1;
        }
        if (lo == (int) a.size()) return {(int) a.size(), 0};
        int i = lo; lo = 0, hi = (int) a[i].size();
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(val, a[i][mid])) hi = mid;
            else lo = mid + 1;
        }
        return {i, lo};
    }
    pair<int, int> below_ind(const Value val) const {
        int lo = 0, hi = ((int) a.size()) - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(a[mid].front(), val)) lo = mid + 1;
            else hi = mid - 1;
        }
        if (hi == -1) return {-1, 0};
        int i = hi; lo = 0, hi = ((int) a[i].size()) - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (cmp(a[i][mid], val)) lo = mid + 1;
            else hi = mid - 1;
        }
        return {i, hi};
    }
    id7(const int id0 = 1) : n(0), id0(id0) {}
    template <typename It> id7(const It st, const It en, const int id0 = 1) :
            n(en - st), id0(id0) {
        assert(n >= 0); assert(is_sorted(st, en, cmp));
        int id2 = (int) sqrt(n) * id0;
        for (It i = st; i < en; i += id2) {
            a.emplace_back(i, min(i + id2, en));
            prefixSZ.push_back(0);
        }
        for (int i = 1; i < (int) a.size(); i++) prefixSZ[i] = prefixSZ[i - 1] + (int) a[i - 1].size();
    }
    id7(initializer_list<Value> il, const int id0 = 1) :
            n(il.end() - il.begin()), id0(id0) {
        assert(n >= 0); assert(is_sorted(il.begin(), il.end(), cmp));
        int id2 = (int) sqrt(n) * id0;
        for (auto i = il.begin(); i < il.end(); i += id2) {
            a.emplace_back(i, min(i + id2, il.end()));
            prefixSZ.push_back(0);
        }
        for (int i = 1; i < (int) a.size(); i++) prefixSZ[i] = prefixSZ[i - 1] + (int) a[i - 1].size();
    }
    void insert(const Value val) {
        pair<int, int> i = above_ind(val);
        if (n++ == 0) { a.emplace_back(); prefixSZ.push_back(0); }
        if (i.first == (int) a.size()) a[--i.first].push_back(val);
        else a[i.first].insert(a[i.first].begin() + i.second, val);
        int id2 = (int) sqrt(n) * id0;
        if ((int) a[i.first].size() > 2 * id2) {
            a.emplace(a.begin() + i.first + 1, a[i.first].begin() + id2, a[i.first].end());
            a[i.first].resize(id2);
            prefixSZ.push_back(0);
        }
        for (int j = i.first + 1; j < (int) a.size(); j++) prefixSZ[j] = prefixSZ[j - 1] + (int) a[j - 1].size();
    }
    bool erase(const Value val) {
        pair<int, int> i = ceiling_ind(val);
        if (i.first == (int) a.size() || a[i.first][i.second] != val) return false;
        --n; a[i.first].erase(a[i.first].begin() + i.second);
        if (a[i.first].empty()) { a.erase(a.begin() + i.first); prefixSZ.pop_back(); }
        for (int j = i.first + 1; j < (int) a.size(); j++) prefixSZ[j] = prefixSZ[j - 1] + (int) a[j - 1].size();
        return true;
    }
    void pop_front() {
        assert(n > 0); --n; a.front().erase(a.front().begin());
        if (a.front().empty()) { a.erase(a.begin()); prefixSZ.pop_back(); }
        for (int i = 1; i < (int) a.size(); i++) prefixSZ[i] = prefixSZ[i - 1] + (int) a[i - 1].size();
    }
    void pop_back() {
        assert(n > 0); --n; a.back().pop_back();
        if (a.back().empty()) { a.pop_back(); prefixSZ.pop_back(); }
    }
    const Value &at(const int k) const {
        assert(0 <= k && k < n); int lo = 0, hi = ((int) a.size()) - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (k < prefixSZ[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return a[hi][k - prefixSZ[hi]];
    }
    const Value &operator [](const int k) const { return at(k); }
    const Value &front() const { assert(n > 0); return a.front().front(); }
    const Value &back() const { assert(n > 0); return a.back().back(); }
    bool empty() const { return n == 0; }
    int size() const { return n; }
    bool contains(const Value val) const {
        pair<int, int> i = ceiling_ind(val);
        return i.first != (int) a.size() && a[i.first][i.second] == val;
    }
    pair<int, Value> floor(const Value val) const {
        pair<int, int> i = floor_ind(val);
        if (i.first == -1) throw id6("call to floor() resulted in no such value");
        return {prefixSZ[i.first] + i.second, a[i.first][i.second]};
    }
    pair<int, Value> ceiling(const Value val) const {
        pair<int, int> i = ceiling_ind(val);
        if (i.first == (int) a.size()) throw id6("call to ceiling() resulted in no such value");
        return {prefixSZ[i.first] + i.second, a[i.first][i.second]};
    }
    pair<int, Value> above(const Value val) const {
        pair<int, int> i = above_ind(val);
        if (i.first == (int) a.size()) throw id6("call to above() resulted in no such value");
        return {prefixSZ[i.first] + i.second, a[i.first][i.second]};
    }
    pair<int, Value> below(const Value val) const {
        pair<int, int> i = below_ind(val);
        if (i.first == -1) throw id6("call to below() resulted in no such value");
        return {prefixSZ[i.first] + i.second, a[i.first][i.second]};
    }
    vector<Value> values() const {
        vector<Value> ret;
        for (auto &&ai : a) for (auto &&aij : ai) ret.push_back(aij);
        return ret;
    }
};

template <const int MAXN, const int MAXM, class T> struct FenwickTree2D {
    id7<T> BIT[MAXM];
    void add(int x, int y) {
        for (int i = x; i < MAXN; i += i & -i) BIT[i].insert(y);
    }
    void rem(int x, int y) {
        for (int i = x; i < MAXN; i += i & -i) BIT[i].erase(y);
    }
    T rsq(int x, int y) {
        T ret = 0;
        for (int i = x; i > 0; i -= i & -i) {
            try {
                ret += BIT[i].above(y).first;
            } catch (id6 &e) {
                ret += BIT[i].size();
            }
        }
        return ret;
    }
    T rsq(int x1, int y1, int x2, int y2) {
        return rsq(x2, y2) + rsq(x1 - 1, y1 - 1) - rsq(x1 - 1, y2) - rsq(x2, y1 - 1);
    }
};

const int MAXNM = 2e5 + 5;

int N, M, A[MAXNM], B[MAXNM], ind[MAXNM];
FenwickTree2D<MAXNM, MAXNM, int> BIT;

int main() {
    

    

    

    read(N, M);
    read(A + 1, A + N + 1, B + 1, B + N + 1);
    For(i, 1, N + 1) ind[A[i]] = i;
    For(i, 1, N + 1) BIT.add(i, B[i] = ind[B[i]]);
    int t, a, b, c, d;
    FOR(i, M) {
        read(t);
        if (t == 1) {
            read(a, b, c, d);
            writeln(BIT.rsq(c, a, d, b));
        } else {
            read(a, b);
            BIT.rem(a, B[a]);
            BIT.rem(b, B[b]);
            swap(B[a], B[b]);
            BIT.add(a, B[a]);
            BIT.add(b, B[b]);
        }
    }
    return 0;
}
