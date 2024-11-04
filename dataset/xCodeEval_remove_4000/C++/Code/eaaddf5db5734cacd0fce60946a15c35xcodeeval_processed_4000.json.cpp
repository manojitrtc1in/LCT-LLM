









using namespace std;

















using namespace std;

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;




typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.X >> p.Y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.X << ' ' << p.Y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return (ui)(8*sizeof(int)-__builtin_clz(x)); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};

void fastIO(){ios::sync_with_stdio(false); }




template <typename ValueType, typename TagType,
    void (*combineTag)(TagType&, TagType),
    void (*applyTag)(ValueType&, TagType, ui),
    ValueType (*combineValues)(ValueType,ValueType)>
struct id10 {
    id10(const vector<ValueType> & data, const ValueType& _nullValue, const TagType& _nullTag)
        : n(1<<logceil(data.size())), nullValue(_nullValue), nullTag(_nullTag), T(2*n, {_nullValue, _nullTag}) {
        for (int i = 0; i < data.size(); ++i) T[n+i].X = data[i];
        for (ui i = n-1; i > 0; i--) T[i].X = combineValues(T[i<<1].X,T[i<<1|1].X);
    }

    id10(ui size, const ValueType& _nullValue, const TagType& _nullTag)
        : n(1<<logceil(size)), nullValue(_nullValue), nullTag(_nullTag), T(2*n, {_nullValue, _nullTag}) {
        for (ui i = n-1; i > 0; i--) T[i].X = combineValues(T[i<<1].X,T[i<<1|1].X);
    }

    inline void put(ui x, const TagType &v) { put(x, x, v); }
    inline void put(ui from, ui to, TagType v) { putInner(from, to, v, 1, n); }

    inline ValueType operator[](pair<ui,ui> x) { return get(x.X, x.Y); }
    inline ValueType operator[](ui x) { return get(x, x); }
    inline ValueType get(ui x) { return get(x, x); }
    inline ValueType get(ui from, ui to) { return getInner(from, to, 1, n); }

    void putInner(ui from, ui to, TagType v, ui i, ui s) {
        vector<int> Q;
        ui r = i;
        while (true) {
            if (from == 0 && to == s - 1) {
                applyTag(T[i].X, v, s);
                combineTag(T[i].Y, v);
                break;
            }
            pushTagDown(i, s);
            s >>= 1;
            i <<= 1;
            if (from & s) {
                from ^= s;
                to ^= s;
                i ^= 1;
            } else if (to & s) {
                putInner(0, to ^ s, v, i | 1, s);
                to = s - 1;
            }
        }

        while (i != r) {
            T[i >> 1].X = combineValues(T[i].X, T[i^1].X);
            i >>= 1;
        }
    }


    ValueType getInner(ui from, ui to, ui i, ui s) {
        while (true) {
            if (from == 0 && to == s-1) {
                return T[i].X;
            }
            pushTagDown(i, s);
            s >>= 1; i <<= 1;
            if (to & s) {
                to ^= s;
                if (from & s) {
                    from ^= s; i |= 1;
                } else {
                    auto a = getInner(from, s-1, i, s),
                        b = getInner(0, to, i|1, s);
                    return combineValues(a,b
                    );
                }
            }
        }
    }

    
    template <typename Pred> ui id5(ui x, Pred pred) {
        ValueType value = nullValue;
        return id11(x, 1, 0, n, value, pred);
    }

    template <typename Pred> ui id2(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].X, curValue);
        if (pred(nextValue)) { curValue = nextValue; return l; }
        if (l + 1 == r) return r;
        ui s = id2(i << 1 | 1, (l + r) / 2, r, curValue, pred);
        if (s == (l+r)/2) {
            return id2(i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            return s;
        }
    }

    template <typename Pred> ui id11(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x >= r-1) {
            return id2(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].X, curValue);
            if (pred(nextValue)) { curValue = nextValue; return l; }
            else return r;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x < m) {
            return id11(x, i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            ui s = id11(x, i << 1 | 1, (l + r) / 2, r, curValue, pred);
            if (s == (l + r) / 2) {
                return id2(i << 1, l, (l + r) / 2, curValue, pred);
            } else {
                return s;
            }
        }
    }

    
    template <typename Pred> ui id4(ui x, Pred pred) {
        ValueType value = nullValue;
        return id0(x, 1, 0, n, value, pred) - 1;
    }

    template <typename Pred> ui id8(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].X, curValue);
        if (pred(nextValue)) { curValue = nextValue; return r; }
        if (l + 1 == r) return l;
        ui s = id8(i << 1, l, (l + r) / 2, curValue, pred);
        return s == (l + r) / 2 ? id8(i << 1 | 1, (l + r) / 2, r, curValue, pred) : s;
    }

    template <typename Pred> ui id0(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x <= l) {
            return id8(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].X, curValue);
            if (pred(nextValue)) { curValue = nextValue; return r; }
            else return l;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x >= m) {
            return id0(x, i << 1 | 1, m, r, curValue, pred);
        } else {
            ui s = id0(x, i << 1, l, m, curValue, pred);
            return s == m ? id8(i << 1 | 1, m, r, curValue, pred) : s;
        }
    }

    void pushTagDown(ui i, ui s) {
        applyTag(T[i<<1].X, T[i].Y, s>>1);
        applyTag(T[i<<1|1].X, T[i].Y, s>>1);
        combineTag(T[i << 1].Y, T[i].Y);
        combineTag(T[i << 1 | 1].Y, T[i].Y);
        T[i].Y = nullTag;
    }

    ui n;
    ValueType nullValue;
    TagType nullTag;
    vector<pair<ValueType, TagType>> T;
};


