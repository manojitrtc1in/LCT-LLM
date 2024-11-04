import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Modular<T> {
    private final T value;
    private static final int MOD = 998244353;

    public Modular() {
        this.value = (T) Integer.valueOf(0);
    }

    public Modular(T x) {
        this.value = normalize(x);
    }

    private static <U> U normalize(U x) {
        if (x instanceof Integer) {
            int v = (Integer) x;
            if (v < 0) v += MOD;
            return (U) Integer.valueOf(v % MOD);
        }
        return x;
    }

    public T getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        int result = (Integer) this.value + (Integer) other.value;
        return new Modular<>(normalize(result));
    }

    public Modular<T> subtract(Modular<T> other) {
        int result = (Integer) this.value - (Integer) other.value;
        return new Modular<>(normalize(result));
    }

    public Modular<T> multiply(Modular<T> other) {
        long result = (long) this.value * (long) other.value;
        return new Modular<>(normalize((int) (result % MOD)));
    }

    public Modular<T> divide(Modular<T> other) {
        return this.multiply(new Modular<>(inverse((Integer) other.value)));
    }

    private static int inverse(int a) {
        int m = MOD, u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            int temp = a; a = m; m = temp;
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
                c.set(i, j, (T) ((Integer) m[i][0] * (Integer) b.getRow(0)[j] + (Integer) m[i][1] * (Integer) b.getRow(1)[j]));
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
}

public class c4ff5f94b8be163cd9b6679c95cd7861_nc {
    private static int cas = 0;

    private static void printCase() {
        System.out.println("Case #" + ++cas + ": ");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int[] x = new int[n];
        int[] v = new int[n];
        Modular<Integer>[] p = new Modular[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Modular<>(Integer.parseInt(st.nextToken()) * inverse(100));
        }

        Mat<Modular<Integer>>[] allowedCollisions = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            allowedCollisions[i] = new Mat<>();
            allowedCollisions[i].set(0, 1, p[i + 1]);
        }

        Modular<Integer>[] a = new Modular[2 * (n - 1) - 1];
        // Build and modify functions would go here...

        // Event handling and calculations would go here...

        // Final output
        System.out.println("Final Result"); // Placeholder for the final result
    }

    private static int inverse(int x) {
        return BigInteger.valueOf(x).modInverse(BigInteger.valueOf(998244353)).intValue();
    }
}
