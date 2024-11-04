import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.IOException;
import java.util.Map;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id6 solver = new id6();
        solver.solve(1, in, out);
        out.close();
    }

    static class id6 {
        final int MOD = MiscUtils.MOD7;
        long[] X;
        Graph graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            X = in.id8(n);
            int[] A = new int[n - 1], B = new int[n - 1];
            in.id12(A, B);
            MiscUtils.id7(A, B);
            graph = id5.createGraph(n, A, B);
            long res = dfs(0, new id21());
            out.printLine(res);
        }

        long dfs(int u, id22 par) {
            id22 counter = new id21();
            long res = 0;
            for (long key : par.keys()) {
                int c = par.get(key);
                long nkey = IntegerUtils.gcd(key, X[u]);
                if (!counter.containsKey(nkey)) {
                    counter.put(nkey, 0);
                }
                counter.put(nkey, counter.get(nkey) + c);
                res += nkey % MOD * c % MOD;
            }
            if (!counter.containsKey(X[u])) {
                counter.put(X[u], 0);
            }
            counter.put(X[u], counter.get(X[u]) + 1);
            res += X[u] % MOD;
            for (int ed = graph.firstOutbound(u); ed != -1; ed = graph.nextOutbound(ed)) {
                graph.removeEdge(graph.transposed(ed));
                int v = graph.destination(ed);
                res += dfs(v, counter);
            }
            res %= MOD;
            return res;
        }

    }

    static interface Edge {
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id26 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id12(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public long[] id8(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
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
            while (id4(c)) {
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
            } while (!id4(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id4(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id4(c));
            return res * sgn;
        }

        public boolean id4(int c) {
            if (filter != null) {
                return filter.id4(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id26 {
            boolean id4(int ch);

        }

    }

    static class id21 implements id22 {
        private static final int id24 = 8;
        private static final int id18 = 0x811c9dc5;
        private static final int id25 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final int id15 = (new int[1])[0];
        private static final Random rnd = new Random();
        private static final int id23;
        private static final int id28;
        private static final int id11;
        private static final int id10;
        private long[] keys;
        private int[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            id23 = rnd.nextInt(10) + 11;
            id28 = rnd.nextInt(10) + 21;
            id11 = rnd.nextInt(10) + 11;
            id10 = rnd.nextInt(10) + 21;
        }

        public id21() {
            this(id24);
        }

        public id21(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id27(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public id21(id22 map) {
            this(map.size());
            for (id16 it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public id21(Map<Long, Integer> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Long, Integer> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
            }
        }

        private int id3(int h) {
            h ^= hashSeed;
            h ^= (h >>> id23) ^ (h >>> id28);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id11) ^ (h >>> id10);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean containsKey(long key) {
            final int keyHash = id13.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    return true;
                }
            }
            return false;
        }

        public int get(long key) {
            final int keyHash = id13.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    returnedNull = false;
                    return values[pos];
                }
            }
            returnedNull = true;
            return id15;
        }

        public int put(long key, int value) {
            final int keyHash = id13.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] == FILLED; pos = (pos + step) & mask) {
                if (keys[pos] == key) {
                    final int oldValue = values[pos];
                    values[pos] = value;
                    returnedNull = false;
                    return oldValue;
                }
            }
            if (status[pos] == FREE) {
                status[pos] = FILLED;
                keys[pos] = key;
                values[pos] = value;
                size++;
                if ((size + removedCount) * 2 > keys.length) {
                    rebuild(keys.length * 2); 

                }
                returnedNull = true;
                return id15;
            }
            final int removedPos = pos;
            for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    final int oldValue = values[pos];
                    values[pos] = value;
                    returnedNull = false;
                    return oldValue;
                }
            }
            status[removedPos] = FILLED;
            keys[removedPos] = key;
            values[removedPos] = value;
            size++;
            removedCount--;
            returnedNull = true;
            return id15;
        }

        public long[] keys() {
            long[] result = new long[size];
            for (int i = 0, j = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    result[j++] = keys[i];
                }
            }
            return result;
        }

        public id16 iterator() {
            return new id2();
        }

        private void rebuild(int newLength) {
            long[] oldKeys = keys;
            int[] oldValues = values;
            byte[] oldStatus = status;
            id27(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void id27(int length) {
            keys = new long[length];
            values = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id21 that = (id21) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    int thatValue = that.get(keys[i]);
                    if (that.returnedNull || thatValue != values[i]) {
                        return false;
                    }
                }
            }
            return true;
        }

        private void randomShuffle(int[] array) {
            int n = array.length;
            for (int i = 0; i < n; i++) {
                int j = i + rnd.nextInt(n - i);
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

        public int hashCode() {
            int[] entryHashes = new int[size];
            for (int i = 0, j = 0; i < status.length; i++) {
                if (status[i] == FILLED) {
                    int hash = id18;
                    hash = (hash ^ id13.getHash(keys[i])) * id25;
                    hash = (hash ^ id13.getHash(values[i])) * id25;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = id18;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * id25;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('{');
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    if (sb.length() > 1) {
                        sb.append(", ");
                    }
                    sb.append(keys[i]);
                    sb.append('=');
                    sb.append(values[i]);
                }
            }
            sb.append('}');
            return sb.toString();
        }

        private class id2 implements id16 {
            private int curIndex;

            private id2() {
                curIndex = 0;
                while (curIndex < status.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
            }

            public boolean hasNext() {
                return curIndex < status.length;
            }

            public long getKey() {
                if (curIndex == keys.length) {
                    throw new NoSuchElementException("Iterator doesn't have more entries");
                }
                return keys[curIndex];
            }

            public int getValue() {
                if (curIndex == values.length) {
                    throw new NoSuchElementException("Iterator doesn't have more entries");
                }
                return values[curIndex];
            }

            public void next() {
                if (curIndex == status.length) {
                    return;
                }
                curIndex++;
                while (curIndex < status.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
            }

        }

    }

    static interface id16 {
        boolean hasNext();

        long getKey();

        int getValue();

        void next();

    }

    static interface id22 {
        int size();

        boolean containsKey(long key);

        int get(long key);

        int put(long key, int value);

        long[] keys();

        id16 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id5 extends Graph {
        public int[] id1;

        public id5(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id5(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id1 = new int[2 * edgeCapacity];
        }

        public static id5 createGraph(int vertexCount, int[] from, int[] to) {
            id5 graph = new id5(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.id20(from[i], to[i]);
            }
            return graph;
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id14 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.id1[id14] = id14 + 1;
            this.id1[id14 + 1] = id14;
            return id14;
        }

        protected int id19() {
            return 2;
        }

        public final int transposed(int id) {
            return id1[id];
        }

        protected void id17(int size) {
            if (size > edgeCapacity()) {
                super.id17(size);
                id1 = resize(id1, edgeCapacity());
            }
        }

    }

    static final class id13 {
        private id13() {
        }

        public static int getHash(int x) {
            return x;
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

        public static void id7(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }

    static class IntegerUtils {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
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

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class Graph {
        public static final int id29 = 0;
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
            id17(edgeCount + 1);
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

        public final int id9(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id14 = edgeCount;
                addEdge(to, from, -weight, 0, id14 + id19());
                return addEdge(from, to, weight, capacity, id14);
            }
        }

        protected int id19() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id9(from, to, weight, 0);
        }

        public final int id20(int from, int to) {
            return id0(from, to, 0);
        }

        protected final int edgeCapacity() {
            return from.length;
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

        public final int destination(int id) {
            return to[id];
        }

        public int transposed(int id) {
            return -1;
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final void setFlag(int id, int bit) {
            flags[id] |= 1 << bit;
        }

        public final void removeEdge(int id) {
            setFlag(id, id29);
        }

        public final boolean isRemoved(int id) {
            return flag(id, id29);
        }

        protected void id17(int size) {
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

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }
}

