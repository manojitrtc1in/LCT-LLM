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

    public T get(int index) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.get(index);
    }

    public T set(int index, T element) {
        if (index >= size()) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return super.set(index, element);
    }
}

class arr<T> {
    private T[] b;
    private int n;

    public arr() {
        this.b = null;
        this.n = 0;
    }

    public arr(int n) {
        this.n = n;
        if (n < 0) {
            throw new OutOfMemoryError("bad alloc");
        }
        this.b = (T[]) new Object[n];
    }

    public arr(int n, T init) {
        this.n = n;
        if (n < 0) {
            throw new OutOfMemoryError("bad alloc");
        }
        this.b = (T[]) new Object[n];
        Arrays.fill(this.b, init);
    }

    public arr(Collection<T> l) {
        this.n = l.size();
        this.b = (T[]) new Object[n];
        int index = 0;
        for (T item : l) {
            this.b[index++] = item;
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

class Input {
    private BufferedReader in;
    private StringTokenizer st;

    public Input(InputStream stream) {
        in = new BufferedReader(new InputStreamReader(stream));
    }

    private String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(in.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
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

    public arr<Integer> readIntArray(int size) {
        arr<Integer> array = new arr<>(size);
        for (int i = 0; i < size; i++) {
            array.set(i, readInt());
        }
        return array;
    }
}

class Output {
    private PrintWriter out;

    public Output(OutputStream stream) {
        out = new PrintWriter(stream);
    }

    public void print(Object... args) {
        for (Object arg : args) {
            out.print(arg + " ");
        }
    }

    public void println(Object... args) {
        print(args);
        out.println();
    }

    public void flush() {
        out.flush();
    }
}

class TaskD {
    public void solve(Input in, Output out) {
        int n = in.readInt();
        int m = in.readInt();
        arr<Integer> b = in.readIntArray(n);
        arr<Integer> w = in.readIntArray(n);
        arr<Integer> x = in.readIntArray(n - 1);
        arr<Integer> y = in.readIntArray(n - 1);

        // Graph and other logic goes here...

        out.println("Result"); // Placeholder for the actual result
    }
}

public class 75d8de55b6fa2ec9613af64469d2cd87xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Input in = new Input(System.in);
        Output out = new Output(System.out);
        int n = in.readInt();
        TaskD solver = new TaskD();
        for (int i = 0; i < n; i++) {
            solver.solve(in, out);
        }
        out.flush();
    }
}
