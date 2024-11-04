



#include <complex>

#include <cstdlib>

#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include  <stack>
using namespace std;

typedef complex<double> point;

#define EPS 1e-7
#define INF 1e9
#define PI 2*acos(0)

#define X real()
#define Y imag()
#define polar(r,t) ((r)*exp(point(0,t)))
#define length(a) hypot((a).X,(a).Y)
#define angle(a) atan2(((a).Y),((a).X))
#define sqrdist(a) (((a)*(conj(a))).real())
#define dist(a) (sqrt(sqrdist((a))))
#define rotate(a,t) ((a)*(exp(point(0,(t)))))
#define rotateabout(a,t,b) ((rotate(((a)-(b)),(t)))+(b))
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define reflect(v,M) (conj((v)/(M)) * (M))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>EPS)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<EPS)
#define cosRule(a,b,c) (((a)*(a) + (b)*(b) - (c)*(c))/(2*(a)*(b)))
#define sz(a) ((int)(a.size()))
#define mid(a,b) (((a)+(b))/point(2,0)) 

#define perp(a) (point(-(a).Y,(a).X)) 

#define perp2(a) (point((a).Y,-(a).X)) 

#define normalize(a) ((a)/length(a)) 

struct line {
    double A, B, C;
    line(const point &a, const point &b) {
        A = b.Y - a.Y;
        B = a.X - b.X;
        C = A * a.X + B * a.Y;
    }
};
bool point_on_line(const point &a, const point &b, const point &x) {
    return fabs(cross(vec(x,a), vec(x,b))) < EPS;
}
bool point_on_ray(const point &a, const point &b, const point &x) {
    return point_on_line(a, b, x) && dot(vec(a,x),vec(a,b)) > -EPS;
}
bool point_on_segment(const point &a, const point& b, const point &x) {
    if (sqrdist(vec(a,b)) < EPS)
        return sqrdist(vec(a,x)) < EPS;
    return point_on_ray(a, b, x) && point_on_ray(b, a, x);
}
double point_line_distance(const point &a, const point&b, const point&x) {
    return cross(vec(a,b),vec(a,x)) / dist(vec(a,b));
}
point point_on_line_parametric(const point &a, const point &b, double t) {
    return a + vec(a,b) * t;
}
point point_line_perpendicular(const point &a, const point &b, const point &x) {
    return point_on_line_parametric(a, b,
            dot(vec(a,b),vec(a,x)) / sqrdist(vec(a,b)));
}
double triangle_area(const point &a, const point &b, const point &c) {
    return fabs(cross(vec(a,b),vec(a,c))) / 2;
}
pair<bool, double> area_from_medians(double m1, double m2, double m3) {
    double s = (m1 + m2 + m3) / 2.0;
    double area = (4.0) * sqrt(s * (s - m1) * (s - m2) * (s - m3)) / 3.0;
    if (s * (s - m1) * (s - m2) * (s - m3) > 0)
        return make_pair(true, area);
    else
        return make_pair(false, -1);
}
double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
bool line_line_intersection(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    double d1 = cross(vec(a,p),vec(a,b));
    double d2 = cross(vec(a,q),vec(a,b));
    ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1 - d2) > EPS;
}
bool line_line_intersection_det(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    line l1(a, b), l2(p, q);
    double det = l1.A * l2.B - l1.B * l2.A;
    if (fabs(det) < EPS)
        return false;
    ret = point((l1.C * l2.B - l1.B * l2.C) / det,
            (l1.A * l2.C - l2.A * l1.C) / det);
    return true;
}
bool segment_segment_intersect(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    if (line_line_intersection(a, b, p, q, ret))
        return point_on_segment(a, b, ret) && point_on_segment(p, q, ret);
    return false;
}


bool point_in_rect(const point &bl, const point &tr, const point& p) {
    return p.X >= bl.X && p.Y >= bl.Y && p.X <= tr.X && p.Y <= tr.Y;
}


bool segment_terminal_intersect(const point&a, const point&b, const point&p,
        const point &q) {
    return point_on_segment(a, b, p) || point_on_segment(a, b, q)
            || point_on_segment(p, q, a) || point_on_segment(p, q, b);
}

