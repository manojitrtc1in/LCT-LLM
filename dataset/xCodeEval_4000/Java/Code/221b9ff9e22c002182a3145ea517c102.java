import javax.annotation.processing.AbstractProcessor;
import java.io.*;
import java.lang.annotation.*;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.*;
import java.util.function.*;

import static java.lang.Math.*;

public class Main {
    public static int[] prefixFunction(String second) {
        int[] res = new int[second.length()];
        for (int i = 1; i < second.length(); ++i) {
            int j = res[i - 1];
            while (j > 0 && second.charAt(i) != second.charAt(j)) {
                j = res[j - 1];
            }
            if (second.charAt(i) == second.charAt(j)) {
                ++j;
            }
            res[i] = j;
        }
        return res;
    }

    public static int[] zFunction(String second) {
        int[] res = new int[second.length()];
        for (int i = 1, l = 0, r = 0; i < second.length(); ++i) {
            res[i] = max(min(r - i + 1, res[i - l]), 0);
            while (i + res[i] < second.length() && second.charAt(res[i]) == second.charAt(i + res[i])) {
                res[i]++;
            }
            if (i + res[i] - 1 > r) {
                l = i;
                r = i + res[i] - 1;
            }
        }
        return res;
    }

    public static Object[] reverse(Object[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            swap(arr[i], arr[arr.length - i - 1]);
        }
        return arr;
    }

    public static char[] reverse(char[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            char tmp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = tmp;
        }
        return arr;
    }

    public static int[] reverse(int[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            int tmp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = tmp;
        }
        return arr;
    }

    public static long[] reverse(long[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            long tmp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = tmp;
        }
        return arr;
    }

    public static boolean[] reverse(boolean[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            boolean tmp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = tmp;
        }
        return arr;
    }

    public static void swap(Object a, Object b) {
        Object tmp = a;
        a = b;
        b = tmp;
        tmp = null;
    }

    private static final int MAX_SIZE = 29;

    public static class Treap {
        Treap l, r;
        long cnt, sum;
        long x, y;
        boolean isReversed = false;

        public Treap(long x) {
            this.x = x;
            y = (long) Math.round(Math.random() * Integer.MAX_VALUE);
            cnt = 1;
            sum = x;
        }

        public void update() {
            cnt = 1;
            sum = x;
            if (l != null) {
                cnt += l.cnt;
                sum = l.sum + sum;
            }
            if (r != null) {
                cnt += r.cnt;
                sum = r.sum + sum;
            }
        }

        @Override
        public String toString() {
            push(this);
            String res = "";
            if (l != null) {
                res += l.toString();
            }
            res += (x + " ");
            if (r != null) {
                res += r.toString();
            }
            return res;
        }

    }

    public static long cnt(Treap t) {
        if (t == null) {
            return 0;
        }
        return t.cnt;
    }

    public static long sum(Treap t) {
        if (t == null) {
            return 0;
        }
        return t.sum;
    }

    public static void push(Treap t) {
        if (t != null) {
            if (t.isReversed) {
                Treap tmp = t.l;
                t.l = t.r;
                t.r = tmp;
                t.isReversed = false;
                if (t.l != null) {
                    t.l.isReversed ^= true;
                }
                if (t.r != null) {
                    t.r.isReversed ^= true;
                }
            }
        }
    }

    public static Treap merge(Treap a, Treap b) {
        push(a);
        push(b);
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        if (a.y > b.y) {
            a.r = merge(a.r, b);
            a.update();
            return a;
        } else {
            b.l = merge(a, b.l);
            b.update();
            return b;
        }
    }

    public static Pair<Treap, Treap> split(Treap t, long index, long add) {
        if (t == null) {
            return new Pair<Treap, Treap>(null, null);
        }
        push(t);
        if (cnt(t.l) + add >= index) {
            Pair<Treap, Treap> p = split(t.l, index, add);
            t.l = p.second;
            t.update();
            return new Pair<Treap, Treap>(p.first, t);
        } else {
            Pair<Treap, Treap> p = split(t.r, index, add + 1 + cnt(t.l));
            t.r = p.first;
            t.update();
            return new Pair<Treap, Treap>(t, p.second);
        }
    }

