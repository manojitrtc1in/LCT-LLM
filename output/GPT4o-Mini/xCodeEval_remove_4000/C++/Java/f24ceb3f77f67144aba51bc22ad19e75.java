import java.io.*;
import java.util.*;

class BVerkhnyayaYacheika {
    public void solve() {
        int n = in.readInt();
        int m = in.readInt();

        mod = m;
        id7<modint> ft = new id7<>(n + 1);
        ft.add(n, 1);
        for (int i : new RevRange(n, 1)) {
            modint res = ft.get(i + 1, n + 1);
            for (int z = 2; z * i <= n; z++) {
                res = res.add(ft.get(z * i, z * i + z));
            }
            ft.add(i, res);
        }
        out.printLine(ft.get(1, 2));
    }
}

class modint {
    public int n;

    public modint() {
        this.n = 0;
    }

    public modint(long n, boolean special) {
        if (special) {
            this.n = -1;
            return;
        }
        if (n >= 0 && n < mod) {
            this.n = (int) n;
            return;
        }
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        this.n = (int) n;
    }

    public modint add(modint other) {
        if (n == -1 || other.n == -1) {
            throw new IllegalStateException("Illegal state");
        }
        n += other.n;
        if (n >= mod) {
            n -= mod;
        }
        return this;
    }

    public modint subtract(modint other) {
        if (n == -1 || other.n == -1) {
            throw new IllegalStateException("Illegal state");
        }
        n -= other.n;
        if (n < 0) {
            n += mod;
        }
        return this;
    }

    public modint multiply(modint other) {
        if (n == -1 || other.n == -1) {
            throw new IllegalStateException("Illegal state");
        }
        n = (int) ((long) n * other.n % mod);
        return this;
    }

    public modint divide(modint other) {
        if (other.n == 0) {
            throw new IllegalArgumentException("Division by zero");
        }
        if (n == -1 || other.n == -1) {
            throw new IllegalStateException("Illegal state");
        }
        return this.multiply(other.inverse());
    }

    public modint inverse() {
        if (n == -1) {
            throw new IllegalStateException("Illegal state");
        }
        long x, y;
        long g = gcd((long) n, (long) mod, x, y);
        if (g != 1) {
            throw new IllegalArgumentException("not inversable");
        }
        return new modint(x, true);
    }

    public static long gcd(long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0;
            y[0] = 1;
            return b;
        }
        long[] y1 = new long[1], x1 = new long[1];
        long d = gcd(b % a, a, y1, x1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }
}

class id7<T> {
    arr<T> value;

    public id7(int size) {
        value = new arr<>(size, (T) new Integer(0));
    }

    public void add(int at, T v) {
        while (at < value.size()) {
            value.set(at, (T) ((Integer) value.get(at) + (Integer) v));
            at = at | (at + 1);
        }
    }

    public T get(int from, int to) {
        if (from >= to) {
            return (T) new Integer(0);
        }
        return (T) ((Integer) get(to - 1) - (Integer) get(from - 1));
    }
}

class arr<T> {
    private T[] b;
    private int n;

    @SuppressWarnings("unchecked")
    public arr(int n, T init) {
        this.n = n;
        b = (T[]) new Object[n];
        for (int i = 0; i < n; i++) {
            b[i] = init;
        }
    }

    public int size() {
        return n;
    }

    public T get(int at) {
        if (at < 0 || at >= n) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return b[at];
    }

    public void set(int at, T value) {
        if (at < 0 || at >= n) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        b[at] = value;
    }
}

class RevRange extends Pair<Integer, Integer> {
    public RevRange(int begin, int end) {
        super(begin - 1, Math.min(begin, end) - 1);
    }

    public RevRange(int n) {
        super(n - 1, Math.min(n, 0) - 1);
    }

    public int begin() {
        return first;
    }

    public int end() {
        return second;
    }
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    public int readInt() {
        return Integer.parseInt(next());
    }

    private String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
}

class Output {
    private PrintWriter writer;

    public Output() {
        writer = new PrintWriter(System.out);
    }

    public void printLine(Object... args) {
        for (int i = 0; i < args.length; i++) {
            writer.print(args[i]);
            if (i + 1 != args.length) {
                writer.print(' ');
            }
        }
        writer.println();
        writer.flush();
    }
}

public class f24ceb3f77f67144aba51bc22ad19e75xcodeeval_processed_4000.json {
    private static Input in = new Input();
    private static Output out = new Output();
    private static int mod;

    public static void main(String[] args) {
        BVerkhnyayaYacheika solver = new BVerkhnyayaYacheika();
        solver.solve();
    }
}
