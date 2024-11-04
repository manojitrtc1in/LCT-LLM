import java.util.*;
import java.awt.geom.Point2D;

public class 1703e35d41ca5f57aec51234ba058581xcodeeval_processed_4000.json {
    static final double EPS = 1e-9;
    static final double OO = 1e18;
    static final double PI = Math.acos(-1.0);
    
    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point add(Point p) {
            return new Point(this.x + p.x, this.y + p.y);
        }

        Point sub(Point p) {
            return new Point(this.x - p.x, this.y - p.y);
        }

        Point mul(double scalar) {
            return new Point(this.x * scalar, this.y * scalar);
        }

        double length() {
            return Math.sqrt(x * x + y * y);
        }

        double lengthSqr() {
            return x * x + y * y;
        }

        double angle() {
            return Math.atan2(y, x);
        }

        Point rotate(double angle) {
            return new Point(x * Math.cos(angle) - y * Math.sin(angle), 
                             x * Math.sin(angle) + y * Math.cos(angle));
        }
    }

    static double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static Point vec(Point a, Point b) {
        return new Point(b.x - a.x, b.y - a.y);
    }

    static Point normalize(Point p) {
        double len = p.length();
        return new Point(p.x / len, p.y / len);
    }

    static double length(Point p) {
        return p.length();
    }

    static double id21(Point a, Point b, Point p) {
        if (dot(vec(a, b), vec(a, p)) < EPS)
            return length(vec(a, p));
        if (dot(vec(b, a), vec(b, p)) < EPS)
            return length(vec(b, p));
        return id13(a, b, p);
    }

    static double id13(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p))) / length(vec(a, b));
    }

    static void id1(Point cen, double r, Point p, Point[] r1, Point[] r2) {
        double lensqr = lengthSqr(vec(cen, p));
        if (Math.abs(lensqr - r * r) < EPS) {
            r1[0] = r2[0] = p;
            return;
        }
        Point cp = vec(cen, p);
        double h = length(cp);
        double a = Math.acos(r / h);
        cp = normalize(cp).mul(r);
        r1[0] = cp.rotate(a).add(cen);
        r2[0] = cp.rotate(-a).add(cen);
    }

    static double arcLength(Point a, Point b, double r) {
        double ang = a.angle() - b.angle();
        if (ang < 0) {
            ang += 2 * PI;
        }
        if (ang > PI) {
            ang = 2 * PI - ang;
        }
        return ang * r;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int Xc = scanner.nextInt();
        int Yc = scanner.nextInt();
        int Vc = scanner.nextInt();
        int Xb = scanner.nextInt();
        int Yb = scanner.nextInt();
        int Vb = scanner.nextInt();
        int r = scanner.nextInt();

        Point planet = new Point(Xc, Yc);
        Point ship = new Point(Xb, Yb);
        double R = length(planet);
        double w = Vc / R;
        double left = 0, right = 1L << 30;

        for (int i = 0; i < 300; i++) {
            double mid = (right + left) / 2;
            Point id23 = planet.rotate(w * mid);
            double distance;

            if (id21(ship, id23, new Point(0, 0)) < r) {
                Point[] a = new Point[1], b = new Point[1], c = new Point[1], d = new Point[1];
                id1(new Point(0, 0), r, ship, a, b);
                id1(new Point(0, 0), r, id23, c, d);
                distance = OO;

                distance = Math.min(distance, length(vec(ship, a[0])) + length(vec(c[0], id23)) + arcLength(a[0], c[0], r));
                distance = Math.min(distance, length(vec(ship, b[0])) + length(vec(c[0], id23)) + arcLength(b[0], c[0], r));
                distance = Math.min(distance, length(vec(ship, a[0])) + length(vec(d[0], id23)) + arcLength(a[0], d[0], r));
                distance = Math.min(distance, length(vec(ship, b[0])) + length(vec(d[0], id23)) + arcLength(b[0], d[0], r));
            } else {
                distance = length(vec(ship, id23));
            }

            if (distance / Vb < mid) {
                right = mid;
            } else {
                left = mid;
            }
        }

        System.out.printf("%.10f\n", left);
    }
}
