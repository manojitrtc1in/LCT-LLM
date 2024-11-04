import java.io.*;
import java.util.*;

class NumberIterator {
    int v;

    NumberIterator(int v) {
        this.v = v;
    }

    public int getValue() {
        return v;
    }

    public int next() {
        return v++;
    }
}

class Range {
    int first, second;

    Range(int begin, int end) {
        this.first = begin;
        this.second = Math.max(begin, end);
    }

    Range(int n) {
        this(0, Math.max(0, n));
    }

    public NumberIterator begin() {
        return new NumberIterator(first);
    }

    public NumberIterator end() {
        return new NumberIterator(second);
    }
}

class Arr<T> {
    T[] b;
    int n;

    @SuppressWarnings("unchecked")
    private void allocate(int sz) {
        n = sz;
        if (sz > 0) {
            b = (T[]) new Object[sz];
        } else {
            b = null;
        }
    }

    public Arr(int n) {
        allocate(n);
    }

    public Arr(int n, T init) {
        allocate(n);
        for (int i : new Range(n).begin().next()) {
            b[i] = init;
        }
    }

    public int size() {
        return n;
    }

    public T get(int at) {
        return b[at];
    }

    public void set(int at, T value) {
        b[at] = value;
    }

    public boolean equals(Arr<T> other) {
        if (n != other.n) {
            return false;
        }
        for (int i : new Range(n).begin().next()) {
            if (!b[i].equals(other.b[i])) {
                return false;
            }
        }
        return true;
    }
}

class Arr2D<T> {
    T[] b;
    int d1, d2;

    @SuppressWarnings("unchecked")
    private void allocate(int n) {
        if (n > 0) {
            b = (T[]) new Object[n];
        } else {
            b = null;
        }
    }

    public Arr2D(int d1, int d2) {
        this.d1 = d1;
        this.d2 = d2;
        allocate(d1 * d2);
    }

    public T get(int i1, int i2) {
        return b[i1 * d2 + i2];
    }

    public void set(int i1, int i2, T value) {
        b[i1 * d2 + i2] = value;
    }
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input() {
        reader = new BufferedReader(new InputStreamReader(System.in));
    }

    private String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long readLong() throws IOException {
        return Long.parseLong(next());
    }

    public double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public String readString() throws IOException {
        return next();
    }
}

class Output {
    private PrintWriter writer;

    public Output() {
        writer = new PrintWriter(System.out);
    }

    public void print(Object... args) {
        for (Object arg : args) {
            writer.print(arg + " ");
        }
    }

    public void println(Object... args) {
        print(args);
        writer.println();
    }

    public void flush() {
        writer.flush();
    }
}

class ModInt {
    private static int mod = 1000000007;
    private int n;

    public ModInt() {
        this.n = 0;
    }

    public ModInt(long n) {
        this.n = (int) ((n % mod + mod) % mod);
    }

    public ModInt add(ModInt other) {
        return new ModInt(n + other.n);
    }

    public ModInt subtract(ModInt other) {
        return new ModInt(n - other.n);
    }

    public ModInt multiply(ModInt other) {
        return new ModInt((long) n * other.n);
    }

    public ModInt inverse() {
        return new ModInt(modInverse(n, mod));
    }

    private static long modInverse(int a, int m) {
        a = a % m;
        for (int x = 1; x < m; x++) {
            if ((a * x) % m == 1) {
                return x;
            }
        }
        return 1;
    }

    public int getValue() {
        return n;
    }
}

class FenwickTree<T extends ModInt> {
    private Arr<T> value;

    public FenwickTree(int size) {
        value = new Arr<>(size);
    }

    public void add(int at, T v) {
        while (at < value.size()) {
            value.set(at, value.get(at).add(v));
            at |= (at + 1);
        }
    }

    public T get(int from, int to) {
        if (from >= to) {
            return new ModInt(0);
        }
        return get(to - 1).subtract(get(from - 1));
    }

    private T get(int to) {
        T result = new ModInt(0);
        while (to >= 0) {
            result = result.add(value.get(to));
            to = (to & (to + 1)) - 1;
        }
        return result;
    }
}

class BVerkhnyayaYacheika {
    public void solve(Input in, Output out) throws IOException {
        int n = in.readInt();
        int m = in.readInt();

        ModInt mod = new ModInt(m);
        FenwickTree<ModInt> ft = new FenwickTree<>(n + 1);
        ft.add(n, new ModInt(1));
        for (int i = n; i >= 1; i--) {
            ModInt res = ft.get(i + 1, n + 1);
            for (int z = 2; z * i <= n; z++) {
                res = res.add(ft.get(z * i, z * i + z));
            }
            ft.add(i, res);
        }
        out.println(ft.get(1, 2).getValue());
    }
}

public class f24ceb3f77f67144aba51bc22ad19e75_nc {
    public static void main(String[] args) throws IOException {
        Input in = new Input();
        Output out = new Output();
        BVerkhnyayaYacheika solver = new BVerkhnyayaYacheika();
        solver.solve(in, out);
        out.flush();
    }
}