    public static long getsum(Treap t, long l, long r) {
        if (t == null) {
            return 0;
        }
        Pair<Treap, Treap> p2 = split(t, r, 0);
        Pair<Treap, Treap> p1 = split(p2.first, l, 0);
        if (p1.second == null) {
            t = merge(p1.first, p1.second);
            t = merge(t, p2.second);
            t.update();
            return 0;
        }
        p1.second.update();
        long res = sum(p1.second);
        t = merge(p1.first, p1.second);
        t = merge(t, p2.second);
        t.update();
        return res;
    }

    public static void reverse(Treap t, long l, long r) {
        l -= 1;
        if (t == null) {
            return;
        }
        Pair<Treap, Treap> p2 = split(t, r, 0);
        Pair<Treap, Treap> p1 = split(p2.first, l, 0);
        p1.second.isReversed ^= true;
        t = merge(p1.first, p1.second);
        t = merge(t, p2.second);
        t.update();
    }

    public static Treap add(Treap t, long index, long val) {
        index -= 1;
        Pair<Treap, Treap> p = split(t, index, 0);
        Treap res = merge(null, p.first);
        res = merge(res, new Treap(val));
        res = merge(res, p.second);
        return res;
    }


    public static boolean checkBambuk(int[] a) {
        int max = a[0];
        for (int i = 1; i < a.length; i++) {
            if (abs(a[i] - a[i - 1]) != 1) {
                return false;
            }
            max = max(max, a[i]);
        }
        System.out.println("YES");
        System.out.println(1 + " " + max);
        return true;
    }

    public static boolean check(int[] a, int y) {
        for (int i = 1; i < a.length; i++) {
            Pair<Integer, Integer> first = getCoordinate(y, a[i - 1]);
            Pair<Integer, Integer> second = getCoordinate(y, a[i]);
            if (!((abs(first.first - second.first) == 1 && abs(first.second - second.second) == 0)
                    || (abs(first.first - second.first) == 0 && abs(first.second - second.second) == 1))) {
                return false;
            }
        }
        return true;
    }

    public static Pair<Integer, Integer> getCoordinate(int y, int a) {
        a--;
        return new Pair<>(a / y, a % y);
    }

    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);
        int n = in.nextInt();
        int[] a = in.nextIntArr(n);
        if (checkBambuk(a)) {
            return;
        }
        int y = 0;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) != 1) {
                y = max(a[i], a[i - 1]) - min(a[i], a[i - 1]);
                break;
            }
        }
        if (y == 0) {
            System.out.println("NO");
            return;
        }
        if (check(a, y)) {
            System.out.println("YES");
            int x = 0;
            for (int i = 0; i < n; i++) {
                x = max(x, (a[i] - 1) / y + 1);
            }
            System.out.println(x + " " + y);
        } else {
            System.out.println("NO");
        }
    }
}

class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in), 1 << 15);
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public Integer nextInt() {
        return Integer.parseInt(next());
    }

    public Long nextLong() {
        return Long.parseLong(next());
    }

    public Double nextDouble() {
        return Double.parseDouble(next());
    }

    public Float nextFloat() {
        return Float.parseFloat(next());
    }

    public Boolean nextBoolean() {
        return Boolean.parseBoolean(next());
    }

    public int[] nextIntArr(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    public long[] nextLongArr(int n) {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    public Point2D nextPoint() {
        return new Point2D(nextDouble(), nextDouble());
    }

    public Line2D nextLine() {
        return new Line2D(nextDouble(), nextDouble(), nextDouble());
    }

    public BigInteger nextBigInteger() {
        return new BigInteger(next());
    }
}

class Pair<A, B> implements Comparable<Pair<A, B>> {
    A first;
    B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair<A, B> o) {
        Comparable a = (Comparable) first;
        Comparable b = (Comparable) second;
        return a.compareTo(o.first) == 0 ? b.compareTo(o.second) : a.compareTo(o.first);
    }

    @Override
    public String toString() {
        return "[" + first + ", " + second + ']';
    }
}

class Point2D {
    public static final Point2D ZERO = new Point2D(0.0, 0.0);

    private double x;

    public final double getX() {
        return x;
    }


    private double y;

    public final double getY() {
        return y;
    }

    private int hash = 0;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(double x1, double y1) {
        double a = getX() - x1;
        double b = getY() - y1;
        return Math.sqrt(a * a + b * b);
    }

    public double distance(Point2D point) {
        return distance(point.getX(), point.getY());
    }

    public Point2D add(double x, double y) {
        return new Point2D(
                getX() + x,
                getY() + y);
    }

    public Point2D add(Point2D point) {
        return add(point.getX(), point.getY());
    }

