import java.util.*;
import java.io.*;

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
        if (x >= MOD) x %= MOD;
        return x;
    }

    public long getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        return new Modular<>(normalize(this.value + other.value));
    }

    public Modular<T> subtract(Modular<T> other) {
        return new Modular<>(normalize(this.value - other.value));
    }

    public Modular<T> multiply(Modular<T> other) {
        return new Modular<>(normalize(this.value * other.value));
    }

    public Modular<T> divide(Modular<T> other) {
        return this.multiply(new Modular<>(inverse(other.value)));
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

class Mat {
    private final Modular<Long>[][] m = new Modular[2][2];

    public Mat() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = new Modular<>();
            }
        }
    }

    public Modular<Long>[] getRow(int i) {
        return m[i];
    }

    public Mat multiply(Mat b) {
        Mat c = new Mat();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.getRow(i)[j] = c.getRow(i)[j].add(m[i][k].multiply(b.getRow(k)[j]));
                }
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

    public static Frac zero() {
        return new Frac(0, 1);
    }

    public boolean isZero() {
        return p == 0;
    }

    public boolean isPositive() {
        return p > 0 && q > 0;
    }

    public boolean isNegative() {
        return p < 0 && q > 0;
    }
}

public class cac2a5e4ea541a56b7341a9eb4fc4500xcodeeval_processed_4000.json {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(in.readLine());
        if (n == 1) {
            out.println(0);
            out.close();
            return;
        }

        int[] x = new int[n];
        int[] v = new int[n];
        Modular<Long>[] p = new Modular[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Modular<>(Integer.parseInt(st.nextToken()));
            p[i] = p[i].divide(new Modular<>(100));
        }

        Mat[] id2 = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            id2[i] = new Mat();
            id2[i].getRow(0)[1] = p[i + 1];
        }

        Mat[] a = new Mat[2 * (n - 1) - 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = new Mat();
        }

        // Function to get probability
        Modular<Long> getProb = new Modular<>(p[0].getValue()).multiply(a[0].getRow(1)[0].add(a[0].getRow(1)[1]))
                .add(new Modular<>(1).subtract(p[0].getValue()).multiply(a[0].getRow(0)[0].add(a[0].getRow(0)[1])));

        // Build function
        build(0, n - 2, id2, a);

        // Modify function
        modify(0, n - 2, 0, id2, a);

        List<Pair<Frac, Integer>> events = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events.add(new Pair<>(new Frac(d, v[i + 1] + v[i]), i << 2 | 1));
            events.add(new Pair<>(v[i] < v[i + 1] ? new Frac(d, v[i + 1] - v[i]) : new Frac(1, 0), i << 2 | 0));
            events.add(new Pair<>(v[i] > v[i + 1] ? new Frac(d, v[i] - v[i + 1]) : new Frac(1, 0), i << 2 | 3));
        }

        Collections.sort(events, Comparator.comparing(a -> a.first));

        Modular<Long> prevProb = getProb;
        Modular<Long> ans = new Modular<>(0);

        for (Pair<Frac, Integer> event : events) {
            int i = event.second >> 2;
            int dir1 = event.second & 1;
            int dir2 = (event.second >> 1) & 1;

            id2[i].getRow(dir1)[dir2] = dir2 == 1 ? p[i + 1] : new Modular<>(1).subtract(p[i + 1]);
            modify(0, n - 2, i, id2, a);

            Modular<Long> prob = getProb;
            if (event.first.q != 0) {
                ans = ans.add(prob.subtract(prevProb).multiply(new Modular<>(event.first.p)));
            }
            prevProb = prob;
        }

        out.println(ans);
        out.close();
    }

    private static void build(int l, int r, Mat[] id2, Mat[] a) {
        if (l == r) {
            a[2 * l] = id2[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, id2, a);
        build(mid + 1, r, id2, a);
        a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
    }

    private static void modify(int l, int r, int k, Mat[] id2, Mat[] a) {
        if (l == r) {
            a[2 * l] = id2[k];
            return;
        }
        int mid = (l + r) / 2;
        if (k <= mid) {
            modify(l, mid, k, id2, a);
        } else {
            modify(mid + 1, r, k, id2, a);
        }
        a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
    }

    private static int getId(int l, int r) {
        return l + r | (l != r ? 1 : 0);
    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
