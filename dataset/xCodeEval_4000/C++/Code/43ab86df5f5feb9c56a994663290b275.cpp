

#include <bits/stdc++.h>







#include <type_traits>


#include <iterator>
#include <utility>

template<typename T>
constexpr auto hasBegin(int) -> decltype(std::begin(std::declval<T>()), true) {
    return true;
}

constexpr bool hasBegin(...) {
    return false;
}

template<typename T>
using IsContainer = std::integral_constant<bool, hasBegin<T>(0)>;


#ifndef JHELPER_EXAMPLE_PROJECT_IO_HPP
#define JHELPER_EXAMPLE_PROJECT_IO_HPP

#endif 


template<class X, class Y>
std::ostream &operator<<(std::ostream &os, std::pair<X, Y> const &p) {
    return os << p.first << " " << p.second;
}

template<class Ch, class Tr, class Container>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, Container const &x) {
    bool first = true;
    for (auto &y : x) {
        if (first) {
            first = false;
        } else {
            os << " ";
        }
        os << y;
    }
    return os;
}


#include <cmath>
#include <tuple>


#include <string>
#include <stdexcept>

#ifndef SPCPPL_ASSERT
#ifdef SPCPPL_DEBUG
#define SPCPPL_ASSERT(condition) \
        if(!(condition)) { \
            throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
        }
#else
#define SPCPPL_ASSERT(condition)
#endif
#endif


const double eps = 1e-9;
const double pi = acosl(-1);

template<typename T>
inline short sign(T a) {
    return (short) (a > eps) - (short) (a < -eps);
}

template<typename T, typename U>
inline short cmp(T a, U b) {
    return sign(a - b);
}

template<typename T, typename SquareT = T>
struct Point2D {
    T x, y;

    Point2D() : x(0), y(0) {
    }

    Point2D(T x, T y) : x(x), y(y) {
    }

    SquareT squaredDist() const {
        return static_cast<SquareT>(x) * x + static_cast<SquareT>(y) * y;
    }

    auto dist() const -> decltype(sqrt(this->squaredDist())) {
        return sqrt(squaredDist());
    }

    double angle() const {
        return atan2(y, x);
    }

