# 1 "e.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "e.cpp"

# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 11 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include<bits/stdc++.h>
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include<ext/pb_ds/assoc_container.hpp>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include<ext/pb_ds/tree_policy.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 23 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
using namespace std;
using namespace __gnu_pbds;

using ii = pair<int64_t, int64_t>;
using tt = tuple<int64_t, int64_t, int64_t>;

using vi = vector<int64_t>;
using vd = vector<long double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vtt = vector<tt>;

using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
using vvtt = vector<vtt>;
# 61 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
void debug_it() { cerr << "\n"; }
template<typename Head, typename... Tail>
void debug_it(Head H, Tail... T) { cerr << ' ' << H; debug_it(T...); }







template<typename T>
ostream &operator<<(ostream &lhs, const vector<T> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}

template<typename T, size_t N>
ostream &operator<<(ostream &lhs, const array<T, N> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &lhs, const pair<T1, T2> &rhs)
{
    if(is_floating_point<T1>::value or is_floating_point<T2>::value)
        lhs << fixed << setprecision(10);
    lhs << rhs.first << ' ' << rhs.second;
    return lhs;
}
# 3 "e.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/point.hpp" 1
       

# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/utility/signum.hpp" 1
       


template<typename T>
int64_t sign(const T n)
{
    return abs(n) < 1e-9L ? 0 : (n < 0 ? -1 : 1);
}
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/point.hpp" 2

template<typename T,
    typename enable_if<is_arithmetic<T>::value, uint64_t>::type = 0>
struct point
{
    T x = 0, y = 0, z = 0;

    point() {}

    point(const T x, const T y) :
        x(x), y(y) {}

    point(const T x, const T y, const T z) :
        x(x), y(y), z(z) {}

    template<typename T1>
    point(const point<T1> &p) :
        x(p.x), y(p.y), z(p.z)
    {}

    

    bool is_null() const
    {
        return abs(x) < 1e-9L and abs(y) < 1e-9L and abs(z) < 1e-9L;
    }

    

    point<long double> as_unit() const
    {
        assert(!is_null());
        return (*this) / norm(*this);
    }

    

    point operator-() const
    {
        return {-x, -y, -z};
    }

    

