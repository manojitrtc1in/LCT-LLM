import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.Queue;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
import java.util.Collection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.AbstractSet;
import java.util.Set;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    private List<Pair<Integer, Integer>> answer = new ArrayList<Pair<Integer, Integer>>();
    private Counter<Pair<Integer, Integer>> canGo = new Counter<Pair<Integer, Integer>>();

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int vertexCount = in.readInt();
        int edgeCount = in.readInt();
        Graph graph = new Graph(vertexCount);
        int[] deg = new int[vertexCount];
        for (int i = 0; i < edgeCount; i++) {
            int from = in.readInt() - 1;
            int to = in.readInt() - 1;
            graph.id7(from, to);
            graph.id7(to, from);
            canGo.add(new Pair<Integer, Integer>(from, to));
            canGo.add(new Pair<Integer, Integer>(to, from));
            deg[from]++;
            deg[to]++;
        }

        Queue<Integer> queue = new ArrayDeque<Integer>();
        for (int i = 0; i < vertexCount; i++) {
            if (deg[i] % 2 == 1) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int from = queue.poll();
            int to = queue.poll();
            graph.id7(from, to);
            graph.id7(to, from);
            canGo.add(new Pair<Integer, Integer>(from, to));
            canGo.add(new Pair<Integer, Integer>(to, from));
            deg[from]++;
            deg[to]++;
        }

        int[] begin = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            begin[i] = graph.firstOutbound(i);
        }

        boolean[] visited = new boolean[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i]) {
                dfs(i, begin, graph, visited);
            }
        }

        int[] inDeg = new int[vertexCount];
        int[] outDeg = new int[vertexCount];

        boolean needReverse = false;
        for (Pair<Integer, Integer> x : answer) {
            if (!needReverse) {
                outDeg[x.first]++;
                inDeg[x.second]++;
            } else {
                outDeg[x.second]++;
                inDeg[x.first]++;
            }
            needReverse = !needReverse;
        }

        for (int i = 0; i < vertexCount; i++) {
            if (inDeg[i] % 2 != 0) {
                answer.add(new Pair<Integer, Integer>(i, i));
            }
        }

        needReverse = false;
        out.printLine(answer.size());
        for (Pair<Integer, Integer> x : answer) {
            if (!needReverse) {
                out.printLine(x.first + 1, x.second + 1);
            } else {
                out.printLine(x.second + 1, x.first + 1);
            }
            needReverse = !needReverse;
        }
    }

    private void dfs(int cur, int[] begin, Graph graph, boolean[] visited) {
        visited[cur] = true;
        for (; begin[cur] != -1;) {
            int next = graph.destination(begin[cur]);
            begin[cur] = graph.nextOutbound(begin[cur]);
            if (canGo.get(new Pair<Integer, Integer>(cur, next)) <= 0) {
                continue;
            }
            canGo.add(new Pair<Integer, Integer>(cur, next), -1);
            canGo.add(new Pair<Integer, Integer>(next, cur), -1);
            dfs(next, begin, graph, visited);
            answer.add(new Pair<Integer, Integer>(cur, next));
        }
    }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

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

class Counter<K> extends id3<K, Long> {
    public Counter() {
        super();
    }

    public long add(K key) {
        long result = get(key);
        put(key, result + 1);
        return result + 1;
    }

    public void add(K key, long delta) {
        put(key, get(key) + delta);
    }

