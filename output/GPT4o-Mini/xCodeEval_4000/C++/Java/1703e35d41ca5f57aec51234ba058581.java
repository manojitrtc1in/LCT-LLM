import java.util.*;
import java.lang.Math;

class Point {
    double x, y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    double X() {
        return x;
    }

    double Y() {
        return y;
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

    double dot(Point p) {
        return this.x * p.x + this.y * p.y;
    }

    double cross(Point p) {
        return this.x * p.y - this.y * p.x;
    }

    double length() {
        return Math.hypot(this.x, this.y);
    }

    Point normalize() {
        double len = this.length();
        return new Point(this.x / len, this.y / len);
    }

    double angle() {
        return Math.atan2(this.y, this.x);
    }

    static Point rotate(Point p, double angle) {
        return new Point(p.x * Math.cos(angle) - p.y * Math.sin(angle),
                         p.x * Math.sin(angle) + p.y * Math.cos(angle));
    }

    static Point mid(Point a, Point b) {
        return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }

    static boolean same(Point a, Point b) {
        return Math.abs(a.sub(b).length()) < 1e-5;
    }
}

public class 1703e35d41ca5f57aec51234ba058581_nc {
    static final double EPS = 1e-5;
    static final double OO = 1e9;
    static final double PI = Math.acos(-1.0);

    static double arcLength(Point a, Point b, double r) {
        double angle = a.angle() - b.angle();
        if (angle < 0) {
            angle += 2 * PI;
        }
        if (angle > PI) {
            angle = 2 * PI - angle;
        }
        return angle * r;
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
        double R = planet.length();
        double w = Vc / R;
        double left = 0, right = 1L << 30;

        for (int i = 0; i < 300; i++) {
            double mid = (right + left) / 2;
            Point newPlanet = Point.rotate(planet, w * mid);
            double distance;

            if (pointSegmentDist(ship, newPlanet, new Point(0, 0)) < r) {
                Point a = new Point(0, 0), b = new Point(0, 0), c = new Point(0, 0), d = new Point(0, 0);
                tangentPoints(new Point(0, 0), r, ship, a, b);
                tangentPoints(new Point(0, 0), r, newPlanet, c, d);
                distance = OO;

                distance = Math.min(distance, ship.sub(a).length() + c.sub(newPlanet).length() + arcLength(a, c, r));
                distance = Math.min(distance, ship.sub(b).length() + c.sub(newPlanet).length() + arcLength(b, c, r));
                distance = Math.min(distance, ship.sub(a).length() + d.sub(newPlanet).length() + arcLength(a, d, r));
                distance = Math.min(distance, ship.sub(b).length() + d.sub(newPlanet).length() + arcLength(b, d, r));
            } else {
                distance = ship.sub(newPlanet).length();
            }

            if (distance / Vb < mid) {
                right = mid;
            } else {
                left = mid;
            }
        }

        System.out.printf("%.10f\n", left);
    }

    static double pointSegmentDist(Point a, Point b, Point p) {
        double d1 = a.sub(b).dot(a.sub(p));
        double d2 = b.sub(a).dot(b.sub(p));
        if (d1 > 0) return p.sub(a).length();
        if (d2 > 0) return p.sub(b).length();
        return Math.abs(a.sub(b).cross(a.sub(p))) / a.sub(b).length();
    }

    static void tangentPoints(Point cen, double r, Point p, Point r1, Point r2) {
        // Implementation of tangent points calculation
    }
}
