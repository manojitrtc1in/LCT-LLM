















template<typename T>
constexpr auto hasBegin(int) -> decltype(std::begin(std::declval<T>()), true) {
    return true;
}

constexpr bool hasBegin(...) {
    return false;
}

template<typename T>
using IsContainer = std::integral_constant<bool, hasBegin<T>(0)>;








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



















        if(!(condition)) { \
            throw std::runtime_error(std::string() + 
        }



















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

template<typename T>
inline T sq(T x) {
    return x * x;
}

template<typename T, typename SquareT = T>
struct id4 {
    T x, y;

    id4() : x(0), y(0) {
    }

    id4(T x, T y) : x(x), y(y) {
    }

    SquareT squaredDist() const {
        return static_cast<SquareT>(x) * x + static_cast<SquareT>(y) * y;
    }

    SquareT squaredDist(const id4 &rhs) const {
        return (rhs - *this).squaredDist();
    }

    auto dist() const -> decltype(sqrtl(this->squaredDist())) {
        return sqrtl(squaredDist());
    }

    auto dist(const id4 &rhs) const -> decltype(sqrtl(this->squaredDist(rhs))) {
        return sqrtl(squaredDist(rhs));
    }

    double angle() const {
        return atan2(y, x);
    }

    id4 &operator-=(const id4 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    id4 &operator+=(const id4 &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    id4 &operator*=(T rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    id4 &operator/=(T rhs) {
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
    id4<U, V> as() {
        return {U(x), U(y)};
    }

    id4 normalized() const {
        static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
        return *this / dist();
    }

    id4 rotated(double angle = pi / 2) const {
        static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
        double co = cos(angle);
        double si = sin(angle);
        return id4(x * co - y * si, x * si + y * co);
    }
};

template<typename T, typename S>
id4<T, S> operator+(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return id4<T, S>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<typename T, typename S>
id4<T, S> operator-(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return id4<T, S>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<typename T, typename S>
id4<T, S> operator*(const id4<T, S> &lhs, T rhs) {
    return id4<T, S>(lhs.x * rhs, lhs.y * rhs);
}

template<typename T, typename S>
id4<T, S> operator*(T lhs, const id4<T, S> &rhs) {
    return id4<T, S>(lhs * rhs.x, lhs * rhs.y);
}

template<typename T, typename S>
id4<T, S> operator/(const id4<T, S> &lhs, T rhs) {
    return id4<T, S>(lhs.x / rhs, lhs.y / rhs);
}

template<typename T, typename S>
S operator*(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return static_cast<S>(lhs.x) * rhs.y - static_cast<S>(rhs.x) * lhs.y;
}

template<typename T, typename S>
S operator%(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return static_cast<S>(lhs.x) * rhs.x + static_cast<S>(lhs.y) * rhs.y;
}

template<typename T, typename S>
bool operator==(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template<typename T, typename S>
bool operator!=(const id4<T, S> &lhs, const id4<T, S> &rhs) {
    return !(lhs == rhs);
}

struct LexicograficallyLess {
    template<typename T, typename S>
    bool operator()(const id4<T, S> &lhs, const id4<T, S> &rhs) const {
        return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
    };
};

template<typename T, typename S = T>
struct id2 {
    explicit id2(const id4<T> &center) : center(center) {
    }

    bool operator()(id4<T, S> lhs, id4<T, S> rhs) {
        lhs -= center;
        rhs -= center;
        if (upper(lhs) != upper(rhs)) {
            return upper(rhs);
        }
        return lhs * rhs > 0;
    }

private:
    bool upper(const id4<T> &point) {
        return point.y > 0 || (point.y == 0 && point.x > 0);
    }

    id4<T, S> center;
};

template<typename T, typename S>
double distance(const id4<T, S> &A, const id4<T, S> &B) {
    return (B - A).dist();
}

template<typename T, typename S>
double id0(const id4<T, S> &point, const id4<T, S> &b, const id4<T, S> &c) {
    static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
    auto ba = b - point;
    auto ca = c - point;
    if ((ba - ca) % ba >= 0 && (ca - ba) % ca >= 0) {
        return fabs(ba * ca) / (ca - ba).dist();
    }
    return std::min(ba.dist(), ca.dist());
};

template<typename T, typename S>
double id3(const id4<T, S> &point, const id4<T, S> &b, const id4<T, S> &c) {
    static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
    auto ba = b - point;
    auto ca = c - point;
    return fabs(ba * ca) / (ca - ba).dist();
};

template<typename T, typename S>
id4<T, S>
intersection(const id4<T, S> &a, const id4<T, S> &b, const id4<T, S> &c, const id4<T, S> &d) {
    return a + (b - a) * (((c - a) * (d - c)) / ((b - a) * (d - c)));
}







template<typename T, typename SquareT = T>
struct id1 {
    using Point = id4<T, SquareT>;

    Point O, v;

    id1() {}

    id1(Point A, Point B) : O(A), v((B - A).normalized()) {}

    SquareT side(const Point &P) const {
        return v * P - v * O;
    }

    SquareT squaredDist(const Point &P) const {
        return sq(side(P)) / v.squaredDist();
    }

    Point proj(const Point &P) const {
        static_assert(std::is_floating_point<T>::value, "only implemented for floating point types");
        return P - P.rotated() * side(P) / v.squaredDist();
    }
};

template<typename T, typename S>
id4<T, S> intersection(const id1<T, S> &A, const id1<T, S> &B) {
    id4<T, S> O = A.O, v = A.v, u = B.v.rotated();
    assert(std::abs(v % u) > 1e-20);
    S t = (B.O - O) % u / (v % u);
    return O + v * t;
}

template<typename T, typename S>
int circleLine(const id4<T, S> &o, double r, const id1<T, S> &l, std::pair<id4<T, S>, id4<T, S>> &out) {
    double h2 = r * r - l.squaredDist(o);
    if (h2 >= 0) { 

        id4<T, S> p = l.proj(o); 

        id4<T, S> h = l.v * sqrt(h2) / l.v.dist(); 

        out = {p - h, p + h};
    }
    return 1 + sign(h2);
}





template<typename T, typename = std::true_type>
struct IdentityHelper;

template<typename T>
struct IdentityHelper<T, typename std::is_arithmetic<T>::type> {
    static T identity() {
        return 1;
    }
};

template<typename T>
T identity() {
    return IdentityHelper<T>::identity();
}


template<typename T>
T gcd(T a, T b) {
    while (b) {
        T tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

template<typename T>
class Rational {
public:
    Rational() : numerator(0), denominator(1) {
    }

    Rational(T numerator) : numerator(numerator), denominator(1) {
    }

    Rational(T numerator, T denominator) : numerator(numerator), denominator(denominator) {
        SPCPPL_ASSERT(denominator != 0);
        normalize();
    }

    Rational &operator+=(const Rational &rhs) {
        return *this = *this + rhs;
    }

    Rational &operator-=(const Rational &rhs) {
        return *this = *this - rhs;
    }

    Rational &operator*=(const Rational &rhs) {
        numerator *= rhs.numerator;
        denominator *= rhs.denominator;
        normalize();
        return *this;
    }

    Rational operator-() const {
        return Rational(-numerator, denominator);
    }

    Rational &operator/=(const Rational &rhs) {
        SPCPPL_ASSERT(rhs.numerator != 0);
        numerator *= rhs.denominator;
        denominator *= rhs.numerator;
        normalize();
        return *this;
    }

    bool operator==(const Rational &rhs) const {
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    const T &getNumerator() const {
        return numerator;
    }

    const T &getDenominator() const {
        return denominator;
    }

private:
    void normalize() {
        T g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    T numerator, denominator;

    template<typename U>
    friend Rational<U> operator+(const Rational<U> &lhs, const Rational<U> &rhs);
};


template<typename T>
Rational<T> operator+(const Rational<T> &lhs, const Rational<T> &rhs) {
    T g = gcd(lhs.denominator, rhs.denominator);
    return Rational<T>(
            lhs.numerator * (rhs.denominator / g) + rhs.numerator * (lhs.denominator / g),
            lhs.denominator / g * rhs.denominator
    );
}

template<typename T>
Rational<T> operator-(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs + (-rhs);
}

template<typename T>
Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs) {
    Rational<T> copy = lhs;
    return copy *= rhs;
}

template<typename T>
Rational<T> operator/(const Rational<T> &lhs, const Rational<T> &rhs) {
    Rational<T> copy = lhs;
    return copy /= rhs;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Rational<T> &rational) {
    return stream << rational.getNumerator() << '/' << rational.getDenominator();
}

template<typename T>
struct IdentityHelper<Rational<T>> {
    static Rational<T> identity() {
        return Rational<T>(1);
    }
};

template<typename T>
bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs.getNumerator() * rhs.getDenominator() == lhs.getDenominator() * rhs.getNumerator();
}

template<typename T>
bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs.getNumerator() * rhs.getDenominator() < lhs.getDenominator() * rhs.getNumerator();
}

template<typename T>
bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) {
    return !(lhs > rhs);
}

template<typename T>
bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {
    return !(lhs < rhs);
}


using namespace std;

class ECoveredPoints {
    using Double = long long;
    using Point = id4<Double, Double>;

    struct Line {
        Point O, v;

        Line(Point A, Point B) : O(A), v(B - A) {
            Double g = __gcd(v.x, v.y);
            v /= g;
            if (v.x < 0 or (v.x == 0 and v.y < 0)) {
                v *= -1;
            }
        }
    };

    bool between(long long a, long long b, long long c) {
        if (a > b) {
            swap(a, b);
        }
        return c >= a and c <= b;
    }

    bool intersection(const Line &A, const Line &B, Point &P) {
        Point O = A.O, v = A.v, u(-B.v.y, B.v.x);
        Point num = (B.O - O) % u * v;
        Double den = v % u;
        assert(den);
        if (num.x % den or num.y % den) {
            return false;
        }
        Point t = num / den;
        P = O + t;
        return true;
    }

public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vector<long long> ax(n), ay(n), bx(n), by(n);
        map<pair<long long, long long>, set<int>> M;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            in >> ax[i] >> ay[i] >> bx[i] >> by[i];
            int dx = bx[i] - ax[i], dy = by[i] - ay[i];
            long long g = abs(__gcd(dx, dy));
            res += g + 1;
            for (int j = 0; j < i; ++j) {
                Point A(ax[i], ay[i]), B(bx[i], by[i]), C(ax[j], ay[j]), D(bx[j], by[j]), P;
                Line AB(A, B), CD(C, D);
                if (AB.v != CD.v and intersection(AB, CD, P)) {
                    long x = P.x, y = P.y;
                    if (abs(P.x - x) < eps and abs(P.y - y) < eps) {
                        if (between(ax[i], bx[i], x) and between(ay[i], by[i], y) and between(ax[j], bx[j], x) and
                            between(ay[j], by[j], y)) {
                            M[{x, y}].insert(i);
                            M[{x, y}].insert(j);
                        }
                    }
                }
            }
        }
        for (auto &item: M) {
            res -= item.second.size() - 1;
        }
        out << res << "\n";
    }

    void setup() {}
};


int main() {
    std::ios_base::sync_with_stdio(false);
    ECoveredPoints solver;
    solver.setup();
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    in.tie(nullptr);
    out << std::fixed;
    out.precision(20);
    solver.solve(in, out);
    return 0;
}
