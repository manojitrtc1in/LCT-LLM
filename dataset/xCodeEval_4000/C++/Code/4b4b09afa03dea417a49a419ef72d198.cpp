

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

#ifndef MAJK_RANDOM_H
#define MAJK_RANDOM_H

#include <random>
#include <chrono>
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
using random_int = std::uniform_int_distribution<int>;
using random_ll = std::uniform_int_distribution<ll>;
struct TimeLimit {
    TimeLimit(double seconds) : s(seconds-0.2), last(clock()), mx(0) {}
    operator bool() const { clock_t cur = clock(); mx = max(mx, cur-last); last = cur; return clock() < s * CLOCKS_PER_SEC - 1.5 * mx; }
    double s; mutable clock_t last, mx;
};

#endif 


#ifndef MAJK_INT128_H
#define MAJK_INT128_H



ull mulull(ull a, ull z, ull mod) {
#ifdef __SIZEOF_INT128__
    __int128 result = ((__int128) a * (__int128) z) % (__int128) mod;
    return (ull) result;
#else
    

	ull q = mod / a, r = mod % a;
	ull rzq = (r < q) ? r * (z/q) : mulull(r, z/q, mod);
	ull azq = a * (z % q);
	if (azq >= rzq) return azq-rzq; else return azq-rzq+mod;
#endif
}


pair<ull,ull> mulull(ull a, ull b) {
#ifdef __SIZEOF_INT128__
    __int128 result = (__int128) a * (__int128) b;
    return {(ull) (result >> 64), (ull) result};
#else
    ull c = (ui)a, d = a>>32, e = (ui)b, f = b>>32, g = d*f, h = d*e, i = f*c, j = c*e, k = (j>>32)+(ui)h+(ui)i, left = g+(h>>32)+(i>>32)+(k>>32);
	return {left, ((h+i) << 32) + j};
#endif
}


bool fractionGreaterOrEqual(ll a, ll b, ll c, ll d) {
    if (b < 0) { b = -b; a = -a; }
    if (d < 0) { d = -d; c = -c; }
    return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

bool fractionGreaterOrEqual(pair<ll, ll> a, pair<ll, ll> b) {
    return fractionGreaterOrEqual(a.x, a.y, b.x, b.y);
}


bool fractionGreaterOrEqual(double a, double b, double c, double d) {
    return a/b >= c/d;
}


























#endif 



constexpr double PI = 3.14159265358979323846;
template <typename T> struct Segment;

template <typename T> struct Point : public pair<T,T> {
    using pair<T,T>::x;
    using pair<T,T>::y;

    Point(T a=0,T b=0) : pair<T,T>(a,b) {}
    Point(const pair<T,T> &p) : pair<T,T>(p.x,p.y) {}
    Point(const Point<T>&p) = default;
    Point<T>& operator=(const Point<T>&p) = default;

    Point<T>& operator-=(const Point<T>&p) { x -= p.x; y -= p.y; return *this; }
    Point<T>& operator+=(const Point<T>&p) { x += p.x; y += p.y; return *this; }
    Point<T>& operator*=(T f) { x *= f; y *= f; return *this; }
    Point<T> operator-(const Point<T>&p) const { Point<T> t(*this); t -= p; return t; }
    Point<T> operator+(const Point<T>&p) const { Point<T> t(*this); t += p; return t; }
    Point<T> operator*(T f) const { Point<T> t(*this); t *= f; return t; }

    T squaredDistance(const Point<T>&o) const { return Segment<T>{*this,o}.squaredLength(); }
    long double distance(const Point<T>&o) const { return Segment<T>{*this,o}.length(); }
    T sqNorm() const { return x*x+y*y; }
    long double norm() const { return sqrtl(x*x+y*y); }
    T dot(const Point<T>&o) const { return x*o.x + y*o.y; }
};

template <typename T> ostream& operator<<(ostream&o, const Point<T>&p) { o << p.x << ' ' << p.y; return o; }



template <typename T> T ccw(const Point<T>&a, const Point<T>&b, const Point<T>&c) { return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x); }
template <typename T> T area(const Point<T>&a,const Point<T>&b,const Point<T>&c) { return abs(ccw(a,b,c)); }
template <typename T> double cosangle(const Point<T>&a, const Point<T> &b, const Point<T> &c) {
    return (double)((b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y)) / a.distance(b) / a.distance(c);
}

template <typename T> bool acuteAngle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return ((b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y)) > 0;
}
template <typename T> bool obtuseAngle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return ((b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y)) < 0;
}
template <typename T> bool rightAngle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return ((b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y)) == 0;
}
template <typename T> double angle(const Point<T>&a, const Point<T> &b, const Point<T> &c) {
    return acos(cosangle(a,b,c));
}
template <typename T> int orientation(const Point<T>&a, const Point<T>&b, const Point<T>&c) { auto o = ccw(a,b,c); return (o>1e-6)-(o<-1e-6); }
template <typename T> bool collinear(const Point<T>&a, const Point<T>&b, const Point<T>&c) { return orientation(a,b,c) == 0; }

