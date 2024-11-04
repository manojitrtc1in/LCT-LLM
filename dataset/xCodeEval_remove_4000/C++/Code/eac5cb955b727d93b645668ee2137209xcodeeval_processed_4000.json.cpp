













using namespace std;

typedef complex<double> point;






























struct line {
    double A, B, C;
    line(const point &a, const point &b) {
        A = b.Y - a.Y;
        B = a.X - b.X;
        C = A * a.X + B * a.Y;
    }
};
bool id0(const point &a, const point &b, const point &x) {
    return fabs(cross(vec(x,a), vec(x,b))) < EPS;
}
bool id27(const point &a, const point &b, const point &x) {
    return id0(a, b, x) && dot(vec(a,x),vec(a,b)) > -EPS;
}
bool id3(const point &a, const point& b, const point &x) {
    if (sqrdist(vec(a,b)) < EPS)
        return sqrdist(vec(a,x)) < EPS;
    return id27(a, b, x) && id27(b, a, x);
}
double id25(const point &a, const point&b, const point&x) {
    return cross(vec(a,b),vec(a,x)) / dist(vec(a,b));
}
point id11(const point &a, const point &b, double t) {
    return a + vec(a,b) * t;
}
point id14(const point &a, const point &b, const point &x) {
    return id11(a, b,
            dot(vec(a,b),vec(a,x)) / sqrdist(vec(a,b)));
}
double triangle_area(const point &a, const point &b, const point &c) {
    return fabs(cross(vec(a,b),vec(a,c))) / 2;
}
pair<bool, double> id15(double m1, double m2, double m3) {
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
bool id18(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    double d1 = cross(vec(a,p),vec(a,b));
    double d2 = cross(vec(a,q),vec(a,b));
    ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1 - d2) > EPS;
}
bool id20(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    line l1(a, b), l2(p, q);
    double det = l1.A * l2.B - l1.B * l2.A;
    if (fabs(det) < EPS)
        return false;
    ret = point((l1.C * l2.B - l1.B * l2.C) / det,
            (l1.A * l2.C - l2.A * l1.C) / det);
    return true;
}
bool id21(const point &a, const point &b, const point &p,
        const point &q, point &ret) {
    if (id18(a, b, p, q, ret))
        return id3(a, b, ret) && id3(p, q, ret);
    return false;
}


bool id29(const point &bl, const point &tr, const point& p) {
    return p.X >= bl.X && p.Y >= bl.Y && p.X <= tr.X && p.Y <= tr.Y;
}


bool id23(const point&a, const point&b, const point&p,
        const point &q) {
    return id3(a, b, p) || id3(a, b, q)
            || id3(p, q, a) || id3(p, q, b);
}

bool id2(const point &c1, double r1, const point &c2, double r2) {
    return sqrdist(vec(c1,c2)) >= (r1 - r2) * (r1 - r2)
            && sqrdist(vec(c1,c2)) <= (r1 + r2) * (r1 + r2);
}
void id12(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (fabs(r1 - r2) < EPS && dist(vec(c1,c2)) < EPS) {
        ret.push_back(point(0, 0));
        ret.push_back(point(0, 0));
        ret.push_back(point(0, 0));
    } else if (fabs(sqrdist(vec(c1,c2)) - (r1 - r2) * (r1 - r2)) < EPS
            || fabs(sqrdist(vec(c1,c2)) - (r1 + r2) * (r1 + r2)) < EPS) {
        if (r1 > r2)
            ret.push_back(
                    id11(c1, c2, r1 / dist(vec(c1,c2))));
        else
            ret.push_back(
                    id11(c2, c1, r2 / dist(vec(c1,c2))));
    } else if (sqrdist(vec(c1,c2)) < (r1 + r2) * (r1 + r2)
            && sqrdist(vec(c1,c2)) > (r1 - r2) * (r1 - r2)) {
        double t = acos(cosRule(dist(vec(c1,c2)),r1,r2));
        point p = id11(c1, c2, r1 / dist(vec(c1,c2)));
        ret.push_back(rotateabout(p, t, c1));
        ret.push_back(rotateabout(p, -t, c1));
    }
}
int id10(const point &c, double r, const point &p,
        vector<point> &ret) {
    if (fabs(sqrdist(vec(c,p)) - r * r) < EPS) {
        ret.push_back(p);
        return 1;
    } else if (sqrdist(vec(c,p)) > r * r) {
        double d = dist(vec(c,p));
        double t = acos(r / d);
        point x = id11(c, p, r / d);
        ret.push_back(rotateabout(x,t,c));
        ret.push_back(rotateabout(x,-t,c));
        return 2;
    } else
        return 0;
}
int id17(const point &c, double r, const point &a,
        const point &b, vector<point> &ret) {
    point p = id14(a, b, c);
    if (fabs(sqrdist(vec(c,p)) - r * r) < EPS) {
        ret.push_back(p);
        return 1;
    } else if (sqrdist(vec(c,p)) < r * r) {
        if (sqrdist(vec(c,p)) < EPS) {
            point q = a;
            if (sqrdist(vec(c,q)) < EPS)
                q = b;
            point p1 = id11(c, q, r / dist(vec(c,q)));
            point p2 = id11(c, q, -r / dist(vec(c,q)));
            ret.push_back(p1);
            ret.push_back(p2);
        } else {
            double t = acos(dist(vec(c,p)) / r);
            point q = id11(c, p, r / dist(vec(c,p)));
            ret.push_back(rotateabout(q,t,c));
            ret.push_back(rotateabout(q,-t,c));
        }
        return 2;
    } else
        return 0;
}


