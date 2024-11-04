import java.util.*;
import java.io.*;
import java.math.*;

class CDeliveringCarcinogen {
    static final double PI = 3.14159265358979323846;

    static class Point {
        double x, y;

        Point(double a, double b) {
            this.x = a;
            this.y = b;
        }

        double squaredDistance(Point o) {
            return (this.x - o.x) * (this.x - o.x) + (this.y - o.y) * (this.y - o.y);
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
            P2.x = P0.x + (P2.x * a / d);
            P2.y = P0.y + (P2.y * a / d);
            double x3 = P2.x + h * (P1.y - P0.y) / d;
            double y3 = P2.y - h * (P1.x - P0.x) / d;
            double x4 = P2.x - h * (P1.y - P0.y) / d;
            double y4 = P2.y + h * (P1.x - P0.x) / d;

            return new Point[]{new Point(x3, y3), new Point(x4, y4)};
        }
    }

    static double bsld(double l, double h, BiFunction<Double, Double, Boolean> f, double p) {
        int r = (int) (3 + Math.log((h - l) / p) / Math.log(2));
        while (r-- > 0) {
            double m = (l + h) / 2;
            if (f.apply(m, null)) {
                l = m;
            } else {
                h = m;
            }
        }
        return (l + h) / 2;
    }

    void solve(Scanner scanner, PrintWriter writer) {
        double XP = scanner.nextDouble();
        double YP = scanner.nextDouble();
        double VP = scanner.nextDouble();

        double X = scanner.nextDouble();
        double Y = scanner.nextDouble();
        double V = scanner.nextDouble();
        double R = scanner.nextDouble();
        Point Orig = new Point(X, Y);
        Point Zero = new Point(0, 0);
        Circle Forbidden = new Circle(Zero, R);

        double RR = Math.sqrt(XP * XP + YP * YP);
        double init = Math.atan2(YP, XP);
        writer.printf("%.10f\n", bsld(0.0, 1e5, (t, unused) -> {
            double angle = (t * VP) / RR;
            Point New = new Point(RR * Math.cos(angle + init), RR * Math.sin(angle + init));
            double dist = New.distance(Zero);
            if (dist >= R) {
                return New.distance(Orig) <= t * V;
            } else {
                BiFunction<Point, Point, Double> solve = (a, b) -> {
                    double ang1 = Math.atan2(a.y, a.x);
                    double ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1) ang2 += 2 * PI;
                    double ang = ang2 - ang1;
                    if (ang > PI) ang = 2 * PI - ang;
                    return Orig.distance(a) + New.distance(b) + ang * R;
                };

                Circle Thales1 = new Circle(Orig, 0);
                Circle Thales2 = new Circle(New, 0);

                Point[] Inter1 = Thales1.intersections(Forbidden);
                Point[] Inter2 = Thales2.intersections(Forbidden);

                double dist = Math.min(solve.apply(Inter1[0], Inter2[0]), solve.apply(Inter1[0], Inter2[1]));
                dist = Math.min(dist, Math.min(solve.apply(Inter1[1], Inter2[0]), solve.apply(Inter1[1], Inter2[1])));
                return dist <= t * V;
            }
        }, 1e-9));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        CDeliveringCarcinogen solver = new CDeliveringCarcinogen();
        solver.solve(scanner, writer);
        writer.flush();
    }
}
