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

class VectorBoolean extends Vector<Boolean> {
    public VectorBoolean() {
        super();
    }

    public VectorBoolean(int n) {
        super(n);
    }

    public VectorBoolean(int n, boolean value) {
        super(n, value);
    }

    public boolean get(int ind) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(ind);
    }

    public boolean set(int ind, boolean value) {
        if (ind >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(ind, value);
    }
}

class TaskD {
    private static final int MOD7 = 1000000007;
    private static final int MOD9 = 1000000009;
    private static final int MODF = 998244353;
    private static int mod = MOD7;

    public void solve(InputStream inp, PrintStream outp) {
        Scanner in = new Scanner(inp);
        int n = in.nextInt();
        Vector<Integer> x = new Vector<>(n);
        Vector<Integer> v = new Vector<>(n);
        Vector<Integer> p = new Vector<>(n);
        
        for (int i = 0; i < n; i++) {
            x.add(in.nextInt());
        }
        for (int i = 0; i < n; i++) {
            v.add(in.nextInt());
        }
        for (int i = 0; i < n; i++) {
            p.add(in.nextInt());
        }

        mod = MODF;
        Vector<Vector<ModInt>> pp = new Vector<>(4 * n);
        Vector<Vector<ModInt>> tmp = new Vector<>(4 * n);
        for (int i = 0; i < 4 * n; i++) {
            pp.add(new Vector<>(4));
            tmp.add(new Vector<>(4));
        }
        
        boolean[][] allowed = new boolean[n][4];
        for (int i = 0; i < n; i++) {
            Arrays.fill(allowed[i], true);
        }

        join(pp, tmp, 0, 0, n, x, p);
        
        Vector<Event> events = new Vector<>();
        for (int i = 1; i < n; i++) {
            events.add(new Event(2, i, x.get(i) - x.get(i - 1), v.get(i) + v.get(i - 1)));
            if (v.get(i) > v.get(i - 1)) {
                events.add(new Event(0, i, x.get(i) - x.get(i - 1), v.get(i) - v.get(i - 1)));
            } else if (v.get(i) < v.get(i - 1)) {
                events.add(new Event(3, i, x.get(i) - x.get(i - 1), v.get(i - 1) - v.get(i)));
            }
        }
        Collections.sort(events);

        ModInt answer = new ModInt(0);
        for (Event e : events) {
            Vector<ModInt> left = query(pp, tmp, 0, 0, n, 0, e.at);
            Vector<ModInt> right = query(pp, tmp, 0, 0, n, e.at, n);
            answer.add(new ModInt(e.dx).divide(e.v).multiply(left.get(e.type / 2).add(left.get(2 + e.type / 2))).multiply(right.get(e.type % 2 * 2).add(right.get(e.type % 2 * 2 + 1))));
            allowed[e.at][e.type] = false;
            recalc(pp, 0, 0, n, e.at);
        }
        outp.println(answer);
    }

    private void join(Vector<Vector<ModInt>> pp, Vector<Vector<ModInt>> tmp, int root, int left, int right, Vector<Integer> x, Vector<Integer> p) {
        // Implementation of join logic
    }

    private Vector<ModInt> query(Vector<Vector<ModInt>> pp, Vector<Vector<ModInt>> tmp, int root, int left, int right, int from, int to) {
        // Implementation of query logic
        return new Vector<>();
    }

    private void recalc(Vector<Vector<ModInt>> pp, int root, int left, int right, int at) {
        // Implementation of recalc logic
    }

    class Event implements Comparable<Event> {
        int type;
        int at;
        int dx;
        int v;

        Event(int type, int at, int dx, int v) {
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

    class ModInt {
        int n;

        ModInt(int n) {
            this.n = n % mod;
            if (this.n < 0) {
                this.n += mod;
            }
        }

        ModInt add(ModInt other) {
            n += other.n;
            if (n >= mod) {
                n -= mod;
            }
            return this;
        }

        ModInt multiply(ModInt other) {
            n = (int) ((long) n * other.n % mod);
            return this;
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            // Implementation of modular inverse
            return new ModInt(1); // Placeholder
        }
    }

    public static void main(String[] args) {
        TaskD solver = new TaskD();
        solver.solve(System.in, System.out);
    }
}
