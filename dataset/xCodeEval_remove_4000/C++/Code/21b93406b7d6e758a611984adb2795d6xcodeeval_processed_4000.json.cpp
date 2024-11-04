
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;



namespace geo {
    using datatype = double;
    const datatype PI = acos((datatype) -1);
    const datatype EPS = 1e-9;

    inline bool is_zero(const datatype a) {
        return fabs(a) < EPS;
    }

    inline bool same(const datatype a, const datatype b) {
        return fabs(a-b) < EPS;
    }

    inline int dcmp(const datatype a, const datatype b = 0) {
        return a <= b + EPS ? (a + EPS < b) ? -1 : 0 : 1;
    }

    inline datatype id9(const datatype deg) {
        return deg / 180 * PI;
    }
    inline datatype id8(const datatype rad) {
        return rad / PI * 180;
    }
}

namespace floating_2d {
    using datatype = geo::datatype;
    enum IntersectionTopology { EMPTY_SET, SINGLE_POINT, INFINITE_POINTS };

    struct vec {
        datatype x, y;

        vec() : x(0), y(0) {}
        vec(const datatype x, const datatype y) : x(x), y(y) {}
        vec(const vec p, const vec q) : x(q.x-p.x), y(q.y-p.y) {}

        inline vec  operator-()                  { return vec(-x, -y);                   }
        inline vec& operator+=(const vec rhs)    { x += rhs.x; y += rhs.y; return *this; }
        inline vec& operator-=(const vec rhs)    { x -= rhs.x; y -= rhs.y; return *this; }
        inline vec& operator*=(const datatype r) { x *= r; y *= r; return *this;         }
        inline vec& operator/=(const datatype r) { x /= r; y /= r; return *this;         }

        inline datatype norm_l1() const   { return fabs(x) + fabs(y);          };
        inline datatype norm_linf() const { return std::max(fabs(x), fabs(y)); };
        inline datatype norm() const      { return hypot(x, y);                }
        inline datatype norm2() const     { return x*x + y*y;                  }
        inline vec versor() const         { return vec(*this) /= norm();       }
    };

    inline vec operator+(vec lhs, const vec rhs)         { return lhs += rhs;   }
    inline vec operator-(vec lhs, const vec rhs)         { return lhs -= rhs;   }
    inline vec operator*(const datatype alpha, vec vec)  { return vec *= alpha; }
    inline vec operator*(vec vec, const datatype alpha)  { return vec *= alpha; }
    inline vec operator/(vec vec, const datatype alpha)  { return vec /= alpha; }

    inline bool operator==(const vec lhs, const vec rhs) {
        return geo::same(lhs.x, rhs.x) &&
               geo::same(lhs.y, rhs.y);
    }
    inline bool operator!=(const vec lhs, const vec rhs) {
        return !(lhs == rhs);
    }
    inline bool operator<(const vec lhs, const vec rhs) {
        if (geo::same(lhs.x, rhs.x)) {
            if (geo::same(lhs.y, rhs.y))
                return false;
            else
                return lhs.y < rhs.y;
        }
        return lhs.x < rhs.x;
    }
    inline bool operator>(const vec lhs, const vec rhs) {
        if (geo::same(lhs.x, rhs.x)) {
            if (geo::same(lhs.y, rhs.y))
                return false;
            else
                return lhs.y > rhs.y;
        }
        return lhs.x > rhs.x;
    }

