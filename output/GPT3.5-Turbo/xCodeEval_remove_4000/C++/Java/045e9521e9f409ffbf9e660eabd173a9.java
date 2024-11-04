import java.io.*;
import java.util.*;

class Point<T> extends Pair<T, T> {
    public T x;
    public T y;

    public Point(T a, T b) {
        super(a, b);
        this.x = a;
        this.y = b;
    }

    public Point(Pair<T, T> p) {
        super(p.x, p.y);
        this.x = p.x;
        this.y = p.y;
    }

    public Point<T> subtract(Point<T> p) {
        this.x -= p.x;
        this.y -= p.y;
        return this;
    }

    public Point<T> add(Point<T> p) {
        this.x += p.x;
        this.y += p.y;
        return this;
    }

    public Point<T> multiply(T f) {
        this.x *= f;
        this.y *= f;
        return this;
    }

    public Point<T> subtract(Point<T> p) {
        Point<T> t = new Point<>(this);
        t.subtract(p);
        return t;
    }

    public Point<T> add(Point<T> p) {
        Point<T> t = new Point<>(this);
        t.add(p);
        return t;
    }

    public Point<T> multiply(T f) {
        Point<T> t = new Point<>(this);
        t.multiply(f);
        return t;
    }

    public T squaredDistance(Point<T> o) {
        return Segment.squaredLength(this, o);
    }

    public double distance(Point<T> o) {
        return Segment.length(this, o);
    }

    @Override
    public String toString() {
        return x + " " + y;
    }
}

class Segment<T> extends Pair<Point<T>, Point<T>> {
    public Point<T> x;
    public Point<T> y;

    public Segment(Point<T> a, Point<T> b) {
        super(a, b);
        this.x = a;
        this.y = b;
    }

    public T dx() {
        return x.x - y.x;
    }

    public T dy() {
        return x.y - y.y;
    }

    public T squaredLength() {
        return dx() * dx() + dy() * dy();
    }

    public double length() {
        return Math.sqrt(squaredLength());
    }

    public boolean contains(Point<T> q) {
        return collinear(x, q, y) && ((q.x <= Math.max(x.x, y.x) && q.x >= Math.min(x.x, y.x)) && (q.y <= Math.max(x.y, y.y) && q.y >= Math.min(x.y, y.y)));
    }

    public double distance(Point<T> p) {
        double u = ((p.x - y.x) * dx() + (p.y - y.y) * dy()) / (double) (dx() * dx() + dy() * dy());
        if (u > 1)
            u = 1;
        if (u < 0)
            u = 0;
        return new Point<>(p.x, p.y).distance(new Point<>(y.x + u * dx(), y.y + u * dy()));
    }

    public boolean intersect(Segment<T> s) {
        return (orientation(x, y, s.x) != orientation(x, y, s.y) && orientation(s.x, s.y, x) != orientation(s.x, s.y, y))
                || contains(s.x) || contains(s.y) || s.contains(x) || s.contains(y);
    }

    public static <T> T squaredLength(Point<T> a, Point<T> b) {
        return (T) a.squaredDistance(b);
    }

    public static <T> double length(Point<T> a, Point<T> b) {
        return a.distance(b);
    }
}

class Line<T> extends Pair<Point<T>, Point<T>> {
    public Point<T> x;
    public Point<T> y;

    public Line(Point<T> a, Point<T> b) {
        super(a, b);
        this.x = a;
        this.y = b;
    }

    public T dx() {
        return x.x - y.x;
    }

    public T dy() {
        return x.y - y.y;
    }

    public T c() {
        return x.y * y.x - x.x * y.y;
    }

    public double distance(Point<T> p) {
        long px = dx(), py = dy(), dL = px * px + py * py;
        return Math.abs(py * p.x - px * p.y + y.x * x.y - y.y * x.x) / Math.sqrt(dL);
    }

    public Point<Double> project(Point<T> p) {
        double u = ((p.x - y.x) * dx() + (p.y - y.y) * dy()) / (double) (dx() * dx() + dy() * dy());
        return new Point<>(y.x + u * dx(), y.y + u * dy());
    }

    public boolean parallel(Line<T> l) {
        return Math.abs(l.dx() * dy() - l.dy() * dx()) < 1e-6;
    }

    public Point<Double> intersection(Line<T> l) {
        double det = l.dx() * dy() - l.dy() * dx();
        if (Math.abs(det) < 1e-6)
            return new Point<>(1e300, 1e300);
        else {
            double c1 = c(), c2 = l.c();
            double x = -(c2 * dx() - l.dx() * c1) / det;
            double y = -(-l.dy() * c1 + c2 * dy()) / det;
            return new Point<>(x, y);
        }
    }
}