bool circle_intersect(const point &c1, double r1, const point &c2, double r2) {
    return sqrdist(vec(c1,c2)) >= (r1 - r2) * (r1 - r2)
            && sqrdist(vec(c1,c2)) <= (r1 + r2) * (r1 + r2);
}
void circle_circle_intersection(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (fabs(r1 - r2) < EPS && dist(vec(c1,c2)) < EPS) {
        ret.push_back(point(0, 0));
        ret.push_back(point(0, 0));
        ret.push_back(point(0, 0));
    } else if (fabs(sqrdist(vec(c1,c2)) - (r1 - r2) * (r1 - r2)) < EPS
            || fabs(sqrdist(vec(c1,c2)) - (r1 + r2) * (r1 + r2)) < EPS) {
        if (r1 > r2)
            ret.push_back(
                    point_on_line_parametric(c1, c2, r1 / dist(vec(c1,c2))));
        else
            ret.push_back(
                    point_on_line_parametric(c2, c1, r2 / dist(vec(c1,c2))));
    } else if (sqrdist(vec(c1,c2)) < (r1 + r2) * (r1 + r2)
            && sqrdist(vec(c1,c2)) > (r1 - r2) * (r1 - r2)) {
        double t = acos(cosRule(dist(vec(c1,c2)),r1,r2));
        point p = point_on_line_parametric(c1, c2, r1 / dist(vec(c1,c2)));
        ret.push_back(rotateabout(p, t, c1));
        ret.push_back(rotateabout(p, -t, c1));
    }
}
int circle_point_tangent(const point &c, double r, const point &p,
        vector<point> &ret) {
    if (fabs(sqrdist(vec(c,p)) - r * r) < EPS) {
        ret.push_back(p);
        return 1;
    } else if (sqrdist(vec(c,p)) > r * r) {
        double d = dist(vec(c,p));
        double t = acos(r / d);
        point x = point_on_line_parametric(c, p, r / d);
        ret.push_back(rotateabout(x,t,c));
        ret.push_back(rotateabout(x,-t,c));
        return 2;
    } else
        return 0;
}
int circle_line_intersection(const point &c, double r, const point &a,
        const point &b, vector<point> &ret) {
    point p = point_line_perpendicular(a, b, c);
    if (fabs(sqrdist(vec(c,p)) - r * r) < EPS) {
        ret.push_back(p);
        return 1;
    } else if (sqrdist(vec(c,p)) < r * r) {
        if (sqrdist(vec(c,p)) < EPS) {
            point q = a;
            if (sqrdist(vec(c,q)) < EPS)
                q = b;
            point p1 = point_on_line_parametric(c, q, r / dist(vec(c,q)));
            point p2 = point_on_line_parametric(c, q, -r / dist(vec(c,q)));
            ret.push_back(p1);
            ret.push_back(p2);
        } else {
            double t = acos(dist(vec(c,p)) / r);
            point q = point_on_line_parametric(c, p, r / dist(vec(c,p)));
            ret.push_back(rotateabout(q,t,c));
            ret.push_back(rotateabout(q,-t,c));
        }
        return 2;
    } else
        return 0;
}


int circle_circle_open_belt(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (fabs(r1 - r2) < EPS) {
        if (sqrdist(vec(c1,c2)) < EPS)
            return 0;
        point p1 = point_on_line_parametric(c1, c2, r1 / dist(vec(c1,c2)));
        point p2 = point_on_line_parametric(c2, c1, r2 / dist(vec(c1,c2)));
        double t = acos(0);

        ret.push_back(rotateabout(p1,t,c1));
        ret.push_back(rotateabout(p1,-t,c1));

        ret.push_back(rotateabout(p2,t,c2));
        ret.push_back(rotateabout(p2,-t,c2));
        return 4;
    } else {
        point a = c1;
        point b = c2;
        double ra = r1;
        double rb = r2;
        if (rb > ra) {
            a = c2;
            b = c1;
            ra = r2;
            rb = r1;
        }
        double rc = ra - rb;
        vector<point> cret;
        if (!circle_point_tangent(a, rc, b, cret))
            return 0;
        point p1 = cret[0];
        point p2 = cret[1];

        ret.push_back(point_on_line_parametric(a, p1, ra / rc));
        ret.push_back(point_on_line_parametric(a, p2, ra / rc));

        ret.push_back(point_on_line_parametric(b, b + vec(a,p1), rb / rc));
        ret.push_back(point_on_line_parametric(b, b + vec(a,p2), rb / rc));
        return 4;
    }
}


