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
        FRainOfFire solver = new FRainOfFire();
        solver.solve(1, in, out);
        out.close();
    }

    static class FRainOfFire {
        Point[] ps;
        Graph graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ps = in.readPolygon(n);


            graph = buildGraph(n);

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

            int answer = ArrayUtils.firstTrue(1, (int) 2e9, this::solveForMid);

            out.println(answer);
        }

        private boolean solveForMid(int t) {
            if (t < 1 || t > 2e9) throw new IllegalStateException("invalid value for t");

            List<List<Integer>> components = new ArrayList<>();
            boolean[] visited = new boolean[ps.length];
            for (int i = 0; i < ps.length; ++i) {
                if (!visited[i]) {
                    var comp = new ArrayList<Integer>();
                    boundedDfs(i, t, visited, comp);
                    components.add(comp);
                }
            }

            if (components.size() == 1) return true;
            if (components.size() > 4) return false;

            int minIndex = ArrayUtils.argMin(components, Comparator.comparingInt(List::size));

            List<Integer> smallestComponent = components.get(minIndex);

            IntSet xs = new IntSet();
            for (var id : smallestComponent) {
                xs.add(ps[id].x);
            }

            smallestComponent.sort(Comparator.comparingInt(i -> ps[i].y));

            outer:
            for (int x0 : xs) {
                LinkedList<IntPair> segments = getPossibleIntervalsForY(t, smallestComponent, x0);

                for (int i = 0; i < components.size(); ++i) {
                    if (i == minIndex) continue;

                    List<Integer> component = components.get(i);
                    component.sort(Comparator.comparingInt(id -> ps[id].y));
                    var otherSegments = getPossibleIntervalsForY(t, component, x0);
                    if (otherSegments.isEmpty()) continue outer;
                    segments = intersectSegments(segments, otherSegments);
                    if (segments.isEmpty()) continue outer;
                }
                if (!segments.isEmpty()) return true;
            }

            IntSet ys = new IntSet();
            for (var id : smallestComponent) {
                ys.add(ps[id].y);
            }

            smallestComponent.sort(Comparator.comparingInt(i -> ps[i].x));

            outer:
            for (int y0 : ys) {
                LinkedList<IntPair> segments = getPossibleIntervalsForX(t, smallestComponent, y0);

                for (int i = 0; i < components.size(); ++i) {
                    if (i == minIndex) continue;

                    List<Integer> component = components.get(i);
                    component.sort(Comparator.comparingInt(id -> ps[id].x));
                    var otherSegments = getPossibleIntervalsForX(t, component, y0);
                    if (otherSegments.isEmpty()) continue outer;
                    segments = intersectSegments(segments, otherSegments);
                    if (segments.isEmpty()) continue outer;
                }
                if (!segments.isEmpty()) return true;
            }

            return false;
        }

        private LinkedList<IntPair> getPossibleIntervalsForX(int t, List<Integer> smallestComponent, int y0) {
            LinkedList<IntPair> segments = new LinkedList<>();
            for (int id : smallestComponent) {
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

        private LinkedList<IntPair> intersectSegments(LinkedList<IntPair> segments, LinkedList<IntPair> otherSegments) {





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

        private LinkedList<IntPair> getPossibleIntervalsForY(int t, List<Integer> smallestComponent, int x0) {
            LinkedList<IntPair> segments = new LinkedList<>();
            for (int id : smallestComponent) {
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

        private void boundedDfs(int node, int t, boolean[] visited, ArrayList<Integer> comp) {
            comp.add(node);
            visited[node] = true;

            for (int neighbor : graph.getEdgesFrom(node)) {
                if (!visited[neighbor] && ps[node].manhattanDistanceToPoint(ps[neighbor]) <= t) {
                    boundedDfs(neighbor, t, visited, comp);
                }
            }
        }

        private void initialVisit(int v, Graph graph, boolean[] visited) {
            visited[v] = true;
            for (var neighbor : graph.getEdgesFrom(v)) {
                if (!visited[neighbor]) {
                    initialVisit(neighbor, graph, visited);
                }
            }
        }

        private Graph buildGraph(int n) {
            Graph graph = new Graph(n);
            Pair<Point, Integer>[] indexedPoints = IntStream.range(0, n)
                    .mapToObj(i -> Pair.of(ps[i], i))
                    .toArray(Pair[]::new);

            Arrays.sort(indexedPoints);
            for (int i = 1; i < n; ++i) {
                int index = indexedPoints[i].second;
                int prevIndex = indexedPoints[i - 1].second;
                if (indexedPoints[i].first.x == indexedPoints[i - 1].first.x) {
                    graph.addEdge(index, prevIndex);
                }
            }

            var yComparator = Point.YCoordinateFirstComparator();
            Arrays.sort(indexedPoints, (a, b) -> yComparator.compare(a.first, b.first));
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

        public IntList getEdgesFrom(int i) {
            if (i < 0 || i >= V)
                throw new IllegalArgumentException("Argument must be in [0, V).");
            return this.edges[i];
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

    static class ArrayUtils {
        public static <T> int argMin(List<T> list, Comparator<T> comparator) {
            int minIndex = -1;
            T minValue = null;

            Iterator<T> iter = list.iterator();
            int currentIndex = 0;
            while (iter.hasNext()) {
                T currentValue = iter.next();
                if (minValue == null) {
                    minValue = currentValue;
                    minIndex = currentIndex;
                } else if (comparator.compare(currentValue, minValue) < 0) {
                    minValue = currentValue;
                    minIndex = currentIndex;
                }
                currentIndex++;
            }
            return minIndex;
        }

        public static int firstTrue(int low, int high, IntPredicate predicate) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (predicate.test(mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low;
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

        public int manhattanDistanceToPoint(Point other) {
            return Math.abs(this.x - other.x) + Math.abs(this.y - other.y);
        }

        public static Comparator<Point> YCoordinateFirstComparator() {
            return (a, b) -> {
                if (a.y == b.y) {
                    return Integer.compare(a.x, b.x);
                }
                return Integer.compare(a.y, b.y);
            };
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

    static class IntList implements Iterable<Integer> {
        public static final int INITIAL_CAPACITY = 4;
        private int size;
        private int[] array;

        public IntList() {
            this(INITIAL_CAPACITY);
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
            return new IntListIterator();
        }

        private class IntListIterator implements Iterator<Integer> {
            private int current;

            public IntListIterator() {
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
}