int id16(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (fabs(r1 - r2) < EPS) {
        if (sqrdist(vec(c1,c2)) < EPS)
            return 0;
        point p1 = id11(c1, c2, r1 / dist(vec(c1,c2)));
        point p2 = id11(c2, c1, r2 / dist(vec(c1,c2)));
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
        if (!id10(a, rc, b, cret))
            return 0;
        point p1 = cret[0];
        point p2 = cret[1];

        ret.push_back(id11(a, p1, ra / rc));
        ret.push_back(id11(a, p2, ra / rc));

        ret.push_back(id11(b, b + vec(a,p1), rb / rc));
        ret.push_back(id11(b, b + vec(a,p2), rb / rc));
        return 4;
    }
}


int id19(const point &c1, double r1, const point &c2,
        double r2, vector<point> &ret) {
    if (r2 > r1)
        id19(c2, r2, c1, r1, ret);
    double r3 = r1 + r2;
    vector<point> v1;
    id10(c1, r3, c2, v1);
    point p1, p2, p3, p4;
    p1 = id11(c1, v1[0], r1 / r3);
    p2 = id11(c1, v1[1], r1 / r3);
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
bool id6(const point &p, const point &c, double r) {
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
    point id5 = perp(vec(p1,p2));
    point id13 = perp(vec(p2,p3));
    point cen;
    id18(m1, m1 + id5, m2, m2 + id13, cen);
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
    if (!id6(P[psz], ret.first, ret.second)) {
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
double id9(const point &a, const point &b, const point &p) {
    point m = id14(a, b, p);
    if (id3(a, b, m))
        return fabs(id25(a, b, p));
    else
        return MIN(length(vec(a,p)), length(vec(b,p)));

}
bool id7(double A, double B, double C) {
    return A < B + C && B < A + C && C < A + B;
}
bool id1(double A, double B, double C) {
    return fabs(A - B) < EPS && fabs(A - C) < EPS;
}
bool id24(double A, double B, double C) {
    return fabs(A - B) < EPS || fabs(A - C) < EPS || fabs(B - C) < EPS;
}
pair<point, double> id28(double a, double b, double c) {
    if (a < EPS || b < EPS || c < EPS) {
        return make_pair(point(0, 0), 0);
    }
    point unit(1, 0);
    point p1(0, 0);
    point p2;
    p2 = point(1, 0) * b;
    double id26 = acos(cosRule(a,b,c));
    point p3;
    p3 = rotate(unit,id26) * a;
    point p4 = rotate(p2,id26/2);
    double id4 = acos(cosRule(c,b,a));
    point p5 = rotateabout(p3,id4/2,p2);
    point m;
    id18(p1, p4, p2, p5, m);
    double r = id25(p1, p2, m);
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
        if (id3(P[i], P[i + 1], a))
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
            id18(a, b, P[i], P[j], r);
            res.push_back(r);
        }

    }
}

void id8(const vector<point> &p, const vector<point> &q,
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

    vector<point> id22;
    id22.push_back(pivot);
    while (!S.empty()) {

        id22.push_back(S.top());
        S.pop();
    }
    return id22;
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
        id8(p,pp,v);
        

        

        sort_polygon(v);
        v = CH(v);







        double area = polygon_area(v);

        

        printf("%.9f\n", area);
    }

    return 0;
}