template <typename T> struct Segment : public pair<Point<T>,Point<T>> {
    using pair<Point<T>,Point<T>>::x;
    using pair<Point<T>,Point<T>>::y;
    explicit Segment(Point<T> a={0,0}, Point<T> b={0,0}) : pair<Point<T>,Point<T>>(a,b) {}
    Segment(const Segment<T>&) = default;
    Segment<T>& operator=(const Segment<T>&) = default;
    inline T dx() const { return x.x - y.x; }
    inline T dy() const { return x.y - y.y; }
    T squaredLength() const { return dx()*dx()+dy()*dy(); }
    long double length() const { return sqrtl(squaredLength()); }

    bool contains(const Point<T> &q) const {
        return collinear(x,q,y) && ((q.x <= max(x.x, y.x) && q.x >= min(x.x, y.x)) && (q.y <= max(x.y, y.y) && q.y >= min(x.y, y.y)));
    }

    double distance(const Point<T>&p) const {
        double u = ((p.x-y.x) * dx() + (p.y-y.y) * dy()) / double(dx()*dx()+dy()*dy());
        if (u > 1) u = 1;
        if (u < 0) u = 0;
        return Point<double>(p.x,p.y).distance({y.x + u * dx(), y.y + u * dy()});
    }

    bool intersect(const Segment<T>&s) const {
        return (orientation(x, y, s.x) != orientation(x, y, s.y) && orientation(s.x, s.y, x) != orientation(s.x, s.y, y))
               || contains(s.x) || contains(s.y) || s.contains(x) || s.contains(y);
    }
};

template <typename T> struct Line : public pair<Point<T>,Point<T>> {
    using pair<Point<T>,Point<T>>::x;
    using pair<Point<T>,Point<T>>::y;
    Line(Point<T> a = {0, 0}, Point<T> b = {0, 0}) : pair<Point<T>, Point<T>>(a, b) {}
    explicit Line(const Segment<T> &s) : pair<Point<T>, Point<T>>(s.x, s.y) {}
    Line(const Line<T> &p) = default;
    Line<T> &operator=(const Line<T> &p) = default;
    inline T dx() const { return x.x - y.x; }
    inline T dy() const { return x.y - y.y; }
    inline T c() const { return x.y * y.x - x.x * y.y; }

    double distance(const Point<T> &p) const {
        auto d = y-x, e = x-p;
        return (e - d*(e.dot(d)/d.sqNorm())).norm();
    }

    Point<double> project(const Point<T> &p) const {
        double u = ((p.x - y.x) * dx() + (p.y - y.y) * dy()) / double(dx() * dx() + dy() * dy());
        return {y.x + u * dx(), y.y + u * dy()};
    }

    bool parallel(const Line<T> &l) const {
        return abs(l.dx() * dy()-l.dy() * dx()) < 1e-6;
    }

    Point<long double> intersection(const Line<T> &l) {
        long double det = l.dx() * dy()-l.dy() * dx();
        if (abs(det) < 1e-12) 

            return {1e300, 1e300}; 

        else {
            long double c1 = c(), c2 = l.c();
            long double x = -(c2 * dx() - l.dx() * c1) / det;
            long double y = -(-l.dy() * c1 + c2 * dy()) / det;
            return {x, y};
        }
    };
};

template <typename T> T cramer(const std::array<T, 9> &X) {
    return X[0] * X[4] * X[8] + X[1] * X[5] * X[6] + X[2] * X[3] * X[7] - X[0] * X[5] * X[7] - X[1] * X[3] * X[8] - X[2] * X[4] * X[6];
}


template <typename T> struct Circle {
    Point<T> center;
    T sqRadius;


    bool contains(const Point<T>&p) const {
        return p.squaredDistance(center) <= sqRadius;
    }

















    




















    

    pair<Point<T>, Point<T>> intersections(Circle c) {
        Point<T> P0 = center;
        Point<T> P1 = c.center;
        T d = P0.distance(P1);
        T a = (sqRadius - c.sqRadius + d*d)/(2*d);
        T h = sqrt(sqRadius - a*a);
        Point<T> P2 = (P1 - P0) * (a/d) + P0;
        T x3 = P2.x + h*(P1.y - P0.y)/d;
        T y3 = P2.y - h*(P1.x - P0.x)/d;
        T x4 = P2.x - h*(P1.y - P0.y)/d;
        T y4 = P2.y + h*(P1.x - P0.x)/d;

        return {{x3, y3}, {x4, y4}};
    }

    Point<T> invert(const Point<T> & t) const {
        return center + (t-center)*(sqRadius / t.squaredDistance(center));
    }

    Circle(const Point<T> &c, T r) : center(c), sqRadius(r) {}
    explicit Circle(const Point<T> &p) : center(p), sqRadius(0) {}
    explicit Circle(const Point<T> &a, const Point<T> &b) : center((a.x+b.x)/2, (a.y+b.y)/2), sqRadius(a.squaredDistance(b)/4) {}
    explicit Circle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
        T la = a.squaredDistance({0,0}), lb = b.squaredDistance({0,0}), lc = c.squaredDistance({0,0});
        T x = cramer<T>({ la, a.y, 1, lb, b.y, 1, lc, c.y, 1 }) / 2;
        T y = cramer<T>({ a.x, la, 1, b.x, lb, 1, c.x, lc, 1 }) / 2;
        T s = cramer<T>({ a.x, a.y, 1, b.x, b.y, 1, c.x, c.y, 1 });
        center.x = x / s;
        center.y = y / s;
        sqRadius = center.squaredDistance(a);
    }

    static Circle minimumEnclosing(vector<Point<T>> p, bool randomize = true) {
        if (randomize) shuffle(p.begin(), p.end(), rng);
        vector<Point<T>> V;
        return welzl(p.begin(), p.end(), V);
    }

