import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {
    
    final long MOD=(long)(1e9+7);
    long[] P;
    id1 automaton;
    long[][] memo;
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String S=in.readString(), X=in.readString(), Y=in.readString();
        int s=S.length()-X.length()/2+1;
        if (s<=0) {
            out.printLine(0);
            return;
        }
        String[] strings=new String[s];
        for (int i=0; i<s; i++) strings[i]=S.substring(i, i+X.length()/2);
        automaton=new id1(strings, '0', '9');
        long ret=0;
        P=new long[X.length()+1];
        P[0]=1;
        for (int i=1; i<=X.length(); i++) P[i]=P[i-1]*10%MOD;
        boolean separate=false;
        memo=new long[X.length()+1][automaton.ends.length];
        for (long[] arr: memo) Arrays.fill(arr, -1);
        for (int i=0; i<X.length(); i++) {
            if (separate) {
                for (int j=X.charAt(i)-'0'+1; j<10; j++) ret+=solve(X.substring(0, i)+j, X.length()-i-1);
                for (int j=0; j<Y.charAt(i)-'0'; j++) ret+=solve(Y.substring(0, i)+j, X.length()-i-1);
            } else if (X.charAt(i)!=Y.charAt(i)) {
                separate=true;
                for (int j=X.charAt(i)-'0'+1; j<Y.charAt(i)-'0'; j++) ret+=solve(X.substring(0, i)+j, X.length()-i-1);
            }
        }
        ret+=solve(X, 0);
        if (!X.equals(Y)) ret+=solve(Y, 0);
        out.printLine(ret%MOD);
    }
    
    long solve(String str, int r) {
        int node=0;
        for (int i=0; i<str.length(); i++) {
            node=automaton.edges[node][str.charAt(i)-'0'];
            if (automaton.ends[node]>0) return P[r];
        }
        return dp(r, node);
    }
    
    long dp(int r, int u) {
        if (memo[r][u]!=-1) return memo[r][u];
        if (automaton.ends[u]>0) return memo[r][u]=P[r];
        memo[r][u]=0;
        if (r==0) return 0;
        for (int i=0; i<10; i++) memo[r][u]+=dp(r-1, automaton.edges[u][i]);
        return memo[r][u]%=MOD;
    }
}

class InputReader {
    private boolean finished = false;

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id27 filter;

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

    public int peek() {
            if (numChars == -1)
                    return -1;
            if (curChar >= numChars) {
                    curChar = 0;
                    try {
                            numChars = stream.read(buf);
                    } catch (IOException e) {
                            return -1;
                    }
                    if (numChars <= 0)
                            return -1;
            }
            return buf[curChar];
    }

