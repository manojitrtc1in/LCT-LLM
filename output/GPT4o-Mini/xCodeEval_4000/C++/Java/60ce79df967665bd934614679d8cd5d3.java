import java.util.*;
import java.io.*;

class Point {
    double x, y;

    Point() {}

    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        x = Double.parseDouble(st.nextToken());
        y = Double.parseDouble(st.nextToken());
    }

    void output() {
        System.out.printf("%.12f %.12f\n", x, y);
    }

    boolean equals(Point a) {
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }

    boolean lessThan(Point a) {
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }

    double len() {
        return Math.hypot(x, y);
    }

    double distance(Point p) {
        return Math.hypot(x - p.x, y - p.y);
    }

    Point add(Point p) {
        return new Point(x + p.x, y + p.y);
    }

    Point sub(Point p) {
        return new Point(x - p.x, y - p.y);
    }

    Point mul(double b) {
        return new Point(x * b, y * b);
    }

    double dot(Point p) {
        return x * p.x + y * p.y;
    }

    double det(Point p) {
        return x * p.y - y * p.x;
    }

    Point rotate(Point p, double angle) {
        Point v = this.sub(p);
        double c = Math.cos(angle), s = Math.sin(angle);
        return new Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
}

class Line {
    Point a, b;

    Line() {}

    Line(Point _a, Point _b) {
        a = _a;
        b = _b;
    }

    void input() throws IOException {
        a.input();
        b.input();
    }

    double length() {
        return a.distance(b);
    }

    int relation(Point p) {
        int c = dblcmp(p.sub(a).det(b.sub(a)));
        if (c < 0) return 1;
        if (c > 0) return 2;
        return 3;
    }

    boolean pointOnSeg(Point p) {
        return dblcmp(p.sub(a).det(b.sub(a))) == 0 && dblcmp(p.sub(a).dot(p.sub(b))) <= 0;
    }

    boolean parallel(Line v) {
        return dblcmp(b.sub(a).det(v.b.sub(v.a))) == 0;
    }

    Point lineProg(Point p) {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a)) / b.sub(a).len2()));
    }
}

class Circle {
    Point p;
    double r;

    Circle() {}

    Circle(Point _p, double _r) {
        p = _p;
        r = _r;
    }

    void input() throws IOException {
        p.input();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        r = Double.parseDouble(br.readLine());
    }

    void output() {
        System.out.printf("%.2f %.2f %.2f\n", p.x, p.y, r);
    }

    int relation(Point b) {
        double dst = b.distance(p);
        if (dblcmp(dst - r) < 0) return 2;
        if (dblcmp(dst - r) == 0) return 1;
        return 0;
    }

    double area() {
        return Math.PI * sqr(r);
    }

    double circumference() {
        return 2 * Math.PI * r;
    }
}

public class 60ce79df967665bd934614679d8cd5d3_nc {
    static double eps = 1e-8;
    static double pi = Math.acos(-1.0);

    static int dblcmp(double d) {
        if (Math.abs(d) < eps) return 0;
        return d > eps ? 1 : -1;
    }

    static double sqr(double x) {
        return x * x;
    }

    static double dist(Point a, Point b, Circle c) {
        Line l = new Line(a, b);
        Point p11 = new Point(), p12 = new Point();

        if (!c.pointCrossLine(l, p11, p12)) return a.distance(b);
        double rd = point(0, 0).rad(p11, p12);
        rd = Math.min(rd, 2 * pi - rd);

        double ds = a.distance(b) - p11.distance(p12) + rd * c.r;
        Line l1 = new Line(), l2 = new Line();
        c.tangentLine(a, l1, l2);
        Point[] p1 = new Point[3];
        p1[0] = l1.b;
        p1[1] = l2.b;
        c.tangentLine(b, l1, l2);
        Point[] p2 = new Point[3];
        p2[0] = l1.b;
        p2[1] = l2.b;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ds = Math.min(ds, a.distance(p1[i]) + point(0, 0).rad(p1[i], p2[j]) * c.r + b.distance(p2[j]));
            }
        }
        return ds;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double xp = Double.parseDouble(st.nextToken());
        double yp = Double.parseDouble(st.nextToken());
        double vp = Double.parseDouble(st.nextToken());
        Point p = new Point(xp, yp);
        st = new StringTokenizer(br.readLine());
        double x = Double.parseDouble(st.nextToken());
        double y = Double.parseDouble(st.nextToken());
        double v = Double.parseDouble(st.nextToken());
        double r = Double.parseDouble(st.nextToken());
        Circle c = new Circle(new Point(0, 0), r);
        double d = 2 * pi * p.distance(new Point(0, 0));
        int k = 1000;
        double low = 0, high = 1e6;

        while (k-- > 0) {
            double mid = (low + high) / 2.0;
            double s = vp * mid;
            double w = s % d;

            w = (w / d) * 2 * pi;

            Point where = p.rotate(new Point(0, 0), w);
            double md = dist(where, new Point(x, y), c);

            if (dblcmp(mid * v - md) >= 0) {
                high = mid;
            } else {
                low = mid;
            }
        }
        System.out.printf("%.12f\n", low);
    }
}
