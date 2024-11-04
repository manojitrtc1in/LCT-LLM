





















using namespace std;




typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double id10(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};






template <typename ValueType, typename TagType,
          void (*combineTag)(TagType&, TagType),
          void (*applyTag)(ValueType&, TagType, ui),
          ValueType (*combineValues)(ValueType,ValueType)>
struct id1 {
    id1(const vector<ValueType> & data, const ValueType& nullValue, const TagType& nullTag)
            : n(1<<logceil(data.size())), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (int i = 0; i < data.size(); ++i) T[n+i].x = data[i];
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    id1(ui size, const ValueType& nullValue, const TagType& nullTag)
         : n(1<<logceil(size)), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    inline void put(ui x, const TagType &n) { put(x, x, n); }
    inline void put(ui from, ui to, TagType v) { putInner(from, to, v, 1, n); }

    inline ValueType operator[](pair<ui,ui> x) { return get(x.x, x.y); }
    inline ValueType operator[](ui x) { return get(x, x); }
    inline ValueType get(ui x) { return get(x, x); }
    inline ValueType get(ui from, ui to) { return getInner(from, to, 1, n); }

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

    
    template <typename Pred> ui id9(ui x, Pred pred) {
        ValueType value = nullValue;
        return id5(x, 1, 0, n, value, pred);
    }

    template <typename Pred> ui id3(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].x, curValue);
        if (pred(nextValue)) { curValue = nextValue; return l; }
        if (l + 1 == r) return r;
        ui s = id3(i << 1 | 1, (l + r) / 2, r, curValue, pred);
        if (s == (l+r)/2) {
            return id3(i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            return s;
        }
    }

    template <typename Pred> ui id5(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x >= r-1) {
            return id3(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].x, curValue);
            if (pred(nextValue)) { curValue = nextValue; return l; }
            else return r;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x < m) {
            return id5(x, i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            ui s = id5(x, i << 1 | 1, (l + r) / 2, r, curValue, pred);
            if (s == (l + r) / 2) {
                return id3(i << 1, l, (l + r) / 2, curValue, pred);
            } else {
                return s;
            }
        }
    }

    
    template <typename Pred> ui id12(ui x, Pred pred) {
        ValueType value = nullValue;
        return id16(x, 1, 0, n, value, pred) - 1;
    }

    template <typename Pred> ui id13(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].x, curValue);
        if (pred(nextValue)) { curValue = nextValue; return r; }
        if (l + 1 == r) return l;
        ui s = id13(i << 1, l, (l + r) / 2, curValue, pred);
        return s == (l + r) / 2 ? id13(i << 1 | 1, (l + r) / 2, r, curValue, pred) : s;
    }

    template <typename Pred> ui id16(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x <= l) {
            return id13(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].x, curValue);
            if (pred(nextValue)) { curValue = nextValue; return r; }
            else return l;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x >= m) {
            return id16(x, i << 1 | 1, m, r, curValue, pred);
        } else {
            ui s = id16(x, i << 1, l, m, curValue, pred);
            return s == m ? id13(i << 1 | 1, m, r, curValue, pred) : s;
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
template <typename F> void id0(F &a, F b, ui) { a += b; }
template <typename F> F id2(F a, F b) { return std::min(a, b); }
template <typename F> F id15(F a, F b) { return std::max(a, b); }
template <typename T> T id4(T a, T b) { return a + b; }
template <typename T> void id6(T &a, T b) { if (b != 0) a = b; };
template <typename T> void id11(T &a, T b, ui) { if (b != 0) a = b; };
template <typename T> void id7(T &a, T b, ui s) { if (b != 0) a = b*s; };


template<typename T> using LAddMaxTree = id1<T, T, id14<T>, id0<T>, id15<T>>;
template<typename T> using LAddMinTree = id1<T, T, id14<T>, id0<T>, id2<T>>;

template<typename T> using AssignSumTree = id1<T, T, id6<T>, id7<T>, id4<T>>;
template<typename T> using AssignMaxTree = id1<T, T, id6<T>, id11<T>, id15<T>>;


void ApplyTag(long long &a,long long b, ui g) {
    a+=b*g;
}

void CombineTag(long long &a,long long b) {
    a+=b;
}

long long CombineValues(long long a, long long b) {
    return a+b;
}



signed main(){
    
    freopen("input.txt", "r", stdin);
    

    int n, q;
    cin >> n >> q;

    id1<ll, ll , CombineTag, ApplyTag, CombineValues> seg(n,(ll) 0,(ll) 0);

    set <pair <int, pair <int, int> > > a;
    for (int i=0; i<n; i++){
        a.insert({i, {i+1, 1}});
    }
    for (int qq=0; qq<q; qq++){
        int mode, l, r;
        cin >> mode >> l >>r;
       

        

        if (mode==1){
                l--; r--;
            int x;
            cin >> x;
         

            pair <int, pair <int, int> > v={l, {-1, -1}};
            auto tap=a.lower_bound(v);
            vc <pair <int, pair <int, int> > > to_insert;
            for(auto ta=a.lower_bound(v); ; ){
              

                auto tap=*ta;
                auto id8=ta;
                ta++;
                int ende=tap.f;
                int start=tap.f-tap.s.s+1;
                int col=tap.s.f;
                int dif=abs(x-col);


              


                if (start<l){
                    to_insert.push_back({l-1, {col,l-start}});
                    start=l;
                }
                if (ende>r){
                    to_insert.push_back({ende, {col,ende-r}});
                    ende=r;
                }
             

               

              

           

                seg.put(start, ende, dif);

                a.erase(id8);
               

                if(ende==r) break;
            }
            to_insert.push_back({r, {x, r-l+1}});
            for (int i=0; i<to_insert.size(); i++){
                a.insert(to_insert[i]);
            }
          
            
        }else{
            cout << seg.get(l-1, r-1) << "\n";
        }
    }
}

