






















using namespace std;



typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double id6(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};








auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
using random_int = std::uniform_int_distribution<int>;
using random_ll = std::uniform_int_distribution<ll>;
struct TimeLimit {
    TimeLimit(double seconds) : s(seconds-0.2), last(clock()), mx(0) {}
    operator bool() const { clock_t cur = clock(); mx = max(mx, cur-last); last = cur; return clock() < s * CLOCKS_PER_SEC - 1.5 * mx; }
    double s; mutable clock_t last, mx;
};






template <typename ValueType, typename TagType,
          void (*combineTag)(TagType&, TagType),
          void (*applyTag)(ValueType&, TagType, ui),
          ValueType (*combineValues)(ValueType,ValueType)>
struct id10 {
    id10(const vector<ValueType> & data, const ValueType& nullValue, const TagType& nullTag)
            : n(1<<logceil(data.size())), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (int i = 0; i < data.size(); ++i) T[n+i].x = data[i];
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    id10(ui size, const ValueType& nullValue, const TagType& nullTag)
         : n(1<<logceil(size)), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    inline void put(ui x, const TagType &n) { put(x, x, n); }
    inline void put(ui from, ui to, TagType v) { putInner(from, to, v, 1, n); }

    inline ValueType operator[](pair<ui,ui> x) { return get(x.x, x.y); }
    inline ValueType operator[](ui x) { return get(x, x); }
    inline ValueType get(ui x) { return get(x, x); }
    inline ValueType get(ui from, ui to) { return getInner(from, to, 1, n); }

    void pushAllDown() {
        ui s = n, t = 1;
        while (s) {
            for (ui i = t; i < (t<<1); ++i) pushTagDown(i, s);
            s >>= 1;
            t <<= 1;
        }
    }

    inline ValueType rawGet(ui x) { return T[n+x].x; }

    void putInner(ui from, ui to, TagType v, ui i, ui s) {
        vector<int> Q;
        ui r = i;
        while (true) {
            if (from == 0 && to == s - 1) {
                applyTag(T[i].x, v, s);
                combineTag(T[i].y, v);
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
            T[i >> 1].x = combineValues(T[i].x, T[i^1].x);
            i >>= 1;
        }
    }


    ValueType getInner(ui from, ui to, ui i, ui s) {
        while (true) {
            if (from == 0 && to == s-1) {
                return T[i].x;
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
        ValueType nextValue = combineValues(T[i].x, curValue);
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
            ValueType nextValue = combineValues(T[i].x, curValue);
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
        ValueType nextValue = combineValues(T[i].x, curValue);
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
            ValueType nextValue = combineValues(T[i].x, curValue);
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
        applyTag(T[i<<1].x, T[i].y, s>>1);
        applyTag(T[i<<1|1].x, T[i].y, s>>1);
        combineTag(T[i << 1].y, T[i].y);
        combineTag(T[i << 1 | 1].y, T[i].y);
        T[i].y = nullTag;
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
template <typename T> void id12(T &a, T b) { if (b != 0) a = b; };
template <typename T> void id7(T &a, T b, ui) { if (b != 0) a = b; };
template <typename T> void id13(T &a, T b, ui s) { if (b != 0) a = b*s; };

template<typename T> using LAddMaxTree = id10<T, T, id14<T>, id9<T>, id15<T>>;
template<typename T> using LAddMinTree = id10<T, T, id14<T>, id9<T>, id1<T>>;

template<typename T> using AddSumTree = id10<T, T, id14<T>, id9<T>, id3<T>>;
template<typename T> using AssignSumTree = id10<T, T, id12<T>, id13<T>, id3<T>>;
template<typename T> using AssignMaxTree = id10<T, T, id12<T>, id7<T>, id15<T>>;


class DDreamoonLikesStrings {
public:

    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for (int t = 0; t < T; ++t) {
            string S; cin >> S;
            int N = S.size(), j = 0;
            vector<int> Same, C(26, 0), stack, Ones(N, 2);
            vector<pii> Solve;
            AssignSumTree<int> ASS(Ones, 0, 0);
            for (int i = 1; i < N; ++i) {
                if (S[i] == S[i-1]) {
                    Same.push_back(i);
                    C[S[i]-'a']++;
                }
            }

            auto add = [&](int a, int b){
                int x = a == 0 ? 0 : ASS.get(0, a-1);
                int y = ASS.get(0, b);
                Solve.push_back({x-a+1, y-b-1});
                ASS.put(a,b, 1);
            };

            int mx = *max_element(C.begin(),C.end());
            int sm = Same.size();
            while (true) {
                int X = stack.size();
                if (X >= 2 && S[stack[X-1]] != S[stack[X-2]]) {
                    C[S[stack[X - 1]]-'a']--;
                    C[S[stack[X - 2]]-'a']--;
                    int newMx = *max_element(C.begin(),C.end());
                    if (max(mx, (sm+1)/2) != max(newMx+1, (sm+1)/2)) {
                        C[S[stack[X - 1]] - 'a']++;
                        C[S[stack[X - 2]] - 'a']++;
                    } else {
                        add(stack[X-2], stack[X-1] - 1);
                        stack.pop_back(); stack.pop_back();
                        mx = newMx;
                        sm -= 2;
                        continue;
                    }
                }

                if (j != Same.size()) {
                    stack.push_back(Same[j++]);
                } else {
                    break;
                }
            }

            for (int i: stack) add(0, i-1);
            add(0, N-1);

            cout << Solve.size() << '\n';
            for (pii soln: Solve) cout << soln << '\n';
        }
    }
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	DDreamoonLikesStrings solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}

