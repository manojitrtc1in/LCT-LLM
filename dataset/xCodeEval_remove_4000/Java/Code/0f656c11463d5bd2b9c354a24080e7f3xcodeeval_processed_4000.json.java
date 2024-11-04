import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {

    int[] belongs, id, to, from, parent;
    Graph graph;
    Indexer indexer;
    boolean[] vis;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt(), m=in.readInt();
        int[] arr= IOUtils.id1(in, n);
        from=new int[n-1];
        to=new int[n-1];
        IOUtils.id8(in, from, to);
        MiscUtils.id5(from, to);
        graph=id4.createGraph(n, from, to);
        id=new int[n];
        to=new int[n];
        vis=new boolean[n];
        belongs=new int[n];
        parent=new int[n];
        indexer=new Indexer();
        parent=new int[n];
        parent[0]=-1;
        dfs(0, 0, out);
        id14[] tree=new id14[2];
        for (int i=0; i<2; i++) tree[i]=new id14(n);
        while (m-->0) {
            int t = in.readInt(), u = in.readInt() - 1;
            if (t == 1) {
                int val = in.readInt();
                tree[belongs[u]].add(id[u], val);
                tree[belongs[u]].add(to[u] + 1, -val);
                tree[1 - belongs[u]].add(id[u], -val);
                tree[1 - belongs[u]].add(to[u] + 1, val);

            } else out.printLine(arr[u] + tree[belongs[u]].get(0, id[u]));
        }
    }

    void dfs(int u, int t, OutputWriter out) {
        belongs[u]=t;
        id[u]=indexer.get(u);
        vis[u]=true;
        for (int i=graph.firstOutbound(u); i!=-1; i=graph.nextOutbound(i)) {
            int v=graph.destination(i);
            if (!vis[v]) {
                parent[v]=u;
                dfs(v, 1-t, out);
            }
        }
        to[u]=indexer.size()-1;
    }
}

class Graph {
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

    public final int id6(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id9 = edgeCount;
            addEdge(to, from, -weight, 0, id9 + id11());
            return addEdge(from, to, weight, capacity, id9);
        }
    }

    protected int id11() {
        return 1;
    }

    public final int id0(int from, int to, long weight) {
        return id6(from, to, weight, 0);
    }

    public final int id12(int from, int to) {
        return id0(from, to, 0);
    }

    protected final int edgeCapacity() {
        return from.length;
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
        return flag(id, id15);
    }

    protected void id10(int size) {
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

class Indexer<K> extends id7<K, Integer> {
    private int index = 0;

    public Integer get(Object key) {
        if (!containsKey(key))
            put((K) key, index++);
        return super.get(key);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id13 filter;

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
        while (id3(c))
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
        } while (!id3(c));
        return res * sgn;
    }

    public boolean id3(int c) {
        if (filter != null)
            return filter.id3(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id13 {
        public boolean id3(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(long i) {
        writer.println(i);
    }

}

class IOUtils {

    public static int[] id1(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static void id8(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

}

class MiscUtils {

    public static void id5(int[]...arrays) {
        for (int[] array : arrays) {
            for (int i = 0; i < array.length; i++)
                array[i]--;
        }
    }

}

class id4 extends Graph {
    public int[] id2;

    public id4(int vertexCount, int edgeCapacity) {
        super(vertexCount, 2 * edgeCapacity);
        id2 = new int[2 * edgeCapacity];
    }

    public static id4 createGraph(int vertexCount, int[] from, int[] to) {
        id4 graph = new id4(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id12(from[i], to[i]);
        return graph;
    }

    public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        int id9 = edgeCount;
        super.addEdge(fromID, toID, weight, capacity, reverseEdge);
        super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
        this.id2[id9] = id9 + 1;
        this.id2[id9 + 1] = id9;
        return id9;
    }

    protected int id11() {
        return 2;
    }

    protected void id10(int size) {
        if (size > edgeCapacity()) {
            super.id10(size);
            id2 = resize(id2, edgeCapacity());
        }
    }
}

class id14 {
    private final long[] value;

    public id14(int size) {
        value = new long[size];
    }

    public long get(int from, int to) {
        return get(to) - get(from - 1);
    }

    private long get(int to) {
        to = Math.min(to, value.length - 1);
        long result = 0;
        while (to >= 0) {
            result += value[to];
            to = (to & (to + 1)) - 1;
        }
        return result;
    }

    public void add(int at, long value) {
        while (at < this.value.length) {
            this.value[at] += value;
            at = at | (at + 1);
        }
    }
}

class id7<E, V> extends AbstractMap<E, V> {
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

    public id7() {
        this(4);
    }

    private void setCapacity(int size) {
        capacity = Integer.highestOneBit(4 * size);
        

        data = new HashEntry[capacity];
    }

    public id7(int maxSize) {
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