int circ_circ_crossed_tangents(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (r2 > r1)
        circ_circ_crossed_tangents(c2, r2, c1, r1, ret);
    double r3 = r1 + r2;
    vector<point> v1;
    circle_point_tangent(c1, r3, c2, v1);
    point p1, p2, p3, p4;
    p1 = point_on_line_parametric(c1, v1[0], r1 / r3);
    p2 = point_on_line_parametric(c1, v1[1], r1 / r3);
    point unit1, unit2;
    unit1 = vec(p1,c1) / (r1);
    unit2 = vec(p2,c1) / (r1);
    p3 = unit1 * r2 + c2;
    p4 = unit2 * r2 + c2;
    ret.push_back(p1);
    ret.push_back(p2);
    ret.push_back(p3);
    ret.push_back(p4);
    return 4;
}
bool point_in_circ(const point &p, const point &c, double r) {
    return sqrdist(vec(p,c)) <= r * r;
}
pair<point, double> circle2(const point &p1, const point &p2) {
    point cen = mid(p1,p2);
    double r = length(vec(p1,p2)) / 2;
    return make_pair(cen, r);
}

pair<point, double> circle3(const point &p1, const point &p2, const point &p3) {
    point m1 = mid(p1,p2);
    point m2 = mid(p2,p3);
    point perp1 = perp(vec(p1,p2));
    point perp2 = perp(vec(p2,p3));
    point cen;
    line_line_intersection(m1, m1 + perp1, m2, m2 + perp2, cen);
    double r = length(vec(cen,p1));
    return make_pair(cen, r);
}
point P[110];
int psz;
point a[3];
int asz;
pair<point, double> min() {
    if (asz == 3) {
        return circle3(a[0], a[1], a[2]);
    }
    if (asz == 2 && psz == 0) {
        return circle2(a[0], a[1]);
    }
    if (psz == 0)
        return make_pair(a[0], 0);
    psz--;
    pair<point, double> ret = min();
    if (!point_in_circ(P[psz], ret.first, ret.second)) {
        a[asz++] = P[psz];
        ret = min();
        asz--;
    }
    psz++;
    return ret;
}
double MIN(double a, double b) {
    return (a > b) ? a : b;
}
double point_to_segment(const point &a, const point &b, const point &p) {
    point m = point_line_perpendicular(a, b, p);
    if (point_on_segment(a, b, m))
        return fabs(point_line_distance(a, b, p));
    else
        return MIN(length(vec(a,p)), length(vec(b,p)));

}
bool is_valid_triangle(double A, double B, double C) {
    return A < B + C && B < A + C && C < A + B;
}
bool is_equil_triangle(double A, double B, double C) {
    return fabs(A - B) < EPS && fabs(A - C) < EPS;
}
bool is_isoc_triangle(double A, double B, double C) {
    return fabs(A - B) < EPS || fabs(A - C) < EPS || fabs(B - C) < EPS;
}
pair<point, double> circle_inscribed_in_triangle(double a, double b, double c) {
    if (a < EPS || b < EPS || c < EPS) {
        return make_pair(point(0, 0), 0);
    }
    point unit(1, 0);
    point p1(0, 0);
    point p2;
    p2 = point(1, 0) * b;
    double angleP1 = acos(cosRule(a,b,c));
    point p3;
    p3 = rotate(unit,angleP1) * a;
    point p4 = rotate(p2,angleP1/2);
    double angleP2 = acos(cosRule(c,b,a));
    point p5 = rotateabout(p3,angleP2/2,p2);
    point m;
    line_line_intersection(p1, p4, p2, p5, m);
    double r = point_line_distance(p1, p2, m);
    pair<point, double> ret = make_pair(m, r);
    return ret;
}
double polygon_area(vector<point> &poly) {
    double area = 0;
    int n = (int) poly.size();
    for (int i = 0; i < n; i++)
        area += cross(poly[i],poly[(i+1)%n]);
    area = fabs(area / 2);
    return area;

}