    public Point2D subtract(double x, double y) {
        return new Point2D(
                getX() - x,
                getY() - y);
    }

    public Point2D multiply(double factor) {
        return new Point2D(getX() * factor, getY() * factor);
    }

    public Point2D subtract(Point2D point) {
        return subtract(point.getX(), point.getY());
    }

    public Point2D normalize() {
        final double mag = magnitude();

        if (mag == 0.0) {
            return new Point2D(0.0, 0.0);
        }

        return new Point2D(
                getX() / mag,
                getY() / mag);
    }

    public Point2D midpoint(double x, double y) {
        return new Point2D(
                x + (getX() - x) / 2.0,
                y + (getY() - y) / 2.0);
    }

    public Point2D midpoint(Point2D point) {
        return midpoint(point.getX(), point.getY());
    }

    public double angle(double x, double y) {
        final double ax = getX();
        final double ay = getY();

        final double delta = (ax * x + ay * y) / Math.sqrt(
                (ax * ax + ay * ay) * (x * x + y * y));

        if (delta > 1.0) {
            return 0.0;
        }
        if (delta < -1.0) {
            return 180.0;
        }

        return Math.toDegrees(Math.acos(delta));
    }

    public double angle(Point2D point) {
        return angle(point.getX(), point.getY());
    }

    public double angle(Point2D p1, Point2D p2) {
        final double x = getX();
        final double y = getY();

        final double ax = p1.getX() - x;
        final double ay = p1.getY() - y;
        final double bx = p2.getX() - x;
        final double by = p2.getY() - y;

        final double delta = (ax * bx + ay * by) / Math.sqrt(
                (ax * ax + ay * ay) * (bx * bx + by * by));

        if (delta > 1.0) {
            return 0.0;
        }
        if (delta < -1.0) {
            return 180.0;
        }

        return Math.toDegrees(Math.acos(delta));
    }

    public double magnitude() {
        final double x = getX();
        final double y = getY();

        return Math.sqrt(x * x + y * y);
    }

    public double dotProduct(double x, double y) {
        return getX() * x + getY() * y;
    }

    public double dotProduct(Point2D vector) {
        return dotProduct(vector.getX(), vector.getY());
    }

    public Point3D crossProduct(double x, double y) {
        final double ax = getX();
        final double ay = getY();

        return new Point3D(
                0, 0, ax * y - ay * x);
    }

    public Point3D crossProduct(Point2D vector) {
        return crossProduct(vector.getX(), vector.getY());
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj instanceof Point2D) {
            Point2D other = (Point2D) obj;
            return getX() == other.getX() && getY() == other.getY();
        } else return false;
    }

    @Override
    public int hashCode() {
        if (hash == 0) {
            long bits = 7L;
            bits = 31L * bits + Double.doubleToLongBits(getX());
            bits = 31L * bits + Double.doubleToLongBits(getY());
            hash = (int) (bits ^ (bits >> 32));
        }
        return hash;
    }

    @Override
    public String toString() {
        return "Point2D [x = " + getX() + ", y = " + getY() + "]";
    }
}

class Point3D {
    public static final Point3D ZERO = new Point3D(0.0, 0.0, 0.0);

    private double x;

    public final double getX() {
        return x;
    }


    private double y;

    public final double getY() {
        return y;
    }


    private double res;

    public final double getZ() {
        return res;
    }

    private int hash = 0;

    public Point3D(double x, double y, double res) {
        this.x = x;
        this.y = y;
        this.res = res;
    }

    public double distance(double x1, double y1, double z1) {
        double a = getX() - x1;
        double b = getY() - y1;
        double c = getZ() - z1;
        return Math.sqrt(a * a + b * b + c * c);
    }

    public double distance(Point3D point) {
        return distance(point.getX(), point.getY(), point.getZ());
    }

    public Point3D add(double x, double y, double res) {
        return new Point3D(
                getX() + x,
                getY() + y,
                getZ() + res);
    }

    public Point3D add(Point3D point) {
        return add(point.getX(), point.getY(), point.getZ());
    }

    public Point3D subtract(double x, double y, double res) {
        return new Point3D(
                getX() - x,
                getY() - y,
                getZ() - res);
    }

    public Point3D subtract(Point3D point) {
        return subtract(point.getX(), point.getY(), point.getZ());
    }

    public Point3D multiply(double factor) {
        return new Point3D(getX() * factor, getY() * factor, getZ() * factor);
    }