    template<typename T1>
    point &operator+=(const point<T1> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    

    template<typename T1>
    point &operator-=(const point<T1> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    

    template<typename T1>
    point &operator^=(const point<T1> &rhs)
    {
        tie(x, y, z) = make_tuple(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
        return *this;
    }

    

    template<typename T1>
    point &operator>>=(const point<T1> &rhs)
    {
        if(rhs.is_null())
            tie(x, y, z) = make_tuple(0, 0, 0);
        else {
            auto res = ((*this) * rhs / squared_norm(rhs)) * rhs;
            tie(x, y, z) = make_tuple(res.x, res.y, res.z);
        }
        return *this;
    }

    

    template<typename T1>
    point &operator<<=(const point<T1> &rhs)
    {
        return *this -= (*this >> rhs);
    }

    

    point &operator*=(const T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    

    point &operator/=(const T rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    

    template<typename T1>
    friend auto operator+(const point &lhs, const point<T1> &rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T, T1>::type> res(lhs);
        return res += rhs;
    }

    

    template<typename T1>
    friend auto operator-(const point &lhs, const point<T1> &rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T, T1>::type> res(lhs);
        return res -= rhs;
    }

    

    template<typename T1>
    friend auto operator*(const point &lhs, const point<T1> &rhs) -> typename common_type<T, T1>::type
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    

    template<typename T1>
    friend auto operator^(const point &lhs, const point<T1> &rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T, T1>::type> res(lhs);
        return res ^= rhs;
    }

    

    template<typename T1>
    friend point<long double> operator>>(const point &lhs, const point<T1> &rhs)
    {
        point<long double> res(lhs);
        return res >>= rhs;
    }

    

    template<typename T1>
    friend point<long double> operator<<(const point &lhs, const point<T1> &rhs)
    {
        point<long double> res(lhs);
        return res <<= rhs;
    }

    

    template<typename T1,
        typename enable_if<is_arithmetic<T1>::value, uint64_t>::type = 0>
    friend auto operator*(const point &lhs, const T1 rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T, T1>::type> res(lhs);
        return res *= rhs;
    }

    

    template<typename T1,
        typename enable_if<is_arithmetic<T1>::value, uint64_t>::type = 0>
    friend auto operator*(const T1 lhs, const point &rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T1, T>::type> res(rhs);
        return res *= lhs;
    }

    

    template<typename T1,
        typename enable_if<is_arithmetic<T1>::value, uint64_t>::type = 0>
    friend auto operator/(const point &lhs, const T1 rhs) -> point<typename common_type<T, T1>::type>
    {
        point<typename common_type<T, T1>::type> res(lhs);
        return res /= rhs;
    }

    

    template<typename T1>
    friend bool operator==(const point &lhs, const point<T1> &rhs)
    {
        return abs(lhs.x - rhs.x) < 1e-9L and abs(lhs.y - rhs.y) < 1e-9L and abs(lhs.z - rhs.z) < 1e-9L;
    }

    

    template<typename T1>
    friend bool operator!=(const point &lhs, const point<T1> &rhs)
    {
        return !(lhs == rhs);
    }

    

    template<typename T1>
    friend bool operator<(const point &lhs, const point<T1> &rhs)
    {
        if(abs(lhs.x - rhs.x) < 1e-9L) { 

            if(abs(lhs.y - rhs.y) < 1e-9L) 

                return lhs.z < rhs.z and abs(lhs.z - rhs.z) >= 1e-9L; 

            return lhs.y < rhs.y; 

        }
        return lhs.x < rhs.x; 

    }

    

    template<typename T1>
    friend bool operator>(const point &lhs, const point<T1> &rhs)
    {
        return rhs < lhs;
    }

    

    template<typename T1>
    friend bool operator<=(const point &lhs, const point<T1> &rhs)
    {
        return !(lhs > rhs);
    }

    

    template<typename T1>
    friend bool operator>=(const point &lhs, const point<T1> &rhs)
    {
        return !(lhs < rhs);
    }

    

    template<typename T1>
    friend bool parallel(const point &u, const point<T1> &v)
    {
        return (u ^ v).is_null();
    }

    

    template<typename T1, typename T2>
    friend bool coplanar(const point &u, const point<T1> &v, const point<T2> &w)
    {
        return abs(triple(u, v, w)) < 1e-9L;
    }

    

    template<typename T1>
    friend bool perpendicular(const point &u, const point<T1> &v)
    {
        return abs(u * v) < 1e-9L;
    }

    

    template<typename T1, typename T2>
    friend bool collinear(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return parallel(a - b, c - b);
    }

    

    template<typename T1, typename T2>
    friend auto triple(const point &u, const point<T1> &v, const point<T2> &w) -> typename common_type<T, T1, T2>::type
    {
        return (u ^ v) * w;
    }

    

    friend T squared_norm(const point &v)
    {
        return v * v;
    }

    

    friend long double norm(const point &v)
    {
        return sqrtl(squared_norm(v));
    }

    

    template<typename T1>
    friend long double projection(const point &u, const point<T1> &v)
    {
        return v.is_null() ? 0 : u * v / norm(v);
    }

    

    template<typename T1>
    friend long double rejection(const point &u, const point<T1> &v)
    {
        return norm(u << v);
    }

    

    template<typename T1>
    friend long double distance(const point &a, const point<T1> &b)
    {
        return norm(b - a);
    }

    

    template<typename T1>
    friend long double angle(const point &u, const point<T1> &v)
    {
        if(u.is_null() or v.is_null())
            return acosl(0);
        auto aux = u * v / norm(u) / norm(v);
        return aux > 1 ? 0 : (aux < -1 ? acosl(-1) : acosl(aux));
    }

    

    template<typename T1, typename T2>
    friend long double angle(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return angle(a - b, c - b); 

    }

    

    friend long double polar_angle(const point &v)
    {
        long double ang = angle(v, point<int64_t>(1, 0));
        if(v.y > -1e-9L) 

            return ang;
        return 2*acosl(-1) - ang; 

    }

    

    template<typename T1>
    friend point<long double> bisector(const point &u, const point<T1> &v)
    {
        return u * norm(v) + v * norm(u);
    }

    

    template<typename T1, typename T2>
    friend int64_t orientation(const point &u, const point<T1> &v, const point<T2> &w)
    {
        

        

        

        return sign(triple(u, v, w));
    }

    

    template<typename T1>
    friend tuple<int64_t, int64_t, int64_t> orientation(const point &u, const point<T1> &v)
    {
        auto aux = u ^ v;
        

        

        

        

        return {sign(aux.x), sign(aux.y), sign(aux.z)};
    }

    

    template<typename T1>
    friend point<long double> rotate(const point &v, const point<T1> &u, long double r)
    {
        assert(abs(norm(u) - 1) < 1e-9L);
        long double dot = v * u, co = cos(r), si = sin(r);
        long double x = u.x * dot * (1 - co) + v.x * co + (u.y * v.z - u.z * v.y) * si;
        long double y = u.y * dot * (1 - co) + v.y * co + (u.z * v.x - u.x * v.z) * si;
        long double z = u.z * dot * (1 - co) + v.z * co + (u.x * v.y - u.y * v.x) * si;
        return {x, y, z};
    }

    

    friend string to_string(const point &p)
    {
        return '(' + to_string(p.x) + ' ' + to_string(p.y) + ' ' + to_string(p.z) + ')';
    }

    

    friend ostream &operator<<(ostream &lhs, const point &rhs)
    {
        return lhs << to_string(rhs);
    }
};

const point<int64_t> OX(1, 0, 0), OY(0, 1, 0), OZ(0, 0, 1);
# 4 "e.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/circle.hpp" 1
       


# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/line.hpp" 1
       



template<typename T>
struct line
{
    point<T> p, v;

    line() {}

    template<typename T1, typename T2>
    line(const point<T1> &p, const point<T2> &v) :
        p(p), v(v)
    {}

    template<typename T1>
    line(const line<T1> &l) :
        p(l.p), v(l.v)
    {}

    

    bool is_degenerate() const
    {
        return v.is_null();
    }

    

    template<typename T1,
        typename enable_if<is_arithmetic<T1>::value, uint64_t>::type = 0>
    auto at(const T1 k) const -> point<typename common_type<T, T1>::type>
    {
        return p + k * v;
    }

    

    template<typename T1>
    friend bool operator==(const line &lhs, const line<T1> &rhs)
    {
        if(lhs.is_degenerate() and rhs.is_degenerate())
            return lhs.p == rhs.p;
        else if(!lhs.is_degenerate() and !rhs.is_degenerate())
            return parallel(lhs, rhs) and count(lhs, rhs.p);
        return false;
    }

    

    template<typename T1>
    friend bool operator!=(const line &lhs, const line<T1> &rhs)
    {
        return !(lhs == rhs);
    }

    

    template<typename T1>
    friend bool count(const line &l, const point<T1> &p)
    {
        return l.is_degenerate() ? p == l.p : parallel((p - l.p), l.v);
    }

    

    template<typename T1>
    friend bool coplanar(const line<T1> &r, const line &l)
    {
        return coplanar(r.v, l.v, l.p - r.p);
    }

    

    template<typename T1>
    friend bool parallel(const line<T1> &r, const line &l)
    {
        return parallel(r.v, l.v);
    }

    

    template<typename T1>
    friend bool concurrent(const line<T1> &r, const line &l)
    {
        return coplanar(r, l) and !parallel(r, l);
    }

    

    template<typename T1>
    friend bool orthogonal(const line<T1> &r, const line &l)
    {
        return perpendicular(r.v, l.v);
    }

    

    template<typename T1>
    friend bool perpendicular(const line<T1> &r, const line &l)
    {
        return coplanar(r, l) and orthogonal(r, l);
    }

    

    template<typename T1>
    friend bool intersect(const line<T1> &r, const line &l)
    {
        if(r == l)
            return true;
        else if(r.is_degenerate() and count(l, r.p))
            return true;
        else if(l.is_degenerate() and count(r, l.p))
            return true;
        return concurrent(r, l);
    }

    

    template<typename T1>
    friend line<long double> intersection(const line<T1> &r, const line &l)
    {
        assert(intersect(r, l));
        if(r == l or r.is_degenerate())
            return r;
        else if(l.is_degenerate())
            return l;
        auto rl = l.p - r.p;
        long double k = sqrtl((long double)squared_norm(rl ^ l.v) / squared_norm(r.v ^ l.v));
        return {r.at(k * orientation(rl, l.v, r.v ^ l.v)), point<long double>()};
    }

    

    template<typename T1>
    friend long double distance(const point<T1> &p, const line &l)
    {
        if(l.is_degenerate())
            return distance(p, l.p);
        return sqrtl((long double)squared_norm((p - l.p) ^ l.v) / squared_norm(l.v));
    }

    

    template<typename T1>
    friend long double distance(const line<T1> &r, const line &l)
    {
        if(l.is_degenerate())
            return distance(l.p, r);
        else if(r.is_degenerate() or parallel(r, l))
            return distance(r.p, l);
        return abs((l.p - r.p) * (r.v ^ l.v)) / norm(r.v ^ l.v);
    }

    

    template<typename T1>
    friend point<long double> projection(const point<T1> &p, const line &l)
    {
        point<long double> res = l.p;
        if(!l.is_degenerate())
            res += l.v * ((long double)((p - l.p) * l.v) / squared_norm(l.v));
        return res;
    }

    

    template<typename T1>
    friend line<long double> projection(const line<T1> &r, const line &l)
    {
        auto p = projection(r.p, l), q = projection(r.p + r.v, l);
        return {p, q - p};
    }

    

    template<typename T1>
    friend point<long double> reflection(const point<T1> &p, const line &l)
    {
        return 2 * projection(p, l) - p;
    }

    

    template<typename T1>
    friend line<long double> reflection(const line<T1> &r, const line &l)
    {
        auto p = reflection(r.p, l), q = reflection(r.p + r.v, l);
        return {p, q - p};
    }

    

    friend string to_string(const line &l)
    {
        return '[' + to_string(l.p) + ' ' + to_string(l.v) + ']';
    }

    

    friend ostream &operator<<(ostream &lhs, const line &rhs)
    {
        return lhs << to_string(rhs);
    }
};

line<long double> make_line2d(const long double a, const long double b, const long double c)
{
    point<long double> p, v(-b, a);
    if(abs(a) >= 1e-9L)
        p = {-c / a, 0};
    else
        p = {0, -c / b};
    return line<long double>(p, v);
}

template<typename T>
tuple<T, T, T> line2d_coefficients(const line<T> &l)
{
    assert(abs(l.p.z) < 1e-9L and abs(l.v.z) < 1e-9L);
    auto p = l.p, q = l.p + l.v;
    return {q.y - p.y, p.x - q.x, p.y * q.x - p.x * q.y};
}
# 5 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/circle.hpp" 2

template<typename T>
struct circle
{
    T r;
    point<T> c;

    circle(const point<T> &c, const T r) :
        c(c), r(r) {}

    

    bool is_degenerate() const
    {
        return abs(r) < 1e-9L;
    }

    

    long double area() const
    {
        return acosl(-1)*r*r;
    }

    

    T diameter() const
    {
        return 2*r;
    }

    

    long double circunference() const
    {
        return 2*acosl(-1)*r;
    }

    

    long double arc(const long double ang) const
    {
        return ang*r; 

    }

    

    long double sector(const long double ang) const
    {
        return (ang/2)*r*r; 

    }

    

    long double chord(const long double ang) const
    {
        return 2*r*sinl(ang/2); 

    }

    

    long double segment(const long double ang) const
    {
        long double b = circle_chord(r, ang);
        long double h = r*cosl(ang/2);
        long double chord_area = b*h/2;
        return circle_sector(r, ang) - chord_area;
    }

    

    template<typename T1>
    tuple<point<long double>, point<long double> > tangents(const point<T1> &p) const
    {
        

        long double h = distance(p, c), x = sqrtl(h*h - r*r), ang = asinl(r/h);
        auto v = c - p;
        

        

        

        return {p + rotate(v, OZ, ang)*x/h, p + rotate(v, OZ, -ang)*x/h};
    }

    

    template<typename T1>
    friend bool operator==(const circle &lhs, const circle<T1> &rhs)
    {
        return lhs.c == rhs.c and abs(lhs.r-rhs.r) < 1e-9L;
    }

    

    template<typename T1>
    friend bool operator!=(const circle &lhs, const circle<T1> &rhs)
    {
        return !(lhs == rhs);
    }

    

    template<typename T1>
    friend int64_t count(const circle &a, const point<T1> &p)
    {
        auto d = p - a.c; 

        auto res = d*d; 

        if(abs(a.r*a.r-res) < 1e-9L) 

            return 2;
        if(res <= a.r*a.r - 1e-9L) 

            return 1;
        return 0; 

    }

    

    template<typename T1>
    friend int64_t count(const circle &a, const circle<T1> &b)
    {
        if(b == a) 

            return 2;

        if(b.r >= a.r + 1e-9L) 

            return 0;

        auto squared_rdiff = a.r-b.r; 

        squared_rdiff *= squared_rdiff;
        if(squared_norm(a.c-b.c) < squared_rdiff+1e-9L) 

            return 1;
        return 0; 

    }

    

    template<typename T1>
    friend int64_t intersect(const line<T1> &l, const circle &a)
    {
        auto d = distance(a.c, l);
        if(abs(d - a.r) < 1e-9L) 

            return 2;
        else if(d <= a.r - 1e-9L) 

            return 1;
        return 0; 

    }

    

    template<typename T1>
    friend int64_t intersect(const circle<T1> &b, const circle &a)
    {
        if(b == a) 

            return 3;

        auto sqd = squared_norm(a.c - b.c); 


        auto squared_rdiff = a.r-b.r; 

        squared_rdiff *= squared_rdiff;

        if(abs(sqd - squared_rdiff) < 1e-9L) 

            return 2;

        auto squared_rsum = a.r + b.r; 

        squared_rsum *= squared_rsum;

        if(abs(sqd - squared_rsum) < 1e-9L) 

            return 2;

        if(sqd >= squared_rsum + 1e-9L or count(b, a) or count(a, b)) 

            return 0;

        return 1; 

    }

    

    template<typename T1>
    friend tuple<point<long double>, point<long double> > intersection(const line<T1> &l, const circle &a)
    {
        int64_t check = intersect(l, a);
        assert(check);

        auto res = projection(a.c, l); 

        if(check == 2) 

            return {res, res};

        if(res == a.c){ 

            auto dir = l.v*a.r/norm(l.v);
            return {res - dir, res + dir};
        }

        auto v = res - a.c; 

        long double sqd = squared_norm(v), d = sqrtl(sqd); 


        long double w = sqrtl(a.r*a.r - sqd); 


        swap(v.x, v.y); 

        v.x = -v.x;

        auto dir = v*w/d;
        

        if(dir*l.v >= 1e-9L)
            return {res - dir, res + dir};
        return {res + dir, res - dir};
    }

    

    template<typename T1>
    friend tuple<point<long double>, point<long double> > intersection(const circle<T1> &b, const circle &a)
    {
        int64_t check = intersect(b, a);
        assert(check);
        if(check == 3) 

            return {b.c + OX*b.r, b.c - OX*b.r};

        auto ac = a.c - b.c;
        auto l = make_line2d(-2*ac.x, -2*ac.y, ac.x*ac.x + ac.y*ac.y + b.r*b.r - a.r*a.r);
        circle<T1> c(point<T1>(0, 0), b.r);

        auto res = intersection(l, c);
        

        

        

        return {get<1>(res) + b.c, get<0>(res) + b.c};
    }

    

    template<typename T1>
    friend long double intersection_area(const circle<T1> &b, const circle &a)
    {
        if(count(b, a)) 

            return a.area();
        else if(count(a, b)) 

            return b.area();

        

        if(intersect(b, a) != 1)
            return 0;

        long double d = distance(a.c, b.c);
        long double sqd = d*d;

        long double sqar = a.r*a.r;
        long double sqbr = b.r*b.r;

        

        long double alpha = acosl((sqd + (a.r-b.r)*(a.r+b.r))/(2*d*a.r));
        long double res_a = sqar*(alpha - 0.5*sinl(2*alpha));

        long double beta = acosl((sqd + (b.r-a.r)*(b.r+a.r))/(2*d*b.r));
        long double res_b = sqbr*(beta - 0.5*sinl(2*beta));

        return res_a + res_b;
    }

    

    friend string to_string(const circle &a)
    {
        return '[' + to_string(a.c) + ' ' + to_string(a.r) + ']';
    }

    

    friend ostream &operator<<(ostream &lhs, const circle &rhs)
    {
        return lhs << to_string(rhs);
    }
};
# 5 "e.cpp" 2

using pdd = pair<long double, long double>;

long double degrees(long double ang){
    return ang*(180.0/3.141592653589793238463);
}

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    point<int64_t> ini;
    int64_t v, T;
    cin >> ini.x >> ini.y >> v >> T;

    int64_t n;
    cin >> n;

    bool ok = false;
    vector<circle<int64_t> > plts;
    for(int64_t i=0; i<n; ++i){
        point<int64_t> p;
        int64_t r;
        cin >> p.x >> p.y >> r;
        plts.emplace_back(p, r);

        if(count(plts.back(), ini))
            ok = true; 

    }
    if(ok)
        cout << 1 << "\n";
    else{
        circle<int64_t> coc(ini, v*T);

        vector<pdd> angs;
        for(int64_t i=0; i<n; ++i){
            if(coc.r > distance(ini, plts[i].c) - 1e-9L){
                auto res = plts[i].tangents(coc.c);

                pdd cur;
                cur.first = polar_angle(get<1>(res) - ini);
                cur.second = polar_angle(get<0>(res) - ini);
                if(cur.first >= cur.second + 1e-9L){
                    angs.emplace_back(cur.first, 2*acosl(-1)-1e-9L);
                    angs.emplace_back(0, cur.second);
                }
                else
                    angs.emplace_back(cur);
            }
            else if(intersect(coc, plts[i])){
                auto res = intersection(coc, plts[i]);

                pdd cur;
                cur.first = polar_angle(get<0>(res) - ini);
                cur.second = polar_angle(get<1>(res) - ini);
                if(cur.first >= cur.second + 1e-9L){
                    angs.emplace_back(cur.first, 2*acosl(-1)-1e-9L);
                    angs.emplace_back(0, cur.second);
                }
                else
                    angs.emplace_back(cur);
            }
        }
        sort(angs.begin(), angs.end());

        vector<pdd> res;
        for(pdd &i:angs){
            if(res.empty() or res.back().second <= i.first - 1e-9L)
                res.emplace_back(i);
            else
                res.back().second = max(res.back().second, i.second);
        }
        long double ans = 2*acosl(-1) - 1e-9L;
        for(pdd &i:res)
            ans -= i.second - i.first + 1e-9L;
        cout << fixed << setprecision(16) << 1 - ans/(2*acosl(-1) - 1e-9L) << "\n";
    }
    return 0;
}