import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.function.IntPredicate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractSequentialList;
import java.io.FileNotFoundException;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id11 solver = new id11();
        solver.solve(1, in, out);
        out.close();
    }

    static class id11 {
        Point[] ps;
        Graph graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ps = in.readPolygon(n);

            Pair<Point, Integer>[] indexedPoints = IntStream.range(0, n).mapToObj(i -> Pair.of(ps[i], i)).toArray(Pair[]::new);

            graph = buildGraph(n, indexedPoints);

            boolean[] visited = new boolean[n];
            int components = 0;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    components++;
                    initialVisit(i, graph, visited);
                }
            }

            if (components >= 3) {
                out.minusOne();
                return;
            }

            int answer = ArrayUtils.firstTrue(1, (int) 2e9, this::id10);

            out.println(answer);
        }

        private boolean id10(int t) {
            if (t < 1 || t > 2e9) throw new IllegalStateException("invalid value for t");

            List<List<Integer>> components = new ArrayList<>();
            boolean[] visited = new boolean[ps.length];
            for (int i = 0; i < ps.length; ++i) {
                if (!visited[i]) {
                    var comp = new ArrayList<Integer>();
                    id0(i, t, visited, comp);
                    components.add(comp);
                }
            }

            if (components.size() == 1) return true;

            for (int i = 0; i < components.size(); ++i) {
                for (int j = i + 1; j < components.size(); j++) {
                    for (int id : components.get(i)) {
                        for (int jd : components.get(j)) {
                            if (ps[id].x == ps[jd].x) {
                                if (Math.abs(ps[id].y - ps[jd].y) <= t) {
                                    throw new IllegalStateException(String.format("found the counter-example. ps[%d].y - ps[$d].y <= t", id, jd));
                                }
                            }
                            if (ps[id].y == ps[jd].y) {
                                if (Math.abs(ps[id].x - ps[jd].x) <= t) {
                                    throw new IllegalStateException("found the counter-example");
                                }
                            }
                        }
                    }
                }
            }

            if (components.size() > 4) return false;

            int minSize = Integer.MAX_VALUE;
            int minIndex = -1;




















































            for (int i = 0; i < components.size(); i++) {
                if (components.get(i).size() < minSize) {
                    minSize = components.get(i).size();
                    minIndex = i;
                }
            }

            List<Integer> id2 = components.get(minIndex);

            IntSet xs = new IntSet();
            for (var id : id2) {
                xs.add(ps[id].x);
            }

            id2.sort(Comparator.comparingInt(i -> ps[i].y));

            outer:
            for (int x0 : xs) {
                LinkedList<IntPair> segments = id3(t, id2, x0);

                for (int i = 0; i < components.size(); ++i) {
                    if (i == minIndex) continue;

                    List<Integer> component = components.get(i);
                    component.sort(Comparator.comparingInt(id -> ps[id].y));
                    var otherSegments = id3(t, component, x0);
                    if (otherSegments.isEmpty()) continue outer;
                    segments = id7(segments, otherSegments);
                    if (segments.isEmpty()) continue outer;
                }
                if (!segments.isEmpty()) return true;
            }

            IntSet ys = new IntSet();
            for (var id : id2) {
                ys.add(ps[id].y);
            }

            id2.sort(Comparator.comparingInt(i -> ps[i].x));

            outer:
            for (int y0 : ys) {
                LinkedList<IntPair> segments = id6(t, id2, y0);

                for (int i = 0; i < components.size(); ++i) {
                    if (i == minIndex) continue;

                    List<Integer> component = components.get(i);
                    component.sort(Comparator.comparingInt(id -> ps[id].x));
                    var otherSegments = id6(t, component, y0);
                    if (otherSegments.isEmpty()) continue outer;
                    segments = id7(segments, otherSegments);
                    if (segments.isEmpty()) continue outer;
                }
                if (!segments.isEmpty()) return true;
            }

            return false;
        }

        private LinkedList<IntPair> id6(int t, List<Integer> id2, int y0) {
            LinkedList<IntPair> segments = new LinkedList<>();
            for (int id : id2) {
                if (ps[id].y == y0) {
                    int low = (int) Math.max((int) -1e9, (long) ps[id].x - t);
                    int high = (int) Math.min((int) 1e9, (long) ps[id].x + t);
                    if (segments.isEmpty()) {
                        segments.add(IntPair.of(low, high));
                        continue;
                    }
                    Iterator<IntPair> iter = segments.descendingIterator();
                    boolean done = false;
                    while (iter.hasNext()) {
                        var current = iter.next();
                        if (high < current.first) throw new IllegalStateException("unexpected situation");
                        if (current.first <= low && high <= current.second) {
                            done = true;
                            break;
                        }
                        if (low < current.first) {
                            high = Math.max(high, current.second);
                            iter.remove();
                        } else if (low <= current.second + 1) {
                            current.second = high;
                            done = true;
                            break;
                        } else {
                            break;
                        }
                    }

                    if (segments.isEmpty() || !done) {
                        segments.add(IntPair.of(low, high));
                    }

                } else if (Math.abs(y0 - (long) ps[id].y) <= t) {
                    int low = ps[id].x;
                    int high = ps[id].x;

                    if (segments.isEmpty()) {
                        segments.add(IntPair.of(low, high));
                        continue;
                    }

                    var current = segments.getLast();
                    if (current.second == low - 1) {
                        current.second = high;
                    } else if (current.second < low) {
                        segments.add(IntPair.of(low, high));
                    } else if (high < current.first) {
                        throw new IllegalStateException("single interval can't be smaller");
                    }
                }
            }

            return segments;
        }

        private LinkedList<IntPair> id7(LinkedList<IntPair> segments, LinkedList<IntPair> otherSegments) {
            id5(segments);
            id5(otherSegments);

            var result = new LinkedList<IntPair>();
            var iter = segments.iterator();
            var otherIter = otherSegments.iterator();
            var segment = iter.next();
            var otherSegment = otherIter.next();

            while (true) {
                if (segment.intersects(otherSegment)) {
                    var copy = segment.clone();
                    copy.intersect(otherSegment);
                    result.add(copy);
                }
                if (segment.second < otherSegment.second) {
                    if (!iter.hasNext()) break;
                    segment = iter.next();
                } else {
                    if (!otherIter.hasNext()) break;
                    otherSegment = otherIter.next();
                }
            }

            return result;
        }

        private void id5(LinkedList<IntPair> segments) {
            IntPair prev = null;
            for (var next : segments) {
                if (prev != null) {
                    if (prev.second >= next.first) throw new IllegalStateException("wrongly ordered");
                }
                prev = next;
            }
        }

        private LinkedList<IntPair> id3(int t, List<Integer> id2, int x0) {
            LinkedList<IntPair> segments = new LinkedList<>();
            for (int id : id2) {
                if (ps[id].x == x0) {
                    int low = (int) Math.max((long) -1e9, (long) ps[id].y - t);
                    int high = (int) Math.min((long) 1e9, (long) ps[id].y + t);
                    if (segments.isEmpty()) {
                        segments.add(IntPair.of(low, high));
                        continue;
                    }
                    Iterator<IntPair> iter = segments.descendingIterator();
                    boolean done = false;
                    while (iter.hasNext()) {
                        var current = iter.next();
                        if (high < current.first) throw new IllegalStateException("unexpected situation");
                        if (current.first <= low && high <= current.second) {
                            done = true;
                            break;
                        }
                        if (low < current.first) {
                            high = Math.max(high, current.second);
                            iter.remove();
                        } else if (low <= current.second + 1) {
                            current.second = high;
                            done = true;
                            break;
                        } else {
                            break;
                        }
                    }

                    if (segments.isEmpty() || !done) {
                        segments.add(IntPair.of(low, high));
                    }

                } else if (Math.abs((long) x0 - ps[id].x) <= t) {
                    int low = ps[id].y;
                    int high = ps[id].y;

                    if (segments.isEmpty()) {
                        segments.add(IntPair.of(low, high));
                        continue;
                    }

                    var current = segments.getLast();
                    if (current.second == low - 1) {
                        current.second = high;
                    } else if (current.second < low) {
                        segments.add(IntPair.of(low, high));
                    } else if (high < current.first) {
                        throw new IllegalStateException("single interval can't be smaller");
                    }
                }
            }

            return segments;
        }

        private void id0(int node, int t, boolean[] visited, ArrayList<Integer> comp) {
            comp.add(node);
            visited[node] = true;

            for (int neighbor : graph.id1(node)) {
                if (!visited[neighbor] && ps[node].id8(ps[neighbor]) <= t) {
                    id0(neighbor, t, visited, comp);
                }
            }
        }

        private void initialVisit(int v, Graph graph, boolean[] visited) {
            visited[v] = true;
            for (var neighbor : graph.id1(v)) {
                if (!visited[neighbor]) {
                    initialVisit(neighbor, graph, visited);
                }
            }
        }

        private Graph buildGraph(int n, Pair<Point, Integer>[] indexedPoints) {
            Graph graph = new Graph(n);

            Arrays.sort(indexedPoints);
            for (int i = 1; i < n; ++i) {
                int index = indexedPoints[i].second;
                int prevIndex = indexedPoints[i - 1].second;
                if (indexedPoints[i].first.x == indexedPoints[i - 1].first.x) {
                    graph.addEdge(index, prevIndex);
                }
            }

            Arrays.sort(indexedPoints, (a, b) -> {
                if (a.first.y == b.first.y) {
                    return Integer.compare(a.first.x, b.first.x);
                }
                return Integer.compare(a.first.y, b.first.y);
            });
            for (int i = 1; i < n; ++i) {
                int index = indexedPoints[i].second;
                int prevIndex = indexedPoints[i - 1].second;
                if (indexedPoints[i].first.y == indexedPoints[i - 1].first.y) {
                    graph.addEdge(index, prevIndex);
                }
            }
            return graph;
        }

    }

    static class InputReader extends BufferedReader {
        StringTokenizer tokenizer;

        public InputReader(InputStream inputStream) {
            super(new InputStreamReader(inputStream), 32768);
        }

        public InputReader(String filename) {
            super(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream(filename)));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = readLine();
                    if (line == null) continue;
                    tokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
            }
            return tokenizer.nextToken();
        }

        public Integer nextInt() {
            return Integer.valueOf(next());
        }

        public Point[] readPolygon(int n) {
            Point[] vertex = new Point[n];
            for (int i = 0; i < n; ++i)
                vertex[i] = new Point(nextInt(), nextInt());

            return vertex;
        }

    }

    static class ArrayUtils {
        public static int firstTrue(int low, int high, IntPredicate predicate) {
            while (low <= high) {
                int mid = (int) (((long) low + high) / 2);
                if (predicate.test(mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

    }

    static class IntSet extends HashSet<Integer> {
        public IntSet() {
            super();
        }

        public IntSet(int initialCapacity) {
            super(initialCapacity);
        }

    }

    static class IntPair implements Comparable<IntPair> {
        public int first;
        public int second;

        public IntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(IntPair o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
        }

        public String toString() {
            return first + " " + second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof IntPair)) return false;
            IntPair intPair = (IntPair) o;
            return first == intPair.first &&
                    second == intPair.second;
        }

        public int hashCode() {
            return (31 * first + second);
        }

        public IntPair clone() {
            return of(first, second);
        }

        public boolean intersects(IntPair other) {
            return Math.max(this.first, other.first) <= Math.min(this.second, other.second);
        }

        public void intersect(IntPair other) {
            this.first = Math.max(this.first, other.first);
            this.second = Math.min(this.second, other.second);
        }

        public static IntPair of(int first, int second) {
            return new IntPair(first, second);
        }

    }

    static class Point implements Comparable<Point> {
        public int x;
        public int y;

        public Point() {
            this.x = 0;
            this.y = 0;
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object that) {
            Point other = (Point) that;
            return this.x == other.x && this.y == other.y;
        }

        public int compareTo(Point o) {
            if (x != o.x) return Integer.compare(x, o.x);
            return Integer.compare(y, o.y);
        }

        public int id8(Point other) {
            return Math.abs(this.x - other.x) + Math.abs(this.y - other.y);
        }

        public String toString() {
            return x + " " + y;
        }

        public int hashCode() {
            return 31 * x + y;
        }

        public Point clone() {
            return new Point(this.x, this.y);
        }

    }

    static class IntList implements Iterable<Integer> {
        public static final int id4 = 4;
        private int size;
        private int[] array;

        public IntList() {
            this(id4);
        }

        public IntList(int initialCapacity) {
            this.array = new int[initialCapacity];
            this.size = 0;
        }

        public IntList(int[] array) {
            this.array = Arrays.copyOf(array, array.length);
            this.size = this.array.length;
        }

        public IntList(Collection<Integer> collection) {
            this.size = collection.size();
            this.array = new int[size];
            int index = 0;
            for (int e : collection) {
                array[index++] = e;
            }
        }

        public void add(int value) {
            if (size == array.length) {
                ensureCapacity();
            }

            this.array[this.size++] = value;
        }

        private void ensureCapacity() {
            if (size < array.length)
                return;
            this.array = Arrays.copyOf(array, array.length << 1);
        }

        public int[] toArray() {
            return Arrays.copyOf(this.array, this.size);
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(array, this.size));
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            IntList integers = (IntList) o;
            return size == integers.size &&
                    Arrays.equals(integers.array, 0, integers.size, this.array, 0, this.size);
        }

        public int hashCode() {
            int result = Objects.hash(size);
            result = 31 * result + Arrays.hashCode(toArray());
            return result;
        }

        public IntList clone() {
            IntList cloned = new IntList(Math.max(1, this.size));
            for (int i = 0; i < size; ++i)
                cloned.add(array[i]);
            return cloned;
        }

        public Iterator<Integer> iterator() {
            return new id9();
        }

        private class id9 implements Iterator<Integer> {
            private int current;

            public id9() {
                this.current = 0;
            }

            public boolean hasNext() {
                return this.current < size;
            }

            public Integer next() {
                return array[current++];
            }

        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(outputStream);
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public OutputWriter(String filename) throws FileNotFoundException {
            super(filename);
        }

        public void minusOne() {
            println(-1);
        }

        public void close() {
            super.close();
        }

    }

    static class Graph {
        public int V;
        public boolean directed = false;
        private IntList[] edges;

        public Graph() {
        }

        public Graph(int v) {
            this(v, false);
        }

        public Graph(int v, boolean directed) {
            this.V = v;
            this.directed = directed;
            this.edges = new IntList[V];
            for (int i = 0; i < V; i++) {
                edges[i] = new IntList(4);
            }
        }

        public void addEdge(int u, int v) {


            edges[u].add(v);
            if (!directed) {


                edges[v].add(u);
            }
        }

        public IntList id1(int i) {
            if (i < 0 || i >= V)
                throw new IllegalArgumentException("Argument must be in [0, V).");
            return this.edges[i];
        }

    }

    static class Pair<K extends Comparable<K>, V> implements Comparable<Pair<K, V>> {
        public K first;
        public V second;

        public Pair(K first, V second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair<K, V> o) {
            return first.compareTo(o.first);
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair<K, V> pair = (Pair<K, V>) o;
            return this.compareTo(pair) == 0;
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return String.format("{" + first + ", " + second + '}');
        }

        public static <K extends Comparable<K>, V> Pair<K, V> of(K first, V second) {
            return new Pair<>(first, second);
        }

    }
}

