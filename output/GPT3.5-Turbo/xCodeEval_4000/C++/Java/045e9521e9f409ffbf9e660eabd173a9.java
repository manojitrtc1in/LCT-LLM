import java.io.*;
import java.util.*;

class Point<T> extends Pair<T, T> {
    public T x;
    public T y;

    public Point(T a, T b) {
        super(a, b);
        x = a;
        y = b;
    }

    public Point(Pair<T, T> p) {
        super(p.x, p.y);
        x = p.x;
        y = p.y;
    }

    public Point<T> subtract(Point<T> p) {
        return new Point<>(x - p.x, y - p.y);
    }

    public Point<T> add(Point<T> p) {
        return new Point<>(x + p.x, y + p.y);
    }

    public Point<T> multiply(T f) {
        return new Point<>(x * f, y * f);
    }

    public T squaredDistance(Point<T> o) {
        return (T) (new Segment<>(this, o).squaredLength());
    }

    public double distance(Point<T> o) {
        return (new Segment<>(this, o).length());
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
        x = a;
        y = b;
    }

    public T dx() {
        return (T) (x.x - y.x);
    }

    public T dy() {
        return (T) (x.y - y.y);
    }

    public T squaredLength() {
        return (T) (dx() * dx() + dy() * dy());
    }

    public double length() {
        return Math.sqrt(squaredLength().doubleValue());
    }

    public boolean contains(Point<T> q) {
        return collinear(x, q, y) && ((q.x <= Math.max(x.x, y.x) && q.x >= Math.min(x.x, y.x))
                && (q.y <= Math.max(x.y, y.y) && q.y >= Math.min(x.y, y.y)));
    }

    public double distance(Point<T> p) {
        double u = ((p.x - y.x) * dx() + (p.y - y.y) * dy()) / (dx() * dx() + dy() * dy());
        if (u > 1)
            u = 1;
        if (u < 0)
            u = 0;
        return new Point<>(p.x, p.y).distance(new Point<>(y.x + u * dx(), y.y + u * dy()));
    }

    public boolean intersect(Segment<T> s) {
        return (orientation(x, y, s.x) != orientation(x, y, s.y)
                && orientation(s.x, s.y, x) != orientation(s.x, s.y, y)) || contains(s.x) || contains(s.y)
                || s.contains(x) || s.contains(y);
    }
}

class Line<T> extends Pair<Point<T>, Point<T>> {
    public Point<T> x;
    public Point<T> y;

    public Line(Point<T> a, Point<T> b) {
        super(a, b);
        x = a;
        y = b;
    }

    public T dx() {
        return (T) (x.x - y.x);
    }

    public T dy() {
        return (T) (x.y - y.y);
    }

    public T c() {
        return (T) (x.y * y.x - x.x * y.y);
    }

    public double distance(Point<T> p) {
        long px = dx().longValue(), py = dy().longValue(), dL = px * px + py * py;
        return Math.abs(py * p.x - px * p.y + y.x * x.y - y.y * x.x) / Math.sqrt(dL);
    }

    public Point<Double> project(Point<T> p) {
        double u = ((p.x - y.x) * dx() + (p.y - y.y) * dy()) / (dx() * dx() + dy() * dy());
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
            double c1 = c().doubleValue(), c2 = l.c().doubleValue();
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
        center = c;
        sqRadius = r;
    }

    public boolean contains(Point<T> p) {
        return p.squaredDistance(center).compareTo(sqRadius) <= 0;
    }