    public int readInt() {
            int c = read();
            while (id7(c))
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
            } while (!id7(c));
            return res * sgn;
    }

    public long readLong() {
            int c = read();
            while (id7(c))
                    c = read();
            int sgn = 1;
            if (c == '-') {
                    sgn = -1;
                    c = read();
            }
            long res = 0;
            do {
                    if (c < '0' || c > '9')
                            throw new InputMismatchException();
                    res *= 10;
                    res += c - '0';
                    c = read();
            } while (!id7(c));
            return res * sgn;
    }

    public String readString() {
            int c = read();
            while (id7(c))
                    c = read();
            StringBuilder res = new StringBuilder();
            do {
                    if (Character.isValidCodePoint(c))
                            res.appendCodePoint(c);
                    c = read();
            } while (!id7(c));
            return res.toString();
    }

    public boolean id7(int c) {
            if (filter != null)
                    return filter.id7(c);
            return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id4() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                    if (c != '\r')
                            buf.appendCodePoint(c);
                    c = read();
            }
            return buf.toString();
    }

    public String readLine() {
            String s = id4();
            while (s.trim().length() == 0)
                    s = id4();
            return s;
    }

    public String readLine(boolean id25) {
            if (id25)
                    return readLine();
            else
                    return id4();
    }

    public BigInteger id19() {
            try {
                    return new BigInteger(readString());
            } catch (NumberFormatException e) {
                    throw new InputMismatchException();
            }
    }

    public char readCharacter() {
            int c = read();
            while (id7(c))
                    c = read();
            return (char) c;
    }

    public double readDouble() {
            int c = read();
            while (id7(c))
                    c = read();
            int sgn = 1;
            if (c == '-') {
                    sgn = -1;
                    c = read();
            }
            double res = 0;
            while (!id7(c) && c != '.') {
                    if (c == 'e' || c == 'E')
                            return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                            throw new InputMismatchException();
                    res *= 10;
                    res += c - '0';
                    c = read();
            }
            if (c == '.') {
                    c = read();
                    double m = 1;
                    while (!id7(c)) {
                            if (c == 'e' || c == 'E')
                                    return res * Math.pow(10, readInt());
                            if (c < '0' || c > '9')
                                    throw new InputMismatchException();
                            m /= 10;
                            res += (c - '0') * m;
                            c = read();
                    }
            }
            return res * sgn;
    }

    public boolean id5() {
            int value;
            while (id7(value = peek()) && value != -1)
                    read();
            return value == -1;
    }

    public String next() {
            return readString();
    }

    public id27 getFilter() {
            return filter;
    }

    public void setFilter(id27 filter) {
            this.filter = filter;
    }

    public interface id27 {
            public boolean id7(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
            writer.print(array);
    }

    public void print(Object...objects) {
            for (int i = 0; i < objects.length; i++) {
                    if (i != 0)
                            writer.print(' ');
                    writer.print(objects[i]);
            }
    }

public void print(int[] array) {
    for (int i = 0; i < array.length; i++) {
        if (i != 0)
            writer.print(' ');
        writer.print(array[i]);
    }
}

public void print(long[] array) {
    for (int i = 0; i < array.length; i++) {
        if (i != 0)
            writer.print(' ');
        writer.print(array[i]);
    }
}

public void print(Collection<Integer> collection) {
            boolean first = true;
            for (Iterator<Integer> iterator = collection.iterator(); iterator.hasNext(); iterator.next()) {
                    if (first)
                            first = false;
                    else
                            writer.print(' ');
                    writer.print(iterator);
            }
    }

    public void printLine(int[] array) {
    print(array);
    writer.println();
}

public void printLine(long[] array) {
    print(array);
    writer.println();
}

public void printLine(Collection<Integer> collection) {
            print(collection);
            writer.println();
    }

    public void printLine() {
            writer.println();
    }

public void printLine(Object...objects) {
            print(objects);
            writer.println();
    }

    public void print(char i) {
            writer.print(i);
    }

    public void printLine(char i) {
            writer.println(i);
    }

    public void printLine(char[] array) {
            writer.println(array);
    }

    public void printFormat(String format, Object...objects) {
            writer.printf(format, objects);
    }

    public void close() {
            writer.close();
    }

    public void flush() {
            writer.flush();
    }

    public void print(long i) {
            writer.print(i);
    }

    public void printLine(long i) {
            writer.println(i);
    }

    public void print(int i) {
            writer.print(i);
    }

    public void printLine(int i) {
            writer.println(i);
    }
}

class id1 {
    public int[][] edges;
    public int[] ends;

    public id1(String[] words) {
        this(words, 'a', 'z');
    }

