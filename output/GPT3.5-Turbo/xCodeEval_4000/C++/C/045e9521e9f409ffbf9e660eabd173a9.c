#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

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

double ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double squaredDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

double length(Segment s) {
    return distance(s.x, s.y);
}

double distanceToSegment(Point p, Segment s) {
    double u = ((p.x - s.y.x) * (s.x.x - s.y.x) + (p.y - s.y.y) * (s.x.y - s.y.y)) / (squaredDistance(s.x, s.y));
    if (u > 1) u = 1;
    if (u < 0) u = 0;
    Point projection = {s.y.x + u * (s.x.x - s.y.x), s.y.y + u * (s.x.y - s.y.y)};
    return distance(p, projection);
}

int contains(Point p, Segment s) {
    return ccw(s.x, p, s.y) == 0 && ((p.x <= fmax(s.x.x, s.y.x) && p.x >= fmin(s.x.x, s.y.x)) && (p.y <= fmax(s.x.y, s.y.y) && p.y >= fmin(s.x.y, s.y.y)));
}

int intersect(Segment s1, Segment s2) {
    return (ccw(s1.x, s1.y, s2.x) != ccw(s1.x, s1.y, s2.y) && ccw(s2.x, s2.y, s1.x) != ccw(s2.x, s2.y, s1.y)) || contains(s2.x, s1) || contains(s2.y, s1) || contains(s1.x, s2) || contains(s1.y, s2);
}

Circle createCircle(Point center, double sqRadius) {
    Circle circle;
    circle.center = center;
    circle.sqRadius = sqRadius;
    return circle;
}

int circleContains(Point p, Circle c) {
    return squaredDistance(p, c.center) <= c.sqRadius;
}

double angle(Point a, Point b, Point c) {
    double cosAngle = ((b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y)) / (distance(a, b) * distance(a, c));
    return acos(cosAngle);
}

double solve(double XP, double YP, double VP, double X, double Y, double V, double R) {
    Point orig = {X, Y};
    Point zero = {0, 0};
    Circle forbidden = createCircle(zero, R * R);

    double RR = sqrt(XP * XP + YP * YP);
    double init = atan2(YP, XP);
    double low = 0.0;
    double high = 1e5;
    double result = 0.0;

    while (high - low > 1e-9) {
        double t = (low + high) / 2;
        double angle = (t * VP) / RR;
        Point new = {RR * cos(angle + init), RR * sin(angle + init)};
        Segment straight = {new, orig};

        double dist = distanceToSegment(zero, straight);
        if (dist >= R) {
            if (length(straight) <= t * V) {
                result = t;
                low = t;
            } else {
                high = t;
            }
        } else {
            double solve(Point a, Point b) {
                double ang1 = atan2(a.y, a.x);
                double ang2 = atan2(b.y, b.x);
                if (ang2 < ang1) ang2 += 2 * PI;
                double ang = ang2 - ang1;
                if (ang > PI) ang = 2 * PI - ang;
                return distance(orig, a) + distance(new, b) + ang * R;
            }

            Circle thales1 = createCircle(orig, zero);
            Circle thales2 = createCircle(new, zero);

            Point inter1[2];
            Point inter2[2];
            int inter1Count = 0;
            int inter2Count = 0;

            double a = thales1.center.x;
            double b = thales1.center.y;
            double c = thales1.sqRadius;
            double d = forbidden.center.x;
            double e = forbidden.center.y;
            double f = forbidden.sqRadius;

            double det = a * e * e - 2 * a * e * b + a * b * b + c * d * d - 2 * c * d * e + c * e * e - c * f;
            if (det > 0) {
                double x = (a * e - b * d + sqrt(det)) / (a * a - 2 * a * b + b * b);
                double y = (a * d - b * e + sqrt(det)) / (a * a - 2 * a * b + b * b);
                inter1[inter1Count++] = (Point){x, y};
            }

            det = a * e * e - 2 * a * e * b + a * b * b + c * d * d - 2 * c * d * e + c * e * e - c * f;
            if (det > 0) {
                double x = (a * e - b * d - sqrt(det)) / (a * a - 2 * a * b + b * b);
                double y = (a * d - b * e - sqrt(det)) / (a * a - 2 * a * b + b * b);
                inter1[inter1Count++] = (Point){x, y};
            }

            a = thales2.center.x;
            b = thales2.center.y;
            c = thales2.sqRadius;
            d = forbidden.center.x;
            e = forbidden.center.y;
            f = forbidden.sqRadius;

            det = a * e * e - 2 * a * e * b + a * b * b + c * d * d - 2 * c * d * e + c * e * e - c * f;
            if (det > 0) {
                double x = (a * e - b * d + sqrt(det)) / (a * a - 2 * a * b + b * b);
                double y = (a * d - b * e + sqrt(det)) / (a * a - 2 * a * b + b * b);
                inter2[inter2Count++] = (Point){x, y};
            }

            det = a * e * e - 2 * a * e * b + a * b * b + c * d * d - 2 * c * d * e + c * e * e - c * f;
            if (det > 0) {
                double x = (a * e - b * d - sqrt(det)) / (a * a - 2 * a * b + b * b);
                double y = (a * d - b * e - sqrt(det)) / (a * a - 2 * a * b + b * b);
                inter2[inter2Count++] = (Point){x, y};
            }

            double dist = fmin(solve(inter1[0], inter2[0]), solve(inter1[0], inter2[1]));
            dist = fmin(dist, fmin(solve(inter1[1], inter2[0]), solve(inter1[1], inter2[1])));

            if (dist <= t * V) {
                result = t;
                low = t;
            } else {
                high = t;
            }
        }
    }

    return result;
}

int main() {
    double XP, YP, VP, X, Y, V, R;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &XP, &YP, &VP, &X, &Y, &V, &R);
    double ans = solve(XP, YP, VP, X, Y, V, R);
    printf("%.10lf\n", ans);
    return 0;
}
