#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double sqRadius;
} Circle;

typedef struct {
    Point x;
    Point y;
} Segment;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double squaredDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

double length(Segment s) {
    return distance(s.x, s.y);
}

double distanceToLine(Point p, Segment s) {
    double u = ((p.x - s.y.x) * (s.x.x - s.y.x) + (p.y - s.y.y) * (s.x.y - s.y.y)) / (squaredDistance(s.x, s.y));
    if (u > 1) u = 1;
    if (u < 0) u = 0;
    Point projection = {s.y.x + u * (s.x.x - s.y.x), s.y.y + u * (s.x.y - s.y.y)};
    return distance(p, projection);
}

int main() {
    double XP, YP, VP;
    scanf("%lf %lf %lf", &XP, &YP, &VP);

    double X, Y, V, R;
    scanf("%lf %lf %lf %lf", &X, &Y, &V, &R);
    Point Orig = {X, Y};
    Point Zero = {0, 0};
    Circle Forbidden = {Zero, R*R};

    double RR = sqrt(XP*XP + YP*YP);
    double init = atan2(YP, XP);

    double low = 0.0;
    double high = 1e5;
    double ans = 0.0;
    while (high - low > 1e-9) {
        double t = (low + high) / 2;
        double angle = (t * VP) / RR;
        Point New = {RR * cos(angle + init), RR * sin(angle + init)};
        Segment straight = {New, Orig};

        double dist = distanceToLine(Zero, straight);
        if (dist >= R) {
            double straightLength = length(straight);
            if (straightLength <= t * V) {
                ans = t;
                low = t;
            } else {
                high = t;
            }
        } else {
            double solve(Point a, Point b) {
                double ang1 = atan2(a.y, a.x);
                double ang2 = atan2(b.y, b.x);
                if (ang2 < ang1) ang2 += 2*M_PI;
                double ang = ang2 - ang1;
                if (ang > M_PI) ang = 2*M_PI - ang;
                return distance(Orig, a) + distance(New, b) + ang * R;
            }

            Circle id1 = {Orig, Zero};
            Circle id3 = {New, Zero};

            Point Inter1[2];
            Point Inter2[2];

            double a = id1.center.x;
            double b = id1.center.y;
            double c = Forbidden.center.x;
            double d = Forbidden.center.y;
            double r = Forbidden.sqRadius;
            double A = (a*a + b*b - c*c - d*d) / 2;
            double B = (b - d) * (b - d) + (a - c) * (a - c);
            double C = (a - c) * (a - c) + (b - d) * (b - d) - r;
            double D = B * B - 4 * A * C;
            double x1 = (-B + sqrt(D)) / (2 * A);
            double x2 = (-B - sqrt(D)) / (2 * A);
            double y1 = sqrt(r - x1 * x1);
            double y2 = sqrt(r - x2 * x2);
            Inter1[0] = (Point){x1, y1};
            Inter1[1] = (Point){x2, y2};

            a = id3.center.x;
            b = id3.center.y;
            c = Forbidden.center.x;
            d = Forbidden.center.y;
            r = Forbidden.sqRadius;
            A = (a*a + b*b - c*c - d*d) / 2;
            B = (b - d) * (b - d) + (a - c) * (a - c);
            C = (a - c) * (a - c) + (b - d) * (b - d) - r;
            D = B * B - 4 * A * C;
            x1 = (-B + sqrt(D)) / (2 * A);
            x2 = (-B - sqrt(D)) / (2 * A);
            y1 = sqrt(r - x1 * x1);
            y2 = sqrt(r - x2 * x2);
            Inter2[0] = (Point){x1, y1};
            Inter2[1] = (Point){x2, y2};

            double dist = solve(Inter1[0], Inter2[0]);
            dist = fmin(dist, solve(Inter1[0], Inter2[1]));
            dist = fmin(dist, solve(Inter1[1], Inter2[0]));
            dist = fmin(dist, solve(Inter1[1], Inter2[1]));

            if (dist <= t * V) {
                ans = t;
                low = t;
            } else {
                high = t;
            }
        }
    }

    printf("%.10lf\n", ans);
    return 0;
}