    std::ostream& operator<<(std::ostream& os, const vec& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    inline datatype id0(const vec p, const vec q) {
        return vec(p, q).norm_l1();
    }
    inline datatype id13(const vec p, const vec q) {
        return vec(p, q).norm_linf();
    }
    inline datatype dist(const vec p, const vec q) {
        return vec(p, q).norm();
    }
    inline datatype dist2(const vec p, const vec q) {
        return vec(p, q).norm2();
    }

    inline datatype dot     (const vec u, const vec v) { return u.x*v.x + u.y*v.y; }
    inline datatype cross   (const vec u, const vec v) { return u.x*v.y - v.x*u.y; }
    inline bool     ortho   (const vec u, const vec v) { return geo::is_zero(dot(u, v));   }
    inline bool     parallel(const vec u, const vec v) { return geo::is_zero(cross(u, v)); }

    inline datatype scalar_projection(const vec v, const vec dir) {
        return dot(v, dir.versor());
    }
    inline vec vector_projection(const vec v, const vec dir) {
        return scalar_projection(v, dir) * dir;
    }

    enum CCW { RIGHT = -1, COLLINEAR = 0, LEFT = +1 };
    inline int ccw(const vec oa, const vec ob) {
        return geo::dcmp(cross(oa, ob));
    }
    inline int ccw(const vec o, const vec a, const vec b)
    {
        return ccw(vec(o, a), vec(o, b));
    }

    inline vec id5(const vec v, const datatype angle_rad)
    {
        const datatype cost = cos(angle_rad),
                       sint = sin(angle_rad);
        return vec(v.x*cost - v.y*sint, v.x*sint + v.y*cost);
    }
    inline vec cw_rotate(const vec v, const datatype angle_rad) { return id5(v, -angle_rad); }

    struct line {
        const vec origin;
        const vec unit_direction;
        

        inline bool is_horizontal() const {
            return geo::is_zero(unit_direction.y);
        }

        inline bool is_vertical() const {
            return geo::is_zero(unit_direction.x);
        }

        bool point_at_x(const datatype x, vec& pt) const {
            if (is_vertical()) {
                if (geo::same(origin.x, x)) {
                    pt = origin;
                    return true;
                } else {
                    return false;
                }
            } else {
                pt.x = x;
                pt.y = origin.y + (x - origin.x) * unit_direction.y / unit_direction.x;
                return true;
            }
        }

        bool point_at_y(const datatype y, vec& pt) const {
            if (is_horizontal()) {
                if (geo::same(origin.y, y)) {
                    pt = origin;
                    return true;
                } else {
                    return false;
                }
            } else {
                pt.x = origin.x + (y - origin.y) * unit_direction.x / unit_direction.y;
                pt.y = y;
                return true;
            }
        }

        vec point_at_x(const datatype x) const {
            vec pt;
            if (!point_at_x(x, pt))
                throw std::runtime_error("no point at x");
            return pt;
        }

        vec point_at_y(const datatype y) const {
            vec pt;
            if (!point_at_y(y, pt))
                throw std::runtime_error("no point at y");
            return pt;
        }

        inline bool contains_point(const vec p) const {
            const vec displacement = vec(origin, p);
            return parallel(displacement, unit_direction);
        }

        static line from_points(const vec p, const vec q) {
            vec direction = vec(p, q).versor();
            if (geo::is_zero(direction.x)) {
                direction.x = 0;
                direction.y = 1;
            } else if (direction.x < 0) {
                direction = -direction;
            }
            return line{p, direction};
        }

        static line from_coefficients(const datatype A, const datatype B, const datatype C) {
            

            if (geo::is_zero(B)) {
                const datatype x = -C/A;
                const vec origin{x, 0};
                const vec unit_direction{0, 1};
                return line{origin, unit_direction};
            } else {
                const datatype x1 = 1;
                const datatype y1 = (-C - A*x1)/B;
                const datatype x2 = 2;
                const datatype y2 = (-C - A*x2)/B;
                const vec origin{x1, y1};
                vec direction = vec(x2-x1, y2-y1).versor();
                if (geo::is_zero(direction.x)) {
                    direction.x = 0;
                    direction.y = 1;
                }
                return line{origin, direction};
            }
        }
    };

    inline bool operator==(const line lhs, const line rhs) {
        return lhs.unit_direction == rhs.unit_direction && lhs.contains_point(rhs.origin);
    }
    inline bool operator!=(const line lhs, const line rhs) {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const line& r) {
        os << "[ori:" << r.origin << " dir:" << r.unit_direction << "]";
        return os;
    }

    inline bool parallel(const line lhs, const line rhs) {
        return lhs.unit_direction == rhs.unit_direction;
    }
    inline IntersectionTopology id2(const line lhs, const line rhs) {
        if (lhs.unit_direction == rhs.unit_direction) {
            return lhs.contains_point(rhs.origin) ? INFINITE_POINTS : EMPTY_SET;
        } else {
            return SINGLE_POINT;
        }
    }
    inline bool intersect(const line lhs, const line rhs) {
        return id2(lhs, rhs) != EMPTY_SET;
    }
    inline vec id4(const line lhs, const line rhs) {
        if (lhs.unit_direction == rhs.unit_direction) {
            if (lhs.contains_point(rhs.origin)) {
                return rhs.origin;
            } else {
                throw std::runtime_error("lines do not intersect");
            }
        } else {
            const datatype alpha = cross(rhs.origin - lhs.origin, rhs.unit_direction) / cross(lhs.unit_direction, rhs.unit_direction);
            return lhs.origin + alpha*lhs.unit_direction;
        }
    }

    vec id10(const line r, const vec pt) {
        const vec displacement = vec(r.origin, pt);
        const vec id16 = dot(displacement, r.unit_direction) * r.unit_direction;
        return r.origin + id16;
    }

    bool id1(const line r, const vec pt, vec& pt2) {
        return r.point_at_y(pt.y, pt2);
    }

    bool id3(const line r, const vec pt, vec& pt2) {
        return r.point_at_x(pt.x, pt2);
    }

    vec id1(const line r, const vec pt) {
        return r.point_at_y(pt.y);
    }

    vec id3(const line r, const vec pt) {
        return r.point_at_x(pt.x);
    }

    inline datatype dist(const line r, const vec p) {
        const vec displacement = vec(r.origin, p);
        return abs(cross(displacement, r.unit_direction));
    }
    inline datatype dist(const vec p, const line r) {
        return dist(r, p);
    }
    inline datatype dist(const line r, const line s) {
        if (r.unit_direction == s.unit_direction) {
            return dist(r.origin, s);
        } else {
            return 0;
        }
    }

    struct segment {
        const vec p, q;
        const line supporting_line;

        segment(const vec p, const vec q) : p(p), q(q), supporting_line(line::from_points(p, q)) {}

        inline datatype left()   const { return std::min(p.x, q.x); }
        inline datatype right()  const { return std::max(p.x, q.x); }
        inline datatype bottom() const { return std::min(p.y, q.y); }
        inline datatype top()    const { return std::max(p.y, q.y); }

        inline bool is_vertical()   const { return supporting_line.is_vertical();   }
        inline bool is_horizontal() const { return supporting_line.is_horizontal(); }

        bool delimiters_point(const vec pt) const {
            

            

            

                

            

            

            

                

            

            return geo::dcmp(dot(vec(pt, p), vec(pt, q))) <= 0;
        }
        inline bool contains_point(const vec pt) const {
            return delimiters_point(pt) && supporting_line.contains_point(pt);
        }
    };

    IntersectionTopology id2(const segment lhs, const segment rhs) {
        if (lhs.supporting_line.unit_direction == rhs.supporting_line.unit_direction) {
            if (lhs.supporting_line.contains_point(rhs.supporting_line.origin)) {
                const bool id7 = lhs.delimiters_point(rhs.p);
                const bool id12 = lhs.delimiters_point(rhs.q);
                const bool id11 = rhs.delimiters_point(lhs.p);
                const bool id14 = rhs.delimiters_point(lhs.q);
                if (id7 && id12)
                    return INFINITE_POINTS;
                else if (id11 && id14)
                    return INFINITE_POINTS;
                else if (lhs.p == rhs.p || lhs.p == rhs.q || lhs.q == rhs.p || lhs.q == rhs.q)
                    return SINGLE_POINT;
                else if (id7 || id12)
                    return INFINITE_POINTS;
                else
                    return EMPTY_SET;
            } else {
                return EMPTY_SET;
            }
        } else {
            const vec candidate = id4(lhs.supporting_line, rhs.supporting_line);
            return lhs.delimiters_point(candidate) && rhs.delimiters_point(candidate) ? SINGLE_POINT : EMPTY_SET;
        }
    }
    bool intersect(const segment lhs, const segment rhs) {
        return id2(lhs, rhs) != EMPTY_SET;
    }
    vec id6(const segment lhs, const segment rhs) {
        

        if (lhs.supporting_line.unit_direction == rhs.supporting_line.unit_direction) {
            if (lhs.p == rhs.p || lhs.p == rhs.q)
                return lhs.p;
            else
                return lhs.q;
        } else {
            return id4(lhs.supporting_line, rhs.supporting_line);
        }
    }

    inline datatype dist(const segment seg, const vec pt) {
        

        const vec displacement = vec(seg.supporting_line.origin, pt);
        const vec id16 = dot(displacement, seg.supporting_line.unit_direction) * seg.supporting_line.unit_direction;
        const vec id10 = seg.supporting_line.origin + id16;
        if (seg.contains_point(id10))
            return (displacement - id10).norm();
        else
            std::min(dist(seg.p, pt), dist(seg.q, pt));
    }
    inline datatype dist(const vec pt, const segment seg) {
        return dist(seg, pt);
    }
    inline datatype dist(const segment r, const segment s) {
        const datatype d1 = dist(r.p, s.p);
        const datatype d2 = dist(r.p, s.q);
        const datatype d3 = dist(r.q, s.p);
        const datatype d4 = dist(r.q, s.q);
        return std::min(std::min(std::min(d1, d2), d3), d4);
    }

    struct triangle {
        const vec p1, p2, p3;
        triangle(const vec p1, const vec p2, const vec p3) : p1(p1), p2(p2), p3(p3) {}

        inline bool has_point_strictly_inside(const vec pt) {
            if (ccw(p1, p2, p3) == 0) return false; 

            const int s1 = ccw(p1, p2, pt);
            const int s2 = ccw(p2, p3, pt);
            const int s3 = ccw(p3, p1, pt);
            if (s1 == 0 || s2 == 0 || s3 == 0) return false; 

            return s1 == s2 && s2 == s3;
        }

        inline bool has_point_on_border(const vec p) {
            return segment(p1, p2).contains_point(p) || segment(p1, p3).contains_point(p) || segment(p2, p3).contains_point(p);
        }
    };

    


    

    inline datatype id15(const vec oa, const vec ob) {
        

        

        return atan2(fabs(cross(oa, ob)), dot(oa, ob));
    }
    inline datatype id15(const vec o, const vec a, const vec b) {
        

        return id15(vec(o, a), vec(o, b));
    }
    inline datatype id17(const vec oa, const vec ob) {
        

        

        datatype val = atan2(cross(oa, ob), dot(oa, ob));
        if (geo::dcmp(val) < 0)
            val += 2 * geo::PI;
        return val;
    }
    inline datatype id17(const vec o, const vec a, const vec b) {
        

        return id17(vec(o, a), vec(o, b));
    }
}


using namespace std;
using namespace floating_2d;

int32_t main() {
    long double a, b, c;
    cin>>a>>b>>c;
    long double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    long double dx = fabs(x1 - x2);
    long double dy = fabs(y1 - y2);
    long double ans = dx+dy;

    vec p1(x1, y1), p2(x2, y2);
    line l = line::from_coefficients(a, b, c);
    if (!l.is_vertical() && !l.is_horizontal()) {
        vector<vec> v1, v2;
        v1.push_back(id1(l, p1));
        v1.push_back(id3(l, p1));
        v2.push_back(id1(l, p2));
        v2.push_back(id3(l, p2));
        for (vec q1 : v1)
        for (vec q2 : v2)
        {
            long double dist = (q1-p1).norm() + (q2-q1).norm() + (p2-q2).norm();
            ans = min(ans, dist);
        }
    }

    cout<<fixed<<setprecision(12)<<ans<<endl;
}
