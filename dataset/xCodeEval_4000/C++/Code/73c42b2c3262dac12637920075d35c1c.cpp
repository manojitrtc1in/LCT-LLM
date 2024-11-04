# 1 "d.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "d.cpp"
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
using vd = vector<double>;
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
# 2 "d.cpp" 2

# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/circle.hpp" 1
       

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
            return acos(0);
        auto aux = u * v / norm(u) / norm(v);
        return aux > 1 ? acos(1) : (aux < -1 ? acos(-1) : acos(aux));
    }

    

    template<typename T1, typename T2>
    friend long double angle(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return angle(a - b, c - b); 

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
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/circle.hpp" 2

template<typename T>
struct circle
{
    T r;
    point<T> c;

    circle(const point<T> &c, const T r) :
        c(c), r(r) {}

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
        return 2*r*sin(ang/2); 

    }

    

    long double segment(const long double ang) const
    {
        long double b = circle_chord(r, ang);
        long double h = r*cos(ang/2);
        long double chord_area = b*h/2;
        return circle_sector(r, ang) - chord_area;
    }

    

    template<typename T1>
    tuple<point<long double>, point<long double> > tangents(const point<T1> &p) const
    {
        

        long double h = distance(p, c), x = sqrtl(h*h - r*r), ang = asin(r/h);
        auto v = c - p;
        return {p + rotate(v, OZ, ang).as_unit()*x, p + rotate(v, OZ, -ang).as_unit()*x};
    }

    

    template<typename T1>
    friend int64_t count(const circle &a, const point<T1> &p)
    {
        auto d = p - a.c; 

        auto res = d*d; 

        if(abs(a.r-res) < 1e-9L) 

            return 2;
        if(res <= a.r-1e-9L) 

            return 1;
        return 0; 

    }

    

    template<typename T1>
    friend int64_t count(const circle &a, const circle<T1> &b)
    {
        if(b.r >= a.r + 1e-9L) 

            return 0;

        if(b.c == a.c and a.r - b.r < 1e-9L) 

            return 2;

        auto squared_rdiff = a.r-b.r;
        squared_rdiff *= squared_rdiff;
        if(squared_norm(a.c-b.c) < squared_rdiff+1e-9L) 

            return 1;
        return 0; 

    }

    

    template<typename T1>
    friend int64_t intersect(const circle<T1> &b, const circle &a)
    {
        

        auto squared_rsum = a.r + b.r;
        squared_rsum *= squared_rsum;
        if(abs(squared_norm(a.c - b.c) - squared_rsum) < 1e-9L) 

            return 2;
        else if(squared_norm(a.c-b.c) < squared_rsum + 1e-9L) 

            return 1;
        return 0; 

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
# 4 "d.cpp" 2

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    point<int64_t> c1, c2;
    int64_t r1, r2;
    cin >> c1.x >> c1.y >> r1 >> c2.x >> c2.y >> r2;

    circle<int64_t> a(c1, r1), b(c2, r2);
    cout << fixed << setprecision(16) << intersection_area(a, b) << "\n";
    return 0;
}
