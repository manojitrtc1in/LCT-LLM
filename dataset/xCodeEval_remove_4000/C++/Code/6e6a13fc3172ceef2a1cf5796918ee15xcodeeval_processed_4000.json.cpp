



using namespace std;






typedef long long ll;
typedef string str;
typedef pair<int, int> pi;

const int INF = 1e9;
const int PI = static_cast<const int>(3.1415926535897932384626433832795);
const int MOD = 1000000007;

ld eps = 1e-6;

struct Point {
    ld x = 0, y = 0;

    Point() {}
    Point(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    Point(Point A, Point B) {
        x = B.x - A.x;
        y = B.y - A.y;
    }

    friend istream& operator >> (istream& stream, Point& P);
    friend ostream& operator << (ostream& stream, const Point& P);

    ld size() {
        return sqrt(x * x + y * y);
    }

    Point perpendicular() {
        return { -y, x };
    }

    ld dist(Point P2) {
        return sqrt((x - P2.x) * (x - P2.x) + (y - P2.y) * (y - P2.y));
    }

    void new_size(ld d) {
        ld sz = size();
        x = x / sz * d;
        y = y / sz * d;
    }

    bool arePointsEqual(Point P2) {
        return abs(x - P2.x) < eps and abs(y - P2.y) < eps;
    }

    int vectorMultiply(Point P2) {
        return y * P2.x - x * P2.y;
    }

    ld scalarMultiply(Point P2) {
        return x * P2.x + y * P2.y;
    }

    ld getAngle(Point P2) {
        return abs(atan2(vectorMultiply(P2), scalarMultiply(P2)));
    }
};

struct Line {
    ld a = 0, b = 0, c = 0;

    Line() {}
    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = B.x * A.y - A.x * B.y;
    }
    Line(ld a, ld b, ld c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Line(Point A, Line other) {
        Point B = { A.x + other.a, A.y + other.b };
        Line local = { A, B };

        a = local.a;
        b = local.b;
        c = local.c;
    }

    friend ostream& operator << (ostream& stream, const Line& l);

    ld dist(Point P) {
        return abs(a * P.x + b * P.y + c) / sqrt(a * a + b * b);
    }

    bool isOnLine(Point P) {
        return dist(P) < eps;
    }

    Point getPoint() {
        if (a == 0) {
            return { 0, -c / b };
        }

        return { -c / a, 0 };
    }

    bool isOnSameSide(Point A, Point B) {
        return (a * A.x + b * A.y + c) * (a * B.x + b * B.y + c) >= -eps;
    }

    bool areLinesEqualed(Line B) {
        ld x = a * B.b - b * B.a;
        ld y = B.c * b - c * B.b;
        ld z = c * B.a - B.c * a;

        return abs(x) < eps and abs(y) < eps and abs(z) < eps;
    }

    bool areLinesParallel (Line B) {
        ld x = a * B.b - b * B.a;

        return abs(x) < eps;
    }

    Point crossLines(Line B) {
        ld x = a * B.b - b * B.a;
        ld y = B.c * b - c * B.b;
        ld z = c * B.a - B.c * a;

        return { y / x, z / x };
    }
};

struct Ray {
    Point P, P1;
    Line l, lP;

    Ray() {};
    Ray(Point P, Point P1) {
        this->P = P;
        this->P1 = P1;

        this->l = Line(P, P1);
        this->lP = Line(P, l);
    }

    ld dist(Point P2) {
        if (lP.isOnSameSide(P2, P1)) {
            return l.dist(P2);
        }

        return P.dist(P2);
    }

    bool isOnRay(Point P2) {
        return lP.isOnSameSide(P2, P1) and l.dist(P2) < eps;
    }

    bool areRaysCrossed(Ray B) {
        if(B.l.areLinesEqualed(l)) {
            return B.lP.isOnSameSide(B.P1, P) or lP.isOnSameSide(P1, B.P);
        } else if(B.l.areLinesParallel(l))
            return false;

        Point cross = B.l.crossLines(l);
        return isOnRay(cross) and B.isOnRay(cross);
    }
};

struct Segment {
    Point P1, P2;
    Line l, id0, id1;

    Segment() {};
    Segment(Point P1, Point P2) {
        this->P1 = P1;
        this->P2 = P2;

        l = Line(P1, P2);
        id0 = Line(P1, l);
        id1 = Line(P2, l);
    }

    ld dist(Point A) {
        if(id1.isOnSameSide(P1, A) and id0.isOnSameSide(P2, A)) {
            return l.dist(A);
        }

        return min(A.dist(P1), A.dist(P2));
    }