    public Long get(Object key) {
        if (containsKey(key))
            return super.get(key);
        return 0L;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id8 filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (id1(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id1(c));
        return res * sgn;
    }

    public boolean id1(int c) {
        if (filter != null)
            return filter.id1(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id8 {
        public boolean id1(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    public void printLine(int i) {
        writer.println(i);
    }
}

class Graph {
    public static final int id9 = 0;

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
        id5(edgeCount + 1);
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        if (firstInbound != null) {
            if (firstInbound[toID] != -1)
                nextInbound[edgeCount] = firstInbound[toID];
            else
                nextInbound[edgeCount] = -1;
            firstInbound[toID] = edgeCount;
        }
        this.from[edgeCount] = fromID;
        this.to[edgeCount] = toID;
        if (capacity != 0) {
            if (this.capacity == null)
                this.capacity = new long[from.length];
            this.capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this.weight == null)
                this.weight = new long[from.length];
            this.weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this.reverseEdge == null) {
                this.reverseEdge = new int[from.length];
                Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
            }
            this.reverseEdge[edgeCount] = reverseEdge;
        }
        if (edges != null)
            edges[edgeCount] = createEdge(edgeCount);
        return edgeCount++;
    }

    protected final GraphEdge createEdge(int id) {
        return new GraphEdge(id);
    }

    public final int id2(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id4 = edgeCount;
            addEdge(to, from, -weight, 0, id4 + id6());
            return addEdge(from, to, weight, capacity, id4);
        }
    }

    protected int id6() {
        return 1;
    }

    public final int id0(int from, int to, long weight) {
        return id2(from, to, weight, 0);
    }

    public final int id7(int from, int to) {
        return id0(from, to, 0);
    }

    public final int firstOutbound(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    public final int nextOutbound(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    public final int destination(int id) {
        return to[id];
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final boolean isRemoved(int id) {
        return flag(id, id9);
    }

    protected void id5(int size) {
        if (from.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            if (edges != null)
                edges = resize(edges, newSize);
            from = resize(from, newSize);
            to = resize(to, newSize);
            nextOutbound = resize(nextOutbound, newSize);
            if (nextInbound != null)
                nextInbound = resize(nextInbound, newSize);
            if (weight != null)
                weight = resize(weight, newSize);
            if (capacity != null)
                capacity = resize(capacity, newSize);
            if (reverseEdge != null)
                reverseEdge = resize(reverseEdge, newSize);
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

    protected class GraphEdge implements Edge {
        protected int id;

        protected GraphEdge(int id) {
            this.id = id;
        }

    }

}

class id3<E, V> extends AbstractMap<E, V> {
    private static final int[] shifts = new int[10];

    private int size;
    private HashEntry<E, V>[] data;
    private int capacity;
    private Set<Entry<E, V>> entrySet;

    static {
        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < 10; i++)
            shifts[i] = 1 + 3 * i + random.nextInt(3);
    }

    public id3() {
        this(4);
    }

    private void setCapacity(int size) {
        capacity = Integer.highestOneBit(4 * size);
        

        data = new HashEntry[capacity];
    }

    public id3(int maxSize) {
        setCapacity(maxSize);
        entrySet = new AbstractSet<Entry<E, V>>() {
            public Iterator<Entry<E, V>> iterator() {
                return new Iterator<Entry<E, V>>() {
                    private HashEntry<E, V> last = null;
                    private HashEntry<E, V> current = null;
                    private HashEntry<E, V> base = null;
                    private int lastIndex = -1;
                    private int index = -1;

                    public boolean hasNext() {
                        if (current == null) {
                            for (index++; index < capacity; index++) {
                                if (data[index] != null) {
                                    base = current = data[index];
                                    break;
                                }
                            }
                        }
                        return current != null;
                    }

                    public Entry<E, V> next() {
                        if (!hasNext())
                            throw new NoSuchElementException();
                        last = current;
                        lastIndex = index;
                        current = current.next;
                        if (base.next != last)
                            base = base.next;
                        return last;
                    }

                    public void remove() {
                        if (last == null)
                            throw new IllegalStateException();
                        size--;
                        if (base == last)
                            data[lastIndex] = last.next;
                        else
                            base.next = last.next;
                    }
                };
            }

            public int size() {
                return size;
            }
        };
    }

    public Set<Entry<E, V>> entrySet() {
        return entrySet;
    }

    public void clear() {
        Arrays.fill(data, null);
        size = 0;
    }

    private int index(Object o) {
        return getHash(o.hashCode()) & (capacity - 1);
    }

    private int getHash(int h) {
        int result = h;
        for (int i : shifts)
            result ^= h >>> i;
        return result;
    }

    public V remove(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        HashEntry<E, V> last = null;
        while (current != null) {
            if (current.key.equals(o)) {
                if (last == null)
                    data[index] = current.next;
                else
                    last.next = current.next;
                size--;
                return current.value;
            }
            last = current;
            current = current.next;
        }
        return null;
    }

    public V put(E e, V value) {
        if (e == null)
            return null;
        int index = index(e);
        HashEntry<E, V> current = data[index];
        if (current != null) {
            while (true) {
                if (current.key.equals(e)) {
                    V oldValue = current.value;
                    current.value = value;
                    return oldValue;
                }
                if (current.next == null)
                    break;
                current = current.next;
            }
        }
        if (current == null)
            data[index] = new HashEntry<E, V>(e, value);
        else
            current.next = new HashEntry<E, V>(e, value);
        size++;
        if (2 * size > capacity) {
            HashEntry<E, V>[] oldData = data;
            setCapacity(size);
            for (HashEntry<E, V> entry : oldData) {
                while (entry != null) {
                    HashEntry<E, V> next = entry.next;
                    index = index(entry.key);
                    entry.next = data[index];
                    data[index] = entry;
                    entry = next;
                }
            }
        }
        return null;
    }

    public V get(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return current.value;
            current = current.next;
        }
        return null;
    }

    public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return true;
            current = current.next;
        }
        return false;
    }

    public int size() {
        return size;
    }

    private static class HashEntry<E, V> implements Entry<E, V> {
        private final E key;
        private V value;
        private HashEntry<E, V> next;

        private HashEntry(E key, V value) {
            this.key = key;
            this.value = value;
        }


        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }
    }
}

interface Edge {
}

