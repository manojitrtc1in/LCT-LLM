# 1 "g.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "g.cpp"
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
# 2 "g.cpp" 2
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

    

    point<double> as_unit() const
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
    friend point<double> operator>>(const point &lhs, const point<T1> &rhs)
    {
        point<double> res(lhs);
        return res >>= rhs;
    }

    

    template<typename T1>
    friend point<double> operator<<(const point &lhs, const point<T1> &rhs)
    {
        point<double> res(lhs);
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

    

    friend double norm(const point &v)
    {
        return sqrtl(squared_norm(v));
    }

    

    template<typename T1>
    friend double projection(const point &u, const point<T1> &v)
    {
        return v.is_null() ? 0 : u * v / norm(v);
    }

    

    template<typename T1>
    friend double rejection(const point &u, const point<T1> &v)
    {
        return norm(u << v);
    }

    

    template<typename T1>
    friend double distance(const point &a, const point<T1> &b)
    {
        return norm(b - a);
    }

    

    template<typename T1>
    friend double angle(const point &u, const point<T1> &v)
    {
        if(u.is_null() or v.is_null())
            return acosl(0);
        auto aux = u * v / norm(u) / norm(v);
        return aux > 1 ? 0 : (aux < -1 ? acosl(-1) : acosl(aux));
    }

    

    template<typename T1, typename T2>
    friend double angle(const point &a, const point<T1> &b, const point<T2> &c)
    {
        return angle(a - b, c - b); 

    }

    

    friend double polar_angle(const point &v)
    {
        double ang = angle(v, point<int64_t>(1, 0));
        if(v.y > -1e-9L) 

            return ang;
        return 2*acosl(-1) - ang; 

    }

    

    template<typename T1>
    friend point<double> bisector(const point &u, const point<T1> &v)
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
    friend point<double> rotate(const point &v, const point<T1> &u, double r)
    {
        assert(abs(norm(u) - 1) < 1e-9L);
        double dot = v * u, co = cos(r), si = sin(r);
        double x = u.x * dot * (1 - co) + v.x * co + (u.y * v.z - u.z * v.y) * si;
        double y = u.y * dot * (1 - co) + v.y * co + (u.z * v.x - u.x * v.z) * si;
        double z = u.z * dot * (1 - co) + v.z * co + (u.x * v.y - u.y * v.x) * si;
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
# 3 "g.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/geo/cvhull.hpp" 1
       



template<typename T>
static bool cw(const point<T> &a, const point<T> &b, const point<T> &c)
{
    return get<2>(orientation(b-a, c-b)) == -1;
}

template<typename T>
static bool ccw(const point<T> &a, const point<T> &b, const point<T> &c)
{
    return get<2>(orientation(b-a, c-b)) == 1;
}

template<typename T>
tuple<vector<point<T> >, int64_t> convex_hull(vector<point<T> > pts){
    int64_t n = pts.size();
    if(n == 1)
        return {pts, 0};
    sort(pts.begin(), pts.end());
    point<T> p1 = pts[0], p2 = pts[n-1];
    vector<point<T> > up(1, p1), down(1, p1);
    for(int64_t i=1; i<n; ++i){
        if(i == n-1 or cw(p1, pts[i], p2)){
            while(up.size() >= 2 and !cw(up[up.size()-2], up[up.size()-1], pts[i]))
                up.pop_back();
            up.emplace_back(pts[i]);
        }
        if(i == n-1 or ccw(p1, pts[i], p2)){
            while(down.size() >= 2 and !ccw(down[down.size()-2], down[down.size()-1], pts[i]))
                down.pop_back();
            down.emplace_back(pts[i]);
        }
    }
    vector<point<T> > res;
    for(auto &p:down)
        res.emplace_back(p);
    for(int64_t i = up.size()-2; i>0; --i)
        res.emplace_back(up[i]);
    return {res, down.size()-1};
}
# 4 "g.cpp" 2

template<typename T1, typename T2>
int64_t cross(point<T1> &a, point<T2> &b){
    return (int64_t)a.x*b.y - (int64_t)a.y*b.x;
}

template<typename T1, typename T2, typename T3, typename T4>
int64_t area(point<T1> &a, point<T2> &b, point<T3> &c, point<T4> &d){
    return cross(a, b) + cross(b, c) + cross(c, d) + cross(d, a);
}

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    int64_t n;
    cin >> n;

    vector<point<int64_t> > arr(n);
    for(auto &p:arr)
        cin >> p.x >> p.y;

    auto aux = get<0>(convex_hull(arr));
    int64_t m = aux.size();

    vector<point<int32_t> > hull(aux.begin(), aux.end());
    for(int64_t i=0; i<m; ++i)
        hull.emplace_back(hull[i]);

    if(m <= 2){
        cout << fixed << setprecision(10) << 0 << "\n";
        return 0;
    }

    int64_t ans = 0;
    if(m == 3){
        for(int64_t i=0; i<n; ++i){
            bool ok = true;
            for(int64_t j=0; j<3; ++j){
                if(arr[i] == hull[j])
                    ok = false;
            }
            if(!ok)
                continue;
            ans = max(ans, area(hull[0], hull[1], hull[2], arr[i]));
            ans = max(ans, area(hull[0], hull[1], arr[i], hull[2]));
            ans = max(ans, area(hull[0], arr[i], hull[1], hull[2]));
        }
    }
    else{
        for(int64_t i=0; i<m; ++i){
            for(int64_t j=i+2; j<i+m-1; ++j){
                int64_t k = i+1;
                int64_t cur_k = area(hull[i], hull[k], hull[j], hull[j]);
                while(k+1 < j){
                    int64_t new_k = area(hull[i], hull[k+1], hull[j], hull[j]);
                    if(new_k >= cur_k){
                        k++;
                        cur_k = new_k;
                    }
                    else
                        break;
                }

                int64_t l = j+1;
                int64_t cur_l = area(hull[j], hull[l], hull[i], hull[i]);
                while(l+1 < i+m){
                    int64_t new_l = area(hull[j], hull[l+1], hull[i], hull[i]);
                    if(new_l > cur_l){
                        l++;
                        cur_l = new_l;
                    }
                    else
                        break;
                }
                ans = max(ans, cur_k + cur_l);
            }
        }
    }
    cout << fixed << setprecision(10) << ans*0.5L << "\n";
    return 0;
}
