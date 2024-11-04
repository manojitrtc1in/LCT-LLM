

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
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


template <typename ValueType, typename TagType,
          void (*combineTag)(TagType&, TagType),
          void (*applyTag)(ValueType&, TagType, ui),
          ValueType (*combineValues)(ValueType,ValueType)>
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

    
    template <typename Pred> ui longestSuffix(ui x, Pred pred) {
        ValueType value = nullValue;
        return longestSuffixInner2(x, 1, 0, n, value, pred);
    }

    template <typename Pred> ui longestSuffixInner(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].x, curValue);
        if (pred(nextValue)) { curValue = nextValue; return l; }
        if (l + 1 == r) return r;
        ui s = longestSuffixInner(i << 1 | 1, (l + r) / 2, r, curValue, pred);
        if (s == (l+r)/2) {
            return longestSuffixInner(i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            return s;
        }
    }

    template <typename Pred> ui longestSuffixInner2(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x >= r-1) {
            return longestSuffixInner(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].x, curValue);
            if (pred(nextValue)) { curValue = nextValue; return l; }
            else return r;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x < m) {
            return longestSuffixInner2(x, i << 1, l, (l + r) / 2, curValue, pred);
        } else {
            ui s = longestSuffixInner2(x, i << 1 | 1, (l + r) / 2, r, curValue, pred);
            if (s == (l + r) / 2) {
                return longestSuffixInner(i << 1, l, (l + r) / 2, curValue, pred);
            } else {
                return s;
            }
        }
    }

    
    template <typename Pred> ui longestPrefix(ui x, Pred pred) {
        ValueType value = nullValue;
        return longestPrefixInner2(x, 1, 0, n, value, pred) - 1;
    }

    template <typename Pred> ui longestPrefixInner(ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (l + 1 != r) pushTagDown(i, r-l);
        ValueType nextValue = combineValues(T[i].x, curValue);
        if (pred(nextValue)) { curValue = nextValue; return r; }
        if (l + 1 == r) return l;
        ui s = longestPrefixInner(i << 1, l, (l + r) / 2, curValue, pred);
        return s == (l + r) / 2 ? longestPrefixInner(i << 1 | 1, (l + r) / 2, r, curValue, pred) : s;
    }

    template <typename Pred> ui longestPrefixInner2(ui x, ui i, ui l, ui r, ValueType &curValue, Pred pred) {
        if (x <= l) {
            return longestPrefixInner(i, l, r, curValue, pred);
        }

        if (l + 1 == r) {
            ValueType nextValue = combineValues(T[i].x, curValue);
            if (pred(nextValue)) { curValue = nextValue; return r; }
            else return l;
        }

        pushTagDown(i, r-l);
        ui m = (l+r)/2;
        if (x >= m) {
            return longestPrefixInner2(x, i << 1 | 1, m, r, curValue, pred);
        } else {
            ui s = longestPrefixInner2(x, i << 1, l, m, curValue, pred);
            return s == m ? longestPrefixInner(i << 1 | 1, m, r, curValue, pred) : s;
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


template <typename F> void LAddOp(F &a, F b) { a += b; }
template <typename F> void LAddOp2(F &a, F b, ui) { a += b; }
template <typename F> F LMinOp(F a, F b) { return std::min(a, b); }
template <typename F> F LMaxOp(F a, F b) { return std::max(a, b); }
template <typename T> T LSumOp(T a, T b) { return a + b; }
template <typename T> void LAssignOp(T &a, T b) { if (b != 0) a = b; };
template <typename T> void LAssignOp2(T &a, T b, ui) { if (b != 0) a = b; };
template <typename T> void LAssignMultOp(T &a, T b, ui s) { if (b != 0) a = b*s; };

template<typename T> using LAddMaxTree = LSegTree<T, T, LAddOp<T>, LAddOp2<T>, LMaxOp<T>>;
template<typename T> using LAddMinTree = LSegTree<T, T, LAddOp<T>, LAddOp2<T>, LMinOp<T>>;

template<typename T> using AddSumTree = LSegTree<T, T, LAddOp<T>, LAddOp2<T>, LSumOp<T>>;
template<typename T> using AssignSumTree = LSegTree<T, T, LAssignOp<T>, LAssignMultOp<T>, LSumOp<T>>;
template<typename T> using AssignMaxTree = LSegTree<T, T, LAssignOp<T>, LAssignOp2<T>, LMaxOp<T>>;


class EAlyonaAndTowers {
public:
    void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        vector<ll> A(N); cin >> A;
        LAddMaxTree<ll> T(A, 0, 0);

        vector<int> L(N, 0), R(N, N-1), D(N);
        for (int i = N-2; i >= 0; --i) if (A[i] > A[i+1]) R[i] = R[i+1]; else R[i] = i;
        for (int i = 1; i < N; ++i) if (A[i] > A[i-1]) L[i] = L[i-1]; else L[i] = i;
        for (int i = 0; i < N; ++i) D[i] = R[i] - L[i];
        LAddMaxTree<int> LL(L, 0, 0);
        LAddMinTree<int> RR(R, 1000000, 0);
        LAddMaxTree<int> DD(D, 0, 0);




        auto setLeft = [&](int l, int target) {
            int orig = LL.get(l);
            int end = LL.longestPrefix(l, [&](int x) { return x == orig; });



            LL.put(l, end, target - orig);
            DD.put(l, end, -(target - orig));
        };
        auto setRight = [&](int r, int target) {
            int orig = RR.get(r);
            int begin = RR.longestSuffix(r, [&](int x) { return x == orig; });



            RR.put(begin, r, target - orig);
            DD.put(begin, r, target - orig);
        };

        int M; cin >> M;
        for (int i = 0; i < M; ++i) {
            int l, r, d; cin >> l >> r >> d;
            --l; --r;


            if (l > 0) {
                ll a = T.get(l-1);
                ll b = T.get(l);


                if (a >= b && a <= b + d) {
                    if (a < b + d) {
                        setLeft(l, LL.get(l-1));
                    }


                    if (a > b) {
                        setRight(l-1, l-1);
                    }
                }
            }

            if (r < N-1) {
                ll a = T.get(r+1);
                ll b = T.get(r);

                if (a >= b && a <= b + d) {
                    if (a < b + d) {
                        setRight(r, RR.get(r+1));
                    }

                    if (a > b) {
                        setLeft(r+1, r+1);
                    }
                }
            }

            T.put(l, r, d);











            cout << DD.get(0, N-1) + 1 << '\n';
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	EAlyonaAndTowers solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}