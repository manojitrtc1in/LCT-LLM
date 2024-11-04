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
        boolean id10 = false;

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
            if (t.id10) {
                Treap tmp = t.l;
                t.l = t.r;
                t.r = tmp;
                t.id10 = false;
                if (t.l != null) {
                    t.l.id10 ^= true;
                }
                if (t.r != null) {
                    t.r.id10 ^= true;
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
        p1.second.id10 ^= true;
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


    public static boolean id11(int[] a) {
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
        int[] a = in.id8(n);
        if (id11(a)) {
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

    public int[] id8(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    public long[] id12(int n) {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    public id9 nextPoint() {
        return new id9(nextDouble(), nextDouble());
    }

    public id4 nextLine() {
        return new id4(nextDouble(), nextDouble(), nextDouble());
    }

    public BigInteger id0() {
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

class id9 {
    public static final id9 ZERO = new id9(0.0, 0.0);

    private double x;

    public final double getX() {
        return x;
    }


    private double y;

    public final double getY() {
        return y;
    }

    private int hash = 0;

    public id9(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(double x1, double y1) {
        double a = getX() - x1;
        double b = getY() - y1;
        return Math.sqrt(a * a + b * b);
    }

    public double distance(id9 point) {
        return distance(point.getX(), point.getY());
    }

    public id9 add(double x, double y) {
        return new id9(
                getX() + x,
                getY() + y);
    }

    public id9 add(id9 point) {
        return add(point.getX(), point.getY());
    }

    public id9 subtract(double x, double y) {
        return new id9(
                getX() - x,
                getY() - y);
    }

    public id9 multiply(double factor) {
        return new id9(getX() * factor, getY() * factor);
    }

    public id9 subtract(id9 point) {
        return subtract(point.getX(), point.getY());
    }

    public id9 normalize() {
        final double mag = magnitude();

        if (mag == 0.0) {
            return new id9(0.0, 0.0);
        }

        return new id9(
                getX() / mag,
                getY() / mag);
    }

    public id9 midpoint(double x, double y) {
        return new id9(
                x + (getX() - x) / 2.0,
                y + (getY() - y) / 2.0);
    }

    public id9 midpoint(id9 point) {
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

    public double angle(id9 point) {
        return angle(point.getX(), point.getY());
    }

    public double angle(id9 p1, id9 p2) {
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

    public double dotProduct(id9 vector) {
        return dotProduct(vector.getX(), vector.getY());
    }

    public id7 crossProduct(double x, double y) {
        final double ax = getX();
        final double ay = getY();

        return new id7(
                0, 0, ax * y - ay * x);
    }

    public id7 crossProduct(id9 vector) {
        return crossProduct(vector.getX(), vector.getY());
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj instanceof id9) {
            id9 other = (id9) obj;
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
        return "id9 [x = " + getX() + ", y = " + getY() + "]";
    }
}

class id7 {
    public static final id7 ZERO = new id7(0.0, 0.0, 0.0);

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

    public id7(double x, double y, double res) {
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

    public double distance(id7 point) {
        return distance(point.getX(), point.getY(), point.getZ());
    }

    public id7 add(double x, double y, double res) {
        return new id7(
                getX() + x,
                getY() + y,
                getZ() + res);
    }

    public id7 add(id7 point) {
        return add(point.getX(), point.getY(), point.getZ());
    }

    public id7 subtract(double x, double y, double res) {
        return new id7(
                getX() - x,
                getY() - y,
                getZ() - res);
    }

    public id7 subtract(id7 point) {
        return subtract(point.getX(), point.getY(), point.getZ());
    }

    public id7 multiply(double factor) {
        return new id7(getX() * factor, getY() * factor, getZ() * factor);
    }

    public id7 normalize() {
        final double mag = magnitude();

        if (mag == 0.0) {
            return new id7(0.0, 0.0, 0.0);
        }

        return new id7(
                getX() / mag,
                getY() / mag,
                getZ() / mag);
    }

    public id7 midpoint(double x, double y, double res) {
        return new id7(
                x + (getX() - x) / 2.0,
                y + (getY() - y) / 2.0,
                res + (getZ() - res) / 2.0);
    }

    public id7 midpoint(id7 point) {
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

    public double angle(id7 point) {
        return angle(point.getX(), point.getY(), point.getZ());
    }

    public double angle(id7 p1, id7 p2) {
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

    public double dotProduct(id7 vector) {
        return dotProduct(vector.getX(), vector.getY(), vector.getZ());
    }

    public id7 crossProduct(double x, double y, double res) {
        final double ax = getX();
        final double ay = getY();
        final double az = getZ();

        return new id7(
                ay * res - az * y,
                az * x - ax * res,
                ax * y - ay * x);
    }

    public id7 crossProduct(id7 vector) {
        return crossProduct(vector.getX(), vector.getY(), vector.getZ());
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj instanceof id7) {
            id7 other = (id7) obj;
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
        return "id7 [x = " + getX() + ", y = " + getY() + ", res = " + getZ() + "]";
    }
}

class id4 {

    double a, b, c;

    id9 A, B;

    id9 normal;

    public id4(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        id6(a, b, c);
    }

    public id4(id9 a, id9 b) {
        A = a;
        B = b;
        id5(a, b);
    }


    private void id5(id9 A, id9 B) {
        id9 vect = B.subtract(A);
        normal = new id9(vect.getY(), -vect.getX()).normalize();
        a = normal.getX();
        b = normal.getY();
        c = -(a * A.getX() + b * B.getY());
    }

    private void id6(double a, double b, double c) {
        if (b == 0) {
            A = new id9(-c / a, 0);
            B = new id9(-c / a, 1);
        } else {
            A = new id9(0, -(c) / b);
            B = new id9(1, -(c + a) / b);
        }
    }

    private double calculate(id9 o) {
        return (a * o.getX() + b * o.getY() + c);
    }


    public double dist(id9 o) {
        return abs(o.subtract(A).crossProduct(o.subtract(B)).getZ()) / A.distance(B);
    }


    public id9 getNormal() {
        if (normal != null) {
            return normal;
        }
        return normal = new id9(a, b);
    }

    public id9 reflect(id9 o) {
        id9 norm = getNormal();
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

    public void id3(BiFunction<T, T, T> id2) {
        this.id2 = id2;
    }

    BiFunction<T, T, T> id2;

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
            delta[v * 2] = id2.apply(delta[v * 2], delta[v]);
            ;
        }
        if (v * 2 + 1 < delta.length) {
            delta[v * 2 + 1] = id2.apply(delta[v * 2 + 1], delta[v]);
        }
        delta[v] = null;
    }
}

class Trie {
    private ArrayList<Integer[]> go;
    private int alphabet;
    private char zeroChar;
    private int ind = 1;

    public Trie(int id1, int alphabet, char zeroChar) {
        this.alphabet = alphabet;
        go = new ArrayList<>(id1);
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
