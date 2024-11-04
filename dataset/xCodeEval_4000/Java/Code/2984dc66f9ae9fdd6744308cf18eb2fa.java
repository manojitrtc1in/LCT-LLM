import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;


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

    static class TaskE {
        final static long inf = (long) 1e16;
        int n;
        int cntG;
        int q;
        Graph gr;
        IntArrayList[] idsGirls;
        int[] vertexCount;
        int[] parent;
        int[] depth;
        int[] leader;
        int[] posLSub;
        int[] posRSub;
        int[] posRVertex;
        int[] posGirl;
        int szOrder;
        int[] orderIdGirl;
        long[] treeDelta;
        long[] treeWeight;
        int[] treeIdGirl;
        long[] ansWeight;
        int[] ansIdGirl;
        OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.out = out;
            n = in.readInt();
            cntG = in.readInt();
            q = in.readInt();

            gr = new BidirectionalGraph(n, n - 1);
            for (int iter = 0; iter < n - 1; iter++) {
                gr.addSimpleEdge(in.readInt() - 1, in.readInt() - 1);
            }

            idsGirls = new IntArrayList[n];
            for (int i = 0; i < n; i++) {
                idsGirls[i] = new IntArrayList();
            }
            for (int i = 0; i < cntG; i++) {
                idsGirls[in.readInt() - 1].add(i);
            }


            vertexCount = new int[n];
            parent = new int[n];
            depth = new int[n];
            initSzAndParentAndDepth(0, -1);

            leader = new int[n];
            posLSub = new int[n];
            posRSub = new int[n];
            posRVertex = new int[n];
            posGirl = new int[cntG];
            orderIdGirl = new int[n + cntG];



            heavyLightDecomp(0, -1, 0);
            {
                int sz = Integer.highestOneBit(szOrder) << 2;
                treeDelta = new long[sz];
                treeIdGirl = new int[sz];
                treeWeight = new long[sz];
                ansIdGirl = new int[sz];
                ansWeight = new long[sz];
            }
            build(0, 0, szOrder - 1);

        


            

            for (int iter = 0; iter < q; iter++) {
                int op = in.readInt();
                if (op == 1) {
                    int a = in.readInt() - 1;
                    int b = in.readInt() - 1;
                    int k = in.readInt();

                    IntArrayList answer = new IntArrayList();
                    for (int iteration = 0; iteration < k; iteration++) {
                        int girl = getGirl(a, b);
                        if (girl == -1) {
                            break;
                        }
                        answer.add(girl);
                    }

                    out.print(answer.size());
                    for (int idG : answer) {
                        out.print(" ");
                        out.print(idG + 1);
                    }
                    out.printLine();
                } else if (op == 2) {
                    int v = in.readInt() - 1;
                    int delta = in.readInt();
                    addDelta(0, 0, szOrder - 1, posLSub[v], posRSub[v], delta);
                }
            }
        
        }

        private int getGirl(int d, int u) {
            long w = inf;
            int id = -1;
            for (; ; ) {
                if (leader[d] == leader[u]) {
                    if (depth[d] < depth[u]) {
                        int t = d;
                        d = u;
                        u = t;
                    }
                    query(0, 0, szOrder - 1, posLSub[u], posRVertex[d]);
                    if (w > ansWeight[0] || w == ansWeight[0] && id > ansIdGirl[0]) {
                        w = ansWeight[0];
                        id = ansIdGirl[0];
                    }
                    break;
                } else {
                    if (depth[leader[d]] < depth[leader[u]]) {
                        int t = d;
                        d = u;
                        u = t;
                    }
                    query(0, 0, szOrder - 1, posLSub[leader[d]], posRVertex[d]);
                    d = parent[leader[d]];

                    if (w > ansWeight[0] || w == ansWeight[0] && id > ansIdGirl[0]) {
                        w = ansWeight[0];
                        id = ansIdGirl[0];
                    }
                }
            }
            if (id != -1) {
                addDelta(0, 0, szOrder - 1, posGirl[id], posGirl[id], inf - w);
            }
            return id;
        }

        private void query(int v, int tl, int tr, int l, int r) {
            if (l > r) {
                ansWeight[v] = inf;
                ansIdGirl[v] = -1;
                return;
            }

            if (tl == l && tr == r) {
                ansWeight[v] = treeWeight[v];
                ansIdGirl[v] = treeIdGirl[v];
            } else {
                push(v);
                int tm = (tl + tr) >> 1;
                query(v + v + 1, tl, tm, l, Math.min(r, tm));
                query(v + v + 2, tm + 1, tr, Math.max(l, tm + 1), r);
                upd(v, ansWeight, ansIdGirl);
            }
        }

        private void addDelta(int v, int tl, int tr, int l, int r, long delta) {
            if (l > r) {
                return;
            }

            if (tl == l && tr == r) {
                treeWeight[v] += delta;
                treeDelta[v] += delta;
            } else {
                push(v);
                int tm = (tl + tr) >> 1;
                addDelta(v + v + 1, tl, tm, l, Math.min(r, tm), delta);
                addDelta(v + v + 2, tm + 1, tr, Math.max(l, tm + 1), r, delta);
                upd(v, treeWeight, treeIdGirl);
            }
        }

        private void build(int v, int tl, int tr) {
            if (tl == tr) {
                treeWeight[v] = orderIdGirl[tl] == -1 ? inf : orderIdGirl[tl] + 1; 

                treeIdGirl[v] = orderIdGirl[tl];
            } else {
                push(v);
                int tm = (tl + tr) >> 1;
                build(v + v + 1, tl, tm);
                build(v + v + 2, tm + 1, tr);
                upd(v, treeWeight, treeIdGirl);
            }
        }

        private void upd(int v, long[] weight, int[] idGirl) {
            int vl = v + v + 1;
            int vr = v + v + 2;
            if (weight[vl] < weight[vr] || weight[vl] == weight[vr] && idGirl[vl] < idGirl[vr]) {
                weight[v] = weight[vl];
                idGirl[v] = idGirl[vl];
            } else {
                weight[v] = weight[vr];
                idGirl[v] = idGirl[vr];
            }
        }

        private void push(int v) {
            add(v + v + 1, treeDelta[v]);
            add(v + v + 2, treeDelta[v]);
            treeDelta[v] = 0;
        }

        private void add(int v, long delta) {
            treeDelta[v] += delta;
            treeWeight[v] += delta;
        }

        private void initSzAndParentAndDepth(int v, int p) {
            vertexCount[v] = 1;
            parent[v] = p;
            if (p != -1) {
                depth[v] = depth[p] + 1;
            }
            for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                int to = gr.destination(id);
                if (to == p) {
                    continue;
                }
                initSzAndParentAndDepth(to, v);
                vertexCount[v] += vertexCount[to];
            }
        }

        void heavyLightDecomp(int v, int parent, int leader) {
            this.leader[v] = leader;

            posLSub[v] = szOrder;

            orderIdGirl[szOrder] = -1;
            

            ++szOrder;

            for (int idG : idsGirls[v]) {
                orderIdGirl[szOrder] = idG;
                

                posGirl[idG] = szOrder;
                ++szOrder;
            }

            posRVertex[v] = szOrder - 1;

            int bestTo = -1;
            for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                int to = gr.destination(id);
                if (to == parent) {
                    continue;
                }
                if (bestTo == -1 || vertexCount[bestTo] < vertexCount[to]) {
                    bestTo = to;
                }
            }

            if (bestTo != -1) {
                heavyLightDecomp(bestTo, v, leader);
                for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                    int to = gr.destination(id);
                    if (to == parent) {
                        continue;

                    }
                    if (bestTo != to) {
                        heavyLightDecomp(to, v, to);
                    }
                }
            }

            posRSub[v] = szOrder - 1;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

        public void printLine() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
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

    }

    static interface Edge {
    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

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

    }

    static abstract class IntAbstractStream implements IntStream {

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

    static class Graph {
        public static final int REMOVED_BIT = 0;
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
            ensureEdgeCapacity(edgeCount + 1);
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

        public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int lastEdgeCount = edgeCount;
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
                return addEdge(from, to, weight, capacity, lastEdgeCount);
            }
        }

        protected int entriesPerEdge() {
            return 1;
        }

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        public final int addSimpleEdge(int from, int to) {
            return addWeightedEdge(from, to, 0);
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

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, REMOVED_BIT);
        }

        protected void ensureEdgeCapacity(int size) {
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

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
            this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
            return lastEdgeCount;
        }


        protected int entriesPerEdge() {
            return 2;
        }


        protected void ensureEdgeCapacity(int size) {
            if (size > edgeCapacity()) {
                super.ensureEdgeCapacity(size);
                transposedEdge = resize(transposedEdge, edgeCapacity());
            }
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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
}

