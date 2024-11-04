import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		id0 solver = new id0();
		solver.solve(1, in, out);
		out.close();
	}
}

class id0 {

    Graph G;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int maxY = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            maxY = Math.max(maxY, y[i]);
        }
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if (y[i] == maxY) {
                if (id == -1) {
                    id = i;
                } else {
                    out.println(-1);
                    return;
                }
            }
        }

        int N = n + n + 2;
        int S = n + n;
        int T = n + n + 1;
        G = new Graph();
        G.id5(N, N * N);






        for (int i = 0; i < n; ++i) {
            

            G.id7(S, i, 2, 0);
        }
        for (int i = 0; i < n; ++i) {
            if (i != id) {
                

                G.id7(i + n, T, 1, 0);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (y[i] > y[j]) {
                        G.id7(i, j + n, 1, Math.round(1e11 * new Point(x[i], y[i]).distanceTo(new Point(x[j], y[j]))));
                        

                    }
                }
            }
        }

        id3 id2 = new id3(G, S, T, false);
        Pair<Long, Long> res = id2.id1();
        if (res.first != n-1) {
            out.println(-1);
            return;
        }
        out.println(res.second / 1e11);




























    }

}

class Graph {
    public int[] from;
    public int[] to;
    public int[] first;
    public int[] next;
    public long[] cost;
    public int[] capacity;
    public long[] flow;
    public int[] last;
    public int nVertex;
    public int nEdges;
    int[] reverseEdge;
    public int curEdge;

    public Graph() {}

    public void id5(int n, int m) {
        curEdge = 0;
        nVertex = n;
        nEdges = m;
        from = new int[m * 2];
        to = new int[m * 2];
        first = new int[n];
        next = new int[m * 2];
        cost = new long[m * 2];
        capacity = new int[m * 2];
        flow = new long[m * 2];
        reverseEdge = new int[m * 2];
        last = new int[m * 2];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);
    }

    public void id7(int a, int b, int f, long c) {


        next[curEdge] = first[a];
        first[a] = curEdge;
        to[curEdge] = b;
        from[curEdge] = a;
        cost[curEdge] = c;
        capacity[curEdge] = f;
        flow[curEdge] = 0;
        reverseEdge[curEdge] = curEdge + 1;
        ++curEdge;

        next[curEdge] = first[b];
        first[b] = curEdge;
        to[curEdge] = a;
        from[curEdge] = b;
        cost[curEdge] = -c;
        capacity[curEdge] = 0;
        flow[curEdge] = 0;
        reverseEdge[curEdge] = curEdge - 1;
        ++curEdge;
    }

    public boolean isSparse() {
        return nVertex == 0 || nEdges * 20 / nVertex <= nVertex;
    }

}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

}

class Point implements Comparable<Point> {
    public double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + ", " + y + " )";
    }

    public boolean equals(Object o) {
        Point p = (Point) o;
        return DoubleUtils.compareTo(x, p.x) == 0 && DoubleUtils.compareTo(y, p.y) == 0;
    }

    public int hashCode() {
        int result;
        long temp;
        temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
        result = (int) (temp ^ (temp >>> 32));
        temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
        result = 31 * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    public Point sub(Point p) {
        return new Point(x - p.x, y - p.y);
    }

    public double dotProduct(Point p) {
        return x * p.x + y * p.y;
    }

    public double length() {
        return DoubleUtils.sqrt(dotProduct(this));
    }

    public double distanceTo(Point p) {
        return sub(p).length();
    }

    

    public int compareTo(Point o) {
        int temp = DoubleUtils.compareTo(x, o.x);
        if (temp == 0) {
            return DoubleUtils.compareTo(y, o.y);
        }
        return temp;
    }
}

class id3 {

    private final static long INF = Long.MAX_VALUE / 2;

    Graph g;
    int source;
    int dest;
    long[] phi;
    long[] dst;
    int n;
    Heap heap;
    boolean[] visited;
    long flow;
    int[] parent;
    long cost;

    public id3(Graph g, int source, int dest, boolean id4) {
        this.flow = 0;
        this.cost = 0;
        this.g = g;
        this.source = source;
        this.dest = dest;
        this.n = g.nVertex;
        dst = new long[n];
        parent = new int[n];
        phi = new long[n];
        if (id4) {
            id6();
        }
        if (g.isSparse()) {
            heap = new Heap(n, new IntComparator() {
                public int compare(int first, int second) {
                    return IntegerUtils.longCompare(dst[first], dst[second]);
                }
            }, n);
            visited = null;
        } else {
            heap = null;
            visited = new boolean[n];
        }
    }

    private void id6() {
        Arrays.fill(phi, Long.MAX_VALUE);
        phi[source] = 0;
        boolean finished = false;
        for (int i = 0; i < n && !finished; ++i) {
            finished = true;
            for (int v = 0; v < n; ++v) {
                for (int j = g.first[v]; j != -1; j = g.next[j]) {
                    int to = g.to[j];
                    long total = phi[v] + g.cost[j];
                    if (g.capacity[j] != 0 && phi[to] > total) {
                        phi[to] = total;
                        finished = false;
                    }
                }
            }
        }
    }

