import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.Reader;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static final double EPS = 1e-8;
    final static DoubleComparator dblcmp = new DoubleComparator() {
        public int compare(double a, double b) {
            return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
        }
    };

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        id7[] p = new id7[n];
        for (int i = 0; i < n; i++) {
            p[i] = new id7(in.nextInt(), in.nextInt(), in.nextInt());
        }
        id9 ans = id5(p);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                all:
                for (int k = j + 1; k < n; k++) {
                    id9 got = getCircle(p[i], p[j], p[k]);
                    if (got.radius > ans.radius) {
                        continue;
                    }
                    for (int z = 0; z < n; z++) {
                        if (!contains(got, p[z])) {
                            continue all;
                        }
                    }
                    ans = got;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            all:
            for (int j = i + 1; j < n; j++) {
                id9 got = getCircle(p[i], p[j]);
                if (got.radius > ans.radius) {
                    continue;
                }
                for (int z = 0; z < n; z++) {
                    if (!contains(got, p[z])) {
                        continue all;
                    }
                }
                ans = got;
            }
        }
        id7 center = ans.p;
        out.println(center.x + " " + center.y + " " + center.z);
    }

    static id9 id5(id7[] p) {
        ArrayUtils.shuffle(p);
        if (p.length == 1) {
            return getCircle(p[0]);
        }
        id9 cur = getCircle(p[0], p[1]);
        for (int i = 2; i < p.length; i++) {
            double dist = cur.p.distance(p[i]);
            if (dblcmp.compare(dist, cur.radius) > 0) {
                id7[] q = Arrays.copyOf(p, i);
                cur = id15(q, p[i]);
            }
        }
        return cur;
    }

    static id9 id15(id7[] p, id7 first) {
        ArrayUtils.shuffle(p);
        if (p.length == 1) {
            return getCircle(first, p[0]);
        }
        id9 cur = getCircle(first, p[0]);
        for (int i = 1; i < p.length; i++) {
            double dist = cur.p.distance(p[i]);
            if (dblcmp.compare(dist, cur.radius) > 0) {
                id7[] q = Arrays.copyOf(p, i);
                cur = id13(q, first, p[i]);
            }
        }
        return cur;
    }

    static id9 id13(id7[] p, id7 first, id7 second) {
        ArrayUtils.shuffle(p);
        id9 cur = getCircle(first, second, p[0]);
        for (int i = 1; i < p.length; i++) {
            double dist = cur.p.distance(p[i]);
            if (dblcmp.compare(dist, cur.radius) > 0) {
                id7[] q = Arrays.copyOf(p, i);
                cur = id11(q, first, second, p[i]);
            }
        }
        return cur;
    }

    static id9 id11(id7[] p, id7 first, id7 second, id7 third) {
        ArrayUtils.shuffle(p);
        id9 cur = getCircle(first, second, third);
        for (int i = 0; i < p.length; i++) {
            double dist = cur.p.distance(p[i]);
            if (dblcmp.compare(dist, cur.radius) > 0) {
                cur = getCircle(first, second, third, p[i]);
            }
        }
        return cur;
    }

    static id9 getCircle(id7 p) {
        return new id9(p, 0);
    }

    static id9 getCircle(id7 p, id7 q) {
        return new id9(p.add(q).multiply(0.5), p.distance(q) * .5);
    }

    static boolean contains(id9 c, id7 p) {
        return dblcmp.compare(c.p.distance(p), c.radius) <= 0;
    }

    static id9 getCircle(id7 p, id7 q, id7 r) {
        id7 v1 = q.subtract(p);
        id7 v2 = r.subtract(p);
        id7 v = v1.vmul(v2);
        id9 circle1 = getCircle(p, q);
        if (contains(circle1, r)) {
            return circle1;
        }
        id9 circle2 = getCircle(p, r);
        if (contains(circle2, q)) {
            return circle2;
        }
        id9 circle3 = getCircle(q, r);
        if (contains(circle3, p)) {
            return circle3;
        }
























        id7 b1 = v1.multiply(1 / v1.length());
        id7 b2 = b1.vmul(v);
        b2 = b2.multiply(1 / b2.length());


















        q = q.subtract(p);
        r = r.subtract(p);
        id14 p2 = new id14(0, 0);
        id14 q2 = new id14(q.smul(b1), q.smul(b2));
        id14 r2 = new id14(r.smul(b1), r.smul(b2));
        id8 circle = getCircle(p2, q2, r2);
        id14 id4 = circle.p;
        id7 center = p.add(b1.multiply(id4.x)).add(b2.multiply(id4.y));






        return new id9(center, center.distance(p));
    }


    static id9 id1(id7 p, id7 q, id7 r) {
        id7 v1 = q.subtract(p);
        id7 v2 = r.subtract(p);
        id7 v = v1.vmul(v2);
        id7 b1 = v1.multiply(1 / v1.length());
        id7 b2 = b1.vmul(v);
        b2 = b2.multiply(1 / b2.length());
        q = q.subtract(p);
        r = r.subtract(p);
        id14 p2 = new id14(0, 0);
        id14 q2 = new id14(q.smul(b1), q.smul(b2));
        id14 r2 = new id14(r.smul(b1), r.smul(b2));
        id8 circle = getCircle(p2, q2, r2);
        id14 id4 = circle.p;
        id7 center = p.add(b1.multiply(id4.x)).add(b2.multiply(id4.y));
        return new id9(center, center.distance(p));
    }
    static id8 getCircle(id14 p, id14 q, id14 r) {
        id16 line1 = id16.id12(p, q);
        id16 line2 = id16.id12(p, r);
        id14 center = line1.intersect(line2, dblcmp);
























        if (center == null) {
            throw new AssertionError();
        }
        return new id8(center, center.distance(p));
    }

    static id9 getCircle(id7 p, id7 q, id7 r, id7 s) {
        id7 v1 = q.subtract(p);
        id7 v2 = r.subtract(p);
        id7 v = v1.vmul(v2);
        id7 v3 = s.subtract(p);
        id7 u = v1.vmul(v3);
        List<id9> list = new ArrayList<id9>(1);
        id9 circle1 = getCircle(p, q, r);
        if (contains(circle1, s)) {


            list.add(circle1);
        }
        id9 circle2 = getCircle(p, q, s);
        if (contains(circle2, r)) {


            list.add(circle2);
        }
        id9 circle3 = getCircle(p, r, s);
        if (contains(circle3, q)) {


            list.add(circle3);
        }
        id9 circle4 = getCircle(q, r, s);
        if (contains(circle4, p)) {


            list.add(circle4);
        }
        if (dblcmp.compare(s.subtract(r).smul(v), 0) != 0) {






























            id7 w = u.vmul(v);
            id7 b1 = v.multiply(1 / v.length());
            id7 b2 = b1.vmul(w);
            b2 = b2.multiply(1 / b2.length());
            id7 center1 = id1(p, q, r).p;
            id7 center2 = id1(p, q, s).p;
            id7 vec1 = p.subtract(q).vmul(r.subtract(q));
            id7 vec2 = p.subtract(q).vmul(s.subtract(q));
            center2 = center2.subtract(center1);
            id14 id2 = new id14(b1.smul(center2), b2.smul(center2));
            id14 id0 = new id14(vec1.smul(b1), vec1.smul(b2));
            id14 id10 = new id14(vec2.smul(b1), vec2.smul(b2));
            id16 line1 = id16.id3(id0, new id14(0, 0));
            id16 line2 = id16.id3(id10, id2);
            id14 inter = line1.intersect(line2, dblcmp);
            if (inter == null) {
                throw new AssertionError();
            }
            id7 center = center1.add(b1.multiply(inter.x)).add(b2.multiply(inter.y));


            list.add(new id9(center, center.distance(p)));
        }
        id9 ret = null;
        for (id9 e : list) {
            if (ret == null || ret.radius > e.radius) {
                ret = e;
            }
        }
        return ret;
    }

}