    public Pair<Point<T>, Point<T>> intersections(Circle<T> c) {
        Point<T> P0 = center;
        Point<T> P1 = c.center;
        T d = P0.distance(P1);
        T a = (T) (sqRadius.doubleValue() - c.sqRadius.doubleValue() + d.doubleValue() * d.doubleValue()) / (2 * d.doubleValue());
        T h = (T) Math.sqrt(sqRadius.doubleValue() - a.doubleValue() * a.doubleValue());
        Point<T> P2 = P1.subtract(P0).multiply(a.doubleValue() / d.doubleValue()).add(P0);
        T x3 = P2.x + h.doubleValue() * (P1.y - P0.y) / d.doubleValue();
        T y3 = P2.y - h.doubleValue() * (P1.x - P0.x) / d.doubleValue();
        T x4 = P2.x - h.doubleValue() * (P1.y - P0.y) / d.doubleValue();
        T y4 = P2.y + h.doubleValue() * (P1.x - P0.x) / d.doubleValue();

        return new Pair<>(new Point<>(x3, y3), new Point<>(x4, y4));
    }

    public Point<T> invert(Point<T> t) {
        return center.add(t.subtract(center).multiply(sqRadius.doubleValue() / t.squaredDistance(center).doubleValue()));
    }
}

class Polygon<T> extends ArrayList<Point<T>> {
    public Polygon(List<Point<T>> v) {
        super(v);
    }

    public T doubleSignedArea() {
        if (isEmpty())
            return (T) Integer.valueOf(0);
        T area = (T) (back().x * front().y - back().y * front().x);
        for (int i = 0; i < size() - 1; ++i)
            area = (T) (area.doubleValue() + (get(i).x * get(i + 1).y - get(i + 1).x * get(i).y));
        return area;
    }

    public double circumference() {
        if (isEmpty())
            return (T) Integer.valueOf(0);
        double res = back().distance(front());
        for (int i = 0; i < size() - 1; ++i)
            res += get(i).distance(get(i + 1));
        return res;
    }
}

public class 045e9521e9f409ffbf9e660eabd173a9_nc {
    static final double PI = 3.14159265358979323846;

    static <T> T ccw(Point<T> a, Point<T> b, Point<T> c) {
        return (T) (b.x.doubleValue() - a.x.doubleValue()) * (c.y.doubleValue() - a.y.doubleValue())
                - (b.y.doubleValue() - a.y.doubleValue()) * (c.x.doubleValue() - a.x.doubleValue());
    }

    static <T> T area(Point<T> a, Point<T> b, Point<T> c) {
        return Math.abs(ccw(a, b, c));
    }

    static <T> double cosangle(Point<T> a, Point<T> b, Point<T> c) {
        return ((b.x.doubleValue() - a.x.doubleValue()) * (c.x.doubleValue() - a.x.doubleValue())
                + (b.y.doubleValue() - a.y.doubleValue()) * (c.y.doubleValue() - a.y.doubleValue()))
                / a.distance(b) / a.distance(c);
    }

    static <T> boolean acuteAngle(Point<T> a, Point<T> b, Point<T> c) {
        return ((b.x.doubleValue() - a.x.doubleValue()) * (c.x.doubleValue() - a.x.doubleValue())
                + (b.y.doubleValue() - a.y.doubleValue()) * (c.y.doubleValue() - a.y.doubleValue())) > 0;
    }

    static <T> boolean obtuseAngle(Point<T> a, Point<T> b, Point<T> c) {
        return ((b.x.doubleValue() - a.x.doubleValue()) * (c.x.doubleValue() - a.x.doubleValue())
                + (b.y.doubleValue() - a.y.doubleValue()) * (c.y.doubleValue() - a.y.doubleValue())) < 0;
    }

    static <T> boolean rightAngle(Point<T> a, Point<T> b, Point<T> c) {
        return ((b.x.doubleValue() - a.x.doubleValue()) * (c.x.doubleValue() - a.x.doubleValue())
                + (b.y.doubleValue() - a.y.doubleValue()) * (c.y.doubleValue() - a.y.doubleValue())) == 0;
    }

    static <T> double angle(Point<T> a, Point<T> b, Point<T> c) {
        return Math.acos(cosangle(a, b, c));
    }