private:
    static Circle welzl(typename vector<Point<T>>::const_iterator it, typename vector<Point<T>>::const_iterator itend, vector<Point<T>> &p) {
        if (it == itend || p.size() == 3) {
            if (p.size() == 1) return Circle{p[0]};
            else if (p.size() == 2) return Circle{p[0], p[1]};
            else if (p.size() == 3) return Circle(p[0], p[1], p[2]);
            else return {Point<T>{0,0}, 0};
        } else {
            Circle d = welzl(next(it), itend, p);
            if (d.contains(*it)) return d;
            else {
                p.push_back(*it);
                d = welzl(next(it), itend, p);
                p.pop_back();
                return d;
            }
        }
    }
};

template <typename T> T doubleSignedArea(const vector<Point<T>>&P) {
    if (P.empty()) return T(0);
    T area = P.back().x*P[0].y - P.back().y*P[0].x;
    for (int i = 0; i < P.size()-1; ++i) area += (P[i].x * P[i+1].y - P[i+1].x * P[i].y);
    return area;
}

template <typename T> struct Polygon : public vector<Point<T>> {
    using vector<Point<T>>::vector;
    using vector<Point<T>>::at;
    using vector<Point<T>>::front;
    using vector<Point<T>>::back;

    T doubleSignedArea() const { return ::doubleSignedArea(*this); }

    double circumference() const {
        if (this->empty()) return T(0);
        T res = back().distance(front());
        for (int i = 0; i < this->size()-1; ++i) res += at(i).distance(at(i+1));
        return res;
    }
};


template <typename T> Polygon<T> convexhull(const vector<Point<T>> &v) {
    ui N = (ui)v.size(); vector<Point<T>> w(N+1); int lo = 0;
    for (int i = 0; i<N; ++i) if (v[i].y < v[lo].y || (v[i].y == v[lo].y && v[i].x < v[lo].x)) lo = i;
    Point<T> o = v[lo];
    for (int i = 0; i<N; ++i) w[i+1] = {v[i].x-o.x,v[i].y-o.y};
    swap(w[1],w[lo+1]);














    sort(w.begin()+2,w.end(),[](Point<T>&a,Point<T>&b) {
        if (a.y==0) return b.y != 0 || a.x < b.x;
        if (b.y==0) return false;
        auto disc = (a.x*b.y-a.y*b.x);
        return disc > 0 || (disc == 0 && a.y < b.y);
    });
    w[0] = w[N];
    ui M=1;
    for (int i=2;i<=N;++i) {
        while(ccw(w[M-1],w[M],w[i]) <= 0) if (M>1) --M; else if (i == N) break; else ++i;
        ++M; swap(w[M],w[i]);
    }
    Polygon<T> res(M);
    for (int i=0;i<M;++i) res[i] = {w[i+1].x+o.x,w[i+1].y+o.y};
    return res;
}



class ENewYearAndCastleConstruction {
public:
    void solve(istream& cin, ostream& cout) {
        int N; cin >> N;
        vector<Point<ll>> A(N); cin >> A;
        ll ans = -N*ll(N-1)*N*(N+1)/6;
        for (int i = 0; i < N; ++i) {
            vector<Point<ll>> B;
            for (int j = 0; j < N; ++j) if (i != j) B.push_back(A[j] - A[i]);
            sort(B.begin(),B.end(),[&](const Point<ll>&a, const Point<ll>&b) {
                if (a.x >= 0 && b.x < 0) return true;
                if (b.x >= 0 && a.x < 0) return false;
                return a.x * b.y > b.x * a.y;
            });

            int k = 0;
            for (int j = 0; j < N-1; ++j) {
                if (k == j) k = k==N-2?0:k+1;
                while (B[j].y*B[k].x < B[j].x*B[k].y) k = k==N-2?0:k+1;
                int cnt = k>j?k-j:k-j+N-1;
                ans += (N-cnt)*cnt;
            }
        }
        cout << ans * (N-4) / 4 << '\n';
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ENewYearAndCastleConstruction solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}