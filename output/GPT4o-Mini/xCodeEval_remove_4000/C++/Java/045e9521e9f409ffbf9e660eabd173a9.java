import java.util.*;
import java.io.*;

class CDeliveringCarcinogen {
    static final double PI = 3.14159265358979323846;

    static class Point {
        double x, y;

        Point(double a, double b) {
            this.x = a;
            this.y = b;
        }

        double squaredDistance(Point o) {
            return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
        }

        double distance(Point o) {
            return Math.sqrt(squaredDistance(o));
        }
    }

    static class Circle {
        Point center;
        double sqRadius;

        Circle(Point c, double r) {
            this.center = c;
            this.sqRadius = r * r;
        }

        boolean contains(Point p) {
            return p.squaredDistance(center) <= sqRadius;
        }

        Point[] intersections(Circle c) {
            Point P0 = center;
            Point P1 = c.center;
            double d = P0.distance(P1);
            double a = (sqRadius - c.sqRadius + d * d) / (2 * d);
            double h = Math.sqrt(sqRadius - a * a);
            Point P2 = new Point(P1.x - P0.x, P1.y - P0.y);
            P2.x = P2.x * (a / d) + P0.x;
            P2.y = P2.y * (a / d) + P0.y;
            double x3 = P2.x + h * (P1.y - P0.y) / d;
            double y3 = P2.y - h * (P1.x - P0.x) / d;
            double x4 = P2.x - h * (P1.y - P0.y) / d;
            double y4 = P2.y + h * (P1.x - P0.x) / d;

            return new Point[]{new Point(x3, y3), new Point(x4, y4)};
        }
    }

    static class Segment {
        Point a, b;

        Segment(Point a, Point b) {
            this.a = a;
            this.b = b;
        }

        double distance(Point p) {
            double u = ((p.x - b.x) * (a.x - b.x) + (p.y - b.y) * (a.y - b.y)) / (a.squaredDistance(b));
            if (u > 1) u = 1;
            if (u < 0) u = 0;
            return p.distance(new Point(b.x + u * (a.x - b.x), b.y + u * (a.y - b.y)));
        }
    }

    static double bsld(double l, double h, DoubleFunction<Boolean> f, double p) {
        int r = 3 + (int) Math.log((h - l) / p) / Math.log(2);
        while (r-- > 0) {
            double m = (l + h) / 2;
            if (f.apply(m)) {
                h = m;
            } else {
                l = m;
            }
        }
        return (l + h) / 2;
    }

    public void solve(Scanner in, PrintWriter out) {
        double XP = in.nextDouble(), YP = in.nextDouble(), VP = in.nextDouble();
        double X = in.nextDouble(), Y = in.nextDouble(), V = in.nextDouble(), R = in.nextDouble();
        Point Orig = new Point(X, Y);
        Point Zero = new Point(0, 0);
        Circle Forbidden = new Circle(Zero, R);

        double RR = Math.sqrt(XP * XP + YP * YP);
        double init = Math.atan2(YP, XP);
        out.printf("%.10f\n", bsld(0.0, 1e5, t -> {
            double angle = (t * VP) / RR;
            Point New = new Point(RR * Math.cos(angle + init), RR * Math.sin(angle + init));
            Segment straight = new Segment(New, Orig);

            double dist = straight.distance(Zero);
            if (dist >= R) {
                return straight.distance(Zero) <= t * V;
            } else {
                double solve(Point a, Point b) {
                    double ang1 = Math.atan2(a.y, a.x);
                    double ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1) ang2 += 2 * PI;
                    double ang = ang2 - ang1;
                    if (ang > PI) ang = 2 * PI - ang;
                    return Orig.distance(a) + New.distance(b) + ang * R;
                }

                Circle id1 = new Circle(Orig, 0);
                Circle id3 = new Circle(New, 0);

                Point[] Inter1 = id1.intersections(Forbidden);
                Point[] Inter2 = id3.intersections(Forbidden);

                double dist = Math.min(solve(Inter1[0], Inter2[0]), solve(Inter1[0], Inter2[1]));
                dist = Math.min(dist, Math.min(solve(Inter1[1], Inter2[0]), solve(Inter1[1], Inter2[1])));
                return dist <= t * V;
            }
        }, 1e-9));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        CDeliveringCarcinogen solver = new CDeliveringCarcinogen();
        solver.solve(in, out);
        out.close();
    }
}