    static <T> int orientation(Point<T> a, Point<T> b, Point<T> c) {
        T o = ccw(a, b, c);
        return (o.compareTo((T) Double.valueOf(1e-6)) > 0 ? 1 : (o.compareTo((T) Double.valueOf(-1e-6)) < 0 ? -1 : 0));
    }

    static <T> boolean collinear(Point<T> a, Point<T> b, Point<T> c) {
        return orientation(a, b, c) == 0;
    }

    static <T> Polygon<T> convexhull(List<Point<T>> v) {
        int N = v.size();
        List<Point<T>> w = new ArrayList<>(N + 1);
        int lo = 0;
        for (int i = 0; i < N; ++i)
            if (v.get(i).y.compareTo(v.get(lo).y) < 0
                    || (v.get(i).y.compareTo(v.get(lo).y) == 0 && v.get(i).x.compareTo(v.get(lo).x) < 0))
                lo = i;
        Point<T> o = v.get(lo);
        for (int i = 0; i < N; ++i)
            w.add(new Point<>(v.get(i).x - o.x, v.get(i).y - o.y));
        Collections.swap(w, 1, lo + 1);
        w.sort((a, b) -> {
            if (a.y.compareTo((T) Integer.valueOf(0)) == 0)
                return b.y.compareTo((T) Integer.valueOf(0)) != 0 || a.x.compareTo(b.x) < 0 ? -1 : 1;
            if (b.y.compareTo((T) Integer.valueOf(0)) == 0)
                return 1;
            T disc = (T) (a.x.doubleValue() * b.y.doubleValue() - a.y.doubleValue() * b.x.doubleValue());
            return disc.compareTo((T) Integer.valueOf(0)) > 0
                    || (disc.compareTo((T) Integer.valueOf(0)) == 0 && a.y.compareTo(b.y) < 0) ? -1 : 1;
        });
        w.set(0, w.get(N));
        int M = 1;
        for (int i = 2; i <= N; ++i) {
            while (ccw(w.get(M - 1), w.get(M), w.get(i)).compareTo((T) Integer.valueOf(0)) <= 0)
                if (M > 1)
                    --M;
                else if (i == N)
                    break;
                else
                    ++i;
            ++M;
            Collections.swap(w, M, i);
        }
        Polygon<T> res = new Polygon<>(w.subList(0, M));
        for (int i = 0; i < M; ++i)
            res.set(i, new Point<>(w.get(i + 1).x + o.x, w.get(i + 1).y + o.y));
        return res;
    }

    static class Pair<T, U> {
        public T x;
        public U y;

        public Pair(T a, U b) {
            x = a;
            y = b;
        }
    }

    static class Circle<T> {
        public Point<T> center;
        public T sqRadius;

        public Circle(Point<T> c, T r) {
            center = c;
            sqRadius = r;
        }

        public boolean contains(Point<T> p) {
            return p.squaredDistance(center).compareTo(sqRadius) <= 0;
        }

        public Pair<Point<T>, Point<T>> intersections(Circle<T> c) {
            Point<T> P0 = center;
            Point<T> P1 = c.center;
            T d = P0.distance(P1);
            T a = (T) (sqRadius.doubleValue() - c.sqRadius.doubleValue() + d.doubleValue() * d.doubleValue()) / (2 * d.doubleValue());
            T h = (T) Math.sqrt(sqRadius.doubleValue() - a.doubleValue() * a.doubleValue());
            Point<T> P2 = P1.subtract(P0).multiply(a.doubleValue() / d.doubleValue()).add(P0);
            T x3 = P2.x + h.doubleValue() * (P1.y - P0.y) / d.doubleValue();
            T y3 = P2.y - h.doubleValue() * (P1.x - P0.x) / d.doubleValue();
            T x4 = P2.x - h.doubleValue() * (P1.y - P0.y) / d.doubleValue();
            T y4 = P2.y + h.doubleValue() * (P1.x - P0.x) / d.doubleValue();

            return new Pair<>(new Point<>(x3, y3), new Point<>(x4, y4));
        }

