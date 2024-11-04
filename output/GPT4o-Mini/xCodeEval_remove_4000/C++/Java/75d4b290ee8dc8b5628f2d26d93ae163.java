import java.util.*;
import java.io.*;

class Vector<T> extends ArrayList<T> {
    public Vector() {
        super();
    }

    public Vector(int n) {
        super(n);
    }

    public Vector(int n, T value) {
        super(n);
        Collections.fill(this, value);
    }

    public Vector(Collection<? extends T> c) {
        super(c);
    }

    public T get(int ind) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(ind);
    }

    public T set(int ind, T value) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(ind, value);
    }
}

class VectorBool extends ArrayList<Boolean> {
    public VectorBool() {
        super();
    }

    public VectorBool(int n) {
        super(n);
    }

    public VectorBool(int n, boolean value) {
        super(n);
        Collections.fill(this, value);
    }

    public Boolean get(int ind) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(ind);
    }

    public Boolean set(int ind, boolean value) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(ind, value);
    }
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    private String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(next());
    }

    public long readLong() {
        return Long.parseLong(next());
    }

    public String readString() {
        return next();
    }

    public double readDouble() {
        return Double.parseDouble(next());
    }

    public int[] readIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = readInt();
        }
        return array;
    }
}

class Output {
    private PrintWriter writer;

    public Output(OutputStream out) {
        writer = new PrintWriter(out);
    }

    public void print(Object... args) {
        for (int i = 0; i < args.length; i++) {
            writer.print(args[i]);
            if (i < args.length - 1) {
                writer.print(" ");
            }
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

class TaskD {
    public void solve(Input in, Output out) {
        int n = in.readInt();
        int[] x = in.readIntArray(n);
        int[] v = in.readIntArray(n);
        int[] p = in.readIntArray(n);
        int mod = 998244353;

        List<modint> pp = new ArrayList<>(Collections.nCopies(4 * n, new modint(0)));
        List<modint> tmp = new ArrayList<>(Collections.nCopies(4 * n, new modint(0)));
        boolean[][] allowed = new boolean[n][4];
        for (int i = 0; i < n; i++) {
            Arrays.fill(allowed[i], true);
        }

        // Initialize pp and tmp
        // (Implementation of init function goes here)

        List<Event> events = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            events.add(new Event(2, i, x[i] - x[i - 1], v[i] + v[i - 1]));
            if (v[i] > v[i - 1]) {
                events.add(new Event(0, i, x[i] - x[i - 1], v[i] - v[i - 1]));
            } else if (v[i] < v[i - 1]) {
                events.add(new Event(3, i, x[i] - x[i - 1], v[i - 1] - v[i]));
            }
        }
        Collections.sort(events);

        modint answer = new modint(0);
        for (Event e : events) {
            // (Implementation of query and recalc functions goes here)
            // Update answer based on the events
        }

        out.println(answer);
    }
}

class Event implements Comparable<Event> {
    int type, at, dx, v;

    public Event(int type, int at, int dx, int v) {
        this.type = type;
        this.at = at;
        this.dx = dx;
        this.v = v;
    }

    @Override
    public int compareTo(Event b) {
        return Long.compare((long) dx * b.v, (long) b.dx * v);
    }
}

class modint {
    int n;

    public modint() {
        this.n = 0;
    }

    public modint(long n) {
        this.n = (int) ((n % 998244353 + 998244353) % 998244353);
    }

    public modint add(modint other) {
        n += other.n;
        if (n >= 998244353) {
            n -= 998244353;
        }
        return this;
    }

    public modint subtract(modint other) {
        n -= other.n;
        if (n < 0) {
            n += 998244353;
        }
        return this;
    }

    public modint multiply(modint other) {
        n = (int) ((long) n * other.n % 998244353);
        return this;
    }

    public modint divide(modint other) {
        if (other.n == 0) {
            throw new ArithmeticException("Division by zero");
        }
        return this.multiply(other.inverse());
    }

    public modint inverse() {
        long x = 0, y = 0;
        long g = gcd(n, 998244353, x, y);
        if (g != 1) {
            throw new ArithmeticException("not inversable");
        }
        return new modint(x);
    }

    private long gcd(long a, long b, long x, long y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        long d = gcd(b % a, a, y, x);
        x -= (b / a) * y;
        return d;
    }

    @Override
    public String toString() {
        return String.valueOf(n);
    }
}

public class 75d4b290ee8dc8b5628f2d26d93ae163xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Input in = new Input(System.in);
        Output out = new Output(System.out);
        TaskD solver = new TaskD();
        solver.solve(in, out);
        out.flush();
    }
}