template <typename F> void id14(F &a, F b) { a += b; }
template <typename F> void id9(F &a, F b, ui) { a += b; }
template <typename F> F id1(F a, F b) { return std::min(a, b); }
template <typename F> F id15(F a, F b) { return std::max(a, b); }
template <typename T> T id3(T a, T b) { return a + b; }
template <typename T> void id12(T &a, T b) { if (b != 0) a = b; }
template <typename T, T id16=0> void id7(T &a, T b, ui) { if (b != id16) a = b; }
template <typename T, T id16=0> void id13(T &a, T b, ui s) { if (b != id16) a = b*s; }


template<typename T> using LAddMaxTree = id10<T, T, id14<T>, id9<T>, id15<T>>;
template<typename T> using LAddMinTree = id10<T, T, id14<T>, id9<T>, id1<T>>;

template<typename T> using AssignSumTree = id10<T, T, id12<T>, id13<T>, id3<T>>;
template<typename T> using AssignMaxTree = id10<T, T, id12<T>, id7<T>, id15<T>>;






template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
    
    inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(Long x = 0) : v((ui)(x%N)) {}
    inline Field<N> pow(int p){return (*this)^p; }
    inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ui)((ull)v*o.v % N); return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
    inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
    inline explicit operator ui() const { return v; }
    inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
    inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

struct Ring {
    static int div(int p, int q, int N) {
        ll t=0,nt=1,r=N,nr=q;
        while(nr){ ll qq=r/nr;t-=qq*nt;r-=qq*nr;swap(t,nt);swap(r,nr); }
        t=(t<0)?t+N:t;
        r=(r<0)?r+N:r;
        if (gcd(p,N)%r) { return 0; }
        return (int)(((ll)t*(ll)p/r)%N);
    }
};



typedef Field<987655723> hash1;
hash1 p1 = 7;

typedef Field<987656927> hash2;
hash2 p2 = 13;


const int MAXN = 200200;

int st[MAXN];
int p[MAXN];
int f[MAXN];

string s;
string t;

hash1 h1[MAXN];
hash2 h2[MAXN];

void buildHash() {
    {
        auto cp = p1;
        h1[0] = t[0];
        FOR(i, 1, t.length()) {
            h1[i] = h1[i - 1] + t[i] * cp;
            cp *= p1;
        }
    }

    {
        auto cp = p2;
        h2[0] = t[0];
        FOR(i, 1, t.length()) {
            h2[i] = h2[i - 1] + t[i] * cp;
            cp *= p2;
        }
    }
}

pair<PII, int> getH(int l, int r) {
    if (l+f[l]-1 >= r)
        return {{-1, -1}, -1};

    int b = st[l + f[l]];
    int e = st[r - p[r]];

    auto len = e-b+1;















    auto hm1 = (h1[e] - h1[b - 1]) / p1.pow(b);
    if (p[r]%2 == 1) {
        ++len;
        hm1 += p1.pow(e - b + 1);
    }

    if (f[l]%2 == 1) {
        ++len;
        hm1 = 1 + hm1 * p1;
    }

    auto hm2 = (h2[e] - h2[b - 1]) / p2.pow(b);
    if (p[r]%2 == 1) {
        hm2 += p2.pow(e - b + 1);
    }

    if (f[l]%2 == 1) {
        hm2 = 1 + hm2 * p2;
    }


    return {{(ui)hm1, (ui)hm2}, len };
}


string id6(int l, int r) {
        if (l+f[l]-1 >= r)
            return {-1, -1};

        int b = st[l + f[l]];
        int e = st[r - p[r]];

        string ans = t.substr(b, e-b+1);
        if (p[r]%2 == 1)
            ans += '1';
        if (f[l]%2 == 1)
            ans = '1'+ans;
        return ans;
}
class DDostizhimieStroki {
public:
    void solve(std::istream& in, std::ostream& out) {
        fastIO();

        int n;
        in >> n >> s;
        n = s.size();


        s = '0'+ s + '0';

        REP(i, s.length()) {
            if (s[i] == '1' && s[i+1] == '1') {
                i ++;
                continue;
            }

            t += s[i];
            st[i] = t.length()-1;
        }


        p[0] = 0;
        if (s[0] == '1') {
            p[0] = 1;
        }

        FOR(i, 1, s.size()) {
            if (s[i] == '0')
                p[i] = 0;
            else
                p[i] = p[i-1]+1;
        }

        f[s.size()-1] = 0;

        RREP(i,s.size()-1) {
            if (s[i] == '0')
                f[i] = 0;
            else
                f[i] = f[i+1]+1;
        }

        buildHash();




























        int q;
        in >> q;

        REP(i, q) {
            int a,b,c;
            in >> a >> b >> c;

            if (getH(a, a+c-1) == getH(b, b+c-1)) {
                out << "Yes" << endl;
            } else {
                out << "No" << endl;
            }
        }
    }
};


int main() {
	DDostizhimieStroki solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}