        public Point<T> invert(Point<T> t) {
            return center.add(t.subtract(center).multiply(sqRadius.doubleValue() / t.squaredDistance(center).doubleValue()));
        }
    }

    static class CDeliveringCarcinogen {
        public void solve(InputStream in, OutputStream out) {
            Scanner sc = new Scanner(in);
            PrintWriter pw = new PrintWriter(out);

            double XP = sc.nextDouble();
            double YP = sc.nextDouble();
            double VP = sc.nextDouble();

            double X = sc.nextDouble();
            double Y = sc.nextDouble();
            double V = sc.nextDouble();
            double R = sc.nextDouble();
            Point<Double> Orig = new Point<>(X, Y);
            Point<Double> Zero = new Point<>(0.0, 0.0);
            Circle<Double> Forbidden = new Circle<>(Zero, R * R);

            double RR = Math.sqrt(XP * XP + YP * YP);
            double init = Math.atan2(YP, XP);
            pw.printf("%.10f\n", bsld(0.0, 1e5, (double t) -> {
                double angle = (t * VP) / RR;
                Point<Double> New = new Point<>(RR * Math.cos(angle + init), RR * Math.sin(angle + init));
                Segment<Double> straight = new Segment<>(New, Orig);

                double dist = straight.distance(Zero);
                if (dist >= R) {
                    return straight.length() <= t * V;
                } else {
                    double solve = 0.0;
                    Point<Double> a, b;
                    double ang1, ang2, ang;
                    Circle<Double> Thales1, Thales2;
                    Pair<Point<Double>, Point<Double>> Inter1, Inter2;

                    Thales1 = new Circle<>(Orig, Zero);
                    Thales2 = new Circle<>(New, Zero);

                    Inter1 = Thales1.intersections(Forbidden);
                    Inter2 = Thales2.intersections(Forbidden);

                    a = Inter1.x;
                    b = Inter2.x;
                    ang1 = Math.atan2(a.y, a.x);
                    ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1)
                        ang2 += 2 * PI;
                    ang = ang2 - ang1;
                    if (ang > PI)
                        ang = 2 * PI - ang;
                    solve = Orig.distance(a) + New.distance(b) + ang * R;

                    a = Inter1.x;
                    b = Inter2.y;
                    ang1 = Math.atan2(a.y, a.x);
                    ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1)
                        ang2 += 2 * PI;
                    ang = ang2 - ang1;
                    if (ang > PI)
                        ang = 2 * PI - ang;
                    solve = Math.min(solve, Orig.distance(a) + New.distance(b) + ang * R);

                    a = Inter1.y;
                    b = Inter2.x;
                    ang1 = Math.atan2(a.y, a.x);
                    ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1)
                        ang2 += 2 * PI;
                    ang = ang2 - ang1;
                    if (ang > PI)
                        ang = 2 * PI - ang;
                    solve = Math.min(solve, Orig.distance(a) + New.distance(b) + ang * R);

                    a = Inter1.y;
                    b = Inter2.y;
                    ang1 = Math.atan2(a.y, a.x);
                    ang2 = Math.atan2(b.y, b.x);
                    if (ang2 < ang1)
                        ang2 += 2 * PI;
                    ang = ang2 - ang1;
                    if (ang > PI)
                        ang = 2 * PI - ang;
                    solve = Math.min(solve, Orig.distance(a) + New.distance(b) + ang * R);

                    return solve <= t * V;
                }
            }, 1e-9));

            pw.flush();
        }

        public double bsld(double l, double h, DoublePredicate f, double p) {
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

        public double bsld(double l, double h, DoublePredicate f) {
            return bsld(l, h, f, 1e-9);
        }
    }

    public static void main(String[] args) {
        CDeliveringCarcinogen solver = new CDeliveringCarcinogen();
        solver.solve(System.in, System.out);
    }
}