    public Point3D normalize() {
        final double mag = magnitude();

        if (mag == 0.0) {
            return new Point3D(0.0, 0.0, 0.0);
        }

        return new Point3D(
                getX() / mag,
                getY() / mag,
                getZ() / mag);
    }

    public Point3D midpoint(double x, double y, double res) {
        return new Point3D(
                x + (getX() - x) / 2.0,
                y + (getY() - y) / 2.0,
                res + (getZ() - res) / 2.0);
    }

    public Point3D midpoint(Point3D point) {
        return midpoint(point.getX(), point.getY(), point.getZ());
    }

    public double angle(double x, double y, double res) {
        final double ax = getX();
        final double ay = getY();
        final double az = getZ();

        final double delta = (ax * x + ay * y + az * res) / Math.sqrt(
                (ax * ax + ay * ay + az * az) * (x * x + y * y + res * res));

        if (delta > 1.0) {
            return 0.0;
        }
        if (delta < -1.0) {
            return 180.0;
        }

        return Math.toDegrees(Math.acos(delta));
    }

    public double angle(Point3D point) {
        return angle(point.getX(), point.getY(), point.getZ());
    }

    public double angle(Point3D p1, Point3D p2) {
        final double x = getX();
        final double y = getY();
        final double res = getZ();

        final double ax = p1.getX() - x;
        final double ay = p1.getY() - y;
        final double az = p1.getZ() - res;
        final double bx = p2.getX() - x;
        final double by = p2.getY() - y;
        final double bz = p2.getZ() - res;

        final double delta = (ax * bx + ay * by + az * bz) / Math.sqrt(
                (ax * ax + ay * ay + az * az) * (bx * bx + by * by + bz * bz));

        if (delta > 1.0) {
            return 0.0;
        }
        if (delta < -1.0) {
            return 180.0;
        }

        return Math.toDegrees(Math.acos(delta));
    }

    public double magnitude() {
        final double x = getX();
        final double y = getY();
        final double res = getZ();

        return Math.sqrt(x * x + y * y + res * res);
    }

    public double dotProduct(double x, double y, double res) {
        return getX() * x + getY() * y + getZ() * res;
    }

    public double dotProduct(Point3D vector) {
        return dotProduct(vector.getX(), vector.getY(), vector.getZ());
    }

    public Point3D crossProduct(double x, double y, double res) {
        final double ax = getX();
        final double ay = getY();
        final double az = getZ();

        return new Point3D(
                ay * res - az * y,
                az * x - ax * res,
                ax * y - ay * x);
    }

    public Point3D crossProduct(Point3D vector) {
        return crossProduct(vector.getX(), vector.getY(), vector.getZ());
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj instanceof Point3D) {
            Point3D other = (Point3D) obj;
            return getX() == other.getX() && getY() == other.getY() && getZ() == other.getZ();
        } else return false;
    }


    @Override
    public int hashCode() {
        if (hash == 0) {
            long bits = 7L;
            bits = 31L * bits + Double.doubleToLongBits(getX());
            bits = 31L * bits + Double.doubleToLongBits(getY());
            bits = 31L * bits + Double.doubleToLongBits(getZ());
            hash = (int) (bits ^ (bits >> 32));
        }
        return hash;
    }


    @Override
    public String toString() {
        return "Point3D [x = " + getX() + ", y = " + getY() + ", res = " + getZ() + "]";
    }
}

class Line2D {

    double a, b, c;

    Point2D A, B;

    Point2D normal;

    public Line2D(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        fromEquationToPoints(a, b, c);
    }

    public Line2D(Point2D a, Point2D b) {
        A = a;
        B = b;
        fromPointsToEquation(a, b);
    }


    private void fromPointsToEquation(Point2D A, Point2D B) {
        Point2D vect = B.subtract(A);
        normal = new Point2D(vect.getY(), -vect.getX()).normalize();
        a = normal.getX();
        b = normal.getY();
        c = -(a * A.getX() + b * B.getY());
    }

    private void fromEquationToPoints(double a, double b, double c) {
        if (b == 0) {
            A = new Point2D(-c / a, 0);
            B = new Point2D(-c / a, 1);
        } else {
            A = new Point2D(0, -(c) / b);
            B = new Point2D(1, -(c + a) / b);
        }
    }

    private double calculate(Point2D o) {
        return (a * o.getX() + b * o.getY() + c);
    }