bool inPolygon(point &a, vector<point> P) {

    int n = (int) P.size();
    if (n == 0)
        return false;
    for (int i = 0; i < n - 1; i++)
        if (point_on_segment(P[i], P[i + 1], a))
            return true;
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int j = (i + 1) % n;
        double angle = acos(
                dot(vec(a,P[i]),vec(a,P[j]))
                        / (length(vec(a,P[i])) * length(vec(a,P[j]))));
        ;
        if (cross(vec(a,P[i]),vec(a,P[i+1])) <= 0)
            sum -= angle;
        else
            sum += angle;
    }
    return fabs(sum - 2 * PI) < EPS || fabs(sum + 2 * PI) < EPS;

}


void polygon_cut(const vector<point> &P, const point &a, const point &b,
        vector<point> &res) {
    int n = (int) P.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        bool in1 = ccw(a,b,P[i]);
        bool in2 = ccw(a,b,P[j]);
        if (in1)
            res.push_back(P[i]);
        if (in1 ^ in2) {
            point r;
            line_line_intersection(a, b, P[i], P[j], r);
            res.push_back(r);
        }

    }
}

void convex_polygon_intersect(const vector<point> &p, const vector<point> &q,
        vector<point> &res) {
    res = q;
    int n = (int) p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        vector<point> temp;
        polygon_cut(res, p[i], p[j], temp);
        res = temp;
        if (res.empty()) {
            return;
        }
    }
}


point pivot(0, 0);

bool angleCmp(point a, point b) {
    if (collinear(pivot,a,b)) {
        return sqrdist(vec(pivot,a)) < sqrdist(vec(pivot,b));
    }
    return ccw(pivot,a,b);

}

vector<point> CH(vector<point> P) {

    int i, N = (int) P.size();
    int po = 0;
    for (i = 0; i < N - 1; i++)
        if (P[i].Y < P[po].Y || (P[i].Y == P[po].Y && P[i].X < P[po].X))
            po = i;
    pivot = P[po];

    sort(P.begin(), P.end(), angleCmp);

    point prev(0, 0), now(0, 0);
    stack<point> S;
    S.push(pivot);
    i = 1;
    while (i < N) {
        if (S.size() < 2) {
            S.push(P[i++]);
        } else {
            now = S.top();
            S.pop();
            prev = S.top();
            S.push(now);
            if (ccw(prev,now,P[i]))
                S.push(P[i++]);
            else
                S.pop();
        }
    }

    vector<point> ConvexHull;
    ConvexHull.push_back(pivot);
    while (!S.empty()) {

        ConvexHull.push_back(S.top());
        S.pop();
    }
    return ConvexHull;
}
void voroni(const vector<point> &pts, const vector<point> &rect,
        vector<vector<point> > &res) {
    res.clear();
    int n = sz(pts);
    for (int i = 0; i < n; i++) {
        res.push_back(rect);
        for (int j = 0; j < n; j++)
            if (i != j) {
                point p = perp(vec(pts[i],pts[j]));
                point m = mid(pts[i],pts[j]);
                vector<point> temp;
                p += m;
                polygon_cut(res.back(), m, p, temp);
                res.back() = temp;
            }
    }
}
vector<point> sort_polygon(vector<point> P) {

    int i, N = (int) P.size();
    int po = 0;
    for (i = 0; i < N - 1; i++)
        if (P[i].Y < P[po].Y || (P[i].Y == P[po].Y && P[i].X < P[po].X))
            po = i;
    pivot = P[po];

    sort(P.begin(), P.end(), angleCmp);
    return P;
}
int main() {

    double h, w, alpha;
    scanf("%lf %lf %lf", &w, &h, &alpha);
    if (alpha == 0 || alpha == 180)
        printf("%.9f\n", w * h);
    else {
        alpha = (alpha * PI) / 180;
        point p1, p2, p3, p4, pp1, pp2, pp3, pp4;
        vector<point> p;
        vector<point> pp;
        p.push_back(point(w / 2, h / 2));
        p.push_back(point(-w / 2, h / 2));
        p.push_back(point(-w / 2, -h / 2));
        p.push_back(point(w / 2, -h / 2));
        pp.push_back(rotate(p[0],alpha));
        pp.push_back(rotate(p[1],alpha));
        pp.push_back(rotate(p[2],alpha));
        pp.push_back(rotate(p[3],alpha));
        vector<point> v;
        convex_polygon_intersect(p,pp,v);
        

        

        sort_polygon(v);
        v = CH(v);







        double area = polygon_area(v);

        

        printf("%.9f\n", area);
    }

    return 0;
}
