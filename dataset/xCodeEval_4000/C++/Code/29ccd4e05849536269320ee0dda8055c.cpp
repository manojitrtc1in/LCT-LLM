# 1 "e.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "e.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include <bits/stdc++.h>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include <ext/pb_ds/assoc_container.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include <ext/pb_ds/tree_policy.hpp>
# 15 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 24 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
using namespace std;
using namespace __gnu_pbds;

using ii = pair<int64_t, int64_t>;
using vi = vector<int64_t>;
using vd = vector<long double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
# 55 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
template<typename T>
ostream &operator<<(ostream &lhs, const vector<T> &rhs){
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i){
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
    for(size_t i = 0; i < rhs.size(); ++i){
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}
# 2 "e.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/point.hpp" 1
       

# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/utility/signum.hpp" 1
       


template<typename T>
int64_t sign(const T n) {
    return n == 0 ? 0 : (n < 0 ? -1 : 1);
}
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/point.hpp" 2

template<typename T,
typename enable_if<is_arithmetic<T>::value, uint64_t>::type = 0>
struct point {
    T x = 0, y = 0, z = 0;

    point(){}

    point(const T x, const T y) :
        x(x), y(y) {}

    point(const T x, const T y, const T z) :
        x(x), y(y), z(z) {}

    template<typename T1>
    point(const point<T1> &p) :
        x(p.x), y(p.y), z(p.z) {}

    

    bool is_null() const
    {
        return abs(x) < 1e-9 and abs(y) < 1e-9 and abs(z) < 1e-9;
    }

    

    point<long double> as_unit() const
    {
        assert(!is_null());
        return (*this)/norm(*this);
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
        tie(x, y, z) = make_tuple(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
        return *this;
    }

    

    template<typename T1>
    point &operator>>=(const point<T1> &rhs)
    {
        if(rhs.is_null())
            tie(x, y, z) = make_tuple(0, 0, 0);
        else{
            auto res = ((*this)*rhs/squared_norm(rhs))*rhs;
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
        return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
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
        return abs(lhs.x - rhs.x) < 1e-9 and abs(lhs.y - rhs.y) < 1e-9 and abs(lhs.z - rhs.z) < 1e-9;
    }

    

    template<typename T1>
    friend bool operator!=(const point &lhs, const point<T1> &rhs)
    {
        return !(lhs == rhs);
    }

    

    template<typename T1>
    friend bool operator<(const point &lhs, const point<T1> &rhs)
    {
        if(abs(lhs.x - rhs.x) < 1e-9){ 

            if(abs(lhs.y - rhs.y) < 1e-9) 

                return lhs.z < rhs.z and abs(lhs.z - rhs.z) >= 1e-9; 

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
        return (u^v).is_null();
    }

    

    template<typename T1, typename T2>
    friend bool coplanar(const point &u, const point<T1> &v, const point<T2> &w)
    {
        return abs(triple(u, v, w)) < 1e-9;
    }

    

    template<typename T1>
    friend bool perpendicular(const point &u, const point<T1> &v)
    {
        return abs(u*v) < 1e-9;
    }

    

    template<typename T1, typename T2>
    friend bool collinear(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return parallel(a - b, c - b);
    }

    

    template<typename T1, typename T2>
    friend auto triple(const point &u, const point<T1> &v, const point<T2> &w) -> typename common_type<T, T1, T2>::type
    {
        return (u^v)*w;
    }

    

    friend T squared_norm(const point &v)
    {
        return v*v;
    }

    

    friend long double norm(const point &v)
    {
        return sqrt(squared_norm(v));
    }

    

    template<typename T1>
    friend long double projection(const point &u, const point<T1> &v)
    {
        return v.is_null()? 0 : u*v/norm(v);
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
        auto aux = u*v/norm(u)/norm(v);
        return aux > 1? acos(1) : (aux < -1? acos(-1) : acos(aux));
    }

    

    template<typename T1, typename T2>
    friend long double angle(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return angle(a-b, c-b); 

    }

    

    template<typename T1>
    friend point<long double> bisector(const point &u, const point<T1> &v)
    {
        return u*norm(v) + v*norm(u);
    }

    

    template<typename T1, typename T2>
    friend int64_t orientation(const point &u, const point<T1> &v, const point<T2> &w)
    {
        

        

        

        return sign(triple(u, v, w));
    }

    

    template<typename T1>
    friend tuple<int64_t, int64_t, int64_t> orientation(const point &u, const point<T1> &v)
    {
        auto aux = u^v;
        

        

        

        

        return {sign(aux.x), sign(aux.y), sign(aux.z)};
    }

    

    template<typename T1>
    friend point<long double> rotate(const point &v, const point<T1> &u, long double r)
    {
        assert(abs(norm(u) - 1) < 1e-9);
        long double dot = v*u, co = cos(r), si = sin(r);
        long double x = u.x*dot*(1 - co) + v.x*co + (u.y*v.z - u.z*v.y)*si;
        long double y = u.y*dot*(1 - co) + v.y*co + (u.z*v.x - u.x*v.z)*si;
        long double z = u.z*dot*(1 - co) + v.z*co + (u.x*v.y - u.y*v.x)*si;
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
# 3 "e.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/geometry/see.hpp" 1
       



template<typename T>
tuple<point<long double>, long double> see(const vector<point<T> > &points, uint64_t iterations = 30000)
{
    uint64_t n = points.size();

    point<long double> c;
    for(uint64_t i=0; i<n; ++i)
        c += points[i];
    c /= n;

    for(long double p = 0.1; iterations; p *= 0.999, --iterations){
        uint64_t f = n;
        long double r = 0;
        for(uint64_t i=0; i<n; ++i){
            long double d = squared_norm(points[i]-c);
            if(d > r){
                f = i;
                r = d;
            }
        }
        if(f == n)
            break;
        c += (points[f] - c)*p;
    }

    long double r = 0;
    for(uint64_t i=0; i<n; ++i)
        r = max(r, squared_norm(points[i]-c));
    return {c, sqrt(r)};
}
# 4 "e.cpp" 2

int32_t main(){
    int64_t n;
    cin >> n;
    vector<point<int64_t> > points;
    for(int64_t i=0; i<n; ++i){
        int64_t x, y, z;
        cin >> x >> y >> z;
        points.emplace_back(x, y, z);
    }
    auto res = get<0>(see(points, 70000));
    cout.precision(10);
    cout << res.x << ' ' << res.y << ' ' << res.z << "\n";
}