    public double dist(Point2D o) {
        return abs(o.subtract(A).crossProduct(o.subtract(B)).getZ()) / A.distance(B);
    }


    public Point2D getNormal() {
        if (normal != null) {
            return normal;
        }
        return normal = new Point2D(a, b);
    }

    public Point2D reflect(Point2D o) {
        Point2D norm = getNormal();
        norm = norm.multiply(calculate(o));
        norm = norm.multiply(-1);
        return o.add(norm).add(norm);
    }

}

class SegTree<T> {
    public T[] tree;
    public T[] delta;
    BiFunction<T, T, T> merge;
    BiFunction<Pair<T, Integer>, T, T> modify;

    public void setDeltamerge(BiFunction<T, T, T> deltamerge) {
        this.deltamerge = deltamerge;
    }

    BiFunction<T, T, T> deltamerge;

    public SegTree(T[] a, BiFunction<T, T, T> merge) {
        tree = (T[]) new Object[a.length * 4];
        delta = (T[]) new Object[a.length * 4];
        this.merge = merge;
        build(1, 1, a.length, a);
        n = a.length;
    }

    public void setModify(BiFunction<Pair<T, Integer>, T, T> modify) {
        this.modify = modify;
    }

    private int ind = 0;
    private int n;

    private void build(int v, int l, int r, T[] a) {
        if (l == r) {
            tree[v] = a[ind++];
            return;
        }
        int m = (r - l + 1) / 2 + l - 1;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);
        tree[v] = merge.apply(tree[v * 2], tree[v * 2 + 1]);
    }

    private T get(int v, int l, int r, int left, int right) {
        push(v, l, r);
        if (left <= l && r <= right) {
            

            return tree[v];
        }
        int m = (r - l + 1) / 2 + l - 1;
        if ((m < left || l > right)) {
            

            return get(v * 2 + 1, m + 1, r, left, right);
        }
        if ((r < left || m + 1 > right)) {
            

            return get(v * 2, l, m, left, right);
        }
        

        return merge.apply(get(v * 2, l, m, left, right), get(v * 2 + 1, m + 1, r, left, right));
    }

    public T get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    public void modify(int l, int r, T delta) {
        modify(1, 1, n, l, r, delta);
    }

    private void modify(int v, int l, int r, int left, int right, T delta) {
        push(v, l, r);
        if (left <= l && r <= right) {
            this.delta[v] = delta;
            push(v, l, r);
            return;
        }
        int m = (r - l + 1) / 2 + l - 1;
        if (m >= left) {
            push(v, l, r);
            modify(v * 2, l, m, left, right, delta);
        }
        if (m + 1 <= right) {
            push(v, l, r);
            modify(v * 2 + 1, m + 1, r, left, right, delta);
        }
        tree[v] = merge.apply(tree[v * 2], tree[v * 2 + 1]);
    }

    public void push(int v, int l, int r) {
        if (delta[v] == null) {
            return;
        }
        tree[v] = modify.apply(new Pair<>(tree[v], r - l + 1), delta[v]);
        if (v * 2 < delta.length) {
            delta[v * 2] = deltamerge.apply(delta[v * 2], delta[v]);
            ;
        }
        if (v * 2 + 1 < delta.length) {
            delta[v * 2 + 1] = deltamerge.apply(delta[v * 2 + 1], delta[v]);
        }
        delta[v] = null;
    }
}

class Trie {
    private ArrayList<Integer[]> go;
    private int alphabet;
    private char zeroChar;
    private int ind = 1;

    public Trie(int initialCapasity, int alphabet, char zeroChar) {
        this.alphabet = alphabet;
        go = new ArrayList<>(initialCapasity);
        this.zeroChar = zeroChar;
        Integer[] links = new Integer[alphabet];
        Arrays.fill(links, -1);
        go.add(links);
    }

    public Trie(int alphabet, char zeroChar) {
        this(10000, alphabet, zeroChar);
    }

    public Trie() {
        this(26, 'a');
    }

    public void add(String str) {
        int cur = 0;
        for (int i = 0; i < str.length(); i++) {
            if (go.get(cur)[str.charAt(i) - zeroChar] == -1) {
                Integer[] links = new Integer[alphabet];
                Arrays.fill(links, -1);
                go.add(links);
                go.get(cur)[str.charAt(i) - zeroChar] = go.size() - 1;
            }
            cur = go.get(cur)[str.charAt(i) - zeroChar];
        }

    }
}