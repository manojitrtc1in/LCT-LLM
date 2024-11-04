

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <array>
#include <bitset>
using namespace std;

#define x first
#define y second
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
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif


template<typename F>struct NoOp{void setup(ui, F){}void op(F&p,F n,ui,ui){p=n;}void down(F&,F&,F&,ui,ui) {}};

template<typename F,typename SetOp,typename PowerOp>struct Lazy{
    void setup(ui s,F def){this->def=def;this->s=s;L=new F[s]();fill(L,L+s,def);}
    void down(F&u,F&l,F&r,ui i,ui s){op(l,L[i],i<<1,s>>1);op(r,L[i],i<<1|1,s>>1);L[i]=def;}
    void op(F&p,F n,ui i,ui s){p=sop(p,pop(n,s));if(i<this->s)this->L[i]=sop(this->L[i],n);}
    SetOp sop;PowerOp pop;F*L;ui s;F def;
};

template <typename F, typename CombineOp, typename ModifyOp = NoOp<F>> struct SegTree {
	void setup(ui s, F def) {
		n = 1<<logceil(s);
		T = vector<F>(2*n, def);
		for (ui i = n-1; i > 0; i--) T[i] = cop(T[i<<1],T[i<<1|1]);
		mop.setup(2*n,def);
	}

	void setup(vector<F> & data, F def = F(), F def2 = F()) {
		n = 1<<logceil(data.size());
		T = vector<F>(2*n, def);
		copy(data.begin(), data.end(), T.begin() + n);
		for (ui i = n-1; i > 0; i--) T[i] = cop(T[i<<1],T[i<<1|1]);
		mop.setup(2*n,def2);
	}

	inline void put(ui x, F n) { put(x, x, n); }
	inline void put(ui from, ui to, F v) { put2(from, to+1, v, 1, n); }
	inline F get(ui x) { return get(x, x); }
	inline F get(ui from, ui to) { return get2(from, to+1, 1, n); }

	void put2(ui from, ui to, F v, ui i, ui s) {
		if (from == 0 && to == s) { mop.op(T[i], v, i, s); return; }
		mop.down(T[i], T[i<<1], T[i<<1|1], i, s);
        s>>=1;i<<=1;
        if (to <= s) { put2(from, to, v, i, s); }
        else if (from >= s) { put2(from-s, to-s, v, i|1, s); }
        else {
            put2(from, s, v, i, s);
            put2(0, to-s, v, i|1, s);
        }
		T[i>>1] = cop(T[i], T[i|1]);
	}

	F get2(ui from, ui to, ui i, ui s) {
        while (true) {
            if (from == 0 && to == s) return T[i];
            mop.down(T[i], T[i << 1], T[i << 1 | 1], i, s);
            s >>= 1;i <<= 1;
            if (to > s) {
                to -= s;
                if (from >= s) { from -= s; i|=1; }
                else return cop(get2(from, s, i, s), get2(0, to, i|1, s));
            }
        }
    }

	ui n;
	vector<F> T;
	CombineOp cop;
    ModifyOp mop;
};


template <typename F> struct AddOp { F operator()(F a, F b) { return a+b; }};
template <typename F> struct MinOp { F operator()(F a, F b) { return std::min(a,b); }};
template <typename F> struct MaxOp { F operator()(F a, F b) { return std::max(a,b); }};
template <typename F> struct MultiplyOp { F operator()(F a, F b) { return a*b; }};
template <typename F> struct MultOp { F operator()(F a, ui b) { return a*b; }};
template <typename F> struct IdempOp { F operator()(F a, ui b) { return a; }};
template <typename F> struct InverseOp { F operator()(F a, F b) { return b?b-a:a; }};

template<typename T> using AddSumTree = SegTree<T, AddOp<T>, Lazy<T, AddOp<T>, MultOp<T>>>;
template<typename T> using AddMaxTree = SegTree<T, MaxOp<T>, Lazy<T, AddOp<T>, IdempOp<T>>>;
template<typename T> using AddMinTree = SegTree<T, MinOp<T>, Lazy<T, AddOp<T>, IdempOp<T>>>;
template<typename T> using AssignMinTree = SegTree<T, MinOp<T>, Lazy<T, MinOp<T>, IdempOp<T>>>;
template<typename T> using AssignMaxTree = SegTree<T, MaxOp<T>, Lazy<T, MaxOp<T>, IdempOp<T>>>;
template<typename T> using XorTree = SegTree<T, AddOp<T>, Lazy<T, InverseOp<T>, MultOp<T>>>;

template<typename T> using SetMinTree = SegTree<T, MinOp<T>>;
template<typename T> using SetMaxTree = SegTree<T, MaxOp<T>>;
template<typename T> using SetMulTree = SegTree<T, MultiplyOp<T>>;

int MOD;

class RField {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline int pow(int a, ll p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%MOD;}e=((ull)e*e)%MOD;p>>=1;}return r;}
    


public:
    inline RField(int x = 0) : v(x) {}
    inline RField pow(int p){return (*this)^p; }
    inline RField operator^(ll p){return {pow(v,p)};}
    inline RField&operator+=(const RField&o) {checkMod(o);if ((ll)v+o.v >= MOD) v = (ll)v+o.v-MOD; else v = v+o.v; return *this; }
    inline RField&operator-=(const RField&o) {checkMod(o);if (v<o.v) v = MOD-o.v+v; else v=v-o.v; return *this; }
    inline RField&operator*=(const RField&o) {checkMod(o);v=ll(v)*o.v % MOD; return *this; }


    inline RField operator+(const RField&o) const {RField r{*this};return r+=o;}
    inline RField operator-(const RField&o) const {RField r{*this};return r-=o;}
    inline RField operator*(const RField&o) const {RField r{*this};return r*=o;}


    inline RField operator-() {if(v) return {MOD-v}; else return {0};};
    inline RField& operator++() { ++v; if (v==MOD) v=0; return *this; }
    inline RField operator++(int) { RField r{*this}; ++*this; return r; }
    inline RField& operator--() { --v; if (v==-1) v=MOD-1; return *this; }
    inline RField operator--(int) { RField r{*this}; --*this; return r; }
    inline bool operator==(const RField&o) const { return o.v==v; }
    inline bool operator!=(const RField&o) const { return o.v!=v; }
    inline explicit operator int() const { return v; }
    void checkMod(const RField&o) {}