class Circle<T> {
    public Point<T> center;
    public T sqRadius;

    public Circle(Point<T> c, T r) {
        this.center = c;
        this.sqRadius = r;
    }

    public boolean contains(Point<T> p) {
        return p.squaredDistance(center) <= sqRadius;
    }

    public Pair<Point<T>, Point<T>> intersections(Circle<T> c) {
        Point<T> P0 = center;
        Point<T> P1 = c.center;
        T d = P0.distance(P1);
        T a = (sqRadius - c.sqRadius + d * d) / (2 * d);
        T h = Math.sqrt(sqRadius - a * a);
        Point<T> P2 = (P1.subtract(P0)).multiply(a / d).add(P0);
        T x3 = P2.x + h * (P1.y - P0.y) / d;
        T y3 = P2.y - h * (P1.x - P0.x) / d;
        T x4 = P2.x - h * (P1.y - P0.y) / d;
        T y4 = P2.y + h * (P1.x - P0.x) / d;

        return new Pair<>(new Point<>(x3, y3), new Point<>(x4, y4));
    }

    public Point<T> invert(Point<T> t) {
        return center.add(t.subtract(center).multiply(sqRadius / t.squaredDistance(center)));
    }
}

class Polygon<T> extends ArrayList<Point<T>> {
    public Polygon(List<Point<T>> v) {
        super(v);
    }

    public T doubleSignedArea() {
        if (this.isEmpty())
            return (T) Integer.valueOf(0);
        T area = back().x * front().y - back().y * front().x;
        for (int i = 0; i < this.size() - 1; ++i)
            area += (get(i).x * get(i + 1).y - get(i + 1).x * get(i).y);
        return area;
    }

    public double circumference() {
        if (this.isEmpty())
            return (T) Integer.valueOf(0);
        double res = back().distance(front());
        for (int i = 0; i < this.size() - 1; ++i)
            res += get(i).distance(get(i + 1));
        return res;
    }
}

class CDeliveringCarcinogen {
    public void solve(InputStream in, OutputStream out) {
        Scanner cin = new Scanner(in);
        PrintWriter cout = new PrintWriter(out);

        double XP = cin.nextDouble();
        double YP = cin.nextDouble();
        double VP = cin.nextDouble();

        double X = cin.nextDouble();
        double Y = cin.nextDouble();
        double V = cin.nextDouble();
        double R = cin.nextDouble();
        Point<Double> Orig = new Point<>(X, Y);
        Point<Double> Zero = new Point<>(0.0, 0.0);
        Circle<Double> Forbidden = new Circle<>(Zero, R * R);

        double RR = Math.sqrt(XP * XP + YP * YP);
        double init = Math.atan2(YP, XP);
        cout.printf("%.10f\n", bsld(0.0, 1e5, (double t) -> {
            double angle = (t * VP) / RR;
            Point<Double> New = new Point<>(RR * Math.cos(angle + init), RR * Math.sin(angle + init));
            Segment<Double> straight = new Segment<>(New, Orig);

            double dist = straight.distance(Zero);
            if (dist >= R) {
                return straight.length() <= t * V;
            } else {
                double solve = (Point<Double> a, Point<Double> b) -> {
                    double ang1 = Math.atan2(a.y, a.x);
                    double ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1)
                        ang2 += 2 * Math.PI;
                    double ang = ang2 - ang1;
                    if (ang > Math.PI)
                        ang = 2 * Math.PI - ang;
                    return Orig.distance(a) + New.distance(b) + ang * R;
                };

                Circle<Double> id1 = new Circle<>(Orig, Zero);
                Circle<Double> id3 = new Circle<>(New, Zero);

                Pair<Point<Double>, Point<Double>> Inter1 = id1.intersections(Forbidden);
                Pair<Point<Double>, Point<Double>> Inter2 = id3.intersections(Forbidden);

                double dist = Math.min(solve(Inter1.x, Inter2.x), solve(Inter1.x, Inter2.y));
                dist = Math.min(dist, Math.min(solve(Inter1.y, Inter2.x), solve(Inter1.y, Inter2.y)));
                return dist <= t * V;
            }
        }, 1e-9));
        cout.close();
    }

    public static void main(String[] args) {
        CDeliveringCarcinogen solver = new CDeliveringCarcinogen();
        solver.solve(System.in, System.out);
    }

    public static double bsld(double l, double h, DoublePredicate f, double p) {
        int r = 3 + (int) Math.log((h - l) / p) / Math.log(2);
        while (r-- > 0) {
            double m = (l + h) / 2;
            if (f.test(m))
                l = m;
            else
                h = m;
        }
        return (l + h) / 2;
    }

    public static double bsld(double l, double h, DoublePredicate f) {
        return bsld(l, h, f, 1e-9);
    }
}
