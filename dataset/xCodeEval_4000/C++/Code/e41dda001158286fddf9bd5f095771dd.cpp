#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 





#include <bits/stdc++.h>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < vlong, vlong > pll;
typedef vector<pll> vll;
typedef vector<vlong> vl;
using ll = long long;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

#ifdef DEBUG
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)  

    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;






inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m; 

    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

namespace FIO{
    char buf[32*1042|1];
    int bc=0, be=0;
    char gc(){
        if(bc>=be){
            be = fread(buf, 1, sizeof(buf)-1, stdin);
            buf[be] = bc = 0;
        }
        return buf[bc++];
    }
    void readint(){}
    void readuint(){}
    template<typename T, typename ...S>
    void readuint(T &a, S& ...b){
        a=0;
        int x=gc();
        while(x<'0' || x>'9') x=gc();
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
        readuint(b...);
    }
	template<typename T, typename ...S>
    void readint(T &a, S& ...b){
        a=0;
        int x=gc(), s=1;;
        while(x!='-' && (x<'0' || x>'9')) x=gc();
		if(x=='-'){ s=-s; x=gc(); }
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
		if(s<0) a=-a;
        readint(b...);
    }
    void readchar ( char &x ) {
        register char c = gc();
        while (c < 33) c = gc();
        x = c;
    }
    void readstring(char *str){
        register char c = 0;
        register int i = 0;
        while (c < 33)
            c = gc();
        while (c != '\n') {
            str[i] = c;
            c = gc();
            i = i + 1;
        }
        str[i] = '\0';
    }
}
using FIO::readint;
using FIO::readuint;
using FIO::readchar;
using FIO::readstring;



signed gen(int T){
    

    auto get_rand = [&](int64_t l, int64_t r){
        return uniform_int_distribution<int64_t>(l, r)(rng);
    };
    auto get_double = [&](double l, double r){
        return uniform_real_distribution<double>(l, r)(rng);
    };
    ofstream o("gen.txt");
    o << T << "\n";
    for(int cas=0;cas<T;++cas){
        o << "\n";
        

        
    }
    o << endl;
    o.close();
    return 0;
}

typedef double T;

template <typename T> int sgn(T x) {
    return ABS(x) < eps ? 0 : (T(0) < x) - (x < T(0));
}

struct pt {
    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}

    pt operator-(pt p) {return {x-p.x, y-p.y};}

    pt operator*(T d) {return {x*d, y*d};}

    pt operator/(T d) {return {x/d, y/d};} 

};

struct p3 {
    T x,y,z;
    

    p3 operator+(p3 p) {return {x+p.x, y+p.y, z+p.z};}

    p3 operator-(p3 p) {return {x-p.x, y-p.y, z-p.z};}

    p3 operator*(T d) {return {x*d, y*d, z*d};}

    p3 operator/(T d) {assert(ABS(d) > eps); return {x/d, y/d, z/d};} 

    

    bool operator==(p3 p) {return tie(x,y,z) == tie(p.x,p.y,p.z);}

    bool operator!=(p3 p) {return !operator==(p);}
};

p3 zero{0,0,0};

T operator|(p3 v, p3 w) {return v.x*w.x + v.y*w.y + v.z*w.z;}

T sq(p3 v) {return v|v;}

double abs(p3 v) {return sqrt(sq(v));}

p3 unit(p3 v) {return v/abs(v);}

