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

class arr<T> {
    private T[] b;
    private int n;

    public arr(int n) {
        this.n = n;
        b = (T[]) new Object[n];
    }

    public arr(int n, T init) {
        this.n = n;
        b = (T[]) new Object[n];
        Arrays.fill(b, init);
    }

    public arr(T[] array) {
        this.n = array.length;
        b = array;
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

    public T[] toArray() {
        return b;
    }
}

class arr2d<T> {
    private T[][] b;
    private int d1, d2;

    public arr2d(int d1, int d2) {
        this.d1 = d1;
        this.d2 = d2;
        b = (T[][]) new Object[d1][d2];
    }

    public T get(int i1, int i2) {
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        return b[i1][i2];
    }

    public void set(int i1, int i2, T value) {
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw new IndexOutOfBoundsException("Out of bounds");
        }
        b[i1][i2] = value;
    }

    public int dim1() {
        return d1;
    }

    public int dim2() {
        return d2;
    }
}

class Input {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Input(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
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

    public String readString() throws IOException {
        return next();
    }

    public arr<Integer> readIntArray(int size) throws IOException {
        arr<Integer> array = new arr<>(size);
        for (int i = 0; i < size; i++) {
            array.set(i, readInt());
        }
        return array;
    }

    public arr2d<Integer> readTable(int rows, int cols) throws IOException {
        arr2d<Integer> table = new arr2d<>(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                table.set(i, j, readInt());
            }
        }
        return table;
    }
}

class Output {
    private PrintWriter writer;

    public Output(OutputStream out) {
        writer = new PrintWriter(out);
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

class TaskD {
    public void solve(Input in, Output out) throws IOException {
        int n = in.readInt();
        int m = in.readInt();
        arr<Integer> b = in.readIntArray(n);
        arr<Integer> w = in.readIntArray(n);
        arr<Integer> x = in.readIntArray(n - 1);
        arr<Integer> y = in.readIntArray(n - 1);

        Graph<BiEdge> graph = new Graph<>(n);
        for (int i = 0; i < n - 1; i++) {
            graph.addEdge(new BiEdge(x.get(i), y.get(i)));
        }

        arr<Integer> q = new arr<>(n);
        calcQ(graph, q, 0, -1);

        arr2d<Pair> answer = new arr2d<>(3000, 3002);
        go(graph, answer, q, b, w, 0, -1);

        out.println(answer.get(0, m).first);
    }

    private int calcQ(Graph<BiEdge> graph, arr<Integer> q, int vert, int last) {
        int res = 1;
        for (BiEdge e : graph.getEdges(vert)) {
            int next = e.to;
            if (next == last) continue;
            res += calcQ(graph, q, next, vert);
        }
        q.set(vert, res);
        return res;
    }

    private void go(Graph<BiEdge> graph, arr2d<Pair> answer, arr<Integer> q, arr<Integer> b, arr<Integer> w, int vert, int last) {
        int id = -1;
        for (BiEdge e : graph.getEdges(vert)) {
            int next = e.to;
            if (next == last) continue;
            go(graph, answer, q, b, w, next, vert);
            if (id == -1 || q.get(next) > q.get(id)) {
                id = next;
            }
        }

        Pair delta = new Pair(0, w.get(vert) - b.get(vert));
        if (id == -1) {
            answer.set(vert, new Pair(0, delta.second));
            return;
        }

        Pair aid = answer.get(id);
        for (int i = 0; i <= q.get(id); i++) {
            answer.set(vert, new Pair(aid.first, aid.second + delta.second));
        }

        int sz = q.get(id);
        for (BiEdge e : graph.getEdges(vert)) {
            int next = e.to;
            if (next == last || next == id) continue;
            Pair anext = answer.get(next);
            for (int i = 0; i <= sz; i++) {
                for (int j = 0; j <= q.get(next); j++) {
                    maxim(answer.get(vert), new Pair(anext.first + answer.get(vert).first, anext.second + answer.get(vert).second));
                }
            }
            sz += q.get(next);
        }
    }

    private void maxim(Pair current, Pair newPair) {
        if (newPair.first > current.first) {
            current.first = newPair.first;
            current.second = newPair.second;
        }
    }
}

class Graph<E> {
    private List<List<E>> edges;
    private int vertexCount;

    public Graph(int vertexCount) {
        this.vertexCount = vertexCount;
        edges = new ArrayList<>(vertexCount);
        for (int i = 0; i < vertexCount; i++) {
            edges.add(new ArrayList<>());
        }
    }

    public void addEdge(E edge) {
        edges.get(edge.from).add(edge);
    }

    public List<E> getEdges(int vertex) {
        return edges.get(vertex);
    }
}

class BiEdge {
    public final int from;
    public final int to;

    public BiEdge(int from, int to) {
        this.from = from;
        this.to = to;
    }
}

class Pair {
    public int first;
    public long second;

    public Pair(int first, long second) {
        this.first = first;
        this.second = second;
    }
}

public class 75d8de55b6fa2ec9613af64469d2cd87_nc {
    public static void main(String[] args) throws IOException {
        Input in = new Input(System.in);
        Output out = new Output(System.out);
        TaskD solver = new TaskD();
        int n = in.readInt();
        for (int i = 0; i < n; i++) {
            solver.solve(in, out);
        }
        out.flush();
    }
}