    void dijkstra() {
        Arrays.fill(parent, -1);
        Arrays.fill(dst, INF);
        dst[source] = 0;
        heap.add(source);
        while (!heap.isEmpty()) {
            int v = heap.poll();
            for (int eid = g.first[v]; eid != -1; eid = g.next[eid]) {
                int to = g.to[eid];
                if (g.capacity[eid] > g.flow[eid]) {
                    long total = g.cost[eid] + phi[v] - phi[to] + dst[v];
                    if (dst[to] > total) {
                        dst[to] = total;
                        if (heap.getIndex(to) == -1) {
                            heap.add(to);
                        } else {
                            heap.shiftUp(heap.getIndex(to));
                        }
                        parent[to] = eid;
                    }
                }
            }

        }
    }

    void id8() {
        Arrays.fill(parent, -1);
        Arrays.fill(dst, INF);
        Arrays.fill(visited, false);
        dst[source] = 0;
        for (int i = 0; i < n; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (v == -1 || dst[v] > dst[j])) {
                    v = j;
                }
            }
            if (v == -1 || dst[v] >= INF) {
                break;
            }
            visited[v] = true;
            for (int eid = g.first[v]; eid != -1; eid = g.next[eid]) {
                int to = g.to[eid];
                if (g.capacity[eid] > g.flow[eid]) {
                    if (!visited[to]) {
                        long total = g.cost[eid] + phi[v] - phi[to] + dst[v];
                        if (dst[to] > total) {
                            dst[to] = total;
                            parent[to] = eid;
                        }
                    }
                }
            }
        }
    }

    public Pair<Long, Long> id1() {
        return id1(INF);
    }

    public Pair<Long, Long> id1(long maxFlow) {
        while (maxFlow != 0) {
            if (g.isSparse()) {
                dijkstra();
            } else {
                id8();
            }
            if (parent[dest] == -1) {
                return Pair.makePair(flow, cost);
            }
            for (int i = 0; i < n; ++i) {
                if (dst[i] != INF) {
                    phi[i] += dst[i];
                }
            }
            int cur = dest;
            long curCost = 0;
            long min = INF;
            while (cur != source) {
                int id = parent[cur];
                min = Math.min(min, g.capacity[id] - g.flow[id]);
                curCost += g.cost[id];
                cur = g.from[id];
            }
            maxFlow -= min;
            flow += min;
            cost += min * curCost;
            cur = dest;
            while (cur != source) {
                int id = parent[cur];
                g.flow[id] += min;
                g.flow[g.reverseEdge[id]] -= min;
                cur = g.from[id];
            }
        }
        return Pair.makePair(flow, cost);
    }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

class DoubleUtils {
    public static final double EPS = 1e-10;

    public static int compareTo(double a, double b) {
        if (doubleEqual(a, b)) {
            return 0;
        }
        if (a < b) {
            return -1;
        }
        return 1;
    }

    private static boolean doubleEqual(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

    public static double sqrt(double a) {
        if (compareTo(a, 0) < 0) {
            System.exit(1);
        }
        if (a < 0) return 0;
        return Math.sqrt(a);
    }

}

class Heap {
    private IntComparator comparator;
    private int size = 0;
    private int[] elements;
    private int[] at;

    public Heap(int capacity, IntComparator comparator, int maxElement) {
        this.comparator = comparator;
        elements = new int[capacity];
        at = new int[maxElement];
        Arrays.fill(at, -1);
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int add(int element) {
        ensureCapacity(size + 1);
        elements[size] = element;
        at[element] = size;
        shiftUp(size++);
        return at[element];
    }

    public void shiftUp(int index) {
        int value = elements[index];
        while (index != 0) {
            int parent = (index - 1) >>> 1;
            int parentValue = elements[parent];
            if (comparator.compare(parentValue, value) <= 0) {
                elements[index] = value;
                at[value] = index;
                return;
            }
            elements[index] = parentValue;
            at[parentValue] = index;
            index = parent;
        }
        elements[0] = value;
        at[value] = 0;
    }

    public void shiftDown(int index) {
        while (true) {
            int child = (index << 1) + 1;
            if (child >= size) {
                return;
            }
            if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0) {
                child++;
            }
            if (comparator.compare(elements[index], elements[child]) <= 0) {
                return;
            }
            swap(index, child);
            index = child;
        }
    }

    public int getIndex(int element) {
        return at[element];
    }

    private void swap(int first, int second) {
        int temp = elements[first];
        elements[first] = elements[second];
        elements[second] = temp;
        at[elements[first]] = first;
        at[elements[second]] = second;
    }

    private void ensureCapacity(int size) {
        if (elements.length < size) {
            int[] oldElements = elements;
            elements = new int[Math.max(2 * elements.length, size)];
            System.arraycopy(oldElements, 0, elements, 0, this.size);
        }
    }

    public int poll() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        int result = elements[0];
        at[result] = -1;
        if (size == 1) {
            size = 0;
            return result;
        }
        elements[0] = elements[--size];
        at[elements[0]] = 0;
        shiftDown(0);
        return result;
    }

}

interface IntComparator {

    public int compare(int first, int second);
}

class IntegerUtils {

    public static int longCompare(long a, long b) {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

}