private:
    int v;
};


ostream &operator<<(std::ostream&os,const RField&f){return os<<int(f);}
RField operator+(int i,const RField&f){return i+f;}
RField operator-(int i,const RField&f){return i-f;}
RField operator*(int i,const RField&f){return i*f;}
RField operator/(int i,const RField&f){return i/f;}


template <typename ValueType, typename TagType>
struct LSegTree {
    LSegTree(const vector<ValueType> & data, const ValueType& nullValue, const TagType& nullTag)
            : n(1<<logceil(data.size())), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (int i = 0; i < data.size(); ++i) T[n+i].x = data[i];
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    LSegTree(ui size, const ValueType& nullValue, const TagType& nullTag)
            : n(1<<logceil(size)), nullValue(nullValue), nullTag(nullTag), T(2*n, {nullValue, nullTag}) {
        for (ui i = n-1; i > 0; i--) T[i].x = combineValues(T[i<<1].x,T[i<<1|1].x);
    }

    inline void put(ui x, const TagType &n) { put(x, x, n); }
    inline void put(ui from, ui to, TagType v) { putInner(from, to, v, 1, n); }

    inline ValueType operator[](pair<ui,ui> x) { return get(x.x, x.y); }
    inline ValueType operator[](ui x) { return get(x, x); }
    inline ValueType get(ui x) { return get(x, x); }
    inline ValueType get(ui from, ui to) { return getInner(from, to, 1, n); }

    void directSet(ui x, const ValueType&v) {
        put(x, nullTag); 

        x += n;
        T[x].x = v;
        while (x != 1) {
            T[x/2].x = combineValues(T[x].x, T[x^1].x);
            x/=2;
        }
    }

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
            if (from == 0 && to == s-1) return T[i].x;
            pushTagDown(i, s);
            s >>= 1; i <<= 1;
            if (to & s) {
                to ^= s;
                if (from & s) {
                    from ^= s; i |= 1;
                } else {
                    return combineValues(
                            getInner(from, s-1, i, s),
                            getInner(0, to, i|1, s)
                    );
                }
            }
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

    void combineTag(TagType&a, TagType b) {
        a *= b;
    }

    void applyTag(ValueType& a, TagType t, ui) {
        a *= t;
    }

    ValueType combineValues(ValueType a, ValueType b) {
        return a + b;
    }
};

using MulTree = LSegTree<RField, RField>;

class ESashaAndAVeryEasyTest {
public:
    void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        cin >> MOD;
        int PHI = MOD;
        vector<int> F;
        int mm = MOD;
        for (int i = 2; i*i <= mm; ++i) {
            if (mm%i==0) {
                while (mm%i==0) mm/=i;
                PHI /= i;
                PHI *= i-1;
                F.push_back(i);
            }
        }
        if (mm!=1) {
            F.push_back(mm);
            PHI /= mm;
            PHI *= mm-1;
        }

        int FF = F.size();
        vector<int> A(N), B(N);
        cin >> A;
        vector2<int> Z(FF, N, 0);
        for (int i = 0; i < N; ++i) {
            int a = A[i];
            for (int j = 0; j < FF; ++j) {
                while (a%F[j]==0) {
                    Z[j][i]++;
                    a /= F[j];
                }
            }
            B[i] = a;
        }

        vector<AddMaxTree<int>> TS(FF);
        for (int i = 0; i < FF; ++i) TS[i].setup(Z[i], 0);

        vector<RField> AF(N), BF(N);
        for (int i = 0; i < N; ++i) AF[i] = RField(int(A[i]));
        for (int i = 0; i < N; ++i) BF[i] = RField(int(B[i]));
        MulTree TA{AF, 0, 1}, TB{BF, 0, 1};

        int Q; cin >> Q;
        for (int q = 0; q < Q; ++q) {
            int t; cin >> t;
            if (t == 1) {
                int l, r, x; cin >> l >> r >> x;
                --l; --r;
                TA.put(l, r, RField(x));
                for (int i = 0; i < FF; ++i) {
                    int c = 0;
                    while (x % F[i] == 0) {
                        x /= F[i];
                        ++c;
                    }
                    if (c) TS[i].put(l, r, c);
                }
                TB.put(l, r, RField(x));
            } else if (t == 2) {
                int p, x; cin >> p >> x;
                --p;
                for (int i = 0; i < FF; ++i) {
                    int c = 0;
                    while (x % F[i] == 0) {
                        x /= F[i];
                        ++c;
                    }
                    if (c) TS[i].put(p, -c);
                }

                RField oldCoprime = TB.get(p);
                RField inv = RField(x).pow(PHI-1);
                RField curCoprime = oldCoprime * inv;
                RField curReal = curCoprime;
                for (int i = 0; i < FF; ++i) {
                    int s = TS[i].get(p);
                    if (s) curReal *= RField{F[i]}.pow(s);
                }
                TA.directSet(p, curReal);
                TB.directSet(p, curCoprime);
            } else {
                int l, r; cin >> l >> r;
                --l; --r;
                cout << TA.get(l, r) << '\n';
            }
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ESashaAndAVeryEasyTest solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}