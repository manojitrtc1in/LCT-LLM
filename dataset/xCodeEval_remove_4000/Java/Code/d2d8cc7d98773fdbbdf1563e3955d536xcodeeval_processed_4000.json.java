import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class F implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    Edge[][] graph, tree;

    

    private void solve() {
        int n = readInt();
        int m = readInt();

        this.graph = id30(n, m);

        TotalEdge[] edges = new TotalEdge[m];
        for (int from = 0, index = 0; from < n; ++from) {
            for (Edge e : graph[from]) {
                if (e.to > from) {
                    edges[index++] = new TotalEdge(from, e);
                }
            }
        }

        Arrays.sort(edges, Comparator.comparingInt(a -> a.w));

        boolean[] isFree = new boolean[n];

        List<Edge>[] treeLists = new List[n];
        for (int v = 0; v < n; ++v) {
            treeLists[v] = new ArrayList<>(1);
        }

        DSU dsu = DSU.createInstance(n);
        for (TotalEdge e : edges) {
            if (dsu.union(e.from, e.to)) {
                treeLists[e.from].add(new Edge(e.to, e.w));
                treeLists[e.to].add(new Edge(e.from, e.w));
            } else {
                isFree[e.from] = true;
                isFree[e.to] = true;
            }
        }

        this.tree = new Edge[n][];
        for (int v = 0; v < n; ++v) {
            tree[v] = treeLists[v].toArray(new Edge[0]);
        }

        int root = 0;
        id12(root);

        List<Integer> id35 = new ArrayList<>();
        for (int v = 0; v < n; ++v) {
            if (isFree[v]) id35.add(v);
        }

        int[] freeVertices = castInt(id35);
        int size = freeVertices.length;

        long[][] d = new long[size][n];
        this.vertices = null;
        
        for (int i = 0; i < size; ++i) {
            int freeVertex = freeVertices[i];
            for (int v = 0; v < n; ++v) {
                d[i][v] = distance(freeVertex, v);
            }
            dijkstra(freeVertex, d[i]);
        }

        int q = readInt();
        while (q --> 0) {
            int from = readInt() - 1, to = readInt() - 1;

            long result = distance(from, to);

            for (int mid = 0; mid < size; ++mid) {
                result = min(result, d[mid][from] + d[mid][to]);
            }

            out.println(result);
        }
    }

    static class Vertex implements Comparable<Vertex> {

        int index;
        long distance;

        public Vertex(int index, long distance) {
            this.index = index;
            this.distance = distance;
        }

        @Override
        public int compareTo(Vertex other) {
            if (this.distance != other.distance) {
                return Long.compare(this.distance, other.distance);
            }

            return Integer.compare(this.index, other.index);
        }
    }

    Vertex[] vertices;

    void dijkstra(int start, long[] distances) {
        NavigableSet<Vertex> queue = new TreeSet<>();

        int n = distances.length;
        if (vertices == null) {
            vertices = new Vertex[n];
            for (int v = 0; v < n; ++v) {
                vertices[v] = new Vertex(v, Long.MAX_VALUE);
            }
        }

        for (int v = 0; v < n; ++v) {
            vertices[v].distance = Long.MAX_VALUE;
        }
        vertices[start].distance = 0;

        queue.add(vertices[start]);

        while (queue.size() > 0) {
            Vertex v = queue.pollFirst();

            int from = v.index;
            long fromDistance = v.distance;

            for (Edge e : graph[from]) {
                int to = e.to;
                long id0 = fromDistance + e.w;
                if (distances[to] > id0) {
                    distances[to] = id0;

                    Vertex vTo = vertices[to];
                    queue.remove(vTo);
                    vTo.distance = id0;
                    queue.add(vTo);
                }
            }
        }
    }

    int time;
    int[] first;
    int[] order;

    long[] distances;

    void id12(int root) {
        int n = tree.length;

        this.first = new int[n];
        this.order = new int[n + n];
        this.time = 0;

        this.distances = new long[n];
        distances[root] = 0;

        dfs(root, root);

        buildSparse();
    }

    void dfs(int from, int parent) {
        order[time] = from;
        first[from] = time++;

        for (Edge e : tree[from]) {
            if (e.to == parent) continue;

            distances[e.to] = distances[from] + e.w;
            dfs(e.to, from);

            order[time++] = from;
        }
    }

    long distance(int u, int v) {
        int lca = lca(u, v);
        return distances[u] + distances[v] - 2 * distances[lca];
    }

    final int MAGIC = 19;
    int[][] table;

    int[] powers;

    void buildSparse() {
        int n = order.length;
        this.table = new int[MAGIC][n];

        table[0] = order;

        for (int bit = 0; bit < MAGIC - 1; ++bit) {
            for (int i = 0, j = i + (1 << bit), k = j + (1 << bit); k <= n; ++i, ++j, ++k) {
                int left = table[bit][i];
                int right = table[bit][j];

                int best = (distances[left] <= distances[right] ? left : right);
                table[bit + 1][i] = best;
            }
        }

        this.powers = new int[1 << MAGIC];
        for (int bit = 0; bit < MAGIC; ++bit) {
            powers[1 << bit] = bit;
        }

        for (int i = 1; i < powers.length; ++i) {
            powers[i] = max(powers[i - 1], powers[i]);
        }
    }

    int lca(int a, int b) {
        a = first[a];
        b = first[b];

        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int length = b - a + 1;
        int bit = powers[length];
        int power = 1 << bit;

        int left = table[bit][a];
        int right = table[bit][b - power + 1];

        return (distances[left] <= distances[right] ? left : right);
    }

    class TotalEdge implements Comparable<TotalEdge> {
        int from, to, w;

        TotalEdge(int from, Edge e) {
            this.from = from;
            this.to = e.to;
            this.w = e.w;
        }

        @Override
        public int compareTo(TotalEdge other) {
            return Integer.compare(this.w, other.w);
        }
    }

    @SuppressWarnings("unused")
    private static class DSU {

        int[] sizes;

        int[] ranks;
        int[] parents;

        @SuppressWarnings("unused")
        static DSU createInstance(int size) {
            int[] sizes = new int[size];
            Arrays.fill(sizes, 1);

            return new DSU(sizes);
        }

        DSU(int[] sizes) {
            this.sizes = sizes;

            int size = sizes.length;

            this.ranks = new int[size];
            Arrays.fill(ranks, 1);

            this.parents = castInt(order(size));
        }

        int get(int v) {
            if (v == parents[v]) return v;
            return parents[v] = get(parents[v]);
        }

        @SuppressWarnings("unused")
        boolean union(int a, int b) {
            a = get(a);
            b = get(b);

            if (a == b) return false;

            if (ranks[a] < ranks[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            parents[b] = a;
            sizes[a] += sizes[b];

            if (ranks[a] == ranks[b]) ++ranks[a];

            return true;
        }

        @SuppressWarnings("unused")
        boolean connected(int a, int b) {
            return get(a) == get(b);
        }
    }

    


    private final static boolean id6 = true;
    private final boolean id10 = !new File("input.txt").exists();



    private final static int id18 = 128;

    private final static boolean id29 = false;

    


    @SuppressWarnings("unused")
    private static long inverse(long x) {
        return binpow(x, MODULO - 2);
    }

    private static long binpow(long base, long power) {
        if (power == 0) return 1;
        if ((power & 1) == 0) {
            long half = binpow(base, power >> 1);
            return mult(half, half);
        } else {
            long prev = binpow(base, power - 1);
            return mult(prev, base);
        }
    }

    private static long add(long a, long b) { return (a + b) % MODULO; }

    @SuppressWarnings("unused")
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }

    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    @SuppressWarnings("unused")
    void yesNo(boolean yes) {
        out.println(yes ? "YES" : "NO");
    }

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id10) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                        out.flush();
                    } catch (NumberFormatException | EOFException e) {
                        break;
                    }
                } while (id6);
            }

            out.close();
            time();
        }catch (Exception e){
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    


    private BufferedReader in;
    private OutputWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args){
        new Thread(null, new F(), "", id18 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id10){
            if (fileName.isEmpty()) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new OutputWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new OutputWriter(fileName + ".out");
            }
        }else{
            in = new BufferedReader(new FileReader("input.txt"));
            out = new OutputWriter("output.txt");
        }
    }

    


    private long timeBegin;

    private void timeInit() {
        this.timeBegin = System.currentTimeMillis();
    }

    private void time(){
        long timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @SuppressWarnings("unused")
    private void debug(Object... objects){
        if (id10){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String id31() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id31();
        if (null == line) throw new EOFException();
        return line;
    }

    private String readString() {
        while(!tok.hasMoreTokens()){
            tok = new StringTokenizer(readLine(), delim);
        }

        return tok.nextToken(delim);
    }

    


    private final char id8 = '\0';

    @SuppressWarnings("unused")
    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id8;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id9() {
        return readLine().toCharArray();
    }

    @SuppressWarnings("unused")
    private char[][] id24(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id9();
        }

        return field;
    }

    


    private long id22() {
        int sign = 1;
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                int j = in.read();
                if (-1 == j) {
                    if (started) return sign * result;
                    throw new NumberFormatException();
                }

                if (j == '-') {
                    if (started) throw new NumberFormatException();
                    sign = -sign;
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else if (started) {
                    return sign * result;
                }
            } catch (IOException e) {
                throw new RuntimeIOException(e);
            }
        }
    }

    private int readInt() {

        if (!id29) {
            return Integer.parseInt(readString());
        } else {
            return (int) id22();
        }
    }

    private int[] id3(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    @SuppressWarnings("unused")
    private int[] id11(int size) {
        Integer[] array = new Integer[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readInt();
        }
        Arrays.sort(array);

        int[] sortedArray = new int[size];
        for (int index = 0; index < size; ++index) {
            sortedArray[index] = array[index];
        }

        return sortedArray;
    }

    private int[] id14(int size) {
        int[] array = id3(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id20(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id3(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id33(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id14(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id29) {
            return Long.parseLong(readString());
        } else {
            return id22();
        }
    }

    @SuppressWarnings("unused")
    private long[] id16(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    @SuppressWarnings("unused")
    private double[] id5(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private BigInteger id28() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id25() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id37(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    


    @Deprecated
    @SuppressWarnings("unused")
    private List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new List[vertexNumber];

        for (int index = 0; index < vertexNumber; ++index){
            graph[index] = new ArrayList<>();
        }

        while (edgeNumber-- > 0){
            int from = readInt() - 1;
            int to = readInt() - 1;

            graph[from].add(to);
            graph[to].add(from);
        }

        return graph;
    }

    private static class GraphBuilder {

        final int size;
        final List<Integer>[] edges;

        static GraphBuilder createInstance(int size) {
            @SuppressWarnings("unchecked")
            List<Integer>[] edges = new List[size];
            for (int v = 0; v < size; ++v) {
                edges[v] = new ArrayList<>();
            }

            return new GraphBuilder(edges);
        }

        private GraphBuilder(List<Integer>[] edges) {
            this.size = edges.length;
            this.edges = edges;
        }

        public void addEdge(int from, int to) {
            id26(from, to);
            id26(to, from);
        }

        public void id26(int from, int to) {
            edges[from].add(to);
        }

        public int[][] build() {
            int[][] graph = new int[size][];
            for (int v = 0; v < size; ++v) {
                List<Integer> vEdges = edges[v];
                graph[v] = castInt(vEdges);
            }

            return graph;
        }
    }

    @SuppressWarnings("unused")
    private final static int id27 = 0, id15 = 1;

    @SuppressWarnings("unused")
    private int[][] id13(int vertexNumber, int edgesNumber) {
        return id13(vertexNumber, edgesNumber, id15, false);
    }

    private int[][] id13(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id26(from, to);
            else graphBuilder.addEdge(from, to);
        }

        return graphBuilder.build();
    }

    private static class Edge {
        int to;
        int w;

        Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    @SuppressWarnings("unused")
    private Edge[][] id30(int vertexNumber, int edgesNumber) {
        return id30(vertexNumber, edgesNumber, id15, false);
    }

    private Edge[][] id30(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<>();
        }

        while (edgesNumber --> 0) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;
            int w = readInt();

            graph[from].add(new Edge(to, w));
            if (!directed) graph[to].add(new Edge(from, w));
        }

        Edge[][] graphArrays = new Edge[vertexNumber][];
        for (int v = 0; v < vertexNumber; ++v) {
            graphArrays[v] = graph[v].toArray(new Edge[0]);
        }

        return graphArrays;
    }

    


    private static class id32 {

        @SuppressWarnings("unused")
        static Comparator<id32> increaseComparator = new Comparator<F.id32>() {
            @Override
            public int compare(F.id32 id23, F.id32 id17) {
                int value1 = id23.value;
                int value2 = id17.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id23.index;
                int index2 = id17.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<id32> id2 = new Comparator<F.id32>() {
            @Override
            public int compare(F.id32 id23, F.id32 id17) {
                int value1 = id23.value;
                int value2 = id17.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id23.index;
                int index2 = id17.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static id32[] from(int[] array) {
            id32[] iip = new id32[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id32(array[i], i);
            }

            return iip;
        }

        int value, index;

        id32(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        @SuppressWarnings("unused")
        int id7() {
            return index + 1;
        }
    }

    @SuppressWarnings("unused")
    private id32[] id4(int size) {
        id32[] array = new id32[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id32(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id40 = 12;

        private int precision;
        private String format, id39;

        {
            precision = id40;

            format = createFormat(precision);
            id39 = format + " ";
        }

        OutputWriter(OutputStream out) {
            super(out);
        }

        OutputWriter(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        int getPrecision() {
            return precision;
        }

        void setPrecision(int precision) {
            precision = max(0, precision);
            this.precision = precision;

            format = createFormat(precision);
            id39 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }
        
        @Override
        public void println(double d){
            print(d);
            println();
        }

        void id34(double d){
            printf(id39, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id34(d[i]);
            }

            print(d[d.length - 1]);
        }

        @SuppressWarnings("unused")
        void printlnAll(double... d){
            printAll(d);
            println();
        }
        
        void printAll(int... array) {
        	for (int value : array) {
        		print(value + " ");
        	}
        }

        @SuppressWarnings("unused")
        void printlnAll(int... array) {
        	printAll(array);
        	println();
        }
        
        void printAll(long... array) {
        	for (long value : array) {
        		print(value + " ");
        	}
        }

        @SuppressWarnings("unused")
        void printlnAll(long... array) {
        	printAll(array);
        	println();
        }
    }

    


    private static class EOFException extends RuntimeException {

        EOFException() {
            super();
        }
    }

    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id36 = -6463830523020118289L;

        RuntimeIOException(Throwable cause) {
            super(cause);
        }
    }

    

    

    


    private static void swap(int[] array, int i, int j) {
        if (i != j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    private static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int[][] steps8 = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    @SuppressWarnings("unused")
    private static boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
        return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
    }

    private static boolean checkIndex(int index, int lim){
        return (0 <= index && index < lim);
    }

    


    private static int getBit(long mask, int bit) { return (int)((mask >> bit) & 1); }

    @SuppressWarnings("unused")
    private static boolean checkBit(long mask, int bit){
        return getBit(mask, bit) != 0;
    }

    


    @SuppressWarnings("unused")
    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    @SuppressWarnings("unused")
    private static Point id19(int[] array) {
        int min = array[0];
        int max = array[0];

        for (int index = 0, size = array.length; index < size; ++index, ++index) {
            int value = array[index];

            if (index == size - 1) {
                min = min(min, value);
                max = max(max, value);
            } else {
                int otherValue = array[index + 1];

                if (value <= otherValue) {
                    min = min(min, value);
                    max = max(max, otherValue);
                } else {
                    min = min(min, otherValue);
                    max = max(max, value);
                }
            }
        }

        return new Point(min, max);
    }

    


    @SuppressWarnings("unused")
    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
        }

        return true;
    }

    @SuppressWarnings("unused")
    private static int[] id21(int n) {
        boolean[] used = new boolean[n];
        used[0] = used[1] = true;

        int size = 0;
        for (int i = 2; i < n; ++i) {
            if (!used[i]) {
                ++size;
                for (int j = 2 * i; j < n; j += i) {
                    used[j] = true;
                }
            }
        }

        int[] primes = new int[size];
        for (int i = 0, cur = 0; i < n; ++i) {
            if (!used[i]) {
                primes[cur++] = i;
            }
        }

        return primes;
    }

    


    @SuppressWarnings("unused")
    int[] id38(int value) {
        List<Integer> id1 = new ArrayList<>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id1.add(divisor);
                if (divisor * divisor != value) {
                    id1.add(value / divisor);
                }
            }
        }

        return castInt(id1);
    }

    @SuppressWarnings("unused")
    long[] id38(long value) {
        List<Long> id1 = new ArrayList<>();
        for (long divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id1.add(divisor);
                if (divisor * divisor != value) {
                    id1.add(value / divisor);
                }
            }
        }

        return castLong(id1);
    }

    


    @SuppressWarnings("unused")
    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    


    private static int[] castInt(List<Integer> list) {
        int[] array = new int[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    @SuppressWarnings("unused")
    private static long[] castLong(List<Long> list) {
        long[] array = new long[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    


    
    @SuppressWarnings("unused")
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }
}