    Point2D &operator-=(const Point2D &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Point2D &operator+=(const Point2D &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Point2D &operator*=(T rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    Point2D &operator/=(T rhs) {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    T &operator[](std::size_t i) {
        if (i == 0) {
            return x;
        }
        if (i == 1) {
            return y;
        }
        SPCPPL_ASSERT(false);
    }

    const T &operator[](std::size_t i) const {
        if (i == 0) {
            return x;
        }
        if (i == 1) {
            return y;
        }
        SPCPPL_ASSERT(false);
    }

    template<typename U, typename V = U>
    Point2D<U, V> as() {
        return {U(x), U(y)};
    }

    Point2D normalized() const {
        static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
        return *this / dist();
    }

    Point2D rotated(double angle = pi / 2) const {
        static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
        double co = cos(angle);
        double si = sin(angle);
        return Point2D(x * co - y * si, x * si + y * co);
    }
};

template<typename T, typename S>
Point2D<T, S> operator+(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return Point2D<T, S>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<typename T, typename S>
Point2D<T, S> operator-(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return Point2D<T, S>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<typename T, typename S>
Point2D<T, S> operator*(const Point2D<T, S> &lhs, T rhs) {
    return Point2D<T, S>(lhs.x * rhs, lhs.y * rhs);
}

template<typename T, typename S>
Point2D<T, S> operator*(T lhs, const Point2D<T, S> &rhs) {
    return Point2D<T, S>(lhs * rhs.x, lhs * rhs.y);
}

template<typename T, typename S>
Point2D<T, S> operator/(const Point2D<T, S> &lhs, T rhs) {
    return Point2D<T, S>(lhs.x / rhs, lhs.y / rhs);
}

template<typename T, typename S>
S operator*(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return static_cast<S>(lhs.x) * rhs.y - static_cast<S>(rhs.x) * lhs.y;
}

template<typename T, typename S>
S operator%(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return static_cast<S>(lhs.x) * rhs.x + static_cast<S>(lhs.y) * rhs.y;
}

template<typename T, typename S>
bool operator==(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template<typename T, typename S>
bool operator!=(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) {
    return !(lhs == rhs);
}

struct LexicograficallyLess {
    template<typename T, typename S>
    bool operator()(const Point2D<T, S> &lhs, const Point2D<T, S> &rhs) const {
        return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
    };
};

template<typename T, typename S = T>
struct LessByAngle {
    explicit LessByAngle(const Point2D<T> &center) : center(center) {
    }

    bool operator()(Point2D<T, S> lhs, Point2D<T, S> rhs) {
        lhs -= center;
        rhs -= center;
        if (upper(lhs) != upper(rhs)) {
            return upper(rhs);
        }
        return lhs * rhs > 0;
    }

private:
    bool upper(const Point2D<T> &point) {
        return point.y > 0 || (point.y == 0 && point.x > 0);
    }

    Point2D<T, S> center;
};

template<typename T, typename S>
double distance_to_segment(const Point2D<T, S> &point, const Point2D<T, S> &b, const Point2D<T, S> &c) {
    static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
    auto ba = b - point;
    auto ca = c - point;
    if ((ba - ca) % ba >= 0 && (ca - ba) % ca >= 0) {
        return fabs(ba * ca) / (ca - ba).dist();
    }
    return std::min(ba.dist(), ca.dist());
};

template<typename T, typename S>
double distance_to_line(const Point2D<T, S> &point, const Point2D<T, S> &b, const Point2D<T, S> &c) {
    static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
    auto ba = b - point;
    auto ca = c - point;
    return fabs(ba * ca) / (ca - ba).dist();
};

template<typename T, typename S>
Point2D<T, S>
intersection(const Point2D<T, S> &a, const Point2D<T, S> &b, const Point2D<T, S> &c, const Point2D<T, S> &d) {
    return a + (b - a) * (((c - a) * (d - c)) / ((b - a) * (d - c)));
}


















#ifndef JHELPER_EXAMPLE_PROJECT_LINE2D_HPP
#define JHELPER_EXAMPLE_PROJECT_LINE2D_HPP

#endif 


template<typename T, typename SquareT = T>
struct Line2D {
    using Point = Point2D<T, SquareT>;

    Point O, v;

    Line2D() {}

    Line2D(Point A, Point B) : O(A), v((B - A).normalized()) {}
};

template<typename T, typename S>
Point2D<T, S> intersection(const Line2D<T, S> &A, const Line2D<T, S> &B) {
    Point2D<T, S> O = A.O, v = A.v, u = B.v.rotated();
    assert(abs(v % u) > 1e-20);
    S t = (B.O - O) % u / (v % u);
    return O + v * t;
}


#include <limits>



template<typename T, typename Enable = std::true_type>
struct PositiveInfinity {
    T operator()() const;
};

template<typename T>
struct PositiveInfinity<T, typename std::is_integral<T>::type> {
    T operator()() const {
        return std::numeric_limits<T>::max();
    }
};

template<typename T>
struct PositiveInfinity<T, typename std::is_floating_point<T>::type> {
    T operator()() const {
        return std::numeric_limits<T>::infinity();
    }
};


template<typename T, typename Enable = std::true_type>
struct NegativeInfinity;

template<typename T>
struct NegativeInfinity<T, typename std::is_integral<T>::type> {
    T operator()() const {
        return std::numeric_limits<T>::min();
    }
};

template<typename T>
struct NegativeInfinity<T, typename std::is_floating_point<T>::type> {
    T operator()() const {
        static_assert(std::numeric_limits<T>::has_infinity, "");
        return -std::numeric_limits<T>::infinity();
    }
};


#ifndef JHELPER_EXAMPLE_PROJECT_HALFPLANEINTERSECTION_HPP
#define JHELPER_EXAMPLE_PROJECT_HALFPLANEINTERSECTION_HPP

#endif 


using namespace std;

template<typename T, typename SquareT = T>
class HalfPlaneIntersection {
    using Point = Point2D<T, SquareT>;
    using Line = Line2D<T, SquareT>;

public:
    bool has_positive_area(vector<Line> l, Point &ret) {
        static mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch()).count());
        shuffle(l.begin(), l.end(), rng);
        Point A = l[0].O;
        for (int i = 1; i < l.size(); i++) {
            if (cmp(0, l[i].v * (A - l[i].O)) > 0) {
                T mn = NegativeInfinity<SquareT>()();
                T mx = PositiveInfinity<SquareT>()();
                for (int j = 0; j < i; j++) {
                    if (cmp(l[j].v * l[i].v, 0) == 0) {
                        if (l[j].v % l[i].v < 0 && (l[j].O - l[i].O) % l[i].v.rotated() <= 0) {
                            return false;
                        }
                    } else {
                        Point u = l[j].v.rotated();
                        SquareT proj = (l[j].O - l[i].O) % u / (l[i].v % u);
                        if (l[i].v * l[j].v > 0) {
                            mx = min(mx, proj);
                        } else {
                            mn = max(mn, proj);
                        }
                    }
                }
                if (mn <= mx) {
                    SquareT k = 0;
                    if (not isinf(mn)) {
                        k = mn;
                    } else if (not isinf(mx)) {
                        k = mx;
                    }
                    A = l[i].O + l[i].v * k;
                } else {
                    return false;
                }
            }
        }
        ret = A;
        return true;
    }
};

using namespace std;

class FDary {
    static const int ITER = 100;
    static const int MAX = 20'000;

    using Point = Point2D<double, double>;
    using Line = Line2D<double, double>;

    vector<Line> base;
    HalfPlaneIntersection<double, double> solver;

//    void print() {
//        for (auto it: base) {
//            cerr << "(" << it.first << ", " << it.second << ") ";
//        }
//        cerr << endl;
//    }

    tuple<double, pair<double, double>, pair<double, double>> solve(const vector<int> &X, const vector<int> &Y) {
        double begin = 0, end = MAX;
        int n = X.size();
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            points[i] = Point(X[i], Y[i]);
        }
        for (int i = 0; i < n; ++i) {
            base.emplace_back(points[i], points[(i + 1) % n]);
        }
        Point A, B;
        for (int i = 0; i < ITER; ++i) {
            double mid = (begin + end) / 2;
            bool aux = check(mid, points, A, B);
            if (aux) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        double r = end + eps;
        bool aux = check(r, points, A, B);
        assert(aux);
        return {r, {A.x, A.y}, {B.x, B.y}};
    }

    bool check(double rad, const vector<Point> &poly, Point &A, Point &B) {
        int n = poly.size();
        vector<pair<Point, Point>> sides(n);
        for (int i = 0; i < n; ++i) {
            Point P = poly[i], Q = poly[(i + 1) % n], dir = (Q - P).rotated(), delta = dir.normalized() * rad;
            Point P_ = P + delta, Q_ = Q + delta;
            sides[i] = {Q_, P_};
        }
        sides.resize(2 * n);
        for (int i = 0; i < n; ++i) {
            sides[i + n] = sides[i];
        }
        vector<int> len(n);
        len[0] = -1;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            if (i) {
                len[i] = len[i - 1] - 1;
                points[i] = points[i - 1];
            }
            while (len[i] < n) {
                Point p;
                bool can = check(sides, i, i + len[i] + 1, p);
                if (can) {
                    len[i]++;
                    points[i] = p;
                } else {
                    break;
                }
            }
            if (len[i] == 0) {
                return false;
            }
            if (len[i] == n) {
                A = B = points[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = (i + len[i]) % n;
            if (len[j] >= n - len[i]) {
                A = points[i];
                B = points[j];
                return true;
            }
        }
        return false;
    }

    bool check(const vector<pair<Point, Point>> &vec, int begin, int end, Point &res) {
        assert(begin <= end);
        vector<Line> hps = base;
        while (begin < end) {
            hps.emplace_back(vec[begin].first, vec[begin].second);
            ++begin;
        }
        if (solver.has_positive_area(hps, res)) {
            return true;
        }
        return false;
    }

public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i] >> y[i];
        }
        tuple<double, pair<double, double>, pair<double, double>> res = solve(x, y);
        out << fixed << setprecision(12) << get<0>(res) << "\n";
        out << get<1>(res).first << ' ' << get<1>(res).second << "\n";
        out << get<2>(res).first << ' ' << get<2>(res).second << "\n";
    }

    void setup() {}
};


int main() {
    std::ios_base::sync_with_stdio(false);
    FDary solver;
    solver.setup();
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    in.tie(nullptr);
    out << std::fixed;
    out.precision(20);
    solver.solve(in, out);
    return 0;
}