    public id1(String[] words, char first, char last) {
        Indexer<Long> indexer = new Indexer<>();
        Counter<Long> fullWords = new Counter<>();
        StringHash[] hashes = new StringHash[words.length];
        int totalLength = 0;
        for (int i = 0; i < words.length; i++) {
            String s = words[i];
            hashes[i] = new id8(s);
            for (int j = 0; j <= s.length(); j++)
                indexer.get(hashes[i].hash(0, j));
            fullWords.add(hashes[i].hash(0));
            totalLength += s.length();
        }
        int size = indexer.size();
        edges = new int[size][last - first + 1];
        ends = new int[size];
        int[] link = new int[size];
        Arrays.fill(link, -1);
        int[] start = new int[size];
        Arrays.fill(start, -1);
        int[] next = new int[totalLength];
        int[] to = new int[totalLength];
        int index = 0;
        Graph graph = new Graph(size);
        int[] length = new int[size];
        for (int i = 0; i < words.length; i++) {
            String s = words[i];
            for (int j = 0; j <= s.length(); j++) {
                int at = indexer.get(hashes[i].hash(0, j));
                if (j != s.length()) {
                    to[index] = i;
                    next[index] = start[at];
                    start[at] = index++;
                }
                if (link[at] == -1) {
                    length[at] = j;
                    for (int k = 1; k <= j; k++) {
                        long key = hashes[i].hash(k, j);
                        if (indexer.containsKey(key)) {
                            link[at] = indexer.get(key);
                            graph.id18(link[at], at);
                            break;
                        }
                    }
                    for (int k = 0; k <= j; k++)
                        ends[at] += fullWords.get(hashes[i].hash(k, j));
                }
            }
        }
        int[] queue = new int[size];
        int count = 1;
        for (int i = 0; i < count; i++) {
            int current = queue[i];
            for (int j = start[current]; j != -1; j = next[j]) {
                int at = to[j];
                edges[current][words[at].charAt(length[current]) - first] = indexer
                        .get(hashes[at].hash(0, length[current] + 1));
            }
            for (int j = graph.firstOutbound(current); j != -1; j = graph
                    .nextOutbound(j)) {
                int at = graph.destination(j);
                queue[count++] = at;
                System.arraycopy(edges[current], 0, edges[at], 0, last - first
                        + 1);
            }
        }
    }
}

class Indexer<K> extends HashMap<K, Integer> {
    private int index = 0;

    @Override
    public Integer get(Object key) {
        if (!containsKey(key))
            put((K) key, index++);
        return super.get(key);
    }
}

class Counter<K> extends HashMap<K, Long> {
    public Counter() {
        super();
    }

    public Counter(int capacity) {
        super(capacity);
    }

    public long add(K key) {
        long result = get(key);
        put(key, result + 1);
        return result + 1;
    }

    public void add(K key, long delta) {
        put(key, get(key) + delta);
    }

    @Override
    public Long get(Object key) {
        if (containsKey(key))
            return super.get(key);
        return 0L;
    }
}

interface StringHash {
    long hash(int from, int to);

    long hash(int from);

    int length();
}

class id8 extends id21 {
    private static long[] id12 = new long[0];
    private static long[] id22 = new long[0];

    private final long[] firstHash;
    private final long[] secondHash;

    public id8(CharSequence string) {
        int length = string.length();
        ensureCapacity(length);
        firstHash = new long[length + 1];
        secondHash = new long[length + 1];
        long firstPower = 1;
        long secondPower = 1;
        for (int i = 0; i < length; i++) {
            firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower)
                    % FIRST_MOD;
            secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower)
                    % SECOND_MOD;
            firstPower *= id15;
            firstPower %= FIRST_MOD;
            secondPower *= id15;
            secondPower %= SECOND_MOD;
        }
    }

    private void ensureCapacity(int length) {
        if (id12.length >= length)
            return;
        length = Math.max(length + 1, id12.length << 1);
        long[] oldFirst = id12;
        long[] oldSecond = id22;
        id12 = new long[length];
        id22 = new long[length];
        System.arraycopy(oldFirst, 0, id12, 0, oldFirst.length);
        System.arraycopy(oldSecond, 0, id22, 0, oldSecond.length);
        id12[0] = id22[0] = 1;
        for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
            id12[i] = id12[i - 1]
                    * id28 % FIRST_MOD;
            id22[i] = id22[i - 1]
                    * id26 % SECOND_MOD;
        }
    }

    public long hash(int from, int to) {
        return (((firstHash[to] - firstHash[from] + FIRST_MOD)
                * id12[from] % FIRST_MOD) << 32)
                + ((secondHash[to] - secondHash[from] + SECOND_MOD)
                        * id22[from] % SECOND_MOD);
    }

    public int length() {
        return firstHash.length - 1;
    }
}

