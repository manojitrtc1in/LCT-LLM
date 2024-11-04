import java.util.*;
import java.io.*;
import java.util.function.*;
import java.util.stream.*;

class Modular<T> {
    private static final int MOD = 998244353;
    private long value;

    public Modular() {
        this.value = 0;
    }

    public Modular(long x) {
        this.value = normalize(x);
    }

    private long normalize(long x) {
        if (x < 0) x += MOD;
        return x % MOD;
    }

    public long getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        return new Modular<>(normalize(value + other.value));
    }

    public Modular<T> subtract(Modular<T> other) {
        return new Modular<>(normalize(value - other.value));
    }

    public Modular<T> multiply(Modular<T> other) {
        return new Modular<>(normalize(value * other.value));
    }

    public Modular<T> divide(Modular<T> other) {
        return multiply(new Modular<>(inverse(other.value)));
    }

    private long inverse(long a) {
        long m = MOD, u = 0, v = 1;
        while (a != 0) {
            long t = m / a;
            m -= t * a;
            long temp = a; a = m; m = temp;
            u -= t * v;
            temp = u; u = v; v = temp;
        }
        return u < 0 ? u + MOD : u;
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }
}

class Mat<T> {
    private T[][] m;

    public Mat() {
        m = (T[][]) new Object[2][2];
    }

    public T[] getRow(int i) {
        return m[i];
    }

    public void set(int i, int j, T value) {
        m[i][j] = value;
    }

    public Mat<T> multiply(Mat<T> b) {
        Mat<T> c = new Mat<>();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.set(i, j, (T) ((Long) m[i][0] * (Long) b.getRow(0)[j] + (Long) m[i][1] * (Long) b.getRow(1)[j]));
            }
        }
        return c;
    }
}

class Frac {
    int p, q;

    public Frac(int p, int q) {
        this.p = p;
        this.q = q;
    }

    public static Frac from(long p, long q) {
        return new Frac((int) p, (int) q);
    }

    public boolean isZero() {
        return q == 0;
    }

    public boolean isLessThan(Frac other) {
        return (long) p * other.q < (long) other.p * q;
    }
}

public class c4ff5f94b8be163cd9b6679c95cd7861xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        if (n == 1) {
            out.println(0);
            out.close();
            return;
        }

        int[] x = new int[n];
        int[] v = new int[n];
        Modular<Long>[] p = new Modular[n];
        Modular<Long> id1 = new Modular<>(1).divide(new Modular<>(100));

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Modular<>(Integer.parseInt(st.nextToken())).multiply(id1);
        }

        Mat<Modular<Long>>[] id2 = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            id2[i] = new Mat<>();
            id2[i].set(0, 1, p[i + 1]);
        }

        Mat<Modular<Long>>[] a = new Mat[2 * (n - 1) - 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = new Mat<>();
        }

        Function<Void, Modular<Long>> getProb = (Void) -> {
            Modular<Long> toRight = p[0];
            Mat<Modular<Long>> mat = a[getId(0, n - 2)];
            return toRight.multiply(mat.getRow(1)[0].add(mat.getRow(1)[1]))
                    .add(new Modular<>(1).subtract(toRight).multiply(mat.getRow(0)[0].add(mat.getRow(0)[1])));
        };

        build(a, id2, 0, n - 2);

        Function<Void, Void> modify = (Void) -> {
            return null;
        };

        List<Pair<Frac, Integer>> events = new ArrayList<>(3 * (n - 1));
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events.add(new Pair<>(Frac.from(d, v[i + 1] + v[i]), i << 2 | 1));
            events.add(new Pair<>(v[i] < v[i + 1] ? Frac.from(d, v[i + 1] - v[i]) : Frac.from(1, 0), i << 2 | 0));
            events.add(new Pair<>(v[i] > v[i + 1] ? Frac.from(d, v[i] - v[i + 1]) : Frac.from(1, 0), i << 2 | 3));
        }

        events.sort(Comparator.comparing(pair -> pair.getKey().p));

        Modular<Long> prevProb = getProb.apply(null);
        Modular<Long> ans = new Modular<>(0);

        for (Pair<Frac, Integer> event : events) {
            int i = event.getValue() >> 2;
            int dir1 = getBit(event.getValue(), 0);
            int dir2 = getBit(event.getValue(), 1);

            id2[i].set(dir1, dir2, dir2 == 1 ? p[i + 1] : new Modular<>(1).subtract(p[i + 1]));
            modify.apply(null);
            Modular<Long> prob = getProb.apply(null);
            if (!event.getKey().isZero()) {
                ans = ans.add(prob.subtract(prevProb).multiply(event.getKey()));
            }
            prevProb = prob;
        }

        out.println(ans);
        out.close();
    }

    private static int getId(int l, int r) {
        return l + r | (l != r ? 1 : 0);
    }

    private static int getBit(int a, int i) {
        return (a >> i) & 1;
    }

    private static void build(Mat<Modular<Long>>[] a, Mat<Modular<Long>>[] id2, int l, int r) {
        if (l == r) {
            a[2 * l] = id2[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, id2, l, mid);
        build(a, id2, mid + 1, r);
        a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
    }

    static class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}