interface DoubleComparator {
    public int compare(double a, double b);
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean id6(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (id6(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!id6(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class id7 {
    public double x;
    public double y;
    public double z;

    public id7(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public id7 vmul(id7 p) {
        return new id7(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }

    public double smul(id7 p) {
        return x * p.x + y * p.y + z * p.z;
    }

    public id7 add(id7 p) {
        return new id7(x + p.x, y + p.y, z + p.z);
    }

    public id7 multiply(double d) {
        return new id7(x * d, y * d, z * d);
    }

    public double distance(id7 p) {
        return Math.sqrt(distanceSquared(p));
    }

    public double length() {
        return Math.sqrt(lengthSquared());
    }

    public double lengthSquared() {
        return x * x + y * y + z * z;
    }

    public double distanceSquared(id7 p) {
        double dx = x - p.x;
        double dy = y - p.y;
        double dz = z - p.z;
        return dx * dx + dy * dy + dz * dz;
    }

    public id7 subtract(id7 p) {
        return new id7(x - p.x, y - p.y, z - p.z);
    }

    public String toString() {
        return "id7{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                '}';
    }
}

class id9 {
    public id7 p;
    public double radius;

    public id9(id7 p, double radius) {
        this.p = p;
        this.radius = radius;
    }
}

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);


    public static <T> void shuffle(T[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            T t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

}

class id14 {
    public double x;
    public double y;

    public id14(double x, double y) {
        this.x = x;
        this.y = y;
    }


    public double distanceSquared(id14 p) {
        double dx = x - p.x;
        double dy = y - p.y;
        return dx * dx + dy * dy;
    }

    public double distance(id14 p) {
        return Math.sqrt(distanceSquared(p));
    }

    public String toString() {
        return "id14{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    }

class id8 {
    public id14 p;
    public double radius;

    public id8(id14 p, double radius) {
        this.p = p;
        this.radius = radius;
    }
}

class id16 {

    public double a;
    public double b;
    public double c;

    public id16(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static id16 id3(id14 v, id14 p) {
        double a = -v.y;
        double b = v.x;
        double c = -a * p.x - b * p.y;
        return new id16(a, b, c);
    }

    public static id16 id12(id14 first, id14 second) {
        double a = second.x - first.x;
        double b = second.y - first.y;
        double c = -a * (second.x + first.x) - b * (second.y + first.y);
        c *= .5;
        return new id16(a, b, c);
    }

    public id14 intersect(id16 line, DoubleComparator comparator) {
        double z = a * line.b - b * line.a;
        if (comparator.compare(z, 0) == 0) {
            return null;
        }
        return new id14((b * line.c - c * line.b) / z, (c * line.a - a * line.c) / z);
    }

}