    bool areSegmentsCrossed(Segment B) {
        return !l.isOnSameSide(B.P1, B.P2) and !B.l.isOnSameSide(P1, P2) or dist(B.P1) < eps or dist(B.P2) < eps or B.dist(P1) < eps or B.dist(P2) < eps ;
    }
};

struct Circle {
    Point P1;
    ld r;

    Circle() {};
    Circle(Point P1, ld r) {
        this->P1 = P1;
        this->r = r;
    }

    vector<Point> crossWithLine(Line L) {
        ld dist = L.dist(P1);
        if(abs(dist - r) < eps) {
            Line L2(P1, L);
            return { L.crossLines(L2) };
        } else if (dist > r) {
            return {};
        } else {
            Line L2(P1, L);
            Point P2 = L.crossLines(L2);

            Point P3(-L.b, L.a);
            P3.new_size(sqrt(r * r - dist * dist));
            return {Point(P2.x + P3.x, P2.y + P3.y), Point(P2.x - P3.x, P2.y - P3.y)};
        }
    }

    vector<Point> getTangents(Point P2) {
        ld dist = P2.dist(P1);
        if(abs(r - dist) < eps) {
            return {P2};
        } else if(dist > r) {
            ld d = P2.dist(P1);
            ld q = sqrt(d * d - r * r);
            ld x = r * q / d;
            ld z = sqrt(q * q - x * x);

            Point c(P1.x - P2.x, P1.y - P2.y);
            c.new_size(z);
            Point C(c.x + P2.x, c.y + P2.y);
            Point y(-c.y, c.x);
            y.new_size(x);
            Point Y(y.x + C.x, y.y + C.y);
            y.new_size(-x);
            Point T(y.x + C.x, y.y + C.y);
            return { Y, T };
        } else {
            return {};
        }
    }

    vector<Point> crossWithCircle(Circle c2) {


        if(P1.dist(c2.P1) > r + c2.r or P1.dist(c2.P1) + r < c2.r) {
            return {};
        } else if(P1.dist(c2.P1) + r - c2.r < eps) {
            Point p(P1.x - c2.P1.x, P1.y - c2.P1.y);
            p.new_size(P1.dist(c2.P1) + r);

            return { Point(c2.P1.x + p.x, c2.P1.y + p.y) };
        } else if(r + c2.r - P1.dist(c2.P1) < eps) {
            Point p( c2.P1.x - P1.x, c2.P1.y - P1.y);
            p.new_size(r);

            return { Point(P1.x + p.x, P1.y + p.y) };
        } else if(P1.dist(c2.P1) < r + c2.r) {
            ld y = (P1.dist(c2.P1) * P1.dist(c2.P1) + c2.r * c2.r - r * r) / (2 * P1.dist(c2.P1));
            ld x = sqrt(abs(c2.r * c2.r - y * y));


            Point p(P1.x - c2.P1.x, P1.y - c2.P1.y);
            p.new_size(y);
            Point P(p.x + c2.P1.x, p.y + c2.P1.y);
            Point c(-p.y, p.x);
            c.new_size(x);
            Point C1(c.x + P.x, c.y + P.y);
            c.new_size(-x);
            Point C2(c.x + P.x, c.y + P.y);

            return { C1, C2 };
        } else {
            ld y = (-P1.dist(c2.P1) * P1.dist(c2.P1) + c2.r * c2.r - r * r) / 2 * P1.dist(c2.P1);
            ld x = sqrt(abs(r * r - y * y));

            Point p(P1.x - c2.P1.x, P1.y - c2.P1.y);
            p.new_size(y);
            Point P(p.x + c2.P1.x, p.y + c2.P1.y);

            Point c(-p.y, p.x);
            c.new_size(x);
            Point C1(c.x + P.x, c.y + P.y);
            c.new_size(-x);
            Point C2(c.x + P.x, c.y + P.y);

            return { C1, C2 };
        }
    }
};

void id2(Circle &c1, Circle &c2) {
    if(c1.r > c2.r)
        swap(c1, c2);
}

ostream& operator << (ostream& stream, const Line& l) {
    stream << l.a << " " << l.b << " " << l.c;

    return stream;
}

istream& operator >> (istream& stream, Point& P) {
    stream >> P.x;
    stream >> P.y;

    return stream;
}

ostream& operator << (ostream& stream, const Point& P) {
    stream << P.x << " ";
    stream << P.y;

    return stream;
}

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    if(c == 'g') {
        cout << 0 << '\n';
        return;
    }

    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(s[i] == c)
            ok = false;
    }

    if(ok) {
        cout << 0 << '\n';
        return;
    }
    s += s;
    n *= 2;

    int ans = 0;
    int last_g = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'g')
            last_g = i;
        if(last_g != -1 and s[i] == c) {


            ans = max(ans, last_g - i);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(16);

    

    int t;
    cin >> t;



    fori(tt, 0, t) {
        

        solve();
    }

    return 0;
}