double angle(p3 v, p3 w) {
    double cosTheta = (v|w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}

p3 operator*(p3 v, p3 w) {
    return {v.y*w.z - v.z*w.y, v.z*w.x - v.x*w.z, v.x*w.y - v.y*w.x};
}

T orient(p3 p, p3 q, p3 r, p3 s) {return (q-p)*(r-p)|(s-p);}

T orientByNormal(p3 p, p3 q, p3 r, p3 n) {return (q-p)*(r-p)|n;}

struct plane {
    p3 n; T d;
    

    plane(p3 n, T d) : n(n), d(d) {}
    

    plane(p3 n, p3 p) : n(n), d(n|p) {}
    

    plane(p3 p, p3 q, p3 r) : plane((q-p)*(r-p), p) {}
    

    T side(p3 p) {return (n|p)-d;}

    double dist(p3 p) {return abs(side(p))/abs(n);}

    plane translate(p3 t) {return {n, d+(n|t)};}
    

    plane shiftUp(double dist) {return {n, d + dist*abs(n)};}

    p3 proj(p3 p) {return p - n*side(p)/sq(n);}

    p3 refl(p3 p) {return p - n*2*side(p)/sq(n);}
};

struct coords {
    p3 o, dx, dy, dz;
    

    

    coords(p3 p, p3 q, p3 r) : o(p) {
        dx = unit(q-p);
        dz = unit(dx*(r-p));
        dy = dz*dx;
    }
    

    

    coords(p3 p, p3 q, p3 r, p3 s) : o(p), dx(q-p), dy(r-p), dz(s-p) {}

    pt pos2d(p3 p) {return {(p-o)|dx, (p-o)|dy};}

    p3 pos3d(p3 p) {return {(p-o)|dx, (p-o)|dy, (p-o)|dz};}
};

struct line3d {
    p3 d, o;
    

    line3d(p3 p, p3 q) : d(q-p), o(p) {}
    

    line3d(plane p1, plane p2) {
        d = p1.n*p2.n;
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }
    

    double sqDist(p3 p) {return sq(d*(p-o))/sq(d);}

    double dist(p3 p) {return sqrt(sqDist(p));}

    bool cmpProj(p3 p, p3 q) {return sgn((d|p) - (d|q)) < 0;}
    

    p3 proj(p3 p) {return o + d*(d|(p-o))/sq(d);}

    p3 refl(p3 p) {return proj(p)*2 - p;}

    p3 inter(plane p) {return o - d*p.side(o)/(p.n|d);}
};

double dist(line3d l1, line3d l2) {
    p3 n = l1.d*l2.d;
    if (n == zero) 

        return l1.dist(l2.o);
    return abs((l2.o-l1.o)|n)/abs(n);
}

p3 closestOnL1(line3d l1, line3d l2) {
    p3 n2 = l2.d*(l1.d*l2.d);
    return l1.o + l1.d*((l2.o-l1.o)|n2)/(l1.d|n2);
}

double smallAngle(p3 v, p3 w) {
    return acos(min(abs(v|w)/abs(v)/abs(w), 1.0));
}

double angle(plane p1, plane p2) {
    return smallAngle(p1.n, p2.n);
}

bool isParallel(plane p1, plane p2) {
    return p1.n*p2.n == zero;
}

bool isPerpendicular(plane p1, plane p2) {
    return (p1.n|p2.n) == 0;
}

double angle(line3d l1, line3d l2) {
    return smallAngle(l1.d, l2.d);
}

bool isParallel(line3d l1, line3d l2) {
    return l1.d*l2.d == zero;
}

bool isPerpendicular(line3d l1, line3d l2) {
    return (l1.d|l2.d) == 0;
}

double angle(plane p, line3d l) {
    return pi/2 - smallAngle(p.n, l.d);
}

bool isParallel(plane p, line3d l) {
    return (p.n|l.d) == 0;
}

bool isPerpendicular(plane p, line3d l) {
    return p.n*l.d == zero;
}

line3d perpThrough(plane p, p3 o) {return line3d(o, o+p.n);}

plane perpThrough(line3d l, p3 o) {return plane(l.d, o);}

p3 vectorArea2(vector<p3> p) { 

    p3 S = zero;
    for (int i = 0, n = p.size(); i < n; i++)
        S = S + p[i]*p[(i+1)%n];
    return S;
}

double area(vector<p3> p) {
    return abs(vectorArea2(p)) / 2.0;
}

vector<p3> get_poly() {
    int n;
    readint(n);
    vector<p3> poly(n);
    for (p3 &P: poly) {
        int x, y, z;
        readint(x, y, z);
        P = {x, y, z};
    }
    return move(poly);
}

vector<p3> inter_points(const vector<p3> &poly, line3d l) {
    int n = SZ(poly);
    vector<p3> res;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line3d l1(poly[i], poly[j]);
        p3 p = isParallel(l, l1) ? poly[i] : closestOnL1(l1, l);
        if (sgn(l.sqDist(p)) == 0 and l1.cmpProj(p, poly[j]) and not l1.cmpProj(p, poly[i])) {
            int pnz = i;
            if (sgn(l.sqDist(poly[pnz])) == 0) {
                pnz = (pnz + n - 1) % n;
            }
            if (sgn(l.sqDist(poly[pnz])) == 0) {
                continue;
            }
            int nnz = j;
            while (sgn(l.sqDist(poly[nnz])) == 0) {
                nnz = (nnz + 1) % n;
            }
            coords C(l.o, l.o + l.d, poly[pnz]);
            if (sgn(C.pos2d(poly[nnz]).y) < 0) {
                res.pb(p);
            }
        }
    }
    sort(ALL(res), [&](p3 i, p3 j) {
        return l.cmpProj(i, j);
    });
    return move(res);
}

bool verify(const vector<p3> &A, const vector<p3> &B, line3d l) {
    bool hasA = false, hasB = false;
    int na = SZ(A), nb = SZ(B), in = 0, out = 0;
    for (int i = 0, j = 0; i < na or j < nb; ) {
        if (j == nb or (i < na and l.cmpProj(A[i], B[j]))) {
            hasA = not hasA;
            if (hasB) {
                if (hasA) {
                    in++;
                } else {
                    out++;
                }
            }
            i++;
        } else {
            hasB = not hasB;
            j++;
        }
    }
    return in != out;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; 
	if(TTT < 0) return gen(-TTT);
	while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif 


    

    vector<p3> poly0 = get_poly(), poly1 = get_poly();
    plane P0(poly0[0], poly0[1], poly0[2]), P1(poly1[0], poly1[1], poly1[2]);
    bool res = false;
    if (not isParallel(P0, P1)) {
        line3d inter(P0, P1);
        vector<p3> S0 = inter_points(poly0, inter), S1 = inter_points(poly1, inter);
        res = verify(S0, S1, inter);
    }
    cout << (res ? "YES" : "NO") << "\n";

    #ifdef LOCAL_RUN
    }
    #endif 

    return 0;
}