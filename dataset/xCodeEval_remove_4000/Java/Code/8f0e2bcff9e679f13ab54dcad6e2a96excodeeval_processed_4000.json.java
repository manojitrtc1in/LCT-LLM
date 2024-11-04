import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Thread t = new Thread(null, new Run(in, out), "name", 1 << 28);
            t.start();
            try {
                t.join();
            } catch (InterruptedException e) {

            }
        }

        public class Run extends Thread {
            InputReader in;
            OutputWriter out;

            public Run(InputReader in, OutputWriter out) {
                this.in = in;
                this.out = out;
            }


            public void run() {
                int n, m;
                n = in.readInt();
                m = in.readInt();
                Graph graph = new Graph(n * 2, m * 2);
                int[][] ed = new int[n][];
                for (int i = 0; i < n; i++) {
                    int cnt = in.readInt();
                    ed[i] = new int[cnt];
                    for (int j = 0; j < cnt; j++) {
                        ed[i][j] = in.readInt();
                        ed[i][j]--;
                        graph.id0(i, ed[i][j] + n, 1);
                        graph.id0(i + n, ed[i][j], 1);
                    }
                }

                int s = in.readInt();
                s--;

                long[] distance = ShortestDistance.id14(graph, s).first;

                for (int i = 0; i < n; i++) {

                    if (distance[i + n] != Long.MAX_VALUE && graph.firstOutbound(i + n) == -1) {
                        out.printLine("Win");
                        IntList path = ShortestDistance.id14(graph, s, i + n).second;
                        int[] answer = new int[path.size() + 1];
                        for (int j = 0; j < path.size(); j++) {
                            answer[j] = graph.source(path.get(j)) % n + 1;
                        }
                        answer[path.size()] = i + 1;
                        out.printLine(answer);
                        return;

                    }
                }

                graph = new Graph(n, m);
                for (int i = 0; i < n; i++) for (int j = 0; j < ed[i].length; j++) graph.id9(i, ed[i][j]);
                int[] color = id7.tarjan(graph);
                int[] count = new int[n];
                for (int i = 0; i < n; i++) {
                    count[color[i]]++;
                }

                distance = ShortestDistance.id14(graph, s).first;

                for (int i = 0; i < n; i++) {
                    if (distance[i] != Long.MAX_VALUE && count[color[i]] > 1) {
                        out.print("Draw");
                        return;
                    }
                }


                out.print("Lose");

            }

        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class Heap implements IntQueue {
        private IntComparator comparator;
        private int size = 0;
        private int[] elements;
        private int[] at;

        public Heap(int maxElement) {
            this(10, maxElement);
        }

        public Heap(IntComparator comparator, int maxElement) {
            this(10, comparator, maxElement);
        }

        public Heap(int capacity, int maxElement) {
            this(capacity, IntComparator.DEFAULT, maxElement);
        }

        public Heap(int capacity, IntComparator comparator, int maxElement) {
            this.comparator = comparator;
            elements = new int[capacity];
            at = new int[maxElement];
            Arrays.fill(at, -1);
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void add(int element) {
            ensureCapacity(size + 1);
            elements[size] = element;
            at[element] = size;
            shiftUp(size++);
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
            if (index < 0 || index >= size) {
                throw new IllegalArgumentException();
            }
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
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
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


        public IntIterator intIterator() {
            return new IntIterator() {
                private int at;


                public int value() throws NoSuchElementException {
                    return elements[at];
                }


                public boolean advance() throws NoSuchElementException {
                    return ++at < size;
                }


                public boolean isValid() {
                    return at < size;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

    }

    static interface IntList extends id11 {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }


        default public void add(int value) {
            addAt(size(), value);
        }

        default public void id3() {
            for (int i = 0, j = size() - 1; i < j; i++, j--) {
                swap(i, j);
            }
        }

    }

    static interface id11 extends IntCollection {
    }

    static abstract class id1 implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static interface Edge {
    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static class Graph {
        public static final int id15 = 0;
        protected int vertexCount;
        protected int edgeCount;
        private int[] firstOutbound;
        private int[] firstInbound;
        private Edge[] edges;
        private int[] nextInbound;
        private int[] nextOutbound;
        private int[] from;
        private int[] to;
        private long[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public Graph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            id10(edgeCount + 1);
            if (firstOutbound[fromID] != -1) {
                nextOutbound[edgeCount] = firstOutbound[fromID];
            } else {
                nextOutbound[edgeCount] = -1;
            }
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1) {
                    nextInbound[edgeCount] = firstInbound[toID];
                } else {
                    nextInbound[edgeCount] = -1;
                }
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null) {
                    this.capacity = new long[from.length];
                }
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null) {
                    this.weight = new long[from.length];
                }
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null) {
                edges[edgeCount] = createEdge(edgeCount);
            }
            return edgeCount++;
        }

        protected final GraphEdge createEdge(int id) {
            return new GraphEdge(id);
        }

        public final int id5(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id6 = edgeCount;
                addEdge(to, from, -weight, 0, id6 + id8());
                return addEdge(from, to, weight, capacity, id6);
            }
        }

        protected int id8() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id5(from, to, weight, 0);
        }

        public final int id9(int from, int to) {
            return id0(from, to, 0);
        }

        public final int vertexCount() {
            return vertexCount;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int source(int id) {
            return from[id];
        }

        public final int destination(int id) {
            return to[id];
        }

        public final long weight(int id) {
            if (weight == null) {
                return 0;
            }
            return weight[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id15);
        }

        protected void id10(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null) {
                    edges = resize(edges, newSize);
                }
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null) {
                    nextInbound = resize(nextInbound, newSize);
                }
                if (weight != null) {
                    weight = resize(weight, newSize);
                }
                if (capacity != null) {
                    capacity = resize(capacity, newSize);
                }
                if (reverseEdge != null) {
                    reverseEdge = resize(reverseEdge, newSize);
                }
                flags = resize(flags, newSize);
            }
        }

        protected final int[] resize(int[] array, int size) {
            int[] newArray = new int[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private long[] resize(long[] array, int size) {
            long[] newArray = new long[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private Edge[] resize(Edge[] array, int size) {
            Edge[] newArray = new Edge[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        public final boolean isSparse() {
            return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface IntQueue extends IntCollection {
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id13 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return res * sgn;
        }

        public boolean id2(int c) {
            if (filter != null) {
                return filter.id2(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id13 {
            public boolean id2(int ch);

        }

    }

    static interface IntComparator {
        public static final IntComparator DEFAULT = (first, second) -> {
            if (first < second) {
                return -1;
            }
            if (first > second) {
                return 1;
            }
            return 0;
        };

        public int compare(int first, int second);

    }

    static class IntegerUtils {
        public static int longCompare(long a, long b) {
            if (a < b) {
                return -1;
            }
            if (a > b) {
                return 1;
            }
            return 0;
        }

    }

    static class id12 extends id1 implements IntList {
        private int size;
        private int[] data;

        public id12() {
            this(3);
        }

        public id12(int capacity) {
            data = new int[capacity];
        }

        public id12(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id12(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id12(id12 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id12(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
        }

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                    !(second != null ? !second.equals(pair.second) : pair.second != null);
        }


        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }

    }

    static class id7 {
        private final Graph graph;
        private int[] order;
        private int[] lowlink;
        private int[] stack;
        private int stack_pos;
        private int color;
        private boolean[] visited;
        private int index = 0;
        private int vertexCount;
        private int[] condensed;

        private id7(Graph graph) {
            this.graph = graph;
            vertexCount = graph.vertexCount();
            order = new int[vertexCount];
            visited = new boolean[vertexCount];
            condensed = new int[vertexCount];
        }

        public static int[] tarjan(Graph graph) {
            return new id7(graph).tarjan();
        }

        private int[] tarjan() {
            lowlink = new int[vertexCount];
            stack = new int[vertexCount];
            index = 1;
            for (int i = 0; i < vertexCount; i++) {
                if (order[i] == 0) {
                    id4(i);
                }
            }
            return condensed;
        }

        private void id4(int node) {
            visited[node] = true;
            stack[stack_pos++] = node;
            lowlink[node] = index;
            order[node] = index;
            index++;
            int edge = graph.firstOutbound(node);
            while (edge != -1) {
                int next = graph.destination(edge);
                if (visited[next]) {
                    lowlink[node] = Math.min(lowlink[node], order[next]);
                } else if (order[next] == 0) {
                    id4(next);
                    lowlink[node] = Math.min(lowlink[node], lowlink[next]);
                }
                edge = graph.nextOutbound(edge);
            }
            if (lowlink[node] == order[node]) {
                int current;
                do {
                    current = stack[stack_pos - 1];
                    stack_pos--;
                    condensed[current] = color;
                    visited[current] = false;
                } while (current != node);
                color++;
            }
        }

    }

    static class ShortestDistance {
        public static Pair<long[], int[]> id14(Graph graph, int source) {
            int vertexCount = graph.vertexCount();
            final long[] distance = new long[vertexCount];
            int[] last = new int[vertexCount];
            Arrays.fill(distance, Long.MAX_VALUE);
            Arrays.fill(last, -1);
            distance[source] = 0;
            if (graph.isSparse()) {
                Heap heap = new Heap(vertexCount, new IntComparator() {
                    public int compare(int first, int second) {
                        return IntegerUtils.longCompare(distance[first], distance[second]);
                    }
                }, vertexCount);
                heap.add(source);
                while (!heap.isEmpty()) {
                    int current = heap.poll();
                    int id = graph.firstOutbound(current);
                    while (id != -1) {
                        int next = graph.destination(id);
                        long total = graph.weight(id) + distance[current];
                        if (distance[next] > total) {
                            distance[next] = total;
                            if (heap.getIndex(next) == -1) {
                                heap.add(next);
                            } else {
                                heap.shiftUp(heap.getIndex(next));
                            }
                            last[next] = id;
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            } else {
                boolean[] visited = new boolean[vertexCount];
                for (int i = 0; i < vertexCount; i++) {
                    int index = -1;
                    long length = Long.MAX_VALUE;
                    for (int j = 0; j < vertexCount; j++) {
                        if (!visited[j] && distance[j] < length) {
                            length = distance[j];
                            index = j;
                        }
                    }
                    if (index == -1) {
                        break;
                    }
                    visited[index] = true;
                    int id = graph.firstOutbound(index);
                    while (id != -1) {
                        int next = graph.destination(id);
                        if (!visited[next]) {
                            long total = graph.weight(id) + length;
                            if (distance[next] > total) {
                                distance[next] = total;
                                last[next] = id;
                            }
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            }
            return Pair.makePair(distance, last);
        }

        public static Pair<Long, IntList> id14(Graph graph, int source, int destination) {
            if (source == destination) {
                return Pair.makePair(0L, new id12());
            }
            Pair<long[], int[]> result = id14(graph, source);
            if (result.second[destination] == -1) {
                return null;
            }
            IntList path = new id12();
            int id = destination;
            while (id != source) {
                path.add(result.second[id]);
                id = graph.source(result.second[id]);
            }
            path.id3();
            return Pair.makePair(result.first[destination], path);
        }

    }
}

