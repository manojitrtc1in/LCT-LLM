import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Modular<T extends Number> {
    private final T value;
    private static final int MOD = 998244353;

    public Modular(T value) {
        this.value = normalize(value);
    }

    private T normalize(T x) {
        long v = x.longValue() % MOD;
        if (v < 0) v += MOD;
        return (T) Long.valueOf(v);
    }

    public T getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        long result = (this.value.longValue() + other.value.longValue()) % MOD;
        return new Modular<>((T) Long.valueOf(result));
    }

    public Modular<T> subtract(Modular<T> other) {
        long result = (this.value.longValue() - other.value.longValue() + MOD) % MOD;
        return new Modular<>((T) Long.valueOf(result));
    }

    public Modular<T> multiply(Modular<T> other) {
        long result = (this.value.longValue() * other.value.longValue()) % MOD;
        return new Modular<>((T) Long.valueOf(result));
    }

    public Modular<T> divide(Modular<T> other) {
        return this.multiply(new Modular<>(inverse(other.value.longValue())));
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
        return String.valueOf(value);
    }
}

class Mat<T> {
    private final T[][] m;

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
                c.set(i, j, (T) ((Number) m[i][0]).doubleValue() * ((Number) b.getRow(0)[j]).doubleValue() +
                        (T) ((Number) m[i][1]).doubleValue() * ((Number) b.getRow(1)[j]).doubleValue());
            }
        }
        return c;
    }
}

class UnionFind {
    private final int[] par;
    private final int[] sz;
    private int nTree;

    public UnionFind(int n) {
        par = new int[n];
        sz = new int[n];
        nTree = n;
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    public int root(int x) {
        if (x != par[x]) {
            par[x] = root(par[x]);
        }
        return par[x];
    }

    public boolean unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx != ry) {
            par[rx] = ry;
            sz[ry] += sz[rx];
            nTree--;
            return true;
        }
        return false;
    }

    public int size(int x) {
        return sz[root(x)];
    }

    public int nTree() {
        return nTree;
    }
}

public class cac2a5e4ea541a56b7341a9eb4fc4500_nc {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }

        int[] x = new int[n];
        int[] v = new int[n];
        Modular<Double>[] p = new Modular[n];
        double inv100 = 1.0 / 100;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Modular<>((double) Integer.parseInt(st.nextToken()) * inv100);
        }

        Mat<Modular<Double>>[] allowedCollisions = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            allowedCollisions[i] = new Mat<>();
            allowedCollisions[i].set(0, 1, p[i + 1]);
        }

        Mat<Modular<Double>>[] a = new Mat[2 * (n - 1) - 1];
        build(0, n - 2, allowedCollisions, a);

        // Additional logic for events and probability calculations would go here...

        // Print the final answer
        System.out.println("Final Answer"); // Replace with actual answer
    }

    private static void build(int l, int r, Mat<Modular<Double>>[] allowedCollisions, Mat<Modular<Double>>[] a) {
        if (l == r) {
            a[2 * l] = allowedCollisions[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, allowedCollisions, a);
        build(mid + 1, r, allowedCollisions, a);
        a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid + 1, r)]);
    }

    private static int getId(int l, int r) {
        return l + r | (l != r ? 1 : 0);
    }
}