abstract class id21 implements StringHash {
    public static final long id15;
    protected static final long id28;
    protected static final long id26;
    public static final long FIRST_MOD;
    public static final long SECOND_MOD;

    static {
        Random random = new Random(System.currentTimeMillis());
        FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random
                .nextInt((int) 1e9)));
        SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random
                .nextInt((int) 1e9)));
        id15 = random.nextInt((int) 1e9 - 257) + 257;
        id28 = IntegerUtils.reverse(id15, FIRST_MOD);
        id26 = IntegerUtils
                .reverse(id15, SECOND_MOD);
    }

    public long hash(int from) {
        return hash(from, length());
    }
}

class Graph {
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

    public static Graph createGraph(int vertexCount, int[] from, int[] to) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id18(from[i], to[i]);
        return graph;
    }

    public static Graph id2(int vertexCount, int[] from,
            int[] to, long[] weight) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id0(from[i], to[i], weight[i]);
        return graph;
    }

    public static Graph id20(int vertexCount, int[] from, int[] to,
            long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id9(from[i], to[i], capacity[i]);
        return graph;
    }

    public static Graph id10(int vertexCount, int[] from,
            int[] to, long[] weight, long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id11(from[i], to[i], weight[i], capacity[i]);
        return graph;
    }

    public static Graph createTree(int[] parent) {
        Graph graph = new Graph(parent.length + 1, parent.length);
        for (int i = 0; i < parent.length; i++)
            graph.id18(parent[i], i + 1);
        return graph;
    }

    public int addEdge(int fromID, int toID, long weight, long capacity,
            int reverseEdge) {
        id17(edgeCount + 1);
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

    public final int id11(int from, int to, long weight,
            long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id14 = edgeCount;
            addEdge(to, from, -weight, 0, id14 + id16());
            return addEdge(from, to, weight, capacity, id14);
        }
    }

    protected int id16() {
        return 1;
    }

    public final int id9(int from, int to, long capacity) {
        return id11(from, to, 0, capacity);
    }

    public final int id0(int from, int to, long weight) {
        return id11(from, to, weight, 0);
    }

    public final int id18(int from, int to) {
        return id0(from, to, 0);
    }

    public final int vertexCount() {
        return vertexCount;
    }

    public final int edgeCount() {
        return edgeCount;
    }

    protected final int edgeCapacity() {
        return from.length;
    }

    public final Edge edge(int id) {
        initEdges();
        return edges[id];
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

    public final int firstInbound(int vertex) {
        initInbound();
        int id = firstInbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int nextInbound(int id) {
        initInbound();
        id = nextInbound[id];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int source(int id) {
        return from[id];
    }

    public final int destination(int id) {
        return to[id];
    }

    public final long weight(int id) {
        if (weight == null)
            return 0;
        return weight[id];
    }

    public final long capacity(int id) {
        if (capacity == null)
            return 0;
        return capacity[id];
    }

    public final long flow(int id) {
        if (reverseEdge == null)
            return 0;
        return capacity[reverseEdge[id]];
    }

    public final void pushFlow(int id, long flow) {
        if (flow == 0)
            return;
        if (flow > 0) {
            if (capacity(id) < flow)
                throw new IllegalArgumentException("Not enough capacity");
        } else {
            if (flow(id) < -flow)
                throw new IllegalArgumentException("Not enough capacity");
        }
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

    public int transposed(int id) {
        return -1;
    }

    public final int reverse(int id) {
        if (reverseEdge == null)
            return -1;
        return reverseEdge[id];
    }

    public final void addVertices(int count) {
        id13(vertexCount + count);
        Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
        if (firstInbound != null)
            Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
        vertexCount += count;
    }

    protected final void initEdges() {
        if (edges == null) {
            edges = new Edge[from.length];
            for (int i = 0; i < edgeCount; i++)
                edges[i] = createEdge(i);
        }
    }

    public final void removeVertex(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextOutbound[id];
        }
        initInbound();
        id = firstInbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextInbound[id];
        }
    }

    private void initInbound() {
        if (firstInbound == null) {
            firstInbound = new int[firstOutbound.length];
            Arrays.fill(firstInbound, 0, vertexCount, -1);
            nextInbound = new int[from.length];
            for (int i = 0; i < edgeCount; i++) {
                nextInbound[i] = firstInbound[to[i]];
                firstInbound[to[i]] = i;
            }
        }
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final void setFlag(int id, int bit) {
        flags[id] |= 1 << bit;
    }

    public final void removeFlag(int id, int bit) {
        flags[id] &= -1 - (1 << bit);
    }

    public final void removeEdge(int id) {
        setFlag(id, id29);
    }

    public final void restoreEdge(int id) {
        removeFlag(id, id29);
    }

    public final boolean isRemoved(int id) {
        return flag(id, id29);
    }

    public final Iterable<Edge> outbound(final int id) {
        initEdges();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstOutbound, nextOutbound);
            }
        };
    }

    public final Iterable<Edge> inbound(final int id) {
        initEdges();
        initInbound();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstInbound, nextInbound);
            }
        };
    }

    protected void id17(int size) {
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

    private void id13(int size) {
        if (firstOutbound.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            firstOutbound = resize(firstOutbound, newSize);
            if (firstInbound != null)
                firstInbound = resize(firstInbound, newSize);
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

        public int getSource() {
            return source(id);
        }

        public int getDestination() {
            return destination(id);
        }

        public long getWeight() {
            return weight(id);
        }

        public long getCapacity() {
            return capacity(id);
        }

        public long getFlow() {
            return flow(id);
        }

        public void pushFlow(long flow) {
            Graph.this.pushFlow(id, flow);
        }

        public boolean getFlag(int bit) {
            return flag(id, bit);
        }

        public void setFlag(int bit) {
            Graph.this.setFlag(id, bit);
        }

        public void removeFlag(int bit) {
            Graph.this.removeFlag(id, bit);
        }

        public int id6() {
            return transposed(id);
        }

        public Edge id3() {
            int reverseID = id6();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int id23() {
            return reverse(id);
        }

        public Edge id24() {
            int reverseID = id23();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int getID() {
            return id;
        }

        public void remove() {
            removeEdge(id);
        }

        public void restore() {
            restoreEdge(id);
        }
    }

    public class EdgeIterator implements Iterator<Edge> {
        private int edgeID;
        private final int[] next;
        private int lastID = -1;

        public EdgeIterator(int id, int[] first, int[] next) {
            this.next = next;
            edgeID = nextEdge(first[id]);
        }

        private int nextEdge(int id) {
            while (id != -1 && isRemoved(id))
                id = next[id];
            return id;
        }

        public boolean hasNext() {
            return edgeID != -1;
        }

        public Edge next() {
            if (edgeID == -1)
                throw new NoSuchElementException();
            lastID = edgeID;
            edgeID = nextEdge(next[lastID]);
            return edges[lastID];
        }

        public void remove() {
            if (lastID == -1)
                throw new IllegalStateException();
            removeEdge(lastID);
            lastID = -1;
        }
    }

}

class IntegerUtils {
    public static long nextPrime(long from) {
        if (from <= 2)
            return 2;
        from += 1 - (from & 1);
        while (!isPrime(from))
            from += 2;
        return from;
    }

    public static long reverse(long number, long module) {
        return power(number, module - 2, module);
    }

    public static boolean isPrime(long number) {
        if (number < 2)
            return false;
        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    public static long power(long base, long exponent, long mod) {
        if (base >= mod)
            base %= mod;
        if (exponent == 0)
            return 1 % mod;
        long result = power(base, exponent >> 1, mod);
        result = result * result % mod;
        if ((exponent & 1) != 0)
            result = result * base % mod;
        return result;
    }
}

interface Edge {
    public int getSource();

    public int getDestination();

    public long getWeight();

    public long getCapacity();

    public long getFlow();

    public void pushFlow(long flow);

    public boolean getFlag(int bit);

    public void setFlag(int bit);

    public void removeFlag(int bit);

    public int id6();

    public Edge id3();

    public int id23();

    public Edge id24();

    public int getID();

    public void remove();

    public void restore();
}